#ifndef MAPVIEWOBJECTS_H
#define MAPVIEWOBJECTS_H

#include <QDebug>
#include <QGraphicsView>
#include <QGraphicsObject>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QPainter>

class MapViewObjects
{
public:
    MapViewObjects();
};

class MapViewScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit MapViewScene(QObject *parent=0);

signals:


protected:
//    void mousePressEvent(QGraphicsSceneMouseEvent *event);
//    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);

};

class MapViewBackground: public QGraphicsObject
{
    Q_OBJECT
public:
    MapViewBackground(qint64 aWidth, qint64 aHeight);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QPainterPath shape() const;

    void switchView(QString aViewStr){mViewStr = aViewStr;}
    void enterGetCoordMode();//change cursor style
    void exitGetCoordMode();
    void enableHoverEvent(bool enabled);

signals:
    void sendPressScenePos(QPointF aScenePos);
    void sendHoverEnterEvent(QPointF aScenePos);
    void sendHoverMoveEvent(QPointF aScenePos);
    void sendHoverLeaveEvent();
    void pressInMonMode(QString aItemStr, QList<qint64> aIdList);
    void pressInLocMode(QHash<qint64,QPair<double,double>> aLocIdCoordHash);
    void pressInVehMode(QHash<qint64,QPair<double,double>> aVheIdCoordHash);
    void pressInCusModeForReq(QHash<qint64,bool> aCusIdPUHash);
    void pressInCusModeForLoc(QList<qint64> aLocIdList);
    void pressInEvtMode(QList<qint64> aVehIdList);
    void loseFocus();

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void hoverMoveEvent(QGraphicsSceneHoverEvent *event);
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);//when get coord is activated
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);

private:
    void ExecuteWithMonMode();
    void ExecuteWithLocMode();
    void ExecuteWithVehMode();
    void ExecuteWithCusMode();
    void ExecuteWithEvtMode();

    QString mViewStr;
    qint64 mWidth;
    qint64 mHeight;

    QPixmap* image;

    QPointF mPressPos;
    QPointF mHoverPos;
    QList<QGraphicsItem*> mItems;
};

class MapViewLandmark: public QGraphicsObject
{
    Q_OBJECT
public:
    MapViewLandmark(const qint64 &aLocId,
                    const QPair<qint64,qint64> &aPos,
                    const QPair<double,double> &aCoord,
                    const QColor &color = Qt::green);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QPainterPath shape() const;

    qint64 getLocId() const{return mLocId;}
    QPair<qint64,qint64> getPos() const{return mPos;}
    QPair<double,double> getCoord() const{return mCoord;}

//    void setLocId(const qint64 &aLocId){mLocId = aLocId;}
    void setLocPos(const QPair<qint64,qint64> &aPos){mPos = aPos;  setPos(mPos.first,mPos.second);}
    void setCoord(const QPair<double,double> &aCoord){mCoord = aCoord;}

//    void ExitInteractiveMode();
//    void EnterInteractiveMode();

protected:
//    void mousePressEvent(QGraphicsSceneMouseEvent *event);
//    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
//    void contextMenuEvent(QGraphicsSceneContextMenuEvent *event);

private:
    QColor brushColor;
    qint64 mLocId;
    QPair<qint64,qint64> mPos;
    QPair<double,double> mCoord;
};

class MapViewVehicle: public QGraphicsObject
{
    Q_OBJECT
public:
    MapViewVehicle(const qint64 &aVehId,
                   const QPair<qint64,qint64> &aPos,
                   const QPair<double,double> &aCoord,
                   const QColor &color = Qt::blue);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QPainterPath shape() const;

    qint64 getVehId() const{return mVehId;}
    QPair<qint64,qint64> getPos() const{return mPos;}
    QPair<double,double> getCoord() const{return mCoord;}

//    void setId(const qint64 &aVehId){mVehId = aVehId;}
    void setVehPos(const QPair<qint64,qint64> &aPos){mPos = aPos;  setPos(mPos.first,mPos.second);}
    void setCoord(const QPair<double,double> &aCoord){mCoord = aCoord;}
private:
    int halfSize = 8;
    QColor brushColor;
    qint64 mVehId;
    QPair<qint64,qint64> mPos;
    QPair<double,double> mCoord;
};

class MapViewVehicleTravelLine : public QGraphicsLineItem
{
//    Q_OBJECT
public:
    MapViewVehicleTravelLine(/*const qint64 &aStartId,
                             const qint64 &aEndId,*/
                             const QPair<qint64,qint64> &aLineStartPos,
                             const QPair<qint64,qint64> &aLineEndPos,
                             bool isFirstLine = false,
                             const QColor &color = Qt::blue);

    void setLineStartPos(const QPair<qint64,qint64> &aLineStartPos);
    void setIsFirstLine(){mIsFirstLine = true;}
    bool getIsFirstLine(){return mIsFirstLine;}
//    qint64 getStartId() const{return mStartId;}
//    qint64 getEndId() const{return mEndId;}
private:
    bool mIsFirstLine;
//    qint64 mStartId, mEndId;
    QPair<qint64,qint64> mLineStartPos, mLineEndPos;
    QColor brushColor;
};

class MapViewRequest: public QGraphicsObject
{
    Q_OBJECT
public:
    MapViewRequest(const qint64 &aCusId,
                   const qint64 &aLocId,
                   bool isPickUp,
                   const QPair<qint64,qint64> &aPos);//red for pickup//yellow for delivery
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QPainterPath shape() const;

    qint64 getCusId() const{return mCusId;}
    qint64 getLocId() const{return mLocId;}
    bool getIsPickUp() const{return mIsPickUp;}
    QPair<qint64,qint64> getPos() const{return mPos;}
    QPair<double,double> getCoord() const{return mCoord;}

//    void setCusId(const qint64 &aCusId){mCusId = aCusId;}
    void setLocId(const qint64 &aLocId){mLocId = aLocId;}
    void setReqPos(const QPair<qint64,qint64> &aPos){mPos = aPos; setPos(mPos.first,mPos.second);}
    void setCoord(const QPair<double,double> &aCoord){mCoord = aCoord;}
private:
    int halfSize = 8;
    QColor brushColor;
    bool mIsPickUp;
    qint64 mCusId,mLocId;
    QPair<qint64,qint64> mPos;
    QPair<double,double> mCoord;
};

class MapViewVehicleEntity : public QObject
{
    Q_OBJECT
public:
    explicit MapViewVehicleEntity(const qint64 &aVehId,
                                  const QPair<qint64,qint64> &aVehPos,
                                  const QPair<double,double> &aVehCoord,
                                  QObject *parent=0);

    void setVehPos(QPair<qint64, qint64> aVehPos);
    void setVehCoord(QPair<double,double> aVehCoord);
    void doUpdate();

    void setLinePosList(QList<QPair<qint64,qint64>> aLinePosList);
    void setFirstLineStartPos(QPair<qint64,qint64> aFirstLineStartPos);
    void arrive();

    void setFocusColor(bool isFocused)
    {
        if(isFocused)
        {lineBrushColor=Qt::darkBlue;}
        else
        {lineBrushColor=Qt::gray;}
    }

    MapViewVehicle* mpVehicleItem;
    QList<MapViewVehicleTravelLine*> mTravelLineList;
    QList<QPair<qint64,qint64>> mLinePosList;
private:
    void setTravelLines();

    QColor lineBrushColor=Qt::gray;
    qint64 mVehId;
    QPair<qint64,qint64> mVehPos;
    QPair<double,double> mVehCoord;
};

class MapViewRequestEntity: public QObject
{
    Q_OBJECT
public:
    explicit MapViewRequestEntity(const qint64 &aCusId,
                                  const qint64 &aDemand,
                                  QPair<qint64,qint64> aLocIds,
                                  QPair<qint64,qint64> aFromPos,
                                  QPair<qint64,qint64> aToPos,
                                  QObject *parent=0);

    void setLocIds(QPair<qint64,qint64> aLocIds);
    void setPUPos(QPair<qint64,qint64> aPos);
    void setDLPos(QPair<qint64,qint64> aPos);
    void setDemand(qint64 aDemand);

    qint64 getCusId(){return mCusId;}

    void setFocusColor(bool isFocused)
    {
        if(isFocused)
        {lineBrushColor=Qt::darkCyan;}
        else
        {lineBrushColor=Qt::gray;}
    }

    MapViewRequest* mPURequest;
    MapViewRequest* mDLRequest;
    QGraphicsLineItem* mRequestLine;
    QGraphicsTextItem* mRequestText;

    QPair<qint64,qint64> mLocIds, mFromPos, mToPos;
private:
    QColor lineBrushColor=Qt::gray;
    void setRequestLine();
    void setRequestText();

    qint64 mCusId,mDemand;
};

class MapViewFocusCircle: public QGraphicsObject
{
    Q_OBJECT
public:
    MapViewFocusCircle(const QPair<qint64,qint64> &aPos,
                       const QColor &color = Qt::red);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QPainterPath shape() const;

    QPair<qint64,qint64> getPos() const{return mPos;}

//    void setId(const qint64 &aVehId){mVehId = aVehId;}
    void setThePos(const QPair<qint64,qint64> &aPos){mPos = aPos;  setPos(mPos.first,mPos.second);}
private:
    QColor brushColor;
    QPair<qint64,qint64> mPos;
};

class MapViewReflectCrossHair: public QGraphicsObject
{
    Q_OBJECT
public:
    MapViewReflectCrossHair(const QPair<qint64,qint64> &aPos,
                            const QColor &color = Qt::magenta);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QPainterPath shape() const;

    QPair<qint64,qint64> getPos() const {return mPos;}

    void setThePos(const QPair<qint64,qint64> &aPos){mPos=aPos;setPos(mPos.first,mPos.second);}
private:
    QColor brushColor;
    QPair<qint64,qint64> mPos;
};

#endif // MAPVIEWOBJECTS_H
