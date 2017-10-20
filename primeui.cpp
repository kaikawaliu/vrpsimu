#include "primeui.h"
#include "ui_primeui.h"

PrimeUI::PrimeUI(vrptest_db* apDb, QWidget *parent) :
    mpDb(apDb),
    QWidget(parent),
    ui(new Ui::PrimeUI)
{
    ui->setupUi(this);
//    ui->graphicsView = new QGraphicsView;
    parseConfigurables();

    mpMapView = new MapViewManager(ui->graphicsView);

    qDebug()<<"start connecting;";
    qRegisterMetaType<QPair<double,double>>("QPair<double,double>");
    qRegisterMetaType<QPair<qint64,qint64>>("QPair<qint64,qint64>");
    connect(mpMapView,SIGNAL(sendGotLLCoordToUI(QPair<double,double>)),this,SLOT(UIGetLocLLFromView(QPair<double,double>)));
    connect(mpMapView,SIGNAL(sendGotLLCoordToUI(QPair<double,double>)),this,SLOT(UIGetVehLLFromView(QPair<double,double>)));
    connect(mpMapView,SIGNAL(sendHoverPosToUI(QPair<qint64,qint64>,QPair<double,double>)),this,SLOT(ViewGetHoverScenePos(QPair<qint64,qint64>,QPair<double,double>)));
    connect(mpMapView,SIGNAL(sendHoverLeaveToUI()),this,SLOT(ViewGetHoverLeaveEvent()));

    qRegisterMetaType<QList<qint64>>("QList<qint64>");
    connect(mpMapView,SIGNAL(sendPressInMonMode(QString,QList<qint64>)),this,SLOT(getPressInMonMode(QString,QList<qint64>)));
    qRegisterMetaType<QHash<qint64,QPair<double,double>>>("QHash<qint64,QPair<double,double>>");
    connect(mpMapView,SIGNAL(sendPressInLocMode(QHash<qint64,QPair<double,double> >)),this,SLOT(getPressInLocMode(QHash<qint64,QPair<double,double> >)));
    connect(mpMapView,SIGNAL(sendPressInVehMode(QHash<qint64,QPair<double,double> >)),this,SLOT(getPressInVehMode(QHash<qint64,QPair<double,double> >)));
    connect(mpMapView,SIGNAL(sendPressInCusModeForLoc(QList<qint64>)),this,SLOT(getPressInCusModeForLoc(QList<qint64>)));
    qRegisterMetaType<QHash<qint64,bool>>("QHash<qint64,bool>");
    connect(mpMapView,SIGNAL(sendPressInCusModeForReq(QHash<qint64,bool>)),this,SLOT(getPressInCusModeForReq(QHash<qint64,bool>)));
    connect(mpMapView,SIGNAL(sendPressInEvtMode(QList<qint64>)),this,SLOT(getPressInEvtMode(QList<qint64>)));
    connect(mpMapView,SIGNAL(loseSelection()),this,SLOT(GetLoseSelection()));


    connect(mpDb,SIGNAL(informAddLocCoordByScan(qint64,double,double)),this,SLOT(InformedAddLocCoord(qint64,double,double)));
    connect(mpDb,SIGNAL(informDeleteLocCoordByScan(qint64)),this,SLOT(InformedDeleteLocCoord(qint64)));
    connect(mpDb,SIGNAL(informUpdateLocCoordByScan(qint64,double,double)),this,SLOT(InformedUpdateLocCoord(qint64,double,double)));

    connect(mpDb,SIGNAL(informAddVehCoordByScan(qint64,double,double)),this,SLOT(InformedAddVehCoord(qint64,double,double)));
    connect(mpDb,SIGNAL(informDeleteVehCoordByScan(qint64)),this,SLOT(InformedDeleteVehCoord(qint64)));
    connect(mpDb,SIGNAL(informUpdateVehCoordByScan(qint64,double,double)),this,SLOT(InformedUpdateVehCoord(qint64,double,double)));

    connect(mpDb,SIGNAL(informRegisterVehByScan(qint64,qint64,double,qint64,qint64,qint64,qint64,qint64,qint64,int)),this,SLOT(informedRegisterVeh(qint64,qint64,double,qint64,qint64,qint64,qint64,qint64,qint64,int)));
    connect(mpDb,SIGNAL(informDeregisterVehByScan(qint64)),this,SLOT(informedDeregisterVeh(qint64)));
    connect(mpDb,SIGNAL(informUpdateVehByScan(qint64,qint64,double,qint64,qint64,qint64,qint64,qint64)),this,SLOT(informedUpdateVeh(qint64,qint64,double,qint64,qint64,qint64,qint64,qint64)));

    connect(mpDb,SIGNAL(informAddRequestByScan(qint64,qint64,qint64,qint64,qint64,qint64,qint64,int)),this,SLOT(informedAddRequest(qint64,qint64,qint64,qint64,qint64,qint64,qint64,int)));
    connect(mpDb,SIGNAL(informUpdateRequestByScan(qint64,qint64,qint64,qint64,qint64,qint64,qint64)),this,SLOT(informedUpdateRequest(qint64,qint64,qint64,qint64,qint64,qint64,qint64)));
    connect(mpDb,SIGNAL(informCancelRequestByScan(qint64)),this,SLOT(informedCancelRequest(qint64)));

    connect(mpDb,SIGNAL(informJobUpdateByScan(qint64,QList<QHash<QString,qint64> >)),this,SLOT(informedJobUpdate(qint64,QList<QHash<QString,qint64> >)));
    connect(mpDb,SIGNAL(informUpdateVehCostByScan(qint64,qint64)),this,SLOT(informedUpdateVehCost(qint64,qint64)));
    connect(mpDb,SIGNAL(informUpdateVehInDepotByScan(qint64,int)),this,SLOT(informedUpdateVehInDepot(qint64,int)));
    connect(mpDb,SIGNAL(informGetPickedUpByScan(qint64)),this,SLOT(informedGetPickedUp(qint64)));
    connect(mpDb,SIGNAL(addArrPUAnsToUI(qint64,qint64,qint64)),this,SLOT(getReplyForEvtTriggerPUNotice(qint64,qint64,qint64)));
    connect(mpDb,SIGNAL(addArrDLAnsToUI(qint64,qint64,qint64)),this,SLOT(getReplyForEvtTriggerDLNotice(qint64,qint64,qint64)));
    connect(mpDb,SIGNAL(expirePUArrAnsFromUI(qint64,qint64)),this,SLOT(getReplyForEvtCusAnsPUExpire(qint64,qint64)));
    connect(mpDb,SIGNAL(expireDLArrAnsFromUI(qint64,qint64)),this,SLOT(getReplyForEvtCusAnsDLExpire(qint64,qint64)));

    connect(mpDb,SIGNAL(curTimeChanged()),this,SLOT(informedCurTimeChanged()));

    qDebug()<<"end connecting;";

    ui->graphicsView->show();

    //Initialization
    ui->monListWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->MonTableWidget->setSelectionMode(QAbstractItemView::NoSelection);
    ui->locTableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->vehTableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->cusTableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->evtVehTableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->evtJobsTableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->evtCusAnsTableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->evtLogTableWidget->setSelectionMode(QAbstractItemView::SingleSelection);


    ui->primaryStackedWidget->setCurrentIndex(0);
    ui->monToolBox->setCurrentIndex(mMonPage);
    mpMapView->SwitchView("mon");


    ui->MonTableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->locTableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
//    ui->vehTableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
//    ui->cusTableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
//    ui->evtVehTableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
//    ui->evtJobsTableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->evtCusAnsTableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
//    ui->evtLogTableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);


    ui->monListWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->MonTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->locTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->vehTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->cusTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->evtVehTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->evtJobsTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->evtCusAnsTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->evtLogTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);



//    int tRSTimes[4] = {0,600,1800,3600};
//    int tWTimes[3] = {300,600,900};

//    for(int i : mRSTimes)
//    {
//        mCusRSTimes.append(i);
//    }

//    for(int i : mWTimes)
//    {
//        mCusWTimes.append(i);
//    }

    //Install VehDefault Params [QHash(String,String)]
//    mVehDefaultParams.insert("speed","10");
//    mVehDefaultParams.insert("capacity","10");
//    mVehDefaultParams.insert("launchcost","300");
//    mVehDefaultParams.insert("fixtime","10");
//    mVehDefaultParams.insert("unittime","5");
//    mVehDefaultParams.insert("refueltime","36000");
//    mVehDefaultParams.insert("buffertime","300");

    refreshMonListWidget();
    refreshMonTableWidget();

    //it's the time to start sys timer
//    mpDb

    //Set Operation Time
    InitOperationTime();
}

PrimeUI::~PrimeUI()
{
    delete ui;
}

void PrimeUI::on_opTimeBtn_clicked()
{
    if(ui->endHourSpBox->value()>ui->startHourSpBox->value())
    {
        mpDb->setStartHour(ui->startHourSpBox->value());
        mpDb->setEndHour(ui->endHourSpBox->value());
    }else
    {
        ui->startHourSpBox->setValue(mpDb->getStartHour());
        ui->endHourSpBox->setValue(mpDb->getEndHour());
        QMessageBox::warning(this,"Setting Operation Time","End Hour Cannot be Less Than Start Hour",QMessageBox::Ok);
    }
}
