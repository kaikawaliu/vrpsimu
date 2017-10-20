#include "primeui.h"
#include "ui_primeui.h"

//====================================================
//Public Slot Funcs:
//Generic
void PrimeUI::ViewGetPressScenePos(QPointF aScenePos)
{

}

void PrimeUI::ViewGetHoverScenePos(QPair<qint64,qint64> aPos,QPair<double,double> aCoord)
{
    ui->posDataLabel->setText(QString("(%1,%2)").arg(aPos.first).arg(aPos.second));
    ui->coordDataLabel->setText(QString("(%1,%2)").arg(QString::number(aCoord.first,'g',10)).arg(QString::number(aCoord.second,'g',10)));
}

void PrimeUI::ViewGetHoverLeaveEvent()
{
    ui->posDataLabel->setText("(,)");
    ui->coordDataLabel->setText("(,)");
}

void PrimeUI::GetLoseSelection()
{
    ui->monListWidget->clearSelection();
    ui->MonTableWidget->clearSelection();
    ui->locTableWidget->clearSelection();
    ui->vehTableWidget->clearSelection();
    ui->cusTableWidget->clearSelection();
    ui->evtVehTableWidget->clearSelection();
}

//Monitoring
void PrimeUI::MonViewUpdateUI(QString aItemStr, QList<qint64> aIdList)
{

}

void PrimeUI::getPressInMonMode(QString aItemStr, QList<qint64> aIdList)
{
    if(ui->primaryStackedWidget->currentIndex()==0)
    {
        QList<QListWidgetItem*> tList = ui->monListWidget->findItems(QString("%1").arg(aIdList.first()),Qt::MatchExactly);
        if(tList.size()>0)
        {
            ui->monListWidget->setCurrentItem(tList.first());
            emit ui->monListWidget->currentRowChanged(ui->monListWidget->currentRow());
        }
    }
}

//Loc Manager
void PrimeUI::LocViewUpdateUI(QHash<qint64, QPair<double, double> > aLocIdCoordHash)
{

}

void PrimeUI::UIGetRepForLocOp(QString aType, qint64 aLocId, QString aResult)
{

}

void PrimeUI::UIGetLocLLFromView(QPair<double, double> aCoord)
{
    if(ui->primaryStackedWidget->currentIndex()==1)
    {
        ui->locLatEdit->setText(QString::number(aCoord.first,'g',10));
        ui->locLongEdit->setText(QString::number(aCoord.second,'g',10));
        mCrossHairCoord = aCoord;
    }
}

void PrimeUI::getPressInLocMode(QHash<qint64, QPair<double, double> > aSelectedLocCoordHash)
{
    if(ui->primaryStackedWidget->currentIndex()==1)
    {
//        qDebug()<<"get press in loc mode";
//        ui->monListWidget->setCurrentItem(ui->monListWidget->findItems(QString("%1").arg(aIdList.first()),Qt::MatchExactly).first());
//        emit ui->monListWidget->currentRowChanged(ui->monListWidget->currentRow());
        QList<QTableWidgetItem*> tTableWidgetItems =
                ui->locTableWidget->findItems(
                    QString("%1").arg(aSelectedLocCoordHash.keys().first()),Qt::MatchExactly);
        for(int i = 0; i < tTableWidgetItems.size(); ++i)
        {
            if(tTableWidgetItems.at(i)->column()==0)
            {
//                ui->locTableWidget->selectRow(tTableWidgetItems.at(i)->row());
                ui->locTableWidget->setCurrentCell(tTableWidgetItems.at(i)->row(),0);
                emit ui->locTableWidget->cellClicked(tTableWidgetItems.at(i)->row(),0);
            }
        }
    }
}

//Veh Manager
void PrimeUI::VehViewUpdateUI(QHash<qint64, QPair<double, double> > aVehIdCoordHash)
{

}

void PrimeUI::UIGetRepForVehOp(QString aType, qint64 aVehId, QString aResult)
{

}

void PrimeUI::UIGetVehLLFromView(QPair<double, double> aCoord)
{
    if(ui->primaryStackedWidget->currentIndex()==2)
    {
        ui->vehLatEdit->setText(QString::number(aCoord.first,'g',10));
        ui->vehLongEdit->setText(QString::number(aCoord.second,'g',10));
        mCrossHairCoord = aCoord;
    }
}

void PrimeUI::UIGetCmdForVehCoordUpd(qint64 aVehId, QPair<double, double> aVehCoord)
{

}

void PrimeUI::UIGetCmdForVehJobsUpd(qint64 aVehId, QHash<QString, qint64> aVehJobs)
{

}

void PrimeUI::getPressInVehMode(QHash<qint64, QPair<double, double> > aSelectedVehCoordHash)
{
    if(ui->primaryStackedWidget->currentIndex()==2)
    {
//        qDebug()<<"get press in veh mode";
        QList<QTableWidgetItem*> tTableWidgetItems =
                ui->vehTableWidget->findItems(
                    QString("%1").arg(aSelectedVehCoordHash.keys().first()),Qt::MatchExactly);
        for(int i = 0; i < tTableWidgetItems.size(); ++i)
        {
            if(tTableWidgetItems.at(i)->column()==0)
            {
//                ui->vehTableWidget->selectRow(tTableWidgetItems.at(i)->row());
                ui->vehTableWidget->setCurrentCell(tTableWidgetItems.at(i)->row(),0);

                emit ui->vehTableWidget->cellClicked(tTableWidgetItems.at(i)->row(),0);
            }
        }
    }
}

void PrimeUI::getReplyForRegisterVehPrpty(qint64 aVehId,bool result)
{
    if(result)
    {
        if(!mVehPrptyRegistereds.contains(aVehId))
        {
//            mVehPrptyRegistereds.insert(aVehId,mVehPrptyRegisterings.value(aVehId));
//            QList<QHash<QString,qint64>> tJobList;
//            mVehJobsHash.insert(aVehId,tJobList)
        }else
        {
//            mVehPrptyRegistereds[aVehId]=mVehPrptyRegisterings.value(aVehId);
        }
//        mVehPrptyRegisterings.remove(aVehId);
        QMessageBox::information(this,QString("Register Vehicle %1").arg(aVehId),"Succeed!",QMessageBox::Ok);
    }
    else
    {
        QMessageBox::information(this,QString("Register Vehicle %1").arg(aVehId),"Failed.",QMessageBox::Ok);
    }
}

void PrimeUI::getReplyForDeregisterVehPrpty(qint64 aVehId,bool result)
{
    if(result)
    {
        if(mVehPrptyRegistereds.contains(aVehId))
        {
//            mVehPrptyRegistereds.remove(aVehId);
//            mVehJobsHash.remove(aVehId)
        }
        QMessageBox::information(this,QString("Deregister Vehicle %1").arg(aVehId),"Succeed!",QMessageBox::Ok);
    }else
    {
        QMessageBox::information(this,QString("Deregister Vehicle %1").arg(aVehId),"Failed.",QMessageBox::Ok);
    }
}

void PrimeUI::getReplyForUpdateVehPrpty(qint64 aVehId, QString aType, bool result)
{
    if(result)
    {
        if(mVehPrptyRegistereds.contains(aVehId))
        {
//            mVehPrptyRegistereds[aVehId][aType] = mVehPrptyUpdatings[aVehId][aType];
        }
        QMessageBox::information(this,QString("Update Vehicle %1 %2").arg(aVehId).arg(aType),"Succeed!",QMessageBox::Ok);
    }else
    {
        QMessageBox::information(this,QString("Update Vehicle %2 %2").arg(aVehId).arg(aType),"Failed.",QMessageBox::Ok);
    }
}

//Cus Manager
void PrimeUI::CusViewUpdUI(QHash<qint64, bool> aCusIdPUHash)
{

}

void PrimeUI::CusViewUpdUIForLoc(QList<qint64> aCusLocIdList)
{

}

void PrimeUI::getPressInCusModeForLoc(QList<qint64> aSelectedLocList)
{
    if(mCusMode=="req"||mCusMode=="chgreq")
    {
        if(ui->cusPULocChBox->isChecked() && !ui->cusDLocChBox->isChecked())
        {
            QString tText = QString("%1").arg(aSelectedLocList.first());
            int tIndex = ui->cusPULocCoBox->findText(tText);
            ui->cusPULocCoBox->setCurrentIndex(tIndex);
        }else if(!ui->cusPULocChBox->isChecked() && ui->cusDLocChBox->isChecked())
        {
            QString tText = QString("%1").arg(aSelectedLocList.first());
            int tIndex = ui->cusDLocCoBox->findText(tText);
            ui->cusDLocCoBox->setCurrentIndex(tIndex);
        }else if(ui->cusPULocChBox->isChecked() && ui->cusDLocChBox->isChecked())
        {
            if(!PULocSelected)
            {
                QString tText = QString("%1").arg(aSelectedLocList.first());
                int tIndex = ui->cusPULocCoBox->findText(tText);
                ui->cusPULocCoBox->setCurrentIndex(tIndex);
                PULocSelected=true;
            }else
            {
                QString tText = QString("%1").arg(aSelectedLocList.first());
                int tIndex = ui->cusDLocCoBox->findText(tText);
                ui->cusDLocCoBox->setCurrentIndex(tIndex);
                PULocSelected=false;
            }
        }
    }
}

void PrimeUI::getPressInCusModeForReq(QHash<qint64, bool> aSelectedCusIdPUHash)
{
    if(ui->primaryStackedWidget->currentIndex()==3)
    {
        QList<QTableWidgetItem*> tTableWidgetItems =
                ui->cusTableWidget->findItems(QString("%1").arg(aSelectedCusIdPUHash.keys().first()),Qt::MatchExactly);
        for(int i = 0; i < tTableWidgetItems.size(); ++i)
        {
            if(tTableWidgetItems.at(i)->column()==0)
            {
//                ui->cusTableWidget->selectRow(tTableWidgetItems.at(i)->row());
                ui->cusTableWidget->setCurrentCell(tTableWidgetItems.at(i)->row(),0);

                emit ui->cusTableWidget->cellClicked(tTableWidgetItems.at(i)->row(),0);
            }
        }
    }
}

void PrimeUI::getReplyForCusRequest(qint64 aCusId, bool result)
{
    if(result)
    {
        if(!mCusRequesteds.contains(aCusId))
        {
//            mCusRequesteds.insert(aCusId,mCusRequestings.value(aCusId));
        }else
        {
//            mCusRequesteds[aCusId]=mCusRequestings.value(aCusId);
        }
//        mCusRequestings.remove(aCusId);
        QMessageBox::information(this,QString("Customer %1 Request").arg(aCusId),"Succeed!",QMessageBox::Ok);
    }else
    {
        QMessageBox::information(this,QString("Customer %1 Request").arg(aCusId),"Failed.",QMessageBox::Ok);
    }
}

void PrimeUI::getReplyForCusCancelRequest(qint64 aCusId, bool result)
{
    if(result)
    {
        if(mCusRequesteds.contains(aCusId))
        {
//            mCusRequesteds.remove(aCusId);
        }
        QMessageBox::information(this,QString("Customer %1 Cancel Request").arg(aCusId),"Succeed!",QMessageBox::Ok);
    }else
    {
        QMessageBox::information(this,QString("Customer %1 Cancel Request").arg(aCusId),"Failed.",QMessageBox::Ok);
    }
}

void PrimeUI::getReplyForCusChangeRequest(qint64 aCusId, bool result)
{
    if(result)
    {
        if(mCusRequesteds.contains(aCusId))
        {
//            mCusRequesteds.insert(aCusId,mCusRequestings.value(aCusId));
        }
        QMessageBox::information(this,QString("Customer %1 Change Request").arg(aCusId),"Succeed!",QMessageBox::Ok);
    }else
    {
        QMessageBox::information(this,QString("Customer %1 Change Request").arg(aCusId),"Failed.",QMessageBox::Ok);
    }
}

//Evt Manager
void PrimeUI::EvtViewUpdUI(QList<qint64> aVehIdList)
{

}

void PrimeUI::getPressInEvtMode(QList<qint64> aSelectedVehIdList)
{
    if(ui->primaryStackedWidget->currentIndex()==4)
    {
//        qDebug()<<"get pressed in evt mode";
        QList<QTableWidgetItem*> tTableWidgetItems =
                ui->evtVehTableWidget->findItems(
                    QString("%1").arg(aSelectedVehIdList.first()),Qt::MatchExactly);
        for(int i = 0; i < tTableWidgetItems.size(); ++i)
        {
            if(tTableWidgetItems.at(i)->column()==0)
            {
//                ui->evtVehTableWidget->selectRow(tTableWidgetItems.at(i)->row());
                ui->evtVehTableWidget->setCurrentCell(tTableWidgetItems.at(i)->row(),0);
                emit ui->vehTableWidget->itemSelectionChanged();
            }
        }
    }
}

void PrimeUI::getReplyForEvtVehArr(qint64 aVehId, qint64 aCusId, qint64 aWaitTime)
{
    //two types of arrival: pick-up and delivery
    //this waittime is mainly to inform the vehicle
    //should report the waiting time to fms.....
    //.....which is what the simevtreply db table used for
    //should display it on UI?
    //No...
    //Remove Job:
//    bool isPickedUp=true;
//    int iterP,iterD;
//    for(int i = 0; i < mVehJobsHash[aVehId].size(); ++i)
//    {
//        if(mVehJobsHash[aVehId].at(i).value("cus")==aCusId)
//        {
//            if(mVehJobsHash[aVehId].at(i).value("demand")>=0)
//            {
//                isPickedUp=false;
//                iterP=i;
//            }else
//            {
//                iterD=i;
//            }
//        }
//    }
//    if(isPickedUp==false)
//    {
//        mVehJobsHash[aVehId].removeAt(iterP);
//    }else
//    {
//        mVehJobsHash[aVehId].removeAt(iterD);

//        //report a finishing of job to View
//        mpMapView->DeregisterRequestInView(aCusId);
//    }
//    mpMapView->ApplyArrivalInView(aVehId);
}

void PrimeUI::getReplyForEvtBackDepot(qint64 aVehId, QString aResult)
{
    //change the data in veh status hash
    //result: "good"/"bad"
    if(aResult=="good")
    {
        mVehPrptyRegistereds[aVehId]["indepot"]="1";
        mVehPrptyRegistereds[aVehId]["cost"]="0";
        mVehJobsHash.remove(aVehId);
    }else
    {
        QMessageBox::warning(this,"Reply For Event Back To Depot",QString("Vehicle:%1 Failed.").arg(aVehId),QMessageBox::Ok);
    }
}

void PrimeUI::getReplyForEvtTriggerPUNotice(qint64 aVehId, qint64 aCusId, qint64 aWaitTime)
{
    //Add the CusAnsPU request
    QHash<QString,qint64> tHash;
    tHash.insert("veh",aVehId);
    tHash.insert("waittime",aWaitTime);
    tHash.insert("type",1);
    if(!mCusAnsDataHash.contains(aCusId))
    {
        mCusAnsDataHash.insert(aCusId,tHash);
    }
    refreshEvtCusAnsTableWidget();
}

void PrimeUI::getReplyForEvtTriggerDLNotice(qint64 aVehId, qint64 aCusId, qint64 aWaitTime)
{
    QHash<QString,qint64> tHash;
    tHash.insert("veh",aVehId);
    tHash.insert("waittime",aWaitTime);
    tHash.insert("type",0);
    if(!mCusAnsDataHash.contains(aCusId))
    {
        mCusAnsDataHash.insert(aCusId,tHash);
    }
    refreshEvtCusAnsTableWidget();
}

void PrimeUI::getReplyForEvtCusAnsPUExpire(qint64 aVehId, qint64 aCusId)
{
    //equal to trigger refuse
    EvtCustomerAnsPickUp(aVehId,aCusId,"no");
}

void PrimeUI::getReplyForEvtCusAnsDLExpire(qint64 aVehId, qint64 aCusId)
{
    EvtCustomerAnsDelivery(aVehId,aCusId,"yes");
}

void PrimeUI::getReplyForEvtArrSettle(qint64 aVehId, qint64 aCusId)
{
    //clear up the CusAns Table Widget
    if(mCusAnsDataHash.contains(aCusId))
    {
        mCusAnsDataHash.remove(aCusId);
    }
    refreshEvtCusAnsTableWidget();
}

//Informed From VRPMaster
//LocCoord
void PrimeUI::InformedAddLocCoord(qint64 aLocId, double aLat, double aLong)
{
    QPair<double,double> tLocCoord(aLat,aLong);
    LocRegisterToView(aLocId,tLocCoord);
    if(!mLocRegistereds.contains(aLocId))
    {
        mLocRegistereds.insert(aLocId,tLocCoord);
//        refreshRelatedWidgets("locA&D",aLocId);

        int tCurrentIndex = ui->primaryStackedWidget->currentIndex();
        if(tCurrentIndex==0)
        {
            if(mMonPage==0)
            {
                ui->monListWidget->addItem(QString("%1").arg(aLocId));
            }
        }else if(tCurrentIndex==1)
        {
            int rowcount = ui->locTableWidget->rowCount();
            ui->locTableWidget->setRowCount(rowcount+1);
            QTableWidgetItem *tLocIdItem = new QTableWidgetItem(QString("%1").arg(aLocId));
            ui->locTableWidget->setItem(rowcount,0,tLocIdItem);
            QTableWidgetItem *tLocLatItem = new QTableWidgetItem(QString::number(aLat,'g',10));
            ui->locTableWidget->setItem(rowcount,1,tLocLatItem);
            QTableWidgetItem *tLocLongItem = new QTableWidgetItem(QString::number(aLong,'g',10));
            ui->locTableWidget->setItem(rowcount,2,tLocLongItem);
        }else if(tCurrentIndex==3)
        {
            if(ui->cusPULocCoBox->isEnabled())
            {
                ui->cusPULocCoBox->addItem(QString("%1").arg(aLocId));
            }
            if(ui->cusDLocCoBox->isEnabled())
            {
                ui->cusDLocCoBox->addItem(QString("%1").arg(aLocId));
            }
        }
    }
}

void PrimeUI::InformedDeleteLocCoord(qint64 aLocId)
{
//    LocDeregisterByUI(aLocId);
    if(mLocRegistereds.contains(aLocId))
    {
        mLocRegistereds.remove(aLocId);
//        refreshRelatedWidget("locA&D",aLocId);

        LocDeregisterToView(aLocId);
        int tCurrentIndex = ui->primaryStackedWidget->currentIndex();
        if(tCurrentIndex==0)
        {
            if(mMonPage==0)
            {
                for(int i = 0 ; i < ui->monListWidget->count(); ++i)
                {
                    if(ui->monListWidget->item(i)->text().toLongLong()==aLocId)
                        ui->monListWidget->removeItemWidget(ui->monListWidget->item(i));
                }

                QList<QString> tLabelStrings = ui->MonTableWidgetLabel->text().split(" ");
                if(tLabelStrings.size()>1)
                {
                    if(tLabelStrings.at(1).toLongLong()==aLocId)
                    {
                        refreshMonTableWidget();
                    }
                }
            }
        }else if(tCurrentIndex==1)
        {
            if(ui->locTableWidget->hasFocus())
            {
                if(ui->locTableWidget->item(ui->locTableWidget->currentRow(),0)->text().toLongLong()==aLocId)
                {
                    int row = ui->locTableWidget->currentRow();
                    ui->locTableWidget->clearSelection();
                    ui->locTableWidget->removeRow(row);
                    emit ui->locTableWidget->itemSelectionChanged();
                }else
                {
                    for(int i = 1; i < ui->locTableWidget->rowCount(); ++i)
                    {
                        if(ui->locTableWidget->item(i,0)->text().toLongLong()==aLocId)
                        {
                            ui->locTableWidget->removeRow(i);
                        }
                    }
                }
            }else
            {
                for(int i = 1; i < ui->locTableWidget->rowCount(); ++i)
                {
                    if(ui->locTableWidget->item(i,0)->text().toLongLong()==aLocId)
                    {
                        ui->locTableWidget->removeRow(i);
                    }
                }
            }
        }else if(tCurrentIndex==3)
        {
            CusRefreshLocationComboList();
        }
    }
}

void PrimeUI::InformedUpdateLocCoord(qint64 aLocId, double aLat, double aLong)
{
    QPair<double,double> tLocCoord(aLat,aLong);
    LocUpdateToView(aLocId,tLocCoord);
    if(mLocRegistereds.contains(aLocId))
    {
        mLocRegistereds[aLocId] = tLocCoord;
    }else
    {
        mLocRegistereds.insert(aLocId,tLocCoord);
    }
//    refreshRelatedWidgets("locU",aLocId);
    int tCurrentIndex = ui->primaryStackedWidget->currentIndex();
    if(tCurrentIndex==0)
    {
        if(mMonPage==0)
        {
            QList<QString> tLabelStrings = ui->MonTableWidgetLabel->text().split(" ");
            if(tLabelStrings.size()>1)
            {
                if(tLabelStrings.at(1).toLongLong()==aLocId)
                {
                    refreshMonTableWidget(aLocId);
                }
            }
        }
    }else if(tCurrentIndex==1)
    {
        for(int i = 1; i < ui->locTableWidget->rowCount(); ++i)
        {
            if(ui->locTableWidget->item(i,0)->text().toLongLong()==aLocId)
            {
                ui->locTableWidget->item(i,1)->setText(QString::number(aLat,'g',10));
                ui->locTableWidget->item(i,2)->setText(QString::number(aLong,'g',10));
            }
        }
    }
}

//VehCoord
void PrimeUI::InformedAddVehCoord(qint64 aVehId, double aLat, double aLong)
{
    QPair<double,double> tVehCoord(aLat,aLong);
    if(!mVehCoordsHash.contains(aVehId))
    {
        mVehCoordsHash.insert(aVehId,tVehCoord);

        VehRegisterToView(aVehId,tVehCoord);
//        refreshRelatedWidgets("vehcoordA&D",aVehId);
    }
}

void PrimeUI::InformedDeleteVehCoord(qint64 aVehId)
{
    if(mVehCoordsHash.contains(aVehId))
    {
        mVehCoordsHash.remove(aVehId);

        if(mpMapView->containsVeh(aVehId))
        {
            VehDeregisterToView(aVehId);
        }

//        refreshRelatedWidgets("vehcoordA&D",aVehId);
    }
}

void PrimeUI::InformedUpdateVehCoord(qint64 aVehId, double aLat, double aLong)
{
    QPair<double,double> tVehCoord(aLat,aLong);
    if(mVehCoordsHash.contains(aVehId))
    {
        mVehCoordsHash[aVehId] = tVehCoord;
        VehCoordUpdateToView(aVehId,tVehCoord);

//        refreshRelatedWidgets("vehcoordU",aVehId);
        int tCurrentIndex = ui->primaryStackedWidget->currentIndex();
        if(tCurrentIndex==0)
        {
            if(mMonPage==1 && mVehOption==0)
            {
                QList<QString> tLabelStrings = ui->MonTableWidgetLabel->text().split(" ");
                if(tLabelStrings.size()>1)
                {
                    if(tLabelStrings.at(1).toLongLong()==aVehId)
                    {
                        refreshMonTableWidget(aVehId);
                    }
                }
            }
        }else if(tCurrentIndex==2)
        {
            for(int i = 1; i < ui->vehTableWidget->rowCount(); ++i)
            {
                if(ui->vehTableWidget->item(i,0)->text().toLongLong()==aVehId)
                {
                    ui->vehTableWidget->item(i,1)->setText(QString::number(aLat,'g',10));
                    ui->vehTableWidget->item(i,2)->setText(QString::number(aLong,'g',10));
                }
            }
        }
    }
}

//Veh
void PrimeUI::informedRegisterVeh(qint64 aVehId,
                                  qint64 aCapacity,
                                  double aSpeed,
                                  qint64 aRefuelTime,
                                  qint64 aFixTime,
                                  qint64 aUnitTime,
                                  qint64 aBufferTime,
                                  qint64 aLaunchCost,
                                  qint64 aCost,
                                  int aInDepot)
{
    if(!mVehPrptyRegistereds.contains(aVehId))
    {
        QHash<QString,QString> tVehPrpty;
        tVehPrpty.insert("capacity",QString("%1").arg(aCapacity));
        tVehPrpty.insert("speed",QString("%1").arg(aSpeed));
        tVehPrpty.insert("refueltime",QString("%1").arg(aRefuelTime));
        tVehPrpty.insert("fixtime",QString("%1").arg(aFixTime));
        tVehPrpty.insert("unittime",QString("%1").arg(aUnitTime));
        tVehPrpty.insert("buffertime",QString("%1").arg(aBufferTime));
        tVehPrpty.insert("launchcost",QString("%1").arg(aLaunchCost));
        tVehPrpty.insert("cost",QString("%1").arg(aCost));
        tVehPrpty.insert("indepot",QString("%1").arg(aInDepot));
        mVehPrptyRegistereds.insert(aVehId,tVehPrpty);

//        refreshRelatedWidgets("vehprptyA&D",aVehId);
        int tCurrentIndex = ui->primaryStackedWidget->currentIndex();
        if(tCurrentIndex==0)
        {
            if(mMonPage==1)
            {
                ui->monListWidget->addItem(QString("%1").arg(aVehId));
            }
        }else if(tCurrentIndex==2)
        {
            int rowcount = ui->vehTableWidget->rowCount();
            ui->vehTableWidget->setRowCount(rowcount+1);
            QTableWidgetItem *tVehIdItem = new QTableWidgetItem(QString("%1").arg(aVehId));
            ui->vehTableWidget->setItem(rowcount,0,tVehIdItem);
            if(mVehCoordsHash.contains(aVehId))
            {
                QPair<double,double> tCoord = mVehCoordsHash.value(aVehId);
                QTableWidgetItem *tVehLatItem = new QTableWidgetItem(QString::number(tCoord.first,'g',10));
                ui->vehTableWidget->setItem(rowcount,1,tVehLatItem);
                QTableWidgetItem *tVehLongItem = new QTableWidgetItem(QString::number(tCoord.second,'g',10));
                ui->vehTableWidget->setItem(rowcount,2,tVehLongItem);
            }
            QTableWidgetItem *tSpeedItem = new QTableWidgetItem(QString("%1").arg(aSpeed));
            ui->vehTableWidget->setItem(rowcount,3,tSpeedItem);
            QTableWidgetItem *tCapacityItem = new QTableWidgetItem(QString("%1").arg(aCapacity));
            ui->vehTableWidget->setItem(rowcount,4,tCapacityItem);
            QTableWidgetItem *tLaunchCostItem = new QTableWidgetItem(QString("%1").arg(aLaunchCost));
            ui->vehTableWidget->setItem(rowcount,5,tLaunchCostItem);
            QTableWidgetItem *tFixTimeItem = new QTableWidgetItem(QString("%1").arg(aFixTime));
            ui->vehTableWidget->setItem(rowcount,6,tFixTimeItem);
            QTableWidgetItem *tUnitTimeItem = new QTableWidgetItem(QString("%1").arg(aUnitTime));
            ui->vehTableWidget->setItem(rowcount,7,tUnitTimeItem);
            QTableWidgetItem *tRefuelTimeItem = new QTableWidgetItem(QString("%1").arg(aRefuelTime));
            ui->vehTableWidget->setItem(rowcount,8,tRefuelTimeItem);
            QTableWidgetItem *tBufferTimeItem = new QTableWidgetItem(QString("%1").arg(aBufferTime));
            ui->vehTableWidget->setItem(rowcount,9,tBufferTimeItem);
        }else if(tCurrentIndex==4)
        {
            int rowcount = ui->evtVehTableWidget->rowCount();
            ui->evtVehTableWidget->setColumnCount(rowcount+1);
            QTableWidgetItem *tVehIdItem = new QTableWidgetItem(QString("%1").arg(aVehId));
            ui->evtVehTableWidget->setItem(rowcount,0,tVehIdItem);
            if(mVehJobsHash.contains(aVehId))
            {
                QTableWidgetItem *tVehJobsItem = new QTableWidgetItem(QString("%1").arg(mVehJobsHash.value(aVehId).size()));
                ui->evtVehTableWidget->setItem(rowcount,1,tVehJobsItem);
            }
            QTableWidgetItem *tVehCostItem = new QTableWidgetItem(QString("%1").arg(aCost));
            ui->evtVehTableWidget->setItem(rowcount,2,tVehCostItem);
            QTableWidgetItem *tVehInDepotItem = new QTableWidgetItem(QString("%1").arg(aInDepot));
            ui->evtVehTableWidget->setItem(rowcount,3,tVehInDepotItem);
        }
    }
}

void PrimeUI::informedDeregisterVeh(qint64 aVehId)
{
    if(mVehPrptyRegistereds.contains(aVehId))
    {
        mVehPrptyRegistereds.remove(aVehId);
//        refreshRelatedWidgets("vehprptyA&D",aVehId);
        int tCurrentIndex = ui->primaryStackedWidget->currentIndex();
        if(tCurrentIndex==0)
        {
            if(mMonPage==1)
            {
                for(int i = 0; i < ui->monListWidget->count(); ++i)
                {
                    if(ui->monListWidget->item(i)->text().toLongLong()==aVehId)
                        ui->monListWidget->removeItemWidget(ui->monListWidget->item(i));
                }

                QList<QString> tLabelStrings = ui->MonTableWidgetLabel->text().split(" ");
                if(tLabelStrings.size()>1)
                {
                    if(tLabelStrings.at(1).toLongLong()==aVehId)
                    {
                        refreshMonTableWidget();
                    }
                }
            }
        }else if(tCurrentIndex==2)
        {
            if(ui->vehTableWidget->hasFocus())
            {
                if(ui->vehTableWidget->item(ui->vehTableWidget->currentRow(),0)->text().toLongLong()==aVehId)
                {
                    int row = ui->vehTableWidget->currentRow();
                    ui->vehTableWidget->clearSelection();
                    ui->vehTableWidget->removeRow(row);
                    emit ui->cusTableWidget->itemSelectionChanged();
                }else
                {
                    for(int i = 1; i < ui->vehTableWidget->rowCount(); ++i)
                    {
                        if(ui->vehTableWidget->item(i,0)->text().toLongLong()==aVehId)
                        {
                            ui->vehTableWidget->removeRow(i);
                        }
                    }
                }
            }else
            {
                for(int i = 1; i < ui->vehTableWidget->rowCount(); ++i)
                {
                    if(ui->vehTableWidget->item(i,0)->text().toLongLong()==aVehId)
                    {
                        ui->vehTableWidget->removeRow(i);
                    }
                }
            }
        }else if(tCurrentIndex==4)
        {
            if(ui->evtVehTableWidget->hasFocus())
            {
                if(ui->evtVehTableWidget->item(ui->evtVehTableWidget->currentRow(),0)->text().toLongLong()==aVehId)
                {
                    int row = ui->evtVehTableWidget->currentRow();
                    ui->evtVehTableWidget->clearSelection();
                    ui->evtVehTableWidget->removeRow(row);
                    emit ui->evtVehTableWidget->itemSelectionChanged();
                }
            }
        }
    }
}

void PrimeUI::informedUpdateVeh(qint64 aVehId,
                                qint64 aCapacity,
                                double aSpeed,
                                qint64 aRefuelTime,
                                qint64 aFixTime,
                                qint64 aUnitTime,
                                qint64 aBufferTime,
                                qint64 aLaunchCost)
{
    if(mVehPrptyRegistereds.contains(aVehId))
    {
        mVehPrptyRegistereds[aVehId]["capacity"] = QString("%1").arg(aCapacity);
        mVehPrptyRegistereds[aVehId]["speed"] = QString("%1").arg(aSpeed);
        mVehPrptyRegistereds[aVehId]["refueltime"] = QString("%1").arg(aRefuelTime);
        mVehPrptyRegistereds[aVehId]["fixtime"] = QString("%1").arg(aFixTime);
        mVehPrptyRegistereds[aVehId]["unittime"] = QString("%1").arg(aUnitTime);
        mVehPrptyRegistereds[aVehId]["buffertime"] = QString("%1").arg(aBufferTime);
        mVehPrptyRegistereds[aVehId]["launchcost"] = QString("%1").arg(aLaunchCost);

//        refreshRelatedWidgets("vehprptyU",aVehId);
        int tCurrentIndex = ui->primaryStackedWidget->currentIndex();
        if(tCurrentIndex==0)
        {
            if(mMonPage==1 && mVehOption==0)
            {
                QList<QString> tLabelStrings = ui->MonTableWidgetLabel->text().split(" ");
                if(tLabelStrings.size()>1)
                {
                    if(tLabelStrings.at(1).toLongLong()==aVehId)
                    {
                        refreshMonTableWidget(aVehId);
                    }
                }
            }
        }else if(tCurrentIndex==2)
        {
            for(int i = 1; i < ui->vehTableWidget->rowCount(); ++i)
            {
                if(ui->vehTableWidget->item(i,0)->text().toLongLong()==aVehId)
                {
                    ui->vehTableWidget->item(i,3)->setText(QString("%1").arg(aSpeed));
                    ui->vehTableWidget->item(i,4)->setText(QString("%1").arg(aCapacity));
                    ui->vehTableWidget->item(i,5)->setText(QString("%1").arg(aLaunchCost));
                    ui->vehTableWidget->item(i,6)->setText(QString("%1").arg(aFixTime));
                    ui->vehTableWidget->item(i,7)->setText(QString("%1").arg(aUnitTime));
                    ui->vehTableWidget->item(i,8)->setText(QString("%1").arg(aRefuelTime));
                    ui->vehTableWidget->item(i,9)->setText(QString("%1").arg(aBufferTime));
                }
            }
        }
    }
}

//Request
void PrimeUI::informedAddRequest(qint64 aCusId,
                                 qint64 aAssignedVeh,
                                 qint64 aDemand,
                                 qint64 aPULoc,
                                 qint64 aDLoc,
                                 qint64 aRTime,
                                 qint64 aWTime,
                                 int aPUFlag)
{


    if(!mCusRequesteds.contains(aCusId))
    {
        QHash<QString,qint64> tCusHash;
        tCusHash.insert("veh",aAssignedVeh);
        tCusHash.insert("demand",aDemand);
        tCusHash.insert("ploc",aPULoc);
        tCusHash.insert("dloc",aDLoc);
        tCusHash.insert("reqtime",aRTime);
        tCusHash.insert("wtime",aWTime);
        tCusHash.insert("puflag",aPUFlag);
        mCusRequesteds.insert(aCusId,tCusHash);
//        refreshRelatedWidgets("requestA&D",aCusId);
        int tCurrentIndex = ui->primaryStackedWidget->currentIndex();
        if(tCurrentIndex == 0)
        {
            if(mMonPage==2)
            {
                ui->monListWidget->addItem(QString("%1").arg(aCusId));
            }
        }else if(tCurrentIndex == 3)
        {
            qDebug()<<"fwelwefhul";

            int rowcount = ui->cusTableWidget->rowCount();
            ui->cusTableWidget->setRowCount(rowcount+1);

            QTableWidgetItem *tCusIdItem = new QTableWidgetItem(QString("%1").arg(aCusId));
            ui->cusTableWidget->setItem(rowcount,0,tCusIdItem);
            QTableWidgetItem *tCusVehItem = new QTableWidgetItem(QString("%1").arg(aAssignedVeh));
            ui->cusTableWidget->setItem(rowcount,1,tCusVehItem);
            QTableWidgetItem *tCusDemandItem = new QTableWidgetItem(QString("%1").arg(aDemand));
            ui->cusTableWidget->setItem(rowcount,2,tCusDemandItem);
            QTableWidgetItem *tCusPULocItem = new QTableWidgetItem(QString("%1").arg(aPULoc));
            ui->cusTableWidget->setItem(rowcount,3,tCusPULocItem);
            QTableWidgetItem *tCusDLocItem = new QTableWidgetItem(QString("%1").arg(aDLoc));
            ui->cusTableWidget->setItem(rowcount,4,tCusDLocItem);
            QTableWidgetItem *tCusRTimeItem = new QTableWidgetItem(QString("%1").arg(aRTime));
            ui->cusTableWidget->setItem(rowcount,5,tCusRTimeItem);
            QTableWidgetItem *tCusWTimeItem = new QTableWidgetItem(QString("%1").arg(aWTime));
            ui->cusTableWidget->setItem(rowcount,6,tCusWTimeItem);
        }

        CusRequestToView(aCusId);
        emit fbCusRequestByGWDone(aCusId,aAssignedVeh);
    }

}

void PrimeUI::informedCancelRequest(qint64 aCusId)
{
    if(mCusRequesteds.contains(aCusId))
    {
        CusDerequestToView(aCusId);
        emit fbCusDelRequestByGWDone(aCusId);

        mCusRequesteds.remove(aCusId);
//        refreshRelatedWidgets("requestA&D",aCusId);

        int tCurrentIndex = ui->primaryStackedWidget->currentIndex();
        if(tCurrentIndex==0)
        {
            if(mMonPage==2)
            {
                for(int i = 0; i < ui->monListWidget->count(); ++i)
                {
                    if(ui->monListWidget->item(i)->text().toLongLong()==aCusId)
                        ui->monListWidget->removeItemWidget(ui->monListWidget->item(i));
                }

                QList<QString> tLabelStrings = ui->MonTableWidgetLabel->text().split(" ");
                if(tLabelStrings.size()>1)
                {
                    if(tLabelStrings.at(1).toLongLong()==aCusId)
                    {
                        refreshMonTableWidget();
                    }
                }
            }
        }else if(tCurrentIndex==3)
        {
            if(ui->cusTableWidget->hasFocus())
            {
                if(ui->cusTableWidget->item(ui->cusTableWidget->currentRow(),0)->text().toLongLong()==aCusId)
                {
                    int row = ui->cusTableWidget->currentRow();
                    ui->cusTableWidget->clearSelection();
                    ui->cusTableWidget->removeRow(row);
                    emit ui->cusTableWidget->itemSelectionChanged();
                }else
                {
                    for(int i = 1; i < ui->cusTableWidget->rowCount(); ++i)
                    {
                        if(ui->cusTableWidget->item(i,0)->text().toLongLong()==aCusId)
                        {
                            ui->cusTableWidget->removeRow(i);
                        }
                    }
                }
            }else
            {
                for(int i = 1; i < ui->cusTableWidget->rowCount(); ++i)
                {
                    if(ui->cusTableWidget->item(i,0)->text().toLongLong()==aCusId)
                    {
                        ui->cusTableWidget->removeRow(i);
                    }
                }
            }
        }


    }
}

void PrimeUI::informedUpdateRequest(qint64 aCusId,
                                    qint64 aAssignedVeh,
                                    qint64 aDemand,
                                    qint64 aPULoc,
                                    qint64 aDLoc,
                                    qint64 aRTime,
                                    qint64 aWTime)
{
    if(mCusRequesteds.contains(aCusId))
    {
        mCusRequesteds[aCusId]["veh"] = aAssignedVeh;
        mCusRequesteds[aCusId]["demand"] = aDemand;
        mCusRequesteds[aCusId]["ploc"] = aPULoc;
        mCusRequesteds[aCusId]["dloc"] = aDLoc;
        mCusRequesteds[aCusId]["reqtime"] = aRTime;
        mCusRequesteds[aCusId]["wtime"] = aWTime;
//        refreshRelatedWidgets("requestU",aCusId);

        int tCurrentIndex = ui->primaryStackedWidget->currentIndex();
        if(tCurrentIndex==0)
        {
            if(mMonPage==2)
            {
                QList<QString> tLabelStrings = ui->MonTableWidgetLabel->text().split(" ");
                if(tLabelStrings.size()>1)
                {
                    if(tLabelStrings.at(1).toLongLong()==aCusId)
                    {
                        refreshMonTableWidget(aCusId);
                    }
                }
            }
        }else if(tCurrentIndex==3)
        {
            for(int i = 1; i < ui->cusTableWidget->rowCount(); ++i)
            {
                if(ui->cusTableWidget->item(i,0)->text().toLongLong()==aCusId)
                {
                    ui->cusTableWidget->item(i,1)->setText(QString("%1").arg(aAssignedVeh));
                    ui->cusTableWidget->item(i,2)->setText(QString("%1").arg(aDemand));
                    ui->cusTableWidget->item(i,3)->setText(QString("%1").arg(aPULoc));
                    ui->cusTableWidget->item(i,4)->setText(QString("%1").arg(aDLoc));
                    ui->cusTableWidget->item(i,5)->setText(QString("%1").arg(aRTime));
                    ui->cusTableWidget->item(i,6)->setText(QString("%1").arg(aWTime));
                }
            }
        }

        CusChgRequestToView(aCusId);
        emit fbCusUpdateRequestByGWDone(aCusId);
    }
}

//Evt
void PrimeUI::informedJobUpdate(qint64 aVehId, QList<QHash<QString, qint64> > aJobList)
{
    if(mVehJobsHash.contains(aVehId))
    {
        mVehJobsHash[aVehId] = aJobList;
    }else
    {
        mVehJobsHash.insert(aVehId,aJobList);
    }
    VehJobUpdateToView(aVehId);
//    refreshRelatedWidgets("job",aVehId);
    int tCurrentIndex = ui->primaryStackedWidget->currentIndex();
    if(tCurrentIndex==0)
    {
        if(mMonPage==1 && mVehOption==2)
        {
            QList<QString> tLabelStrings = ui->MonTableWidgetLabel->text().split(" ");
            if(tLabelStrings.size()>1)
            {
                if(tLabelStrings.at(1).toLongLong()==aVehId)
                {
                    refreshMonTableWidget(aVehId);
                }
            }
        }
    }else if(tCurrentIndex==4)
    {
        int rowcount = ui->evtVehTableWidget->rowCount();
        //update of evt veh table
        for(int i = 1; i < rowcount; ++i)
        {
            if(ui->evtVehTableWidget->item(i,0)->text().toLongLong()==aVehId)
            {
                ui->evtVehTableWidget->item(i,1)->setText(QString("%1").arg(aJobList.size()));
                break;
            }
        }
        if(ui->evtJobsTableWidget->rowCount()>1)
        {
            if(ui->evtVehTableWidget->item(ui->evtVehTableWidget->currentRow(),0)->text().toLongLong()==aVehId)
            {
                refreshEvtJobsTableWidget();
            }
        }
    }
}

void PrimeUI::informedUpdateVehCost(qint64 aVehId, qint64 aCost)
{
    if(mVehPrptyRegistereds.contains(aVehId))
    {
        mVehPrptyRegistereds[aVehId]["cost"] = QString("%1").arg(aCost);
//        refreshRelatedWidgets("cost",aVehId);

        int tCurrentIndex = ui->primaryStackedWidget->currentIndex();
        if(tCurrentIndex==0)
        {
            if(mMonPage==1 && mVehOption==0)
            {
                QList<QString> tLabelStrings = ui->MonTableWidgetLabel->text().split(" ");
                if(tLabelStrings.size()>1)
                {
                    if(tLabelStrings.at(1).toLongLong()==aVehId)
                    {
                        refreshMonTableWidget(aVehId);
                    }
                }
            }
        }else if(tCurrentIndex==4)
        {
            int rowcount = ui->evtVehTableWidget->rowCount();
            //update of evt veh table
            for(int i = 1; i < rowcount; ++i)
            {
                if(ui->evtVehTableWidget->item(i,0)->text().toLongLong()==aVehId)
                {
                    ui->evtVehTableWidget->item(i,2)->setText(QString("%1").arg(aCost));
                    break;
                }
            }
        }
    }
}

void PrimeUI::informedUpdateVehInDepot(qint64 aVehId, int aInDepot)
{
    if(mVehPrptyRegistereds.contains(aVehId))
    {
        mVehPrptyRegistereds[aVehId]["indepot"] = QString("%1").arg(aInDepot);
//        refreshRelatedWidgets("indepot",aVehId);

        int tCurrentIndex = ui->primaryStackedWidget->currentIndex();
        if(tCurrentIndex==0)
        {
            if(mMonPage==1 && mVehOption==0)
            {
                QList<QString> tLabelStrings = ui->MonTableWidgetLabel->text().split(" ");
                if(tLabelStrings.size()>1)
                {
                    if(tLabelStrings.at(1).toLongLong()==aVehId)
                    {
                        refreshMonTableWidget(aVehId);
                    }
                }
            }
        }else if(tCurrentIndex==4)
        {
            int rowcount = ui->evtVehTableWidget->rowCount();
            //update of evt veh table
            for(int i = 1; i < rowcount; ++i)
            {
                if(ui->evtVehTableWidget->item(i,0)->text().toLongLong()==aVehId)
                {
                    ui->evtVehTableWidget->item(i,3)->setText(QString("%1").arg(aInDepot));
                    break;
                }
            }
        }
    }
}

void PrimeUI::informedGetPickedUp(qint64 aCusId)
{
    if(mCusRequesteds.contains(aCusId))
    {
        mCusRequesteds[aCusId]["puflag"] = 1;
//        refreshRelatedWidgets("pickup",aCusId);
        int tCurrentIndex = ui->primaryStackedWidget->currentIndex();
        if(tCurrentIndex==0)
        {
            if(mMonPage==2)
            {
                QList<QString> tLabelStrings = ui->MonTableWidgetLabel->text().split(" ");
                if(tLabelStrings.size()>1)
                {
                    if(tLabelStrings.at(1).toLongLong()==aCusId)
                    {
                        refreshMonTableWidget(aCusId);
                    }
                }
            }
        }
    }
}

void PrimeUI::informedCurTimeChanged()
{
    if(settingCurrentTime)
    {

    }else
    {
        QList<QString> tRealTimeStrs = mpDb->getRealTime().split(":");
        int hour = tRealTimeStrs.at(0).toInt();
        int min = tRealTimeStrs.at(1).toInt();
        int sec = tRealTimeStrs.at(2).toInt();
        ui->evtHourSpBox->setValue(hour);
        ui->evtMinuteSpBox->setValue(min);
        ui->evtSecondSpBox->setValue(sec);
        ui->evtSimTimeSpBox->setValue(mpDb->getSimTime());
    }
    ui->simTimeDataLabel->setText(QString("%1").arg(mpDb->getSimTime()));
    ui->timeDataLabel->setText(mpDb->getRealTime());
}

//=======================================================
//Slot For Client Gateway Communication
void PrimeUI::CusRequestByGW(qint64 aCusId, QHash<QString, qint64> aHash)
{
    CusRequestByUI(aCusId, aHash);
}

void PrimeUI::CusDelRequestByGW(qint64 aCusId)
{
    CusDerequestByUI(aCusId);
}

void PrimeUI::CusUpdateRequestByGW(qint64 aCusId, QHash<QString, qint64> aHash)
{
    CusChgRequestByUI(aCusId, aHash);
}

void PrimeUI::CusAnsPickupByGW(qint64 aCusId, qint64 aVehId, QString aAns)
{
    EvtCustomerAnsPickUp(aVehId,aCusId,aAns);
    QList<QTableWidgetItem*> tItemList = ui->evtCusAnsTableWidget->findItems(QString::number(aCusId),Qt::MatchExactly);
    for (QTableWidgetItem* tItem : tItemList)
    {
        if(tItem->column()==0 && ui->evtCusAnsTableWidget->item(tItem->row(),3)->text()==QString("PU"))
        {
            ui->evtCusAnsTableWidget->removeRow(tItem->row());
            emit ui->evtCusAnsTableWidget->itemSelectionChanged();
            break;
        }
    }
}

void PrimeUI::CusAnsDeliveryByGW(qint64 aCusId, qint64 aVehId, QString aAns)
{
    EvtCustomerAnsDelivery(aVehId,aCusId,aAns);
    QList<QTableWidgetItem*> tItemList = ui->evtCusAnsTableWidget->findItems(QString::number(aCusId),Qt::MatchExactly);
    for (QTableWidgetItem* tItem : tItemList)
    {
        if(tItem->column()==0 && ui->evtCusAnsTableWidget->item(tItem->row(),3)->text()==QString("DL"))
        {
            ui->evtCusAnsTableWidget->removeRow(tItem->row());
            emit ui->evtCusAnsTableWidget->itemSelectionChanged();
            break;
        }
    }
}
