#include "FmsDbReader.h"

#include <trunk/library/Common/Conversion/ll_to_utm/ll_to_utm.h>

FMSDbReader::FMSDbReader(QObject *parent) :
    QObject(parent)
{
    //    Initialization();
}

void FMSDbReader::Initialization()
{
    //Install the configurable mAgentGroup from a file
    parseConfigurables();

    db = new QSqlDatabase(QSqlDatabase::addDatabase("QMYSQL","FMSConnection"));

    //    db->setHostName("10.1.153.89");
    //    db->setPort(3306);
    //    db->setDatabaseName("FMS");
    //    db->setUserName("FMSS_General");
    //    db->setPassword("common1234");

    db->setHostName(mHostName);
    db->setPort(mPort.toInt());
    db->setDatabaseName(mDatabaseName);
    db->setUserName(mUserName);
    db->setPassword(mPassword);

    if(db->open())
    {
        qDebug()<<"DB for FMS open success!!!!!";
        query = new QSqlQuery(*db);

        scanTimer = new QTimer(0);
        connect(scanTimer,SIGNAL(timeout()),this,SLOT(scanSummary()));
        scanTimer->start(5000);
    }else
    {
        qDebug()<<"DB for FMS open failed.....";
    }
}

void FMSDbReader::parseConfigurables()
{
    STKCI::tree_node tNode;
    STKCI::txml_doc_parser tParser;
    if(tParser.LoadFromFile(gVRPFMSConfigFile,&tNode)>=0)
    {
        //Retrieve the Agent Group
        STKCI::tree_node* tAgentConfigNode = tNode.first_node("Agent");
        if(tAgentConfigNode!=NULL)
        {
            STKCI::tree_node* tAgentNode = tAgentConfigNode->first_node();
            while(tAgentNode!=NULL)
            {
                if(!tAgentNode->name().empty()
                        &&(tAgentNode->name()=="Agent_Group"))
                {

                    std::stringstream convert(tAgentNode->value());
                    convert>>mAgentGroup;
                    qDebug()<<"mAgentGroup: "<<mAgentGroup;
                    break;
                }
                tAgentNode = tAgentNode->next_sibling();
            }
        }
        //Retrieve the Location Group
        STKCI::tree_node* tLandmarkConfigNode = tNode.first_node("Landmark");
        if(tLandmarkConfigNode!=NULL)
        {
            STKCI::tree_node* tLandmarkNode = tLandmarkConfigNode->first_node();
            while(tLandmarkNode!=NULL)
            {
                if(!tLandmarkNode->name().empty()
                        &&(tLandmarkNode->name()=="Landmark_Group"))
                {

                    std::stringstream convert(tLandmarkNode->value());
                    convert>>mLandmarkGroup;
                    qDebug()<<"mLandmarkGroup: "<<mLandmarkGroup;
                    break;
                }
                tLandmarkNode = tLandmarkNode->next_sibling();
            }
        }

        //Retrieve the Db configs
        STKCI::tree_node* tDbConfigNode = tNode.first_node("FMSDatabase");
        if(tDbConfigNode!=NULL)
        {
            STKCI::tree_node* tDbNode = tDbConfigNode->first_node();
            while(tDbNode!=NULL)
            {

                if(!tDbNode->name().empty())
                {
                    std::stringstream convert(tDbNode->value());
                    if(tDbNode->name()=="HostName")
                    {
                        std::string tStr;
                        convert>>tStr;
                        mHostName = QString::fromStdString(tStr);
                        qDebug()<<"mFMSHostName: "<<mHostName;
                    }else if(tDbNode->name()=="Port")
                    {
                        std::string tStr;
                        convert>>tStr;
                        mPort = QString::fromStdString(tStr);
                        qDebug()<<"mFMSPort: "<<mPort;
                    }else if(tDbNode->name()=="DatabaseName")
                    {
                        std::string tStr;
                        convert>>tStr;
                        mDatabaseName = QString::fromStdString(tStr);
                        qDebug()<<"mFMSDatabaseName: "<<mDatabaseName;
                    }else if(tDbNode->name()=="Username")
                    {
                        std::string tStr;
                        convert>>tStr;
                        mUserName = QString::fromStdString(tStr);
                        qDebug()<<"mFMSUsername: "<<mUserName;
                    }else if(tDbNode->name()=="Password")
                    {
                        std::string tStr;
                        convert>>tStr;
                        mPassword = QString::fromStdString(tStr);
                        qDebug()<<"mFMSPassword: "<<mPassword;
                    }
                }
                tDbNode = tDbNode->next_sibling();
            }
        }
    }
}

//SCAN FUNCS
void FMSDbReader::scanSummary()
{
    scanLandmark();
    scanAgentInfo();
    scanAgentLocal();
}

void FMSDbReader::scanAgentInfo()
{
    //    qDebug()<<"scan agent info";
    QList<qint64> tAgentIds = mAgentInfoTimeStamps.keys();
    query->exec(QString("SELECT * FROM AgentInfo"));
    while(query->next())
    {
        //        qDebug()<<"checkpoint0";

        qint64 tAgentId = query->value("agent_id").toLongLong();
        qint64 tAgentGroup = query->value("agent_group").toLongLong();
        qint64 tAgentSS = query->value("service_status").toInt();
        //        qDebug()<<"tAgentGroup:"<<tAgentGroup;

        if(tAgentGroup==mAgentGroup && tAgentSS==1)
        {
            //            qDebug()<<"checkpoint1";


            qint64 tTimeStamp = query->value("db_update_time").toLongLong();

            //get specific params
            QString tPlatSpecInfo = query->value("platform_specific_info").toString();
            qint64 tCapacity;
            double tSpeed;
            if(!tPlatSpecInfo.isEmpty())
            {
                QString tCapacityFrontTag = QString("<capacity>");
                QString tCapacityEndTag = QString("</capacity>");
                QString tSpeedFrontTag = QString("<avgspeed>");
                QString tSpeedEndTag = QString("</avgspeed>");
                int indexOfCapacity = tPlatSpecInfo.indexOf(tCapacityFrontTag)+tCapacityFrontTag.size();
                int indexOfSpeed = tPlatSpecInfo.indexOf(tSpeedFrontTag)+tSpeedFrontTag.size();
                tCapacity = tPlatSpecInfo.mid(indexOfCapacity,tPlatSpecInfo.indexOf(tCapacityEndTag) - indexOfCapacity).toLongLong();
                tSpeed = tPlatSpecInfo.mid(indexOfSpeed,tPlatSpecInfo.indexOf(tSpeedEndTag) - indexOfSpeed).toDouble();
            }

            if(mAgentInfoTimeStamps.contains(tAgentId))
            {
                if(mAgentInfoTimeStamps.value(tAgentId)==tTimeStamp)
                {

                }else
                {
                    mAgentInfoTimeStamps[tAgentId]=tTimeStamp;


                    if(mAgentsStatus[tAgentId]["capacity"]!=QString("%1").arg(tCapacity))
                    {
                        mAgentsStatus[tAgentId]["capacity"]=QString("%1").arg(tCapacity);
                        QPair<qint64,QString> tPair;
                        tPair.first = tAgentId;
                        tPair.second = "capacity";
                        tAgentStatusUpdates.append(tPair);
                    }
                    if(mAgentsStatus[tAgentId]["speed"]!=QString("%1").arg(tSpeed))
                    {
                        mAgentsStatus[tAgentId]["speed"]=QString("%1").arg(tSpeed);
                        QPair<qint64,QString> tPair;
                        tPair.first = tAgentId;
                        tPair.second = "speed";
                        tAgentStatusUpdates.append(tPair);
                    }
                }
            }else
            {
                mAgentInfoTimeStamps.insert(tAgentId,tTimeStamp);
                mReadyAgents.append(tAgentId);

                QHash<QString,QString> tHash;
                tHash.insert("capacity",QString("%1").arg(tCapacity));
                tHash.insert("speed",QString("%1").arg(tSpeed));
                mAgentsStatus.insert(tAgentId,tHash);

                tAgentStatusRegisters.append(tAgentId);
            }

            tAgentIds.removeOne(tAgentId);
        }
    }

    if(tAgentIds.size()>0)
    {
        //call delete
        for(qint64 tVehId: tAgentIds)
        {
            deleteAgent(tVehId);
        }
    }

    for(QPair<qint64,QString> tVehUpdate: tAgentStatusUpdates)
    {
        if(mAgentLocalTimeStamps.contains(tVehUpdate.first))
        {
            UpdateAgentStatusIntoVRP(tVehUpdate.first,tVehUpdate.second);
        }
    }
}

void FMSDbReader::scanAgentLocal()
{
    //    qDebug()<<"scan agent local";
    QList<qint64> tAgentIds = mAgentLocalTimeStamps.keys();
    query->exec("SELECT * FROM AgentPlatformLocal");
    while(query->next())
    {
        //        qDebug()<<"checkpoint01";

        qint64 tAgentId = query->value("agent_id").toLongLong();


        if(mReadyAgents.contains(tAgentId))
        {
            //            qDebug()<<"checkpoint02";

            double tLat = query->value("latitude").toDouble();
            double tLong = query->value("longitude").toDouble();
            qint64 tTimeStamp = query->value("db_update_time").toLongLong();

            if(mAgentLocalTimeStamps.contains(tAgentId))
            {
                //                qDebug()<<"checkpoint03";

                if(mAgentLocalTimeStamps.value(tAgentId)==tTimeStamp)
                {

                }else
                {
                    mAgentLocalTimeStamps[tAgentId]=tTimeStamp;
                    UpdateAgentLocalInVRP(tAgentId,tLat,tLong);
                }
            }else
            {
                //                qDebug()<<"checkpoint04";

                mAgentLocalTimeStamps.insert(tAgentId,tTimeStamp);
                AddAgentLocalIntoVRP(tAgentId,tLat,tLong);

                if(tAgentStatusRegisters.contains(tAgentId))
                {
                    AddAgentStatusIntoVRP(tAgentId);
                }
            }

            tAgentIds.removeOne(tAgentId);
        }
    }

    if(tAgentIds.size()>0)
    {
        for(qint64 tVehId: tAgentIds)
        {
            deleteAgent(tVehId);
        }
    }
}

void FMSDbReader::scanLandmark()
{
    QList<qint64> tLandmarkIds = mLandmarkTimeStamps.keys();
    query->exec("SELECT * FROM Landmark");
    while(query->next())
    {
        qint64 tLandmarkId = query->value("landmark_id").toLongLong();
        qint64 tLandmarkGroup = query->value("landmark_group").toLongLong();

        if(tLandmarkGroup==mLandmarkGroup)
        {
            qint64 tTimeStamp = query->value("db_update_time").toLongLong();
            double tPosX = query->value("landmark_pose_x").toDouble();
            double tPosY = query->value("landmark_pose_y").toDouble();
            QPair<double,double> tPos(tPosX,tPosY);

            if(mLandmarkTimeStamps.contains(tLandmarkId))
            {
                if(mLandmarkTimeStamps.value(tLandmarkId)==tTimeStamp)
                {

                }else
                {
                    mLandmarkTimeStamps[tLandmarkId]=tTimeStamp;

                    if(mLandmarkPos[tLandmarkId]!=tPos)
                    {
                        mLandmarkPos[tLandmarkId]=tPos;

                        UpdateLandmarkInVRP(tLandmarkId, tPos);
                    }
                }
            }else
            {
                mLandmarkTimeStamps.insert(tLandmarkId,tTimeStamp);

                AddLandmarkIntoVRP(tLandmarkId,tPos);

                mLandmarkPos.insert(tLandmarkId,tPos);
            }

            tLandmarkIds.removeOne(tLandmarkId);
        }
    }

    if(tLandmarkIds.size()>0)
    {
        for(qint64 tLandmarkId: tLandmarkIds)
        {
            DeleteLandmarkFromVRP(tLandmarkId);
        }
    }
}

void FMSDbReader::scanAgentEvent()
{
    //arrival

    //depot
}

void FMSDbReader::deleteAgent(qint64 aAgentId)
{
    if(mAgentInfoTimeStamps.contains(aAgentId))
        DeleteAgentStatusFromVRP(aAgentId);
    if(mAgentLocalTimeStamps.contains(aAgentId))
        DeleteAgentLocalFromVRP(aAgentId);
    if(mAgentInfoTimeStamps.contains(aAgentId))
        mAgentInfoTimeStamps.remove(aAgentId);
    if(mAgentLocalTimeStamps.contains(aAgentId))
        mAgentLocalTimeStamps.remove(aAgentId);
    if(mReadyAgents.contains(aAgentId))
        mReadyAgents.removeOne(aAgentId);
    if(mAgentsStatus.contains(aAgentId))
        mAgentsStatus.remove(aAgentId);
    if(tAgentStatusRegisters.contains(aAgentId))
        tAgentStatusRegisters.removeOne(aAgentId);
    QPair<qint64, QString> tPair1(aAgentId,"capacity");
    if(tAgentStatusUpdates.contains(tPair1))
        tAgentStatusUpdates.removeOne(tPair1);
    QPair<qint64, QString> tPair2(aAgentId,"speed");
    if(tAgentStatusUpdates.contains(tPair2))
        tAgentStatusUpdates.removeOne(tPair2);
    //    DeleteAgentInVRP(tVehId);
}

//VRPDB EXECUTION FUNS
void FMSDbReader::AddAgentStatusIntoVRP(qint64 aAgentId)
{
    qint64 tCapacity = mAgentsStatus.value(aAgentId).value("capacity").toLongLong();
    double tSpeed = mAgentsStatus.value(aAgentId).value("speed").toDouble();

    emit SendAddVehStatusByFMS(aAgentId,tCapacity,tSpeed);

    //clean up the updateslist
    tAgentStatusRegisters.removeOne(aAgentId);
}

void FMSDbReader::UpdateAgentStatusIntoVRP(qint64 aAgentId, QString aType)
{    
    emit SendUpdateVehStatusByFMS(aAgentId,aType,mAgentsStatus.value(aAgentId).value(aType));

    QPair<qint64, QString> tPair(aAgentId,aType);
    tAgentStatusUpdates.removeOne(tPair);
}

void FMSDbReader::DeleteAgentStatusFromVRP(qint64 aAgentId)
{
    emit SendDeleteVehStatusByFMS(aAgentId);
}

void FMSDbReader::AddAgentLocalIntoVRP(qint64 aAgentId, double aLat, double aLong)
{
    emit SendAddVehLLByFMS(aAgentId, aLat, aLong);
}

void FMSDbReader::DeleteAgentLocalFromVRP(qint64 aAgentId)
{
    emit SendDeleteVehLLByFMS(aAgentId);
}

void FMSDbReader::UpdateAgentLocalInVRP(qint64 aAgentId, double aLat, double aLong)
{
    emit SendUpdateVehLLByFMS(aAgentId, aLat, aLong);
}

void FMSDbReader::DeleteAgentInVRP(qint64 aAgentId)
{
    emit SendDeleteVehByFMS(aAgentId);
}

QPair<double,double> FMSDbReader::ConvertUTMtoLL(QPair<double, double> aUTMPos)
{
    double tLat, tLong;
    Common::Convert::utm_to_ll(aUTMPos.second,aUTMPos.first,"48N",tLat,tLong);
    QPair<double,double> ret(tLat,tLong);
    return ret;
}

void FMSDbReader::AddLandmarkIntoVRP(qint64 aLandmarkId, QPair<double, double> aPos)
{
    QPair<double,double> tLLPos = ConvertUTMtoLL(aPos);
    qDebug()<<"[tLLPos-Add][tLLPos-Add]"<<tLLPos;
    emit SendAddLandmarkByFMS(aLandmarkId,tLLPos.first,tLLPos.second);
}

void FMSDbReader::UpdateLandmarkInVRP(qint64 aLandmarkId, QPair<double, double> aPos)
{
    QPair<double,double> tLLPos = ConvertUTMtoLL(aPos);
    qDebug()<<"[tLLPos-Update][tLLPos-Add]"<<tLLPos;
    emit SendUpdateLandmarkByFMS(aLandmarkId,tLLPos.first,tLLPos.second);
}

void FMSDbReader::DeleteLandmarkFromVRP(qint64 aLandmarkId)
{
    emit SendDeleteLandmarkByFMS(aLandmarkId);
}

//--------------------------------
//SLOTS FOR SENDING MESSAGE TO FMS
void FMSDbReader::sendWaitingTimeToFMS(qint64 aVehId, qint64 aWaitingTime)
{
    //Not Ready
}

void FMSDbReader::triggerVehicleMoving(qint64 aVehId)
{
    //Not Ready
}
