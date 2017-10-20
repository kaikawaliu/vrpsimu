#include "vrptest_db.h"
#include <QSqlError>

vrptest_db::vrptest_db(QSqlDatabase *adb, QObject *parent) :
    db(adb),
    QObject(parent)
{
    Initialization();


}

void vrptest_db::Initialization()
{
    //    db = new QSqlDatabase::addDatabase("QMYSQL","BaseConnection");
    //    db = new QSqlDatabase(QSqlDatabase::addDatabase("QMYSQL","BaseConnection"));
    //    db->setHostName("127.0.0.1");
    //    db->setPort(3306);
    //    db->setDatabaseName("VRP");
    //    db->setUserName("root");
    //    db->setPassword("");

    parseConfigurables();

//    db->setHostName("10.1.153.89");
//    db->setPort(3306);
//    db->setDatabaseName("VRP");
//    db->setUserName("FMSS_General");
//    db->setPassword("common1234");

    db->setHostName(mHostName);
    db->setPort(mPort.toInt());
    db->setDatabaseName(mDatabaseName);
    db->setUserName(mUserName);
    db->setPassword(mPassword);

    if(db->open())
    {
        qDebug()<<"DB for VRPSIM open success!!!!!";
        query = new QSqlQuery(*db);

        if(cleanUpAllReply())
        {
            qDebug()<<"Cleaned Up All Replies Succeed";
        }else
        {
            qDebug()<<"Cleaned Up All Replies Failed";
        }

        fmsDbReader = new FMSDbReader;
        fmsDbReader->moveToThread(&thFMS);
        connect(fmsDbReader,SIGNAL(SendAddVehStatusByFMS(qint64,qint64,double)),this,SLOT(RegisterVehStatusFromFMS(qint64,qint64,double)));
        connect(fmsDbReader,SIGNAL(SendUpdateVehStatusByFMS(qint64,QString,QString)),this,SLOT(UpdateVehStatusFromFMS(qint64,QString,QString)));
        connect(fmsDbReader,SIGNAL(SendDeleteVehStatusByFMS(qint64)),this,SLOT(DeleteVehStatusFromFMS(qint64)));

        connect(fmsDbReader,SIGNAL(SendAddVehLLByFMS(qint64,double,double)),this,SLOT(RegisterVehLL(qint64,double,double)));
        connect(fmsDbReader,SIGNAL(SendDeleteVehLLByFMS(qint64)),this,SLOT(DeregisterVehLL(qint64)));
        connect(fmsDbReader,SIGNAL(SendUpdateVehLLByFMS(qint64,double,double)),this,SLOT(UpdateVehLL(qint64,double,double)));

        connect(fmsDbReader,SIGNAL(SendAddLandmarkByFMS(qint64,double,double)),this,SLOT(RegisterLocLL(qint64,double,double)));
        connect(fmsDbReader,SIGNAL(SendUpdateLandmarkByFMS(qint64,double,double)),this,SLOT(UpdateLocLL(qint64,double,double)));
        connect(fmsDbReader,SIGNAL(SendDeleteLandmarkByFMS(qint64)),this,SLOT(DeregisterLocLL(qint64)));

        //        connect(fmsDbReader,SIGNAL(SendDeleteVehByFMS(qint64)),this,SLOT(DeleteVehFromFMS(qint64)));

        //        mVehDefaultParams.insert("speed","10");
        //        mVehDefaultParams.insert("capacity","10");
        //        mVehDefaultParams.insert("launchcost","300");
        //        mVehDefaultParams.insert("fixtime","10");
        //        mVehDefaultParams.insert("unittime","5");
        //        mVehDefaultParams.insert("refueltime","36000");
        //        mVehDefaultParams.insert("buffertime","300");

        fmsDbReader->Initialization();
        thFMS.start();
    }else
    {
        qDebug()<<"DBforRP open failed.....";
    }
}

void vrptest_db::parseConfigurables()
{
    STKCI::tree_node tNode;
    STKCI::txml_doc_parser tParser;
    if(tParser.LoadFromFile(gVRPDBConfigFile,&tNode)>=0)
    {
        //Retrieve the mStartHour
        STKCI::tree_node* tStartConfigNode = tNode.first_node("StartHour");
        if(tStartConfigNode!=NULL)
        {
            std::stringstream convert(tStartConfigNode->value());
            convert>>mStartHour;
            qDebug()<<"mStartHour: "<<mStartHour;
        }
        //Retrieve the mEndHour
        STKCI::tree_node* tEndConfigNode = tNode.first_node("EndHour");
        if(tEndConfigNode!=NULL)
        {
            std::stringstream convert(tEndConfigNode->value());
            convert>>mEndHour;
            qDebug()<<"mEndHour: "<<mEndHour;
        }
        //Retrieve the Db configs
        STKCI::tree_node* tDbConfigNode = tNode.first_node("VRPDatabase");
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
                        qDebug()<<"mVRPHostName: "<<mHostName;
                    }else if(tDbNode->name()=="Port")
                    {
//                        convert>>mPort;
                        std::string tStr;
                        convert>>tStr;
                        mPort = QString::fromStdString(tStr);
                        qDebug()<<"mVRPPort: "<<mPort;
                    }else if(tDbNode->name()=="DatabaseName")
                    {
//                        convert>>mDatabaseName;
                        std::string tStr;
                        convert>>tStr;
                        mDatabaseName = QString::fromStdString(tStr);
                        qDebug()<<"mVRPDatabaseName: "<<mDatabaseName;
                    }else if(tDbNode->name()=="Username")
                    {
//                        convert>>mUserName;
                        std::string tStr;
                        convert>>tStr;
                        mUserName = QString::fromStdString(tStr);
                        qDebug()<<"mVRPUsername: "<<mUserName;
                    }else if(tDbNode->name()=="Password")
                    {
//                        convert>>mPassword;
                        std::string tStr;
                        convert>>tStr;
                        mPassword = QString::fromStdString(tStr);
                        qDebug()<<"mVRPPassword: "<<mPassword;
                    }
                }
                tDbNode = tDbNode->next_sibling();
            }
        }
    }
}

bool vrptest_db::cleanUpAllReply()
{
    bool vehresult, cusresult, evtresult;
    //veh
    QString queryString = QString("TRUNCATE VRPSIMVehicleReply");
    if(query->exec(queryString))
        vehresult=true;
    else
        vehresult=false;
    //cus
    queryString = QString("TRUNCATE VRPSIMCustomerReply");
    if(query->exec(queryString))
        cusresult=true;
    else
        cusresult=false;
    //evt
    queryString = QString("TRUNCATE VRPSIMEventReply");
    if(query->exec(queryString))
        evtresult=true;
    else
        evtresult=false;

    return vehresult && cusresult && evtresult;
}

bool vrptest_db::RegisterLocLL(qint64 aLocId, double aLat, double aLong)
{
    QDateTime dateTime = QDateTime(QDateTime::currentDateTime());
    QString dateTimeString = dateTime.toString();

    QString queryString = QString("INSERT INTO VRPLandmarkToAdd VALUES ('%1','%2','%3','%4')").arg(aLocId).arg(QString::number(aLat,'g',10)).arg(QString::number(aLong,'g',10)).arg(dateTimeString);
    qDebug()<<queryString;

    if(query->exec(queryString))
    {
        qDebug()<<"register landmark LL from vrptest success!!!!!";
        return true;
    }else
    {
        qDebug()<<"register landmark LL from vrptest failed.....";
        return false;
    }
}

bool vrptest_db::DeregisterLocLL(qint64 aLocId)
{
    QString queryString = QString("DELETE FROM VRPLandmarkToAdd WHERE landmarkID = '%1'").arg(aLocId);

    if(query->exec(queryString))
    {
        qDebug()<<"deregister landmark LL from vrptest success!!!!!";
        return true;
    }else
    {
        qDebug()<<"deregister landmark LL from vrptest failed.....";
        return false;
    }
}

bool vrptest_db::UpdateLocLL(qint64 aLocId, double aLat, double aLong)
{
    //    QDateTime dateTime = QDateTime(QDateTime::currentDateTime());
    //    QString dateTimeString = dateTime.toString();

    //    QString queryString = QString("UPDATE VRPLandmarkToAdd SET lat = %1, long = %2, time = '%3' WHERE landmarkID = %4").arg(QString::number(aLat,'g',10)).arg(QString::number(aLong,'g',10)).arg(dateTimeString).arg(aLocId);
    //    qDebug()<<queryString;
    //    if(query->exec(queryString))
    //    {
    //        qDebug()<<"update landmark LL from vrptest success!!!!!";
    //    }else
    //    {
    //        qDebug()<<"update landmark LL from vrptest failed.....";
    //    }
    qDebug()<<QString("Update Loc: %1 to Lat: %2 Long: %3").arg(aLocId).arg(aLat).arg(aLong);
    return DeregisterLocLL(aLocId) && RegisterLocLL(aLocId,aLat,aLong);
}

bool vrptest_db::RegisterVehLL(qint64 aVehId, double aLat, double aLong)
{
    QDateTime dateTime = QDateTime(QDateTime::currentDateTime());
    QString dateTimeString = dateTime.toString();

    QString queryString = QString("INSERT INTO VRPVehicleToAdd VALUES ('%1','%2','%3','%4')").arg(aVehId).arg(QString::number(aLat,'g',10)).arg(QString::number(aLong,'g',10)).arg(dateTimeString);
    qDebug()<<queryString;
    if(query->exec(queryString))
    {
        qDebug()<<"register vehicle LL from vrptest success!!!!!";
        return true;
    }else
    {
        qDebug()<<"register vehicle LL from vrptest failed.....";
        return false;
    }
}

bool vrptest_db::DeregisterVehLL(qint64 aVehId)
{
    QString queryString = QString("DELETE FROM VRPVehicleToAdd WHERE vehicleID = '%1'").arg(aVehId);
    qDebug()<<queryString;
    if(query->exec(queryString))
    {
        qDebug()<<"deregister vehicle LL from vrptest success!!!!!";
        return true;
    }else
    {
        qDebug()<<"deregister vehicle LL from vrptest failed.....";
        return false;
    }
}

bool vrptest_db::UpdateVehLL(qint64 aVehId, double aLat, double aLong)
{
    qDebug()<<QString("update Veh: %1 to Lat: %2 Long: %3").arg(aVehId).arg(aLat).arg(aLong);

    return DeregisterVehLL(aVehId) && RegisterVehLL(aVehId,aLat,aLong);
}

void vrptest_db::RegisterVehStatusFromFMS(qint64 aVehId, qint64 aCapacity, double aSpeed)
{
    VehRegister(aVehId,
                0,
                aCapacity,
                aSpeed,
                mVehDefaultParams.value("refueltime").toLongLong(),
                mVehDefaultParams.value("fixtime").toLongLong(),
                mVehDefaultParams.value("unittime").toLongLong(),
                mVehDefaultParams.value("buffertime").toLongLong(),
                mVehDefaultParams.value("launchcost").toLongLong());
}

void vrptest_db::UpdateVehStatusFromFMS(qint64 aVehId, QString aType, QString aValue)
{
    if(aType=="capacity")
    {
        VehSetCapacity(aVehId,aValue.toLongLong());
    }else if(aType=="speed")
    {
        VehSetSpeed(aVehId,aValue.toDouble());
    }
}

void vrptest_db::DeleteVehStatusFromFMS(qint64 aVehId)
{
    VehDeregister(aVehId);
}

void vrptest_db::DeleteVehFromFMS(qint64 aVehId)
{
    if(VehDeregister(aVehId))
    {
        DeregisterVehLL(aVehId);
    }
}


//=============================== PUB ==================================
//========================= VRP SIM VEH REQ=============================
//======================================================================
bool vrptest_db::VehRegister(qint64 aVehId, qint64 aDepot, qint64 aCapacity, double aSpeed, qint64 aRefuelTime, qint64 aFixTime, qint64 aUnitTime, qint64 aBufferTime, qint64 aLaunchCost)
{
    QString RefFixUnitTime = QString("%1','%2','%3").arg(aRefuelTime).arg(aFixTime).arg(aUnitTime);

    QString queryString = QString("INSERT INTO VRPSIMVehicleReq VALUES (NULL,'%1','%2','%3','%4',%5,'%6','%7','%8')")
            .arg(QString("register"))
            .arg(aVehId)
            .arg(aDepot)
            .arg(aCapacity)
            .arg(aSpeed)
            .arg(RefFixUnitTime)
            .arg(aBufferTime)
            .arg(aLaunchCost);
    qDebug()<<queryString;
    if(query->exec(queryString))
    {
        //        qDebug()<<"request registering vehicle from vrptest_db success!!!!!";
        return true;
    }else
    {
        qDebug()<<"request registering vehicle from vrptest_db failed.....";
        return false;
    }
}

bool vrptest_db::VehDeregister(qint64 aVehId)
{
    QString queryString = QString("INSERT INTO VRPSIMVehicleReq VALUES(NULL,'%1','%2',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL)")
            .arg(QString("deregister"))
            .arg(aVehId);
    qDebug()<<queryString;
    if(query->exec(queryString))
    {
        qDebug()<<"request deregistering vehicle from vrptest_db success!!!!!";
        return true;
    }else
    {
        qDebug()<<"request deregistering vehicle from vrptest_db failed.....";
        return false;
    }
}

bool vrptest_db::VehSetDepot(qint64 aVehId, qint64 aDepot)
{
    QString queryString = QString("INSERT INTO VRPSIMVehicleReq VALUES(NULL,'%1','%2','%3',NULL,NULL,NULL,NULL,NULL,NULL,NULL)")
            .arg(QString("depot"))
            .arg(aVehId)
            .arg(aDepot);
    qDebug()<<queryString;
    if(query->exec(queryString))
    {
        qDebug()<<"request updating vehicle depot from vrptest_db success!!!!!";
        return true;
    }else
    {
        qDebug()<<"request updating vehicle depot from vrptest_db failed.....";
        return false;
    }
}

bool vrptest_db::VehSetCapacity(qint64 aVehId, qint64 aCapacity)
{
    QString queryString = QString("INSERT INTO VRPSIMVehicleReq VALUES(NULL,'%1','%2',NULL,'%3',NULL,NULL,NULL,NULL,NULL,NULL)")
            .arg(QString("capacity"))
            .arg(aVehId)
            .arg(aCapacity);
    qDebug()<<queryString;
    if(query->exec(queryString))
    {
        qDebug()<<"request updating vehicle capacity from vrptest_db success!!!!!";
        return true;
    }else
    {
        qDebug()<<"request updating vehicle capacity from vrptest_db failed.....";
        return false;
    }
}

bool vrptest_db::VehSetSpeed(qint64 aVehId, double aSpeed)
{
    QString queryString = QString("INSERT INTO VRPSIMVehicleReq VALUES(NULL,'%1','%2',NULL,NULL,'%3',NULL,NULL,NULL,NULL,NULL)")
            .arg(QString("speed"))
            .arg(aVehId)
            .arg(aSpeed);
    qDebug()<<queryString;
    if(query->exec(queryString))
    {
        qDebug()<<"request updating vehicle speed from vrptest_db success!!!!!";
        return true;
    }else
    {
        qDebug()<<"request updating vehicle speed from vrptest_db failed.....";
        return false;
    }
}

bool vrptest_db::VehSetRefuelTime(qint64 aVehId, qint64 aRefuelTime)
{
    QString queryString = QString("INSERT INTO VRPSIMVehicleReq VALUES(NULL,'%1','%2',NULL,NULL,NULL,'%3',NULL,NULL,NULL,NULL)")
            .arg(QString("refueltime"))
            .arg(aVehId)
            .arg(aRefuelTime);
    qDebug()<<queryString;
    if(query->exec(queryString))
    {
        qDebug()<<"request updating vehicle refueltime from vrptest_db success!!!!!";
        return true;
    }else
    {
        qDebug()<<"request updating vehicle refueltime from vrptest_db failed.....";
        return false;
    }
}

bool vrptest_db::VehSetFixTime(qint64 aVehId, qint64 aFixTime)
{
    QDateTime dateTime = QDateTime(QDateTime::currentDateTime());
    QString dateTimeString = dateTime.toString();

    QString queryString = QString("INSERT INTO VRPSIMVehicleReq VALUES(NULL,'%1','%2',NULL,NULL,NULL,NULL,'%3',NULL,NULL,NULL)")
            .arg(QString("fixtime"))
            .arg(aVehId)
            .arg(aFixTime);
    qDebug()<<queryString;
    if(query->exec(queryString))
    {
        qDebug()<<"request updating vehicle fixtime from vrptest_db success!!!!!";
        return true;
    }else
    {
        qDebug()<<"request updating vehicle fixtime from vrptest_db failed.....";
        return false;
    }
}

bool vrptest_db::VehSetUnitTime(qint64 aVehId, qint64 aUnitTime)
{
    QDateTime dateTime = QDateTime(QDateTime::currentDateTime());
    QString dateTimeString = dateTime.toString();

    QString queryString = QString("INSERT INTO VRPSIMVehicleReq VALUES(NULL,'%1','%2',NULL,NULL,NULL,NULL,NULL,'%3',NULL,NULL)")
            .arg(QString("unittime"))
            .arg(aVehId)
            .arg(aUnitTime);
    qDebug()<<queryString;
    if(query->exec(queryString))
    {
        qDebug()<<"request updating vehicle unittime from vrptest_db success!!!!!";
        return true;
    }else
    {
        qDebug()<<"request updating vehicle unittime from vrptest_db failed.....";
        return false;
    }
}

bool vrptest_db::VehSetBufferTime(qint64 aVehId, qint64 aBufferTime)
{
    QDateTime dateTime = QDateTime(QDateTime::currentDateTime());
    QString dateTimeString = dateTime.toString();

    QString queryString = QString("INSERT INTO VRPSIMVehicleReq VALUES(NULL,'%1','%2',NULL,NULL,NULL,NULL,NULL,NULL,'%3',NULL)")
            .arg(QString("buffertime"))
            .arg(aVehId)
            .arg(aBufferTime);
    qDebug()<<queryString;
    if(query->exec(queryString))
    {
        qDebug()<<"request updating vehicle buffertime from vrptest_db success!!!!!";
        return true;
    }else
    {
        qDebug()<<"request updating vehicle buffertime from vrptest_db failed.....";
        return false;
    }
}

bool vrptest_db::VehSetLaunchCost(qint64 aVehId, qint64 aLaunchCost)
{
    QDateTime dateTime = QDateTime(QDateTime::currentDateTime());
    QString dateTimeString = dateTime.toString();

    QString queryString = QString("INSERT INTO VRPSIMVehicleReq VALUES(NULL,'%1','%2',NULL,NULL,NULL,NULL,NULL,NULL,NULL,'%3')")
            .arg(QString("launchcost"))
            .arg(aVehId)
            .arg(aLaunchCost);
    qDebug()<<queryString;
    if(query->exec(queryString))
    {
        qDebug()<<"request updating vehicle launchcost from vrptest_db success!!!!!";
        return true;
    }else
    {
        qDebug()<<"request updating vehicle launchcost from vrptest_db failed.....";
        return false;
    }
}

//========================= VRP SIM CUS REQ=============================
bool vrptest_db::CusRequest(qint64 aCusId, qint64 aDemand, qint64 aPickupLoc, qint64 aDeliveryLoc, qint64 aReqTime, qint64 aWaitTime)
{
    //    QDateTime dateTime = QDateTime(QDateTime::currentDateTime());
    //    QString dateTimeString = dateTime.toString();

    QString queryString = QString("INSERT INTO VRPSIMCustomerReq VALUES (NULL,'%1','%2','%3','%4','%5','%6','%7')")
            .arg(QString("request"))
            .arg(aCusId)
            .arg(aDemand)
            .arg(aPickupLoc)
            .arg(aDeliveryLoc)
            .arg(aReqTime)
            .arg(aWaitTime);

    qDebug()<<queryString;
    if(query->exec(queryString))
    {
        qDebug()<<"request registering customer from vrptest_db success!!!!!";
        return true;
    }else
    {
        qDebug()<<"request registering customer from vrptest_db failed.....";
        return false;
    }
}

bool vrptest_db::CusDerequest(qint64 aCusId)
{
    QString queryString = QString("INSERT INTO VRPSIMCustomerReq VALUES (NULL,'%1','%2',NULL,NULL,NULL,NULL,NULL)")
            .arg(QString("derequest"))
            .arg(aCusId);

    qDebug()<<queryString;
    if(query->exec(queryString))
    {
        qDebug()<<"request deregistering customer from vrptest_db success!!!!!";
        return true;
    }else
    {
        qDebug()<<"request deregistering customer from vrptest_db failed.....";
        return false;
    }
}

bool vrptest_db::CusChgReq(qint64 aCusId, qint64 aDemand, qint64 aPickupLoc, qint64 aDeliveryLoc, qint64 aReqTime, qint64 aWaitTime)
{
    //    QDateTime dateTime = QDateTime(QDateTime::currentDateTime());
    //    QString dateTimeString = dateTime.toString();

    QString queryString = QString("INSERT INTO VRPSIMCustomerReq VALUES (NULL,'%1','%2','%3','%4','%5','%6','%7')")
            .arg(QString("chgreq"))
            .arg(aCusId)
            .arg(aDemand)
            .arg(aPickupLoc)
            .arg(aDeliveryLoc)
            .arg(aReqTime)
            .arg(aWaitTime);

    qDebug()<<queryString;
    if(query->exec(queryString))
    {
        qDebug()<<"request updating customer from vrptest_db success!!!!!";
        return true;
    }else
    {
        qDebug()<<"request updating customer from vrptest_db failed.....";
        return false;
    }
}


//========================= VRP SIM EVT REQ=============================
bool vrptest_db::OnArrivalEvent(qint64 aVehId, int SizeOfJob, qint64 aCusId, qint64 aDemand)
{
    QString queryString = QString("INSERT INTO VRPSIMEventReq VALUES (NULL,'%1','%2','%3','%4',NULL,'%5')")
            .arg(QString("arrival"))
            .arg(aVehId)
            .arg(aCusId)
            .arg(aDemand)
            .arg(SizeOfJob);
    qDebug()<<queryString;
    if(query->exec(queryString))
    {
        qDebug()<<"request arrival event from vrptest_db success!!!!!";
        return true;
    }else
    {
        qDebug()<<"request arrival event from vrptest_db failed.....";
        return false;
    }
}

bool vrptest_db::CusAnsPickup(qint64 aCusId, qint64 aVehId, QString aAns)
{
    QString queryString = QString("INSERT INTO VRPSIMEventReq VALUES (NULL,'%1','%2','%3',NULL,NULL,'%4')")
            .arg(QString("anspick"))
            .arg(aVehId)
            .arg(aCusId)
            .arg(aAns);
    qDebug()<<queryString;
    if(query->exec(queryString))
    {
        qDebug()<<"request anspick event from vrptest_db success!!!!!";
        return true;
    }else
    {
        qDebug()<<"request anspick event from vrptest_db failed.....";
        return false;
    }
}

bool vrptest_db::CusAnsDelivery(qint64 aCusId, qint64 aVehId, QString aAns)
{
    QString queryString = QString("INSERT INTO VRPSIMEventReq VALUES (NULL,'%1','%2','%3',NULL,NULL,'%4')")
            .arg(QString("ansdelivery"))
            .arg(aVehId)
            .arg(aCusId)
            .arg(aAns);
    qDebug()<<queryString;
    if(query->exec(queryString))
    {
        qDebug()<<"request anspick event from vrptest_db success!!!!!";
        return true;
    }else
    {
        qDebug()<<"request anspick event from vrptest_db failed.....";
        return false;
    }
}

bool vrptest_db::SetCurrentTime(qint64 aCurTime)
{
    QString queryString = QString("INSERT INTO VRPSIMEventReq VALUES (NULL,'%1',NULL,NULL,NULL,'%2',NULL)")
            .arg(QString("setcurtime"))
            .arg(aCurTime);
//            .arg(0);
    //    qDebug()<<queryString;
    if(query->prepare(queryString))
    {
//        qDebug()<<"is prepared";
    }else
    {
        qDebug()<<"not prepared";
    }
    if(query->exec(queryString))
    {
//        qDebug()<<"request setcurtime event from vrptest_db success!!!!!";
        return true;
    }else
    {
        QString tString;
        if(db->isOpen())
        {
            tString = "db is open";
        }else
        {
            tString = "db is closed";
        }
        QSqlError tError = query->lastError();
        qDebug() << "Sql Error" << tError;
        qDebug()<<tString;
        qDebug()<<queryString;
        qDebug()<<"request setcurtime event from vrptest_db failed.....";
        return false;
    }
}

void vrptest_db::RcvCusConfirmAns(qint64 aVehId, qint64 aCusId, QString aAnsStr)
{
    if(aAnsStr=="yes"){

    }else
    {
        qDebug()<<"delete customer request in FMS";
    }
    CusAnsPickup(aCusId,aVehId,aAnsStr);
}

bool vrptest_db::BackToDepotEvent(qint64 aVehId)
{
    QString queryString = QString("INSERT INTO VRPSIMEventReq VALUES (,'%1','%2',NULL,NULL,NULL,NULL)")
            .arg(QString("backtodepot"))
            .arg(aVehId);
    qDebug()<<queryString;
    if(query->exec(queryString))
    {
        qDebug()<<"request backtodepot event from vrptest_db success!!!!!";
        return true;
    }else
    {
        qDebug()<<"request backtodepot event from vrptest_db failed.....";
        return false;
    }
}

//======================================================================
//=============================== SUB ==================================
//======================================================================
void vrptest_db::starttimer()
{
    qDebug()<<"start DB scan Timer";
    scanVRPDBForLocCoord();
    scanVRPDBForVehCoord();
    scanVRPDBForVeh();
    scanVRPDBForCus();
    scanVRPDBForJob();
    scanVRPDBForCurTime();
    scanDBForVeh();
    scanDBForCus();
    scanDBForEvt();


    //    scanSummary();
    StartSysTimer();
    //    mpVehTimer = new QTimer(0);
    //    mpCusTimer = new QTimer(0);
    //    mpEvtTimer = new QTimer(0);
    mpScanTimer = new QTimer(0);

    //    connect(mpVehTimer,SIGNAL(timeout()),this,SLOT(scanDBForVeh()));
    //    connect(mpCusTimer,SIGNAL(timeout()),this,SLOT(scanDBForCus()));
    //    connect(mpEvtTimer,SIGNAL(timeout()),this,SLOT(scanDBForEvt()));
    connect(mpScanTimer,SIGNAL(timeout()),this,SLOT(scanSummary()));
    //    mpVehTimer->start(1000);
    //    mpCusTimer->start(1000);
    //    mpEvtTimer->start(1000);
    mpScanTimer->start(1000);

    //    StartSysTimer();
}

//SCAN FUNCTIONS======================================================
//Summary:
void vrptest_db::scanSummary()
{
    scanVRPDBForLocCoord();
    scanVRPDBForVehCoord();
    scanVRPDBForVeh();
    scanVRPDBForCus();
    scanVRPDBForJob();
    scanVRPDBForCurTime();
    scanDBForVeh();
    scanDBForCus();
    scanDBForEvt();
    CurTimerHit();
}

//Vehicle:
void vrptest_db::scanDBForVeh()
{
    //    qDebug()<<"Test Scan Vehicle";

    QList<QHash<QString,QString>> tReplyVehIDsToDelete;

    query->exec(QString("SELECT * FROM VRPSIMVehicleReply"));
    while(query->next())
    {
        //get type
        qint64 tReplyID = query->value("replyid").toLongLong();
        qint64 tVehID = query->value("vehid").toLongLong();
        QString tReplyType = query->value("type").toString();
        QString tResultStr = query->value("result").toString();

        //        bool tResult=false;
        //        if(tResultStr=="good")
        //            tResult = true;
        if(tReplyType == "register")
        {
            ExecuteVehRegisterReply(tVehID,tResultStr);
        }else if(tReplyType == "derequest")
        {
            ExecuteVehDeregisterReply(tVehID,tResultStr);
        }else if(tReplyType == "depot")
        {
            ExecuteVehSetDepotReply(tVehID,tResultStr);
        }else if(tReplyType == "capacity")
        {
            ExecuteVehSetCapacityReply(tVehID,tResultStr);
        }else if(tReplyType == "speed")
        {
            ExecuteVehSetSpeedReply(tVehID,tResultStr);
        }else if(tReplyType == "refueltime")
        {
            ExecuteVehSetRefuelTimeReply(tVehID,tResultStr);
        }else if(tReplyType == "fixtime")
        {
            ExecuteVehSetFixTimeReply(tVehID,tResultStr);
        }else if(tReplyType == "unittime")
        {
            ExecuteVehSetUnitTimeReply(tVehID,tResultStr);
        }else if(tReplyType == "buffertime")
        {
            ExecuteVehSetBufferTimeReply(tVehID,tResultStr);
        }else if(tReplyType == "launchcost")
        {
            ExecuteVehSetLaunchCostReply(tVehID,tResultStr);
        }else
        {
            qDebug()<<"bad msg";
        }

        QHash<QString,QString> tReplyInfos;
        tReplyInfos.insert("replyid",QString("%1").arg(tReplyID));
        tReplyInfos.insert("vehid",QString("%1").arg(tVehID));
        tReplyInfos.insert("type",tReplyType);
        tReplyVehIDsToDelete.append(tReplyInfos);
    }
    for(int i = 0; i < tReplyVehIDsToDelete.size();++i)
    {
        QString tReplyId = tReplyVehIDsToDelete.at(i).value("replyid");
        QString tVehId = tReplyVehIDsToDelete.at(i).value("vehid");
        QString tType = tReplyVehIDsToDelete.at(i).value("type");

        DeleteVehicleReply(tReplyId,tType,tVehId);
    }
}
//Customer:
void vrptest_db::scanDBForCus()
{
    //    qDebug()<<"Test Scan Customer";

    QList<QHash<QString,QString>> tReplyCusIDsToDelete;

    query->exec(QString("SELECT * FROM VRPSIMCustomerReply"));
    while(query->next())
    {
        qint64 tReplyID = query->value("replyid").toLongLong();
        qint64 tCusID = query->value("cusid").toLongLong();
        QString tReplyType = query->value("type").toString();
        QString tResultStr = query->value("result").toString();

        //        bool tResult = false;
        //        if(tResultStr=="success"/"registered"/"failed")
        //            tResult = true;
        if(tReplyType == "req")
        {
            ExecuteCusRequestReply(tCusID,tResultStr);
        }else if(tReplyType == "dereq")
        {
            ExecuteCusDerequestReply(tCusID,tResultStr);
        }else if(tReplyType == "chgreq")
        {
            ExecuteCusChangeRequestReply(tCusID,tResultStr);
        }else
        {
            qDebug()<<"bad msg";
        }

        QHash<QString,QString> tReplyInfos;
        tReplyInfos.insert("replyid",QString("%1").arg(tReplyID));
        tReplyInfos.insert("cusid",QString("%1").arg(tCusID));
        tReplyInfos.insert("type",tReplyType);
        tReplyCusIDsToDelete.append(tReplyInfos);
    }
    for(int i = 0; i < tReplyCusIDsToDelete.size();++i)
    {
        QString tReplyId = tReplyCusIDsToDelete.at(i).value("replyid");
        QString tCusId = tReplyCusIDsToDelete.at(i).value("cusid");
        QString tType = tReplyCusIDsToDelete.at(i).value("type");

        DeleteCustomerReply(tReplyId,tType,tCusId);
    }
}
//Event:
void vrptest_db::scanDBForEvt()
{
    //    qDebug()<<"Test Scan Event";

    QList<QHash<QString,QString>> tReplyEvtIDsToDelete;

    query->exec(QString("SELECT * FROM VRPSIMEventReply"));
    while(query->next())
    {
        qint64 tReplyID = query->value("replyid").toLongLong();
        qint64 tVehID = query->value("vehid").toLongLong();
        qint64 tCusID = query->value("cusid").toLongLong();
        QString tReplyType = query->value("type").toString();
        QString tResultStr = query->value("result").toString();

        if(tReplyType == "arrivalevent")
        {
            qint64 tWaitTime = tResultStr.toLongLong();
            ExecuteEvtVehicleArrivalReply(tVehID,tCusID,tWaitTime);
        }else if(tReplyType == "triggerPU")
        {
            qint64 tWaitTime = tResultStr.toLongLong();
            ExecuteEvtTriggerPUNoticeReply(tVehID,tCusID,tWaitTime);
        }else if(tReplyType == "triggerDL")
        {
            qint64 tWaitTime = tResultStr.toLongLong();
            ExecuteEvtTriggerDLNoticeReply(tVehID,tCusID,tWaitTime);
        }else if(tReplyType == "expirePU")
        {
            ExecutePUEvtExpireReply(tVehID,tCusID);
        }else if(tReplyType == "expireDL")
        {
            ExecuteDLEvtExpireReply(tVehID,tCusID);
        }
        else if(tReplyType == "backtodepot")
        {
            ExecuteEvtVehBackDepotReply(tVehID,tResultStr);
        }else if(tReplyType == "settlePU")
        {
            ExecuteEvtSettlePUReply(tVehID,tCusID,tResultStr);
        }else if(tReplyType == "settleDL")
        {
            ExecuteEvtSettleDLReply(tVehID,tCusID,tResultStr);
        }
        else if(tReplyType == "updateETA")
        {
            ExecuteEvtUpdateETA(tCusID,tResultStr);
        }
        else if(tReplyType == "move")
        {
            ExecuteEvtTriggerMove(tVehID);
        }
        else
        {
            qDebug()<<"bad reply msg";
        }

        QHash<QString,QString> tReplyInfos;
        tReplyInfos.insert("replyid",QString("%1").arg(tReplyID));
        tReplyInfos.insert("vehid",QString("%1").arg(tVehID));
        tReplyInfos.insert("cusid",QString("%1").arg(tCusID));
        tReplyInfos.insert("type",tReplyType);
        tReplyEvtIDsToDelete.append(tReplyInfos);
    }
    for(int i = 0; i < tReplyEvtIDsToDelete.size();++i)
    {
        QString tReplyId = tReplyEvtIDsToDelete.at(i).value("replyid");
        QString tVehId = tReplyEvtIDsToDelete.at(i).value("vehid");
        QString tCusId = tReplyEvtIDsToDelete.at(i).value("cusid");
        QString tType = tReplyEvtIDsToDelete.at(i).value("type");

        DeleteEventReply(tReplyId,tType,tVehId,tCusId);
    }
}
//========================================================================

//SCAN FUNCTIONS FOR SYNCRONIZATION=======================================
//Landmark Coord
void vrptest_db::scanVRPDBForLocCoord()
{
    QList<qint64> tLocIds = mLocCoordTimeStamps.keys();
    query->exec(QString("SELECT * FROM VRPLocCoordMat"));
    while(query->next())
    {
        qint64 tLocId = query->value("landmarkID").toLongLong();
        QString tTimeString = query->value("time").toString();
        double tLat = query->value("lat").toDouble();
        double tLong = query->value("long").toDouble();

        if(mLocCoordTimeStamps.contains(tLocId))
        {
            if(mLocCoordTimeStamps.value(tLocId)==tTimeString)
            {
                //do nothing
            }else
            {
                //here is a update
                mLocCoordTimeStamps[tLocId] = tTimeString;
                emit informUpdateLocCoordByScan(tLocId,tLat,tLong);
            }
        }else
        {
            mLocCoordTimeStamps.insert(tLocId,tTimeString);
            emit informAddLocCoordByScan(tLocId,tLat,tLong);
        }

        if(tLocIds.contains(tLocId))
        {
            if(tLocIds.removeOne(tLocId))
            {}
        }
    }
    if(tLocIds.size()>0)
    {
        //call delete
        for(int i = 0; i < tLocIds.size(); ++i)
        {
            emit informDeleteLocCoordByScan(tLocIds.at(i));
            mLocCoordTimeStamps.remove(tLocIds.at(i));
        }
    }
}

//Vehicle Coord
void vrptest_db::scanVRPDBForVehCoord()
{
    QList<qint64> tVehIds = mVehCoordTimeStamps.keys();

    query->exec(QString("SELECT * FROM VRPVehCoordMat"));
    while(query->next())
    {
        qint64 tVehId = query->value("vehicleID").toLongLong();
        QString tTimeString = query->value("time").toString();
        double tLat = query->value("lat").toDouble();
        double tLong = query->value("long").toDouble();

        if(mVehCoordTimeStamps.contains(tVehId))
        {
            if(mVehCoordTimeStamps.value(tVehId)==tTimeString)
            {
                //do nothing
            }else
            {
                //here is a update
                mVehCoordTimeStamps[tVehId] = tTimeString;
                emit informUpdateVehCoordByScan(tVehId,tLat,tLong);
            }
        }else
        {
            mVehCoordTimeStamps.insert(tVehId,tTimeString);
            emit informAddVehCoordByScan(tVehId,tLat,tLong);
        }

        if(tVehIds.contains(tVehId))
        {
            if(tVehIds.removeOne(tVehId))
            {}
        }
    }

    if(tVehIds.size()>0)
    {
        //call delete
        for(int i = 0; i < tVehIds.size(); ++i)
        {
            emit informDeleteVehCoordByScan(tVehIds.at(i));
            mVehCoordTimeStamps.remove(tVehIds.at(i));
        }
    }
}

//Vehicle:
void vrptest_db::scanVRPDBForVeh()
{
    QList<qint64> tVehIds = mVehTimeStamps.keys();
    query->exec(QString("SELECT * FROM VRPVehicleMat"));
    while(query->next())
    {
        qint64 tVehId = query->value("vehicle_id").toLongLong();
        QString tTimeString = query->value("time").toString();
        qint64 tCapacity = query->value("capacity").toLongLong();
        double tSpeed = query->value("speed").toDouble();
        qint64 tRefuelTime = query->value("refuel_time").toLongLong();
        qint64 tFixTime = query->value("fix_wait_secs").toLongLong();
        qint64 tUnitTime = query->value("unit_wait_secs").toLongLong();
        qint64 tBufferTime = query->value("buffer_secs").toLongLong();
        qint64 tLaunchCost = query->value("launch_cost").toLongLong();
        qint64 tCost = query->value("cost").toLongLong();
        int tInDepot = query->value("indepot").toInt();

        if(mVehTimeStamps.contains(tVehId))
        {
            if(mVehTimeStamps.value(tVehId)==tTimeString)
            {
                //do nothing
            }else
            {
                //here is just a change
                //update
                mVehTimeStamps[tVehId] = tTimeString;
                emit informUpdateVehByScan(tVehId, tCapacity, tSpeed, tRefuelTime, tFixTime, tUnitTime, tBufferTime, tLaunchCost);
            }
        }else{
            mVehTimeStamps.insert(tVehId,tTimeString);
            emit informRegisterVehByScan(tVehId,tCapacity,tSpeed,tRefuelTime,tFixTime,tUnitTime,tBufferTime,tLaunchCost, tCost, tInDepot);
        }

        //check for indepot
        if(mVehInDepots.contains(tVehId))
        {
            if(mVehInDepots.value(tVehId)==tInDepot)
            {
                //do nothing
            }else
            {
                mVehInDepots[tVehId] = tInDepot;
                emit informUpdateVehInDepotByScan(tVehId,tInDepot);
            }
        }else
        {
            mVehInDepots.insert(tVehId,tInDepot);
        }

        //check for cost
        if(mVehCosts.contains(tVehId))
        {
            if(mVehCosts.value(tVehId)==tCost)
            {
                //do nothing
            }else
            {
                mVehCosts[tVehId] = tCost;
                emit informUpdateVehCostByScan(tVehId,tCost);
            }
        }else
        {
            mVehCosts.insert(tVehId,tCost);
        }

        //check for delete
        if(tVehIds.contains(tVehId))
        {
            if(tVehIds.removeOne(tVehId))
            {}
        }
    }

    if(tVehIds.size()>0)
    {
        //call delete
        for(int i = 0; i < tVehIds.size(); ++i)
        {
            emit informDeregisterVehByScan(tVehIds.at(i));
            mVehTimeStamps.remove(tVehIds.at(i));
            mVehCosts.remove(tVehIds.at(i));
            mVehInDepots.remove(tVehIds.at(i));
        }
    }
}

void vrptest_db::scanVRPDBForCus()
{
    QList<qint64> tCusIds = mCusTimeStamps.keys();

    query->exec(QString("SELECT * FROM VRPCustomerMat"));
    while(query->next())
    {
        qint64 tCusId = query->value("customer_id").toLongLong();
        QString tTimeString = query->value("time").toString();
        qint64 tAssignedVeh = query->value("assigned_vehicle").toLongLong();
        qint64 tDemand = query->value("demand").toLongLong();
        qint64 tPULoc = query->value("pickup_Loc").toLongLong();
        qint64 tDLoc = query->value("delivery_Loc").toLongLong();
        qint64 tRTime = query->value("request_time").toLongLong();
        qint64 tWTime = query->value("waiting_time").toLongLong();
        int tPUFlag = query->value("pickedup_flag").toInt();

        if(mCusTimeStamps.contains(tCusId))
        {
            if(mCusTimeStamps.value(tCusId)==tTimeString)
            {
                //do nothing
            }else
            {
                //here is just a change
                //update
                mCusTimeStamps[tCusId] = tTimeString;
                emit informUpdateRequestByScan(tCusId,tAssignedVeh,tDemand,tPULoc,tDLoc,tRTime,tWTime);
            }
        }else
        {
            mCusTimeStamps.insert(tCusId, tTimeString);
            emit informAddRequestByScan(tCusId,tAssignedVeh,tDemand,tPULoc,tDLoc,tRTime,tWTime,tPUFlag);
        }

        if(mCusPUFlags.contains(tCusId))
        {
            if(mCusPUFlags.value(tCusId)==tPUFlag)
            {

            }else
            {
                mCusPUFlags[tCusId]=tPUFlag;
                emit informGetPickedUpByScan(tCusId);
            }
        }else
        {
            mCusPUFlags.insert(tCusId,tPUFlag);
        }

        if(tCusIds.contains(tCusId))
        {
            if(tCusIds.removeOne(tCusId))
            {}
        }
    }

    if(tCusIds.size()>0)
    {
        //call delete
        for(int i = 0; i < tCusIds.size(); ++i)
        {
            emit informCancelRequestByScan(tCusIds.at(i));
            mCusTimeStamps.remove(tCusIds.at(i));
            mCusPUFlags.remove(tCusIds.at(i));
        }
    }
}

void vrptest_db::scanVRPDBForJob()
{
    query->exec(QString("SELECT * FROM VRPJobListMat"));

    QList<qint64> tShouldVehList;

    QHash<qint64, QList<qint64>> tVehJobIds;//existed mark
    for(int i = 0; i < mVehJobs.keys().size(); ++i)
    {
        tVehJobIds.insert(mVehJobs.keys().at(i),mVehJobs.value(mVehJobs.keys().at(i)).keys());
    }

    while(query->next())
    {
        qint64 tJobId = query->value("job_id").toLongLong();
        qint64 tVehId = query->value("vehicle_id").toLongLong();
        qint64 tLocId = query->value("loc").toLongLong();
        qint64 tOpenTime = query->value("open_time").toLongLong();
        qint64 tCloseTime = query->value("close_time").toLongLong();
        qint64 tDemand = query->value("demand").toLongLong();
        qint64 tCusId = query->value("cusid").toLongLong();

        if(tLocId>0)
        {
            QHash<QString,qint64> tJob;
            tJob.insert("loc",tLocId);
            tJob.insert("opentime",tOpenTime);
            tJob.insert("closetime",tCloseTime);
            tJob.insert("demand",tDemand);
            tJob.insert("cus",tCusId);

            if(mVehJobs.keys().contains(tVehId))
            {
                if(mVehJobs.value(tVehId).contains(tJobId))
                {
                    //do nothing
                    //delete the existed
                    tVehJobIds[tVehId].removeOne(tJobId);
                }else
                {
                    if(tShouldVehList.contains(tVehId))
                    {
                        mVehJobs[tVehId].insert(tJobId,tJob);
                    }else
                    {
                        tShouldVehList.append(tVehId);
                        mVehJobs[tVehId].insert(tJobId,tJob);
                    }
                }
            }else
            {
                tShouldVehList.append(tVehId);
                QHash<qint64,QHash<QString,qint64>> tJobs;
                tJobs.insert(tJobId,tJob);
                mVehJobs.insert(tVehId,tJobs);
            }
        }else
        {
            //ignore
        }
    }

    //only the deleted existeds should be left
    //delete them in sim
    QList<qint64> tVehIds = tVehJobIds.keys();
    for(int i = 0; i < tVehIds.size(); ++i)
    {
        if(tVehJobIds.value(tVehIds.at(i)).size()>0)
        {
            //update the mVehJobs
            for(int j = 0; j < tVehJobIds.value(tVehIds.at(i)).size(); ++j)
            {
                mVehJobs[tVehIds.at(i)].remove(tVehJobIds.value(tVehIds.at(i)).at(j));
            }

            //activate the veh for updating
            if(!tShouldVehList.contains(tVehIds.at(i)))
            {
                tShouldVehList.append(tVehIds.at(i));
            }
        }
    }

    //sort the mVehJobs for activated ones according to close time for sending
    QHash<qint64, QList<QHash<QString,qint64>>> tSendingJobs;



    for(int i = 0; i < tShouldVehList.size(); ++i)
    {

        qint64 tVehId = tShouldVehList.at(i);
        QList<qint64> tJobIds = mVehJobs.value(tVehId).keys();
        QList<QHash<QString,qint64>> tJobsList;
        QHash<qint64,QHash<QString,qint64>> tJobsHash = mVehJobs.value(tVehId);
        for(int j = 0; j < tJobIds.size(); ++j)
        {
            qint64 tJobId = tJobIds.at(j);
            QHash<QString,qint64> tJob = tJobsHash.value(tJobId);
            tJobsList.append(tJob);
        }
        if(tJobsList.size()>0)
        {
            qSort(tJobsList.begin(),tJobsList.end(),CMP);
        }

        if(mVehJobs.value(tVehId).size()==0)
        {
            mVehJobs.remove(tVehId);
        }
        emit informJobUpdateByScan(tVehId,tJobsList);


        //        for(int j = 0; j < tJobIds.size(); ++j)
        //        {
        //            qint64 tJobId = tJobIds.at(j);
        //            QHash<QString,qint64> tJob = mVehJobs.value(tVehId).value(tJobId);
        //            if(j==0)
        //            {
        //                tJobList.append(tJob);
        //            }else
        //            {
        //                bool inserted = false;

        //                for(int k = 0; k < tJobList.size(); ++k)
        //                {
        //                    if(tJob.value("closetime")<=tJobList.at(k).value("closetime"))
        //                    {
        //                        tJobList.insert(k,mVehJobs.value(tVehId))
        //                    }
        //                }
        //            }
        //        }
    }
}

void vrptest_db::scanVRPDBForCurTime()
{
    query->exec(QString("SELECT * FROM VRPCurTime"));

    while(query->next())
    {
        qint64 tSimTime = query->value("currentTime").toLongLong();

        if(!scanCurTimeFirstCalled)
        {
            //set the initial diff time according to the time still existed in vrpmaster
            //get the current time
            QTime tRealTime = QTime::currentTime();
            QString tRealTimeStr = tRealTime.toString("hh:mm:ss");
            //get the sim time
            qint64 rSimTime = RealToSimTime(tRealTimeStr);
            mCurTimeDiff = tSimTime - rSimTime;
            //if first scan got no entry...then no pre defined time in vrpmaster, just wont' go into this loop
            mSimTime = tSimTime;
            mRealTime = SimToRealTime(mSimTime);
            emit curTimeChanged();
            scanCurTimeFirstCalled=true;
        }else
        {
            if(mSimTime!=tSimTime)
            {
                mSimTime=tSimTime;
                mRealTime = SimToRealTime(mSimTime);
                emit curTimeChanged();
            }
        }
    }
}

//========================================================================

//DELETE FUNCTIONS========================================================
void vrptest_db::DeleteVehicleReply(QString aReplyId, QString aType, QString aVehId)
{
    QString queryString = QString("DELETE FROM VRPSIMVehicleReply WHERE replyid = '%1'")
            .arg(aReplyId);

    qDebug()<<queryString;
    if(query->exec(queryString))
    {
        qDebug()<<QString("delete reply type:[%1] for vehid:[%2] succeed!!!!!")
                  .arg(aType)
                  .arg(aVehId);
    }else
    {
        qDebug()<<QString("delete reply type:[%1] for vehid:[%2] failed.....")
                  .arg(aType)
                  .arg(aVehId);
    }
}

void vrptest_db::DeleteCustomerReply(QString aReplyId, QString aType, QString aCusId)
{
    QString queryString = QString("DELETE FROM VRPSIMCustomerReply WHERE replyid = '%1'")
            .arg(aReplyId);

    qDebug()<<queryString;
    if(query->exec(queryString))
    {
        qDebug()<<QString("delete reply type:[%1] for cusid:[%2] succeed!!!!!")
                  .arg(aType)
                  .arg(aCusId);
    }else
    {
        qDebug()<<QString("delete reply type:[%1] for cusid:[%2] failed.....")
                  .arg(aType)
                  .arg(aCusId);
    }
}

void vrptest_db::DeleteEventReply(QString aReplyId, QString aType, QString aVehId, QString aCusId)
{
    QString queryString = QString("DELETE FROM VRPSIMEventReply WHERE replyid = '%1'").arg(aReplyId);

    qDebug()<<queryString;
    if(query->exec(queryString))
    {
        if(aType == "arrivalevent")
        {
            qDebug()<<QString("delete reply type:[%1] veh:[%2] succeed!!!!!")
                      .arg(aType)
                      .arg(aVehId);
        }else if(aType == "trigger")
        {
            qDebug()<<QString("delete reply type:[%1] veh:[%2] cus:[%3] succeed!!!!!")
                      .arg(aType)
                      .arg(aVehId)
                      .arg(aCusId);
        }else if(aType == "expire")
        {
            qDebug()<<QString("delete reply type:[%1] veh:[%2] cus:[%3] succeed!!!!!")
                      .arg(aType)
                      .arg(aVehId)
                      .arg(aCusId);
        }else if(aType == "backtodepot")
        {
            qDebug()<<QString("delete reply type:[%1] veh:[%2] succeed!!!!!")
                      .arg(aType)
                      .arg(aVehId);
        }
    }else
    {
        if(aType == "arrivalevent")
        {
            qDebug()<<QString("delete reply type:[%1] veh:[%2] failed.....")
                      .arg(aType)
                      .arg(aVehId);
        }else if(aType == "trigger")
        {
            qDebug()<<QString("delete reply type:[%1] veh:[%2] cus:[%3] failed.....")
                      .arg(aType)
                      .arg(aVehId)
                      .arg(aCusId);
        }else if(aType == "expire")
        {
            qDebug()<<QString("delete reply type:[%1] veh:[%2] cus:[%3] failed.....")
                      .arg(aType)
                      .arg(aVehId)
                      .arg(aCusId);
        }else if(aType == "backtodepot")
        {
            qDebug()<<QString("delete reply type:[%1] veh:[%2] failed.....")
                      .arg(aType)
                      .arg(aVehId);
        }
    }
}
//=============================================================================

//EXCUTE FUNCTIONS=============================================================
//Vehicle:
void vrptest_db::ExecuteVehRegisterReply(qint64 aVehId, QString aResult)
{
    qDebug()<<QString("[VehRegister] VehID: %1 Ret: %2").arg(aVehId).arg(aResult);
}

void vrptest_db::ExecuteVehDeregisterReply(qint64 aVehId, QString aResult)
{
    qDebug()<<QString("[VehDeregister] VehID: %1 Ret: %2").arg(aVehId).arg(aResult);
}

void vrptest_db::ExecuteVehSetDepotReply(qint64 aVehId, QString aResult)
{
    qDebug()<<QString("[VehSetDepot] VehID: %1 Ret: %2").arg(aVehId).arg(aResult);
}

void vrptest_db::ExecuteVehSetCapacityReply(qint64 aVehId, QString aResult)
{
    qDebug()<<QString("[VehSetCapacity] VehID: %1 Ret: %2").arg(aVehId).arg(aResult);
}

void vrptest_db::ExecuteVehSetSpeedReply(qint64 aVehId, QString aResult)
{
    qDebug()<<QString("[VehSetSpeed] VehID: %1 Ret: %2").arg(aVehId).arg(aResult);
}

void vrptest_db::ExecuteVehSetRefuelTimeReply(qint64 aVehId, QString aResult)
{
    qDebug()<<QString("[VehSetRefuelTime] VehID: %1 Ret: %2").arg(aVehId).arg(aResult);
}

void vrptest_db::ExecuteVehSetFixTimeReply(qint64 aVehId, QString aResult)
{
    qDebug()<<QString("[VehSetFixTime] VehID: %1 Ret: %2").arg(aVehId).arg(aResult);
}

void vrptest_db::ExecuteVehSetUnitTimeReply(qint64 aVehId, QString aResult)
{
    qDebug()<<QString("[VehSetUnitTime] VehID: %1 Ret: %2").arg(aVehId).arg(aResult);
}

void vrptest_db::ExecuteVehSetBufferTimeReply(qint64 aVehId, QString aResult)
{
    qDebug()<<QString("[VehSetBufferTime] VehID: %1 Ret: %2").arg(aVehId).arg(aResult);
}

void vrptest_db::ExecuteVehSetLaunchCostReply(qint64 aVehId, QString aResult)
{
    qDebug()<<QString("[VehSetLaunchCost] VehID: %1 Ret: %2").arg(aVehId).arg(aResult);
}
//Customer:
void vrptest_db::ExecuteCusRequestReply(qint64 aCusId, QString aResult)
{
    qDebug()<<QString("[CusRequest] VehID: %1 Ret: %2").arg(aCusId).arg(aResult);
    emit fbCusRequestByGW(aCusId, aResult);
}
void vrptest_db::ExecuteCusDerequestReply(qint64 aCusId, QString aResult)
{
    qDebug()<<QString("[CusDerequest] VehID: %1 Ret: %2").arg(aCusId).arg(aResult);
    emit fbCusDelRequestByGW(aCusId, aResult);
}
void vrptest_db::ExecuteCusChangeRequestReply(qint64 aCusId, QString aResult)
{
    qDebug()<<QString("[CusChgRequest] VehID: %1 Ret: %2").arg(aCusId).arg(aResult);
    emit fbCusUpdateRequestByGW(aCusId, aResult);
}
//Event:
void vrptest_db::ExecuteEvtVehicleArrivalReply(qint64 aVehId, qint64 aCusId, qint64 aWaitTime)
{
    qDebug()<<QString("[EventVehArrival] VehID: %1 CusID: %2 WaitTime: %3").arg(aVehId).arg(aCusId).arg(aWaitTime);
    //0907:
    //report the waiting time to FMS
    fmsDbReader->sendWaitingTimeToFMS(aVehId, aWaitTime);
}
void vrptest_db::ExecuteEvtTriggerPUNoticeReply(qint64 aVehId, qint64 aCusId, qint64 aWaitTime)
{
    qDebug()<<QString("[TriggerPUNotice] VehID: %1 CusID: %2 WaitTime: %3").arg(aVehId).arg(aCusId).arg(aWaitTime);
    //    emit createArrAnsDialogSignal(aVehId,aCusId,aWaitTime);
    emit addArrPUAnsToUI(aVehId,aCusId,aWaitTime);
    emit addArrPUAnsToGW(aCusId,aWaitTime);
}
void vrptest_db::ExecuteEvtTriggerDLNoticeReply(qint64 aVehId, qint64 aCusId, qint64 aWaitTime)
{
    qDebug()<<QString("[TriggerDLNotice] VehID: %1 CusID: %2 WaitTime: %3").arg(aVehId).arg(aCusId).arg(aWaitTime);
    emit addArrDLAnsToUI(aVehId,aCusId,aWaitTime);
    emit addArrDLAnsToGW(aCusId,aWaitTime);
}

void vrptest_db::ExecutePUEvtExpireReply(qint64 aVehId, qint64 aCusId)
{
    qDebug()<<QString("[WaitPUExpired] CusID: %1 VehID: %2").arg(aCusId).arg(aVehId);
    //    emit deleteArrAnsDialogSignal(aVehId,aCusId);
    emit expirePUArrAnsFromUI(aVehId,aCusId);
    emit reportExpirePUArrAnsToGW(aCusId);
}
void vrptest_db::ExecuteDLEvtExpireReply(qint64 aVehId, qint64 aCusId)
{
    qDebug()<<QString("[WaitDLExpired] CusID: %1 VehID: %2").arg(aCusId).arg(aVehId);
    //    emit deleteArrAnsDialogSignal(aVehId,aCusId);
    emit expireDLArrAnsFromUI(aVehId,aCusId);
    emit reportExpireDLArrAnsToGW(aCusId);
}
void vrptest_db::ExecuteEvtVehBackDepotReply(qint64 aVehId, QString aResult)
{
    qDebug()<<QString("[EventVehBackDepot] VehID: %1 Ret: %2").arg(aVehId).arg(aResult);
}
void vrptest_db::ExecuteEvtSettlePUReply(qint64 aVehId, qint64 aCusId, QString aResultStr)
{
    qDebug()<<QString("[EventSettlePU] VehID: %1 CusID: %2 Result: %3").arg(aVehId).arg(aCusId).arg(aResultStr);
    emit fbSettlePUArrAnsToGW(aCusId, aResultStr);
}

void vrptest_db::ExecuteEvtSettleDLReply(qint64 aVehId, qint64 aCusId, QString aResultStr)
{
    qDebug()<<QString("[EventSettleDL] VehID: %1 CusID: %2").arg(aVehId).arg(aCusId);
    emit fbSettleDLArrAnsToGW(aCusId, aResultStr);
}

void vrptest_db::ExecuteEvtUpdateETA(qint64 aCusId, QString aOpenTimes)
{
    qDebug()<<QString("[EventUpdateETA] CusID: %1").arg(aCusId);
    emit updateETAToGW(aCusId, aOpenTimes);
}

void vrptest_db::ExecuteEvtTriggerMove(qint64 aVehId)
{
    qDebug()<<QString("[EventUpdateETA] VehID: %1").arg(aVehId);
    //0907:
    //emit the trigger event to fmsdb
    fmsDbReader->triggerVehicleMoving(aVehId);
}

//==========================================================
//Time Related
QString vrptest_db::SimToRealTime(qint64 aSimTime)
{
    int tHour = aSimTime / 3600;
    int tMin = (aSimTime - tHour*3600) / 60;
    int tSec = aSimTime - tHour * 3600 - tMin * 60;
    tHour += mStartHour;
    QString tHourStr = RealTimeStringlize(tHour);
    QString tMinStr = RealTimeStringlize(tMin);
    QString tSecStr = RealTimeStringlize(tSec);

    QString tTimeStr = QString("%1:%2:%3").arg(tHourStr).arg(tMinStr).arg(tSecStr);
    return tTimeStr;
}

qint64 vrptest_db::RealToSimTime(QString aRealTime)
{
    int tHour = aRealTime.split(":").at(0).toInt();
    int tMin = aRealTime.split(":").at(1).toInt();
    int tSec = aRealTime.split(":").at(2).toInt();

    return (tHour-mStartHour)*3600 + tMin*60 + tSec;
}

QString vrptest_db::RealTimeStringlize(int aTimeParam)
{
    if(aTimeParam/10==0)
        return QString("0%1").arg(aTimeParam);
    else
        return QString("%1").arg(aTimeParam);
}

void vrptest_db::StartSysTimer()
{
    //This must be after the first scan of VRPDBForCurTime called

    //get the current time
    QTime tRealTime = QTime::currentTime();
    QString tRealTimeStr = tRealTime.toString("hh:mm:ss");
    //get the sim time
    qint64 tSimTime = RealToSimTime(tRealTimeStr);
    qDebug()<<"1sim time:"<<tSimTime;

    SetCurrentTime(tSimTime + mCurTimeDiff);

    //    mpCurTimer = new QTimer(0);
    //    connect(mpCurTimer,SIGNAL(timeout()),this,SLOT(CurTimerHit()));
    //    mpCurTimer->start(1000);
}

void vrptest_db::CurTimerHit()
{
    QTime tRealTime = QTime::currentTime();
    QString tRealTimeStr = tRealTime.toString("hh:mm:ss");
    qint64 tSimTime = RealToSimTime(tRealTimeStr);
    //    qDebug()<<"realtime:"<<tRealTimeStr<<"simtime"<<tSimTime;
//    qDebug()<<"2sim time:"<<tSimTime;
    SetCurrentTime(tSimTime + mCurTimeDiff);
}
