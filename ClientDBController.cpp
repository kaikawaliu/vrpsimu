#include "ClientDBController.h"

ClientDBController::ClientDBController(QObject *parent) : QObject(parent)
{

}

bool ClientDBController::SetDatabase(const stkfms::DB::GatewayConnection &aConnection)
{
    //    const stkfms::MutexLockGuard tLock(&mAccessMutex);
//    mDBAccess = std::make_shared<stkfms::DB::MobileCustomer>();
//    mDBAccess->SetConnection(aConnection);
//    return mDBAccess->IsConnected();
}

bool ClientDBController::Connect()
{
    mDBRequestAccess = std::make_shared<stkfms::DB::VRPMobileCustomerRequest>();
    mDBReplyAccess = std::make_shared<stkfms::DB::VRPMobileCustomerReply>();
    const QString tDbIpAddress("10.1.153.89");
    const QString tDbUserName("FMSS_General");
    const QString tDbUserPassword("common1234");
    const QString tDbName("VRP");

    return mDBRequestAccess->Connect(tDbIpAddress,tDbUserName,tDbUserPassword,tDbName)
            && mDBReplyAccess->Connect(tDbIpAddress,tDbUserName,tDbUserPassword,tDbName);
}

void ClientDBController::Disconnect()
{
    mDBRequestAccess->Disconnect();
    mDBReplyAccess->Disconnect();
}

void ClientDBController::Close()
{
    //    const stkfms::MutexLockGuard tLock(&mAccessMutex);
    mDBRequestAccess.reset();
    mDBReplyAccess.reset();
}

void ClientDBController::StartTimer()
{
    mScanTimer = new QTimer(0);
    connect(mScanTimer,SIGNAL(timeout()),this,SLOT(Iteration()));
    mScanTimer->start(500);
    Iteration();
}

void ClientDBController::Iteration()
{
    //    const stkfms::MutexLockGuard tLockDB(&mAccessMutex);
    QList<qint64> tRequestIDs = mDBRequestAccess->QueryRequestIds();

    if(tRequestIDs.size()>0)
    {
        for(qint64 tID : tRequestIDs)
        {
            stkfms::MobileCustomerRequest tRequest;
            if(mDBRequestAccess->QueryRequestDetailsbyId(tID,tRequest))
            {
                if(tRequest.mType==stkfms::FMSCustomerRequestType_Add)
                {
                    if(!(mGWCusList.contains(tRequest.mCusID)))
                    {
                        qint64 tCusId = tRequest.mCusID;
                        qint64 tDemand = tRequest.mNumOfCus;
                        qint64 tPULoc = tRequest.mPickPoint;
                        qint64 tDLLoc = tRequest.mDropPoint;
                        QTime tTime = QTime(mStartHour,0);
                        qint64 tReqTime = QDateTime::fromMSecsSinceEpoch(tRequest.mRequestTime).time().secsTo(tTime);
                        qint64 tWaitTime = tRequest.mWaitTime;
                        QHash<QString, qint64> tHash;
                        tHash.insert("demand",tDemand);
                        tHash.insert("ploc",tPULoc);
                        tHash.insert("dloc",tDLLoc);
                        tHash.insert("reqtime",tReqTime);
                        tHash.insert("wtime",tWaitTime);
                        tHash.insert("puflag",0);
                        AddReply(tCusId,
                                 stkfms::FMSCustomerRequestType_Add,
                                 stkfms::FMSCustomerRequestStatus_Acknowledged);
                        emit GetAddRequest(tCusId, tHash);
                        mGWCusList.append(tCusId);
                    }
                }else if(tRequest.mType==stkfms::FMSCustomerRequestType_Delete)
                {
                    if(mGWCusList.contains(tRequest.mCusID))
                    {
                        AddReply((qint64)tRequest.mCusID,
                                 stkfms::FMSCustomerRequestType_Delete,
                                 stkfms::FMSCustomerRequestStatus_Acknowledged);
                        emit GetDelRequest(tRequest.mCusID);
                    }
                }else if(tRequest.mType==stkfms::FMSCustomerRequestType_Update)
                {
                    if(mGWCusList.contains(tRequest.mCusID))
                    {
                        qint64 tCusId = tRequest.mCusID;
                        qint64 tDemand = tRequest.mNumOfCus;
                        qint64 tPULoc = tRequest.mPickPoint;
                        qint64 tDLLoc = tRequest.mDropPoint;
                        qint64 tReqTime = QDateTime::fromMSecsSinceEpoch(tRequest.mRequestTime).time().secsTo(QTime(mStartHour,0));
                        qint64 tWaitTime = tRequest.mWaitTime;
                        QHash<QString, qint64> tHash;
                        tHash.insert("demand",tDemand);
                        tHash.insert("ploc",tPULoc);
                        tHash.insert("dloc",tDLLoc);
                        tHash.insert("reqtime",tReqTime);
                        tHash.insert("wtime",tWaitTime);
                        tHash.insert("puflag",0);
                        AddReply(tCusId,
                                 stkfms::FMSCustomerRequestType_Update,
                                 stkfms::FMSCustomerRequestStatus_Acknowledged);
                        emit GetUpdateRequest(tCusId, tHash);
                    }
                }else if(tRequest.mType==stkfms::FMSCustomerRequestType_Event)
                {
                    if(mGWCusList.contains(tRequest.mCusID))
                    {
                        if(tRequest.mEventType==stkfms::FMSCustomerEventRequestType_AnsBoard)
                        {
                            emit GetAnsPUEventRequest(tRequest.mCusID,
                                                      tRequest.mVehID,
                                                      QString::fromStdString(tRequest.mChoice));//yes/no
                        }
                        else if(tRequest.mEventType==stkfms::FMSCustomerEventRequestType_AnsAlight)
                        {
                            emit GetAnsDLEventRequest(tRequest.mCusID,
                                                      tRequest.mVehID,
                                                      QString::fromStdString(tRequest.mChoice));
                        }
                    }
                }
            }
            mDBRequestAccess->RemoveRequestbyId(tID);
        }
    }
}

void ClientDBController::AddReply(qint64 aCusID,
                                  int aType,
                                  int aStatus,
                                  qint64 aVehID,
                                  qint64 aETAstart, qint64 aETAend,
                                  QString aReplyData)
{
    //    const stkfms::MutexLockGuard tLockDB(&mAccessMutex);
    if(mDBReplyAccess)
    {
        stkfms::MobileCustomerReply tReply;
        tReply.mCusID=aCusID;
        tReply.mType=aType;
        tReply.mStatus=aStatus;
        tReply.mETA=aETAstart;
        tReply.mVehID=aVehID;
        tReply.mReplyData=aReplyData.toStdString();
        qint64 tReplyID = mDBReplyAccess->AddReply(tReply);
        Q_UNUSED(tReplyID);
    }
}

void ClientDBController::FinishOrder(qint64 aCusID)
{
    if(mGWCusList.contains(aCusID))
    {
        mGWCusList.removeOne(aCusID);
    }
}

void ClientDBController::AddRequestReply(qint64 aCusID, QString aResult)
{
    if(mGWCusList.contains(aCusID) || openInternalReply)
    {
        if(aResult=="success")
        {
            //do nothing

        }else{
            //do pub!
            AddReply(aCusID,
                     stkfms::FMSCustomerRequestType_Add,
                     stkfms::FMSCustomerRequestStatus_Failed,
                     0,0,0,aResult);

            FinishOrder(aCusID);
        }
    }
}

void ClientDBController::AddRequestReplyDone(qint64 aCusID, qint64 aVehID)
{
    if(mGWCusList.contains(aCusID) || openInternalReply)
    {
        AddReply(aCusID,
                 stkfms::FMSCustomerRequestType_Add,
                 stkfms::FMSCustomerRequestStatus_Assigned,
                 aVehID);
    }
}

void ClientDBController::DelRequestReply(qint64 aCusID, QString aResult)
{
    if(mGWCusList.contains(aCusID) || openInternalReply)
    {
        if(aResult=="success")
        {
            //do nothing
        }else
        {

            AddReply(aCusID,
                     stkfms::FMSCustomerRequestType_Delete,
                     stkfms::FMSCustomerRequestStatus_Failed,0,0,0,
                     aResult);
        }
    }
}

void ClientDBController::DelRequestReplyDone(qint64 aCusID)
{
    if(mGWCusList.contains(aCusID) || openInternalReply)
    {
        AddReply(aCusID,
                 stkfms::FMSCustomerRequestType_Delete,
                 stkfms::FMSCustomerRequestStatus_Completed);
        FinishOrder(aCusID);
    }
}

void ClientDBController::UpdateRequestReply(qint64 aCusID, QString aResult)
{
    if(mGWCusList.contains(aCusID) || openInternalReply)
    {
        if(aResult=="success")
        {

        }else
        {
            AddReply(aCusID,
                     stkfms::FMSCustomerRequestType_Update,
                     stkfms::FMSCustomerRequestStatus_Failed,0,0,0,
                     aResult);
        }
    }
}

void ClientDBController::UpdateRequestReplyDone(qint64 aCusID)
{
    if(mGWCusList.contains(aCusID) || openInternalReply)
    {
        AddReply(aCusID,
                 stkfms::FMSCustomerRequestType_Update,
                 stkfms::FMSCustomerRequestStatus_Completed);
    }
}

void ClientDBController::TriggerBoardingNotice(qint64 aCusID, qint64 aWaitingTime)
{
    if(mGWCusList.contains(aCusID) || openInternalReply)
    {
        AddReply(aCusID,
                 stkfms::FMSCustomerRequestType_Event,
                 stkfms::FMSCustomerEventRequestType_ArriveBoard,
                 0,0,0,QString::number(aWaitingTime));
    }
}

void ClientDBController::ReportExpireForBoarding(qint64 aCusID)
{
    if(mGWCusList.contains(aCusID) || openInternalReply)
    {
        AddReply(aCusID,
                 stkfms::FMSCustomerRequestType_Event,
                 stkfms::FMSCustomerEventRequestType_ExpireBoard);
    }
}

void ClientDBController::fbConfirmBoardingReply(qint64 aCusID, QString aResultStr)
{
    if(mGWCusList.contains(aCusID) || openInternalReply)
    {
        AddReply(aCusID,
                 stkfms::FMSCustomerRequestType_Event,
                 stkfms::FMSCustomerEventRequestType_Boarded);
    }
}

void ClientDBController::TriggerAlightingNotice(qint64 aCusID, qint64 aWaitingTime)
{
    if(mGWCusList.contains(aCusID) || openInternalReply)
    {
        AddReply(aCusID,
                 stkfms::FMSCustomerRequestType_Event,
                 stkfms::FMSCustomerEventRequestType_ArriveAlight);
    }
}

void ClientDBController::ReportExpireForAlighting(qint64 aCusID)
{
    if(mGWCusList.contains(aCusID) || openInternalReply)
    {
        AddReply(aCusID,
                 stkfms::FMSCustomerRequestType_Event,
                 stkfms::FMSCustomerEventRequestType_ExpireAlight);
    }
}

void ClientDBController::fbConfirmAlightingReply(qint64 aCusID, QString aResultStr)
{
    if(mGWCusList.contains(aCusID) || openInternalReply)
    {
        AddReply(aCusID,
                 stkfms::FMSCustomerRequestType_Event,
                 stkfms::FMSCustomerEventRequestType_Alighted);
    }
}

void ClientDBController::UpdateETA(qint64 aCusID, QString aOpenTimes)
{
    if(mGWCusList.contains(aCusID) /*|| openInternalReply*/)
    {
        QStringList tStrList = aOpenTimes.split(";");
        if(tStrList[0]!=NULL)
        {
            qint64 tETALocationStart = tStrList[0].toLongLong()
                    + QDateTime(QDate::currentDate(),QTime(mStartHour,0)).toMSecsSinceEpoch();
            AddReply(aCusID,
                     stkfms::FMSCustomerRequestType_Event,
                     stkfms::FMSCustomerEventRequestType_ETALocationStart,0,tETALocationStart);
        }
        if(tStrList[1]!=NULL)
        {
            qint64 tETALocationEnd = tStrList[1].toLongLong()
                    + QDateTime(QDate::currentDate(),QTime(mStartHour,0)).toMSecsSinceEpoch();
            AddReply(aCusID,
                     stkfms::FMSCustomerRequestType_Event,
                     stkfms::FMSCustomerEventRequestType_ETALocationEnd,0,tETALocationEnd);
        }
    }
}
