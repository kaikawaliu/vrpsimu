#ifndef VRPTEST_DB_H
#define VRPTEST_DB_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QDateTime>
#include <QTimer>

#include <QThread>

#include "FmsDbReader.h"

static const std::string gVRPDBConfigFile = "VRPTestConfigurables.xml";


class vrptest_db : public QObject
{
    Q_OBJECT
public:
    explicit vrptest_db(QSqlDatabase *adb, QObject *parent = 0);

    void Initialization();

    void setDefaultVehParams(QHash<QString,QString> aVehDefaultParams)
    {
        mVehDefaultParams=aVehDefaultParams;
    }

//    bool RegisterLocLL(qint64 aLocId, double aLat, double aLong);
//    bool DeregisterLocLL(qint64 aLocId);
//    bool UpdateLocLL(qint64 aLocId, double aLat, double aLong);

//    bool RegisterVehLL(qint64 aVehId, double aLat, double aLong);
//    bool DeregisterVehLL(qint64 aVehId);
//    bool UpdateVehLL(qint64 aVehId, double aLat, double aLong);




    //Time Related:
    void setStartHour(qint64 aStartHour){mStartHour = aStartHour;}
    void setEndHour(qint64 aEndHour){mEndHour = aEndHour;}
    qint64 getStartHour(){return mStartHour;}
    qint64 getEndHour(){return mEndHour;}
    QString getDate(){return mDate;}
    QString getRealTime(){return mRealTime;}
    qint64 getSimTime(){return mSimTime;}
    void setTimeDiff(qint64 aSimTime){mCurTimeDiff = aSimTime - mSimTime;}
    void setTimeDiffToZero(){mCurTimeDiff=0;}

    QString SimToRealTime(qint64 aSimTime);
    qint64 RealToSimTime(QString aRealTime);
    QString RealTimeStringlize(int aTimeParam);

    //PUB:
    //Add functions here!
    //Just duplicate the function in vrptest_stkci_pub/sub
    //Table1
    bool VehRegister(qint64 aVehId, qint64 aDepot, qint64 aCapacity, double aSpeed, qint64 aRefuelTime,
                     qint64 aFixTime, qint64 aUnitTime, qint64 aBufferTime, qint64 aLaunchCost);
    bool VehDeregister(qint64 aVehId);

    bool VehSetDepot(qint64 aVehId, qint64 aDepot);
    bool VehSetCapacity(qint64 aVehId, qint64 aCapacity);
    bool VehSetSpeed(qint64 aVehId, double aSpeed);
    bool VehSetRefuelTime(qint64 aVehId, qint64 aRefuelTime);
    bool VehSetFixTime(qint64 aVehId, qint64 aFixTime);
    bool VehSetUnitTime(qint64 aVehId, qint64 aUnitTime);
    bool VehSetBufferTime(qint64 aVehId, qint64 aBufferTime);
    bool VehSetLaunchCost(qint64 aVehId, qint64 aLaunchCost);



    //Table2
    bool CusRequest(qint64 aCusId, qint64 aDemand, qint64 aPickupLoc, qint64 aDeliveryLoc, qint64 aReqTime, qint64 aWaitTime);
    bool CusDerequest(qint64 aCusId);
    bool CusChgReq(qint64 aCusId, qint64 aDemand, qint64 aPickupLoc, qint64 aDeliveryLoc, qint64 aReqTime, qint64 aWaitTime);

    //Table3
    bool OnArrivalEvent(qint64 aVehId, int SizeOfJob, qint64 aCusId, qint64 aDemand);
    bool CusAnsPickup(qint64 aCusId, qint64 aVehId, QString aAns);
    bool CusAnsDelivery(qint64 aCusId, qint64 aVehId, QString aAns);
    bool SetCurrentTime(qint64 aCurTime);
    bool BackToDepotEvent(qint64 aVehId);

    //SUB:

    //SYS TIME:
    void StartSysTimer();//~

signals:
    //SUB:


    void sendCusConfirmAns(qint64 aVehId, qint64 aCusId, QString aAnsStr);
    void createArrAnsDialogSignal(qint64 aVehId, qint64 aCusId, qint64 aWaitTime);
    void deleteArrAnsDialogSignal(qint64 aVehId, qint64 aCusId);

    //=====================================================================
    //get the changes happened in VRPMaster
    void informAddLocCoordByScan(qint64 aLocId, double aLat, double aLong);
    void informDeleteLocCoordByScan(qint64 aLocId);
    void informUpdateLocCoordByScan(qint64 aLocId, double aLat, double aLong);

    void informAddVehCoordByScan(qint64 aVehId, double aLat, double aLong);
    void informDeleteVehCoordByScan(qint64 aVehId);
    void informUpdateVehCoordByScan(qint64 aVehId, double alat, double aLong);

    void informRegisterVehByScan(qint64 aVehId,qint64 aCapacity, double aSpeed, qint64 aRefuelTime, qint64 aFixTime, qint64 aUnitTime, qint64 aBufferTime, qint64 aLaunchCost, qint64 aCost, int tInDepot);
    void informDeregisterVehByScan(qint64 aVehId);
    void informUpdateVehByScan(qint64 aVehId, qint64 aCapacity, double aSpeed, qint64 aRefuelTime, qint64 aFixTime, qint64 aUnitTime, qint64 aBufferTime, qint64 aLaunchCost);

    void informAddRequestByScan(qint64 aCusId, qint64 aAssignedVeh, qint64 aDemand, qint64 aPULoc, qint64 aDLoc, qint64 aRTime, qint64 aWTime, int aPUFlag);
    void informUpdateRequestByScan(qint64 aCusId, qint64 aAssignedVeh, qint64 aDemand, qint64 aPULoc, qint64 aDLoc, qint64 aRTime, qint64 aWTime);
    void informCancelRequestByScan(qint64 aCusId);

    void informJobUpdateByScan(qint64 aVehId, QList<QHash<QString,qint64>> aJobList);
    void informUpdateVehCostByScan(qint64 tVehId, qint64 tCost);
    void informUpdateVehInDepotByScan(qint64 tVehId, int tInDepot);
    void informGetPickedUpByScan(qint64 aCusId);
    void addArrPUAnsToUI(qint64 aVehId,qint64 aCusId,qint64 aWaitTime);
    void addArrDLAnsToUI(qint64 aVehId,qint64 aCusId,qint64 aWaitTime);
    void expirePUArrAnsFromUI(qint64 aVehId,qint64 aCusId);
    void expireDLArrAnsFromUI(qint64 aVehId,qint64 aCusId);
//    void informCurTimeByScan(qint64 aCurTime);
    void curTimeChanged();
    //======================================================================
//    void sendCurrentDate(QString aDate);//00-00-0000
//    void sendCurrentRealTime(QString aRealTime);//00:00:00

    //======================================================================
    //for feedback to Client Gateway
    void fbCusRequestByGW(qint64 aCusID, QString aResult);
    void fbCusDelRequestByGW(qint64 aCusID, QString aResult);
    void fbCusUpdateRequestByGW(qint64 aCusID, QString aResult);
    void addArrPUAnsToGW(qint64 aCusId, qint64 aWaitingTime);
    void addArrDLAnsToGW(qint64 aCusId, qint64 aWaitingTime);
    void reportExpirePUArrAnsToGW(qint64 aCusId);
    void reportExpireDLArrAnsToGW(qint64 aCusId);
    void fbSettlePUArrAnsToGW(qint64 aCusId, QString aResultStr);
    void fbSettleDLArrAnsToGW(qint64 aCusId, QString aResultStr);
    void updateETAToGW(qint64 aCusId, QString aOpenTimes);
public slots:
    //PUB:
    void RcvCusConfirmAns(qint64 aVehId, qint64 aCusId, QString aAnsStr);

    //SUB:
    void starttimerslot(){starttimer();}

    void scanSummary();

    void scanDBForVeh();
    void scanDBForCus();
    void scanDBForEvt();

    //SYNCRONIZE WITH VRP
    void scanVRPDBForLocCoord();
    void scanVRPDBForVehCoord();
    void scanVRPDBForVeh();
    void scanVRPDBForCus();
    void scanVRPDBForJob();
    void scanVRPDBForCurTime();

//    void rcvCusAnsArrival(qint64 aVehId, qint64 aCuusId, QString aAnsStr);
    bool RegisterLocLL(qint64 aLocId, double aLat, double aLong);
    bool DeregisterLocLL(qint64 aLocId);
    bool UpdateLocLL(qint64 aLocId, double aLat, double aLong);

    bool RegisterVehLL(qint64 aVehId, double aLat, double aLong);
    bool DeregisterVehLL(qint64 aVehId);
    bool UpdateVehLL(qint64 aVehId, double aLat, double aLong);

    //Specially for FMS Communication Use
    void RegisterVehStatusFromFMS(qint64 aVehId, qint64 aCapacity, double aSpeed);
    void UpdateVehStatusFromFMS(qint64 aVehId, QString aType, QString aValue);
    void DeleteVehStatusFromFMS(qint64 aVehId);

    void DeleteVehFromFMS(qint64 aVehId);

private slots:
    //TIME related:
    void CurTimerHit();

private:
    bool cleanUpAllReply();
    void starttimer();
    void parseConfigurables();

    QTimer* mpScanTimer;

    QTimer* mpVehTimer;
    QTimer* mpCusTimer;
    QTimer* mpEvtTimer;

    QTimer* mpVRPLocCoordTimer;
    QTimer* mpVRPVehCoordTimer;
    QTimer* mpVRPVehTimer;
    QTimer* mpVRPCusTimer;
    QTimer* mpVRPJobTimer;

    QTimer* mpCurTimer;

    bool scanCurTimeFirstCalled=false;
    qint64 mStartHour = 9, mEndHour = 18;
    QString mDate = "00-00-0000";
    qint64 mSimTime = 0;//listen to vrpmaster//~
    QString mRealTime = SimToRealTime(mSimTime);//listen to mSimTime//~
    qint64 mCurTimeDiff = 0;//listen to primeUI//for adapting the time set by ui with the current time//~

    QString mHostName;
    QString mPort;
    QString mDatabaseName;
    QString mUserName;
    QString mPassword;

    QHash<qint64,QString> mLocCoordTimeStamps;
    QHash<qint64,QString> mVehCoordTimeStamps;
    QHash<qint64,QString> mVehTimeStamps;//~
    QHash<qint64,QString> mCusTimeStamps;//~
    QHash<qint64, bool> mVehInDepots;
    QHash<qint64, qint64> mVehCosts;
    QHash<qint64, int> mCusPUFlags;
    QHash<qint64,QHash<QString,QString>> mVehsHash;
    QHash<qint64,QHash<QString,QString>> mCussHash;
    QHash<QString,QString> mVehDefaultParams;
    QHash<qint64,QHash<qint64,QHash<QString,qint64> > > mVehJobs;

    void DeleteVehicleReply(QString aReplyId, QString aType, QString aVehId);
    void DeleteCustomerReply(QString aReplyId, QString aType, QString aCusId);
    void DeleteEventReply(QString aReplyId, QString aType, QString aVehId, QString aCusId);

    //==============================================
    //====Executive Functions for Reply Sub=========
    //================= Veh ========================
    void ExecuteVehRegisterReply(qint64 aVehId, QString aResult);
    void ExecuteVehDeregisterReply(qint64 aVehId, QString aResult);
    void ExecuteVehSetDepotReply(qint64 aVehId, QString aResult);
    void ExecuteVehSetCapacityReply(qint64 aVehId, QString aResult);
    void ExecuteVehSetSpeedReply(qint64 aVehId, QString aResult);
    void ExecuteVehSetRefuelTimeReply(qint64 aVehId, QString aResult);
    void ExecuteVehSetFixTimeReply(qint64 aVehId, QString aResult);
    void ExecuteVehSetUnitTimeReply(qint64 aVehId, QString aResult);
    void ExecuteVehSetBufferTimeReply(qint64 aVehId, QString aResult);
    void ExecuteVehSetLaunchCostReply(qint64 aVehId, QString aResult);
    //================= Cus ========================
    void ExecuteCusRequestReply(qint64 aCusId, QString aResult);
    void ExecuteCusDerequestReply(qint64 aCusId, QString aResult);
    void ExecuteCusChangeRequestReply(qint64 aCusId, QString aResult);
    //================= Evt ========================
    void ExecuteEvtVehicleArrivalReply(qint64 aVehId, qint64 aCusId, qint64 aWaitTime);
    void ExecuteEvtTriggerPUNoticeReply(qint64 aVehId, qint64 aCusId, qint64 aWaitTime);
    void ExecuteEvtTriggerDLNoticeReply(qint64 aVehId, qint64 aCusId, qint64 aWaitTime);
    void ExecutePUEvtExpireReply(qint64 aVehId, qint64 aCusId);
    void ExecuteDLEvtExpireReply(qint64 aVehId, qint64 aCusId);
    void ExecuteEvtVehBackDepotReply(qint64 aVehId, QString aResult);
    void ExecuteEvtSettlePUReply(qint64 aVehId, qint64 aCusId, QString aResultStr);
    void ExecuteEvtSettleDLReply(qint64 aVehId, qint64 aCusId, QString aResultStr);
    void ExecuteEvtUpdateETA(qint64 aCusId, QString aOpenTimes);
    void ExecuteEvtTriggerMove(qint64 aVehId);
    //==============================================

    //=======================================================
    //====Executive Functions for Syncronization With VRP====
    //=======================================================
    //Veh

    //=======================================================
    //Cus

    //=======================================================
    //Job

    //=======================================================

    QThread thFMS;
    QSqlDatabase* db;
    QSqlQuery* query;
    FMSDbReader* fmsDbReader;
};

static bool CMP(const QHash<QString,qint64> &i, const QHash<QString,qint64> &j)
{
    return i.value("closetime")<j.value("closetime");
}

#endif // VRPTEST_DB_H
