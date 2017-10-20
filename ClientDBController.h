#ifndef CLIENTDBCONTROLLER_H
#define CLIENTDBCONTROLLER_H

#include <QObject>
#include <QTimer>
#include "FMS/DatabaseAccessVRP/VRPMobileCustomerReply.h"
#include "FMS/DatabaseAccessVRP/VRPMobileCustomerRequest.h"
#include "FMS/C2Bridge/FMSC2Enums.h"

class ClientDBController : public QObject
{
    Q_OBJECT
public:
    explicit ClientDBController(QObject *parent = 0);
    bool SetDatabase(const stkfms::DB::GatewayConnection &aConnection);
    bool Connect();
    void Disconnect();

    void Close();
    void StartTimer();

    void SetStartHour(qint64 aStartHour){mStartHour = aStartHour;}

signals:
    void GetAddRequest(qint64 aCusID,
                       QHash<QString,qint64> tHash);
    void GetDelRequest(qint64 aCusID);
    void GetUpdateRequest(qint64 aCusID,
                          QHash<QString,qint64> tHash);
    void GetAnsPUEventRequest(qint64 aCusID,
                              qint64 aVehID,
                              QString aAns);
    void GetAnsDLEventRequest(qint64 aCusID,
                              qint64 aVehID,
                              QString aAns);

private slots:
    void Iteration();

public slots:
    //Add Request
    void AddRequestReply(qint64 aCusID, QString aResult);
    void AddRequestReplyDone(qint64 aCusID,qint64 aVehID);
    //Del Request
    void DelRequestReply(qint64 aCusID, QString aResult);
    void DelRequestReplyDone(qint64 aCusID);
    //Update Request
    void UpdateRequestReply(qint64 aCusID, QString aResult);
    void UpdateRequestReplyDone(qint64 aCusID);
    //Arrival Event

    //Boarding Event
    void TriggerBoardingNotice(qint64 aCusID, qint64 aWaitingTime);
    void ReportExpireForBoarding(qint64 aCusID);
    void fbConfirmBoardingReply(qint64 aCusID, QString aResultStr);
    //Alighting Event
    void TriggerAlightingNotice(qint64 aCusID, qint64 aWaitingTime);
    void ReportExpireForAlighting(qint64 aCusID);
    void fbConfirmAlightingReply(qint64 aCusID, QString aResultStr);//accept/refuse
    //update ETA
    void UpdateETA(qint64 aCusID, QString aOpenTimes);

    void FinishOrder(qint64 aCusID);
private:
//    mutable stkfms::wMutex mAccessMutex;
//    mutable stkfms::wMutex mDBMutex;

    void AddReply(qint64 aCusID,
                  int aType,
                  int aStatus,
                  qint64 aVehID=0,
                  qint64 aETAstart=0,
                  qint64 aETAend=0,
                  QString aReplyData="");

    QTimer* mScanTimer;
    std::shared_ptr<stkfms::DB::VRPMobileCustomerReply> mDBReplyAccess;
    std::shared_ptr<stkfms::DB::VRPMobileCustomerRequest> mDBRequestAccess;

    qint64 mStartHour = 0;
    QList<qint64> mGWCusList;

    bool openInternalReply = false;
};

#endif // CLIENTDBCONTROLLER_H
