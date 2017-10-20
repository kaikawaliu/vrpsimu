#include "primeui.h"
#include "ui_primeui.h"


//====================================================
//Private Funcs:
//Generic:
qint64 PrimeUI::RealTimeToSimTime(QString aRealTime)
{

}

QString PrimeUI::SimTimeToRealTime(qint64 aSimTime)
{

}

void PrimeUI::updateDate()
{

}

void PrimeUI::resetAllViews()
{
    //also delete crosshair here
//    deleteCrossHairInView();
    LocResetInterface();
    VehResetInterface();
    CusResetInterface();
    EvtResetInterface();
}

void PrimeUI::refreshRelatedWidgets(QString aFlagStr, qint64 aId)
{
//    if(aFlagStr == "locA&D")
//    {
//        if(ui->primaryStackedWidget->currentIndex()==0)
//        {
//            //monpage
//            if(mMonPage==0)
//            {
//                ui->MonListRefreshBtn->setEnabled(true);
//            }
//        }else if(ui->primaryStackedWidget->currentIndex()==1)
//        {
//            //locpage
//            ui->locRefreshBtn->setEnabled(true);
//        }else if(ui->primaryStackedWidget->currentIndex()==3)
//        {
//            //cuspage
//            CusRefreshLocationComboList();
//        }
//    }else if(aFlagStr == "locU")
//    {
//        if(ui->primaryStackedWidget->currentIndex()==0)
//        {
//            if(mMonPage==0)
//            {
//                if(ui->MonTableWidgetLabel->text().split(" ").size()>1)
//                {
//                    if(ui->MonTableWidgetLabel->text().split(" ").at(1).toLongLong()==aId)
//                        ui->MonTableRefreshBtn->setEnabled(true);
//                }
//            }
//        }else if(ui->primaryStackedWidget->currentIndex()==1)
//        {
//            ui->locRefreshBtn->setEnabled(true);
//        }
//    }else if(aFlagStr == "vehcoordA&D")
//    {
//        if(ui->primaryStackedWidget->currentIndex()==0)
//        {
//            if(mMonPage==1)
//            {
//                ui->MonListRefreshBtn->setEnabled(true);
//            }
//        }else if(ui->primaryStackedWidget->currentIndex()==2)
//        {
//            ui->vehRefreshBtn->setEnabled(true);
//        }else if(ui->primaryStackedWidget->currentIndex()==4)
//        {
//            ui->evtVehRefreshBtn->setEnabled(true);
//        }
//    }else if(aFlagStr == "vehcoordU")
//    {
//        if(ui->primaryStackedWidget->currentIndex()==0)
//        {
//            if(mMonPage==1)
//            {
//                if(mVehOption==0)
//                {
//                    if(ui->MonTableWidgetLabel->text().split(" ").size()>1)
//                    {
//                        if(ui->MonTableWidgetLabel->text().split(" ").at(1).toLongLong()==aId)
//                        {
//                            ui->MonTableRefreshBtn->setEnabled(true);
//                        }
//                    }
//                }
//            }
//        }else if(ui->primaryStackedWidget->currentIndex()==2)
//        {
//            ui->vehRefreshBtn->setEnabled(true);
//        }
//    }
//    else if(aFlagStr == "vehprptyA&D")
//    {
//        if(ui->primaryStackedWidget->currentIndex()==0)
//        {
//            if(mMonPage==1)
//            {
//                ui->MonListRefreshBtn->setEnabled(true);
//            }
//        }else if(ui->primaryStackedWidget->currentIndex()==2)
//        {
//            ui->vehRefreshBtn->setEnabled(true);
//        }else if(ui->primaryStackedWidget->currentIndex()==4)
//        {
//            ui->evtVehRefreshBtn->setEnabled(true);
//        }
//    }
}

void PrimeUI::addCrossHairToView(QPair<double, double> aCoord)
{
    mpMapView->showCrossHair(mpMapView->CoordToPos(aCoord));
}

void PrimeUI::deleteCrossHairInView()
{
    mCrossHairCoord = QPair<double,double>(0,0);
    mpMapView->hideCrossHair();
}

bool PrimeUI::checkInRangeLat(double aLat)
{
     if(aLat*1000000>1237643 && aLat*1000000<1260340)
         return true;
     else
         return false;
}

bool PrimeUI::checkInRangeLong(double aLong)
{
    if(aLong*1000000>103806385 && aLong*1000000<103848614)
        return true;
    else
        return false;
}

void PrimeUI::parseConfigurables()
{
    //mCusRSTimes
    //mCusWTimes
    //mStartHour
    //mEndHour
    //mVehDefaultParams
    STKCI::tree_node tNode;
    STKCI::txml_doc_parser tParser;
    if(tParser.LoadFromFile(gVRPTestConfigFile,&tNode)>=0)
    {
        //Retrieve the mCusRSTimes
        STKCI::tree_node* tCusRSConfigNode = tNode.first_node("CusRSTimes");
        if(tCusRSConfigNode!=NULL)
        {
            STKCI::tree_node* tCusRSNode = tCusRSConfigNode->first_node();
            while(tCusRSNode!=NULL)
            {
                if(!tCusRSNode->name().empty())
                {
                    std::stringstream convert(tCusRSNode->value());
                    qint64 tRSTime;
                    convert>>tRSTime;
                    qDebug()<<"tRSTime: "<<tRSTime;
                    mCusRSTimes.append(tRSTime);
                }
                tCusRSNode = tCusRSNode->next_sibling();
            }
        }
        //Retrieve the mCusWTimes
        STKCI::tree_node* tCusWConfigNode = tNode.first_node("CusWTimes");
        if(tCusWConfigNode!=NULL)
        {
            STKCI::tree_node* tCusWNode = tCusWConfigNode->first_node();
            while(tCusWNode!=NULL)
            {
                if(!tCusWNode->name().empty())
                {
                    std::stringstream convert(tCusWNode->value());
                    qint64 tWTime;
                    convert>>tWTime;
                    qDebug()<<"tWTime: "<<tWTime;
                    mCusWTimes.append(tWTime);
                }
                tCusWNode = tCusWNode->next_sibling();
            }
        }
        //Retrieve the mVehDefaultParams
        STKCI::tree_node* tVehDefaultConfigNode = tNode.first_node("VehDefaultParams");
        if(tVehDefaultConfigNode!=NULL)
        {
            STKCI::tree_node* tVehDefaultNode = tVehDefaultConfigNode->first_node();
            while(tVehDefaultNode!=NULL)
            {

                if(!tVehDefaultNode->name().empty())
                {
                    std::stringstream convert(tVehDefaultNode->value());
                    if(tVehDefaultNode->name()=="speed")
                    {
                        double tSpeed;
                        convert>>tSpeed;
                        qDebug()<<"tDefaultSpeed: "<<tSpeed;
                        mVehDefaultParams.insert("speed",QString("%1").arg(tSpeed));
                    }else if(tVehDefaultNode->name()=="capacity")
                    {
                        int tCapacity;
                        convert>>tCapacity;
                        qDebug()<<"tDefaultCapacity: "<<tCapacity;
                        mVehDefaultParams.insert("capacity",QString("%1").arg(tCapacity));
                    }else if(tVehDefaultNode->name()=="launchcost")
                    {
                        int tLaunchCost;
                        convert>>tLaunchCost;
                        qDebug()<<"tDefaultLaunchCost: "<<tLaunchCost;
                        mVehDefaultParams.insert("launchcost",QString("%1").arg(tLaunchCost));
                    }else if(tVehDefaultNode->name()=="fixtime")
                    {
                        int tFixtime;
                        convert>>tFixtime;
                        qDebug()<<"tDefaultFixTime: "<<tFixtime;
                        mVehDefaultParams.insert("fixtime",QString("%1").arg(tFixtime));
                    }else if(tVehDefaultNode->name()=="unittime")
                    {
                        int tUnittime;
                        convert>>tUnittime;
                        qDebug()<<"tDefaultUnitTime: "<<tUnittime;
                        mVehDefaultParams.insert("unittime",QString("%1").arg(tUnittime));
                    }else if(tVehDefaultNode->name()=="refueltime")
                    {
                        int tRefueltime;
                        convert>>tRefueltime;
                        qDebug()<<"tRefuelRefuelTime: "<<tRefueltime;
                        mVehDefaultParams.insert("refueltime",QString("%1").arg(tRefueltime));
                    }else if(tVehDefaultNode->name()=="buffertime")
                    {
                        int tBuffertime;
                        convert>>tBuffertime;
                        qDebug()<<"tDefaultBufferTime: "<<tBuffertime;
                        mVehDefaultParams.insert("buffertime",QString("%1").arg(tBuffertime));
                    }
                }
                tVehDefaultNode = tVehDefaultNode->next_sibling();
            }
            mpDb->setDefaultVehParams(mVehDefaultParams);
        }
    }
}

void PrimeUI::InitOperationTime()
{
    ui->startHourSpBox->setValue(mpDb->getStartHour());
    ui->endHourSpBox->setValue(mpDb->getEndHour());

    on_opTimeBtn_clicked();
}

void PrimeUI::resetEverything()
{

}

//Monitoring:
void PrimeUI::refreshMonListWidget()
{
//    qDebug()<<"refreshMonListWidget";
    QString tListLabel;
    ui->monListWidget->clear();
    QList<qint64> tMonListItemIds;

    if(mMonPage==0)
    {
        tListLabel = QString("Locations");
        tMonListItemIds = mLocRegistereds.keys();
    }else if(mMonPage==1)
    {
        tListLabel = QString("Vehicles");
        tMonListItemIds = mVehPrptyRegistereds.keys();
    }else if(mMonPage==2)
    {
        tListLabel = QString("Requests");
        tMonListItemIds = mCusRequesteds.keys();
    }
    QList<QString> tMonListItemIdsStrs;
    for(int i = 0; i < tMonListItemIds.size(); ++i)
    {
        QString tMonListItemIdStr = QString("%1").arg(tMonListItemIds.at(i));
        tMonListItemIdsStrs.append(tMonListItemIdStr);
    }
    ui->MonListWidgetLabel->setText(tListLabel);
    ui->monListWidget->addItems(tMonListItemIdsStrs);

    if(tMonListItemIdsStrs.size()>0)
    {
        ui->monListWidget->setCurrentRow(0);
    }

    MonUIPageUpdateView();
}

void PrimeUI::refreshMonTableWidget(qint64 aId)
{
//    qDebug()<<"refreshMonTableWidget";
    QString tTableLabel;
    tTableLabel = QString("Details");

    ui->MonTableWidget->clear();

    qint64 tId = aId;

    if(aId == 0)
    {
        if(ui->monListWidget->count()>0)
        {
            tId = ui->monListWidget->item(0)->text().toLongLong();
        }
    }

    if(tId!=0){
//        ui->monListWidget->setCurrentRow(0);
        if(mMonPage==0)
        {
            tTableLabel = QString("Location %1").arg(tId);

//            QHash<qint64,qint64> tDists = mMonLocDistsHash.value(tId);
//            QList<qint64> tLocations = tDists.keys();
            ui->MonTableWidget->setColumnCount(2);
            ui->MonTableWidget->setRowCount(2/*+1+tLocations.size()*/);
            QTableWidgetItem *tLatUnitItem = new QTableWidgetItem("Lat");
            QTableWidgetItem *tLongUnitItem = new QTableWidgetItem("Long");
            ui->MonTableWidget->setItem(0,0,tLatUnitItem);
            ui->MonTableWidget->setItem(1,0,tLongUnitItem);
            QPair<double,double> tLL = mLocRegistereds.value(tId);
            QTableWidgetItem *tLatItem = new QTableWidgetItem(QString::number(tLL.first,'g',10));
            QTableWidgetItem *tLongItem = new QTableWidgetItem(QString::number(tLL.first,'g',10));
            ui->MonTableWidget->setItem(0,1,tLatItem);
            ui->MonTableWidget->setItem(1,1,tLongItem);

//            QTableWidgetItem *tLocUnitItem = new QTableWidgetItem(QString("Location Id"));
//            ui->MonTableWidget->setItem(2,0,tLocUnitItem);
//            QTableWidgetItem *tDistUnitItem = new QTableWidgetItem(QString("Distance"));
//            ui->MonTableWidget->setItem(2,1,tDistUnitItem);

//            for(int i = 0; i < tLocations.size(); ++i)
//            {
//                qint64 tLocId = tLocations.at(i);
//                QTableWidgetItem *tLocIdItem = new QTableWidgetItem(QString("%1").arg(tLocId));
//                ui->MonTableWidget->setItem(i+1+2,0,tLocIdItem);
//                qint64 tDist = tDists.value(tLocId);
//                QTableWidgetItem *tDistItem = new QTableWidgetItem(QString("%1").arg(tDist));
//                ui->MonTableWidget->setItem(i+1+2,1,tDistItem);
//            }
        }else if(mMonPage==1)
        {
            if(mVehOption==0)//Status //params + cost + in/out
            {
                tTableLabel = QString("Vehicle %1 Status").arg(tId);

                QPair<double,double> tCoord = mVehCoordsHash.value(tId);
                QHash<QString,QString> tPrptyHash = mVehPrptyRegistereds.value(tId);
                QList<QString> tParams;
                tParams.append("lat");
                tParams.append("long");
                tParams.append(tPrptyHash.keys());

                ui->MonTableWidget->setColumnCount(2);
                ui->MonTableWidget->setRowCount(2+tParams.size()-2);

                QTableWidgetItem *tLatUnitItem = new QTableWidgetItem("lat");
                ui->MonTableWidget->setItem(0,0,tLatUnitItem);
                QTableWidgetItem *tLatItem = new QTableWidgetItem(QString::number(tCoord.first,'g',10));
                ui->MonTableWidget->setItem(0,1,tLatItem);
                QTableWidgetItem *tLongUnitItem = new QTableWidgetItem("long");
                ui->MonTableWidget->setItem(1,0,tLongUnitItem);
                QTableWidgetItem *tLongItem = new QTableWidgetItem(QString::number(tCoord.second,'g',10));
                ui->MonTableWidget->setItem(1,1,tLongItem);

                for(int i = 0; i < tParams.size(); ++i)
                {
                    if(tParams.at(i)=="lat"||tParams.at(i)=="long")
                    {

                    }else
                    {
                        QTableWidgetItem *tParamItem = new QTableWidgetItem(tParams.at(i));
                        ui->MonTableWidget->setItem(i+2-2,0,tParamItem);
                        QTableWidgetItem *tValueItem = new QTableWidgetItem(tPrptyHash.value(tParams.at(i)));
                        ui->MonTableWidget->setItem(i+2-2,1,tValueItem);
                    }
                }
            }else if(mVehOption==1)//Distances
            {
//                tTableLabel = QString("Vehicle %1 Distances").arg(tId);
//                QHash<qint64,qint64> tDists = mMonVehDistsHash.value(tId);
//                QList<qint64> tLocations = tDists.keys();

//                ui->MonTableWidget->setRowCount(tLocations.size()+1);
//                ui->MonTableWidget->setColumnCount(2);

//                QTableWidgetItem *tLocUnitItem = new QTableWidgetItem(QString("Location Id"));
//                ui->MonTableWidget->setItem(0,0,tLocUnitItem);
//                QTableWidgetItem *tDistUnitItem = new QTableWidgetItem(QString("Distance"));
//                ui->MonTableWidget->setItem(0,1,tDistUnitItem);

//                for(int i = 0; i < tLocations.size(); ++i)
//                {
//                    qint64 tLocId = tLocations.at(i);
//                    QTableWidgetItem *tLocIdItem = new QTableWidgetItem(QString("%1").arg(tLocId));
//                    ui->MonTableWidget->setItem(i+1,0,tLocIdItem);
//                    qint64 tDist = tDists.value(tLocId);
//                    QTableWidgetItem *tDistItem = new QTableWidgetItem(QString("%1").arg(tDist));
//                    ui->MonTableWidget->setItem(i+1,1,tDistItem);
//                }
            }
            else if(mVehOption==2)//Jobs
            {
                tTableLabel = QString("Vehicle %1 Jobs").arg(tId);

                QList<QHash<QString,qint64>> tJobs = mVehJobsHash.value(tId);

                if(tJobs.size()>0){
                    QList<QString> tParams = tJobs.at(0).keys();

                    ui->MonTableWidget->setRowCount(tJobs.size()+1);
                    ui->MonTableWidget->setColumnCount(tParams.size());
                    //unit
                    for(int i = 0; i < tParams.size(); ++i)
                    {
                        QTableWidgetItem *tParamItem = new QTableWidgetItem(tParams.at(i));
                        ui->MonTableWidget->setItem(0,i,tParamItem);
                    }
                    //value
                    for(int i = 0; i < tJobs.size(); ++i)
                    {
                        if(tJobs.at(i).value("loc")<0)
                        {
                            //do nothing
                        }else
                        {
                            for(int j = 0; j < tParams.size(); ++j)
                            {
                                QTableWidgetItem *tValueItem = new QTableWidgetItem(QString("%1").arg(tJobs.at(i).value(tParams.at(j))));
                                ui->MonTableWidget->setItem(1+i,j,tValueItem);
                            }
                        }
                    }
                }
            }
        }else if(mMonPage==2) //params + pickedupFlag
        {
            tTableLabel = QString("Request %1").arg(tId);

            QHash<QString,qint64> tHash = mCusRequesteds.value(tId);
            QList<QString> tParams = tHash.keys();

            ui->MonTableWidget->setColumnCount(2);
            ui->MonTableWidget->setRowCount(tParams.size());
            for(int i = 0; i < tParams.size(); ++i)
            {
                QTableWidgetItem *tParamItem = new QTableWidgetItem(tParams.at(i));
                ui->MonTableWidget->setItem(i,0,tParamItem);
                QTableWidgetItem *tValueItem = new QTableWidgetItem(QString("%1").arg(tHash.value(tParams.at(i))));
                ui->MonTableWidget->setItem(i,1,tValueItem);
            }
        }

        MonUIUpdateView(tId);
    }
    ui->MonTableWidgetLabel->setText(tTableLabel);
}

void PrimeUI::MonUIPageUpdateView()
{
    mpMapView->SwitchMonPage(mMonPage);
}

void PrimeUI::MonUIUpdateView(qint64 aId)
{
    if(aId!=0){
        QString tViewStr;
        if(mMonPage==0)
        {
            tViewStr = "loc";
        }
        else if(mMonPage==1)
        {
            tViewStr = "veh";
        }else if(mMonPage==2)
        {
            tViewStr = "cus";
        }
        mpMapView->focusOnItem(tViewStr,aId);
    }
}

//Loc Manager:
void PrimeUI::refreshLocTableWidget()
{
    locCellSelected=false;
    ui->locTableWidget->clear();

    QList<qint64> tIdList = mLocRegistereds.keys();

    ui->locTableWidget->setColumnCount(3);
    ui->locTableWidget->setRowCount(1+tIdList.size());

    QTableWidgetItem *tLocIdUnitItem = new QTableWidgetItem("ID");
    ui->locTableWidget->setItem(0,0,tLocIdUnitItem);
    QTableWidgetItem *tLocLatUnitItem = new QTableWidgetItem("Lat");
    ui->locTableWidget->setItem(0,1,tLocLatUnitItem);
    QTableWidgetItem *tLocLongUnitItem = new QTableWidgetItem("Long");
    ui->locTableWidget->setItem(0,2,tLocLongUnitItem);

    for(int i = 0; i < tIdList.size(); ++i)
    {
        QTableWidgetItem *tLocIdItem = new QTableWidgetItem(QString("%1").arg(tIdList.at(i)));
        ui->locTableWidget->setItem(1+i,0,tLocIdItem);
        QTableWidgetItem *tLocLatItem = new QTableWidgetItem(QString::number(mLocRegistereds.value(tIdList.at(i)).first,'g',10));
        ui->locTableWidget->setItem(1+i,1,tLocLatItem);
        QTableWidgetItem *tLocLongItem = new QTableWidgetItem(QString::number(mLocRegistereds.value(tIdList.at(i)).second,'g',10));
        ui->locTableWidget->setItem(1+i,2,tLocLongItem);
    }
}

void PrimeUI::LocRegisterByUI(qint64 aLocId, QPair<double, double> aLocCoord)
{
    if(!mLocRegistereds.contains(aLocId)){
        if(mpDb->RegisterLocLL(aLocId,aLocCoord.first,aLocCoord.second))
        {
//            LocRegisterToView(aLocId,aLocCoord);
//            if(!mLocRegistereds.contains(aLocId))
//            {
//                mLocRegistereds.insert(aLocId,aLocCoord);
//            }
        }else
        {
            QMessageBox::warning(this,QString("Register Location %1").arg(aLocId),"Failed!",QMessageBox::Ok);
        }
    }else
    {
        QMessageBox::warning(this,QString("Register Location %1").arg(aLocId),"This ID already registered",QMessageBox::Ok);
    }
}

void PrimeUI::LocDeregisterByUI(qint64 aLocId)
{
    if(mLocRegistereds.contains(aLocId))
    {
        if(mpDb->DeregisterLocLL(aLocId))
        {
//            LocDeregisterToView(aLocId);
//            if(mLocRegistereds.contains(aLocId))
//            {
//                mLocRegistereds.remove(aLocId);
//            }
        }else
        {
            QMessageBox::warning(this,QString("Deregister Location %1").arg(aLocId),"Failed!",QMessageBox::Ok);
        }
    }else
    {
        QMessageBox::warning(this,QString("Deregister Location %1").arg(aLocId),"No Such Location ID",QMessageBox::Ok);
    }

}

void PrimeUI::LocUpdateByUI(qint64 aLocId, QPair<double, double> aLocCoord)
{
    if(mLocRegistereds.contains(aLocId))
    {
        if(mpDb->UpdateLocLL(aLocId,aLocCoord.first,aLocCoord.second))
        {
//            LocUpdateToView(aLocId,aLocCoord);
//            if(mLocRegistereds.contains(aLocId))
//                mLocRegistereds[aLocId]=aLocCoord;
        }else
        {
            QMessageBox::warning(this,QString("Update Location %1").arg(aLocId),"Failed!",QMessageBox::Ok);
        }
    }else
    {
        QMessageBox::warning(this,QString("Update Location %1").arg(aLocId),"No Such Location ID",QMessageBox::Ok);
    }
}

void PrimeUI::LocRegisterToView(qint64 aLocId, QPair<double,double> aLocCoord)
{
    mpMapView->RegisterLandmarkInView(aLocId,aLocCoord);
}

void PrimeUI::LocDeregisterToView(qint64 aLocId)
{
    mpMapView->DeregisterLandmarkInView(aLocId);
}

void PrimeUI::LocUpdateToView(qint64 aLocId, QPair<double,double> aLocCoord)
{
    mpMapView->SetLandmarkPosInView(aLocId,aLocCoord);
}

void PrimeUI::LocResetInterface()
{
    mpMapView->leaveGetLLMode();
    mpMapView->clearFocus();
    locCellSelected=false;
    deleteCrossHairInView();
    mLocClickedId = 0;
    mLocMode = "";
    ui->locTableWidget->clearSelection();
    ui->locTableWidget->setEnabled(true);
    ui->locRegBtn->setEnabled(true);
    ui->locDeregBtn->setEnabled(false);
    ui->locUpdateBtn->setEnabled(false);
    ui->locLatLabel->setEnabled(false);
    ui->locLongLabel->setEnabled(false);
    ui->locIdEdit->clear();
    ui->locIdEdit->setEnabled(false);
    ui->locLatEdit->clear();
    ui->locLatEdit->setEnabled(false);
    ui->locLongEdit->clear();
    ui->locLongEdit->setEnabled(false);
    ui->LLGetCoordBtn->setEnabled(false);
    ui->LLReflectBtn->setEnabled(false);
    ui->locConfirmBtn->setEnabled(false);
    ui->locConfirmBtn->setText("Confirm");
    ui->locCancelBtn->setEnabled(false);
//    qDebug()<<"finish loc reset";
}

//Veh Manager:
void PrimeUI::refreshVehTableWidget()
{
    vehCellSelected=false;
    ui->vehTableWidget->clear();

    QList<qint64> tIdList = mVehPrptyRegistereds.keys();

    ui->vehTableWidget->setColumnCount(10);
    ui->vehTableWidget->setRowCount(1+tIdList.size());

    QTableWidgetItem *tVehIdUnitItem = new QTableWidgetItem("ID");//0
    ui->vehTableWidget->setItem(0,0,tVehIdUnitItem);
    QTableWidgetItem *tVehLatUnitItem = new QTableWidgetItem("Lat");//1
    ui->vehTableWidget->setItem(0,1,tVehLatUnitItem);
    QTableWidgetItem *tVehLongUnitItem = new QTableWidgetItem("Long");//2
    ui->vehTableWidget->setItem(0,2,tVehLongUnitItem);
    QTableWidgetItem *tVehSpeedUnitItem = new QTableWidgetItem("Speed");//3
    ui->vehTableWidget->setItem(0,3,tVehSpeedUnitItem);
    QTableWidgetItem *tVehCapacityUnitItem = new QTableWidgetItem("Capacity");//4
    ui->vehTableWidget->setItem(0,4,tVehCapacityUnitItem);
    QTableWidgetItem *tVehLaunchCostUnitItem = new QTableWidgetItem("Launch Cost");//5
    ui->vehTableWidget->setItem(0,5,tVehLaunchCostUnitItem);
    QTableWidgetItem *tVehFixTimeUnitItem = new QTableWidgetItem("Fix Time");//6
    ui->vehTableWidget->setItem(0,6,tVehFixTimeUnitItem);
    QTableWidgetItem *tVehUnitTimeUnitItem = new QTableWidgetItem("Unit Time");//7
    ui->vehTableWidget->setItem(0,7,tVehUnitTimeUnitItem);
    QTableWidgetItem *tVehRefuelTimeUnitItem = new QTableWidgetItem("Refuel Time");//8
    ui->vehTableWidget->setItem(0,8,tVehRefuelTimeUnitItem);
    QTableWidgetItem *tVehBufferTimeUnitItem = new QTableWidgetItem("Buffer Time");//9
    ui->vehTableWidget->setItem(0,9,tVehBufferTimeUnitItem);

    for(int i = 0; i < tIdList.size(); ++i)
    {
        QTableWidgetItem *tVehIdItem = new QTableWidgetItem(QString("%1").arg(tIdList.at(i)));
        ui->vehTableWidget->setItem(1+i,0,tVehIdItem);
        QTableWidgetItem *tVehLatItem = new QTableWidgetItem(QString::number(mVehCoordsHash.value(tIdList.at(i)).first,'g',10));
        ui->vehTableWidget->setItem(1+i,1,tVehLatItem);
        QTableWidgetItem *tVehLongItem = new QTableWidgetItem(QString::number(mVehCoordsHash.value(tIdList.at(i)).first,'g',10));
        ui->vehTableWidget->setItem(1+i,2,tVehLongItem);
        QTableWidgetItem *tVehSpeedItem = new QTableWidgetItem(mVehPrptyRegistereds.value(tIdList.at(i)).value("speed"));
        ui->vehTableWidget->setItem(1+i,3,tVehSpeedItem);
        QTableWidgetItem *tVehCapacityItem = new QTableWidgetItem(mVehPrptyRegistereds.value(tIdList.at(i)).value("capacity"));
        ui->vehTableWidget->setItem(1+i,4,tVehCapacityItem);
        QTableWidgetItem *tVehLaunchCostItem = new QTableWidgetItem(mVehPrptyRegistereds.value(tIdList.at(i)).value("launchcost"));
        ui->vehTableWidget->setItem(1+i,5,tVehLaunchCostItem);
        QTableWidgetItem *tVehFixTimeItem = new QTableWidgetItem(mVehPrptyRegistereds.value(tIdList.at(i)).value("fixtime"));
        ui->vehTableWidget->setItem(1+i,6,tVehFixTimeItem);
        QTableWidgetItem *tVehUnitTimeItem = new QTableWidgetItem(mVehPrptyRegistereds.value(tIdList.at(i)).value("unittime"));
        ui->vehTableWidget->setItem(1+i,7,tVehUnitTimeItem);
        QTableWidgetItem *tVehRefuelTimeItem = new QTableWidgetItem(mVehPrptyRegistereds.value(tIdList.at(i)).value("refueltime"));
        ui->vehTableWidget->setItem(1+i,8,tVehRefuelTimeItem);
        QTableWidgetItem *tVehBufferTimeItem = new QTableWidgetItem(mVehPrptyRegistereds.value(tIdList.at(i)).value("buffertime"));
        ui->vehTableWidget->setItem(1+i,9,tVehBufferTimeItem);
    }

}

void PrimeUI::VehRegisterByUI(qint64 aVehId, QPair<double, double> aVehCoord, QHash<QString, QString> aVehHash)
{
    if(!mVehPrptyRegistereds.contains(aVehId)){
        if(mpDb->RegisterVehLL(aVehId,aVehCoord.first,aVehCoord.second))
        {
//            if(!mVehCoordsHash.contains(aVehId))
//            {
//                mVehCoordsHash.insert(aVehId,aVehCoord);
//            }else
//            {
//                mVehCoordsHash[aVehId]=aVehCoord;
//            }

            double tSpeed = aVehHash.value("speed").toDouble();
            qint64 tCapacity = aVehHash.value("capacity").toLongLong();
            qint64 tLaunchCost = aVehHash.value("launchcost").toLongLong();
            qint64 tFixTime = aVehHash.value("fixtime").toLongLong();
            qint64 tUnitTime = aVehHash.value("unittime").toLongLong();
            qint64 tRefuelTime = aVehHash.value("refueltime").toLongLong();
            qint64 tBufferTime = aVehHash.value("buffertime").toLongLong();
            if(mpDb->VehRegister(aVehId,0,tCapacity,tSpeed,tRefuelTime,tFixTime,tUnitTime,tBufferTime,tLaunchCost))
            {
//                if(!mVehPrptyRegisterings.contains(aVehId))
//                {
//                    mVehPrptyRegisterings.insert(aVehId,aVehHash);
//                }else
//                {
//                    mVehPrptyRegisterings[aVehId]=aVehHash;
//                }
            }else
            {
                QMessageBox::warning(this,QString("Register Vehicle %1 Property").arg(aVehId),"Failed!",QMessageBox::Ok);
            }
        }else
        {
            QMessageBox::warning(this,QString("Register Vehicle Coord").arg(aVehId),"Failed!",QMessageBox::Ok);
        }
    }else
    {
        QMessageBox::warning(this,QString("Register Vehicle").arg(aVehId),"This ID already registered",QMessageBox::Ok);
    }
}

void PrimeUI::VehDeregisterByUI(qint64 aVehId)
{
    if(mVehPrptyRegistereds.contains(aVehId))
    {
        if(mpDb->VehDeregister(aVehId))
        {
            mpDb->DeregisterVehLL(aVehId);
            //do nothing
        }else
        {
            QMessageBox::warning(this,QString("Deregister Vehicle %1 Property").arg(aVehId),"Failed!",QMessageBox::Ok);
        }
    }else
    {
        QMessageBox::warning(this,QString("Deregister Vehicle %1 Property").arg(aVehId),"No Such Vehicle ID",QMessageBox::Ok);
    }
}

void PrimeUI::VehPrptyUpdateByUI(qint64 aVehId, QString aType, QString aValue)
{
    if(mVehPrptyRegistereds.contains(aVehId))
    {
        bool tRet;
        if(aType=="speed")
        {
            tRet = mpDb->VehSetSpeed(aVehId,aValue.toDouble());
        }else if(aType=="capacity")
        {
            tRet = mpDb->VehSetCapacity(aVehId,aValue.toLongLong());
        }else if(aType=="launchcost")
        {
            tRet = mpDb->VehSetLaunchCost(aVehId,aValue.toLongLong());
        }else if(aType=="fixtime")
        {
            tRet = mpDb->VehSetFixTime(aVehId,aValue.toLongLong());
        }else if(aType=="unittime")
        {
            tRet = mpDb->VehSetUnitTime(aVehId,aValue.toLongLong());
        }else if(aType=="refueltime")
        {
            tRet = mpDb->VehSetRefuelTime(aVehId,aValue.toLongLong());
        }else if(aType=="buffertime")
        {
            tRet = mpDb->VehSetBufferTime(aVehId,aValue.toLongLong());
        }
        if(tRet)
        {
//            if(!mVehPrptyUpdatings.contains(aVehId))
//            {
//                QHash<QString,QString> tHash;
//                tHash.insert(aType,aValue);
//                mVehPrptyUpdatings.insert(aVehId,tHash);
//            }else
//            {
//                if(!mVehPrptyUpdatings.value(aVehId).contains(aType))
//                {
//                    mVehPrptyUpdatings[aVehId].insert(aType,aValue);
//                }else
//                {
//                    mVehPrptyUpdatings[aVehId][aType] = aValue;
//                }
//            }
        }else
        {
            QMessageBox::warning(this,QString("Update Veh %1 %2").arg(aVehId).arg(aType),"Failed!",QMessageBox::Ok);
        }
    }else
    {
        QMessageBox::warning(this,QString("Update Veh %1 %2").arg(aVehId).arg(aType),"No Such Vehicle ID",QMessageBox::Ok);
    }
}

void PrimeUI::VehCoordUpdateByUI(qint64 aVehId, QPair<double, double> aVehCoord)
{
    if(mVehCoordsHash.contains(aVehId))
    {
        if(mpDb->UpdateVehLL(aVehId,aVehCoord.first,aVehCoord.second))
        {
//            if(mVehCoordsHash.contains(aVehId))
//                mVehCoordsHash[aVehId]=aVehCoord;
        }else
        {
            QMessageBox::warning(this,QString("Update Vehicle %1 Coord").arg(aVehId),"Failed!",QMessageBox::Ok);
        }
    }else
    {
        QMessageBox::warning(this,QString("Update Vehicle %1 Coord").arg(aVehId),"No Such Location ID",QMessageBox::Ok);
    }
}

void PrimeUI::VehRegisterToView(qint64 aVehId, QPair<double, double> aVehCoord)
{
//    QList<qint64> tDestList;
    mpMapView->RegisterVehicleEntityInView(aVehId,aVehCoord/*,tDestList*/);
}

void PrimeUI::VehDeregisterToView(qint64 aVehId)
{
    mpMapView->DeregisterVehicleInView(aVehId);
}

void PrimeUI::VehPrptyUpdateToView(qint64 aVehId, QString aType)
{

}

void PrimeUI::VehJobUpdateToView(qint64 aVehId)
{
    if(mVehJobsHash.contains(aVehId))
    {
        QList<qint64> tDests;
        QList<QHash<QString,qint64>> tJobs = mVehJobsHash.value(aVehId);
        for(int i = 0; i < tJobs.size(); ++i)
        {
            tDests.append(tJobs.at(i).value("loc"));
        }
        mpMapView->RescheduleDest(aVehId,tDests);
    }
}

void PrimeUI::VehCoordUpdateToView(qint64 aVehId, QPair<double, double> aVehCoord)
{
    mpMapView->SetVehPosInView(aVehId,aVehCoord);
}

void PrimeUI::VehResetInterface()
{
    mpMapView->leaveGetLLMode();
    mpMapView->clearFocus();
    vehCellSelected=false;
    deleteCrossHairInView();
    mVehClickedId = 0;
    mVehMode = "";
    ui->vehTableWidget->clearSelection();
    ui->vehTableWidget->setEnabled(true);
    ui->vehRegBtn->setEnabled(true);
    ui->vehDeregBtn->setEnabled(false);
    ui->vehUpdateBtn->setEnabled(false);
    ui->vehIdEdit->clear();
    ui->vehIdEdit->setEnabled(false);
    ui->vehCoordChBox->setChecked(false);
    ui->vehCoordChBox->setEnabled(false);
    ui->vehLatLabel->setEnabled(false);
    ui->vehLongLabel->setEnabled(false);
    ui->vehLatEdit->clear();
    ui->vehLatEdit->setEnabled(false);
    ui->vehLongEdit->clear();
    ui->vehLongEdit->setEnabled(false);
    ui->vehSpeedChBox->setChecked(false);
    ui->vehSpeedChBox->setEnabled(false);
    ui->vehSpeedEdit->clear();
    ui->vehSpeedEdit->setEnabled(false);
    ui->vehCapChBox->setChecked(false);
    ui->vehCapChBox->setEnabled(false);
    ui->vehCapSpBox->setValue(0);
    ui->vehCapSpBox->setEnabled(false);
    ui->vehLCostChBox->setChecked(false);
    ui->vehLCostChBox->setEnabled(false);
    ui->vehLCostSpBox->setValue(0);
    ui->vehLCostSpBox->setEnabled(false);
    ui->vehFTimeChBox->setChecked(false);
    ui->vehFTimeChBox->setEnabled(false);
    ui->vehFTimeSpBox->setValue(0);
    ui->vehFTimeSpBox->setEnabled(false);
    ui->vehUTimeChBox->setChecked(false);
    ui->vehUTimeChBox->setEnabled(false);
    ui->vehUTimeSpBox->setValue(0);
    ui->vehUTimeSpBox->setEnabled(false);
    ui->vehRTimeChBox->setChecked(false);
    ui->vehRTimeChBox->setEnabled(false);
    ui->vehRTimeSpBox->setValue(0);
    ui->vehRTimeSpBox->setEnabled(false);
    ui->vehBTimeChBox->setChecked(false);
    ui->vehBTimeChBox->setEnabled(false);
    ui->vehBTimeSpBox->setValue(0);
    ui->vehBTimeSpBox->setEnabled(false);
    ui->vehGetCoordBtn->setEnabled(false);
    ui->vehRefCoordBtn->setEnabled(false);
    ui->vehDefaultBtn->setEnabled(false);
    ui->vehConfirmBtn->setEnabled(false);
    ui->vehConfirmBtn->setText("Confirm");
    ui->vehCancelBtn->setEnabled(false);
//    qDebug()<<"finish veh reset";
}

//Cus Manager:
void PrimeUI::refreshCusTableWidget()
{
    cusCellSelected=false;
    ui->cusTableWidget->clear();

    QList<qint64> tIdList = mCusRequesteds.keys();

    ui->cusTableWidget->setColumnCount(7);
    ui->cusTableWidget->setRowCount(1+tIdList.size());

    QTableWidgetItem *tCusIdUnitItem = new QTableWidgetItem("ID");
    ui->cusTableWidget->setItem(0,0,tCusIdUnitItem);
    QTableWidgetItem *tCusVehUnitItem = new QTableWidgetItem("Assigned Vehicle");
    ui->cusTableWidget->setItem(0,1,tCusVehUnitItem);
    QTableWidgetItem *tCusDemandUnitItem = new QTableWidgetItem("Demand");
    ui->cusTableWidget->setItem(0,2,tCusDemandUnitItem);
    QTableWidgetItem *tCusPULocUnitItem = new QTableWidgetItem("Pick-up");
    ui->cusTableWidget->setItem(0,3,tCusPULocUnitItem);
    QTableWidgetItem *tCusDLocUnitItem = new QTableWidgetItem("Delivery");
    ui->cusTableWidget->setItem(0,4,tCusDLocUnitItem);
    QTableWidgetItem *tCusRTimeUnitItem = new QTableWidgetItem("Request Time");
    ui->cusTableWidget->setItem(0,5,tCusRTimeUnitItem);
    QTableWidgetItem *tCusWTimeUnitItem = new QTableWidgetItem("Wait Time");
    ui->cusTableWidget->setItem(0,6,tCusWTimeUnitItem);

    for(int i = 0; i < tIdList.size(); ++i)
    {
        QTableWidgetItem *tCusIdItem = new QTableWidgetItem(QString("%1").arg(tIdList.at(i)));
        ui->cusTableWidget->setItem(1+i,0,tCusIdItem);
        QTableWidgetItem *tCusVehItem = new QTableWidgetItem(QString("%1").arg(mCusRequesteds.value(tIdList.at(i)).value("veh")));
        ui->cusTableWidget->setItem(1+i,1,tCusVehItem);
        QTableWidgetItem *tCusDemandItem = new QTableWidgetItem(QString("%1").arg(mCusRequesteds.value(tIdList.at(i)).value("demand")));
        ui->cusTableWidget->setItem(1+i,2,tCusDemandItem);
        QTableWidgetItem *tCusPULocItem = new QTableWidgetItem(QString("%1").arg(mCusRequesteds.value(tIdList.at(i)).value("ploc")));
        ui->cusTableWidget->setItem(1+i,3,tCusPULocItem);
        QTableWidgetItem *tCusDLocItem = new QTableWidgetItem(QString("%1").arg(mCusRequesteds.value(tIdList.at(i)).value("dloc")));
        ui->cusTableWidget->setItem(1+i,4,tCusDLocItem);
        QTableWidgetItem *tCusRTimeItem = new QTableWidgetItem(QString("%1").arg(mCusRequesteds.value(tIdList.at(i)).value("reqtime")));
        ui->cusTableWidget->setItem(1+i,5,tCusRTimeItem);
        QTableWidgetItem *tCusWTimeItem = new QTableWidgetItem(QString("%1").arg(mCusRequesteds.value(tIdList.at(i)).value("wtime")));
        ui->cusTableWidget->setItem(1+i,6,tCusWTimeItem);
    }
}

void PrimeUI::CusRefreshLocationComboList()
{
    if(true/*ui->cusPULocCoBox->isEnabled() && ui->cusDLocCoBox->isEnabled()*/)
    {
//        qDebug()<<"PULoc/DLoc activated";

        ui->cusPULocCoBox->clear();
        ui->cusDLocCoBox->clear();
        for(int i = 0; i < mLocRegistereds.keys().size(); ++i)
        {
            qint64 tLocId = mLocRegistereds.keys().at(i);
            ui->cusPULocCoBox->addItem(QString("%1").arg(tLocId));
            ui->cusDLocCoBox->addItem(QString("%1").arg(tLocId));
        }
    }
}

void PrimeUI::CusRefreshRSTimeComboList()
{
    PULocSelected=false;
    ui->cusRSTimeCoBox->clear();
    for(int i = 0; i < mCusRSTimes.size(); ++i)
    {
        qint64 tRSTime = mCusRSTimes.at(i);
        qint64 tMins = tRSTime/60;
        ui->cusRSTimeCoBox->addItem(QString("%1").arg(tMins));
    }
}

void PrimeUI::CusRefreshWTimeComboList()
{
    ui->cusWTimeCoBox->clear();
    for(int i = 0; i < mCusWTimes.size(); ++i)
    {
        qint64 tWTime = mCusWTimes.at(i);
        qint64 tMins = tWTime/60;
        ui->cusWTimeCoBox->addItem(QString("%1").arg(tMins));
    }
}

void PrimeUI::CusRequestByUI(qint64 aCusId, QHash<QString, qint64> aCusHash)
{
    if(!mCusRequesteds.contains(aCusId))
    {
        qint64 tDemand = aCusHash.value("demand");
        qint64 tPULoc = aCusHash.value("ploc");
        qint64 tDLoc = aCusHash.value("dloc");
        qint64 tReqTime = aCusHash.value("reqtime");
        qint64 tWTime = aCusHash.value("wtime");
        if(mpDb->CusRequest(aCusId,tDemand,tPULoc,tDLoc,tReqTime,tWTime))
        {
//            if(!mCusRequestings.contains(aCusId))
//            {
//                mCusRequestings.insert(aCusId,aCusHash);
//            }else
//            {
//                mCusRequestings[aCusId] = aCusHash;
//            }
        }else
        {
            QMessageBox::warning(this,QString("Customer %1 Request").arg(aCusId),"Failed!",QMessageBox::Ok);
        }
    }else
    {
        QMessageBox::warning(this,QString("Customer %1 Request").arg(aCusId),"This ID already requested",QMessageBox::Ok);
    }
}

void PrimeUI::CusDerequestByUI(qint64 aCusId)
{
    if(mCusRequesteds.contains(aCusId))
    {
        if(mpDb->CusDerequest(aCusId))
        {
            //do nothing
        }else
        {
            QMessageBox::warning(this,QString("Customer %1 Cancel Request").arg(aCusId),"Failed!",QMessageBox::Ok);
        }
    }else
    {
        QMessageBox::warning(this,QString("Customer %1 Cancel Request").arg(aCusId),"No Request From Such Customer ID",QMessageBox::Ok);
    }
}

void PrimeUI::CusChgRequestByUI(qint64 aCusId, QHash<QString, qint64> aCusHash)
{
    if(mCusRequesteds.contains(aCusId))
    {
        qint64 tDemand = aCusHash.value("demand");
        qint64 tPULoc = aCusHash.value("ploc");
        qint64 tDLoc = aCusHash.value("dloc");
        qint64 tReqTime = aCusHash.value("reqtime");
        qint64 tWTime = aCusHash.value("wtime");
        if(mpDb->CusChgReq(aCusId,tDemand,tPULoc,tDLoc,tReqTime,tWTime))
        {
//            if(!mCusChgRequestings.contains(aCusId))
//            {
//                mCusChgRequestings.insert(aCusId,aCusHash);
//            }else
//            {
//                mCusChgRequestings[aCusId] = aCusHash;
//            }
        }else
        {
            QMessageBox::warning(this,QString("Customer %1 Change Request").arg(aCusId),"Failed!",QMessageBox::Ok);
        }
    }else
    {
        QMessageBox::warning(this,QString("Customer %1 Change Request").arg(aCusId),"No Request From Such Customer ID",QMessageBox::Ok);
    }
}

void PrimeUI::CusRequestToView(qint64 aCusId)
{
    QPair<qint64,qint64> tPair(mCusRequesteds.value(aCusId).value("ploc"),mCusRequesteds.value(aCusId).value("dloc"));
    mpMapView->RegisterRequestInView(aCusId,mCusRequesteds.value(aCusId).value("demand"),tPair/*mCusPUDLocs.value(aCusId)*/);
}

void PrimeUI::CusDerequestToView(qint64 aCusId)
{
    mpMapView->DeregisterRequestInView(aCusId);
}

void PrimeUI::CusChgRequestToView(qint64 aCusId)
{
    QPair<qint64,qint64> tPair(mCusRequesteds.value(aCusId).value("ploc"),mCusRequesteds.value(aCusId).value("dloc"));
    mpMapView->ApplyChgReqInView(aCusId,mCusRequesteds.value(aCusId).value("demand"),tPair/*mCusPUDLocs.value(aCusId)*/);
}

void PrimeUI::CusResetInterface()
{
    mpMapView->clearFocus();
    cusCellSelected=false;
    deleteCrossHairInView();
    mCusClickedId=0;
    mCusMode="";
    ui->cusTableWidget->clearSelection();
    ui->cusTableWidget->setEnabled(true);
    ui->cusReqBtn->setEnabled(true);
    ui->cusCancelReqBtn->setEnabled(false);
    ui->cusChgReqBtn->setEnabled(false);
    ui->cusIdEdit->clear();
    ui->cusIdEdit->setEnabled(false);
    ui->cusDemandsChBox->setChecked(false);
    ui->cusDemandsChBox->setEnabled(false);
    ui->cusDemandsSpBox->setValue(0);
    ui->cusDemandsSpBox->setEnabled(false);
    ui->cusPULocChBox->setChecked(false);
    ui->cusPULocChBox->setEnabled(false);
    ui->cusPULocCoBox->clear();
    ui->cusPULocCoBox->setEnabled(false);
    ui->cusDLocChBox->setChecked(false);
    ui->cusDLocChBox->setEnabled(false);
    ui->cusDLocCoBox->clear();
    ui->cusDLocCoBox->setEnabled(false);
    ui->cusRSTimeChBox->setChecked(false);
    ui->cusRSTimeChBox->setEnabled(false);
    ui->cusRSTimeCoBox->clear();
    ui->cusRSTimeCoBox->setEnabled(false);
    ui->cusRSTimeMinLabel->setEnabled(false);
    ui->cusWTimeChBox->setChecked(false);
    ui->cusWTimeChBox->setEnabled(false);
    ui->cusWTimeCoBox->clear();
    ui->cusWTimeCoBox->setEnabled(false);
    ui->cusWTimeMinLabel->setEnabled(false);
    ui->cusConfirmBtn->setEnabled(false);
    ui->cusConfirmBtn->setText("Confirm");
    ui->cusCancelBtn->setEnabled(false);

}

//Evt Manager:
void PrimeUI::refreshEvtVehTableWidget()
{
    //vehid jobs cost in/out
    ui->evtVehTableWidget->clear();

    ui->evtVehTableWidget->setColumnCount(4);
    ui->evtVehTableWidget->setRowCount(mVehPrptyRegistereds.keys().size()+1);

    QTableWidgetItem* tVehIdUnitItem = new QTableWidgetItem("ID");
    ui->evtVehTableWidget->setItem(0,0,tVehIdUnitItem);
    QTableWidgetItem* tVehJobsUnitItem = new QTableWidgetItem("Jobs");
    ui->evtVehTableWidget->setItem(0,1,tVehJobsUnitItem);
    QTableWidgetItem* tVehCostUnitItem = new QTableWidgetItem("Cost");
    ui->evtVehTableWidget->setItem(0,2,tVehCostUnitItem);
    QTableWidgetItem* tVehInDepotUnitItem = new QTableWidgetItem("In Depot");
    ui->evtVehTableWidget->setItem(0,3,tVehInDepotUnitItem);

    QList<qint64> tIdList = mVehPrptyRegistereds.keys();
    for(int i = 0; i < tIdList.size(); ++i)
    {
        QTableWidgetItem* tVehIdItem =
                new QTableWidgetItem(QString("%1").arg(tIdList.at(i)));
        ui->evtVehTableWidget->setItem(i+1,0,tVehIdItem);
        QTableWidgetItem* tVehJobsItem =
                new QTableWidgetItem(QString("%1").arg(mVehJobsHash.value(tIdList.at(i)).size()));
        ui->evtVehTableWidget->setItem(i+1,1,tVehJobsItem);
        QTableWidgetItem* tVehCostItem =
                new QTableWidgetItem(mVehPrptyRegistereds.value(tIdList.at(i)).value("cost"));
        ui->evtVehTableWidget->setItem(i+1,2,tVehCostItem);
        QTableWidgetItem* tVehInDepotItem =
                new QTableWidgetItem(mVehPrptyRegistereds.value(tIdList.at(i)).value("indepot")/* == "1" ? "yes" : "no"*/);
        ui->evtVehTableWidget->setItem(i+1,3,tVehInDepotItem);
    }
}

void PrimeUI::refreshEvtJobsTableWidget()
{
    if(mEvtVehClickedId==0)
    {
        ui->evtJobsTableWidget->clear();
    }else
    {
        //loc opentime closetime demand cusid
        //exclude of loc<0/cusid=0//no need to consider//won't add into the joblist
        ui->evtJobsTableWidget->clear();

        QList<QHash<QString,qint64>> tJobList = mVehJobsHash.value(mEvtVehClickedId);

        ui->evtJobsTableWidget->setColumnCount(5);
        ui->evtJobsTableWidget->setRowCount(1+tJobList.size());

        QTableWidgetItem *tLocUnitItem = new QTableWidgetItem("Location");
        ui->evtJobsTableWidget->setItem(0,0,tLocUnitItem);
        QTableWidgetItem *tOpenTimeUnitItem = new QTableWidgetItem("Open Time");
        ui->evtJobsTableWidget->setItem(0,1,tOpenTimeUnitItem);
        QTableWidgetItem *tCloseTimeUnitItem = new QTableWidgetItem("Close Time");
        ui->evtJobsTableWidget->setItem(0,2,tCloseTimeUnitItem);
        QTableWidgetItem *tDemandUnitItem = new QTableWidgetItem("Demand");
        ui->evtJobsTableWidget->setItem(0,3,tDemandUnitItem);
        QTableWidgetItem *tCusIdUnitItem = new QTableWidgetItem("Customer ID");
        ui->evtJobsTableWidget->setItem(0,4,tCusIdUnitItem);

        for(int i = 0; i < tJobList.size(); ++i)
        {
            QTableWidgetItem *tLocItem = new QTableWidgetItem(QString("%1").arg(tJobList.at(i).value("loc")));
            ui->evtJobsTableWidget->setItem(i+1,0,tLocItem);
            QTableWidgetItem *tOpenTimeItem = new QTableWidgetItem(QString("%1").arg(tJobList.at(i).value("opentime")));
            ui->evtJobsTableWidget->setItem(i+1,1,tOpenTimeItem);
            QTableWidgetItem *tCloseTimeItem = new QTableWidgetItem(QString("%1").arg(tJobList.at(i).value("closetime")));
            ui->evtJobsTableWidget->setItem(i+1,2,tCloseTimeItem);
            QTableWidgetItem *tDemandItem = new QTableWidgetItem(QString("%1").arg(tJobList.at(i).value("demand")));
            ui->evtJobsTableWidget->setItem(i+1,3,tDemandItem);
            QTableWidgetItem *tCusIdItem = new QTableWidgetItem(QString("%1").arg(tJobList.at(i).value("cus")));
            ui->evtJobsTableWidget->setItem(i+1,4,tCusIdItem);
        }
    }
}

void PrimeUI::refreshEvtCusAnsTableWidget()
{
    //cusid vehid waittime
    ui->evtCusAnsTableWidget->clear();
    QList<qint64> tIdList = mCusAnsDataHash.keys();

    ui->evtCusAnsTableWidget->setColumnCount(4);
    ui->evtCusAnsTableWidget->setRowCount(1+tIdList.size());

    QTableWidgetItem *tCusIdUnitItem = new QTableWidgetItem("Customer ID");
    ui->evtCusAnsTableWidget->setItem(0,0,tCusIdUnitItem);
    QTableWidgetItem *tVehIdUnitItem = new QTableWidgetItem("Vehicle ID");
    ui->evtCusAnsTableWidget->setItem(0,1,tVehIdUnitItem);
    QTableWidgetItem *tWaitTimeUnitItem = new QTableWidgetItem("Wait Time");
    ui->evtCusAnsTableWidget->setItem(0,2,tWaitTimeUnitItem);
    QTableWidgetItem *tTypeUnitItem = new QTableWidgetItem("Type");
    ui->evtCusAnsTableWidget->setItem(0,3,tTypeUnitItem);

    for(int i = 0; i < tIdList.size(); ++i)
    {
        QTableWidgetItem *tCusIdItem = new QTableWidgetItem(QString("%1").arg(tIdList.at(i)));
        ui->evtCusAnsTableWidget->setItem(i+1,0,tCusIdItem);
        QTableWidgetItem *tVehIdItem = new QTableWidgetItem(QString("%1").arg(mCusAnsDataHash.value(tIdList.at(i)).value("veh")));
        ui->evtCusAnsTableWidget->setItem(i+1,1,tVehIdItem);
        QTableWidgetItem *tWaitTimeItem = new QTableWidgetItem(QString("%1").arg(mCusAnsDataHash.value(tIdList.at(i)).value("waittime")));
        ui->evtCusAnsTableWidget->setItem(i+1,2,tWaitTimeItem);
//        QTableWidgetItem *tTypeItem = new QTableWidgetItem(QString("%1").arg(mCusAnsDataHash.value(tIdList.at(i)).value("type")?"PU":"DL"));
        QTableWidgetItem *tTypeItem;
        if(mCusAnsDataHash.value(tIdList.at(i)).value("type")==1)
            tTypeItem = new QTableWidgetItem(QString("%1").arg("PU"));
        else
            tTypeItem = new QTableWidgetItem(QString("%1").arg("DL"));
        ui->evtCusAnsTableWidget->setItem(i+1,3,tTypeItem);
    }
}

void PrimeUI::refreshEvtLogTableWidget()
{
    //left over
}

void PrimeUI::EvtVehicleArrive(qint64 aVehId, int SizeOfJob,qint64 aCusId, qint64 aDemand)
{
    //send command to db
    if(mpDb->OnArrivalEvent(aVehId,SizeOfJob,aCusId,aDemand))
    {
        //ok
    }else
    {
        QMessageBox::warning(this,QString("Event Vehicle %1 Arrive Customer %2").arg(aVehId).arg(aCusId),"Failed!",QMessageBox::Ok);
    }
}

void PrimeUI::EvtVehicleBackToDepot(qint64 aVehId)
{
    //send command to db
    if(mpDb->BackToDepotEvent(aVehId))
    {
        //ok
    }else
    {
        QMessageBox::warning(this,QString("Event Vehicle %1 Back To Depot").arg(aVehId),"Failed!",QMessageBox::Ok);
    }
}

void PrimeUI::EvtCustomerAnsPickUp(qint64 aVehId, qint64 aCusId, QString aAnsStr)
{
    //send command to db
    if(mpDb->CusAnsPickup(aCusId,aVehId,aAnsStr))
    {
        getReplyForEvtArrSettle(aVehId,aCusId);
    }else
    {
        QMessageBox::warning(this,QString("Event Customer %1 Send Answer Pick-up").arg(aCusId),"Failed!",QMessageBox::Ok);
    }
}

void PrimeUI::EvtCustomerAnsDelivery(qint64 aVehId, qint64 aCusId, QString aAnsStr)
{
    if(mpDb->CusAnsDelivery(aCusId, aVehId, aAnsStr))
    {
        getReplyForEvtArrSettle(aVehId,aCusId);
    }else
    {
        QMessageBox::warning(this,QString("Event Customer %1 Send Answer Delivery").arg(aCusId),"Failed!",QMessageBox::Ok);
    }
}

void PrimeUI::EvtSetCurTimeBySimTime(qint64 aSimTime)
{
    //send command to db
    if(mpDb->SetCurrentTime(aSimTime))
    {
        mpDb->setTimeDiff(aSimTime);
    }else
    {
        QMessageBox::warning(this,QString("Event Set Current Time").arg(aSimTime),"Failed!",QMessageBox::Ok);
    }
}

void PrimeUI::EvtResetCurTime()
{
    //params
    settingCurrentTime=false;
    evtCurTimeMode = 0;
    //ui
    ui->evtSetCurTimeBtn->setEnabled(true);
    ui->evtResetTimeBtn->setEnabled(false);
    ui->evtHourSpBox->setEnabled(false);
    ui->evtMinuteSpBox->setEnabled(false);
    ui->evtSecondSpBox->setEnabled(false);
    ui->evtSimTimeSpBox->setEnabled(false);
    //data
    QList<QString> tRealTimeStringList = mpDb->getRealTime().split(":");
    int hour = tRealTimeStringList.at(0).toInt();
    int min = tRealTimeStringList.at(1).toInt();
    int sec = tRealTimeStringList.at(2).toInt();
    ui->evtHourSpBox->setValue(hour);
    ui->evtMinuteSpBox->setValue(min);
    ui->evtSecondSpBox->setValue(sec);
    ui->evtSimTimeSpBox->setValue(mpDb->getSimTime());

    ui->evtConfirmCurTimeBtn->setEnabled(false);
}

void PrimeUI::EvtResetInterface()
{
    mpMapView->clearFocus();

    evtVehCellSelected=false;
    evtJobCellSelected=false;
    evtCusCellSelected=false;

    mEvtVehClickedId = 0;
    mEvtJobClickedHash.clear();
    mEvtCusClickedId= 0;
    ui->evtVehTableWidget->clearSelection();
    ui->evtVehArrBtn->setEnabled(false);
    ui->evtVehBTDBtn->setEnabled(false);
    ui->evtCusAnsTableWidget->clearSelection();
    ui->evtLogTableWidget->clearSelection();
    EvtResetCurTime();
}
