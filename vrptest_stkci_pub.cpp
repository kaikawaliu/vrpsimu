#include "vrptest_stkci_pub.h"

vrptest_stkci_pub::vrptest_stkci_pub(QObject *parent) :
    QObject(parent)
{

}

void vrptest_stkci_pub::setup()
{
    qDebug()<<"Setup Connection for VRPTest Publisher";

    if(mPubInterface.setup("VRPInterfaceConfigFile.xml",mProfile)==STKCI::InterfaceRetCode_OK)
    {
        mMessage.mKeyId = mKeyId;
        cleanMsg();
        startSendingMsg();
    }else
    {
        qDebug()<<"Failed Setup!";
    }
}

void vrptest_stkci_pub::startSendingMsg()
{
    //for test only:
//    QTimer *timer = new QTimer(0);
//    connect(timer,SIGNAL(timeout()),this,SLOT(loopMsg()));
//    timer->start(1000);
}

void vrptest_stkci_pub::loopMsg()
{
    mMessage.msg = QString("test|str").toStdString();
    pubMsg();
}

void vrptest_stkci_pub::close()
{
    qDebug()<<"Close Connection ";
    mPubInterface.close();
}

void vrptest_stkci_pub::pubMsg()
{
    if(mPubInterface.publish(mMessage)!=STKCI::InterfaceRetCode_OK)
    {
        qDebug()<<"!! Failed to Publish ";
    }else
    {
        qDebug()<<"::Publish Message!!:: Of Size"<<STKCI::sizeRequiredExampleMainMsg(&mMessage)<<" Bytes";
        PrintMessage(mMessage);
    }
    cleanMsg();
}

void vrptest_stkci_pub::PrintMessage(const STKCI::ExampleMainMsg &aMessage)
{
    std::cout<<">>EXAMPLEVALUE="<<aMessage.EXAMPLEVALUE<<std::endl
            <<">>Id="<<aMessage.mID<<std::endl
           <<">>KeyId="<<aMessage.mKeyId<<std::endl
          <<">>enum="<<aMessage.mType<<std::endl
         <<">>msg="<<aMessage.msg<<std::endl
        <<">>segment.segmentid="<<aMessage.mSegment.mSegmentID<<std::endl
       <<">>value=("<<aMessage.value.size()<<")";

    for (STKCI::DCHAR_TSeq::const_iterator it = aMessage.value.begin();
         it < aMessage.value.end();
         ++it)
    {
        std::cout<<*it;
    }
    std::cout<<std::endl;

    for (STKCI::ExampleSubArraySeq::const_iterator it = aMessage.mSequence.begin();
         it < aMessage.mSequence.end();
         ++it)
    {
        std::cout<<">> mSequence Member "<<it-aMessage.mSequence.begin()<<":";
        std::cout<<it->mValues[0]<<" ";
        std::cout<<it->mValues[1]<<" ";
        std::cout<<it->mValues[2]<<" ";
        std::cout<<it->mValues[3]<<" ";
        std::cout<<it->mValues[4]<<" ";
        std::cout<<std::endl;
    }
}

void vrptest_stkci_pub::cleanMsg()
{
    mMessage.mID = 0;
    mMessage.EXAMPLEVALUE = 0;
//    mMessage.mKeyId = 11;
    mMessage.msg = "";
    mMessage.value.clear();
    mMessage.mType = STKCI::INFO;
    mMessage.mSegment.mSegmentID = 0;
    mMessage.mSequence.clear();
    mMessage.DefaultSeq.clear();
    mMessage.FixedSeq.clear();
}

void vrptest_stkci_pub::VehRegister(qint64 aVehId, qint64 aDepot, qint64 aCapacity, double aSpeed, qint64 aRefuelTime, qint64 aFixTime, qint64 aUnitTime, qint64 aBufferTime, qint64 aLaunchCost)
{
    mMessage.msg = QString("veh|reg|id:%1|dep:%2|cap:%3|spd:%4|rftime:%5|ftime:%6|utime:%7|btime:%8|lcost:%9")
            .arg(aVehId)
            .arg(aDepot)
            .arg(aCapacity)
            .arg(aSpeed)
            .arg(aRefuelTime)
            .arg(aFixTime)
            .arg(aUnitTime)
            .arg(aBufferTime)
            .arg(aLaunchCost).toStdString();
    pubMsg();
}

void vrptest_stkci_pub::VehDeregister(qint64 aVehId)
{
    mMessage.msg = QString("veh|dereg|id:%1").arg(aVehId).toStdString();
    pubMsg();
}

void vrptest_stkci_pub::VehSetDepot(qint64 aVehId, qint64 aDepot)
{
    mMessage.msg = QString("veh|depot|id:%1|loc:%2").arg(aVehId).arg(aDepot).toStdString();
    pubMsg();
}

void vrptest_stkci_pub::VehSetCapacity(qint64 aVehId, qint64 aCapacity)
{
    mMessage.msg = QString("veh|capacity|id:%1|cap:%2").arg(aVehId).arg(aCapacity).toStdString();
    pubMsg();
}

void vrptest_stkci_pub::VehSetSpeed(qint64 aVehId, double aSpeed)
{
    mMessage.msg = QString("veh|speed|id:%1|spd:%2").arg(aVehId).arg(aSpeed).toStdString();
    pubMsg();
}

void vrptest_stkci_pub::VehSetRefuelTime(qint64 aVehId, qint64 aRefuelTime)
{
    mMessage.msg = QString("veh|refueltime|id:%1|rftime:%2").arg(aVehId).arg(aRefuelTime).toStdString();
    pubMsg();
}

void vrptest_stkci_pub::VehSetFixTime(qint64 aVehId, qint64 aFixTime)
{
    mMessage.msg = QString("veh|fixtime|id:%1|ftime:%2").arg(aVehId).arg(aFixTime).toStdString();
    pubMsg();
}

void vrptest_stkci_pub::VehSetUnitTime(qint64 aVehId, qint64 aUnitTime)
{
    mMessage.msg = QString("veh|unittime|id:%1|utime:%2").arg(aVehId).arg(aUnitTime).toStdString();
    pubMsg();
}

void vrptest_stkci_pub::VehSetBufferTime(qint64 aVehId, qint64 aBufferTime)
{
    mMessage.msg = QString("veh|buffertime|id:%1|btime:%2").arg(aVehId).arg(aBufferTime).toStdString();
    pubMsg();
}

void vrptest_stkci_pub::VehSetLaunchCost(qint64 aVehId, qint64 aLaunchCost)
{
    mMessage.msg = QString("veh|launchcost|id:%1|lcost:%2").arg(aVehId).arg(aLaunchCost).toStdString();
    pubMsg();
}

void vrptest_stkci_pub::CusRequest(qint64 aCusId, qint64 aDemand, qint64 aPickupLoc, qint64 aDeliveryLoc, qint64 aReqTime, qint64 aWaitTime)
{
    mMessage.msg = QString("cus|req|id:%1|dmd:%2|ploc:%3|dloc:%4|rtime:%5|wtime:%6")
            .arg(aCusId)
            .arg(aDemand)
            .arg(aPickupLoc)
            .arg(aDeliveryLoc)
            .arg(aReqTime)
            .arg(aWaitTime).toStdString();
    pubMsg();
}

void vrptest_stkci_pub::CusDerequest(qint64 aCusId)
{
    mMessage.msg = QString("cus|dereq|id:%1").arg(aCusId).toStdString();
    pubMsg();
}

void vrptest_stkci_pub::CusChgReq(qint64 aCusId, qint64 aDemand, qint64 aPickupLoc, qint64 aDeliveryLoc, qint64 aReqTime, qint64 aWaitTime)
{
    mMessage.msg = QString("cus|chgreq|id:%1|dmd:%2|ploc:%3|dloc:%4|rtime:%5|wtime:%6")
            .arg(aCusId)
            .arg(aDemand)
            .arg(aPickupLoc)
            .arg(aDeliveryLoc)
            .arg(aReqTime)
            .arg(aWaitTime).toStdString();
    pubMsg();
}

void vrptest_stkci_pub::OnArrivalEvent(qint64 aVehId, qint64 aCusId, qint64 aDemand)
{
    //execute on the joblist shown in FMS please do here or upper. no need to go through VRPMaster
    {
        qDebug()<<"delete the job in FMS";
        if(aDemand>0)
        {
            //arrival at pickup
            qDebug()<<"arrival at pickup";
            qDebug()<<"change customer pickupFlag to pickup on FMS";
            qDebug()<<"delete job with this CusId and demand of this vehicle in FMS";
        }else
        {
            //arrival at delivery
            qDebug()<<"arrival at delivery";
            qDebug()<<"delete job with this cusId and demand of this vehicle in FMS";
            qDebug()<<"delete customer request in FMS";
        }
    }
    mMessage.msg = QString("evt|arr|vid:%1|cid:%2|dmd:%3")
            .arg(aVehId)
            .arg(aCusId)
            .arg(aDemand).toStdString();
    pubMsg();
}

void vrptest_stkci_pub::CusAnsPickup(qint64 aCusId, qint64 aVehId, QString aAns)
{
    mMessage.msg = QString("evt|anspick|id:%1|vid:%2|ans:%3")
            .arg(aCusId)
            .arg(aVehId)
            .arg(aAns).toStdString();
    pubMsg();
}

void vrptest_stkci_pub::SetCurrentTime(qint64 aCurTime)
{
    mMessage.msg = QString("evt|setcur|time:%1").arg(aCurTime).toStdString();
    pubMsg();
}

void vrptest_stkci_pub::RcvCusConfirmAns(qint64 aVehId, qint64 aCusId, QString aAnsStr)
{
    if(aAnsStr=="yes"){

    }else
    {
        qDebug()<<"delete customer request in FMS";
    }
    CusAnsPickup(aCusId,aVehId,aAnsStr);
}


