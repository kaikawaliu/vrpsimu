#include "cusconfirmdialog.h"
#include "ui_cusconfirmdialog.h"

cusconfirmdialog::cusconfirmdialog(qint64 aVehId, qint64 aCusId, qint64 aWaitTime, QWidget *parent) :
    mVehId(aVehId),
    mCusId(aCusId),
    mWaitTime(aWaitTime),
    QDialog(parent),
    ui(new Ui::cusconfirmdialog)
{
    qDebug()<<"creating new dialog";




    ui->setupUi(this);
    ui->vidLabel->setText(QString("%1").arg(mVehId));
    ui->cidLabel->setText(QString("%1").arg(mCusId));
    ui->wtimeLabel->setText(QString("%1").arg(mWaitTime));
//    qDebug()<<"finish set label";
//    this->show();
}

void cusconfirmdialog::showUp()
{
    this->show();
}

void cusconfirmdialog::hideShow()
{
    this->hide();
}

cusconfirmdialog::~cusconfirmdialog()
{
    delete ui;
}

void cusconfirmdialog::on_confirmBtn_clicked()
{
    emit CusAnsPickup(mVehId,mCusId,"yes");
}

void cusconfirmdialog::on_rejectBtn_clicked()
{
    emit CusAnsPickup(mVehId,mCusId,"no");
}
