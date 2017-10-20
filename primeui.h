#ifndef PRIMEUI_H
#define PRIMEUI_H

#include <QWidget>
#include "mapviewmanager.h"
#include "vrptest_db.h"
#include <QMessageBox>
#include <memory>
//#include <stdlib.h>

namespace Ui {
class PrimeUI;
}

static const std::string gVRPTestConfigFile = "VRPTestConfigurables.xml";

class PrimeUI : public QWidget
{
    Q_OBJECT
    
public:
    explicit PrimeUI(vrptest_db* apDb,QWidget *parent = 0);
    ~PrimeUI();
    
private slots:
    
    void on_monBtn_clicked();
    void on_locManBtn_clicked();
    void on_vehManBtn_clicked();
    void on_cusManBtn_clicked();
    void on_evtManBtn_clicked();
    void on_resetBtn_clicked();

    //Monitoring:
    void on_monToolBox_currentChanged(int index);
    void on_monVehStatusBtn_clicked();
    void on_monVehDistBtn_clicked();
    void on_monVehJobsBtn_clicked();
    void on_monListWidget_currentRowChanged(int currentRow);
    void on_monListWidget_itemSelectionChanged();

//    void on_MonListRefreshBtn_clicked();

//    void on_MonTableRefreshBtn_clicked();

    //Loc Manager:
    void on_locRegBtn_clicked();
    void on_locDeregBtn_clicked();
    void on_locUpdateBtn_clicked();
    void on_LLGetCoordBtn_clicked();
    void on_LLReflectBtn_clicked();
    void on_locConfirmBtn_clicked();
    void on_locCancelBtn_clicked();
    void on_locTableWidget_cellClicked(int row, int column);
    void on_locTableWidget_itemSelectionChanged();
    void on_locIdEdit_textChanged(const QString &arg1);
    void on_locLatEdit_textChanged(const QString &arg1);
    void on_locLongEdit_textChanged(const QString &arg1);

//    void on_locRefreshBtn_clicked();

    //Veh Manager:
    void on_vehRegBtn_clicked();
    void on_vehDeregBtn_clicked();
    void on_vehUpdateBtn_clicked();
    void on_vehGetCoordBtn_clicked();
    void on_vehRefCoordBtn_clicked();
    void on_vehDefaultBtn_clicked();
    void on_vehConfirmBtn_clicked();
    void on_vehCancelBtn_clicked();
    void on_vehCoordChBox_toggled(bool checked);
    void on_vehSpeedChBox_toggled(bool checked);
    void on_vehCapChBox_toggled(bool checked);
    void on_vehLCostChBox_toggled(bool checked);
    void on_vehFTimeChBox_toggled(bool checked);
    void on_vehUTimeChBox_toggled(bool checked);
    void on_vehRTimeChBox_toggled(bool checked);
    void on_vehBTimeChBox_toggled(bool checked);
    void on_vehTableWidget_cellClicked(int row, int column);
    void on_vehTableWidget_itemSelectionChanged();

//    void on_vehRefreshBtn_clicked();

    //Cus Manager:
    void on_cusReqBtn_clicked();
    void on_cusCancelReqBtn_clicked();
    void on_cusChgReqBtn_clicked();
    void on_cusConfirmBtn_clicked();
    void on_cusCancelBtn_clicked();
    void on_cusTableWidget_cellClicked(int row, int column);
    void on_cusTableWidget_itemSelectionChanged();
    void on_cusDemandsChBox_toggled(bool checked);
    void on_cusPULocChBox_toggled(bool checked);
    void on_cusDLocChBox_toggled(bool checked);
    void on_cusRSTimeChBox_toggled(bool checked);
    void on_cusWTimeChBox_toggled(bool checked);

//    void on_cusRefreshBtn_clicked();

    //Evt Manager:
    void on_evtVehArrBtn_clicked();
    void on_evtVehBTDBtn_clicked();
    void on_evtSetCurTimeBtn_clicked();//~
    void on_evtConfirmCurTimeBtn_clicked();//~
    void on_evtHourSpBox_editingFinished();//~
    void on_evtMinuteSpBox_editingFinished();//~
    void on_evtSecondSpBox_editingFinished();//~
    void on_evtSimTimeSpBox_editingFinished();//~
    void on_evtVehTableWidget_itemSelectionChanged();
    void on_evtCusAnsTableWidget_itemSelectionChanged();
    void on_evtJobsTableWidget_itemSelectionChanged();
    void on_evtCusAnsAcceptBtn_clicked();
    void on_evtCusAnsRefuseBtn_clicked();
    void on_evtResetTimeBtn_clicked();//~
    void on_opTimeBtn_clicked();//~

signals:
    //Monitoring

    //Loc Manager

    //Veh Manager

    //Cus Manager
    void fbCusRequestByGWDone(qint64 aCusId,qint64 aVehId);
    void fbCusDelRequestByGWDone(qint64 aCusId);
    void fbCusUpdateRequestByGWDone(qint64 aCusId);
    //Evt Manager

public slots:
    //Generic
    void ViewGetPressScenePos(QPointF aScenePos);
    void ViewGetHoverScenePos(QPair<qint64,qint64> aPos,QPair<double,double> aCoord);
    void ViewGetHoverLeaveEvent();
    void GetLoseSelection();
    //Monitoring
    void MonViewUpdateUI(QString aItemStr, QList<qint64> aIdList);
    void getPressInMonMode(QString aItemStr, QList<qint64> aIdList);
    //Loc Manager
    void LocViewUpdateUI(QHash<qint64,QPair<double,double>> aLocIdCoordHash);
    void UIGetLocLLFromView(QPair<double,double> aCoord);
    void UIGetRepForLocOp(QString aType, qint64 aLocId, QString aResult);
    void getPressInLocMode(QHash<qint64,QPair<double,double>> aSelectedLocCoordHash);
    //Veh Manager
    void VehViewUpdateUI(QHash<qint64,QPair<double,double>> aVehIdCoordHash);
    void UIGetRepForVehOp(QString aType, qint64 aVehId, QString aResult);
    void UIGetVehLLFromView(QPair<double,double> aCoord);
    void UIGetCmdForVehCoordUpd(qint64 aVehId, QPair<double,double> aVehCoord);
    void UIGetCmdForVehJobsUpd(qint64 aVehId, QHash<QString,qint64> aVehJobs);
    void getPressInVehMode(QHash<qint64,QPair<double,double>> aSelectedVehCoordHash);
    void getReplyForRegisterVehPrpty(qint64 aVehId, bool result);
    void getReplyForDeregisterVehPrpty(qint64 aVehId, bool result);
    void getReplyForUpdateVehPrpty(qint64 aVehId, QString aType, bool result);
    //Cus Manager
    void CusViewUpdUI(QHash<qint64,bool> aCusIdPUHash);
    void CusViewUpdUIForLoc(QList<qint64> aCusLocIdList);
    void getPressInCusModeForLoc(QList<qint64> aSelectedLocList);
    void getPressInCusModeForReq(QHash<qint64,bool> aSelectedCusIdPUHash);
    void getReplyForCusRequest(qint64 aCusId, bool result);
    void getReplyForCusCancelRequest(qint64 aCusId, bool result);
    void getReplyForCusChangeRequest(qint64 aCusId, bool result);
    //Evt Manager
    void EvtViewUpdUI(QList<qint64> aVehIdList);
    void getPressInEvtMode(QList<qint64> aSelectedVehIdList);
    void getReplyForEvtVehArr(qint64 aVehId, qint64 aCusId,qint64 aWaitTime);
    void getReplyForEvtTriggerPUNotice(qint64 aVehId, qint64 aCusId, qint64 aWaitTime);
    void getReplyForEvtTriggerDLNotice(qint64 aVehId, qint64 aCusId, qint64 aWaitTime);
    void getReplyForEvtCusAnsPUExpire(qint64 aVehId, qint64 aCusId);
    void getReplyForEvtCusAnsDLExpire(qint64 aVehId, qint64 aCusId);
    void getReplyForEvtBackDepot(qint64 aVehId, QString aResult);
    void getReplyForEvtArrSettle(qint64 aVehId, qint64 aCusId);
    //=================================
    //Informed Slots From VRPMaster DB
    void InformedAddLocCoord(qint64 aLocId, double aLat, double aLong);
    void InformedDeleteLocCoord(qint64 aLocId);
    void InformedUpdateLocCoord(qint64 aLocId, double aLat, double aLong);

    void InformedAddVehCoord(qint64 aVehId, double aLat, double aLong);
    void InformedDeleteVehCoord(qint64 aVehId);
    void InformedUpdateVehCoord(qint64 aVehId, double aLat, double aLong);

    void informedRegisterVeh(qint64 aVehId, qint64 aCapacity, double aSpeed, qint64 aRefuelTime, qint64 aFixTime, qint64 aUnitTime, qint64 aBufferTime, qint64 aLaunchCost, qint64 aCost, int aInDepot);
    void informedDeregisterVeh(qint64 aVehId);
    void informedUpdateVeh(qint64 aVehId, qint64 aCapacity, double aSpeed, qint64 aRefuelTime, qint64 aFixTime, qint64 aUnitTime, qint64 aBufferTime, qint64 aLaunchCost);

    void informedAddRequest(qint64 aCusId, qint64 aAssignedVeh, qint64 aDemand, qint64 aPULoc, qint64 aDLoc, qint64 aRTime, qint64 aWTime, int aPUFlag);
    void informedUpdateRequest(qint64 aCusId, qint64 aAssignedVeh, qint64 aDemand, qint64 aPULoc, qint64 aDLoc, qint64 aRTime, qint64 aWTime);
    void informedCancelRequest(qint64 aCusId);

    void informedJobUpdate(qint64 aVehId, QList<QHash<QString,qint64>> aJobList);
    void informedUpdateVehCost(qint64 aVehId, qint64 aCost);
    void informedUpdateVehInDepot(qint64 aVehId, int aInDepot);
    void informedGetPickedUp(qint64 aCusId);

    void informedCurTimeChanged();//~
    //===================================
    //Slot For Client Gateway Communication
    void CusRequestByGW(qint64 aCusId, QHash<QString, qint64> aHash);
    void CusDelRequestByGW(qint64 aCusId);
    void CusUpdateRequestByGW(qint64 aCusId, QHash<QString, qint64> aHash);
    void CusAnsPickupByGW(qint64 aCusId, qint64 aVehId, QString aAns);
    void CusAnsDeliveryByGW(qint64 aCusId, qint64 aVehId, QString aAns);
private:
    //Generic:
    //funcs:
    qint64 RealTimeToSimTime(QString aRealTime);//~
    QString SimTimeToRealTime(qint64 aSimTime);//~
    void resetAllViews();
    void refreshRelatedWidgets(QString aFlagStr, qint64 aId);
    void updateDate();//~
    void addCrossHairToView(QPair<double,double> aCoord);
    void deleteCrossHairInView();
    bool checkInRangeLat(double aLat);
    bool checkInRangeLong(double aLong);
    void parseConfigurables();
    void InitOperationTime();//~
    void resetEverything();
    //params:
    Ui::PrimeUI *ui;
    vrptest_db* mpDb;
    MapViewManager* mpMapView;
    QPointF mPressPos;
    QPointF mHoverPos;
    QPair<double,double> mPressCoord;
    QPair<double,double> mHoverCoord;
//    QString mDate="00-00-0000";//00-00-0000
//    QString mRealTime="00:00:00";//00:00:00
//    qint64 mSimTime=0;
//    qint64 mStartHour=9,mEndHour=16;
    QPair<double,double> mCrossHairCoord;
//    qint64 mStartHour, mEndHour;
//    std::vector<int> mRSTimes;
//    std::vector<int> mWTimes;

    //Monitoring:
    //funcs:
    void refreshMonListWidget();
    void refreshMonTableWidget(qint64 aId=0);
    void MonUIPageUpdateView();
    void MonUIUpdateView(qint64 aId);
    //params:
    qint64 mMonPage=1;
    qint64 mVehOption=0;
//    QHash<qint64, QHash<qint64,qint64>> mMonLocDistsHash;
//    QHash<qint64, QHash<QString,QString>> mMonVehStatusHash;
//    QHash<qint64, QHash<qint64,qint64>> mMonVehDistsHash;
//    QHash<qint64, QList<QHash<QString,qint64>>> mMonVehJobsHash;
//    QHash<qint64, QHash<QString,qint64>> mMonCusTaskDetails;
//    QHash<qint64, QHash<QString,qint64>> mMonCusHash;

    //Loc Manager:
    //funcs:
    void refreshLocTableWidget();
    void LocRegisterByUI(qint64 aLocId, QPair<double,double> aLocCoord);
    void LocDeregisterByUI(qint64 aLocId);
    void LocUpdateByUI(qint64 aLocId, QPair<double,double> aLocCoord);
    void LocRegisterToView(qint64 aLocId, QPair<double,double> aLocCoord);
    void LocDeregisterToView(qint64 aLocId);
    void LocUpdateToView(qint64 aLocId, QPair<double,double> aLocCoord);
    void LocResetInterface();
    //params:
    bool locCellSelected=false;
    QString mLocMode;
    qint64 mLocClickedId;
    QHash<qint64,QPair<double,double>> mLocRegistereds;
//    QHash<qint64,QPair<double,double>> mLocRegisterings;
//    QHash<qint64,QPair<double,double>> mLocUpdatings;
//    QPair<double,double> mLocRefCoord;

    //Veh Manager:
    //funcs:
    void refreshVehTableWidget();
    void VehRegisterByUI(qint64 aVehId, QPair<double,double> aVehCoord, QHash<QString,QString> aVehHash);
    void VehDeregisterByUI(qint64 aVehId);
    void VehPrptyUpdateByUI(qint64 aVehId, QString aType, QString aValue);
    void VehCoordUpdateByUI(qint64 aVehId, QPair<double,double> aVehCoord);
    void VehRegisterToView(qint64 aVehId, QPair<double, double> aVehCoord);
    void VehDeregisterToView(qint64 aVehId);
    void VehPrptyUpdateToView(qint64 aVehId, QString aType);
    void VehJobUpdateToView(qint64 aVehId);
    void VehCoordUpdateToView(qint64 aVehId, QPair<double,double> aVehCoord);
    void VehResetInterface();
    //params:
    bool vehCellSelected;
    QString mVehMode;
    qint64 mVehClickedId;
    QHash<QString,QString> mVehDefaultParams;
    QPair<double,double> mVehDefaultCoord;
    QHash<qint64, QHash<QString,QString>> mVehPrptyRegistereds;
    QHash<qint64, QHash<QString,QString>> mVehPrptyRegisterings;
    QHash<qint64, QHash<QString,QString>> mVehPrptyUpdatings;
    QHash<qint64,QPair<double,double>> mVehCoordsHash;
//    QPair<double,double> mVehRefCoord;

    //Cus Manager:
    //funcs:
    void refreshCusTableWidget();
    void CusRefreshLocationComboList();
    void CusRefreshRSTimeComboList();
    void CusRefreshWTimeComboList();

    void CusRequestByUI(qint64 aCusId, QHash<QString,qint64> aCusHash);
    void CusDerequestByUI(qint64 aCusId);
    void CusChgRequestByUI(qint64 aCusId, QHash<QString,qint64> aCusHash);
    void CusRequestToView(qint64 aCusId);
    void CusDerequestToView(qint64 aCusId);
    void CusChgRequestToView(qint64 aCusId);
    void CusResetInterface();

    //params:
    bool cusCellSelected;
    bool PULocSelected=false;
    QString mCusMode;
    qint64 mCusClickedId;
    QHash<qint64, QHash<QString,qint64>> mCusRequesteds;
    QHash<qint64, QHash<QString,qint64>> mCusRequestings;
    QHash<qint64, QHash<QString,qint64>> mCusChgRequestings;
    QHash<qint64, QPair<qint64,qint64>> mCusPUDLocs;
    QHash<qint64, QPair<qint64,qint64>> mCusRWTimes;
    QList<qint64> mCusRSTimes;
    QList<qint64> mCusWTimes;

    //Evt Manager;
    //funcs:
    void refreshEvtVehTableWidget();
    void refreshEvtJobsTableWidget();
    void refreshEvtCusAnsTableWidget();
    void refreshEvtLogTableWidget();
    void EvtResetInterface();
    //arrive
    void EvtVehicleArrive(qint64 aVehId, int SizeOfJob, qint64 aCusId, qint64 aDemand);
    //back to depot
    void EvtVehicleBackToDepot(qint64 aVehId);
    //cus ans pickup
    void EvtCustomerAnsPickUp(qint64 aVehId, qint64 aCusId, QString aAnsStr);
    void EvtCustomerAnsDelivery(qint64 aVehId, qint64 aCusId, QString aAnsStr);
    //set cur time...
    void EvtSetCurTimeBySimTime(qint64 aSimTime);//~
    //reset curtime
    void EvtResetCurTime();//~
    //params:
    bool settingCurrentTime=false;
    bool evtVehCellSelected=false;
    bool evtJobCellSelected=false;
    bool evtCusCellSelected=false;
    int evtCurTimeMode=0;
    qint64 mEvtVehClickedId;
    QHash<QString, qint64> mEvtJobClickedHash;//"cus""demand"
    qint64 mEvtCusClickedId;
    QHash<qint64,QList<QHash<QString,qint64>>> mVehJobsHash;
    QHash<qint64,QHash<QString,qint64>> mCusAnsDataHash;//veh//waittime
//    QHash<qint64,QHash<QString,/*SpecialTableWidgetItemForCusAns*/>> mCusAnsItemHash;
    QHash<QString,QString> mLogHash;
};

#endif // PRIMEUI_H
