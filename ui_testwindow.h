/********************************************************************************
** Form generated from reading UI file 'testwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTWINDOW_H
#define UI_TESTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TestWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_4;
    QLabel *generic_loc_label;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_29;
    QLabel *loc_lid_label;
    QLineEdit *loc_lid_edit;
    QHBoxLayout *horizontalLayout_32;
    QHBoxLayout *horizontalLayout_30;
    QLabel *loc_lat_label;
    QLineEdit *loc_lat_edit;
    QHBoxLayout *horizontalLayout_31;
    QLabel *loc_long_label;
    QLineEdit *loc_long_edit;
    QHBoxLayout *horizontalLayout_33;
    QPushButton *loc_register_btn;
    QPushButton *loc_deregister_btn;
    QPushButton *loc_update_btn;
    QSpacerItem *verticalSpacer;
    QLabel *generic_veh_label;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_11;
    QLabel *veh_vid_label;
    QLineEdit *veh_vid_edit;
    QHBoxLayout *horizontalLayout_22;
    QHBoxLayout *horizontalLayout_13;
    QLabel *veh_lat_label;
    QLineEdit *veh_lat_edit;
    QHBoxLayout *horizontalLayout_14;
    QLabel *veh_long_label;
    QLineEdit *veh_long_edit;
    QPushButton *veh_latlong_btn;
    QHBoxLayout *horizontalLayout_24;
    QHBoxLayout *horizontalLayout_15;
    QLabel *veh_capacity_label;
    QLineEdit *veh_capacity_edit;
    QPushButton *veh_capacity_btn;
    QHBoxLayout *horizontalLayout_16;
    QLabel *veh_speed_label;
    QLineEdit *veh_speed_edit;
    QPushButton *veh_speed_btn;
    QHBoxLayout *horizontalLayout_25;
    QHBoxLayout *horizontalLayout_17;
    QLabel *veh_rftime_label;
    QLineEdit *veh_rftime_edit;
    QPushButton *veh_rftime_btn;
    QHBoxLayout *horizontalLayout_18;
    QLabel *veh_ftime_label;
    QLineEdit *veh_ftime_edit;
    QPushButton *veh_ftime_btn;
    QHBoxLayout *horizontalLayout_26;
    QHBoxLayout *horizontalLayout_19;
    QLabel *veh_utime_label;
    QLineEdit *veh_utime_edit;
    QPushButton *veh_utime_btn;
    QHBoxLayout *horizontalLayout_20;
    QLabel *veh_btime_label;
    QLineEdit *veh_btime_edit;
    QPushButton *veh_btime_btn;
    QHBoxLayout *horizontalLayout_27;
    QHBoxLayout *horizontalLayout_12;
    QLabel *veh_depot_label;
    QLineEdit *veh_depot_edit;
    QPushButton *veh_depot_btn;
    QHBoxLayout *horizontalLayout_21;
    QLabel *veh_lcost_label;
    QLineEdit *veh_lcost_edit;
    QPushButton *veh_lcost_btn;
    QHBoxLayout *horizontalLayout_23;
    QPushButton *veh_register_btn;
    QPushButton *veh_deregister_btn;
    QPushButton *clean_veh_btn;
    QSpacerItem *verticalSpacer_2;
    QLabel *generic_cus_label;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_7;
    QHBoxLayout *horizontalLayout_2;
    QLabel *cus_cid_label;
    QLineEdit *cus_cid_edit;
    QHBoxLayout *horizontalLayout;
    QLabel *cus_dmd_label;
    QLineEdit *cus_dmd_edit;
    QHBoxLayout *horizontalLayout_8;
    QHBoxLayout *horizontalLayout_3;
    QLabel *cus_ploc_label;
    QLineEdit *cus_ploc_edit;
    QHBoxLayout *horizontalLayout_4;
    QLabel *cus_dloc_label;
    QLineEdit *cus_dloc_edit;
    QHBoxLayout *horizontalLayout_9;
    QHBoxLayout *horizontalLayout_5;
    QLabel *cus_rtime_label;
    QLineEdit *cus_rtime_edit;
    QHBoxLayout *horizontalLayout_6;
    QLabel *cus_wtime_label;
    QLineEdit *cus_wtime_edit;
    QHBoxLayout *horizontalLayout_10;
    QPushButton *cus_register_btn;
    QPushButton *cus_deregister_btn;
    QPushButton *cus_chgreg_btn;
    QPushButton *clean_cus_btn;
    QSpacerItem *verticalSpacer_3;
    QLabel *generic_evt_label;
    QHBoxLayout *horizontalLayout_34;
    QLabel *evt_curTime_label;
    QLineEdit *evt_curTime_edit;
    QPushButton *evt_curTime_btn;
    QHBoxLayout *horizontalLayout_28;
    QLabel *evt_vid_label;
    QLineEdit *evt_vid_edit;
    QLabel *evt_cid_label;
    QLineEdit *evt_cid_edit;
    QLabel *evt_dmd_label;
    QLineEdit *evt_dmd_edit;
    QPushButton *evt_arrive_btn;
    QPushButton *pushButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *TestWindow)
    {
        if (TestWindow->objectName().isEmpty())
            TestWindow->setObjectName(QStringLiteral("TestWindow"));
        TestWindow->resize(461, 848);
        centralWidget = new QWidget(TestWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_4 = new QVBoxLayout(centralWidget);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        generic_loc_label = new QLabel(centralWidget);
        generic_loc_label->setObjectName(QStringLiteral("generic_loc_label"));

        verticalLayout_4->addWidget(generic_loc_label);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_29 = new QHBoxLayout();
        horizontalLayout_29->setSpacing(6);
        horizontalLayout_29->setObjectName(QStringLiteral("horizontalLayout_29"));
        loc_lid_label = new QLabel(centralWidget);
        loc_lid_label->setObjectName(QStringLiteral("loc_lid_label"));

        horizontalLayout_29->addWidget(loc_lid_label);

        loc_lid_edit = new QLineEdit(centralWidget);
        loc_lid_edit->setObjectName(QStringLiteral("loc_lid_edit"));

        horizontalLayout_29->addWidget(loc_lid_edit);


        verticalLayout_3->addLayout(horizontalLayout_29);

        horizontalLayout_32 = new QHBoxLayout();
        horizontalLayout_32->setSpacing(6);
        horizontalLayout_32->setObjectName(QStringLiteral("horizontalLayout_32"));
        horizontalLayout_30 = new QHBoxLayout();
        horizontalLayout_30->setSpacing(6);
        horizontalLayout_30->setObjectName(QStringLiteral("horizontalLayout_30"));
        loc_lat_label = new QLabel(centralWidget);
        loc_lat_label->setObjectName(QStringLiteral("loc_lat_label"));

        horizontalLayout_30->addWidget(loc_lat_label);

        loc_lat_edit = new QLineEdit(centralWidget);
        loc_lat_edit->setObjectName(QStringLiteral("loc_lat_edit"));

        horizontalLayout_30->addWidget(loc_lat_edit);


        horizontalLayout_32->addLayout(horizontalLayout_30);

        horizontalLayout_31 = new QHBoxLayout();
        horizontalLayout_31->setSpacing(6);
        horizontalLayout_31->setObjectName(QStringLiteral("horizontalLayout_31"));
        loc_long_label = new QLabel(centralWidget);
        loc_long_label->setObjectName(QStringLiteral("loc_long_label"));

        horizontalLayout_31->addWidget(loc_long_label);

        loc_long_edit = new QLineEdit(centralWidget);
        loc_long_edit->setObjectName(QStringLiteral("loc_long_edit"));

        horizontalLayout_31->addWidget(loc_long_edit);


        horizontalLayout_32->addLayout(horizontalLayout_31);


        verticalLayout_3->addLayout(horizontalLayout_32);

        horizontalLayout_33 = new QHBoxLayout();
        horizontalLayout_33->setSpacing(6);
        horizontalLayout_33->setObjectName(QStringLiteral("horizontalLayout_33"));
        loc_register_btn = new QPushButton(centralWidget);
        loc_register_btn->setObjectName(QStringLiteral("loc_register_btn"));

        horizontalLayout_33->addWidget(loc_register_btn);

        loc_deregister_btn = new QPushButton(centralWidget);
        loc_deregister_btn->setObjectName(QStringLiteral("loc_deregister_btn"));

        horizontalLayout_33->addWidget(loc_deregister_btn);

        loc_update_btn = new QPushButton(centralWidget);
        loc_update_btn->setObjectName(QStringLiteral("loc_update_btn"));

        horizontalLayout_33->addWidget(loc_update_btn);


        verticalLayout_3->addLayout(horizontalLayout_33);


        verticalLayout_4->addLayout(verticalLayout_3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);

        generic_veh_label = new QLabel(centralWidget);
        generic_veh_label->setObjectName(QStringLiteral("generic_veh_label"));

        verticalLayout_4->addWidget(generic_veh_label);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        veh_vid_label = new QLabel(centralWidget);
        veh_vid_label->setObjectName(QStringLiteral("veh_vid_label"));

        horizontalLayout_11->addWidget(veh_vid_label);

        veh_vid_edit = new QLineEdit(centralWidget);
        veh_vid_edit->setObjectName(QStringLiteral("veh_vid_edit"));

        horizontalLayout_11->addWidget(veh_vid_edit);


        verticalLayout_2->addLayout(horizontalLayout_11);

        horizontalLayout_22 = new QHBoxLayout();
        horizontalLayout_22->setSpacing(6);
        horizontalLayout_22->setObjectName(QStringLiteral("horizontalLayout_22"));
        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        veh_lat_label = new QLabel(centralWidget);
        veh_lat_label->setObjectName(QStringLiteral("veh_lat_label"));

        horizontalLayout_13->addWidget(veh_lat_label);

        veh_lat_edit = new QLineEdit(centralWidget);
        veh_lat_edit->setObjectName(QStringLiteral("veh_lat_edit"));

        horizontalLayout_13->addWidget(veh_lat_edit);


        horizontalLayout_22->addLayout(horizontalLayout_13);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        veh_long_label = new QLabel(centralWidget);
        veh_long_label->setObjectName(QStringLiteral("veh_long_label"));

        horizontalLayout_14->addWidget(veh_long_label);

        veh_long_edit = new QLineEdit(centralWidget);
        veh_long_edit->setObjectName(QStringLiteral("veh_long_edit"));

        horizontalLayout_14->addWidget(veh_long_edit);


        horizontalLayout_22->addLayout(horizontalLayout_14);

        veh_latlong_btn = new QPushButton(centralWidget);
        veh_latlong_btn->setObjectName(QStringLiteral("veh_latlong_btn"));

        horizontalLayout_22->addWidget(veh_latlong_btn);


        verticalLayout_2->addLayout(horizontalLayout_22);

        horizontalLayout_24 = new QHBoxLayout();
        horizontalLayout_24->setSpacing(6);
        horizontalLayout_24->setObjectName(QStringLiteral("horizontalLayout_24"));
        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setSpacing(6);
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        veh_capacity_label = new QLabel(centralWidget);
        veh_capacity_label->setObjectName(QStringLiteral("veh_capacity_label"));

        horizontalLayout_15->addWidget(veh_capacity_label);

        veh_capacity_edit = new QLineEdit(centralWidget);
        veh_capacity_edit->setObjectName(QStringLiteral("veh_capacity_edit"));

        horizontalLayout_15->addWidget(veh_capacity_edit);

        veh_capacity_btn = new QPushButton(centralWidget);
        veh_capacity_btn->setObjectName(QStringLiteral("veh_capacity_btn"));

        horizontalLayout_15->addWidget(veh_capacity_btn);


        horizontalLayout_24->addLayout(horizontalLayout_15);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setSpacing(6);
        horizontalLayout_16->setObjectName(QStringLiteral("horizontalLayout_16"));
        veh_speed_label = new QLabel(centralWidget);
        veh_speed_label->setObjectName(QStringLiteral("veh_speed_label"));

        horizontalLayout_16->addWidget(veh_speed_label);

        veh_speed_edit = new QLineEdit(centralWidget);
        veh_speed_edit->setObjectName(QStringLiteral("veh_speed_edit"));

        horizontalLayout_16->addWidget(veh_speed_edit);

        veh_speed_btn = new QPushButton(centralWidget);
        veh_speed_btn->setObjectName(QStringLiteral("veh_speed_btn"));

        horizontalLayout_16->addWidget(veh_speed_btn);


        horizontalLayout_24->addLayout(horizontalLayout_16);


        verticalLayout_2->addLayout(horizontalLayout_24);

        horizontalLayout_25 = new QHBoxLayout();
        horizontalLayout_25->setSpacing(6);
        horizontalLayout_25->setObjectName(QStringLiteral("horizontalLayout_25"));
        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setSpacing(6);
        horizontalLayout_17->setObjectName(QStringLiteral("horizontalLayout_17"));
        veh_rftime_label = new QLabel(centralWidget);
        veh_rftime_label->setObjectName(QStringLiteral("veh_rftime_label"));

        horizontalLayout_17->addWidget(veh_rftime_label);

        veh_rftime_edit = new QLineEdit(centralWidget);
        veh_rftime_edit->setObjectName(QStringLiteral("veh_rftime_edit"));

        horizontalLayout_17->addWidget(veh_rftime_edit);

        veh_rftime_btn = new QPushButton(centralWidget);
        veh_rftime_btn->setObjectName(QStringLiteral("veh_rftime_btn"));

        horizontalLayout_17->addWidget(veh_rftime_btn);


        horizontalLayout_25->addLayout(horizontalLayout_17);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setSpacing(6);
        horizontalLayout_18->setObjectName(QStringLiteral("horizontalLayout_18"));
        veh_ftime_label = new QLabel(centralWidget);
        veh_ftime_label->setObjectName(QStringLiteral("veh_ftime_label"));

        horizontalLayout_18->addWidget(veh_ftime_label);

        veh_ftime_edit = new QLineEdit(centralWidget);
        veh_ftime_edit->setObjectName(QStringLiteral("veh_ftime_edit"));

        horizontalLayout_18->addWidget(veh_ftime_edit);

        veh_ftime_btn = new QPushButton(centralWidget);
        veh_ftime_btn->setObjectName(QStringLiteral("veh_ftime_btn"));

        horizontalLayout_18->addWidget(veh_ftime_btn);


        horizontalLayout_25->addLayout(horizontalLayout_18);


        verticalLayout_2->addLayout(horizontalLayout_25);

        horizontalLayout_26 = new QHBoxLayout();
        horizontalLayout_26->setSpacing(6);
        horizontalLayout_26->setObjectName(QStringLiteral("horizontalLayout_26"));
        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setSpacing(6);
        horizontalLayout_19->setObjectName(QStringLiteral("horizontalLayout_19"));
        veh_utime_label = new QLabel(centralWidget);
        veh_utime_label->setObjectName(QStringLiteral("veh_utime_label"));

        horizontalLayout_19->addWidget(veh_utime_label);

        veh_utime_edit = new QLineEdit(centralWidget);
        veh_utime_edit->setObjectName(QStringLiteral("veh_utime_edit"));

        horizontalLayout_19->addWidget(veh_utime_edit);

        veh_utime_btn = new QPushButton(centralWidget);
        veh_utime_btn->setObjectName(QStringLiteral("veh_utime_btn"));

        horizontalLayout_19->addWidget(veh_utime_btn);


        horizontalLayout_26->addLayout(horizontalLayout_19);

        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setSpacing(6);
        horizontalLayout_20->setObjectName(QStringLiteral("horizontalLayout_20"));
        veh_btime_label = new QLabel(centralWidget);
        veh_btime_label->setObjectName(QStringLiteral("veh_btime_label"));

        horizontalLayout_20->addWidget(veh_btime_label);

        veh_btime_edit = new QLineEdit(centralWidget);
        veh_btime_edit->setObjectName(QStringLiteral("veh_btime_edit"));

        horizontalLayout_20->addWidget(veh_btime_edit);

        veh_btime_btn = new QPushButton(centralWidget);
        veh_btime_btn->setObjectName(QStringLiteral("veh_btime_btn"));

        horizontalLayout_20->addWidget(veh_btime_btn);


        horizontalLayout_26->addLayout(horizontalLayout_20);


        verticalLayout_2->addLayout(horizontalLayout_26);

        horizontalLayout_27 = new QHBoxLayout();
        horizontalLayout_27->setSpacing(6);
        horizontalLayout_27->setObjectName(QStringLiteral("horizontalLayout_27"));
        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        veh_depot_label = new QLabel(centralWidget);
        veh_depot_label->setObjectName(QStringLiteral("veh_depot_label"));

        horizontalLayout_12->addWidget(veh_depot_label);

        veh_depot_edit = new QLineEdit(centralWidget);
        veh_depot_edit->setObjectName(QStringLiteral("veh_depot_edit"));

        horizontalLayout_12->addWidget(veh_depot_edit);

        veh_depot_btn = new QPushButton(centralWidget);
        veh_depot_btn->setObjectName(QStringLiteral("veh_depot_btn"));

        horizontalLayout_12->addWidget(veh_depot_btn);


        horizontalLayout_27->addLayout(horizontalLayout_12);

        horizontalLayout_21 = new QHBoxLayout();
        horizontalLayout_21->setSpacing(6);
        horizontalLayout_21->setObjectName(QStringLiteral("horizontalLayout_21"));
        veh_lcost_label = new QLabel(centralWidget);
        veh_lcost_label->setObjectName(QStringLiteral("veh_lcost_label"));

        horizontalLayout_21->addWidget(veh_lcost_label);

        veh_lcost_edit = new QLineEdit(centralWidget);
        veh_lcost_edit->setObjectName(QStringLiteral("veh_lcost_edit"));

        horizontalLayout_21->addWidget(veh_lcost_edit);

        veh_lcost_btn = new QPushButton(centralWidget);
        veh_lcost_btn->setObjectName(QStringLiteral("veh_lcost_btn"));

        horizontalLayout_21->addWidget(veh_lcost_btn);


        horizontalLayout_27->addLayout(horizontalLayout_21);


        verticalLayout_2->addLayout(horizontalLayout_27);

        horizontalLayout_23 = new QHBoxLayout();
        horizontalLayout_23->setSpacing(6);
        horizontalLayout_23->setObjectName(QStringLiteral("horizontalLayout_23"));
        veh_register_btn = new QPushButton(centralWidget);
        veh_register_btn->setObjectName(QStringLiteral("veh_register_btn"));

        horizontalLayout_23->addWidget(veh_register_btn);

        veh_deregister_btn = new QPushButton(centralWidget);
        veh_deregister_btn->setObjectName(QStringLiteral("veh_deregister_btn"));

        horizontalLayout_23->addWidget(veh_deregister_btn);


        verticalLayout_2->addLayout(horizontalLayout_23);

        clean_veh_btn = new QPushButton(centralWidget);
        clean_veh_btn->setObjectName(QStringLiteral("clean_veh_btn"));

        verticalLayout_2->addWidget(clean_veh_btn);


        verticalLayout_4->addLayout(verticalLayout_2);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_2);

        generic_cus_label = new QLabel(centralWidget);
        generic_cus_label->setObjectName(QStringLiteral("generic_cus_label"));

        verticalLayout_4->addWidget(generic_cus_label);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        cus_cid_label = new QLabel(centralWidget);
        cus_cid_label->setObjectName(QStringLiteral("cus_cid_label"));

        horizontalLayout_2->addWidget(cus_cid_label);

        cus_cid_edit = new QLineEdit(centralWidget);
        cus_cid_edit->setObjectName(QStringLiteral("cus_cid_edit"));

        horizontalLayout_2->addWidget(cus_cid_edit);


        horizontalLayout_7->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        cus_dmd_label = new QLabel(centralWidget);
        cus_dmd_label->setObjectName(QStringLiteral("cus_dmd_label"));

        horizontalLayout->addWidget(cus_dmd_label);

        cus_dmd_edit = new QLineEdit(centralWidget);
        cus_dmd_edit->setObjectName(QStringLiteral("cus_dmd_edit"));

        horizontalLayout->addWidget(cus_dmd_edit);


        horizontalLayout_7->addLayout(horizontalLayout);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        cus_ploc_label = new QLabel(centralWidget);
        cus_ploc_label->setObjectName(QStringLiteral("cus_ploc_label"));

        horizontalLayout_3->addWidget(cus_ploc_label);

        cus_ploc_edit = new QLineEdit(centralWidget);
        cus_ploc_edit->setObjectName(QStringLiteral("cus_ploc_edit"));

        horizontalLayout_3->addWidget(cus_ploc_edit);


        horizontalLayout_8->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        cus_dloc_label = new QLabel(centralWidget);
        cus_dloc_label->setObjectName(QStringLiteral("cus_dloc_label"));

        horizontalLayout_4->addWidget(cus_dloc_label);

        cus_dloc_edit = new QLineEdit(centralWidget);
        cus_dloc_edit->setObjectName(QStringLiteral("cus_dloc_edit"));

        horizontalLayout_4->addWidget(cus_dloc_edit);


        horizontalLayout_8->addLayout(horizontalLayout_4);


        verticalLayout->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        cus_rtime_label = new QLabel(centralWidget);
        cus_rtime_label->setObjectName(QStringLiteral("cus_rtime_label"));

        horizontalLayout_5->addWidget(cus_rtime_label);

        cus_rtime_edit = new QLineEdit(centralWidget);
        cus_rtime_edit->setObjectName(QStringLiteral("cus_rtime_edit"));

        horizontalLayout_5->addWidget(cus_rtime_edit);


        horizontalLayout_9->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        cus_wtime_label = new QLabel(centralWidget);
        cus_wtime_label->setObjectName(QStringLiteral("cus_wtime_label"));

        horizontalLayout_6->addWidget(cus_wtime_label);

        cus_wtime_edit = new QLineEdit(centralWidget);
        cus_wtime_edit->setObjectName(QStringLiteral("cus_wtime_edit"));

        horizontalLayout_6->addWidget(cus_wtime_edit);


        horizontalLayout_9->addLayout(horizontalLayout_6);


        verticalLayout->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        cus_register_btn = new QPushButton(centralWidget);
        cus_register_btn->setObjectName(QStringLiteral("cus_register_btn"));

        horizontalLayout_10->addWidget(cus_register_btn);

        cus_deregister_btn = new QPushButton(centralWidget);
        cus_deregister_btn->setObjectName(QStringLiteral("cus_deregister_btn"));

        horizontalLayout_10->addWidget(cus_deregister_btn);

        cus_chgreg_btn = new QPushButton(centralWidget);
        cus_chgreg_btn->setObjectName(QStringLiteral("cus_chgreg_btn"));

        horizontalLayout_10->addWidget(cus_chgreg_btn);


        verticalLayout->addLayout(horizontalLayout_10);

        clean_cus_btn = new QPushButton(centralWidget);
        clean_cus_btn->setObjectName(QStringLiteral("clean_cus_btn"));

        verticalLayout->addWidget(clean_cus_btn);


        verticalLayout_4->addLayout(verticalLayout);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_3);

        generic_evt_label = new QLabel(centralWidget);
        generic_evt_label->setObjectName(QStringLiteral("generic_evt_label"));

        verticalLayout_4->addWidget(generic_evt_label);

        horizontalLayout_34 = new QHBoxLayout();
        horizontalLayout_34->setSpacing(6);
        horizontalLayout_34->setObjectName(QStringLiteral("horizontalLayout_34"));
        evt_curTime_label = new QLabel(centralWidget);
        evt_curTime_label->setObjectName(QStringLiteral("evt_curTime_label"));

        horizontalLayout_34->addWidget(evt_curTime_label);

        evt_curTime_edit = new QLineEdit(centralWidget);
        evt_curTime_edit->setObjectName(QStringLiteral("evt_curTime_edit"));

        horizontalLayout_34->addWidget(evt_curTime_edit);

        evt_curTime_btn = new QPushButton(centralWidget);
        evt_curTime_btn->setObjectName(QStringLiteral("evt_curTime_btn"));

        horizontalLayout_34->addWidget(evt_curTime_btn);


        verticalLayout_4->addLayout(horizontalLayout_34);

        horizontalLayout_28 = new QHBoxLayout();
        horizontalLayout_28->setSpacing(6);
        horizontalLayout_28->setObjectName(QStringLiteral("horizontalLayout_28"));
        evt_vid_label = new QLabel(centralWidget);
        evt_vid_label->setObjectName(QStringLiteral("evt_vid_label"));

        horizontalLayout_28->addWidget(evt_vid_label);

        evt_vid_edit = new QLineEdit(centralWidget);
        evt_vid_edit->setObjectName(QStringLiteral("evt_vid_edit"));

        horizontalLayout_28->addWidget(evt_vid_edit);

        evt_cid_label = new QLabel(centralWidget);
        evt_cid_label->setObjectName(QStringLiteral("evt_cid_label"));

        horizontalLayout_28->addWidget(evt_cid_label);

        evt_cid_edit = new QLineEdit(centralWidget);
        evt_cid_edit->setObjectName(QStringLiteral("evt_cid_edit"));

        horizontalLayout_28->addWidget(evt_cid_edit);

        evt_dmd_label = new QLabel(centralWidget);
        evt_dmd_label->setObjectName(QStringLiteral("evt_dmd_label"));

        horizontalLayout_28->addWidget(evt_dmd_label);

        evt_dmd_edit = new QLineEdit(centralWidget);
        evt_dmd_edit->setObjectName(QStringLiteral("evt_dmd_edit"));

        horizontalLayout_28->addWidget(evt_dmd_edit);

        evt_arrive_btn = new QPushButton(centralWidget);
        evt_arrive_btn->setObjectName(QStringLiteral("evt_arrive_btn"));

        horizontalLayout_28->addWidget(evt_arrive_btn);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout_28->addWidget(pushButton);


        verticalLayout_4->addLayout(horizontalLayout_28);

        TestWindow->setCentralWidget(centralWidget);
        generic_evt_label->raise();
        generic_cus_label->raise();
        generic_veh_label->raise();
        generic_loc_label->raise();
        menuBar = new QMenuBar(TestWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 461, 27));
        TestWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(TestWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        TestWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(TestWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        TestWindow->setStatusBar(statusBar);

        retranslateUi(TestWindow);

        QMetaObject::connectSlotsByName(TestWindow);
    } // setupUi

    void retranslateUi(QMainWindow *TestWindow)
    {
        TestWindow->setWindowTitle(QApplication::translate("TestWindow", "TestWindow", 0));
        generic_loc_label->setText(QApplication::translate("TestWindow", "Loc", 0));
        loc_lid_label->setText(QApplication::translate("TestWindow", "lid", 0));
        loc_lat_label->setText(QApplication::translate("TestWindow", "lat", 0));
        loc_long_label->setText(QApplication::translate("TestWindow", "long", 0));
        loc_register_btn->setText(QApplication::translate("TestWindow", "register", 0));
        loc_deregister_btn->setText(QApplication::translate("TestWindow", "deregister", 0));
        loc_update_btn->setText(QApplication::translate("TestWindow", "update", 0));
        generic_veh_label->setText(QApplication::translate("TestWindow", "Veh", 0));
        veh_vid_label->setText(QApplication::translate("TestWindow", "vid", 0));
        veh_lat_label->setText(QApplication::translate("TestWindow", "lat", 0));
        veh_long_label->setText(QApplication::translate("TestWindow", "long", 0));
        veh_latlong_btn->setText(QApplication::translate("TestWindow", "set", 0));
        veh_capacity_label->setText(QApplication::translate("TestWindow", "capacity", 0));
        veh_capacity_btn->setText(QApplication::translate("TestWindow", "set", 0));
        veh_speed_label->setText(QApplication::translate("TestWindow", "speed", 0));
        veh_speed_btn->setText(QApplication::translate("TestWindow", "set", 0));
        veh_rftime_label->setText(QApplication::translate("TestWindow", "rfTime", 0));
        veh_rftime_btn->setText(QApplication::translate("TestWindow", "set", 0));
        veh_ftime_label->setText(QApplication::translate("TestWindow", "fTime", 0));
        veh_ftime_btn->setText(QApplication::translate("TestWindow", "set", 0));
        veh_utime_label->setText(QApplication::translate("TestWindow", "uTime", 0));
        veh_utime_btn->setText(QApplication::translate("TestWindow", "set", 0));
        veh_btime_label->setText(QApplication::translate("TestWindow", "bTime", 0));
        veh_btime_btn->setText(QApplication::translate("TestWindow", "set", 0));
        veh_depot_label->setText(QApplication::translate("TestWindow", "depot", 0));
        veh_depot_btn->setText(QApplication::translate("TestWindow", "set", 0));
        veh_lcost_label->setText(QApplication::translate("TestWindow", "lCost", 0));
        veh_lcost_btn->setText(QApplication::translate("TestWindow", "set", 0));
        veh_register_btn->setText(QApplication::translate("TestWindow", "register", 0));
        veh_deregister_btn->setText(QApplication::translate("TestWindow", "deregister", 0));
        clean_veh_btn->setText(QApplication::translate("TestWindow", "Clean Veh Edit", 0));
        generic_cus_label->setText(QApplication::translate("TestWindow", "Cus", 0));
        cus_cid_label->setText(QApplication::translate("TestWindow", "cid", 0));
        cus_dmd_label->setText(QApplication::translate("TestWindow", "demand", 0));
        cus_ploc_label->setText(QApplication::translate("TestWindow", "pLoc", 0));
        cus_dloc_label->setText(QApplication::translate("TestWindow", "dLoc", 0));
        cus_rtime_label->setText(QApplication::translate("TestWindow", "rTime", 0));
        cus_wtime_label->setText(QApplication::translate("TestWindow", "wTime", 0));
        cus_register_btn->setText(QApplication::translate("TestWindow", "register", 0));
        cus_deregister_btn->setText(QApplication::translate("TestWindow", "deregister", 0));
        cus_chgreg_btn->setText(QApplication::translate("TestWindow", "chgreg", 0));
        clean_cus_btn->setText(QApplication::translate("TestWindow", "Clean Cus Edit", 0));
        generic_evt_label->setText(QApplication::translate("TestWindow", "Evt", 0));
        evt_curTime_label->setText(QApplication::translate("TestWindow", "currentTime", 0));
        evt_curTime_btn->setText(QApplication::translate("TestWindow", "set", 0));
        evt_vid_label->setText(QApplication::translate("TestWindow", "vid", 0));
        evt_cid_label->setText(QApplication::translate("TestWindow", "cid", 0));
        evt_dmd_label->setText(QApplication::translate("TestWindow", "demand", 0));
        evt_arrive_btn->setText(QApplication::translate("TestWindow", "arrive", 0));
        pushButton->setText(QApplication::translate("TestWindow", "backDepot", 0));
    } // retranslateUi

};

namespace Ui {
    class TestWindow: public Ui_TestWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTWINDOW_H
