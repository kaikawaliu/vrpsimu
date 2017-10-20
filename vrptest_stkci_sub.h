#ifndef VRPTEST_STKCI_SUB_H
#define VRPTEST_STKCI_SUB_H

#include <QObject>
//#include <QHash>
#include <QDebug>
#include <QTimer>

#include "cusconfirmdialog.h"

#include "Interfaces/ExampleMainMsgSubInterface.h"
#include "Interfaces/STKCIEXampleMsgfunc.h"
#include "Interfaces/STKCIEXampleMsgsupport.h"
#include "STKCI/stkci_Utils.h"
#include "STKCI/stkci_CommonTime.h"

#include "STKCI/stkci_tree_node.h"
#include "STKCI/stkci_xml_parser.h"

class vrptest_stkci_sub : public QObject
{
    Q_OBJECT
public:
    explicit vrptest_stkci_sub(QObject *parent = 0);

    void setup();
    void close();



signals:
    void sendCusConfirmAns(qint64 aVehId, qint64 aCusId, QString aAnsStr);

    void createArrAnsDialogSignal(qint64 aVehId, qint64 aCusId, qint64 aWaitTime);
    void deleteArrAnsDialogSignal(qint64 aVehId, qint64 aCusId);
public slots:
    void starttimerslot(){starttimer();}
    void listen();

    void rcvCusAnsArrival(qint64 aVehId,qint64 aCusId,QString aAnsStr);

private:
    std::string mProfile = "VRPImpPub";
    qint64 mKeyId = 21;
    STKCI::ExampleMainMsgSubInterface mSubInterface;

    bool gGlobalTerminate = false;

    QHash<qint64,QHash<QString,QString>> mVehicleRegSeq;

    void print(QString aString);

    void starttimer();

//    QHash<QPair<qint64,qint64>,cusconfirmdialog*> mCusDialogHash;
};

#endif // VRPTEST_STKCI_SUB_H

//I think there should be a timer to timing the cus answer pickup event
//time set to the waiting time
//timeout = delete dialog and automatically reply reject
//this counting should be in VRP
//do this after finish bridging the communication of ans arrival
