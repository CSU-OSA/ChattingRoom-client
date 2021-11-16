/********************************************************************************
** Form generated from reading UI file 'CSUchatting.ui'
**
** Created by: Qt User Interface Compiler version 6.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CSUCHATTING_H
#define UI_CSUCHATTING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CSUchatting
{
public:
    QWidget *centralwidget;
    QTextBrowser *msgBox;
    QLineEdit *usrNick;
    QLineEdit *usrTicket;
    QPushButton *submitButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *CSUchatting)
    {
        if (CSUchatting->objectName().isEmpty())
            CSUchatting->setObjectName(QString::fromUtf8("CSUchatting"));
        CSUchatting->resize(500, 350);
        centralwidget = new QWidget(CSUchatting);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        msgBox = new QTextBrowser(centralwidget);
        msgBox->setObjectName(QString::fromUtf8("msgBox"));
        msgBox->setGeometry(QRect(50, 150, 381, 131));
        usrNick = new QLineEdit(centralwidget);
        usrNick->setObjectName(QString::fromUtf8("usrNick"));
        usrNick->setGeometry(QRect(80, 20, 151, 31));
        usrTicket = new QLineEdit(centralwidget);
        usrTicket->setObjectName(QString::fromUtf8("usrTicket"));
        usrTicket->setGeometry(QRect(80, 59, 151, 31));
        submitButton = new QPushButton(centralwidget);
        submitButton->setObjectName(QString::fromUtf8("submitButton"));
        submitButton->setGeometry(QRect(260, 40, 111, 31));
        CSUchatting->setCentralWidget(centralwidget);
        menubar = new QMenuBar(CSUchatting);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 500, 25));
        CSUchatting->setMenuBar(menubar);
        statusbar = new QStatusBar(CSUchatting);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        CSUchatting->setStatusBar(statusbar);

        retranslateUi(CSUchatting);

        QMetaObject::connectSlotsByName(CSUchatting);
    } // setupUi

    void retranslateUi(QMainWindow *CSUchatting)
    {
        CSUchatting->setWindowTitle(QCoreApplication::translate("CSUchatting", "csu", nullptr));
        submitButton->setText(QCoreApplication::translate("CSUchatting", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CSUchatting: public Ui_CSUchatting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CSUCHATTING_H
