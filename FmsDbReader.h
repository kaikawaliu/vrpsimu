#ifndef FMSDBREADER_H
#define FMSDBREADER_H

#include <iostream>

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QTimer>
#include <QHash>
#include <QDebug>

#include <string>

#include "STKCI/stkci_Utils.h"
#include "STKCI/stkci_CommonTime.h"

#include "STKCI/stkci_xml_parser.h"
#include "STKCI/stkci_tree_node.h"

static const std::string gVRPFMSConfigFile = "VRPTestConfigurables.xml";

class FMSDbReader : public QObject
{
    Q_OBJECT
public:
    explicit FMSDbReader(QObject *parent = 0);

    void Initialization();
signals:
    void SendAddVehStatusByFMS(qint64 aVehId, qint64 aCapacity, double aSpeed);
    void SendUpdateVehStatusByFMS(qint64 aVehId, QString aType, QString aValue);
//    void SendUpdateVehCapacityByFMS(qint64 aVehId, qint64 aCapacity);
//    void SendUpdateVehSpeedByFMS(qint64 aVehId, qint64 aSpeed);
    void SendDeleteVehStatusByFMS(qint64 aVehId);

    void SendAddVehLLByFMS(qint64 aVehId, double aLat, double aLong);
    void SendDeleteVehLLByFMS(qint64 aVehId);
    void SendUpdateVehLLByFMS(qint64 aVehId, double aLat, double aLong);

    void SendDeleteVehByFMS(qint64 aVehId);

    void SendAddLandmarkByFMS(qint64 aLandmarkId, double aLat, double aLong);
    void SendUpdateLandmarkByFMS(qint64 aLandmarkId, double aLat, double aLong);
    void SendDeleteLandmarkByFMS(qint64 aLandmarkId);

    //0907:
    //
    //!fms report arrive msg->*
    //vrpi get arrive msg->
    //vrpi send arrive msg to vrpc->
    //vrpc get arrve msg->
    //vrpc send can pickup event to vpri->
    //vrpc send waiting time to to fms->*
    //vrpi send reply to pickup event to vprc->
    //vrpc count the replies until meeting the number of sent request
    //vrpc trigger moving to fms->!*
    //
    //*
    //should also be functions to scan and reply for options event such as:
    //1. get the arrival event from vehicle
    //2. get the waiting time to vehicle
    //3. trigger the vehicle to move
    //share for pick and drop
    //4. entering depot (for resetting launch cost)
    //
    //question: what if pick and drop happen at same time
    //answer: it's handled already in vehicle AVehicleArrived function

public slots:
    void sendWaitingTimeToFMS(qint64 aVehId, qint64 aWaitingTime);
    void triggerVehicleMoving(qint64 aVehId);

private slots:
    void scanSummary();

private:
    //Funcs:


    void parseConfigurables();

    void scanAgentInfo();
    void scanAgentLocal();

    void scanLandmark();

    void scanAgentEvent();//Not Ready

    void deleteAgent(qint64 aAgentId);

    void AddAgentStatusIntoVRP(qint64 aAgentId);
    void UpdateAgentStatusIntoVRP(qint64 aAgentId,QString aType);
//    void UpdateAgentCapacityIntoVRP(qint64 aAgentId);
//    void UpdateAgentSpeedIntoVRP(qint64 aAgentId);
    void DeleteAgentStatusFromVRP(qint64 aAgentId);

    void AddAgentLocalIntoVRP(qint64 aAgentId, double aLat, double aLong);
    void DeleteAgentLocalFromVRP(qint64 aAgentId);
    void UpdateAgentLocalInVRP(qint64 aAgentId, double aLat, double aLong);

    void DeleteAgentInVRP(qint64 aAgentId);

    void AddLandmarkIntoVRP(qint64 aLandmarkId, QPair<double,double> aPos);
    void UpdateLandmarkInVRP(qint64 aLandmarkId, QPair<double,double> aPos);
    void DeleteLandmarkFromVRP(qint64 aLandmarkId);

    QPair<double,double> ConvertUTMtoLL(QPair<double,double> aUTMPos);

    //Params
    qint64 mAgentGroup;
    qint64 mLandmarkGroup;

    QSqlDatabase *db;
    QSqlQuery* query;

    QString mHostName;
    QString mPort;
    QString mDatabaseName;
    QString mUserName;
    QString mPassword;

    QTimer* scanTimer;

    QHash<qint64, qint64> mAgentInfoTimeStamps;
    QList<qint64> mReadyAgents;
    QHash<qint64,QHash<QString,QString>> mAgentsStatus;
    QHash<qint64,QPair<double,double>> mLandmarkPos;
    QList<qint64> tAgentStatusRegisters;
    QList<QPair<qint64,QString>> tAgentStatusUpdates;
//    QList<qint64> tAgentCapacityUpdates;
//    QList<qint64> tAgentSpeedUpdates;
    QHash<qint64, qint64> mAgentLocalTimeStamps;

    QHash<qint64, qint64> mLandmarkTimeStamps;
};

#endif // FMSDBREADER_H
