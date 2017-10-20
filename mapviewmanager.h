#ifndef MAPVIEWMANAGER_H
#define MAPVIEWMANAGER_H

//ZValue:
//Background: 0
//Location: 1 Mon(6)
//CusLines/Text: 2 Mon(7)
//Customer: 3 Mon(8)
//VehLines: 4
//Vehicle: 5

#include <QObject>
#include <QGraphicsView>
#include <QDebug>

#include "mapviewobjects.h"

class MapViewManager : public QObject
{
    Q_OBJECT
public:
    explicit MapViewManager(QGraphicsView* apView,QObject *parent = 0);

    void SwitchView(QString aViewStr);
    void SwitchMonPage(int index);
    void resetZValues();
    void focusOnItem(QString aViewStr, qint64 aId);
    void clearFocus();
    void focusUpdate(QString aViewStr, qint64 aId, QList<QPair<qint64, qint64> > aPosList);
    void enterGetLLMode(){inGetLLMode=true;}
    void leaveGetLLMode(){inGetLLMode=false;}
    void showCrossHair(QPair<qint64,qint64> aPos);
    void hideCrossHair();


    void EnterInteractiveMode();
    void ExitInteractiveMode();

    //conversion
    QPair<qint64,qint64> CoordToPos(QPair<double,double> aCoord);
    QPair<double,double> PosToCoord(QPair<qint64,qint64> aPos);

    //Loc:
    void RegisterLandmarkInView(qint64 aLocId, QPair<double,double> aLocCoord);
    void DeregisterLandmarkInView(qint64 aLocId);
    void SetLandmarkPosInView(qint64 aLocId, QPair<double,double> aLocCoord);
    //Veh:
    void RegisterVehicleEntityInView(qint64 aVehId,
                                     QPair<double,double> aVehCoord);
    void DeregisterVehicleInView(qint64 aVehId);
    void SetVehPosInView(qint64 aVehId, QPair<double,double> aVehCoord);
    void RescheduleDest(qint64 aVehId, QList<qint64> aDestList);
    //Cus:
    void RegisterRequestInView(qint64 aCusId, qint64 aDemand, QPair<qint64,qint64> aLocIds);
    void DeregisterRequestInView(qint64 aCusId);
    void ApplyChgReqInView(qint64 aCusId, qint64 aDemand, QPair<qint64,qint64> aLocIds);
    //Evt:
    void ApplyArrivalInView(qint64 aVehId);

    bool containsVeh(qint64 aVehId){return mVehEntities.contains(aVehId);}

protected:
//    void mousePressEvent(QGraphicsSceneMouseEvent *event);
//    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
//    void contextMenuEvent(QGraphicsSceneContextMenuEvent *event);

signals:
    void sendMousePressEventToUI(QPair<qint64,qint64> aPos, QPair<double,double> aCoord);
    void sendHoverPosToUI(QPair<qint64,qint64> aPos, QPair<double,double> aCoord);
    void sendHoverLeaveToUI();
    void sendGotLLCoordToUI(QPair<double,double> aCoord);

    void sendPressInMonMode(QString aItemStr, QList<qint64> aIdList);
    void sendPressInLocMode(QHash<qint64,QPair<double,double>> aSelectedLocCoordHash);
    void sendPressInVehMode(QHash<qint64,QPair<double,double>> aSelectedVehCoordHash);
    void sendPressInCusModeForLoc(QList<qint64> aSelectedLocList);
    void sendPressInCusModeForReq(QHash<qint64,bool> aSelectedCusIdPUHash);
    void sendPressInEvtMode(QList<qint64> aSelectedVehIdList);
    void loseSelection();
public slots:
    void getMousePressEvent(QPointF aPressPos);
    void getHoverEnterEvent(QPointF aHoverPos);
    void getHoverMoveEvent(QPointF aHoverPos);
    void getHoverLeaveEvent();

    void getLoseFocus();

private:
    void InitView();
    void updateDisplay();

    QString mViewStr;

    //switch
    void hideAllItems();
    void showMonOrEvt();
    void showLoc();
    void showVeh();
    void showCus();

    QGraphicsView* mpView;
    MapViewBackground* mpMapViewBgd;
//    QGraphicsScene* mpScene;
    MapViewScene* mpScene;

    bool inManMode=false;
    bool inGetLLMode=false;
    bool inHoverMode=false;
    QString mFocusViewStr;
    qint64 mFocusId;

    QHash<qint64,MapViewLandmark*> mLandmarkItems;
    QHash<qint64,MapViewVehicleEntity*> mVehEntities;
    QHash<qint64,MapViewRequestEntity*> mReqEntities;

    QHash<qint64,QPair<qint64,qint64>> mLocsPosHash;

    QList<MapViewFocusCircle*> mFocusCircles;
    MapViewReflectCrossHair* mRefCrossHair;
};

#endif // MAPVIEWMANAGER_H
