#ifndef CUSCONFIRMDIALOG_H
#define CUSCONFIRMDIALOG_H

#include <QDialog>

#include <QDebug>

namespace Ui {
class cusconfirmdialog;
}

class cusconfirmdialog : public QDialog
{
    Q_OBJECT

public:
    explicit cusconfirmdialog(qint64 aVehId, qint64 aCusId, qint64 aWaitTime, QWidget *parent = 0);
    ~cusconfirmdialog();

    void showUp();

    void hideShow();

signals:
    void CusAnsPickup(qint64 aVehId, qint64 aCusId, QString aAnsStr);

private slots:
    void on_confirmBtn_clicked();

    void on_rejectBtn_clicked();

private:
    Ui::cusconfirmdialog *ui;

    qint64 mVehId, mCusId, mWaitTime;
};

#endif // CUSCONFIRMDIALOG_H
