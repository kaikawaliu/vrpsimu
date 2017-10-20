#ifndef TESTWINDOW_H
#define TESTWINDOW_H

#include <QMainWindow>

#include "primeui.h"
#include "vrptest_db.h"
//#include "vrptest_stkci_pub.h"
//#include "vrptest_stkci_sub.h"
#include "vrptest_db_pub.h"
#include "vrptest_db_sub.h"
#include "cusconfirmdialog.h"
#include "ClientDBController.h"

#include <QSqlDatabase>
#include <QThread>

namespace Ui {
class TestWindow;
}

class TestWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit TestWindow(QWidget *parent = 0);
    ~TestWindow();

private slots:
//    void on_loc_register_btn_clicked();

//    void on_loc_deregister_btn_clicked();

//    void on_loc_update_btn_clicked();

//    void on_veh_register_btn_clicked();

//    void on_veh_deregister_btn_clicked();

//    void on_veh_latlong_btn_clicked();

//    void on_veh_capacity_btn_clicked();

//    void on_veh_speed_btn_clicked();

//    void on_veh_rftime_btn_clicked();

//    void on_veh_ftime_btn_clicked();

//    void on_veh_utime_btn_clicked();

//    void on_veh_btime_btn_clicked();

//    void on_veh_depot_btn_clicked();

//    void on_veh_lcost_btn_clicked();

//    void on_clean_veh_btn_clicked();

//    void on_cus_register_btn_clicked();

//    void on_cus_deregister_btn_clicked();

//    void on_cus_chgreg_btn_clicked();

//    void on_evt_arrive_btn_clicked();

//    void createArrAnsDialog(qint64 aVehId, qint64 aCusId, qint64 aWaitingTime);

//    void rcvCusAnsArrival(qint64 aVehId, qint64 aCusId, QString aAnsStr);

//    void on_evt_curTime_btn_clicked();

//    void deleteArrAnsDialogSlot(qint64 aVehId, qint64 aCusId);

//    void on_pushButton_clicked();

signals:
    void starttimersignal();

    void sendCusConfirmAns(qint64 aVehId,qint64 aCusId,QString aAnsStr);


private:
    Ui::TestWindow *ui;

    QSqlDatabase* mDB;

    vrptest_db* mpDb;
//    vrptest_stkci_pub* mpPub;
//    vrptest_stkci_sub* mpSub;
//    ClientPublisher* mpClientPub;
//    ClientSubscriber* mpClientSub;
    ClientDBController* mpClientDBController;
    QThread thDBController;

//    QThread thRcv;
    PrimeUI* pui;

    QHash<QPair<qint64,qint64>,cusconfirmdialog*> mCusDialogHash;
};

#endif // TESTWINDOW_H
