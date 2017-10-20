#include "vrptest_stkci_sub.h"

vrptest_stkci_sub::vrptest_stkci_sub(QObject *parent) :
    QObject(parent)
{
}

void vrptest_stkci_sub::setup()
{
    qDebug()<<"Setup Connection for VRPTest Subscriber";

    if(mSubInterface.setup("VRPInterfaceConfigFile.xml",mProfile)==STKCI::InterfaceRetCode_OK)
    {
        qDebug()<<"Setup OK! ";
        STKCI::tree_node tConfigTree;
        mSubInterface.GetConfiguration(tConfigTree);
        qDebug()<<"Configuration: ";
        {
            STKCI::txml_doc_writer tWriter;
            tWriter.WriteToStream(std::cout,&tConfigTree);
        }
//        qRegisterMetaType<QPair>
    }
}

void vrptest_stkci_sub::close()
{
    qDebug()<<"Close Connection ";
    mSubInterface.close();
}

void vrptest_stkci_sub::starttimer()
{
    QTimer *timer = new QTimer(0);
    connect(timer,SIGNAL(timeout()),this,SLOT(listen()));
    timer->start(1000);
}

void vrptest_stkci_sub::listen()
{
        STKCI::ExampleMainMsgSeq aMessageSeq;
//        qDebug()<<"listening";
        if(mSubInterface.takewithTimeout(aMessageSeq,1000)==STKCI::InterfaceRetCode_OK)
        {
            qDebug()<<"::Received Messages (Timed Take)!!::";
            for(STKCI::ExampleMainMsg& tMessage:aMessageSeq)
            {
                if(tMessage.mKeyId==mKeyId){
                    qDebug()<<"  >>Message";

                    std::string tmsg = tMessage.msg;
                    QString msg = QString::fromLocal8Bit(tmsg.c_str());
                    QStringList msgfrags = msg.split("|");

                    if(msgfrags[0]=="feedback")
                    {
                        if(msgfrags[1]=="cus")
                        {

                            if(msgfrags[2]=="req")
                            {
                                qint64 tCusID = tMessage.mID;
                                qint64 tRetCode = tMessage.EXAMPLEVALUE;
                                qint64 tVehID = tMessage.mSegment.mSegmentID;

                                qDebug()<<QString("[CusRequest] CusID: %1 tRet: %2 VehID:%3").arg(tCusID).arg(tRetCode).arg(tVehID);
                            }else if(msgfrags[2]=="dereq")
                            {
                                qint64 tCusID = tMessage.mID;
                                qint64 tRetCode = tMessage.EXAMPLEVALUE;

                                qDebug()<<QString("[CusDerequest] CusID: %1 Ret: %2").arg(tCusID).arg(tRetCode);
                            }else if(msgfrags[2]=="chgreq")
                            {
                                qint64 tCusID = tMessage.mID;
                                qint64 tRetCode = tMessage.EXAMPLEVALUE;

                                qDebug()<<QString("[CusChgReq] CusID: %1 Ret: %2").arg(tCusID).arg(tRetCode);
                            }/*else if(msgfrags[2]=="ans")
                            {

                            }*/else
                            {
                                qDebug()<<"bad msg";
                            }
                        }else if(msgfrags[1]=="veh")
                        {
                            if(msgfrags[2]=="arrivalevent")
                            {
                                qint64 tVehID = tMessage.mID;
                                qint64 tWaitingTime = tMessage.EXAMPLEVALUE;

                                qDebug()<<QString("[VehArrEvt] VehID: %1 WaitingTime: %2").arg(tVehID).arg(tWaitingTime);

                                //set waiting time of veh in fms...
                                {
                                    //......
                                }
                            }else if(msgfrags[2]=="register")
                            {
                                qint64 tVehID = tMessage.mID;
                                qint64 tRet = tMessage.EXAMPLEVALUE;

                                qDebug()<<QString("[VehRegister] VehID: %1 Ret: %2").arg(tVehID).arg(tRet);
                            }else if(msgfrags[2]=="derequest")
                            {
                                qint64 tVehID = tMessage.mID;
                                qint64 tRet = tMessage.EXAMPLEVALUE;

                                qDebug()<<QString("[VehDeregister] VehID: %1 Ret: %2").arg(tVehID).arg(tRet);
                            }else if(msgfrags[2]=="depot")
                            {
                                qint64 tVehID = tMessage.mID;
                                qint64 tRet = tMessage.EXAMPLEVALUE;

                                qDebug()<<QString("[VehSetDepot] VehID: %1 Ret: %2").arg(tVehID).arg(tRet);
                            }else if(msgfrags[2]=="capacity")
                            {
                                qint64 tVehID = tMessage.mID;
                                qint64 tRet = tMessage.EXAMPLEVALUE;

                                qDebug()<<QString("[VehSetCapacity] VehID: %1 Ret: %2").arg(tVehID).arg(tRet);
                            }else if(msgfrags[2]=="speed")
                            {
                                qint64 tVehID = tMessage.mID;
                                qint64 tRet = tMessage.EXAMPLEVALUE;

                                qDebug()<<QString("[VehSetSpeed] VehID: %1 Ret: %2").arg(tVehID).arg(tRet);
                            }else if(msgfrags[2]=="refueltime")
                            {
                                qint64 tVehID = tMessage.mID;
                                qint64 tRet = tMessage.EXAMPLEVALUE;

                                qDebug()<<QString("[VehSetRefuelTime] VehID: %1 Ret: %2").arg(tVehID).arg(tRet);
                            }else if(msgfrags[2]=="fixtime")
                            {
                                qint64 tVehID = tMessage.mID;
                                qint64 tRet = tMessage.EXAMPLEVALUE;

                                qDebug()<<QString("[VehSetFixTime] VehID: %1 Ret: %2").arg(tVehID).arg(tRet);
                            }else if(msgfrags[2]=="unittime")
                            {
                                qint64 tVehID = tMessage.mID;
                                qint64 tRet = tMessage.EXAMPLEVALUE;

                                qDebug()<<QString("[VehSetUnitTime] VehID: %1 Ret: %2").arg(tVehID).arg(tRet);
                            }else if(msgfrags[2]=="buffertime")
                            {
                                qint64 tVehID = tMessage.mID;
                                qint64 tRet = tMessage.EXAMPLEVALUE;

                                qDebug()<<QString("[VehSetBufferTime] VehID: %1 Ret: %2").arg(tVehID).arg(tRet);
                            }else if(msgfrags[2]=="launchcost")
                            {
                                qint64 tVehID = tMessage.mID;
                                qint64 tRet = tMessage.EXAMPLEVALUE;

                                qDebug()<<QString("[VehSetLaunchCost] VehID: %1 Ret: %2").arg(tVehID).arg(tRet);
                            }else
                            {
                                qDebug()<<"bad msg";
                            }
                        }
                    }else if(msgfrags[0]=="updatejob")
                    {
                        qint64 aVehId = tMessage.mID;
                        QList<QHash<QString,qint64>> tJobList;
                        for(int i = 0; i < tMessage.mSequence.size(); ++i)
                        {
                            QHash<QString,qint64> tJob;
                            tJob.insert("loc",tMessage.mSequence.at(i).mValues[0]);
                            tJob.insert("demand",tMessage.mSequence.at(i).mValues[1]);
                            tJob.insert("open_time",tMessage.mSequence.at(i).mValues[2]);
                            tJob.insert("close_time",tMessage.mSequence.at(i).mValues[3]);
                            tJob.insert("cusid",tMessage.mSequence.at(i).mValues[4]);
                            tJobList.append(tJob);
                        }
                        qDebug()<<QString("[UpdateJob] VehID: %1 JobList: ").arg(aVehId)<<tJobList;
                    }else if(msgfrags[0]=="trigger")
                    {
                        qint64 tVehId = tMessage.mID;
                        qint64 tCusId = tMessage.EXAMPLEVALUE;
                        qint64 tWaitingTime = tMessage.mSegment.mSegmentID;
                        qDebug()<<QString("[TriggerNotice] VehID: %1 CusID: %2 WaitingTime: %3").arg(tVehId).arg(tCusId).arg(tWaitingTime);
                        //should call the cus confirm window

                        emit createArrAnsDialogSignal(tVehId,tCusId,tWaitingTime);

//                        QPair<qint64,qint64> tVCIdPair;
//                        tVCIdPair.first = tVehId;
//                        tVCIdPair.second = tCusId;
//                        cusconfirmdialog* tCusConfirmDialog = new cusconfirmdialog(tVehId,tCusId,tWaitingTime);

//                        connect(tCusConfirmDialog,SIGNAL(CusAnsPickup(qint64,qint64,QString)),this,SLOT(rcvCusAnsArrival(qint64,qint64,QString)));
//                        tCusConfirmDialog->showUp();

//                        mCusDialogHash.insert(tVCIdPair,tCusConfirmDialog);
                    }else if(msgfrags[0]=="expire")
                    {
                        qint64 tCusId = tMessage.mID;
                        qint64 tVehId = tMessage.mSegment.mSegmentID;

                        emit deleteArrAnsDialogSignal(tVehId,tCusId);
                    }
                }
            }
        }
}

void vrptest_stkci_sub::rcvCusAnsArrival(qint64 aVehId, qint64 aCusId, QString aAnsStr)
{
//    //string: yes/no

//    //set wait time of veh in fms to 0
//    {
//        //...
//    }

//    //send out cus confirm pub to vrp by sending signal to puber
//    emit sendCusConfirmAns(aVehId,aCusId,aAnsStr);

//    //clean up the dialog widget
//    //disconnect
//    QPair<qint64,qint64> tVCIdPair(aVehId,aCusId);
//    //disconnect(mCusDialogHash[tVCIdPair],SIGNAL(CusAnsPickUp(qint64,qint64,QString)),this,SLOT(rcvCusAnsArrival(qint64,qint64,QString)));
//    //unshow
//    mCusDialogHash[tVCIdPair]->hideShow();
//    //removal
//    delete mCusDialogHash[tVCIdPair];
//    mCusDialogHash.remove(tVCIdPair);
}
