#-------------------------------------------------
#
# Project created by QtCreator 2017-04-12T10:22:54
#
#-------------------------------------------------

QT       += core gui sql network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

include (../../../Project.pri)


#PROJDIR = /proj/airbase
#INCLUDEPATH += $$PROJDIR/include
#LIBS += -L$$PROJDIR/lib

#LIBS += -lfms_Utils
#LIBS += -lfms_Entity
#LIBS += -lSTKCI
#LIBS += -lFMSInterf/acesCommon
INCLUDEPATH += $$KXRCOMMONPATH

LIBS += -L$$PROJDIR/lib
LIBS += -lRMSDatabaseAccessVRP
LIBS += -lRMSDatabase
LIBS += -lRMSDatabaseData

TARGET = VRPTest
TEMPLATE = app
OBJECTS_DIR = $$PROJDIR/build/component/$$TARGET
MOC_DIR = $$OBJECTS_DIR
RCC_DIR = $$OBJECTS_DIR
DESTDIR = $$PROJDIR/bin/FMS
CONFIG += console
CONFIG += c++11

#Specific Dependencies
LIBS += -lSTKCIEXampleMsgCommon

#Common Libraries
include (../../ProjectCommonLibs.pri)

SOURCES += main.cpp\
        testwindow.cpp \
    vrptest_stkci_sub.cpp \
    vrptest_stkci_pub.cpp \
    vrptest_db.cpp \
#    manager.cpp \
    cusconfirmdialog.cpp \
#    vrptest_db_pub.cpp \
#    vrptest_db_sub.cpp \
    primeui.cpp \
    mapviewmanager.cpp \
    mapviewobjects.cpp \
    primeui_UISlots.cpp \
    primeui_publicSlots.cpp \
    primeui_privateFuncs.cpp \
    FmsDbReader.cpp \
#    ClientSubscriber.cpp \
#    ClientPublisher.cpp \
#    ClientDBSubscriber.cpp \
    ClientDBController.cpp

HEADERS  += testwindow.h \
    vrptest_stkci_sub.h \
    vrptest_stkci_pub.h \
    vrptest_db.h \
#    manager.h \
    cusconfirmdialog.h \
#    vrptest_db_pub.h \
#    vrptest_db_sub.h \
    primeui.h \
    mapviewmanager.h \
    mapviewobjects.h \
    FmsDbReader.h \
#    ClientSubscriber.h \
#    ClientPublisher.h \
#    ClientDBSubscriber.h \
    ClientDBController.h

FORMS    += testwindow.ui \
    cusconfirmdialog.ui \
    primeui.ui

OTHER_FILES += \
    TestConfigFile.xml \
    TestRTIConfig.xml \
    VRPInterfaceConfigFile.xml \
    VRPTestConfigurables.xml
