#include "mapviewobjects.h"

MapViewObjects::MapViewObjects()
{
}
//=================================================================
//Scene
MapViewScene::MapViewScene(QObject *parent) :
    QGraphicsScene(parent)
{
}

//void MapViewScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
//{
//    QPointF scenePos = event->scenePos();
//    qDebug()<<"press"<<scenePos;
//}

//void MapViewScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
//{
//    qDebug()<<"move";
//}

//==================================================================
//Background
MapViewBackground::MapViewBackground(qint64 aWidth, qint64 aHeight) :
    mWidth(aWidth),
    mHeight(aHeight)
{
    QString imagePath = QString("./images/VRPImage/sentosa_map.png");
    image = new QPixmap(imagePath);
    qDebug()<<QString("image src: %1, width: %2, height: %3")
              .arg(imagePath)
              .arg(image->width())
              .arg(image->height());
    enableHoverEvent(true);
}

void MapViewBackground::enableHoverEvent(bool enabled)
{
    if(enabled){
        if(image->width()>0 && image->height()>0)
        {
            setAcceptHoverEvents(true);
        }
    }else
    {
        setAcceptHoverEvents(false);
    }
}

void MapViewBackground::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    mPressPos = event->scenePos();
    qDebug()<<"scenePos:"<<event->scenePos();
//    qDebug()<<"itemPos:"<<event->pos();
    mItems = scene()->items(event->scenePos());

    if(mItems.size()==1)
    {
        emit loseFocus();
    }

    qDebug()<<"itemsNum:"<<mItems.size();
//    qDebug()<<"itemZValue:"<<mItems.at(mItems.size()-1)->zValue();
    emit sendPressScenePos(mPressPos);
    if(mViewStr == "mon")
    {
        ExecuteWithMonMode();
    }else if(mViewStr == "loc")
    {
        ExecuteWithLocMode();
    }else if(mViewStr == "veh")
    {
        ExecuteWithVehMode();
    }else if(mViewStr == "cus")
    {
        ExecuteWithCusMode();
    }else if(mViewStr == "evt")
    {
        ExecuteWithEvtMode();
    }
    //clean up mItems
    mItems.clear();
}

void MapViewBackground::hoverMoveEvent(QGraphicsSceneHoverEvent *event)
{
    mHoverPos = event->scenePos();
    emit sendHoverMoveEvent(mHoverPos);
}

void MapViewBackground::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    mHoverPos = event->scenePos();
    emit sendHoverEnterEvent(mHoverPos);
}

void MapViewBackground::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    emit sendHoverLeaveEvent();
}

QRectF MapViewBackground::boundingRect() const
{
    qreal penWidth = 1;
    return QRectF(0/*-penWidth/2*/,0/*-penWidth/2*/,image->width()/*+penWidth*/,image->height()/*+penWidth*/);
}

void MapViewBackground::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(0,0,image->width(),image->height(),*image);
    painter->drawRect(0,0,image->width(),image->height());
}

QPainterPath MapViewBackground::shape() const
{
    QPainterPath path;
    path.addRect(0,0,image->width(),image->height());
    return path;
}

void MapViewBackground::ExecuteWithMonMode()
{
    QList<qint64> tSelectedLocList;
    QList<qint64> tSelectedVehList;
    QList<qint64> tSelectedCusList;

    QString tItemStr;
    for(int i = 0; i < mItems.size(); ++i)
    {
        qreal tZValue = mItems.at(i)->zValue();
        if(tZValue==5)
        {
            MapViewVehicle* tVehItem = dynamic_cast<MapViewVehicle*>(mItems.at(i));
            qint64 tVehId = tVehItem->getVehId();
            tSelectedVehList.append(tVehId);
//            delete tVehItem;
        }else if(tZValue==3||tZValue==8)
        {
            MapViewRequest* tReqItem = dynamic_cast<MapViewRequest*>(mItems.at(i));
            qint64 tCusId = tReqItem->getCusId();
            tSelectedCusList.append(tCusId);
//            delete tReqItem;
        }else if(tZValue==1||tZValue==6)
        {
            MapViewLandmark* tLocItem = dynamic_cast<MapViewLandmark*>(mItems.at(i));
            qint64 tLocId = tLocItem->getLocId();
            tSelectedLocList.append(tLocId);
//            delete tLocItem;
        }
    }

//    qDebug()<<"bbhbhb";

    if(!tSelectedVehList.isEmpty())
    {
        tItemStr = QString("veh");
        emit pressInMonMode(tItemStr,tSelectedVehList);
    }
    if(!tSelectedCusList.isEmpty())
    {
        tItemStr = QString("cus");
        emit pressInMonMode(tItemStr,tSelectedCusList);
    }
    if(!tSelectedLocList.isEmpty())
    {
        tItemStr = QString("loc");
        emit pressInMonMode(tItemStr,tSelectedLocList);
    }
    //how the ui reacts depends on which page it is on

//    qDebug()<<"bbhbhb";
}

void MapViewBackground::ExecuteWithLocMode()
{
    qDebug()<<"enter execute with loc mode";
    //also need to feedback the pos
    QHash<qint64,QPair<double,double>> tSelectedLocCoordHash;

    for(int i = 0; i < mItems.size(); ++i)
    {
        qreal tZValue = mItems.at(i)->zValue();
        if(tZValue==1)
        {
            MapViewLandmark* tLocItem = dynamic_cast<MapViewLandmark*>(mItems.at(i));
            qint64 tLocId = tLocItem->getLocId();
            QPair<double,double> tCoord = tLocItem->getCoord();
            tSelectedLocCoordHash.insert(tLocId,tCoord);
//            delete tLocItem;
        }
    }

    if(!tSelectedLocCoordHash.isEmpty())
    {
        qDebug()<<"coord hash has content";
        emit pressInLocMode(tSelectedLocCoordHash);
    }
}

void MapViewBackground::ExecuteWithVehMode()
{
    QHash<qint64,QPair<double,double>> tSelectedVehCoordHash;
    for(int i = 0; i < mItems.size(); ++i)
    {
        qreal tZValue = mItems.at(i)->zValue();
        if(tZValue==5)
        {
            MapViewVehicle* tVehItem = dynamic_cast<MapViewVehicle*>(mItems.at(i));
            qint64 tVehId = tVehItem->getVehId();
            QPair<double,double> tCoord = tVehItem->getCoord();
            tSelectedVehCoordHash.insert(tVehId,tCoord);
//            delete tVehItem;
        }
    }
    if(!tSelectedVehCoordHash.isEmpty())
    {
        emit pressInVehMode(tSelectedVehCoordHash);
    }
}

void MapViewBackground::ExecuteWithCusMode()
{
    QHash<qint64,bool> tSelectedCusIdPUHash;
    QList<qint64> tSelectedLocList;
    for(int i = 0; i < mItems.size(); ++i)
    {
        qreal tZValue = mItems.at(i)->zValue();
        if(tZValue==3)
        {
            MapViewRequest* tReqItem = dynamic_cast<MapViewRequest*>(mItems.at(i));
            qint64 tCusId = tReqItem->getCusId();
            bool tIsPickUp = tReqItem->getIsPickUp();
            tSelectedCusIdPUHash.insert(tCusId,tIsPickUp);
//            delete tReqItem;
        }
        if(tZValue==1)
        {
            MapViewLandmark* tLocItem = dynamic_cast<MapViewLandmark*>(mItems.at(i));
            qint64 tLocId = tLocItem->getLocId();
            tSelectedLocList.append(tLocId);
//            delete tLocItem;
        }
    }
    if(!tSelectedLocList.isEmpty())
    {
        emit pressInCusModeForLoc(tSelectedLocList);
    }

    if(!tSelectedCusIdPUHash.isEmpty())
    {
        emit pressInCusModeForReq(tSelectedCusIdPUHash);
    }
}

void MapViewBackground::ExecuteWithEvtMode()
{
    //only need vehid
    QList<qint64> tSelectedVehIdList;
    for(int i = 0; i < mItems.size(); ++i)
    {
        qreal tZValue = mItems.at(i)->zValue();
        if(tZValue==5)
        {
            MapViewVehicle* tVehItem = dynamic_cast<MapViewVehicle*>(mItems.at(i));
            qint64 tVehId = tVehItem->getVehId();
            tSelectedVehIdList.append(tVehId);
//            delete tVehItem;
        }
    }
    if(!tSelectedVehIdList.isEmpty())
    {
        emit pressInEvtMode(tSelectedVehIdList);
    }
}
//==================================================================
//Landmark

//void MapViewLandmark::EnterInteractiveMode()
//{
//    setFlag(QGraphicsItem::ItemIsFocusable);
//    setAcceptHoverEvents(true);
//}

//void MapViewLandmark::ExitInteractiveMode()
//{
//    setFlag(QGraphicsItem::ItemIsFocusable,false);
//    setAcceptHoverEvents(false);
//}

//void MapViewLandmark::mousePressEvent(QGraphicsSceneMouseEvent *event)
//{
//    setFocus();
//    setCursor(Qt::Close);
//}

//void MapViewLandmark::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
//{
//    setCursor(Qt::OpenHandCursor);
//}

MapViewLandmark::MapViewLandmark(const qint64 &aLocId,
                                 const QPair<qint64, qint64> &aPos,
                                 const QPair<double, double> &aCoord,
                                 const QColor &color):
    mLocId(aLocId),
    mPos(aPos),
    mCoord(aCoord),
    brushColor(color)
{
    setZValue(1);
    setPos(mPos.first,mPos.second);
}

QRectF MapViewLandmark::boundingRect() const
{
    qreal adjust = 0.5;
    return QRectF(-8 - adjust, -8 - adjust, 16 + adjust, 16 + adjust);
}

void MapViewLandmark::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(brushColor);
    QColor tPenColor;
    tPenColor = brushColor;
    tPenColor.setAlpha(20);
    painter->setPen(tPenColor);
    painter->setOpacity(0.7);
    painter->drawRoundedRect(-8,-8,16,16,8,8);
    QFont font = painter->font();
    font.setPointSize(font.pointSize()/2);
    painter->setFont(font);
    painter->setPen(Qt::black);
    painter->drawText(-8,-8,16,16,Qt::AlignCenter, QString("%1").arg(mLocId));
}

QPainterPath MapViewLandmark::shape() const
{
    QPainterPath path;
    path.addRoundedRect(-8,-8,16,16,8,8);
    return path;
}
//==================================================================
//Vehicle
MapViewVehicle::MapViewVehicle(const qint64 &aVehId,
                               const QPair<qint64, qint64> &aPos,
                               const QPair<double, double> &aCoord,
                               const QColor &color):
    mVehId(aVehId),
    mPos(aPos),
    mCoord(aCoord),
    brushColor(color)
{
    setPos(mPos.first,mPos.second);
    setZValue(5);
}

QRectF MapViewVehicle::boundingRect() const
{
    qreal adjust = 0.5;
    return QRectF(-halfSize - adjust, -halfSize - adjust, 2*halfSize + adjust, 2*halfSize + adjust);
}

void MapViewVehicle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(brushColor);
    QColor tPenColor;
    tPenColor = brushColor;
    tPenColor.setAlpha(20);
    painter->setPen(tPenColor);
    painter->setOpacity(0.7);
    painter->drawRect(-halfSize,-halfSize,2*halfSize,2*halfSize);
//    painter->setPen(Qt::white);
//    painter->drawText(-10,-10,20,20,Qt::AlignCenter, QString("%1").arg(mVehId));
    QFont font = painter->font();
    font.setPointSize(font.pointSize()/2);
    painter->setFont(font);
    painter->setPen(Qt::white);
    painter->drawText(-halfSize,-halfSize,2*halfSize,2*halfSize,Qt::AlignCenter, QString("%1").arg(mVehId));
}

QPainterPath MapViewVehicle::shape() const
{
    QPainterPath path;
    path.addRect(-halfSize,-halfSize,2*halfSize,2*halfSize);
    return path;
}
//==================================================================
//Vehicle Travel Line
MapViewVehicleTravelLine::MapViewVehicleTravelLine(const QPair<qint64, qint64> &aLineStartPos,
                                                   const QPair<qint64, qint64> &aLineEndPos,
                                                   bool isFirstLine,
                                                   const QColor &color):
//    mStartId(aStartId),
//    mEndId(aEndId),
    mLineStartPos(aLineStartPos),
    mLineEndPos(aLineEndPos),
    mIsFirstLine(isFirstLine),
    brushColor(color)
{
    QPen pen = Qt::DashLine;
    pen.setColor(brushColor);
    pen.setWidth(1);
    setPen(pen);
    setOpacity(0.5);

    setLine(mLineStartPos.first,mLineStartPos.second,mLineEndPos.first,mLineEndPos.second);
}

void MapViewVehicleTravelLine::setLineStartPos(const QPair<qint64, qint64> &aLineStartPos)
{
    mLineStartPos = aLineStartPos;
    setLine(mLineStartPos.first,mLineStartPos.second,mLineEndPos.first,mLineEndPos.second);
}
//==================================================================
//Request
MapViewRequest::MapViewRequest(const qint64 &aCusId,
                               const qint64 &aLocId,
                               bool isPickUp,
                               const QPair<qint64, qint64> &aPos):
    mCusId(aCusId),
    mLocId(aLocId),
    mIsPickUp(isPickUp),
    mPos(aPos)
{
    if(isPickUp)
    {
        brushColor = Qt::yellow;
    }else
    {
        brushColor = Qt::darkYellow;
    }
    setPos(mPos.first,mPos.second);
}

QRectF MapViewRequest::boundingRect() const
{
    qreal adjust = 0.5;
    return QRectF(- halfSize - adjust, -halfSize - adjust, 2*halfSize + adjust, 2*halfSize + adjust);
}

void MapViewRequest::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(brushColor);
    QColor tPenColor;
    tPenColor = brushColor;
    tPenColor.setAlpha(20);
    painter->setPen(tPenColor);
    painter->setOpacity(0.5);
    painter->drawRoundedRect(-halfSize,-halfSize,2*halfSize,2*halfSize,halfSize,halfSize);
//    painter->setPen(Qt::white);
//    painter->drawText(-10,-10,20,20,Qt::AlignCenter, QString("%1").arg(mLocId));
}

QPainterPath MapViewRequest::shape() const
{
    QPainterPath path;
    path.addRoundedRect(-halfSize,-halfSize,2*halfSize,2*halfSize,halfSize,halfSize);
    return path;
}
//==================================================================
//Vehicle Entity
MapViewVehicleEntity::MapViewVehicleEntity(const qint64 &aVehId,
                                           const QPair<qint64, qint64> &aVehPos,
                                           const QPair<double, double> &aVehCoord,
                                           QObject *parent):
    mVehId(aVehId),
    mVehPos(aVehPos),
    mVehCoord(aVehCoord),
//    mLinePosList(aLinePosList),
    QObject(parent)
{
    mpVehicleItem = new MapViewVehicle(mVehId,mVehPos,mVehCoord);

//    for(int i = 0; i < mLinePosList.size(); ++i)
//    {
//        MapViewVehicleTravelLine* tTravelLine;
//        if(i==0)
//        {
//            tTravelLine = new MapViewVehicleTravelLine(mVehPos,mLinePosList.at(i),true,lineBrushColor);
//        }else
//        {
//            tTravelLine = new MapViewVehicleTravelLine(mLinePosList.at(i-1),mLinePosList.at(i),false,lineBrushColor);
//        }
//        mTravelLineList.append(tTravelLine);
//    }
}

void MapViewVehicleEntity::setVehPos(QPair<qint64, qint64> aVehPos)
{
    mVehPos = aVehPos;
    mpVehicleItem->setVehPos(mVehPos);
    setFirstLineStartPos(mVehPos);
}

void MapViewVehicleEntity::setVehCoord(QPair<double, double> aVehCoord)
{
    mVehCoord = aVehCoord;
    mpVehicleItem->setCoord(mVehCoord);
}

void MapViewVehicleEntity::doUpdate()
{
    mpVehicleItem->update();
    for(int i = 0; i < mTravelLineList.size(); ++i)
    {
        mTravelLineList[i]->update();
    }
}

void MapViewVehicleEntity::setLinePosList(QList<QPair<qint64, qint64> > aLinePosList)
{
    //don't forget to clear the items already added to scene
    for(int i = 0; i < mTravelLineList.size();++i)
    {
        delete mTravelLineList[i];
    }
    mTravelLineList.clear();
    mLinePosList.clear();
    mLinePosList = aLinePosList;
    for(int i = 0; i < mLinePosList.size(); ++i)
    {
        MapViewVehicleTravelLine* tTravelLine;
        if(i==0)
        {
            tTravelLine = new MapViewVehicleTravelLine(mVehPos,mLinePosList.at(i),true);
        }else
        {
            tTravelLine = new MapViewVehicleTravelLine(mLinePosList.at(i-1),mLinePosList.at(i),false);
        }
        mTravelLineList.append(tTravelLine);
    }
}

void MapViewVehicleEntity::setFirstLineStartPos(QPair<qint64, qint64> aFirstLineStartPos)
{
    if(!mTravelLineList.isEmpty())
    {
        if(mTravelLineList.first()->getIsFirstLine())
        {
            mTravelLineList.first()->setLineStartPos(aFirstLineStartPos);
        }
    }
}

void MapViewVehicleEntity::arrive()
{
    mTravelLineList.removeFirst();
    mTravelLineList.first()->setIsFirstLine();
}
//==================================================================
//Request Entity
MapViewRequestEntity::MapViewRequestEntity(const qint64 &aCusId,
                                           const qint64 &aDemand,
                                           QPair<qint64, qint64> aLocIds,
                                           QPair<qint64, qint64> aFromPos,
                                           QPair<qint64, qint64> aToPos,
                                           QObject *parent):
    mCusId(aCusId),
    mDemand(aDemand),
    mLocIds(aLocIds),
    mFromPos(aFromPos),
    mToPos(aToPos),
    QObject(parent)
{
    mPURequest = new MapViewRequest(mCusId,mLocIds.first,true,mFromPos);
    mDLRequest = new MapViewRequest(mCusId,mLocIds.second,false,mToPos);

    mRequestLine = new QGraphicsLineItem;
    QPen tPen(Qt::DashLine);
    tPen.setWidth(1);
    tPen.setColor(lineBrushColor);
    mRequestLine->setPen(tPen);
    mRequestLine->setLine(mFromPos.first,mFromPos.second,mToPos.first,mToPos.second);

    mRequestText = new QGraphicsTextItem(0);
    mRequestText->setFont(QFont("Times",10));
    mRequestText->setHtml(QString("<font color=black>%1</font>").arg(mDemand));
    mRequestText->setPos((mFromPos.first+mToPos.first)/2,(mFromPos.second+mToPos.second)/2);
}

void MapViewRequestEntity::setLocIds(QPair<qint64, qint64> aLocIds)
{
    mLocIds = aLocIds;
    mPURequest->setLocId(mLocIds.first);
    mDLRequest->setLocId(mLocIds.second);
    setRequestLine();
}

void MapViewRequestEntity::setPUPos(QPair<qint64, qint64> aPos)
{
    mFromPos = aPos;
    mPURequest->setReqPos(mFromPos);
}

void MapViewRequestEntity::setDLPos(QPair<qint64, qint64> aPos)
{
    mToPos = aPos;
    mDLRequest->setPos(mToPos.first,mToPos.second);
}

void MapViewRequestEntity::setDemand(qint64 aDemand)
{
    mDemand = aDemand;
    setRequestText();
}

void MapViewRequestEntity::setRequestLine()
{
    mRequestLine->setLine(mFromPos.first,mFromPos.second,mToPos.first,mToPos.second);
}

void MapViewRequestEntity::setRequestText()
{
    mRequestText->setHtml(QString("<font color=black>%1</font>").arg(mDemand));
    mRequestText->setPos((mFromPos.first+mToPos.first)/2,(mFromPos.second+mToPos.second)/2);
}

//==================================================================
//Focus Circle
//ZValue:9
MapViewFocusCircle::MapViewFocusCircle(const QPair<qint64, qint64> &aPos, const QColor &color)
    : mPos(aPos),
      brushColor(color)
{
    setPos(mPos.first,mPos.second);
    setZValue(9);
}

QRectF MapViewFocusCircle::boundingRect() const
{
    qreal adjust = 0.5;
    return  QRectF(-10-adjust,-10-adjust,20+adjust,20+adjust);
}

void MapViewFocusCircle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(brushColor);
    QColor tPenColor;
    tPenColor = brushColor;
    tPenColor.setAlpha(20);
//    QPen tPen;
//    tPen.setColor(tPenColor);
//    tPen.setWidth(3);
    painter->setPen(tPenColor),
    painter->setOpacity(0.3);
    painter->drawRoundedRect(-10,-10,20,20,10,10);
//    painter->drawArc(-10,-10,20,20,0,360*16);
}


QPainterPath MapViewFocusCircle::shape() const
{
    QPainterPath path;
    path.addRoundedRect(-10,-10,20,20,10,10);
    return path;
}

//==================================================================
//ReflectCrossHair
MapViewReflectCrossHair::MapViewReflectCrossHair(const QPair<qint64, qint64> &aPos, const QColor &color):
    mPos(aPos),
    brushColor(color)
{
    setPos(mPos.first,mPos.second);
    setZValue(10);
//    this->show();
}

QRectF MapViewReflectCrossHair::boundingRect() const
{
    qreal adjust = 0.5;
    return QRectF(-5-adjust,-5-adjust,10+adjust,10+adjust);
}

void MapViewReflectCrossHair::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
//    painter->setBrush(brushColor);
//    QColor tPenColor;
//    tPenColor = brushColor;
//    tPenColor.setAlpha(20);
//    QPen tPen;
//    tPen.setColor(tPenColor);
//    tPen.setWidth(5);
//    painter->setPen(tPen);
//    painter->setOpacity(0.7);
//    painter->drawLine(mPos.first,mPos.second-10,mPos.first,mPos.second+10);
//    painter->drawLine(mPos.first-10,mPos.second,mPos.first+10,mPos.second);
    painter->setBrush(brushColor);
    QColor tPenColor;
    tPenColor = brushColor;
    tPenColor.setAlpha(20);
    painter->setPen(tPenColor);
    painter->setOpacity(0.7);
    painter->drawRoundedRect(-5,-5,10,10,5,5);
}

QPainterPath MapViewReflectCrossHair::shape() const
{
    QPainterPath path;
//    path.addRect(-10,-10,20,20);
    path.addRoundedRect(-5,-5,10,10,5,5);
    return path;
}
