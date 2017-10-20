#include "testwindow.h"
#include "ui_testwindow.h"

#include "FMS/DatabaseAccess/DBConnectionController.h"

TestWindow::TestWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TestWindow)
{
    mDB = new QSqlDatabase(QSqlDatabase::addDatabase("QMYSQL","BaseConnection"));
    mpDb = new vrptest_db(mDB);

    pui = new PrimeUI(mpDb);
    pui->show();

//    mpPub = new vrptest_stkci_pub;
//    mpSub = new vrptest_stkci_sub;
//    QList<qint64>* gGWCusList = new QList<qint64>;
//    mpClientSub = new ClientSubscriber(gGWCusList);
//    mpClientPub = new ClientPublisher(gGWCusList);
//    mpClientSub->setStartHour(mpDb->getStartHour());
    mpClientDBController = new ClientDBController();
    mpClientDBController->SetStartHour(mpDb->getStartHour());
    mpClientDBController->Connect();
//    mpClientDBController->SetDatabase(stkfms::DB::DBConnectionController::getInstance()->GetConnection());
    mpClientDBController->moveToThread(&thDBController);
//    mpSub->moveToThread(&thRcv);

//    connect(this,SIGNAL(sendCusConfirmAns(qint64,qint64,QString)),mpPub,SLOT(RcvCusConfirmAns(qint64,qint64,QString)));
//    connect(this,SIGNAL(sendCusConfirmAns(qint64,qint64,QString)),mpDb,SLOT(RcvCusConfirmAns(qint64,qint64,QString)));
    connect(this,SIGNAL(starttimersignal()),/*mpSub*/mpDb,SLOT(starttimerslot()));
//    connect(/*mpSub*/mpDb,SIGNAL(createArrAnsDialogSignal(qint64,qint64,qint64)),this,SLOT(createArrAnsDialog(qint64,qint64,qint64)));
//    connect(/*mpSub*/mpDb,SIGNAL(deleteArrAnsDialogSignal(qint64,qint64)),this,SLOT(deleteArrAnsDialogSlot(qint64,qint64)));

    qRegisterMetaType<QHash<QString,qint64>>("QHash<QString,qint64>");
    //For Add Request
    connect(mpClientDBController,SIGNAL(GetAddRequest(qint64,QHash<QString,qint64>)),pui,SLOT(CusRequestByGW(qint64,QHash<QString,qint64>)));
    connect(mpDb,SIGNAL(fbCusRequestByGW(qint64,QString)),mpClientDBController,SLOT(AddRequestReply(qint64,QString)));
    connect(pui,SIGNAL(fbCusRequestByGWDone(qint64,qint64)),mpClientDBController,SLOT(AddRequestReplyDone(qint64,qint64)));
    //For Del Request
    connect(mpClientDBController,SIGNAL(GetDelRequest(qint64)),pui,SLOT(CusDelRequestByGW(qint64)));
    connect(mpDb,SIGNAL(fbCusDelRequestByGW(qint64,QString)),mpClientDBController,SLOT(DelRequestReply(qint64,QString)));
    connect(pui,SIGNAL(fbCusDelRequestByGWDone(qint64)),mpClientDBController,SLOT(DelRequestReplyDone(qint64)));
    //For Update Request
    connect(mpClientDBController,SIGNAL(GetUpdateRequest(qint64,QHash<QString,qint64>)),pui,SLOT(CusUpdateRequestByGW(qint64,QHash<QString,qint64>)));
    connect(mpDb,SIGNAL(fbCusUpdateRequestByGW(qint64,QString)),mpClientDBController,SLOT(UpdateRequestReply(qint64,QString)));
    connect(pui,SIGNAL(fbCusUpdateRequestByGWDone(qint64)),mpClientDBController,SLOT(UpdateRequestReplyDone(qint64)));
    //For Arrival Event
    //For Boarding Event
    connect(mpDb,SIGNAL(addArrPUAnsToGW(qint64,qint64)),mpClientDBController,SLOT(TriggerBoardingNotice(qint64,qint64)));
    connect(mpDb,SIGNAL(reportExpirePUArrAnsToGW(qint64)),mpClientDBController,SLOT(ReportExpireForBoarding(qint64)));
    connect(mpDb,SIGNAL(fbSettlePUArrAnsToGW(qint64,QString)),mpClientDBController,SLOT(fbConfirmBoardingReply(qint64,QString)));

    connect(mpClientDBController,SIGNAL(GetAnsPUEventRequest(qint64,qint64,QString)),pui,SLOT(CusAnsPickupByGW(qint64,qint64,QString)));
    //For Alighting Event
    connect(mpDb,SIGNAL(addArrDLAnsToGW(qint64,qint64)),mpClientDBController,SLOT(TriggerAlightingNotice(qint64,qint64)));
    connect(mpDb,SIGNAL(reportExpireDLArrAnsToGW(qint64)),mpClientDBController,SLOT(ReportExpireForAlighting(qint64)));
    connect(mpDb,SIGNAL(fbSettleDLArrAnsToGW(qint64,QString)),mpClientDBController,SLOT(fbConfirmAlightingReply(qint64,QString)));

    connect(mpClientDBController,SIGNAL(GetAnsDLEventRequest(qint64,qint64,QString)),pui,SLOT(CusAnsDeliveryByGW(qint64,qint64,QString)));
    //For Update ETA
    connect(mpDb,SIGNAL(updateETAToGW(qint64,QString)),mpClientDBController,SLOT(UpdateETA(qint64,QString)));

//    connect(pui,SIGNAL(ConfirmCusRequestByGW(qint64)),pui,SLOT(ConfirmCusRequest(qint64)));

//    mpPub->setup();
//    mpSub->setup();

    emit starttimersignal();

//    thRcv.start();
    mpClientDBController->StartTimer();
    thDBController.start();


    ui->setupUi(this);
}

TestWindow::~TestWindow()
{
    delete ui;
}/*

void TestWindow::on_loc_register_btn_clicked()
{
    qint64 uLocId = ui->loc_lid_edit->text().toLongLong();
    double uLat = ui->loc_lat_edit->text().toDouble();
    double uLong = ui->loc_long_edit->text().toDouble();

    qDebug()<<"FromTestWindow, Lat:  "<<uLat<<"Long: "<<uLong;
//    qDebug()<<"FromTestWindow, Lat:  "<<QString::number(uLat)<<"Long: "<<QString::number(uLong,'g',10);
    mpDb->RegisterLocLL(uLocId,uLat,uLong);

//    ui->loc_lid_edit->clear();
//    ui->loc_lat_edit->clear();
//    ui->loc_long_edit->clear();
//    ui->loc_lid_edit->setFocus();
}

void TestWindow::on_loc_deregister_btn_clicked()
{
    qint64 uLocId = ui->loc_lid_edit->text().toLongLong();

    mpDb->DeregisterLocLL(uLocId);

    ui->loc_lid_edit->clear();
    ui->loc_lid_edit->setFocus();
}

void TestWindow::on_loc_update_btn_clicked()
{
    qint64 uLocId = ui->loc_lid_edit->text().toLongLong();
    double uLat = ui->loc_lat_edit->text().toDouble();
    double uLong = ui->loc_long_edit->text().toDouble();

    mpDb->UpdateLocLL(uLocId,uLat,uLong);

    ui->loc_lid_edit->setFocus();
}

void TestWindow::on_veh_register_btn_clicked()
{
    //get data
    if(!ui->veh_vid_edit->text().isEmpty() &&
            !ui->veh_lat_edit->text().isEmpty() &&
            !ui->veh_long_edit->text().isEmpty() &&
            !ui->veh_depot_edit->text().isEmpty() &&
            !ui->veh_capacity_edit->text().isEmpty() &&
            !ui->veh_speed_edit->text().isEmpty() &&
            !ui->veh_rftime_edit->text().isEmpty() &&
            !ui->veh_ftime_edit->text().isEmpty() &&
            !ui->veh_utime_edit->text().isEmpty() &&
            !ui->veh_btime_edit->text().isEmpty() &&
            !ui->veh_lcost_edit->text().isEmpty())
    {
        qint64 tVehId = ui->veh_vid_edit->text().toLongLong();
        double tLat = ui->veh_lat_edit->text().toDouble();
        double tLong = ui->veh_long_edit->text().toDouble();

        qint64 tDepot = ui->veh_depot_edit->text().toLongLong();
        qint64 tCapacity = ui->veh_capacity_edit->text().toLongLong();
        double tSpeed = ui->veh_speed_edit->text().toLongLong();
        qint64 tRefuelTime = ui->veh_rftime_edit->text().toLongLong();
        qint64 tFixTime = ui->veh_ftime_edit->text().toLongLong();
        qint64 tUnitTime = ui->veh_utime_edit->text().toLongLong();
        qint64 tBufferTime = ui->veh_btime_edit->text().toLongLong();
        qint64 tLaunchCost = ui->veh_lcost_edit->text().toLongLong();
        //companied with ll registration.
//        mpPub->VehRegister(tVehId,tDepot,tCapacity,tSpeed,tRefuelTime,
//                           tFixTime,tUnitTime,tBufferTime,tLaunchCost);
        mpDb->VehRegister(tVehId,tDepot,tCapacity,tSpeed,tRefuelTime,
                          tFixTime,tUnitTime,tBufferTime,tLaunchCost);
        mpDb->RegisterVehLL(tVehId,tLat,tLong);

    }else{
        qDebug()<<"data cannot be empty";
    }
}

void TestWindow::on_veh_deregister_btn_clicked()
{
    //get data
    if(!ui->veh_vid_edit->text().isEmpty())
    {
        qint64 tVehId = ui->veh_vid_edit->text().toLongLong();

        //companied with ll registration.
//        mpPub->VehDeregister(tVehId);
        mpDb->VehDeregister(tVehId);
        mpDb->DeregisterVehLL(tVehId);
    }else{
        qDebug()<<"vid cannot be empty";
    }
}

void TestWindow::on_veh_latlong_btn_clicked()
{
    //get data
    if(!ui->veh_vid_edit->text().isEmpty() &&
            !ui->veh_lat_edit->text().isEmpty() &&
            !ui->veh_long_edit->text().isEmpty())
    {
        qint64 tVehId = ui->veh_vid_edit->text().toLongLong();
        double tLat = ui->veh_lat_edit->text().toDouble();
        double tLong = ui->veh_long_edit->text().toDouble();

        mpDb->UpdateVehLL(tVehId,tLat,tLong);
    }else{
        qDebug()<<"data cannot be empty";
    }
}

void TestWindow::on_veh_depot_btn_clicked()
{
    //get data
    if(!ui->veh_vid_edit->text().isEmpty() &&
            !ui->veh_depot_edit->text().isEmpty())
    {
        qint64 tVehId = ui->veh_vid_edit->text().toLongLong();
        qint64 tDepot = ui->veh_depot_edit->text().toLongLong();

//        mpPub->VehSetDepot(tVehId,tDepot);
        mpDb->VehSetDepot(tVehId,tDepot);
    }else{
        qDebug()<<"data cannot be empty";
    }
}

void TestWindow::on_veh_capacity_btn_clicked()
{
    //get data
    if(!ui->veh_vid_edit->text().isEmpty() &&
            !ui->veh_capacity_edit->text().isEmpty())
    {
        qint64 tVehId = ui->veh_vid_edit->text().toLongLong();
        qint64 tCapacity = ui->veh_capacity_edit->text().toLongLong();

//        mpPub->VehSetCapacity(tVehId,tCapacity);
        mpDb->VehSetCapacity(tVehId,tCapacity);
    }else{
        qDebug()<<"data cannot be empty";
    }
}

void TestWindow::on_veh_speed_btn_clicked()
{
    //get data
    if(!ui->veh_vid_edit->text().isEmpty() &&
            !ui->veh_speed_edit->text().isEmpty())
    {
        qint64 tVehId = ui->veh_vid_edit->text().toLongLong();
        qint64 tSpeed = ui->veh_speed_edit->text().toDouble();

//        mpPub->VehSetSpeed(tVehId,tSpeed);
        mpDb->VehSetSpeed(tVehId,tSpeed);
    }else{
        qDebug()<<"data cannot be empty";
    }
}

void TestWindow::on_veh_rftime_btn_clicked()
{
    //get data
    if(!ui->veh_vid_edit->text().isEmpty() &&
            !ui->veh_rftime_edit->text().isEmpty())
    {
        qint64 tVehId = ui->veh_vid_edit->text().toLongLong();
        qint64 tRefuelTime = ui->veh_rftime_edit->text().toLongLong();

//        mpPub->VehSetRefuelTime(tVehId,tRefuelTime);
        mpDb->VehSetRefuelTime(tVehId,tRefuelTime);
    }else{
        qDebug()<<"data cannot be empty";
    }
}

void TestWindow::on_veh_ftime_btn_clicked()
{
    //get data
    if(!ui->veh_vid_edit->text().isEmpty() &&
            !ui->veh_ftime_edit->text().isEmpty())
    {
        qint64 tVehId = ui->veh_vid_edit->text().toLongLong();
        qint64 tFixTime = ui->veh_ftime_edit->text().toLongLong();

//        mpPub->VehSetFixTime(tVehId,tFixTime);
        mpDb->VehSetFixTime(tVehId,tFixTime);
    }else{
        qDebug()<<"data cannot be empty";
    }
}

void TestWindow::on_veh_utime_btn_clicked()
{
    //get data
    if(!ui->veh_vid_edit->text().isEmpty() &&
            !ui->veh_utime_edit->text().isEmpty())
    {
        qint64 tVehId = ui->veh_vid_edit->text().toLongLong();
        qint64 tUnitTime = ui->veh_utime_edit->text().toLongLong();

//        mpPub->VehSetUnitTime(tVehId,tUnitTime);
        mpDb->VehSetUnitTime(tVehId,tUnitTime);
    }else{
        qDebug()<<"data cannot be empty";
    }
}

void TestWindow::on_veh_btime_btn_clicked()
{
    //get data
    if(!ui->veh_vid_edit->text().isEmpty() &&
            !ui->veh_btime_edit->text().isEmpty())
    {
        qint64 tVehId = ui->veh_vid_edit->text().toLongLong();
        qint64 tBufferTime = ui->veh_btime_edit->text().toLongLong();

//        mpPub->VehSetBufferTime(tVehId,tBufferTime);
        mpDb->VehSetBufferTime(tVehId,tBufferTime);
    }else{
        qDebug()<<"data cannot be empty";
    }
}

void TestWindow::on_veh_lcost_btn_clicked()
{
    //get data
    if(!ui->veh_vid_edit->text().isEmpty() &&
            !ui->veh_lcost_edit->text().isEmpty())
    {
        qint64 tVehId = ui->veh_vid_edit->text().toLongLong();
        qint64 tLaunchCost = ui->veh_lcost_edit->text().toLongLong();

//        mpPub->VehSetLaunchCost(tVehId,tLaunchCost);
        mpDb->VehSetLaunchCost(tVehId,tLaunchCost);
    }else{
        qDebug()<<"data cannot be empty";
    }
}

void TestWindow::on_clean_veh_btn_clicked()
{
    ui->veh_btime_edit->clear();
    ui->veh_capacity_edit->clear();
    ui->veh_depot_edit->clear();
    ui->veh_ftime_edit->clear();
    ui->veh_lat_edit->clear();
    ui->veh_long_edit->clear();
    ui->veh_lcost_edit->clear();
    ui->veh_rftime_edit->clear();
    ui->veh_speed_edit->clear();
    ui->veh_utime_edit->clear();
    ui->veh_vid_edit->clear();
}

void TestWindow::on_cus_register_btn_clicked()
{
    if(!ui->cus_cid_edit->text().isEmpty() &&
            !ui->cus_dmd_edit->text().isEmpty() &&
            !ui->cus_ploc_edit->text().isEmpty() &&
            !ui->cus_dloc_edit->text().isEmpty() &&
            !ui->cus_rtime_edit->text().isEmpty() &&
            !ui->cus_wtime_edit->text().isEmpty())
    {
        qint64 tCusId = ui->cus_cid_edit->text().toLongLong();
        qint64 tDemand = ui->cus_dmd_edit->text().toLongLong();
        qint64 tPickupLoc = ui->cus_ploc_edit->text().toLongLong();
        qint64 tDeliveryLoc = ui->cus_dloc_edit->text().toLongLong();
        qint64 tReqTime = ui->cus_rtime_edit->text().toLongLong();
        qint64 tWaitTime = ui->cus_wtime_edit->text().toLongLong();

//        mpPub->CusRequest(tCusId,tDemand,tPickupLoc,tDeliveryLoc,tReqTime,tWaitTime);
        mpDb->CusRequest(tCusId,tDemand,tPickupLoc,tDeliveryLoc,tReqTime,tWaitTime);
    }else{
        qDebug()<<"data cannot be empty";
    }
}

void TestWindow::on_cus_deregister_btn_clicked()
{
    if(!ui->cus_cid_edit->text().isEmpty())
    {
        qint64 tCusId = ui->cus_cid_edit->text().toLongLong();

//        mpPub->CusDerequest(tCusId);
        mpDb->CusDerequest(tCusId);
    }else
    {
        qDebug()<<"data cannot be empty";
    }
}

void TestWindow::on_cus_chgreg_btn_clicked()
{
    if(!ui->cus_cid_edit->text().isEmpty() &&
            !ui->cus_dmd_edit->text().isEmpty() &&
            !ui->cus_ploc_edit->text().isEmpty() &&
            !ui->cus_dloc_edit->text().isEmpty() &&
            !ui->cus_rtime_edit->text().isEmpty() &&
            !ui->cus_wtime_edit->text().isEmpty())
    {
        qint64 tCusId = ui->cus_cid_edit->text().toLongLong();
        qint64 tDemand = ui->cus_dmd_edit->text().toLongLong();
        qint64 tPickupLoc = ui->cus_ploc_edit->text().toLongLong();
        qint64 tDeliveryLoc = ui->cus_dloc_edit->text().toLongLong();
        qint64 tReqTime = ui->cus_rtime_edit->text().toLongLong();
        qint64 tWaitTime = ui->cus_wtime_edit->text().toLongLong();

//        mpPub->CusChgReq(tCusId,tDemand,tPickupLoc,tDeliveryLoc,tReqTime,tWaitTime);
        mpDb->CusChgReq(tCusId,tDemand,tPickupLoc,tDeliveryLoc,tReqTime,tWaitTime);
    }else{
        qDebug()<<"data cannot be empty";
    }
}

void TestWindow::on_evt_arrive_btn_clicked()
{
    if(!ui->evt_vid_edit->text().isEmpty() &&
            !ui->evt_cid_edit->text().isEmpty() &&
            !ui->evt_dmd_edit->text().isEmpty())
    {
        qint64 tVehId = ui->evt_vid_edit->text().toLongLong();
        qint64 tCusId = ui->evt_cid_edit->text().toLongLong();
        qint64 tDemand = ui->evt_dmd_edit->text().toLongLong();

//        mpPub->OnArrivalEvent(tVehId,tCusId,tDemand);
//        mpDb->OnArrivalEvent(tVehId,tCusId,tDemand);
    }else
    {
        qDebug()<<"data cannot be empty";
    }
}

void TestWindow::createArrAnsDialog(qint64 aVehId, qint64 aCusId, qint64 aWaitingTime)
{
    QPair<qint64,qint64> tVCIdPair;
    tVCIdPair.first = aVehId;
    tVCIdPair.second = aCusId;
    cusconfirmdialog* tCusConfirmDialog = new cusconfirmdialog(aVehId,aCusId,aWaitingTime);

    connect(tCusConfirmDialog,SIGNAL(CusAnsPickup(qint64,qint64,QString)),this,SLOT(rcvCusAnsArrival(qint64,qint64,QString)));
    tCusConfirmDialog->showUp();

    mCusDialogHash.insert(tVCIdPair,tCusConfirmDialog);
}

void TestWindow::deleteArrAnsDialogSlot(qint64 aVehId, qint64 aCusId)
{
    QPair<qint64,qint64> tVCIdPair;
    tVCIdPair.first = aVehId;
    tVCIdPair.second = aCusId;

    mCusDialogHash[tVCIdPair]->hideShow();
    delete mCusDialogHash[tVCIdPair];
    mCusDialogHash.remove(tVCIdPair);
}

void TestWindow::rcvCusAnsArrival(qint64 aVehId, qint64 aCusId, QString aAnsStr)
{
    //string: yes/no

    //set wait time of veh in fms to 0
    {
        //...
    }

    emit sendCusConfirmAns(aVehId,aCusId,aAnsStr);

    QPair<qint64,qint64> tVCIdPair(aVehId,aCusId);
    mCusDialogHash[tVCIdPair]->hideShow();
    delete mCusDialogHash[tVCIdPair];
    mCusDialogHash.remove(tVCIdPair);
}



void TestWindow::on_evt_curTime_btn_clicked()
{
    if(!ui->evt_curTime_edit->text().isEmpty())
    {
        qint64 tCurTime = ui->evt_curTime_edit->text().toLongLong();

//        mpPub->SetCurrentTime(tCurTime);
        mpDb->SetCurrentTime(tCurTime);
    }
}

void TestWindow::on_pushButton_clicked()
{
    if(!ui->evt_vid_edit->text().isEmpty())
    {
        qint64 tVehId = ui->evt_vid_edit->text().toLongLong();

        mpDb->BackToDepotEvent(tVehId);
    }
}*/
