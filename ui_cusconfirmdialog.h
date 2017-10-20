/********************************************************************************
** Form generated from reading UI file 'cusconfirmdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CUSCONFIRMDIALOG_H
#define UI_CUSCONFIRMDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_cusconfirmdialog
{
public:
    QPushButton *confirmBtn;
    QPushButton *rejectBtn;
    QLabel *vidLabel;
    QLabel *cidLabel;
    QLabel *wtimeLabel;

    void setupUi(QDialog *cusconfirmdialog)
    {
        if (cusconfirmdialog->objectName().isEmpty())
            cusconfirmdialog->setObjectName(QStringLiteral("cusconfirmdialog"));
        cusconfirmdialog->resize(400, 103);
        confirmBtn = new QPushButton(cusconfirmdialog);
        confirmBtn->setObjectName(QStringLiteral("confirmBtn"));
        confirmBtn->setGeometry(QRect(40, 60, 87, 27));
        rejectBtn = new QPushButton(cusconfirmdialog);
        rejectBtn->setObjectName(QStringLiteral("rejectBtn"));
        rejectBtn->setGeometry(QRect(250, 60, 87, 27));
        vidLabel = new QLabel(cusconfirmdialog);
        vidLabel->setObjectName(QStringLiteral("vidLabel"));
        vidLabel->setGeometry(QRect(40, 20, 63, 17));
        cidLabel = new QLabel(cusconfirmdialog);
        cidLabel->setObjectName(QStringLiteral("cidLabel"));
        cidLabel->setGeometry(QRect(170, 20, 63, 17));
        wtimeLabel = new QLabel(cusconfirmdialog);
        wtimeLabel->setObjectName(QStringLiteral("wtimeLabel"));
        wtimeLabel->setGeometry(QRect(290, 20, 63, 17));

        retranslateUi(cusconfirmdialog);

        QMetaObject::connectSlotsByName(cusconfirmdialog);
    } // setupUi

    void retranslateUi(QDialog *cusconfirmdialog)
    {
        cusconfirmdialog->setWindowTitle(QApplication::translate("cusconfirmdialog", "Dialog", 0));
        confirmBtn->setText(QApplication::translate("cusconfirmdialog", "confirm", 0));
        rejectBtn->setText(QApplication::translate("cusconfirmdialog", "reject", 0));
        vidLabel->setText(QApplication::translate("cusconfirmdialog", "vid", 0));
        cidLabel->setText(QApplication::translate("cusconfirmdialog", "cid", 0));
        wtimeLabel->setText(QApplication::translate("cusconfirmdialog", "wtime", 0));
    } // retranslateUi

};

namespace Ui {
    class cusconfirmdialog: public Ui_cusconfirmdialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CUSCONFIRMDIALOG_H
