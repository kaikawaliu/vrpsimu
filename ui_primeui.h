/********************************************************************************
** Form generated from reading UI file 'primeui.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRIMEUI_H
#define UI_PRIMEUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PrimeUI
{
public:
    QVBoxLayout *verticalLayout_33;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_43;
    QLabel *timeLabel;
    QLabel *timeDataLabel;
    QLabel *simTimeLabel;
    QLabel *simTimeDataLabel;
    QLabel *startHourLabel;
    QSpinBox *startHourSpBox;
    QLabel *endHourLabel;
    QSpinBox *endHourSpBox;
    QPushButton *opTimeBtn;
    QPushButton *resetBtn;
    QGraphicsView *graphicsView;
    QHBoxLayout *horizontalLayout_44;
    QLabel *posLabel;
    QLabel *posDataLabel;
    QLabel *coordLabel;
    QLabel *coordDataLabel;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QPushButton *monBtn;
    QPushButton *locManBtn;
    QPushButton *vehManBtn;
    QPushButton *cusManBtn;
    QPushButton *evtManBtn;
    QPushButton *OptionsBtn;
    QStackedWidget *primaryStackedWidget;
    QWidget *monPage;
    QVBoxLayout *verticalLayout_25;
    QVBoxLayout *verticalLayout_24;
    QLabel *monLabel;
    QHBoxLayout *horizontalLayout_42;
    QToolBox *monToolBox;
    QWidget *MonLocPage;
    QWidget *MonVehPage;
    QPushButton *monVehStatusBtn;
    QPushButton *monVehJobsBtn;
    QPushButton *monVehDistBtn;
    QWidget *MonCusPage;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_2;
    QFrame *frame1;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_46;
    QLabel *MonListWidgetLabel;
    QListWidget *monListWidget;
    QFrame *frame2;
    QVBoxLayout *verticalLayout_36;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_58;
    QLabel *MonTableWidgetLabel;
    QTableWidget *MonTableWidget;
    QWidget *locationManagerPage;
    QVBoxLayout *verticalLayout_26;
    QVBoxLayout *verticalLayout_7;
    QLabel *locManLabel;
    QHBoxLayout *horizontalLayout_6;
    QFrame *frame3;
    QHBoxLayout *horizontalLayout_48;
    QHBoxLayout *horizontalLayout_47;
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout_9;
    QLabel *locTableLabel;
    QTableWidget *locTableWidget;
    QVBoxLayout *verticalLayout_6;
    QPushButton *locRegBtn;
    QPushButton *locDeregBtn;
    QPushButton *locUpdateBtn;
    QFrame *frame4;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_7;
    QLabel *locIdLabel;
    QLineEdit *locIdEdit;
    QFrame *frame_2;
    QVBoxLayout *verticalLayout_35;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *LLGetCoordBtn;
    QVBoxLayout *verticalLayout_34;
    QHBoxLayout *horizontalLayout_3;
    QLabel *locLatLabel;
    QLineEdit *locLatEdit;
    QHBoxLayout *horizontalLayout_4;
    QLabel *locLongLabel;
    QLineEdit *locLongEdit;
    QPushButton *LLReflectBtn;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *locConfirmBtn;
    QPushButton *locCancelBtn;
    QWidget *vehicleManagerPage;
    QVBoxLayout *verticalLayout_27;
    QVBoxLayout *verticalLayout_11;
    QLabel *vehManLabel;
    QHBoxLayout *horizontalLayout_27;
    QFrame *frame5;
    QHBoxLayout *horizontalLayout_49;
    QVBoxLayout *verticalLayout_12;
    QHBoxLayout *horizontalLayout_26;
    QLabel *vehTableLabel;
    QTableWidget *vehTableWidget;
    QVBoxLayout *verticalLayout_9;
    QPushButton *vehRegBtn;
    QPushButton *vehDeregBtn;
    QPushButton *vehUpdateBtn;
    QFrame *frame6;
    QVBoxLayout *verticalLayout_14;
    QHBoxLayout *horizontalLayout_13;
    QLabel *vehIdLabel;
    QLineEdit *vehIdEdit;
    QFrame *frame7;
    QVBoxLayout *verticalLayout_10;
    QCheckBox *vehCoordChBox;
    QHBoxLayout *horizontalLayout_12;
    QHBoxLayout *horizontalLayout_10;
    QLabel *vehLatLabel;
    QLineEdit *vehLatEdit;
    QHBoxLayout *horizontalLayout_11;
    QLabel *vehLongLabel;
    QLineEdit *vehLongEdit;
    QHBoxLayout *horizontalLayout_24;
    QPushButton *vehGetCoordBtn;
    QPushButton *vehRefCoordBtn;
    QHBoxLayout *horizontalLayout_14;
    QCheckBox *vehSpeedChBox;
    QLineEdit *vehSpeedEdit;
    QHBoxLayout *horizontalLayout_23;
    QHBoxLayout *horizontalLayout_16;
    QCheckBox *vehCapChBox;
    QSpinBox *vehCapSpBox;
    QHBoxLayout *horizontalLayout_20;
    QCheckBox *vehLCostChBox;
    QSpinBox *vehLCostSpBox;
    QFrame *frame8;
    QVBoxLayout *verticalLayout_13;
    QHBoxLayout *horizontalLayout_22;
    QHBoxLayout *horizontalLayout_17;
    QCheckBox *vehFTimeChBox;
    QSpinBox *vehFTimeSpBox;
    QHBoxLayout *horizontalLayout_18;
    QCheckBox *vehUTimeChBox;
    QSpinBox *vehUTimeSpBox;
    QHBoxLayout *horizontalLayout_21;
    QHBoxLayout *horizontalLayout_15;
    QCheckBox *vehRTimeChBox;
    QSpinBox *vehRTimeSpBox;
    QHBoxLayout *horizontalLayout_19;
    QCheckBox *vehBTimeChBox;
    QSpinBox *vehBTimeSpBox;
    QFrame *frame9;
    QHBoxLayout *horizontalLayout_25;
    QPushButton *vehDefaultBtn;
    QPushButton *vehConfirmBtn;
    QPushButton *vehCancelBtn;
    QWidget *customerManagerPage;
    QVBoxLayout *verticalLayout_28;
    QVBoxLayout *verticalLayout_19;
    QLabel *cusManLabel;
    QHBoxLayout *horizontalLayout_36;
    QFrame *frame10;
    QHBoxLayout *horizontalLayout_51;
    QHBoxLayout *horizontalLayout_50;
    QVBoxLayout *verticalLayout_20;
    QHBoxLayout *horizontalLayout_34;
    QLabel *cusTableLabel;
    QTableWidget *cusTableWidget;
    QVBoxLayout *verticalLayout_15;
    QPushButton *cusReqBtn;
    QPushButton *cusCancelReqBtn;
    QPushButton *cusChgReqBtn;
    QFrame *frame11;
    QVBoxLayout *verticalLayout_18;
    QHBoxLayout *horizontalLayout_33;
    QLabel *cusIdLabel;
    QLineEdit *cusIdEdit;
    QHBoxLayout *horizontalLayout_32;
    QCheckBox *cusDemandsChBox;
    QSpinBox *cusDemandsSpBox;
    QFrame *frame12;
    QVBoxLayout *verticalLayout_17;
    QHBoxLayout *horizontalLayout_31;
    QCheckBox *cusPULocChBox;
    QComboBox *cusPULocCoBox;
    QHBoxLayout *horizontalLayout_30;
    QCheckBox *cusDLocChBox;
    QComboBox *cusDLocCoBox;
    QFrame *frame13;
    QVBoxLayout *verticalLayout_16;
    QHBoxLayout *horizontalLayout_29;
    QCheckBox *cusRSTimeChBox;
    QComboBox *cusRSTimeCoBox;
    QLabel *cusRSTimeMinLabel;
    QHBoxLayout *horizontalLayout_28;
    QCheckBox *cusWTimeChBox;
    QComboBox *cusWTimeCoBox;
    QLabel *cusWTimeMinLabel;
    QFrame *frame14;
    QHBoxLayout *horizontalLayout_35;
    QPushButton *cusConfirmBtn;
    QPushButton *cusCancelBtn;
    QWidget *eventManagerPage;
    QVBoxLayout *verticalLayout_32;
    QVBoxLayout *verticalLayout_22;
    QLabel *evtManLabel;
    QFrame *frame15;
    QHBoxLayout *horizontalLayout_41;
    QFrame *frame16;
    QHBoxLayout *horizontalLayout_55;
    QHBoxLayout *horizontalLayout_54;
    QVBoxLayout *verticalLayout_23;
    QHBoxLayout *horizontalLayout_37;
    QLabel *evtVehTableLabel;
    QTableWidget *evtVehTableWidget;
    QVBoxLayout *verticalLayout_29;
    QHBoxLayout *horizontalLayout_38;
    QLabel *evtJobsTableLabel;
    QTableWidget *evtJobsTableWidget;
    QVBoxLayout *verticalLayout_21;
    QPushButton *evtVehArrBtn;
    QPushButton *evtVehBTDBtn;
    QFrame *frame17;
    QHBoxLayout *horizontalLayout_57;
    QHBoxLayout *horizontalLayout_56;
    QVBoxLayout *verticalLayout_30;
    QHBoxLayout *horizontalLayout_52;
    QLabel *evtCusAnsTableLabel;
    QTableWidget *evtCusAnsTableWidget;
    QHBoxLayout *horizontalLayout_45;
    QPushButton *evtCusAnsAcceptBtn;
    QPushButton *evtCusAnsRefuseBtn;
    QVBoxLayout *verticalLayout_31;
    QHBoxLayout *horizontalLayout_53;
    QLabel *evtLogTableLabel;
    QTableWidget *evtLogTableWidget;
    QFrame *frame18;
    QHBoxLayout *horizontalLayout_40;
    QPushButton *evtSetCurTimeBtn;
    QPushButton *evtResetTimeBtn;
    QFrame *frame19;
    QHBoxLayout *horizontalLayout_39;
    QSpinBox *evtHourSpBox;
    QSpinBox *evtMinuteSpBox;
    QSpinBox *evtSecondSpBox;
    QSpinBox *evtSimTimeSpBox;
    QPushButton *evtConfirmCurTimeBtn;
    QWidget *page;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;

    void setupUi(QWidget *PrimeUI)
    {
        if (PrimeUI->objectName().isEmpty())
            PrimeUI->setObjectName(QStringLiteral("PrimeUI"));
        PrimeUI->resize(1075, 1068);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(PrimeUI->sizePolicy().hasHeightForWidth());
        PrimeUI->setSizePolicy(sizePolicy);
        PrimeUI->setMinimumSize(QSize(1075, 0));
        PrimeUI->setMaximumSize(QSize(2000, 16777215));
        verticalLayout_33 = new QVBoxLayout(PrimeUI);
        verticalLayout_33->setObjectName(QStringLiteral("verticalLayout_33"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_43 = new QHBoxLayout();
        horizontalLayout_43->setObjectName(QStringLiteral("horizontalLayout_43"));
        timeLabel = new QLabel(PrimeUI);
        timeLabel->setObjectName(QStringLiteral("timeLabel"));

        horizontalLayout_43->addWidget(timeLabel);

        timeDataLabel = new QLabel(PrimeUI);
        timeDataLabel->setObjectName(QStringLiteral("timeDataLabel"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(timeDataLabel->sizePolicy().hasHeightForWidth());
        timeDataLabel->setSizePolicy(sizePolicy1);

        horizontalLayout_43->addWidget(timeDataLabel);

        simTimeLabel = new QLabel(PrimeUI);
        simTimeLabel->setObjectName(QStringLiteral("simTimeLabel"));

        horizontalLayout_43->addWidget(simTimeLabel);

        simTimeDataLabel = new QLabel(PrimeUI);
        simTimeDataLabel->setObjectName(QStringLiteral("simTimeDataLabel"));
        sizePolicy1.setHeightForWidth(simTimeDataLabel->sizePolicy().hasHeightForWidth());
        simTimeDataLabel->setSizePolicy(sizePolicy1);

        horizontalLayout_43->addWidget(simTimeDataLabel);

        startHourLabel = new QLabel(PrimeUI);
        startHourLabel->setObjectName(QStringLiteral("startHourLabel"));

        horizontalLayout_43->addWidget(startHourLabel);

        startHourSpBox = new QSpinBox(PrimeUI);
        startHourSpBox->setObjectName(QStringLiteral("startHourSpBox"));
        startHourSpBox->setMaximum(23);
        startHourSpBox->setValue(0);

        horizontalLayout_43->addWidget(startHourSpBox);

        endHourLabel = new QLabel(PrimeUI);
        endHourLabel->setObjectName(QStringLiteral("endHourLabel"));

        horizontalLayout_43->addWidget(endHourLabel);

        endHourSpBox = new QSpinBox(PrimeUI);
        endHourSpBox->setObjectName(QStringLiteral("endHourSpBox"));
        endHourSpBox->setMaximum(24);
        endHourSpBox->setValue(0);

        horizontalLayout_43->addWidget(endHourSpBox);

        opTimeBtn = new QPushButton(PrimeUI);
        opTimeBtn->setObjectName(QStringLiteral("opTimeBtn"));

        horizontalLayout_43->addWidget(opTimeBtn);

        resetBtn = new QPushButton(PrimeUI);
        resetBtn->setObjectName(QStringLiteral("resetBtn"));
        resetBtn->setEnabled(false);

        horizontalLayout_43->addWidget(resetBtn);


        verticalLayout_2->addLayout(horizontalLayout_43);

        graphicsView = new QGraphicsView(PrimeUI);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(graphicsView->sizePolicy().hasHeightForWidth());
        graphicsView->setSizePolicy(sizePolicy2);
        graphicsView->setMinimumSize(QSize(1049, 543));

        verticalLayout_2->addWidget(graphicsView);

        horizontalLayout_44 = new QHBoxLayout();
        horizontalLayout_44->setObjectName(QStringLiteral("horizontalLayout_44"));
        posLabel = new QLabel(PrimeUI);
        posLabel->setObjectName(QStringLiteral("posLabel"));

        horizontalLayout_44->addWidget(posLabel);

        posDataLabel = new QLabel(PrimeUI);
        posDataLabel->setObjectName(QStringLiteral("posDataLabel"));
        sizePolicy1.setHeightForWidth(posDataLabel->sizePolicy().hasHeightForWidth());
        posDataLabel->setSizePolicy(sizePolicy1);

        horizontalLayout_44->addWidget(posDataLabel);

        coordLabel = new QLabel(PrimeUI);
        coordLabel->setObjectName(QStringLiteral("coordLabel"));

        horizontalLayout_44->addWidget(coordLabel);

        coordDataLabel = new QLabel(PrimeUI);
        coordDataLabel->setObjectName(QStringLiteral("coordDataLabel"));
        sizePolicy1.setHeightForWidth(coordDataLabel->sizePolicy().hasHeightForWidth());
        coordDataLabel->setSizePolicy(sizePolicy1);

        horizontalLayout_44->addWidget(coordDataLabel);


        verticalLayout_2->addLayout(horizontalLayout_44);


        verticalLayout_33->addLayout(verticalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        monBtn = new QPushButton(PrimeUI);
        monBtn->setObjectName(QStringLiteral("monBtn"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(monBtn->sizePolicy().hasHeightForWidth());
        monBtn->setSizePolicy(sizePolicy3);

        verticalLayout->addWidget(monBtn);

        locManBtn = new QPushButton(PrimeUI);
        locManBtn->setObjectName(QStringLiteral("locManBtn"));
        sizePolicy3.setHeightForWidth(locManBtn->sizePolicy().hasHeightForWidth());
        locManBtn->setSizePolicy(sizePolicy3);

        verticalLayout->addWidget(locManBtn);

        vehManBtn = new QPushButton(PrimeUI);
        vehManBtn->setObjectName(QStringLiteral("vehManBtn"));
        sizePolicy3.setHeightForWidth(vehManBtn->sizePolicy().hasHeightForWidth());
        vehManBtn->setSizePolicy(sizePolicy3);

        verticalLayout->addWidget(vehManBtn);

        cusManBtn = new QPushButton(PrimeUI);
        cusManBtn->setObjectName(QStringLiteral("cusManBtn"));
        sizePolicy3.setHeightForWidth(cusManBtn->sizePolicy().hasHeightForWidth());
        cusManBtn->setSizePolicy(sizePolicy3);

        verticalLayout->addWidget(cusManBtn);

        evtManBtn = new QPushButton(PrimeUI);
        evtManBtn->setObjectName(QStringLiteral("evtManBtn"));
        sizePolicy3.setHeightForWidth(evtManBtn->sizePolicy().hasHeightForWidth());
        evtManBtn->setSizePolicy(sizePolicy3);

        verticalLayout->addWidget(evtManBtn);

        OptionsBtn = new QPushButton(PrimeUI);
        OptionsBtn->setObjectName(QStringLiteral("OptionsBtn"));
        OptionsBtn->setEnabled(false);

        verticalLayout->addWidget(OptionsBtn);


        horizontalLayout->addLayout(verticalLayout);

        primaryStackedWidget = new QStackedWidget(PrimeUI);
        primaryStackedWidget->setObjectName(QStringLiteral("primaryStackedWidget"));
        monPage = new QWidget();
        monPage->setObjectName(QStringLiteral("monPage"));
        verticalLayout_25 = new QVBoxLayout(monPage);
        verticalLayout_25->setObjectName(QStringLiteral("verticalLayout_25"));
        verticalLayout_24 = new QVBoxLayout();
        verticalLayout_24->setObjectName(QStringLiteral("verticalLayout_24"));
        monLabel = new QLabel(monPage);
        monLabel->setObjectName(QStringLiteral("monLabel"));
        QFont font;
        font.setPointSize(12);
        monLabel->setFont(font);
        monLabel->setFrameShape(QFrame::NoFrame);
        monLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_24->addWidget(monLabel);

        horizontalLayout_42 = new QHBoxLayout();
        horizontalLayout_42->setObjectName(QStringLiteral("horizontalLayout_42"));
        monToolBox = new QToolBox(monPage);
        monToolBox->setObjectName(QStringLiteral("monToolBox"));
        monToolBox->setFrameShape(QFrame::WinPanel);
        MonLocPage = new QWidget();
        MonLocPage->setObjectName(QStringLiteral("MonLocPage"));
        MonLocPage->setGeometry(QRect(0, 0, 100, 30));
        monToolBox->addItem(MonLocPage, QStringLiteral("Location"));
        MonVehPage = new QWidget();
        MonVehPage->setObjectName(QStringLiteral("MonVehPage"));
        MonVehPage->setGeometry(QRect(0, 0, 100, 30));
        monVehStatusBtn = new QPushButton(MonVehPage);
        monVehStatusBtn->setObjectName(QStringLiteral("monVehStatusBtn"));
        monVehStatusBtn->setGeometry(QRect(30, 50, 87, 27));
        monVehJobsBtn = new QPushButton(MonVehPage);
        monVehJobsBtn->setObjectName(QStringLiteral("monVehJobsBtn"));
        monVehJobsBtn->setGeometry(QRect(230, 50, 87, 27));
        monVehDistBtn = new QPushButton(MonVehPage);
        monVehDistBtn->setObjectName(QStringLiteral("monVehDistBtn"));
        monVehDistBtn->setEnabled(false);
        monVehDistBtn->setGeometry(QRect(130, 50, 87, 27));
        monToolBox->addItem(MonVehPage, QStringLiteral("Vehicle"));
        MonCusPage = new QWidget();
        MonCusPage->setObjectName(QStringLiteral("MonCusPage"));
        MonCusPage->setGeometry(QRect(0, 0, 18, 16));
        monToolBox->addItem(MonCusPage, QStringLiteral("Customer"));

        horizontalLayout_42->addWidget(monToolBox);

        frame = new QFrame(monPage);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::WinPanel);
        horizontalLayout_2 = new QHBoxLayout(frame);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        frame1 = new QFrame(frame);
        frame1->setObjectName(QStringLiteral("frame1"));
        frame1->setFrameShape(QFrame::Panel);
        verticalLayout_3 = new QVBoxLayout(frame1);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_46 = new QHBoxLayout();
        horizontalLayout_46->setObjectName(QStringLiteral("horizontalLayout_46"));
        MonListWidgetLabel = new QLabel(frame1);
        MonListWidgetLabel->setObjectName(QStringLiteral("MonListWidgetLabel"));

        horizontalLayout_46->addWidget(MonListWidgetLabel);


        verticalLayout_3->addLayout(horizontalLayout_46);

        monListWidget = new QListWidget(frame1);
        monListWidget->setObjectName(QStringLiteral("monListWidget"));

        verticalLayout_3->addWidget(monListWidget);


        horizontalLayout_2->addWidget(frame1);

        frame2 = new QFrame(frame);
        frame2->setObjectName(QStringLiteral("frame2"));
        frame2->setFrameShape(QFrame::Panel);
        verticalLayout_36 = new QVBoxLayout(frame2);
        verticalLayout_36->setObjectName(QStringLiteral("verticalLayout_36"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout_58 = new QHBoxLayout();
        horizontalLayout_58->setObjectName(QStringLiteral("horizontalLayout_58"));
        MonTableWidgetLabel = new QLabel(frame2);
        MonTableWidgetLabel->setObjectName(QStringLiteral("MonTableWidgetLabel"));

        horizontalLayout_58->addWidget(MonTableWidgetLabel);


        verticalLayout_4->addLayout(horizontalLayout_58);

        MonTableWidget = new QTableWidget(frame2);
        MonTableWidget->setObjectName(QStringLiteral("MonTableWidget"));
        MonTableWidget->setEnabled(true);

        verticalLayout_4->addWidget(MonTableWidget);


        verticalLayout_36->addLayout(verticalLayout_4);


        horizontalLayout_2->addWidget(frame2);


        horizontalLayout_42->addWidget(frame);


        verticalLayout_24->addLayout(horizontalLayout_42);


        verticalLayout_25->addLayout(verticalLayout_24);

        primaryStackedWidget->addWidget(monPage);
        locationManagerPage = new QWidget();
        locationManagerPage->setObjectName(QStringLiteral("locationManagerPage"));
        verticalLayout_26 = new QVBoxLayout(locationManagerPage);
        verticalLayout_26->setObjectName(QStringLiteral("verticalLayout_26"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        locManLabel = new QLabel(locationManagerPage);
        locManLabel->setObjectName(QStringLiteral("locManLabel"));
        locManLabel->setFont(font);
        locManLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_7->addWidget(locManLabel);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        frame3 = new QFrame(locationManagerPage);
        frame3->setObjectName(QStringLiteral("frame3"));
        sizePolicy1.setHeightForWidth(frame3->sizePolicy().hasHeightForWidth());
        frame3->setSizePolicy(sizePolicy1);
        frame3->setFrameShape(QFrame::WinPanel);
        horizontalLayout_48 = new QHBoxLayout(frame3);
        horizontalLayout_48->setObjectName(QStringLiteral("horizontalLayout_48"));
        horizontalLayout_47 = new QHBoxLayout();
        horizontalLayout_47->setObjectName(QStringLiteral("horizontalLayout_47"));
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        locTableLabel = new QLabel(frame3);
        locTableLabel->setObjectName(QStringLiteral("locTableLabel"));

        horizontalLayout_9->addWidget(locTableLabel);


        verticalLayout_8->addLayout(horizontalLayout_9);

        locTableWidget = new QTableWidget(frame3);
        locTableWidget->setObjectName(QStringLiteral("locTableWidget"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(locTableWidget->sizePolicy().hasHeightForWidth());
        locTableWidget->setSizePolicy(sizePolicy4);
        locTableWidget->setMinimumSize(QSize(350, 0));

        verticalLayout_8->addWidget(locTableWidget);


        horizontalLayout_47->addLayout(verticalLayout_8);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        locRegBtn = new QPushButton(frame3);
        locRegBtn->setObjectName(QStringLiteral("locRegBtn"));
        locRegBtn->setEnabled(true);
        sizePolicy3.setHeightForWidth(locRegBtn->sizePolicy().hasHeightForWidth());
        locRegBtn->setSizePolicy(sizePolicy3);
        locRegBtn->setAcceptDrops(false);
        locRegBtn->setCheckable(false);

        verticalLayout_6->addWidget(locRegBtn);

        locDeregBtn = new QPushButton(frame3);
        locDeregBtn->setObjectName(QStringLiteral("locDeregBtn"));
        locDeregBtn->setEnabled(false);
        sizePolicy3.setHeightForWidth(locDeregBtn->sizePolicy().hasHeightForWidth());
        locDeregBtn->setSizePolicy(sizePolicy3);

        verticalLayout_6->addWidget(locDeregBtn);

        locUpdateBtn = new QPushButton(frame3);
        locUpdateBtn->setObjectName(QStringLiteral("locUpdateBtn"));
        locUpdateBtn->setEnabled(false);
        sizePolicy3.setHeightForWidth(locUpdateBtn->sizePolicy().hasHeightForWidth());
        locUpdateBtn->setSizePolicy(sizePolicy3);

        verticalLayout_6->addWidget(locUpdateBtn);


        horizontalLayout_47->addLayout(verticalLayout_6);


        horizontalLayout_48->addLayout(horizontalLayout_47);


        horizontalLayout_6->addWidget(frame3);

        frame4 = new QFrame(locationManagerPage);
        frame4->setObjectName(QStringLiteral("frame4"));
        frame4->setMinimumSize(QSize(430, 0));
        frame4->setMaximumSize(QSize(430, 16777215));
        frame4->setFrameShape(QFrame::WinPanel);
        verticalLayout_5 = new QVBoxLayout(frame4);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        locIdLabel = new QLabel(frame4);
        locIdLabel->setObjectName(QStringLiteral("locIdLabel"));
        QSizePolicy sizePolicy5(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(locIdLabel->sizePolicy().hasHeightForWidth());
        locIdLabel->setSizePolicy(sizePolicy5);

        horizontalLayout_7->addWidget(locIdLabel);

        locIdEdit = new QLineEdit(frame4);
        locIdEdit->setObjectName(QStringLiteral("locIdEdit"));
        locIdEdit->setEnabled(false);
        QSizePolicy sizePolicy6(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(locIdEdit->sizePolicy().hasHeightForWidth());
        locIdEdit->setSizePolicy(sizePolicy6);

        horizontalLayout_7->addWidget(locIdEdit);


        verticalLayout_5->addLayout(horizontalLayout_7);

        frame_2 = new QFrame(frame4);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setFrameShape(QFrame::Panel);
        verticalLayout_35 = new QVBoxLayout(frame_2);
        verticalLayout_35->setObjectName(QStringLiteral("verticalLayout_35"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        LLGetCoordBtn = new QPushButton(frame_2);
        LLGetCoordBtn->setObjectName(QStringLiteral("LLGetCoordBtn"));
        QSizePolicy sizePolicy7(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(LLGetCoordBtn->sizePolicy().hasHeightForWidth());
        LLGetCoordBtn->setSizePolicy(sizePolicy7);

        horizontalLayout_5->addWidget(LLGetCoordBtn);

        verticalLayout_34 = new QVBoxLayout();
        verticalLayout_34->setObjectName(QStringLiteral("verticalLayout_34"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        locLatLabel = new QLabel(frame_2);
        locLatLabel->setObjectName(QStringLiteral("locLatLabel"));
        sizePolicy5.setHeightForWidth(locLatLabel->sizePolicy().hasHeightForWidth());
        locLatLabel->setSizePolicy(sizePolicy5);

        horizontalLayout_3->addWidget(locLatLabel);

        locLatEdit = new QLineEdit(frame_2);
        locLatEdit->setObjectName(QStringLiteral("locLatEdit"));
        locLatEdit->setEnabled(false);
        sizePolicy6.setHeightForWidth(locLatEdit->sizePolicy().hasHeightForWidth());
        locLatEdit->setSizePolicy(sizePolicy6);

        horizontalLayout_3->addWidget(locLatEdit);


        verticalLayout_34->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        locLongLabel = new QLabel(frame_2);
        locLongLabel->setObjectName(QStringLiteral("locLongLabel"));
        sizePolicy5.setHeightForWidth(locLongLabel->sizePolicy().hasHeightForWidth());
        locLongLabel->setSizePolicy(sizePolicy5);

        horizontalLayout_4->addWidget(locLongLabel);

        locLongEdit = new QLineEdit(frame_2);
        locLongEdit->setObjectName(QStringLiteral("locLongEdit"));
        locLongEdit->setEnabled(false);
        sizePolicy6.setHeightForWidth(locLongEdit->sizePolicy().hasHeightForWidth());
        locLongEdit->setSizePolicy(sizePolicy6);

        horizontalLayout_4->addWidget(locLongEdit);


        verticalLayout_34->addLayout(horizontalLayout_4);


        horizontalLayout_5->addLayout(verticalLayout_34);

        LLReflectBtn = new QPushButton(frame_2);
        LLReflectBtn->setObjectName(QStringLiteral("LLReflectBtn"));
        LLReflectBtn->setEnabled(false);
        sizePolicy7.setHeightForWidth(LLReflectBtn->sizePolicy().hasHeightForWidth());
        LLReflectBtn->setSizePolicy(sizePolicy7);

        horizontalLayout_5->addWidget(LLReflectBtn);


        verticalLayout_35->addLayout(horizontalLayout_5);


        verticalLayout_5->addWidget(frame_2);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        locConfirmBtn = new QPushButton(frame4);
        locConfirmBtn->setObjectName(QStringLiteral("locConfirmBtn"));
        locConfirmBtn->setEnabled(false);
        sizePolicy7.setHeightForWidth(locConfirmBtn->sizePolicy().hasHeightForWidth());
        locConfirmBtn->setSizePolicy(sizePolicy7);

        horizontalLayout_8->addWidget(locConfirmBtn);

        locCancelBtn = new QPushButton(frame4);
        locCancelBtn->setObjectName(QStringLiteral("locCancelBtn"));
        locCancelBtn->setEnabled(false);
        sizePolicy7.setHeightForWidth(locCancelBtn->sizePolicy().hasHeightForWidth());
        locCancelBtn->setSizePolicy(sizePolicy7);

        horizontalLayout_8->addWidget(locCancelBtn);


        verticalLayout_5->addLayout(horizontalLayout_8);


        horizontalLayout_6->addWidget(frame4);


        verticalLayout_7->addLayout(horizontalLayout_6);


        verticalLayout_26->addLayout(verticalLayout_7);

        primaryStackedWidget->addWidget(locationManagerPage);
        vehicleManagerPage = new QWidget();
        vehicleManagerPage->setObjectName(QStringLiteral("vehicleManagerPage"));
        verticalLayout_27 = new QVBoxLayout(vehicleManagerPage);
        verticalLayout_27->setObjectName(QStringLiteral("verticalLayout_27"));
        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setObjectName(QStringLiteral("verticalLayout_11"));
        vehManLabel = new QLabel(vehicleManagerPage);
        vehManLabel->setObjectName(QStringLiteral("vehManLabel"));
        vehManLabel->setFont(font);
        vehManLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_11->addWidget(vehManLabel);

        horizontalLayout_27 = new QHBoxLayout();
        horizontalLayout_27->setObjectName(QStringLiteral("horizontalLayout_27"));
        frame5 = new QFrame(vehicleManagerPage);
        frame5->setObjectName(QStringLiteral("frame5"));
        sizePolicy1.setHeightForWidth(frame5->sizePolicy().hasHeightForWidth());
        frame5->setSizePolicy(sizePolicy1);
        frame5->setFrameShape(QFrame::WinPanel);
        horizontalLayout_49 = new QHBoxLayout(frame5);
        horizontalLayout_49->setObjectName(QStringLiteral("horizontalLayout_49"));
        verticalLayout_12 = new QVBoxLayout();
        verticalLayout_12->setObjectName(QStringLiteral("verticalLayout_12"));
        horizontalLayout_26 = new QHBoxLayout();
        horizontalLayout_26->setObjectName(QStringLiteral("horizontalLayout_26"));
        vehTableLabel = new QLabel(frame5);
        vehTableLabel->setObjectName(QStringLiteral("vehTableLabel"));
        QSizePolicy sizePolicy8(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy8.setHorizontalStretch(0);
        sizePolicy8.setVerticalStretch(0);
        sizePolicy8.setHeightForWidth(vehTableLabel->sizePolicy().hasHeightForWidth());
        vehTableLabel->setSizePolicy(sizePolicy8);

        horizontalLayout_26->addWidget(vehTableLabel);


        verticalLayout_12->addLayout(horizontalLayout_26);

        vehTableWidget = new QTableWidget(frame5);
        vehTableWidget->setObjectName(QStringLiteral("vehTableWidget"));
        sizePolicy4.setHeightForWidth(vehTableWidget->sizePolicy().hasHeightForWidth());
        vehTableWidget->setSizePolicy(sizePolicy4);
        vehTableWidget->setMinimumSize(QSize(0, 0));

        verticalLayout_12->addWidget(vehTableWidget);


        horizontalLayout_49->addLayout(verticalLayout_12);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        vehRegBtn = new QPushButton(frame5);
        vehRegBtn->setObjectName(QStringLiteral("vehRegBtn"));
        sizePolicy3.setHeightForWidth(vehRegBtn->sizePolicy().hasHeightForWidth());
        vehRegBtn->setSizePolicy(sizePolicy3);

        verticalLayout_9->addWidget(vehRegBtn);

        vehDeregBtn = new QPushButton(frame5);
        vehDeregBtn->setObjectName(QStringLiteral("vehDeregBtn"));
        vehDeregBtn->setEnabled(false);
        sizePolicy3.setHeightForWidth(vehDeregBtn->sizePolicy().hasHeightForWidth());
        vehDeregBtn->setSizePolicy(sizePolicy3);

        verticalLayout_9->addWidget(vehDeregBtn);

        vehUpdateBtn = new QPushButton(frame5);
        vehUpdateBtn->setObjectName(QStringLiteral("vehUpdateBtn"));
        vehUpdateBtn->setEnabled(false);
        sizePolicy3.setHeightForWidth(vehUpdateBtn->sizePolicy().hasHeightForWidth());
        vehUpdateBtn->setSizePolicy(sizePolicy3);

        verticalLayout_9->addWidget(vehUpdateBtn);


        horizontalLayout_49->addLayout(verticalLayout_9);


        horizontalLayout_27->addWidget(frame5);

        frame6 = new QFrame(vehicleManagerPage);
        frame6->setObjectName(QStringLiteral("frame6"));
        frame6->setMinimumSize(QSize(430, 0));
        frame6->setMaximumSize(QSize(430, 16777215));
        frame6->setFrameShape(QFrame::WinPanel);
        verticalLayout_14 = new QVBoxLayout(frame6);
        verticalLayout_14->setObjectName(QStringLiteral("verticalLayout_14"));
        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        vehIdLabel = new QLabel(frame6);
        vehIdLabel->setObjectName(QStringLiteral("vehIdLabel"));
        sizePolicy5.setHeightForWidth(vehIdLabel->sizePolicy().hasHeightForWidth());
        vehIdLabel->setSizePolicy(sizePolicy5);

        horizontalLayout_13->addWidget(vehIdLabel);

        vehIdEdit = new QLineEdit(frame6);
        vehIdEdit->setObjectName(QStringLiteral("vehIdEdit"));
        vehIdEdit->setEnabled(false);
        sizePolicy6.setHeightForWidth(vehIdEdit->sizePolicy().hasHeightForWidth());
        vehIdEdit->setSizePolicy(sizePolicy6);

        horizontalLayout_13->addWidget(vehIdEdit);


        verticalLayout_14->addLayout(horizontalLayout_13);

        frame7 = new QFrame(frame6);
        frame7->setObjectName(QStringLiteral("frame7"));
        frame7->setFrameShape(QFrame::Panel);
        verticalLayout_10 = new QVBoxLayout(frame7);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        vehCoordChBox = new QCheckBox(frame7);
        vehCoordChBox->setObjectName(QStringLiteral("vehCoordChBox"));
        vehCoordChBox->setEnabled(false);
        sizePolicy6.setHeightForWidth(vehCoordChBox->sizePolicy().hasHeightForWidth());
        vehCoordChBox->setSizePolicy(sizePolicy6);

        verticalLayout_10->addWidget(vehCoordChBox);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        vehLatLabel = new QLabel(frame7);
        vehLatLabel->setObjectName(QStringLiteral("vehLatLabel"));
        sizePolicy5.setHeightForWidth(vehLatLabel->sizePolicy().hasHeightForWidth());
        vehLatLabel->setSizePolicy(sizePolicy5);

        horizontalLayout_10->addWidget(vehLatLabel);

        vehLatEdit = new QLineEdit(frame7);
        vehLatEdit->setObjectName(QStringLiteral("vehLatEdit"));
        vehLatEdit->setEnabled(false);
        sizePolicy6.setHeightForWidth(vehLatEdit->sizePolicy().hasHeightForWidth());
        vehLatEdit->setSizePolicy(sizePolicy6);

        horizontalLayout_10->addWidget(vehLatEdit);


        horizontalLayout_12->addLayout(horizontalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        vehLongLabel = new QLabel(frame7);
        vehLongLabel->setObjectName(QStringLiteral("vehLongLabel"));
        sizePolicy5.setHeightForWidth(vehLongLabel->sizePolicy().hasHeightForWidth());
        vehLongLabel->setSizePolicy(sizePolicy5);

        horizontalLayout_11->addWidget(vehLongLabel);

        vehLongEdit = new QLineEdit(frame7);
        vehLongEdit->setObjectName(QStringLiteral("vehLongEdit"));
        vehLongEdit->setEnabled(false);
        sizePolicy6.setHeightForWidth(vehLongEdit->sizePolicy().hasHeightForWidth());
        vehLongEdit->setSizePolicy(sizePolicy6);

        horizontalLayout_11->addWidget(vehLongEdit);


        horizontalLayout_12->addLayout(horizontalLayout_11);


        verticalLayout_10->addLayout(horizontalLayout_12);

        horizontalLayout_24 = new QHBoxLayout();
        horizontalLayout_24->setObjectName(QStringLiteral("horizontalLayout_24"));
        vehGetCoordBtn = new QPushButton(frame7);
        vehGetCoordBtn->setObjectName(QStringLiteral("vehGetCoordBtn"));
        vehGetCoordBtn->setEnabled(false);
        sizePolicy6.setHeightForWidth(vehGetCoordBtn->sizePolicy().hasHeightForWidth());
        vehGetCoordBtn->setSizePolicy(sizePolicy6);

        horizontalLayout_24->addWidget(vehGetCoordBtn);

        vehRefCoordBtn = new QPushButton(frame7);
        vehRefCoordBtn->setObjectName(QStringLiteral("vehRefCoordBtn"));
        vehRefCoordBtn->setEnabled(false);
        sizePolicy6.setHeightForWidth(vehRefCoordBtn->sizePolicy().hasHeightForWidth());
        vehRefCoordBtn->setSizePolicy(sizePolicy6);

        horizontalLayout_24->addWidget(vehRefCoordBtn);


        verticalLayout_10->addLayout(horizontalLayout_24);


        verticalLayout_14->addWidget(frame7);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        vehSpeedChBox = new QCheckBox(frame6);
        vehSpeedChBox->setObjectName(QStringLiteral("vehSpeedChBox"));
        vehSpeedChBox->setEnabled(false);
        sizePolicy.setHeightForWidth(vehSpeedChBox->sizePolicy().hasHeightForWidth());
        vehSpeedChBox->setSizePolicy(sizePolicy);

        horizontalLayout_14->addWidget(vehSpeedChBox);

        vehSpeedEdit = new QLineEdit(frame6);
        vehSpeedEdit->setObjectName(QStringLiteral("vehSpeedEdit"));
        vehSpeedEdit->setEnabled(false);
        sizePolicy6.setHeightForWidth(vehSpeedEdit->sizePolicy().hasHeightForWidth());
        vehSpeedEdit->setSizePolicy(sizePolicy6);

        horizontalLayout_14->addWidget(vehSpeedEdit);


        verticalLayout_14->addLayout(horizontalLayout_14);

        horizontalLayout_23 = new QHBoxLayout();
        horizontalLayout_23->setObjectName(QStringLiteral("horizontalLayout_23"));
        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setObjectName(QStringLiteral("horizontalLayout_16"));
        vehCapChBox = new QCheckBox(frame6);
        vehCapChBox->setObjectName(QStringLiteral("vehCapChBox"));
        vehCapChBox->setEnabled(false);
        sizePolicy.setHeightForWidth(vehCapChBox->sizePolicy().hasHeightForWidth());
        vehCapChBox->setSizePolicy(sizePolicy);

        horizontalLayout_16->addWidget(vehCapChBox);

        vehCapSpBox = new QSpinBox(frame6);
        vehCapSpBox->setObjectName(QStringLiteral("vehCapSpBox"));
        vehCapSpBox->setEnabled(false);
        sizePolicy6.setHeightForWidth(vehCapSpBox->sizePolicy().hasHeightForWidth());
        vehCapSpBox->setSizePolicy(sizePolicy6);

        horizontalLayout_16->addWidget(vehCapSpBox);


        horizontalLayout_23->addLayout(horizontalLayout_16);

        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setObjectName(QStringLiteral("horizontalLayout_20"));
        vehLCostChBox = new QCheckBox(frame6);
        vehLCostChBox->setObjectName(QStringLiteral("vehLCostChBox"));
        vehLCostChBox->setEnabled(false);
        sizePolicy.setHeightForWidth(vehLCostChBox->sizePolicy().hasHeightForWidth());
        vehLCostChBox->setSizePolicy(sizePolicy);

        horizontalLayout_20->addWidget(vehLCostChBox);

        vehLCostSpBox = new QSpinBox(frame6);
        vehLCostSpBox->setObjectName(QStringLiteral("vehLCostSpBox"));
        vehLCostSpBox->setEnabled(false);
        sizePolicy6.setHeightForWidth(vehLCostSpBox->sizePolicy().hasHeightForWidth());
        vehLCostSpBox->setSizePolicy(sizePolicy6);
        vehLCostSpBox->setMaximum(100000);

        horizontalLayout_20->addWidget(vehLCostSpBox);


        horizontalLayout_23->addLayout(horizontalLayout_20);


        verticalLayout_14->addLayout(horizontalLayout_23);

        frame8 = new QFrame(frame6);
        frame8->setObjectName(QStringLiteral("frame8"));
        frame8->setFrameShape(QFrame::Panel);
        verticalLayout_13 = new QVBoxLayout(frame8);
        verticalLayout_13->setObjectName(QStringLiteral("verticalLayout_13"));
        horizontalLayout_22 = new QHBoxLayout();
        horizontalLayout_22->setObjectName(QStringLiteral("horizontalLayout_22"));
        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setObjectName(QStringLiteral("horizontalLayout_17"));
        vehFTimeChBox = new QCheckBox(frame8);
        vehFTimeChBox->setObjectName(QStringLiteral("vehFTimeChBox"));
        vehFTimeChBox->setEnabled(false);
        sizePolicy.setHeightForWidth(vehFTimeChBox->sizePolicy().hasHeightForWidth());
        vehFTimeChBox->setSizePolicy(sizePolicy);

        horizontalLayout_17->addWidget(vehFTimeChBox);

        vehFTimeSpBox = new QSpinBox(frame8);
        vehFTimeSpBox->setObjectName(QStringLiteral("vehFTimeSpBox"));
        vehFTimeSpBox->setEnabled(false);
        sizePolicy6.setHeightForWidth(vehFTimeSpBox->sizePolicy().hasHeightForWidth());
        vehFTimeSpBox->setSizePolicy(sizePolicy6);
        vehFTimeSpBox->setMaximum(10000);

        horizontalLayout_17->addWidget(vehFTimeSpBox);


        horizontalLayout_22->addLayout(horizontalLayout_17);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setObjectName(QStringLiteral("horizontalLayout_18"));
        vehUTimeChBox = new QCheckBox(frame8);
        vehUTimeChBox->setObjectName(QStringLiteral("vehUTimeChBox"));
        vehUTimeChBox->setEnabled(false);
        sizePolicy.setHeightForWidth(vehUTimeChBox->sizePolicy().hasHeightForWidth());
        vehUTimeChBox->setSizePolicy(sizePolicy);

        horizontalLayout_18->addWidget(vehUTimeChBox);

        vehUTimeSpBox = new QSpinBox(frame8);
        vehUTimeSpBox->setObjectName(QStringLiteral("vehUTimeSpBox"));
        vehUTimeSpBox->setEnabled(false);
        sizePolicy6.setHeightForWidth(vehUTimeSpBox->sizePolicy().hasHeightForWidth());
        vehUTimeSpBox->setSizePolicy(sizePolicy6);
        vehUTimeSpBox->setMaximum(10000);

        horizontalLayout_18->addWidget(vehUTimeSpBox);


        horizontalLayout_22->addLayout(horizontalLayout_18);


        verticalLayout_13->addLayout(horizontalLayout_22);

        horizontalLayout_21 = new QHBoxLayout();
        horizontalLayout_21->setObjectName(QStringLiteral("horizontalLayout_21"));
        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        vehRTimeChBox = new QCheckBox(frame8);
        vehRTimeChBox->setObjectName(QStringLiteral("vehRTimeChBox"));
        vehRTimeChBox->setEnabled(false);
        sizePolicy.setHeightForWidth(vehRTimeChBox->sizePolicy().hasHeightForWidth());
        vehRTimeChBox->setSizePolicy(sizePolicy);

        horizontalLayout_15->addWidget(vehRTimeChBox);

        vehRTimeSpBox = new QSpinBox(frame8);
        vehRTimeSpBox->setObjectName(QStringLiteral("vehRTimeSpBox"));
        vehRTimeSpBox->setEnabled(false);
        sizePolicy6.setHeightForWidth(vehRTimeSpBox->sizePolicy().hasHeightForWidth());
        vehRTimeSpBox->setSizePolicy(sizePolicy6);
        vehRTimeSpBox->setMaximum(1000000);

        horizontalLayout_15->addWidget(vehRTimeSpBox);


        horizontalLayout_21->addLayout(horizontalLayout_15);

        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setObjectName(QStringLiteral("horizontalLayout_19"));
        vehBTimeChBox = new QCheckBox(frame8);
        vehBTimeChBox->setObjectName(QStringLiteral("vehBTimeChBox"));
        vehBTimeChBox->setEnabled(false);
        sizePolicy.setHeightForWidth(vehBTimeChBox->sizePolicy().hasHeightForWidth());
        vehBTimeChBox->setSizePolicy(sizePolicy);

        horizontalLayout_19->addWidget(vehBTimeChBox);

        vehBTimeSpBox = new QSpinBox(frame8);
        vehBTimeSpBox->setObjectName(QStringLiteral("vehBTimeSpBox"));
        vehBTimeSpBox->setEnabled(false);
        sizePolicy6.setHeightForWidth(vehBTimeSpBox->sizePolicy().hasHeightForWidth());
        vehBTimeSpBox->setSizePolicy(sizePolicy6);
        vehBTimeSpBox->setMaximum(10000);

        horizontalLayout_19->addWidget(vehBTimeSpBox);


        horizontalLayout_21->addLayout(horizontalLayout_19);


        verticalLayout_13->addLayout(horizontalLayout_21);


        verticalLayout_14->addWidget(frame8);

        frame9 = new QFrame(frame6);
        frame9->setObjectName(QStringLiteral("frame9"));
        frame9->setFrameShape(QFrame::Panel);
        horizontalLayout_25 = new QHBoxLayout(frame9);
        horizontalLayout_25->setObjectName(QStringLiteral("horizontalLayout_25"));
        vehDefaultBtn = new QPushButton(frame9);
        vehDefaultBtn->setObjectName(QStringLiteral("vehDefaultBtn"));
        vehDefaultBtn->setEnabled(false);
        sizePolicy6.setHeightForWidth(vehDefaultBtn->sizePolicy().hasHeightForWidth());
        vehDefaultBtn->setSizePolicy(sizePolicy6);

        horizontalLayout_25->addWidget(vehDefaultBtn);

        vehConfirmBtn = new QPushButton(frame9);
        vehConfirmBtn->setObjectName(QStringLiteral("vehConfirmBtn"));
        vehConfirmBtn->setEnabled(false);
        sizePolicy6.setHeightForWidth(vehConfirmBtn->sizePolicy().hasHeightForWidth());
        vehConfirmBtn->setSizePolicy(sizePolicy6);

        horizontalLayout_25->addWidget(vehConfirmBtn);

        vehCancelBtn = new QPushButton(frame9);
        vehCancelBtn->setObjectName(QStringLiteral("vehCancelBtn"));
        vehCancelBtn->setEnabled(false);
        sizePolicy6.setHeightForWidth(vehCancelBtn->sizePolicy().hasHeightForWidth());
        vehCancelBtn->setSizePolicy(sizePolicy6);

        horizontalLayout_25->addWidget(vehCancelBtn);


        verticalLayout_14->addWidget(frame9);


        horizontalLayout_27->addWidget(frame6);


        verticalLayout_11->addLayout(horizontalLayout_27);


        verticalLayout_27->addLayout(verticalLayout_11);

        primaryStackedWidget->addWidget(vehicleManagerPage);
        customerManagerPage = new QWidget();
        customerManagerPage->setObjectName(QStringLiteral("customerManagerPage"));
        verticalLayout_28 = new QVBoxLayout(customerManagerPage);
        verticalLayout_28->setObjectName(QStringLiteral("verticalLayout_28"));
        verticalLayout_19 = new QVBoxLayout();
        verticalLayout_19->setObjectName(QStringLiteral("verticalLayout_19"));
        cusManLabel = new QLabel(customerManagerPage);
        cusManLabel->setObjectName(QStringLiteral("cusManLabel"));
        cusManLabel->setFont(font);
        cusManLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_19->addWidget(cusManLabel);

        horizontalLayout_36 = new QHBoxLayout();
        horizontalLayout_36->setObjectName(QStringLiteral("horizontalLayout_36"));
        frame10 = new QFrame(customerManagerPage);
        frame10->setObjectName(QStringLiteral("frame10"));
        frame10->setFrameShape(QFrame::WinPanel);
        horizontalLayout_51 = new QHBoxLayout(frame10);
        horizontalLayout_51->setObjectName(QStringLiteral("horizontalLayout_51"));
        horizontalLayout_50 = new QHBoxLayout();
        horizontalLayout_50->setObjectName(QStringLiteral("horizontalLayout_50"));
        verticalLayout_20 = new QVBoxLayout();
        verticalLayout_20->setObjectName(QStringLiteral("verticalLayout_20"));
        horizontalLayout_34 = new QHBoxLayout();
        horizontalLayout_34->setObjectName(QStringLiteral("horizontalLayout_34"));
        cusTableLabel = new QLabel(frame10);
        cusTableLabel->setObjectName(QStringLiteral("cusTableLabel"));

        horizontalLayout_34->addWidget(cusTableLabel);


        verticalLayout_20->addLayout(horizontalLayout_34);

        cusTableWidget = new QTableWidget(frame10);
        cusTableWidget->setObjectName(QStringLiteral("cusTableWidget"));
        cusTableWidget->setMinimumSize(QSize(0, 0));

        verticalLayout_20->addWidget(cusTableWidget);


        horizontalLayout_50->addLayout(verticalLayout_20);

        verticalLayout_15 = new QVBoxLayout();
        verticalLayout_15->setObjectName(QStringLiteral("verticalLayout_15"));
        cusReqBtn = new QPushButton(frame10);
        cusReqBtn->setObjectName(QStringLiteral("cusReqBtn"));
        QSizePolicy sizePolicy9(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy9.setHorizontalStretch(0);
        sizePolicy9.setVerticalStretch(0);
        sizePolicy9.setHeightForWidth(cusReqBtn->sizePolicy().hasHeightForWidth());
        cusReqBtn->setSizePolicy(sizePolicy9);

        verticalLayout_15->addWidget(cusReqBtn);

        cusCancelReqBtn = new QPushButton(frame10);
        cusCancelReqBtn->setObjectName(QStringLiteral("cusCancelReqBtn"));
        cusCancelReqBtn->setEnabled(false);
        sizePolicy9.setHeightForWidth(cusCancelReqBtn->sizePolicy().hasHeightForWidth());
        cusCancelReqBtn->setSizePolicy(sizePolicy9);

        verticalLayout_15->addWidget(cusCancelReqBtn);

        cusChgReqBtn = new QPushButton(frame10);
        cusChgReqBtn->setObjectName(QStringLiteral("cusChgReqBtn"));
        cusChgReqBtn->setEnabled(false);
        sizePolicy9.setHeightForWidth(cusChgReqBtn->sizePolicy().hasHeightForWidth());
        cusChgReqBtn->setSizePolicy(sizePolicy9);

        verticalLayout_15->addWidget(cusChgReqBtn);


        horizontalLayout_50->addLayout(verticalLayout_15);


        horizontalLayout_51->addLayout(horizontalLayout_50);


        horizontalLayout_36->addWidget(frame10);

        frame11 = new QFrame(customerManagerPage);
        frame11->setObjectName(QStringLiteral("frame11"));
        QSizePolicy sizePolicy10(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy10.setHorizontalStretch(0);
        sizePolicy10.setVerticalStretch(0);
        sizePolicy10.setHeightForWidth(frame11->sizePolicy().hasHeightForWidth());
        frame11->setSizePolicy(sizePolicy10);
        frame11->setMinimumSize(QSize(430, 0));
        frame11->setMaximumSize(QSize(430, 16777215));
        frame11->setFrameShape(QFrame::WinPanel);
        verticalLayout_18 = new QVBoxLayout(frame11);
        verticalLayout_18->setObjectName(QStringLiteral("verticalLayout_18"));
        horizontalLayout_33 = new QHBoxLayout();
        horizontalLayout_33->setObjectName(QStringLiteral("horizontalLayout_33"));
        cusIdLabel = new QLabel(frame11);
        cusIdLabel->setObjectName(QStringLiteral("cusIdLabel"));
        sizePolicy5.setHeightForWidth(cusIdLabel->sizePolicy().hasHeightForWidth());
        cusIdLabel->setSizePolicy(sizePolicy5);

        horizontalLayout_33->addWidget(cusIdLabel);

        cusIdEdit = new QLineEdit(frame11);
        cusIdEdit->setObjectName(QStringLiteral("cusIdEdit"));
        cusIdEdit->setEnabled(false);
        sizePolicy6.setHeightForWidth(cusIdEdit->sizePolicy().hasHeightForWidth());
        cusIdEdit->setSizePolicy(sizePolicy6);

        horizontalLayout_33->addWidget(cusIdEdit);


        verticalLayout_18->addLayout(horizontalLayout_33);

        horizontalLayout_32 = new QHBoxLayout();
        horizontalLayout_32->setObjectName(QStringLiteral("horizontalLayout_32"));
        cusDemandsChBox = new QCheckBox(frame11);
        cusDemandsChBox->setObjectName(QStringLiteral("cusDemandsChBox"));
        cusDemandsChBox->setEnabled(false);
        sizePolicy.setHeightForWidth(cusDemandsChBox->sizePolicy().hasHeightForWidth());
        cusDemandsChBox->setSizePolicy(sizePolicy);

        horizontalLayout_32->addWidget(cusDemandsChBox);

        cusDemandsSpBox = new QSpinBox(frame11);
        cusDemandsSpBox->setObjectName(QStringLiteral("cusDemandsSpBox"));
        cusDemandsSpBox->setEnabled(false);
        sizePolicy6.setHeightForWidth(cusDemandsSpBox->sizePolicy().hasHeightForWidth());
        cusDemandsSpBox->setSizePolicy(sizePolicy6);
        cusDemandsSpBox->setMinimum(1);
        cusDemandsSpBox->setMaximum(10);
        cusDemandsSpBox->setValue(1);

        horizontalLayout_32->addWidget(cusDemandsSpBox);


        verticalLayout_18->addLayout(horizontalLayout_32);

        frame12 = new QFrame(frame11);
        frame12->setObjectName(QStringLiteral("frame12"));
        frame12->setFrameShape(QFrame::Panel);
        verticalLayout_17 = new QVBoxLayout(frame12);
        verticalLayout_17->setObjectName(QStringLiteral("verticalLayout_17"));
        horizontalLayout_31 = new QHBoxLayout();
        horizontalLayout_31->setObjectName(QStringLiteral("horizontalLayout_31"));
        cusPULocChBox = new QCheckBox(frame12);
        cusPULocChBox->setObjectName(QStringLiteral("cusPULocChBox"));
        cusPULocChBox->setEnabled(false);
        sizePolicy.setHeightForWidth(cusPULocChBox->sizePolicy().hasHeightForWidth());
        cusPULocChBox->setSizePolicy(sizePolicy);

        horizontalLayout_31->addWidget(cusPULocChBox);

        cusPULocCoBox = new QComboBox(frame12);
        cusPULocCoBox->setObjectName(QStringLiteral("cusPULocCoBox"));
        cusPULocCoBox->setEnabled(false);
        sizePolicy6.setHeightForWidth(cusPULocCoBox->sizePolicy().hasHeightForWidth());
        cusPULocCoBox->setSizePolicy(sizePolicy6);

        horizontalLayout_31->addWidget(cusPULocCoBox);


        verticalLayout_17->addLayout(horizontalLayout_31);

        horizontalLayout_30 = new QHBoxLayout();
        horizontalLayout_30->setObjectName(QStringLiteral("horizontalLayout_30"));
        cusDLocChBox = new QCheckBox(frame12);
        cusDLocChBox->setObjectName(QStringLiteral("cusDLocChBox"));
        cusDLocChBox->setEnabled(false);
        sizePolicy.setHeightForWidth(cusDLocChBox->sizePolicy().hasHeightForWidth());
        cusDLocChBox->setSizePolicy(sizePolicy);

        horizontalLayout_30->addWidget(cusDLocChBox);

        cusDLocCoBox = new QComboBox(frame12);
        cusDLocCoBox->setObjectName(QStringLiteral("cusDLocCoBox"));
        cusDLocCoBox->setEnabled(false);
        sizePolicy6.setHeightForWidth(cusDLocCoBox->sizePolicy().hasHeightForWidth());
        cusDLocCoBox->setSizePolicy(sizePolicy6);

        horizontalLayout_30->addWidget(cusDLocCoBox);


        verticalLayout_17->addLayout(horizontalLayout_30);


        verticalLayout_18->addWidget(frame12);

        frame13 = new QFrame(frame11);
        frame13->setObjectName(QStringLiteral("frame13"));
        frame13->setFrameShape(QFrame::Panel);
        verticalLayout_16 = new QVBoxLayout(frame13);
        verticalLayout_16->setObjectName(QStringLiteral("verticalLayout_16"));
        horizontalLayout_29 = new QHBoxLayout();
        horizontalLayout_29->setObjectName(QStringLiteral("horizontalLayout_29"));
        cusRSTimeChBox = new QCheckBox(frame13);
        cusRSTimeChBox->setObjectName(QStringLiteral("cusRSTimeChBox"));
        cusRSTimeChBox->setEnabled(false);
        sizePolicy.setHeightForWidth(cusRSTimeChBox->sizePolicy().hasHeightForWidth());
        cusRSTimeChBox->setSizePolicy(sizePolicy);

        horizontalLayout_29->addWidget(cusRSTimeChBox);

        cusRSTimeCoBox = new QComboBox(frame13);
        cusRSTimeCoBox->setObjectName(QStringLiteral("cusRSTimeCoBox"));
        cusRSTimeCoBox->setEnabled(false);
        sizePolicy6.setHeightForWidth(cusRSTimeCoBox->sizePolicy().hasHeightForWidth());
        cusRSTimeCoBox->setSizePolicy(sizePolicy6);

        horizontalLayout_29->addWidget(cusRSTimeCoBox);

        cusRSTimeMinLabel = new QLabel(frame13);
        cusRSTimeMinLabel->setObjectName(QStringLiteral("cusRSTimeMinLabel"));
        cusRSTimeMinLabel->setEnabled(false);
        sizePolicy5.setHeightForWidth(cusRSTimeMinLabel->sizePolicy().hasHeightForWidth());
        cusRSTimeMinLabel->setSizePolicy(sizePolicy5);

        horizontalLayout_29->addWidget(cusRSTimeMinLabel);


        verticalLayout_16->addLayout(horizontalLayout_29);

        horizontalLayout_28 = new QHBoxLayout();
        horizontalLayout_28->setObjectName(QStringLiteral("horizontalLayout_28"));
        cusWTimeChBox = new QCheckBox(frame13);
        cusWTimeChBox->setObjectName(QStringLiteral("cusWTimeChBox"));
        cusWTimeChBox->setEnabled(false);
        sizePolicy.setHeightForWidth(cusWTimeChBox->sizePolicy().hasHeightForWidth());
        cusWTimeChBox->setSizePolicy(sizePolicy);

        horizontalLayout_28->addWidget(cusWTimeChBox);

        cusWTimeCoBox = new QComboBox(frame13);
        cusWTimeCoBox->setObjectName(QStringLiteral("cusWTimeCoBox"));
        cusWTimeCoBox->setEnabled(false);
        sizePolicy6.setHeightForWidth(cusWTimeCoBox->sizePolicy().hasHeightForWidth());
        cusWTimeCoBox->setSizePolicy(sizePolicy6);

        horizontalLayout_28->addWidget(cusWTimeCoBox);

        cusWTimeMinLabel = new QLabel(frame13);
        cusWTimeMinLabel->setObjectName(QStringLiteral("cusWTimeMinLabel"));
        cusWTimeMinLabel->setEnabled(false);
        sizePolicy5.setHeightForWidth(cusWTimeMinLabel->sizePolicy().hasHeightForWidth());
        cusWTimeMinLabel->setSizePolicy(sizePolicy5);

        horizontalLayout_28->addWidget(cusWTimeMinLabel);


        verticalLayout_16->addLayout(horizontalLayout_28);


        verticalLayout_18->addWidget(frame13);

        frame14 = new QFrame(frame11);
        frame14->setObjectName(QStringLiteral("frame14"));
        frame14->setFrameShape(QFrame::Panel);
        horizontalLayout_35 = new QHBoxLayout(frame14);
        horizontalLayout_35->setObjectName(QStringLiteral("horizontalLayout_35"));
        cusConfirmBtn = new QPushButton(frame14);
        cusConfirmBtn->setObjectName(QStringLiteral("cusConfirmBtn"));
        cusConfirmBtn->setEnabled(false);
        sizePolicy7.setHeightForWidth(cusConfirmBtn->sizePolicy().hasHeightForWidth());
        cusConfirmBtn->setSizePolicy(sizePolicy7);

        horizontalLayout_35->addWidget(cusConfirmBtn);

        cusCancelBtn = new QPushButton(frame14);
        cusCancelBtn->setObjectName(QStringLiteral("cusCancelBtn"));
        cusCancelBtn->setEnabled(false);
        sizePolicy7.setHeightForWidth(cusCancelBtn->sizePolicy().hasHeightForWidth());
        cusCancelBtn->setSizePolicy(sizePolicy7);

        horizontalLayout_35->addWidget(cusCancelBtn);


        verticalLayout_18->addWidget(frame14);


        horizontalLayout_36->addWidget(frame11);


        verticalLayout_19->addLayout(horizontalLayout_36);


        verticalLayout_28->addLayout(verticalLayout_19);

        primaryStackedWidget->addWidget(customerManagerPage);
        eventManagerPage = new QWidget();
        eventManagerPage->setObjectName(QStringLiteral("eventManagerPage"));
        verticalLayout_32 = new QVBoxLayout(eventManagerPage);
        verticalLayout_32->setObjectName(QStringLiteral("verticalLayout_32"));
        verticalLayout_22 = new QVBoxLayout();
        verticalLayout_22->setObjectName(QStringLiteral("verticalLayout_22"));
        evtManLabel = new QLabel(eventManagerPage);
        evtManLabel->setObjectName(QStringLiteral("evtManLabel"));
        evtManLabel->setFont(font);
        evtManLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_22->addWidget(evtManLabel);

        frame15 = new QFrame(eventManagerPage);
        frame15->setObjectName(QStringLiteral("frame15"));
        frame15->setFrameShape(QFrame::WinPanel);
        horizontalLayout_41 = new QHBoxLayout(frame15);
        horizontalLayout_41->setObjectName(QStringLiteral("horizontalLayout_41"));
        frame16 = new QFrame(frame15);
        frame16->setObjectName(QStringLiteral("frame16"));
        frame16->setFrameShape(QFrame::Panel);
        horizontalLayout_55 = new QHBoxLayout(frame16);
        horizontalLayout_55->setObjectName(QStringLiteral("horizontalLayout_55"));
        horizontalLayout_54 = new QHBoxLayout();
        horizontalLayout_54->setObjectName(QStringLiteral("horizontalLayout_54"));
        verticalLayout_23 = new QVBoxLayout();
        verticalLayout_23->setObjectName(QStringLiteral("verticalLayout_23"));
        horizontalLayout_37 = new QHBoxLayout();
        horizontalLayout_37->setObjectName(QStringLiteral("horizontalLayout_37"));
        evtVehTableLabel = new QLabel(frame16);
        evtVehTableLabel->setObjectName(QStringLiteral("evtVehTableLabel"));

        horizontalLayout_37->addWidget(evtVehTableLabel);


        verticalLayout_23->addLayout(horizontalLayout_37);

        evtVehTableWidget = new QTableWidget(frame16);
        evtVehTableWidget->setObjectName(QStringLiteral("evtVehTableWidget"));

        verticalLayout_23->addWidget(evtVehTableWidget);


        horizontalLayout_54->addLayout(verticalLayout_23);

        verticalLayout_29 = new QVBoxLayout();
        verticalLayout_29->setObjectName(QStringLiteral("verticalLayout_29"));
        horizontalLayout_38 = new QHBoxLayout();
        horizontalLayout_38->setObjectName(QStringLiteral("horizontalLayout_38"));
        evtJobsTableLabel = new QLabel(frame16);
        evtJobsTableLabel->setObjectName(QStringLiteral("evtJobsTableLabel"));

        horizontalLayout_38->addWidget(evtJobsTableLabel);


        verticalLayout_29->addLayout(horizontalLayout_38);

        evtJobsTableWidget = new QTableWidget(frame16);
        evtJobsTableWidget->setObjectName(QStringLiteral("evtJobsTableWidget"));

        verticalLayout_29->addWidget(evtJobsTableWidget);


        horizontalLayout_54->addLayout(verticalLayout_29);

        verticalLayout_21 = new QVBoxLayout();
        verticalLayout_21->setObjectName(QStringLiteral("verticalLayout_21"));
        evtVehArrBtn = new QPushButton(frame16);
        evtVehArrBtn->setObjectName(QStringLiteral("evtVehArrBtn"));
        evtVehArrBtn->setEnabled(false);
        sizePolicy9.setHeightForWidth(evtVehArrBtn->sizePolicy().hasHeightForWidth());
        evtVehArrBtn->setSizePolicy(sizePolicy9);

        verticalLayout_21->addWidget(evtVehArrBtn);

        evtVehBTDBtn = new QPushButton(frame16);
        evtVehBTDBtn->setObjectName(QStringLiteral("evtVehBTDBtn"));
        evtVehBTDBtn->setEnabled(false);
        sizePolicy9.setHeightForWidth(evtVehBTDBtn->sizePolicy().hasHeightForWidth());
        evtVehBTDBtn->setSizePolicy(sizePolicy9);

        verticalLayout_21->addWidget(evtVehBTDBtn);


        horizontalLayout_54->addLayout(verticalLayout_21);


        horizontalLayout_55->addLayout(horizontalLayout_54);


        horizontalLayout_41->addWidget(frame16);

        frame17 = new QFrame(frame15);
        frame17->setObjectName(QStringLiteral("frame17"));
        frame17->setFrameShape(QFrame::Panel);
        horizontalLayout_57 = new QHBoxLayout(frame17);
        horizontalLayout_57->setObjectName(QStringLiteral("horizontalLayout_57"));
        horizontalLayout_56 = new QHBoxLayout();
        horizontalLayout_56->setObjectName(QStringLiteral("horizontalLayout_56"));
        verticalLayout_30 = new QVBoxLayout();
        verticalLayout_30->setObjectName(QStringLiteral("verticalLayout_30"));
        horizontalLayout_52 = new QHBoxLayout();
        horizontalLayout_52->setObjectName(QStringLiteral("horizontalLayout_52"));
        evtCusAnsTableLabel = new QLabel(frame17);
        evtCusAnsTableLabel->setObjectName(QStringLiteral("evtCusAnsTableLabel"));

        horizontalLayout_52->addWidget(evtCusAnsTableLabel);


        verticalLayout_30->addLayout(horizontalLayout_52);

        evtCusAnsTableWidget = new QTableWidget(frame17);
        evtCusAnsTableWidget->setObjectName(QStringLiteral("evtCusAnsTableWidget"));

        verticalLayout_30->addWidget(evtCusAnsTableWidget);

        horizontalLayout_45 = new QHBoxLayout();
        horizontalLayout_45->setObjectName(QStringLiteral("horizontalLayout_45"));
        evtCusAnsAcceptBtn = new QPushButton(frame17);
        evtCusAnsAcceptBtn->setObjectName(QStringLiteral("evtCusAnsAcceptBtn"));
        evtCusAnsAcceptBtn->setEnabled(false);

        horizontalLayout_45->addWidget(evtCusAnsAcceptBtn);

        evtCusAnsRefuseBtn = new QPushButton(frame17);
        evtCusAnsRefuseBtn->setObjectName(QStringLiteral("evtCusAnsRefuseBtn"));
        evtCusAnsRefuseBtn->setEnabled(false);

        horizontalLayout_45->addWidget(evtCusAnsRefuseBtn);


        verticalLayout_30->addLayout(horizontalLayout_45);


        horizontalLayout_56->addLayout(verticalLayout_30);

        verticalLayout_31 = new QVBoxLayout();
        verticalLayout_31->setObjectName(QStringLiteral("verticalLayout_31"));
        horizontalLayout_53 = new QHBoxLayout();
        horizontalLayout_53->setObjectName(QStringLiteral("horizontalLayout_53"));
        evtLogTableLabel = new QLabel(frame17);
        evtLogTableLabel->setObjectName(QStringLiteral("evtLogTableLabel"));

        horizontalLayout_53->addWidget(evtLogTableLabel);


        verticalLayout_31->addLayout(horizontalLayout_53);

        evtLogTableWidget = new QTableWidget(frame17);
        evtLogTableWidget->setObjectName(QStringLiteral("evtLogTableWidget"));
        evtLogTableWidget->setEnabled(false);

        verticalLayout_31->addWidget(evtLogTableWidget);


        horizontalLayout_56->addLayout(verticalLayout_31);


        horizontalLayout_57->addLayout(horizontalLayout_56);


        horizontalLayout_41->addWidget(frame17);


        verticalLayout_22->addWidget(frame15);

        frame18 = new QFrame(eventManagerPage);
        frame18->setObjectName(QStringLiteral("frame18"));
        frame18->setFrameShape(QFrame::WinPanel);
        horizontalLayout_40 = new QHBoxLayout(frame18);
        horizontalLayout_40->setObjectName(QStringLiteral("horizontalLayout_40"));
        evtSetCurTimeBtn = new QPushButton(frame18);
        evtSetCurTimeBtn->setObjectName(QStringLiteral("evtSetCurTimeBtn"));
        sizePolicy.setHeightForWidth(evtSetCurTimeBtn->sizePolicy().hasHeightForWidth());
        evtSetCurTimeBtn->setSizePolicy(sizePolicy);
        evtSetCurTimeBtn->setMinimumSize(QSize(150, 0));

        horizontalLayout_40->addWidget(evtSetCurTimeBtn);

        evtResetTimeBtn = new QPushButton(frame18);
        evtResetTimeBtn->setObjectName(QStringLiteral("evtResetTimeBtn"));
        evtResetTimeBtn->setEnabled(false);
        evtResetTimeBtn->setMinimumSize(QSize(150, 0));
        evtResetTimeBtn->setMaximumSize(QSize(150, 16777215));

        horizontalLayout_40->addWidget(evtResetTimeBtn);

        frame19 = new QFrame(frame18);
        frame19->setObjectName(QStringLiteral("frame19"));
        frame19->setFrameShape(QFrame::Panel);
        horizontalLayout_39 = new QHBoxLayout(frame19);
        horizontalLayout_39->setObjectName(QStringLiteral("horizontalLayout_39"));
        evtHourSpBox = new QSpinBox(frame19);
        evtHourSpBox->setObjectName(QStringLiteral("evtHourSpBox"));
        evtHourSpBox->setEnabled(false);
        evtHourSpBox->setMaximum(24);
        evtHourSpBox->setValue(9);

        horizontalLayout_39->addWidget(evtHourSpBox);

        evtMinuteSpBox = new QSpinBox(frame19);
        evtMinuteSpBox->setObjectName(QStringLiteral("evtMinuteSpBox"));
        evtMinuteSpBox->setEnabled(false);
        evtMinuteSpBox->setMaximum(60);

        horizontalLayout_39->addWidget(evtMinuteSpBox);

        evtSecondSpBox = new QSpinBox(frame19);
        evtSecondSpBox->setObjectName(QStringLiteral("evtSecondSpBox"));
        evtSecondSpBox->setEnabled(false);
        evtSecondSpBox->setMaximum(60);

        horizontalLayout_39->addWidget(evtSecondSpBox);


        horizontalLayout_40->addWidget(frame19);

        evtSimTimeSpBox = new QSpinBox(frame18);
        evtSimTimeSpBox->setObjectName(QStringLiteral("evtSimTimeSpBox"));
        evtSimTimeSpBox->setEnabled(false);
        evtSimTimeSpBox->setMaximum(100000);

        horizontalLayout_40->addWidget(evtSimTimeSpBox);

        evtConfirmCurTimeBtn = new QPushButton(frame18);
        evtConfirmCurTimeBtn->setObjectName(QStringLiteral("evtConfirmCurTimeBtn"));
        evtConfirmCurTimeBtn->setEnabled(false);
        sizePolicy.setHeightForWidth(evtConfirmCurTimeBtn->sizePolicy().hasHeightForWidth());
        evtConfirmCurTimeBtn->setSizePolicy(sizePolicy);
        evtConfirmCurTimeBtn->setMinimumSize(QSize(150, 0));

        horizontalLayout_40->addWidget(evtConfirmCurTimeBtn);


        verticalLayout_22->addWidget(frame18);


        verticalLayout_32->addLayout(verticalLayout_22);

        primaryStackedWidget->addWidget(eventManagerPage);
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        pushButton = new QPushButton(page);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(70, 50, 87, 27));
        pushButton_2 = new QPushButton(page);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(70, 100, 87, 27));
        pushButton_3 = new QPushButton(page);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(70, 160, 87, 27));
        pushButton_4 = new QPushButton(page);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(70, 210, 87, 27));
        pushButton_5 = new QPushButton(page);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(70, 10, 87, 27));
        primaryStackedWidget->addWidget(page);

        horizontalLayout->addWidget(primaryStackedWidget);


        verticalLayout_33->addLayout(horizontalLayout);


        retranslateUi(PrimeUI);

        primaryStackedWidget->setCurrentIndex(4);
        monToolBox->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(PrimeUI);
    } // setupUi

    void retranslateUi(QWidget *PrimeUI)
    {
        PrimeUI->setWindowTitle(QApplication::translate("PrimeUI", "VRPControlUI", 0));
        timeLabel->setText(QApplication::translate("PrimeUI", "Time:", 0));
        timeDataLabel->setText(QApplication::translate("PrimeUI", "00:00:00", 0));
        simTimeLabel->setText(QApplication::translate("PrimeUI", "Simulation Time:", 0));
        simTimeDataLabel->setText(QApplication::translate("PrimeUI", "0", 0));
        startHourLabel->setText(QApplication::translate("PrimeUI", "Start", 0));
        endHourLabel->setText(QApplication::translate("PrimeUI", "End", 0));
        opTimeBtn->setText(QApplication::translate("PrimeUI", "Set OpTime", 0));
        resetBtn->setText(QApplication::translate("PrimeUI", "Reset All", 0));
        posLabel->setText(QApplication::translate("PrimeUI", "Position:", 0));
        posDataLabel->setText(QApplication::translate("PrimeUI", "(,)", 0));
        coordLabel->setText(QApplication::translate("PrimeUI", "Coordinate:", 0));
        coordDataLabel->setText(QApplication::translate("PrimeUI", "(,)", 0));
        monBtn->setText(QApplication::translate("PrimeUI", "Monitoring", 0));
        locManBtn->setText(QApplication::translate("PrimeUI", "Location\n"
"Manager", 0));
        vehManBtn->setText(QApplication::translate("PrimeUI", "Vehicle\n"
"Manager", 0));
        cusManBtn->setText(QApplication::translate("PrimeUI", "Customer\n"
"Manager", 0));
        evtManBtn->setText(QApplication::translate("PrimeUI", "Event\n"
"Manager", 0));
        OptionsBtn->setText(QApplication::translate("PrimeUI", "Options", 0));
        monLabel->setText(QApplication::translate("PrimeUI", "Monitoring", 0));
        monToolBox->setItemText(monToolBox->indexOf(MonLocPage), QApplication::translate("PrimeUI", "Location", 0));
        monVehStatusBtn->setText(QApplication::translate("PrimeUI", "Status", 0));
        monVehJobsBtn->setText(QApplication::translate("PrimeUI", "Jobs", 0));
        monVehDistBtn->setText(QApplication::translate("PrimeUI", "Distances", 0));
        monToolBox->setItemText(monToolBox->indexOf(MonVehPage), QApplication::translate("PrimeUI", "Vehicle", 0));
        monToolBox->setItemText(monToolBox->indexOf(MonCusPage), QApplication::translate("PrimeUI", "Customer", 0));
        MonListWidgetLabel->setText(QApplication::translate("PrimeUI", "Label1", 0));
        MonTableWidgetLabel->setText(QApplication::translate("PrimeUI", "Label2", 0));
        locManLabel->setText(QApplication::translate("PrimeUI", "Location Manager", 0));
        locTableLabel->setText(QApplication::translate("PrimeUI", "Location List", 0));
        locRegBtn->setText(QApplication::translate("PrimeUI", "Register", 0));
        locDeregBtn->setText(QApplication::translate("PrimeUI", "Deregister", 0));
        locUpdateBtn->setText(QApplication::translate("PrimeUI", "Update", 0));
        locIdLabel->setText(QApplication::translate("PrimeUI", "Location ID", 0));
        LLGetCoordBtn->setText(QApplication::translate("PrimeUI", "Get\n"
"Coordinate", 0));
        locLatLabel->setText(QApplication::translate("PrimeUI", "Latitude:", 0));
        locLongLabel->setText(QApplication::translate("PrimeUI", "Longtitude:", 0));
        LLReflectBtn->setText(QApplication::translate("PrimeUI", "Reflect", 0));
        locConfirmBtn->setText(QApplication::translate("PrimeUI", "Confirm", 0));
        locCancelBtn->setText(QApplication::translate("PrimeUI", "Cancel", 0));
        vehManLabel->setText(QApplication::translate("PrimeUI", "Vehicle Manager", 0));
        vehTableLabel->setText(QApplication::translate("PrimeUI", "Vehicle List", 0));
        vehRegBtn->setText(QApplication::translate("PrimeUI", "Register", 0));
        vehDeregBtn->setText(QApplication::translate("PrimeUI", "Deregister", 0));
        vehUpdateBtn->setText(QApplication::translate("PrimeUI", "Update", 0));
        vehIdLabel->setText(QApplication::translate("PrimeUI", "Vehicle ID", 0));
        vehCoordChBox->setText(QApplication::translate("PrimeUI", "Coordinate", 0));
        vehLatLabel->setText(QApplication::translate("PrimeUI", "Latitude", 0));
        vehLongLabel->setText(QApplication::translate("PrimeUI", "Longtitude", 0));
        vehGetCoordBtn->setText(QApplication::translate("PrimeUI", "Get Coordinate", 0));
        vehRefCoordBtn->setText(QApplication::translate("PrimeUI", "Reflect", 0));
        vehSpeedChBox->setText(QApplication::translate("PrimeUI", "Speed", 0));
        vehCapChBox->setText(QApplication::translate("PrimeUI", "Capacity", 0));
        vehLCostChBox->setText(QApplication::translate("PrimeUI", "Launch Cost", 0));
        vehFTimeChBox->setText(QApplication::translate("PrimeUI", "Fix Time      ", 0));
        vehUTimeChBox->setText(QApplication::translate("PrimeUI", "Unit Time    ", 0));
        vehRTimeChBox->setText(QApplication::translate("PrimeUI", "Refuel Time", 0));
        vehBTimeChBox->setText(QApplication::translate("PrimeUI", "Buffer Time", 0));
        vehDefaultBtn->setText(QApplication::translate("PrimeUI", "Default", 0));
        vehConfirmBtn->setText(QApplication::translate("PrimeUI", "Confirm", 0));
        vehCancelBtn->setText(QApplication::translate("PrimeUI", "Cancel", 0));
        cusManLabel->setText(QApplication::translate("PrimeUI", "Customer Manager", 0));
        cusTableLabel->setText(QApplication::translate("PrimeUI", "Customer List", 0));
        cusReqBtn->setText(QApplication::translate("PrimeUI", "Request", 0));
        cusCancelReqBtn->setText(QApplication::translate("PrimeUI", "Cancel\n"
"Request", 0));
        cusChgReqBtn->setText(QApplication::translate("PrimeUI", "Change\n"
"Request", 0));
        cusIdLabel->setText(QApplication::translate("PrimeUI", "Customer ID", 0));
        cusDemandsChBox->setText(QApplication::translate("PrimeUI", "Demands", 0));
        cusPULocChBox->setText(QApplication::translate("PrimeUI", "Pick-up Location", 0));
        cusDLocChBox->setText(QApplication::translate("PrimeUI", "Delivery Location", 0));
        cusRSTimeChBox->setText(QApplication::translate("PrimeUI", "Reservation Time", 0));
        cusRSTimeMinLabel->setText(QApplication::translate("PrimeUI", "Minutes", 0));
        cusWTimeChBox->setText(QApplication::translate("PrimeUI", "Wait Time            ", 0));
        cusWTimeMinLabel->setText(QApplication::translate("PrimeUI", "Minutes", 0));
        cusConfirmBtn->setText(QApplication::translate("PrimeUI", "Confirm", 0));
        cusCancelBtn->setText(QApplication::translate("PrimeUI", "Cancel", 0));
        evtManLabel->setText(QApplication::translate("PrimeUI", "Event Manager", 0));
        evtVehTableLabel->setText(QApplication::translate("PrimeUI", "Vehicle List", 0));
        evtJobsTableLabel->setText(QApplication::translate("PrimeUI", "Jobs List", 0));
        evtVehArrBtn->setText(QApplication::translate("PrimeUI", "Arrive", 0));
        evtVehBTDBtn->setText(QApplication::translate("PrimeUI", "Back\n"
"To\n"
"Depot", 0));
        evtCusAnsTableLabel->setText(QApplication::translate("PrimeUI", "Customer Answers", 0));
        evtCusAnsAcceptBtn->setText(QApplication::translate("PrimeUI", "Accept", 0));
        evtCusAnsRefuseBtn->setText(QApplication::translate("PrimeUI", "Refuse", 0));
        evtLogTableLabel->setText(QApplication::translate("PrimeUI", "Log", 0));
        evtSetCurTimeBtn->setText(QApplication::translate("PrimeUI", "Set Current Time", 0));
        evtResetTimeBtn->setText(QApplication::translate("PrimeUI", "Reset", 0));
        evtConfirmCurTimeBtn->setText(QApplication::translate("PrimeUI", "Confirm", 0));
        pushButton->setText(QApplication::translate("PrimeUI", "Loc", 0));
        pushButton_2->setText(QApplication::translate("PrimeUI", "Veh", 0));
        pushButton_3->setText(QApplication::translate("PrimeUI", "Cus/Job", 0));
        pushButton_4->setText(QApplication::translate("PrimeUI", "Others", 0));
        pushButton_5->setText(QApplication::translate("PrimeUI", "All", 0));
    } // retranslateUi

};

namespace Ui {
    class PrimeUI: public Ui_PrimeUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRIMEUI_H
