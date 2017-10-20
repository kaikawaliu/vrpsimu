#include "mapviewmanager.h"

MapViewManager::MapViewManager(QGraphicsView* apView, QObject *parent) :
    mpView(apView),
    QObject(parent)
{
    InitView();
}

void MapViewManager::InitView()
{
    mpMapViewBgd = new MapViewBackground(mpView->width(),mpView->height());
    qDebug()<<QString("width: %1 height: %2").arg(mpView->width()).arg(mpView->height());
    mpMapViewBgd->setPos(0,0);
    mpMapViewBgd->setZValue(0);

//    mpMapViewBgd->enableHoverEvent(true);

    QPair<qint64,qint64> tCHPair(0,0);
    mRefCrossHair = new MapViewReflectCrossHair(tCHPair);
    mRefCrossHair->hide();

    mpView->setRenderHint(QPainter::Antialiasing);
    mpView->setCacheMode(QGraphicsView::CacheBackground);

//    mpScene = new QGraphicsScene;
    mpScene = new MapViewScene;
    mpScene->setSceneRect(0,0,mpView->width(),mpView->height());
    mpScene->setBackgroundBrush(QColor(255,255,255,100));
    mpView->setScene(mpScene);

    connect(mpMapViewBgd,SIGNAL(sendPressScenePos(QPointF)),this,SLOT(getMousePressEvent(QPointF)));
    connect(mpMapViewBgd,SIGNAL(sendHoverEnterEvent(QPointF)),this,SLOT(getHoverEnterEvent(QPointF)));
    connect(mpMapViewBgd,SIGNAL(sendHoverMoveEvent(QPointF)),this,SLOT(getHoverMoveEvent(QPointF)));
    connect(mpMapViewBgd,SIGNAL(sendHoverLeaveEvent()),this,SLOT(getHoverLeaveEvent()));

    qRegisterMetaType<QList<qint64>>("QList<qint64>");
    connect(mpMapViewBgd,SIGNAL(pressInMonMode(QString,QList<qint64>)),this,SIGNAL(sendPressInMonMode(QString,QList<qint64>)));
    qRegisterMetaType<QHash<qint64,QPair<double,double>>>("QHash<qint64,QPair<double,double>>");
    connect(mpMapViewBgd,SIGNAL(pressInLocMode(QHash<qint64,QPair<double,double> >)),this,SIGNAL(sendPressInLocMode(QHash<qint64,QPair<double,double> >)));
    connect(mpMapViewBgd,SIGNAL(pressInVehMode(QHash<qint64,QPair<double,double> >)),this,SIGNAL(sendPressInVehMode(QHash<qint64,QPair<double,double> >)));
    connect(mpMapViewBgd,SIGNAL(pressInCusModeForLoc(QList<qint64>)),this,SIGNAL(sendPressInCusModeForLoc(QList<qint64>)));
    qRegisterMetaType<QHash<qint64,bool>>("QHash<qint64,bool>");
    connect(mpMapViewBgd,SIGNAL(pressInCusModeForReq(QHash<qint64,bool>)),this,SIGNAL(sendPressInCusModeForReq(QHash<qint64,bool>)));
    connect(mpMapViewBgd,SIGNAL(pressInEvtMode(QList<qint64>)),this,SIGNAL(sendPressInEvtMode(QList<qint64>)));
    connect(mpMapViewBgd,SIGNAL(loseFocus()),this,SLOT(getLoseFocus()));

    updateDisplay();
}

void MapViewManager::updateDisplay()
{
    mpScene->clear();

    //install background
    mpScene->addItem(mpMapViewBgd);
    //install crosshair
    mpScene->addItem(mRefCrossHair);

    //install loc into view
    QList<qint64> tLocIdList = mLandmarkItems.keys();
    for(int i = 0; i < tLocIdList.size(); ++i)
    {
        mpScene->addItem(mLandmarkItems[tLocIdList.at(i)]);
    }

    //install veh into view
    QList<qint64> tVehIdList = mVehEntities.keys();
    for(int i = 0; i < tVehIdList.size(); ++i)
    {
        mpScene->addItem(mVehEntities[tVehIdList.at(i)]->mpVehicleItem);
        for(int j = 0; j < mVehEntities[tVehIdList.at(i)]->mTravelLineList.size(); ++j)
        {
            mpScene->addItem(mVehEntities[tVehIdList.at(i)]->mTravelLineList[j]);
        }
    }

    //install req into view
    QList<qint64> tCusIdList = mReqEntities.keys();
    for(int i = 0; i < tCusIdList.size(); ++i)
    {
        mpScene->addItem(mReqEntities[tCusIdList.at(i)]->mPURequest);
        mpScene->addItem(mReqEntities[tCusIdList.at(i)]->mDLRequest);
        mpScene->addItem(mReqEntities[tCusIdList.at(i)]->mRequestLine);
        mpScene->addItem(mReqEntities[tCusIdList.at(i)]->mRequestText);
    }

    //install focus circle (1 or 2)
    for(int i = 0; i < mFocusCircles.size(); ++i)
    {
        mpScene->addItem(mFocusCircles[i]);
    }
}

void MapViewManager::SwitchView(QString aViewStr)
{
    resetZValues();
    clearFocus();


    mViewStr = aViewStr;
    mpMapViewBgd->switchView(mViewStr);

//    qDebug()<<"done the pre work of switch view";


    if(mViewStr=="mon")
    {
        showMonOrEvt();
    }else if(mViewStr=="loc")
    {

        hideAllItems();
        showLoc();
    }else if(mViewStr=="veh")
    {
//        qDebug()<<"enter the proc of switch veh view";
        hideAllItems();
        showVeh();
    }else if(mViewStr=="cus")
    {
        hideAllItems();
        showCus();
    }else if(mViewStr=="evt")
    {
        showMonOrEvt();
    }
}

void MapViewManager::hideAllItems()
{
    //hide loc from view
    QList<qint64> tLocIdList = mLandmarkItems.keys();
    for(int i = 0; i < tLocIdList.size(); ++i)
    {
        mLandmarkItems[tLocIdList.at(i)]->hide();
    }

    //hide veh from view
    QList<qint64> tVehIdList = mVehEntities.keys();
    for(int i = 0; i < tVehIdList.size(); ++i)
    {
        mVehEntities[tVehIdList.at(i)]->mpVehicleItem->hide();
        for(int j = 0; j < mVehEntities[tVehIdList.at(i)]->mTravelLineList.size(); ++j)
        {
            mVehEntities[tVehIdList.at(i)]->mTravelLineList[j]->hide();
        }
    }

    //hide cus from view
    QList<qint64> tCusIdList = mReqEntities.keys();
    for(int i = 0; i < tCusIdList.size(); ++i)
    {
        mReqEntities[tCusIdList.at(i)]->mPURequest->hide();
        mReqEntities[tCusIdList.at(i)]->mDLRequest->hide();
        mReqEntities[tCusIdList.at(i)]->mRequestLine->hide();
        mReqEntities[tCusIdList.at(i)]->mRequestText->hide();
    }
//    qDebug()<<"hide all items";
}

void MapViewManager::showMonOrEvt()
{
    //show loc in view
    QList<qint64> tLocIdList = mLandmarkItems.keys();
    for(int i = 0; i < tLocIdList.size(); ++i)
    {
        mLandmarkItems[tLocIdList.at(i)]->show();
    }

    //show veh in view
    QList<qint64> tVehIdList = mVehEntities.keys();
    for(int i = 0; i < tVehIdList.size(); ++i)
    {
        mVehEntities[tVehIdList.at(i)]->mpVehicleItem->show();
        for(int j = 0; j < mVehEntities[tVehIdList.at(i)]->mTravelLineList.size(); ++j)
        {
            mVehEntities[tVehIdList.at(i)]->mTravelLineList[j]->show();
        }
    }

    //show cus in view
    QList<qint64> tCusIdList = mReqEntities.keys();
    for(int i = 0; i < tCusIdList.size(); ++i)
    {
        mReqEntities[tCusIdList.at(i)]->mPURequest->show();
        mReqEntities[tCusIdList.at(i)]->mDLRequest->show();
        mReqEntities[tCusIdList.at(i)]->mRequestLine->show();
        mReqEntities[tCusIdList.at(i)]->mRequestText->show();
    }
}

void MapViewManager::showLoc()
{
    //show loc in view
    QList<qint64> tLocIdList = mLandmarkItems.keys();
    for(int i = 0; i < tLocIdList.size(); ++i)
    {
        mLandmarkItems[tLocIdList.at(i)]->show();
    }
//    qDebug()<<"done show loc";
}

void MapViewManager::showVeh()
{
    showLoc();
    //show veh in view
    QList<qint64> tVehIdList = mVehEntities.keys();
    for(int i = 0; i < tVehIdList.size(); ++i)
    {
        mVehEntities[tVehIdList.at(i)]->mpVehicleItem->show();
        for(int j = 0; j < mVehEntities[tVehIdList.at(i)]->mTravelLineList.size(); ++j)
        {
            mVehEntities[tVehIdList.at(i)]->mTravelLineList[j]->show();
        }
    }
//    qDebug()<<"done show veh";
}

void MapViewManager::showCus()
{
    showLoc();
    //show cus in view
    QList<qint64> tCusIdList = mReqEntities.keys();
    for(int i = 0; i < tCusIdList.size(); ++i)
    {
        mReqEntities[tCusIdList.at(i)]->mPURequest->show();
        mReqEntities[tCusIdList.at(i)]->mDLRequest->show();
        mReqEntities[tCusIdList.at(i)]->mRequestLine->show();
        mReqEntities[tCusIdList.at(i)]->mRequestText->show();
    }
}

void MapViewManager::EnterInteractiveMode()
{
//    setFlag(QGraphicsItem::ItemIsFocusable);
//    setAcceptHoverEvents(true);
    inManMode=true;
}

void MapViewManager::ExitInteractiveMode()
{
//    setFlag(QGraphicsItem::ItemIsFocusable,false);
//    setAcceptHoverEvents(false);
    inManMode=false;
}

void MapViewManager::getMousePressEvent(QPointF aPressPos)
{
    QPair<qint64,qint64> tPosPair(aPressPos.rx(),aPressPos.ry());
    QPair<double,double> tCoordPair = PosToCoord(tPosPair);
//    emit sendMousePressEventToUI(tPosPair,tCoordPair);
    if(inGetLLMode)
    {
        emit sendGotLLCoordToUI(tCoordPair);
        leaveGetLLMode();
    }
}

void MapViewManager::getHoverEnterEvent(QPointF aHoverPos)
{
    inHoverMode=true;
    QPair<qint64,qint64> tPosPair(aHoverPos.rx(),aHoverPos.ry());
    QPair<double,double> tCoordPair = PosToCoord(tPosPair);
    emit sendHoverPosToUI(tPosPair,tCoordPair);
    if(inGetLLMode)
    {
        showCrossHair(tPosPair);
    }
}

void MapViewManager::getHoverMoveEvent(QPointF aHoverPos)
{
    QPair<qint64,qint64> tPosPair(aHoverPos.rx(),aHoverPos.ry());
    QPair<double,double> tCoordPair = PosToCoord(tPosPair);
    emit sendHoverPosToUI(tPosPair,tCoordPair);
    if(inGetLLMode)
    {
        mRefCrossHair->setThePos(tPosPair);
        mRefCrossHair->update();
    }
//    qDebug()<<QString("CrossHair Pos: (%1,%2) %3").arg(mRefCrossHair->pos().rx()).arg(mRefCrossHair->pos().ry()).arg(mRefCrossHair->isVisible() ? 1 : 0);
}

void MapViewManager::getHoverLeaveEvent()
{
    inHoverMode=false;
    emit sendHoverLeaveToUI();
    if(inGetLLMode)
    {
        hideCrossHair();
    }
}

void MapViewManager::getLoseFocus()
{
    clearFocus();
    emit loseSelection();
}

void MapViewManager::resetZValues()
{
//    qDebug()<<"MapViewManager::resetZValues()";
    QList<qint64> tLocIds = mLandmarkItems.keys();

    for(int i = 0; i < tLocIds.size(); ++i)
    {
        mLandmarkItems[tLocIds.at(i)]->setZValue(1);
    }

    QList<qint64> tReqIds = mReqEntities.keys();
    for(int i = 0; i < tReqIds.size(); ++i)
    {
        mReqEntities[tReqIds.at(i)]->mRequestLine->setZValue(2);
        mReqEntities[tReqIds.at(i)]->mRequestText->setZValue(2);
        mReqEntities[tReqIds.at(i)]->mPURequest->setZValue(3);
        mReqEntities[tReqIds.at(i)]->mDLRequest->setZValue(3);
    }
}

void MapViewManager::focusOnItem(QString aViewStr, qint64 aId)
{
    clearFocus();

    mFocusViewStr = aViewStr;
    mFocusId = aId;

    if(mFocusViewStr=="loc")
    {
        //one circle only
        QPair<qint64,qint64> tPos = mLandmarkItems.value(mFocusId)->getPos();
        MapViewFocusCircle* tFocusCircle = new MapViewFocusCircle(tPos);
        tFocusCircle->show();
        mFocusCircles.append(tFocusCircle);
        mpScene->addItem(tFocusCircle);
    }else if(mFocusViewStr=="veh")
    {
        //one circle with several lines
        if(mVehEntities.contains(mFocusId)){
            QPair<qint64,qint64> tPos = mVehEntities.value(mFocusId)->mpVehicleItem->getPos();
            MapViewFocusCircle* tFocusCircle = new MapViewFocusCircle(tPos);
            tFocusCircle->show();
            mFocusCircles.append(tFocusCircle);
            mpScene->addItem(tFocusCircle);

            QPen tPen(Qt::DashLine);
            tPen.setWidth(3);
            tPen.setColor(Qt::darkBlue);
            for(int i = 0; i < mVehEntities[mFocusId]->mTravelLineList.size();++i)
            {
                mVehEntities[mFocusId]->mTravelLineList[i]->setPen(tPen);
                mVehEntities[mFocusId]->mTravelLineList[i]->update();
            }
            mVehEntities[mFocusId]->setFocusColor(true);
        }
    }else if(mFocusViewStr=="cus")
    {
        //two circles with one line
        QPair<qint64,qint64> tPUPos = mReqEntities.value(mFocusId)->mFromPos;
        MapViewFocusCircle* tPUFocusCircle = new MapViewFocusCircle(tPUPos);
        tPUFocusCircle->show();
        mFocusCircles.append(tPUFocusCircle);
        mpScene->addItem(tPUFocusCircle);

        QPair<qint64,qint64> tDLPos = mReqEntities.value(mFocusId)->mToPos;
        MapViewFocusCircle* tDLFocusCircle = new MapViewFocusCircle(tDLPos);
        tDLFocusCircle->show();
        mFocusCircles.append(tDLFocusCircle);
        mpScene->addItem(tDLFocusCircle);

        QPen tPen(Qt::DashLine);
        tPen.setWidth(2);
        tPen.setColor(Qt::darkCyan);
        mReqEntities[mFocusId]->mRequestLine->setPen(tPen);
        mReqEntities[mFocusId]->mRequestLine->update();
        mReqEntities[mFocusId]->setFocusColor(true);
    }
}

void MapViewManager::clearFocus()
{
//    qDebug()<<"MapViewManager::clearFocus()";
    for(int i = 0; i < mFocusCircles.size(); ++i)
    {
        mpScene->removeItem(mFocusCircles[i]);
        delete mFocusCircles[i];
    }
    mFocusCircles.clear();

    if(mFocusViewStr=="cus")
    {
        if(mReqEntities.contains(mFocusId))
        {
            QPen tPen(Qt::DashLine);
            tPen.setColor(Qt::gray);
            tPen.setWidth(1);
            mReqEntities[mFocusId]->mRequestLine->setPen(tPen);
            mReqEntities[mFocusId]->mRequestLine->update();
            mReqEntities[mFocusId]->setFocusColor(false);
        }
    }else if(mFocusViewStr=="veh")
    {
        if(mVehEntities.contains(mFocusId))
        {
            QPen tPen(Qt::DashLine);
            tPen.setColor(Qt::gray);
            tPen.setWidth(1);
            for(int i = 0; i < mVehEntities[mFocusId]->mTravelLineList.size();++i)
            {
                mVehEntities[mFocusId]->mTravelLineList[i]->setPen(tPen);
                mVehEntities[mFocusId]->mTravelLineList[i]->update();
            }
            mVehEntities[mFocusId]->setFocusColor(false);
        }
    }
}

void MapViewManager::focusUpdate(QString aViewStr, qint64 aId, QList<QPair<qint64, qint64>> aPosList)
{
    if(mFocusViewStr==aViewStr && mFocusId==aId)
    {
        if(aViewStr=="cus")
        {
            mFocusCircles[0]->setPos(aPosList.at(0).first,aPosList.at(0).second);
            mFocusCircles[1]->setPos(aPosList.at(1).first,aPosList.at(1).second);
        }else
        {
            mFocusCircles[0]->setPos(aPosList.at(0).first,aPosList.at(0).second);
        }
    }
}

void MapViewManager::SwitchMonPage(int index)
{
//    qDebug()<<"MapView::SwitchMonPage";
    resetZValues();
    clearFocus();

    if(index==0)
    {
        QList<qint64> tLocIds = mLandmarkItems.keys();
        for(int i = 0; i < tLocIds.size(); ++i)
        {
            mLandmarkItems[tLocIds.at(i)]->setZValue(6);
//            focusOnItem("loc",tLocIds.at(i));
        }
    }else if(index==1)
    {
        QList<qint64> tVehIds = mVehEntities.keys();
        for(int i = 0; i < tVehIds.size(); ++i)
        {
            //no need to change zvalue
//            focusOnItem("veh",tVehIds.at(i));
        }
    }else if(index==2)
    {
        QList<qint64> tReqIds = mReqEntities.keys();
        for(int i = 0; i < tReqIds.size(); ++i)
        {
            mReqEntities[tReqIds.at(i)]->mRequestLine->setZValue(7);
            mReqEntities[tReqIds.at(i)]->mRequestText->setZValue(7);
            mReqEntities[tReqIds.at(i)]->mPURequest->setZValue(8);
            mReqEntities[tReqIds.at(i)]->mDLRequest->setZValue(8);
//            focusOnItem("cus",tReqIds.at(i));
        }
    }
//    qDebug()<<"MapView::SwitchMonPage done";
}

void MapViewManager::showCrossHair(QPair<qint64, qint64> aPos)
{
//    mRefCrossHair = new MapViewReflectCrossHair(aPos);
    mRefCrossHair->setThePos(aPos);
    mRefCrossHair->update();
    mRefCrossHair->show();
//    qDebug()<<QString("CrossHair Pos: (%1,%2)").arg(mRefCrossHair->pos().rx()).arg(mRefCrossHair->pos().ry());
}

void MapViewManager::hideCrossHair()
{
//    if(mRefCrossHair!=NULL)
//        delete mRefCrossHair;
    QPair<qint64,qint64> tCHPair(0,0);
    mRefCrossHair->setThePos(tCHPair);
    mRefCrossHair->hide();
}

//==========================================
//Loc
void MapViewManager::RegisterLandmarkInView(qint64 aLocId, QPair<double, double> aLocCoord)
{
    if(!mLandmarkItems.contains(aLocId)){
        MapViewLandmark* tMapViewLandmark = new MapViewLandmark(aLocId,CoordToPos(aLocCoord),aLocCoord);
        mLandmarkItems.insert(aLocId,tMapViewLandmark);
        mpScene->addItem(mLandmarkItems[aLocId]);
        mLocsPosHash.insert(aLocId,CoordToPos(aLocCoord));
    }else
    {
        SetLandmarkPosInView(aLocId,aLocCoord);
    }
}

void MapViewManager::DeregisterLandmarkInView(qint64 aLocId)
{
    if(mLandmarkItems.contains(aLocId))
    {
        mpScene->removeItem(mLandmarkItems[aLocId]);
        delete mLandmarkItems[aLocId];
        mLandmarkItems.remove(aLocId);
        mLocsPosHash.remove(aLocId);
    }
}

void MapViewManager::SetLandmarkPosInView(qint64 aLocId, QPair<double, double> aLocCoord)
{
    if(mLandmarkItems.contains(aLocId))
    {
        mLandmarkItems[aLocId]->setLocPos(CoordToPos(aLocCoord));
        mLandmarkItems[aLocId]->setCoord(aLocCoord);
        mLandmarkItems[aLocId]->update();
        mLocsPosHash[aLocId] = CoordToPos(aLocCoord);
    }
}
//==========================================
//Veh
void MapViewManager::RegisterVehicleEntityInView(qint64 aVehId, QPair<double, double> aVehCoord)
{
    if(!mVehEntities.contains(aVehId))
    {
        MapViewVehicleEntity* tMapViewVehEnt = new MapViewVehicleEntity(aVehId,CoordToPos(aVehCoord),aVehCoord);
        mVehEntities.insert(aVehId,tMapViewVehEnt);
        mpScene->addItem(mVehEntities[aVehId]->mpVehicleItem);
    }
}

void MapViewManager::DeregisterVehicleInView(qint64 aVehId)
{
    if(mVehEntities.contains(aVehId))
    {
        mpScene->removeItem(mVehEntities[aVehId]->mpVehicleItem);
        delete mVehEntities[aVehId]->mpVehicleItem;
        for(int i = 0; i < mVehEntities[aVehId]->mTravelLineList.size(); ++i)
        {
            mpScene->removeItem(mVehEntities[aVehId]->mTravelLineList[i]);
            delete mVehEntities[aVehId]->mTravelLineList[i];
            mVehEntities[aVehId]->mTravelLineList.removeAt(i);
        }
        mVehEntities.remove(aVehId);
    }
}

void MapViewManager::SetVehPosInView(qint64 aVehId, QPair<double, double> aVehCoord)
{
    if(mVehEntities.contains(aVehId))
    {
        mVehEntities[aVehId]->setVehPos(CoordToPos(aVehCoord));
        mVehEntities[aVehId]->setVehCoord(aVehCoord);
        mVehEntities[aVehId]->doUpdate();
    }
}

void MapViewManager::RescheduleDest(qint64 aVehId, QList<qint64> aDestList)
{
    QList<QPair<qint64,qint64>> tDestPosList;
    for(int i = 0; i < aDestList.size(); ++i)
    {
        if(mLandmarkItems.contains(aDestList.at(i)))
        {
            QPair<qint64,qint64> tDestPos = mLandmarkItems.value(aDestList.at(i))->getPos();
            tDestPosList.append(tDestPos);
        }else
        {
            qDebug()<<"Veh RescheduleDest: such location is not existed"<<"locid:"<<aDestList.at(i);
        }
    }
//    for(MapViewLandmark landmark : mLandmarkItems)

    if(mVehEntities.contains(aVehId))
    {
        //delete the line in scene first
        for(int i = 0; i < mVehEntities[aVehId]->mTravelLineList.size(); ++i)
        {
            mpScene->removeItem(mVehEntities[aVehId]->mTravelLineList[i]);
        }

        mVehEntities[aVehId]->setLinePosList(tDestPosList);
        mVehEntities[aVehId]->doUpdate();

        //insert into scene
        for(int i = 0; i < mVehEntities[aVehId]->mTravelLineList.size(); ++i)
        {
            mpScene->addItem(mVehEntities[aVehId]->mTravelLineList[i]);
            if(!mVehEntities[aVehId]->mpVehicleItem->isVisible())
                mVehEntities[aVehId]->mTravelLineList[i]->hide();
        }
    }
}

void MapViewManager::ApplyArrivalInView(qint64 aVehId)
{   
    if(mVehEntities.contains(aVehId))
    {
        mpScene->removeItem(mVehEntities[aVehId]->mTravelLineList[0]);

        mVehEntities[aVehId]->arrive();
    }
}
//==========================================
//Cus
void MapViewManager::RegisterRequestInView(qint64 aCusId, qint64 aDemand, QPair<qint64, qint64> aLocIds)
{
    if(!mReqEntities.contains(aCusId))
    {   
        MapViewRequestEntity* tMapViewReqEnt = new MapViewRequestEntity(aCusId,aDemand,aLocIds,mLocsPosHash.value(aLocIds.first),mLocsPosHash.value(aLocIds.second));
        mReqEntities.insert(aCusId,tMapViewReqEnt);
        mpScene->addItem(mReqEntities[aCusId]->mPURequest);
        mpScene->addItem(mReqEntities[aCusId]->mDLRequest);
        mpScene->addItem(mReqEntities[aCusId]->mRequestLine);
        mpScene->addItem(mReqEntities[aCusId]->mRequestText);
    }
}

void MapViewManager::DeregisterRequestInView(qint64 aCusId)
{
    if(mReqEntities.contains(aCusId))
    {
        mpScene->removeItem(mReqEntities[aCusId]->mPURequest);
        mpScene->removeItem(mReqEntities[aCusId]->mDLRequest);
        mpScene->removeItem(mReqEntities[aCusId]->mRequestLine);
        mpScene->removeItem(mReqEntities[aCusId]->mRequestText);
        delete mReqEntities[aCusId]->mPURequest;
        delete mReqEntities[aCusId]->mDLRequest;
        delete mReqEntities[aCusId]->mRequestLine;
        delete mReqEntities[aCusId]->mRequestText;
        mReqEntities.remove(aCusId);
    }
}

void MapViewManager::ApplyChgReqInView(qint64 aCusId, qint64 aDemand, QPair<qint64, qint64> aLocIds)
{
    if(mReqEntities.contains(aCusId))
    {
        mReqEntities[aCusId]->setDemand(aDemand);
        mReqEntities[aCusId]->setPUPos(mLocsPosHash.value(aLocIds.first));
        mReqEntities[aCusId]->setDLPos(mLocsPosHash.value(aLocIds.second));
        mReqEntities[aCusId]->setLocIds(aLocIds);
    }
}

//==========================================
//Conversion
QPair<qint64,qint64> MapViewManager::CoordToPos(QPair<double, double> aCoord)
{
    double tLat = aCoord.first;
    double tLong = aCoord.second;
    qint64 tX = (qint64)(23283*(tLong-103.809860)) + 113;
    qint64 tY = (qint64)((-23196.84)*(tLat-1.258115)) + 78;
    QPair<qint64,qint64> tRetPair(tX,tY);
    return tRetPair;
}

QPair<double,double> MapViewManager::PosToCoord(QPair<qint64, qint64> aPos)
{
    qint64 tX = aPos.first;
    qint64 tY = aPos.second;
    double tLat = (double)((tY-78)/(-23196.84))+1.258115;
    double tLong = (double)((tX-113)/23283.0)+103.809860;
    QPair<double,double> tRetPair(tLat,tLong);
    return tRetPair;
}
