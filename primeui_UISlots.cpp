#include "primeui.h"
#include "ui_primeui.h"

//====================================================
//UI Slot Funcs:
//Monitoring
void PrimeUI::on_monBtn_clicked()
{
    resetAllViews();
    ui->primaryStackedWidget->setCurrentIndex(0);
    ui->monToolBox->setCurrentIndex(mMonPage);
    refreshMonListWidget();
    refreshMonTableWidget();
    mpMapView->SwitchView("mon");
}

void PrimeUI::on_monToolBox_currentChanged(int index)
{
//    qDebug()<<"on_monToolBox_currentChanged"<<index;
    mMonPage = index;
    refreshMonListWidget();
    refreshMonTableWidget();
}

void PrimeUI::on_monVehStatusBtn_clicked()
{
    mVehOption=0;
    refreshMonTableWidget();
}

void PrimeUI::on_monVehDistBtn_clicked()
{
    mVehOption=1;
    refreshMonTableWidget();
}

void PrimeUI::on_monVehJobsBtn_clicked()
{
    mVehOption=2;
    refreshMonTableWidget();
}

void PrimeUI::on_monListWidget_currentRowChanged(int currentRow)
{
    //    qDebug()<<"weh";
    if(/*ui->monListWidget->selectedItems().size()*/currentRow>=0){
        qint64 tId = ui->monListWidget->item(currentRow)->text().toLongLong();
        refreshMonTableWidget(tId);
    }
}

void PrimeUI::on_monListWidget_itemSelectionChanged()
{
    //    qDebug()<<"weh";
    //    if(ui->monListWidget->selectedItems().size()>0){
    ////        qint64 tId = ui->monListWidget->item(row)->text().toLongLong();
    //        qint64 tId = ui->monListWidget->selectedItems().first()->text().toLongLong();
    //        refreshMonTableWidget(tId);
    //    }
}

//void PrimeUI::on_MonListRefreshBtn_clicked()
//{

//}

//void PrimeUI::on_MonTableRefreshBtn_clicked()
//{

//}

//Loc Manager
void PrimeUI::on_locManBtn_clicked()
{
    resetAllViews();
    ui->primaryStackedWidget->setCurrentIndex(1);
    refreshLocTableWidget();
    mpMapView->SwitchView("loc");
}

void PrimeUI::on_locRegBtn_clicked()
{
    mLocMode = QString("reg");
    ui->locIdEdit->setFocus();
    ui->locTableWidget->clearSelection();
    ui->locTableWidget->setEnabled(false);
    ui->locRegBtn->setEnabled(false);
    ui->locDeregBtn->setEnabled(false);
    ui->locUpdateBtn->setEnabled(false);
    ui->locIdEdit->setEnabled(true);
    ui->locCancelBtn->setEnabled(true);
    ui->locConfirmBtn->setText("Confirm Register");
}

void PrimeUI::on_locDeregBtn_clicked()
{
    locCellSelected=false;
    mLocMode = QString("dereg");
    ui->locIdEdit->setText(QString("%1").arg(mLocClickedId));
    //    ui->locLatEdit->setText(QString::number(mLocRegistereds.value(mLocClickedId).first,'g',10));
    //    ui->locLongEdit->setText(QString::number(mLocRegistereds.value(mLocClickedId).second,'g',10));
    ui->locTableWidget->clearSelection();
    ui->locTableWidget->setEnabled(false);
    ui->locRegBtn->setEnabled(false);
    ui->locDeregBtn->setEnabled(false);
    ui->locUpdateBtn->setEnabled(false);
    ui->locConfirmBtn->setEnabled(true);
    ui->locCancelBtn->setEnabled(true);
    ui->locConfirmBtn->setText("Confirm Deregister");
}

void PrimeUI::on_locUpdateBtn_clicked()
{
    locCellSelected=false;
    mLocMode = QString("update");
    ui->locIdEdit->setText(QString("%1").arg(mLocClickedId));
    ui->locLatEdit->setText(QString::number(mLocRegistereds.value(mLocClickedId).first,'g',10));
    ui->locLongEdit->setText(QString::number(mLocRegistereds.value(mLocClickedId).second,'g',10));
    ui->locTableWidget->clearSelection();
    ui->locTableWidget->setEnabled(false);
    ui->locRegBtn->setEnabled(false);
    ui->locDeregBtn->setEnabled(false);
    ui->locUpdateBtn->setEnabled(false);
    ui->locCancelBtn->setEnabled(true);
    ui->locConfirmBtn->setText("Confirm Update");
}

void PrimeUI::on_LLGetCoordBtn_clicked()
{

    mpMapView->enterGetLLMode();
}

void PrimeUI::on_LLReflectBtn_clicked()
{
    double tLat = ui->locLatEdit->text().toDouble();
    double tLong = ui->locLatEdit->text().toDouble();
    if(checkInRangeLat(tLat)&&checkInRangeLong(tLong))
    {
        QPair<double,double> tCoord(tLat,tLong);
        addCrossHairToView(tCoord);
    }
}

void PrimeUI::on_locConfirmBtn_clicked()
{
    qint64 tLocId = ui->locIdEdit->text().toLongLong();
    if(mLocMode=="reg"){
        double tLat = ui->locLatEdit->text().toDouble();
        double tLong = ui->locLongEdit->text().toDouble();
        QPair<double,double> tCoord(tLat,tLong);
        LocRegisterByUI(tLocId,tCoord);
    }else if(mLocMode=="dereg")
    {
        LocDeregisterByUI(tLocId);
    }else if(mLocMode=="update")
    {
        double tLat = ui->locLatEdit->text().toDouble();
        double tLong = ui->locLongEdit->text().toDouble();
        QPair<double,double> tCoord(tLat,tLong);
        LocUpdateByUI(tLocId,tCoord);
    }
    LocResetInterface();
    //    refreshLocTableWidget();
}

void PrimeUI::on_locCancelBtn_clicked()
{
    LocResetInterface();
}

void PrimeUI::on_locTableWidget_cellClicked(int row, int column)
{
    ui->locTableWidget->selectRow(row);
    if(row>0)
    {
        locCellSelected=true;
        mLocClickedId = ui->locTableWidget->item(row,0)->text().toLongLong();
        ui->locDeregBtn->setEnabled(true);
        ui->locUpdateBtn->setEnabled(true);

        mpMapView->focusOnItem("loc",mLocClickedId);
    }else
    {
        locCellSelected=false;
        ui->locRegBtn->setEnabled(true);
        ui->locDeregBtn->setEnabled(false);
        ui->locUpdateBtn->setEnabled(false);
        mLocClickedId = 0;
        mpMapView->clearFocus();
    }
}

void PrimeUI::on_locTableWidget_itemSelectionChanged()
{
    if(ui->locTableWidget->selectedItems().isEmpty() &&
            locCellSelected &&
            ui->primaryStackedWidget->currentIndex()==1)
    {
        locCellSelected=false;
        ui->locRegBtn->setEnabled(true);
        ui->locDeregBtn->setEnabled(false);
        ui->locUpdateBtn->setEnabled(false);

        mLocClickedId = 0;
        mpMapView->clearFocus();
    }
}

void PrimeUI::on_locIdEdit_textChanged(const QString &arg1)
{
    if(ui->locIdEdit->text().data()->isNumber()||ui->locIdEdit->text().toLongLong()>0)
    {
        if(mLocMode=="reg"||mLocMode=="update")
        {
            ui->LLGetCoordBtn->setEnabled(true);
            ui->locLatLabel->setEnabled(true);
            ui->locLongLabel->setEnabled(true);
            ui->locLatEdit->setEnabled(true);
            ui->locLongEdit->setEnabled(true);
        }
    }
}

void PrimeUI::on_locLatEdit_textChanged(const QString &arg1)
{
    if(!ui->locLatEdit->text().isEmpty() && !ui->locLongEdit->text().isEmpty())
    {
        if(mLocMode=="reg"||mLocMode=="update")
            ui->LLReflectBtn->setEnabled(true);

        double tLat = ui->locLatEdit->text().toDouble();
        double tLong = ui->locLongEdit->text().toDouble();
        qint64 tLocId = ui->locIdEdit->text().toLongLong();
        if(checkInRangeLat(tLat)&&checkInRangeLong(tLong))
        {
            qDebug()<<"in range";
            if(tLocId>0)
                ui->locConfirmBtn->setEnabled(true);
        }else
        {
            ui->locConfirmBtn->setEnabled(false);
            //            deleteCrossHairInView();
        }
    }else
    {
        ui->LLReflectBtn->setEnabled(false);
        //        deleteCrossHairInView();
    }
}

void PrimeUI::on_locLongEdit_textChanged(const QString &arg1)
{
    if(!ui->locLatEdit->text().isEmpty() && !ui->locLongEdit->text().isEmpty())
    {
        ui->LLReflectBtn->setEnabled(true);

        double tLat = ui->locLatEdit->text().toDouble();
        double tLong = ui->locLongEdit->text().toDouble();
        qint64 tLocId = ui->locIdEdit->text().toLongLong();
        if(checkInRangeLat(tLat)&&checkInRangeLong(tLong))
        {
            qDebug()<<"in range";
            if(tLocId>0)
                ui->locConfirmBtn->setEnabled(true);
        }else
        {
            ui->locConfirmBtn->setEnabled(false);
            //            deleteCrossHairInView();
        }
    }else
    {
        ui->LLReflectBtn->setEnabled(false);
        //        deleteCrossHairInView();
    }
}

//void PrimeUI::on_locRefreshBtn_clicked()
//{

//}

//Veh Manager
void PrimeUI::on_vehManBtn_clicked()
{
    resetAllViews();
    refreshVehTableWidget();
    ui->primaryStackedWidget->setCurrentIndex(2);
    mpMapView->SwitchView("veh");
}

void PrimeUI::on_vehRegBtn_clicked()
{
    mVehMode = QString("reg");
    ui->vehIdEdit->setFocus();
    ui->vehTableWidget->clearSelection();
    ui->vehTableWidget->setEnabled(false);
    ui->vehRegBtn->setEnabled(false);
    ui->vehDeregBtn->setEnabled(false);
    ui->vehIdEdit->setEnabled(true);
    //    ui->vehCoordChBox->setEnabled(true);
    ui->vehCoordChBox->setChecked(true);
    ui->vehGetCoordBtn->setEnabled(true);
    ui->vehRefCoordBtn->setEnabled(true);
    //    ui->vehSpeedChBox->setEnabled(true);
    ui->vehSpeedChBox->setChecked(true);
    //    ui->vehCapChBox->setEnabled(true);
    ui->vehCapChBox->setChecked(true);
    //    ui->vehLCostChBox->setEnabled(true);
    ui->vehLCostChBox->setChecked(true);
    //    ui->vehFTimeChBox->setEnabled(true);
    ui->vehFTimeChBox->setChecked(true);
    //    ui->vehUTimeChBox->setEnabled(true);
    ui->vehUTimeChBox->setChecked(true);
    //    ui->vehRTimeChBox->setEnabled(true);
    ui->vehRTimeChBox->setChecked(true);
    //    ui->vehBTimeChBox->setEnabled(true);
    ui->vehBTimeChBox->setChecked(true);

    ui->vehDefaultBtn->setEnabled(true);
    on_vehDefaultBtn_clicked();

    ui->vehConfirmBtn->setEnabled(true);
    ui->vehCancelBtn->setEnabled(true);
    ui->vehLatLabel->setEnabled(true);
    ui->vehLongLabel->setEnabled(true);
    ui->vehConfirmBtn->setText("Confirm Register");
}

void PrimeUI::on_vehDeregBtn_clicked()
{
    vehCellSelected=false;
    mVehMode = QString("dereg");
    ui->vehIdEdit->setText(QString("%1").arg(mVehClickedId));
    ui->vehTableWidget->clearSelection();
    ui->vehTableWidget->setEnabled(false);
    ui->vehRegBtn->setEnabled(false);
    ui->vehDeregBtn->setEnabled(false);
    ui->vehUpdateBtn->setEnabled(false);
    ui->vehConfirmBtn->setEnabled(true);
    ui->vehCancelBtn->setEnabled(true);
    ui->vehConfirmBtn->setText("Confirm Deregister");
}

void PrimeUI::on_vehUpdateBtn_clicked()
{
    vehCellSelected=false;
    mVehMode= QString("update");

    ui->vehCoordChBox->setEnabled(true);
    ui->vehSpeedChBox->setEnabled(true);
    ui->vehCapChBox->setEnabled(true);
    ui->vehLCostChBox->setEnabled(true);
    ui->vehFTimeChBox->setEnabled(true);
    ui->vehUTimeChBox->setEnabled(true);
    ui->vehRTimeChBox->setEnabled(true);
    ui->vehBTimeChBox->setEnabled(true);

    ui->vehIdEdit->setText(QString("%1").arg(mVehClickedId));
    ui->vehLatEdit->setText(QString("%1").arg(mVehCoordsHash.value(mVehClickedId).first));
    ui->vehLongEdit->setText(QString("%1").arg(mVehCoordsHash.value(mVehClickedId).second));
    ui->vehSpeedEdit->setText(mVehPrptyRegistereds.value(mVehClickedId).value("speed"));
    ui->vehCapSpBox->setValue(mVehPrptyRegistereds.value(mVehClickedId).value("capacity").toInt());
    ui->vehLCostSpBox->setValue(mVehPrptyRegistereds.value(mVehClickedId).value("launchcost").toInt());
    ui->vehFTimeSpBox->setValue(mVehPrptyRegistereds.value(mVehClickedId).value("fixtime").toInt());
    ui->vehUTimeSpBox->setValue(mVehPrptyRegistereds.value(mVehClickedId).value("unittime").toInt());
    ui->vehRTimeSpBox->setValue(mVehPrptyRegistereds.value(mVehClickedId).value("refueltime").toInt());
    ui->vehBTimeSpBox->setValue(mVehPrptyRegistereds.value(mVehClickedId).value("buffertime").toInt());

    ui->vehTableWidget->clearSelection();
    ui->vehTableWidget->setEnabled(false);
    ui->vehRegBtn->setEnabled(false);
    ui->vehDeregBtn->setEnabled(false);
    ui->vehUpdateBtn->setEnabled(false);
    ui->vehCancelBtn->setEnabled(true);
    ui->vehConfirmBtn->setEnabled(true);
    ui->vehConfirmBtn->setText("Confirm Update");
}

void PrimeUI::on_vehGetCoordBtn_clicked()
{
    mpMapView->enterGetLLMode();
}

void PrimeUI::on_vehRefCoordBtn_clicked()
{
    double tLat = ui->vehLatEdit->text().toDouble();
    double tLong = ui->locLatEdit->text().toDouble();
    if(checkInRangeLat(tLat)&&checkInRangeLong(tLong))
    {
        QPair<double,double> tCoord(tLat,tLong);
        addCrossHairToView(tCoord);
    }
}

void PrimeUI::on_vehDefaultBtn_clicked()
{
    //    ui->vehSpeedEdit->setText(mVehPrptyRegistereds.value(mVehClickedId).value("speed"));
    //    ui->vehCapSpBox->setValue(mVehPrptyRegistereds.value(mVehClickedId).value("capacity").toInt());
    //    ui->vehLCostSpBox->setValue(mVehPrptyRegistereds.value(mVehClickedId).value("launchcost").toInt());
    //    ui->vehFTimeSpBox->setValue(mVehPrptyRegistereds.value(mVehClickedId).value("fixtime").toInt());
    //    ui->vehUTimeSpBox->setValue(mVehPrptyRegistereds.value(mVehClickedId).value("unittime").toInt());
    //    ui->vehRTimeSpBox->setValue(mVehPrptyRegistereds.value(mVehClickedId).value("refueltime").toInt());
    //    ui->vehBTimeSpBox->setValue(mVehPrptyRegistereds.value(mVehClickedId).value("buffertime").toInt());
    ui->vehSpeedEdit->setText(mVehDefaultParams.value("speed"));
    ui->vehCapSpBox->setValue(mVehDefaultParams.value("capacity").toInt());
    ui->vehLCostSpBox->setValue(mVehDefaultParams.value("launchcost").toInt());
    ui->vehFTimeSpBox->setValue(mVehDefaultParams.value("fixtime").toInt());
    ui->vehUTimeSpBox->setValue(mVehDefaultParams.value("unittime").toInt());
    ui->vehRTimeSpBox->setValue(mVehDefaultParams.value("refueltime").toInt());
    ui->vehBTimeSpBox->setValue(mVehDefaultParams.value("buffertime").toInt());
}

void PrimeUI::on_vehConfirmBtn_clicked()
{
    qint64 tVehId = ui->vehIdEdit->text().toLongLong();

    if(mVehMode=="reg")
    {
        if(!ui->vehIdEdit->text().isEmpty() && ui->vehIdEdit->text().data()->isNumber() && ui->vehIdEdit->text().toInt()>0 &&
                !ui->vehLatEdit->text().isEmpty() && ui->vehLatEdit->text().data()->isDigit() && checkInRangeLat(ui->vehLatEdit->text().toDouble()) &&
                !ui->vehLongEdit->text().isEmpty() && ui->vehLongEdit->text().data()->isDigit() && checkInRangeLong(ui->vehLongEdit->text().toDouble()) &&
                !ui->vehSpeedEdit->text().isEmpty() && ui->vehSpeedEdit->text().data()->isDigit() && ui->vehSpeedEdit->text().toDouble()>0 &&
                !ui->vehCapSpBox->text().isEmpty() && ui->vehCapSpBox->value()>=0 && ui->vehCapSpBox->text().data()->isNumber() &&
                !ui->vehLCostSpBox->text().isEmpty() && ui->vehLCostSpBox->value()>=0 && ui->vehLCostSpBox->text().data()->isNumber() &&
                !ui->vehFTimeSpBox->text().isEmpty() && ui->vehFTimeSpBox->value()>=0 && ui->vehFTimeSpBox->text().data()->isNumber() &&
                !ui->vehUTimeSpBox->text().isEmpty() && ui->vehUTimeSpBox->value()>=0 && ui->vehUTimeSpBox->text().data()->isNumber() &&
                !ui->vehRTimeSpBox->text().isEmpty() && ui->vehRTimeSpBox->value()>=0 && ui->vehRTimeSpBox->text().data()->isNumber() &&
                !ui->vehBTimeSpBox->text().isEmpty() && ui->vehBTimeSpBox->value()>=0 && ui->vehBTimeSpBox->text().data()->isNumber())
        {
            double tLat = ui->vehLatEdit->text().toDouble();
            double tLong = ui->vehLongEdit->text().toDouble();
            QPair<double,double> tCoord(tLat,tLong);
            QHash<QString,QString> tHash;
            tHash.insert("speed",ui->vehSpeedEdit->text());
            tHash.insert("capacity",ui->vehCapSpBox->text());
            tHash.insert("launchcost",ui->vehLCostSpBox->text());
            tHash.insert("fixtime",ui->vehFTimeSpBox->text());
            tHash.insert("unittime",ui->vehUTimeSpBox->text());
            tHash.insert("refueltime",ui->vehRTimeSpBox->text());
            tHash.insert("buffertime",ui->vehBTimeSpBox->text());
            tHash.insert("cost","0");
            tHash.insert("indepot","1");
            VehRegisterByUI(tVehId,tCoord,tHash);
        }else
        {
            QMessageBox::warning(this,"Register Vehicle","Parameters Invalid",QMessageBox::Ok);
        }
    }else if(mVehMode=="dereg")
    {
        VehDeregisterByUI(tVehId);
    }else if(mVehMode=="update")
    {
        if(ui->vehCoordChBox->isChecked())
        {
            if(!ui->vehLatEdit->text().isEmpty() && ui->vehLatEdit->text().data()->isDigit() && checkInRangeLat(ui->vehLatEdit->text().toDouble()) &&
                    !ui->vehLongEdit->text().isEmpty() && ui->vehLongEdit->text().data()->isDigit() && checkInRangeLong(ui->vehLongEdit->text().toDouble()))
            {
                double tLat = ui->vehLatEdit->text().toDouble();
                double tLong = ui->vehLongEdit->text().toDouble();
                QPair<double,double> tCoord(tLat,tLong);
                VehCoordUpdateByUI(tVehId,tCoord);
            }else
            {
                qDebug()<<"veh lat or long invalid";
            }
        }
        if(ui->vehSpeedChBox->isChecked())
        {
            if(!ui->vehSpeedEdit->text().isEmpty() && ui->vehSpeedEdit->text().data()->isDigit() && ui->vehSpeedEdit->text().toDouble()>0)
            {
                VehPrptyUpdateByUI(tVehId,"speed",ui->vehSpeedEdit->text());
            }else
            {
                qDebug()<<"veh speed invalid";
            }
        }
        if(ui->vehCapChBox->isChecked())
        {
            if(!ui->vehCapSpBox->text().isEmpty() && ui->vehCapSpBox->value()>=0 && ui->vehCapSpBox->text().data()->isNumber())
            {
                VehPrptyUpdateByUI(tVehId,"capacity",ui->vehCapSpBox->text());
            }else
            {
                qDebug()<<"veh capacity invalid";
            }
        }
        if(ui->vehLCostChBox->isChecked())
        {
            if(!ui->vehLCostSpBox->text().isEmpty() && ui->vehLCostSpBox->value()>=0 && ui->vehLCostSpBox->text().data()->isNumber())
            {
                VehPrptyUpdateByUI(tVehId,"launchcost",ui->vehLCostSpBox->text());
            }else
            {
                qDebug()<<"veh launch cost invalid";
            }
        }
        if(ui->vehFTimeChBox->isChecked())
        {
            if(!ui->vehFTimeSpBox->text().isEmpty() && ui->vehFTimeSpBox->value()>=0 && ui->vehFTimeSpBox->text().data()->isNumber())
            {
                VehPrptyUpdateByUI(tVehId,"fixtime",ui->vehFTimeSpBox->text());
            }else
            {
                qDebug()<<"veh fix time invalid";
            }
        }
        if(ui->vehUTimeChBox->isChecked())
        {
            if(!ui->vehUTimeSpBox->text().isEmpty() && ui->vehUTimeSpBox->value()>=0 && ui->vehUTimeSpBox->text().data()->isNumber())
            {
                VehPrptyUpdateByUI(tVehId,"unittime",ui->vehUTimeSpBox->text());
            }else
            {
                qDebug()<<"veh unit time invalid";
            }
        }
        if(ui->vehRTimeChBox->isChecked())
        {
            if(!ui->vehRTimeSpBox->text().isEmpty() && ui->vehRTimeSpBox->value()>=0 && ui->vehRTimeSpBox->text().data()->isNumber())
            {
                VehPrptyUpdateByUI(tVehId,"refueltime",ui->vehRTimeSpBox->text());
            }else
            {
                qDebug()<<"veh refuel time invalid";
            }
        }if(ui->vehBTimeChBox->isChecked())
        {
            if(!ui->vehBTimeSpBox->text().isEmpty() && ui->vehBTimeSpBox->value()>=0 && ui->vehBTimeSpBox->text().data()->isNumber())
            {
                VehPrptyUpdateByUI(tVehId,"buffertime",ui->vehBTimeSpBox->text());
            }else
            {
                qDebug()<<"veh buffer time invalid";
            }
        }
    }
    VehResetInterface();
    //    refreshVehTableWidget();
}

void PrimeUI::on_vehCancelBtn_clicked()
{
    VehResetInterface();
}

void PrimeUI::on_vehTableWidget_cellClicked(int row, int column)
{
    ui->vehTableWidget->selectRow(row);
    if(row>0)
    {
        vehCellSelected=true;
        mVehClickedId = ui->vehTableWidget->item(row,0)->text().toLongLong();
        ui->vehDeregBtn->setEnabled(true);
        ui->vehUpdateBtn->setEnabled(true);

        mpMapView->focusOnItem("veh",mVehClickedId);
    }else
    {
        vehCellSelected=false;
        ui->vehRegBtn->setEnabled(true);
        ui->vehDeregBtn->setEnabled(false);
        ui->vehUpdateBtn->setEnabled(false);

        mVehClickedId=0;
        mpMapView->clearFocus();
    }
}

void PrimeUI::on_vehTableWidget_itemSelectionChanged()
{
    if(ui->vehTableWidget->selectedItems().isEmpty() &&
            vehCellSelected &&
            ui->primaryStackedWidget->currentIndex()==2)
    {
        vehCellSelected=false;
        ui->vehRegBtn->setEnabled(true);
        ui->vehDeregBtn->setEnabled(false);
        ui->vehUpdateBtn->setEnabled(false);

        mVehClickedId=0;
        mpMapView->clearFocus();
    }
}

void PrimeUI::on_vehCoordChBox_toggled(bool checked)
{
    if(checked)
    {
        ui->vehLatLabel->setEnabled(true);
        ui->vehLongLabel->setEnabled(true);
        ui->vehLatEdit->setEnabled(true);
        ui->vehLongEdit->setEnabled(true);
        ui->vehGetCoordBtn->setEnabled(true);
        ui->vehRefCoordBtn->setEnabled(true);
    }else
    {
        ui->vehLatLabel->setEnabled(false);
        ui->vehLongLabel->setEnabled(false);
        ui->vehLatEdit->setEnabled(false);
        ui->vehLongEdit->setEnabled(false);
        ui->vehGetCoordBtn->setEnabled(false);
        ui->vehRefCoordBtn->setEnabled(false);
    }
}

void PrimeUI::on_vehSpeedChBox_toggled(bool checked)
{
    if(checked)
    {
        ui->vehSpeedEdit->setEnabled(true);
    }else
    {
        ui->vehSpeedEdit->setEnabled(false);
    }
}

void PrimeUI::on_vehCapChBox_toggled(bool checked)
{
    if(checked)
    {
        ui->vehCapSpBox->setEnabled(true);
    }else
    {
        ui->vehCapSpBox->setEnabled(false);
    }
}

void PrimeUI::on_vehLCostChBox_toggled(bool checked)
{
    if(checked)
    {
        ui->vehLCostSpBox->setEnabled(true);
    }else
    {
        ui->vehLCostSpBox->setEnabled(false);
    }
}

void PrimeUI::on_vehFTimeChBox_toggled(bool checked)
{
    if(checked)
    {
        ui->vehFTimeSpBox->setEnabled(true);
    }else
    {
        ui->vehFTimeSpBox->setEnabled(false);
    }
}

void PrimeUI::on_vehUTimeChBox_toggled(bool checked)
{
    if(checked)
    {
        ui->vehUTimeSpBox->setEnabled(true);
    }else
    {
        ui->vehUTimeSpBox->setEnabled(false);
    }
}

void PrimeUI::on_vehRTimeChBox_toggled(bool checked)
{
    if(checked)
    {
        ui->vehRTimeSpBox->setEnabled(true);
    }else
    {
        ui->vehRTimeSpBox->setEnabled(false);
    }
}

void PrimeUI::on_vehBTimeChBox_toggled(bool checked)
{
    if(checked)
    {
        ui->vehBTimeSpBox->setEnabled(true);
    }else
    {
        ui->vehBTimeSpBox->setEnabled(false);
    }
}

//void PrimeUI::on_vehRefreshBtn_clicked()
//{

//}

//Cus Manager
void PrimeUI::on_cusManBtn_clicked()
{
    resetAllViews();
    ui->primaryStackedWidget->setCurrentIndex(3);
    refreshCusTableWidget();
    mpMapView->SwitchView("cus");
}

void PrimeUI::on_cusReqBtn_clicked()
{


    mCusMode = QString("req");
    ui->cusIdEdit->setFocus();
    ui->cusTableWidget->clearSelection();
    ui->cusTableWidget->setEnabled(false);

    ui->cusReqBtn->setEnabled(false);
    ui->cusCancelReqBtn->setEnabled(false);
    ui->cusIdEdit->setEnabled(true);
    //    ui->cusDemandsChBox->setEnabled(true);
    ui->cusDemandsChBox->setChecked(true);
    //    ui->cusPULocChBox->setEnabled(true);
    ui->cusPULocChBox->setChecked(true);
    //    ui->cusDLocChBox->setEnabled(true);
    ui->cusDLocChBox->setChecked(true);
    //    ui->cusRSTimeChBox->setEnabled(true);
    ui->cusRSTimeChBox->setChecked(true);
    //    ui->cusWTimeChBox->setEnabled(true);
    ui->cusWTimeChBox->setChecked(true);

    CusRefreshLocationComboList();
    CusRefreshRSTimeComboList();
    CusRefreshWTimeComboList();

    ui->cusPULocCoBox->setCurrentIndex(0);
    ui->cusDLocCoBox->setCurrentIndex(0);
    ui->cusRSTimeCoBox->setCurrentIndex(0);
    ui->cusWTimeCoBox->setCurrentIndex(0);

    ui->cusConfirmBtn->setEnabled(true);
    ui->cusCancelBtn->setEnabled(true);
    ui->vehConfirmBtn->setText("Confirm Request");


}

void PrimeUI::on_cusCancelReqBtn_clicked()
{
    cusCellSelected=false;
    mCusMode = QString("dereq");
    ui->cusIdEdit->setText(QString("%1").arg(mCusClickedId));
    ui->cusTableWidget->clearSelection();
    ui->cusTableWidget->setEnabled(false);
    ui->cusReqBtn->setEnabled(false);
    ui->cusCancelReqBtn->setEnabled(false);
    ui->cusChgReqBtn->setEnabled(false);
    ui->cusConfirmBtn->setEnabled(true);
    ui->cusCancelBtn->setEnabled(true);
    ui->cusConfirmBtn->setText("Confirm\nCancel Request");
}

void PrimeUI::on_cusChgReqBtn_clicked()
{
    CusRefreshLocationComboList();
    CusRefreshRSTimeComboList();
    CusRefreshWTimeComboList();

    cusCellSelected=false;
    mCusMode=QString("chgreq");

    ui->cusDemandsChBox->setEnabled(true);
    ui->cusPULocChBox->setEnabled(true);
    ui->cusDLocChBox->setEnabled(true);
    ui->cusRSTimeChBox->setEnabled(true);
    ui->cusWTimeChBox->setEnabled(true);

    ui->cusIdEdit->setText(QString("%1").arg(mCusClickedId));
    ui->cusDemandsSpBox->setValue(mCusRequesteds.value(mCusClickedId).value("demand"));
    ui->cusPULocCoBox->setCurrentIndex(
                ui->cusPULocCoBox->findText(QString("%1").arg(mCusRequesteds.value(mCusClickedId).value("ploc")/*mCusPUDLocs.value(mCusClickedId).first*/)));
    ui->cusDLocCoBox->setCurrentIndex(
                ui->cusDLocCoBox->findText(QString("%1").arg(mCusRequesteds.value(mCusClickedId).value("dloc")/*mCusPUDLocs.value(mCusClickedId).second*/)));
    ui->cusRSTimeCoBox->setCurrentIndex(
                ui->cusRSTimeCoBox->findText(QString("%1").arg(mCusRequesteds.value(mCusClickedId).value("reqtime")/60/*mCusRWTimes.value(mCusClickedId).first/60*/)));
    ui->cusWTimeCoBox->setCurrentIndex(
                ui->cusWTimeCoBox->findText(QString("%1").arg(mCusRequesteds.value(mCusClickedId).value("wtime")/60/*mCusRWTimes.value(mCusClickedId).second/60*/)));
    ui->cusTableWidget->clearSelection();
    ui->cusTableWidget->setEnabled(false);
    ui->cusReqBtn->setEnabled(false);
    ui->cusCancelBtn->setEnabled(true);
    ui->cusConfirmBtn->setEnabled(true);
    ui->cusConfirmBtn->setText("Confirm\nChange Request");


}

void PrimeUI::on_cusConfirmBtn_clicked()
{
    qint64 tCusId = ui->cusIdEdit->text().toLongLong();

    if(mCusMode=="req")
    {
        if(!ui->cusIdEdit->text().isEmpty() && ui->cusIdEdit->text().data()->isNumber() && ui->cusIdEdit->text().toInt()>0 &&
                !ui->cusDemandsSpBox->text().isEmpty() && ui->cusDemandsSpBox->value()>=0 && ui->cusDemandsSpBox->text().data()->isNumber() &&
                !ui->cusPULocCoBox->currentText().isNull() &&
                !ui->cusDLocCoBox->currentText().isNull() &&
                ui->cusPULocCoBox->currentText() != ui->cusDLocCoBox->currentText() &&
                //                !ui->cusRTimeCoBox->currentText().isNull() &&
                !ui->cusWTimeCoBox->currentText().isNull())
        {
            //            qint64 tDemand = ui->cusDemandsSpBox
            QHash<QString, qint64> tHash;
            tHash.insert("demand",ui->cusDemandsSpBox->text().toLongLong());
            tHash.insert("ploc",ui->cusPULocCoBox->currentText().toLongLong());
            tHash.insert("dloc",ui->cusDLocCoBox->currentText().toLongLong());
            tHash.insert("reqtime",ui->cusRSTimeCoBox->currentText().toLongLong()*60+mpDb->getSimTime());
            tHash.insert("wtime",ui->cusWTimeCoBox->currentText().toLongLong()*60);
            tHash.insert("puflag",0);
            CusRequestByUI(tCusId,tHash);
        }else
        {
            QMessageBox::warning(this,"Customer Request","Parameters Invalid",QMessageBox::Ok);
        }
    }else if(mCusMode=="dereq")
    {
        CusDerequestByUI(tCusId);
    }else if(mCusMode=="chgreq")
    {
        if(!ui->cusIdEdit->text().isEmpty() && ui->cusIdEdit->text().data()->isNumber() && ui->cusIdEdit->text().toInt()>0 &&
                !ui->cusDemandsSpBox->text().isEmpty() && ui->cusDemandsSpBox->value()>=0 && ui->cusDemandsSpBox->text().data()->isNumber() &&
                !ui->cusPULocCoBox->currentText().isNull() &&
                !ui->cusDLocCoBox->currentText().isNull() &&
                ui->cusPULocCoBox->currentText() != ui->cusDLocCoBox->currentText() &&
                //                !ui->cusRTimeCoBox->currentText().isNull() &&
                !ui->cusWTimeCoBox->currentText().isNull())
        {
            //            qint64 tDemand = ui->cusDemandsSpBox
            QHash<QString, qint64> tHash;
            tHash.insert("demand",ui->cusDemandsSpBox->text().toLongLong());
            tHash.insert("ploc",ui->cusPULocCoBox->currentText().toLongLong());
            tHash.insert("dloc",ui->cusDLocCoBox->currentText().toLongLong());
            tHash.insert("reqtime",ui->cusRSTimeCoBox->currentText().toLongLong()*60+mpDb->getSimTime()/*mCusRequesteds.value(tCusId).value("reqtime")-mCusRWTimes.value(tCusId).first*/);
            tHash.insert("wtime",ui->cusWTimeCoBox->currentText().toLongLong()*60);
            CusChgRequestByUI(tCusId,tHash);
        }else
        {
            QMessageBox::warning(this,"Customer Change Request","Parameters Invalid",QMessageBox::Ok);
        }
    }
    CusResetInterface();
    //    refreshCusTableWidget();
}

void PrimeUI::on_cusCancelBtn_clicked()
{
    CusResetInterface();
}

void PrimeUI::on_cusTableWidget_cellClicked(int row, int column)
{

    ui->cusTableWidget->selectRow(row);
    if(row>0)
    {
        cusCellSelected=true;
        mCusClickedId = ui->cusTableWidget->item(row,0)->text().toLongLong();
        ui->cusCancelReqBtn->setEnabled(true);
        ui->cusChgReqBtn->setEnabled(true);

        mpMapView->focusOnItem("cus",mCusClickedId);
    }else
    {
        cusCellSelected=false;
        ui->cusReqBtn->setEnabled(true);
        ui->cusCancelReqBtn->setEnabled(false);
        ui->cusChgReqBtn->setEnabled(false);

        mCusClickedId=0;
        mpMapView->clearFocus();
    }
}

void PrimeUI::on_cusTableWidget_itemSelectionChanged()
{
    if(ui->cusTableWidget->selectedItems().isEmpty() &&
            cusCellSelected &&
            ui->primaryStackedWidget->currentIndex()==3)
    {
        cusCellSelected=false;
        ui->cusReqBtn->setEnabled(true);
        ui->cusCancelReqBtn->setEnabled(false);
        ui->cusChgReqBtn->setEnabled(false);

        mCusClickedId=0;
        mpMapView->clearFocus();
    }
}

void PrimeUI::on_cusDemandsChBox_toggled(bool checked)
{
    if(checked)
    {
        ui->cusDemandsSpBox->setEnabled(true);
    }else
    {
        ui->cusDemandsSpBox->setEnabled(false);
    }
}

void PrimeUI::on_cusPULocChBox_toggled(bool checked)
{
    if(checked)
    {
        ui->cusPULocCoBox->setEnabled(true);
    }else
    {
        ui->cusPULocCoBox->setEnabled(false);
    }
}

void PrimeUI::on_cusDLocChBox_toggled(bool checked)
{
    if(checked)
    {
        ui->cusDLocCoBox->setEnabled(true);
    }else
    {
        ui->cusDLocCoBox->setEnabled(false);
    }
}

void PrimeUI::on_cusRSTimeChBox_toggled(bool checked)
{
    if(checked)
    {
        ui->cusRSTimeCoBox->setEnabled(true);
        ui->cusRSTimeMinLabel->setEnabled(true);
    }else
    {
        ui->cusRSTimeCoBox->setEnabled(false);
        ui->cusRSTimeMinLabel->setEnabled(false);
    }
}

void PrimeUI::on_cusWTimeChBox_toggled(bool checked)
{
    if(checked)
    {
        ui->cusWTimeCoBox->setEnabled(true);
        ui->cusWTimeMinLabel->setEnabled(true);
    }else
    {
        ui->cusWTimeCoBox->setEnabled(false);
        ui->cusWTimeMinLabel->setEnabled(false);
    }
}

//void PrimeUI::on_cusRefreshBtn_clicked()
//{

//}

//Evt Manager
void PrimeUI::on_evtManBtn_clicked()
{
    resetAllViews();
    ui->primaryStackedWidget->setCurrentIndex(4);
    refreshEvtVehTableWidget();
    refreshEvtJobsTableWidget();
    refreshEvtCusAnsTableWidget();
    refreshEvtLogTableWidget();
    mpMapView->SwitchView("evt");
}

void PrimeUI::on_evtVehArrBtn_clicked()
{
    //    qint64 tCusId = mEvtJobClickedHash.value("cus");
    if(ui->evtJobsTableWidget->rowCount()>1)
    {
        QList<QHash<QString,qint64>> tCacheList;

        QHash<QString,qint64> tHead;

        qint64 tCusId = ui->evtJobsTableWidget->item(1,4)->text().toLongLong();
        qint64 tDemand = ui->evtJobsTableWidget->item(1,3)->text().toLongLong();/*mEvtJobClickedHash.value("demand");*/
        qint64 tLocId = ui->evtJobsTableWidget->item(1,0)->text().toLongLong();

        tHead.insert("cusid",tCusId);
        tHead.insert("demand",tDemand);

        tCacheList.append(tHead);

        if(ui->evtJobsTableWidget->rowCount()>2)
        {
            for(int i = 2; i < ui->evtJobsTableWidget->rowCount(); ++i)
            {
                qint64 ttLocId = ui->evtJobsTableWidget->item(i,0)->text().toLongLong();
                if(ttLocId==tLocId)
                {
                    qint64 tOpenTime = ui->evtJobsTableWidget->item(i,1)->text().toLongLong();

                    if(tOpenTime < mpDb->getSimTime())
                    {
                        qint64 ttCusId = ui->evtJobsTableWidget->item(i,4)->text().toLongLong();
                        qint64 ttDemand = ui->evtJobsTableWidget->item(i,3)->text().toLongLong();

                        QHash<QString,qint64> tNode;
                        tNode.insert("cusid",ttCusId);
                        tNode.insert("demand",ttDemand);

                        tCacheList.append(tNode);
                    }else
                    {
                        break;
                    }
                }
            }
        }

        //iterative
        int sizeOfList = tCacheList.size();
        for(QHash<QString,qint64> tNode : tCacheList)
        {
            EvtVehicleArrive(mEvtVehClickedId,sizeOfList,tNode.value("cusid"),tNode.value("demand"));
        }



        ui->evtVehArrBtn->setEnabled(false);
        ui->evtVehBTDBtn->setEnabled(false);
        ui->evtVehTableWidget->clearSelection();

        emit ui->evtVehTableWidget->itemSelectionChanged();
    }

    //0907: this should be modified to triger multiple job arrival event happening at the same place during the same time
    //need to send a parameter to indicate the number of job entered in order to wait for the last one to be processed and return
    //the final waiting time for only once.
}

void PrimeUI::on_evtVehBTDBtn_clicked()
{
    EvtVehicleBackToDepot(mEvtVehClickedId);
    ui->evtVehArrBtn->setEnabled(false);
    ui->evtVehBTDBtn->setEnabled(false);
    ui->evtVehTableWidget->clearSelection();
    emit ui->evtVehTableWidget->itemSelectionChanged();
}

void PrimeUI::on_evtSetCurTimeBtn_clicked()
{
    if(!settingCurrentTime)
    {
        ui->evtResetTimeBtn->setEnabled(true);
        ui->evtHourSpBox->setEnabled(true);
        ui->evtMinuteSpBox->setEnabled(true);
        ui->evtSecondSpBox->setEnabled(true);
        ui->evtSimTimeSpBox->setEnabled(true);
        settingCurrentTime = true;
    }else
    {
        //        EvtResetInterface();
        EvtResetCurTime();
        settingCurrentTime = false;
    }
}

void PrimeUI::on_evtHourSpBox_editingFinished()
{
    evtCurTimeMode=1;
    ui->evtHourSpBox->clearFocus();
    ui->evtSimTimeSpBox->setEnabled(false);
    ui->evtConfirmCurTimeBtn->setEnabled(true);
}

void PrimeUI::on_evtMinuteSpBox_editingFinished()
{
    evtCurTimeMode=1;
    ui->evtMinuteSpBox->clearFocus();
    ui->evtSimTimeSpBox->setEnabled(false);
    ui->evtConfirmCurTimeBtn->setEnabled(true);
}

void PrimeUI::on_evtSecondSpBox_editingFinished()
{
    evtCurTimeMode=1;
    ui->evtSecondSpBox->clearFocus();
    ui->evtSimTimeSpBox->setEnabled(false);
    ui->evtConfirmCurTimeBtn->setEnabled(true);
}

void PrimeUI::on_evtSimTimeSpBox_editingFinished()
{
    evtCurTimeMode=2;
    ui->evtHourSpBox->setEnabled(false);
    ui->evtMinuteSpBox->setEnabled(false);
    ui->evtSecondSpBox->setEnabled(false);
    ui->evtConfirmCurTimeBtn->setEnabled(true);
}

void PrimeUI::on_evtConfirmCurTimeBtn_clicked()
{
    qint64 tSimTime;
    if(evtCurTimeMode==1)
    {
        qint64 tHour = ui->evtHourSpBox->value();
        qint64 tMin = ui->evtMinuteSpBox->value();
        qint64 tSec = ui->evtSecondSpBox->value();
        if(tHour>=mpDb->getStartHour() && tHour<mpDb->getEndHour())
        {
            tSimTime = (tHour-mpDb->getStartHour())*3600 + tMin*60 + tSec;
            EvtSetCurTimeBySimTime(tSimTime);
        }else
        {
            QMessageBox::warning(this,"Set Current Time","Time Execeed The Range",
                                 QMessageBox::Ok);
        }
    }else
    {
        tSimTime = ui->evtSimTimeSpBox->value();
        if(tSimTime>0 && tSimTime < (mpDb->getEndHour()-mpDb->getStartHour())*3600)
        {
            EvtSetCurTimeBySimTime(tSimTime);
        }
    }
    on_evtSetCurTimeBtn_clicked();
}

void PrimeUI::on_evtVehTableWidget_itemSelectionChanged()
{
    if(ui->evtVehTableWidget->selectedItems().isEmpty() &&
            evtVehCellSelected &&
            ui->primaryStackedWidget->currentIndex()==4)
    {
        evtVehCellSelected=false;
        ui->evtVehArrBtn->setEnabled(false);
        ui->evtVehBTDBtn->setEnabled(false);
        mEvtVehClickedId=0;
        mpMapView->clearFocus();
        refreshEvtJobsTableWidget();
    }else{
        //        ui->evtVehTableWidget->selectRow(ui->evtVehTableWidget->currentRow());
        int row = ui->evtVehTableWidget->currentRow();
        if(row>0)
        {
            evtVehCellSelected=true;
            mEvtVehClickedId = ui->evtVehTableWidget->item(row,0)->text().toLongLong();
            ui->evtVehArrBtn->setEnabled(true);
            ui->evtVehBTDBtn->setEnabled(true);
            mpMapView->focusOnItem("veh",mEvtVehClickedId);
            refreshEvtJobsTableWidget();
        }else
        {
            evtVehCellSelected=false;
            ui->evtVehArrBtn->setEnabled(false);
            ui->evtVehBTDBtn->setEnabled(false);
            mEvtVehClickedId=0;
            mpMapView->clearFocus();
            refreshEvtJobsTableWidget();
        }
    }
}

void PrimeUI::on_evtJobsTableWidget_itemSelectionChanged()
{
    //    if(ui->evtJobsTableWidget->selectedItems().isEmpty() &&
    //            evtJobCellSelected &&
    //            ui->primaryStackedWidget->currentIndex()==4)
    //    {
    //        evtJobCellSelected=false;
    //        mEvtJobClickedHash.clear();
    //        ui->evtVehArrBtn->setEnabled(false);
    //    }else
    //    {
    //        ui->evtJobsTableWidget->selectRow(ui->evtJobsTableWidget->currentRow());
    //        int row = ui->evtJobsTableWidget->currentRow();
    //        if(row>0)
    //        {
    //            evtJobCellSelected=true;
    //            mEvtJobClickedHash.clear();
    //            mEvtJobClickedHash.insert("cus",ui->evtJobsTableWidget->item(row,4)->text().toLongLong());
    //            mEvtJobClickedHash.insert("demand",ui->evtJobsTableWidget->item(row,3)->text().toLongLong());
    //            ui->evtVehArrBtn->setEnabled(true);
    //        }else
    //        {
    //            evtJobCellSelected=false;
    //            mEvtJobClickedHash.clear();
    //            ui->evtVehArrBtn->setEnabled(false);
    //        }
    //    }
}

void PrimeUI::on_evtCusAnsTableWidget_itemSelectionChanged()
{
    if(ui->evtCusAnsTableWidget->selectedItems().isEmpty() &&
            evtCusCellSelected &&
            ui->primaryStackedWidget->currentIndex()==4)
    {
        evtCusCellSelected=false;
        ui->evtCusAnsAcceptBtn->setEnabled(false);
        ui->evtCusAnsRefuseBtn->setEnabled(false);
        mEvtCusClickedId=0;
    }else
    {
        ui->evtCusAnsTableWidget->selectRow(ui->evtCusAnsTableWidget->currentRow());
        int row = ui->evtCusAnsTableWidget->currentRow();
        if(row>0)
        {
            evtCusCellSelected=true;
            mEvtCusClickedId = ui->evtCusAnsTableWidget->item(row,0)->text().toLongLong();
            ui->evtCusAnsAcceptBtn->setEnabled(true);
            if(ui->evtCusAnsTableWidget->item(row,3)->text()==QString("PU"))
                ui->evtCusAnsRefuseBtn->setEnabled(true);
        }else
        {
            evtCusCellSelected=false;
            ui->evtCusAnsAcceptBtn->setEnabled(false);
            ui->evtCusAnsRefuseBtn->setEnabled(false);
            mEvtCusClickedId=0;
        }
    }
}

void PrimeUI::on_evtCusAnsAcceptBtn_clicked()
{
    qint64 tAssignedVehId = ui->evtCusAnsTableWidget->item(ui->evtCusAnsTableWidget->currentRow(),1)->text().toLongLong();

    QString type = ui->evtCusAnsTableWidget->item(ui->evtCusAnsTableWidget->currentRow(),3)->text();

    if(type==QString("PU"))
        EvtCustomerAnsPickUp(tAssignedVehId,mEvtCusClickedId,"yes");
    else if(type==QString("DL"))
        EvtCustomerAnsDelivery(tAssignedVehId,mEvtCusClickedId,"yes");

    ui->evtCusAnsTableWidget->removeRow(ui->evtCusAnsTableWidget->currentRow());
    ui->evtCusAnsAcceptBtn->setEnabled(false);
    ui->evtCusAnsRefuseBtn->setEnabled(false);
    ui->evtCusAnsTableWidget->clearSelection();
    emit ui->evtCusAnsTableWidget->itemSelectionChanged();
}

void PrimeUI::on_evtCusAnsRefuseBtn_clicked()
{
    qint64 tAssignedVehId = ui->evtCusAnsTableWidget->item(ui->evtCusAnsTableWidget->currentRow(),1)->text().toLongLong();
    //    EvtCustomerAnsPickUp(tAssignedVehId,mEvtCusClickedId,"no");

    QString type = ui->evtCusAnsTableWidget->item(ui->evtCusAnsTableWidget->currentRow(),3)->text();

    if(type==QString("PU")){

        EvtCustomerAnsPickUp(tAssignedVehId,mEvtCusClickedId,"no");


        ui->evtCusAnsTableWidget->removeRow(ui->evtCusAnsTableWidget->currentRow());
        ui->evtCusAnsAcceptBtn->setEnabled(false);
        ui->evtCusAnsRefuseBtn->setEnabled(false);
        ui->evtCusAnsTableWidget->clearSelection();
        emit ui->evtCusAnsTableWidget->itemSelectionChanged();
    }else
    {

    }
}

void PrimeUI::on_evtResetTimeBtn_clicked()
{
    //set diff = 0;
    mpDb->setTimeDiffToZero();
    EvtResetCurTime();
}


//void PrimeUI::on_evtVehRefreshBtn_clicked()
//{

//}

//void PrimeUI::on_evtJobsRefreshBtn_clicked()
//{

//}

//void PrimeUI::on_evtCusAnsRefreshBtn_clicked()
//{

//}

//void PrimeUI::on_evtLogRefreshBtn_clicked()
//{

//}

void PrimeUI::on_resetBtn_clicked()
{
    QMessageBox msgBox;
    msgBox.setText("Reset Everything?");
    msgBox.setStandardButtons(QMessageBox::Ok|QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Cancel);
    int ret = msgBox.exec();

    switch (ret) {
    case QMessageBox::Ok:
        //
        resetEverything();
        break;
    case QMessageBox::Cancel:
        //
        break;
    default:
        //should never be reached
        break;
    }

}
