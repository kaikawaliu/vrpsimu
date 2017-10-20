#ifndef VRPTEST_STKCI_PUB_H
#define VRPTEST_STKCI_PUB_H

#include <QObject>
#include <QDebug>
#include <QTimer>

#include "Interfaces/ExampleMainMsgPubInterface.h"
#include "Interfaces/STKCIEXampleMsgfunc.h"
#include "Interfaces/STKCIEXampleMsgsupport.h"
#include "STKCI/stkci_Utils.h"
#include "STKCI/stkci_CommonTime.h"

#include "STKCI/stkci_tree_node.h"
#include "STKCI/stkci_xml_parser.h"

//#include

class vrptest_stkci_pub : public QObject
{
    Q_OBJECT
public:
    explicit vrptest_stkci_pub(QObject *parent = 0);

    void setup();
    void close();
    void cleanMsg();

    void VehRegister(qint64 aVehId, qint64 aDepot, qint64 aCapacity, double aSpeed, qint64 aRefuelTime,
                     qint64 aFixTime, qint64 aUnitTime, qint64 aBufferTime, qint64 aLaunchCost);
    void VehDeregister(qint64 aVehId);

    void VehSetDepot(qint64 aVehId, qint64 aDepot);
    void VehSetCapacity(qint64 aVehId, qint64 aCapacity);
    void VehSetSpeed(qint64 aVehId, double aSpeed);
    void VehSetRefuelTime(qint64 aVehId, qint64 aRefuelTime);
    void VehSetFixTime(qint64 aVehId, qint64 aFixTime);
    void VehSetUnitTime(qint64 aVehId, qint64 aUnitTime);
    void VehSetBufferTime(qint64 aVehId, qint64 aBufferTime);
    void VehSetLaunchCost(qint64 aVehId, qint64 aLaunchCost);

    void CusRequest(qint64 aCusId, qint64 aDemand, qint64 aPickupLoc, qint64 aDeliveryLoc, qint64 aReqTime, qint64 aWaitTime);
    void CusDerequest(qint64 aCusId);
    void CusChgReq(qint64 aCusId, qint64 aDemand, qint64 aPickupLoc, qint64 aDeliveryLoc, qint64 aReqTime, qint64 aWaitTime);

    void OnArrivalEvent(qint64 aVehId, qint64 aCusId, qint64 aDemand);
    void CusAnsPickup(qint64 aCusId, qint64 aVehId, QString aAns);
    void SetCurrentTime(qint64 aCurTime);
signals:

public slots:
    void RcvCusConfirmAns(qint64 aVehId, qint64 aCusId, QString aAnsStr);

private slots:
    void loopMsg();

private:
    std::string mProfile = "VRPImpSub";
    qint64 mKeyId = 22;
    STKCI::ExampleMainMsgPubInterface mPubInterface;
    STKCI::ExampleMainMsg mMessage;

    void pubMsg();
    void PrintMessage(const STKCI::ExampleMainMsg& aMessage);
    void startSendingMsg();
};

#endif // VRPTEST_STKCI_PUB_H
