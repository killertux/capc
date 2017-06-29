/********************************************************************************
** Form generated from reading UI file 'StartWindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StartWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QLabel *labelTitle;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButtonCollect;
    QPushButton *pushButtonVisualize;
    QPushButton *pushButtonSettings;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *StartWindow)
    {
        if (StartWindow->objectName().isEmpty())
            StartWindow->setObjectName(QString::fromUtf8("StartWindow"));
        StartWindow->resize(555, 308);
        centralwidget = new QWidget(StartWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        labelTitle = new QLabel(centralwidget);
        labelTitle->setObjectName(QString::fromUtf8("labelTitle"));
        QFont font;
        font.setFamily(QString::fromUtf8("Verdana"));
        font.setPointSize(18);
        labelTitle->setFont(font);
        labelTitle->setAlignment(Qt::AlignHCenter|Qt::AlignTop);

        verticalLayout->addWidget(labelTitle);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButtonCollect = new QPushButton(centralwidget);
        pushButtonCollect->setObjectName(QString::fromUtf8("pushButtonCollect"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButtonCollect->sizePolicy().hasHeightForWidth());
        pushButtonCollect->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setFamily(QString::fromUtf8("Verdana"));
        font1.setPointSize(16);
        pushButtonCollect->setFont(font1);

        horizontalLayout->addWidget(pushButtonCollect);

        pushButtonVisualize = new QPushButton(centralwidget);
        pushButtonVisualize->setObjectName(QString::fromUtf8("pushButtonVisualize"));
        pushButtonVisualize->setFont(font1);

        horizontalLayout->addWidget(pushButtonVisualize);

        pushButtonSettings = new QPushButton(centralwidget);
        pushButtonSettings->setObjectName(QString::fromUtf8("pushButtonSettings"));
        pushButtonSettings->setFont(font1);

        horizontalLayout->addWidget(pushButtonSettings);


        verticalLayout->addLayout(horizontalLayout);

        StartWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(StartWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 555, 24));
        StartWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(StartWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        StartWindow->setStatusBar(statusbar);

        retranslateUi(StartWindow);

        QMetaObject::connectSlotsByName(StartWindow);
    } // setupUi

    void retranslateUi(QMainWindow *StartWindow)
    {
        StartWindow->setWindowTitle(QApplication::translate("StartWindow", "CAPC", 0, QApplication::UnicodeUTF8));
        labelTitle->setText(QApplication::translate("StartWindow", "Coleta Autom\303\241tica de Peri\303\263dicos Cient\303\255ficos", 0, QApplication::UnicodeUTF8));
        pushButtonCollect->setText(QApplication::translate("StartWindow", "Realizar Coleta", 0, QApplication::UnicodeUTF8));
        pushButtonVisualize->setText(QApplication::translate("StartWindow", "Visualizar Coletas", 0, QApplication::UnicodeUTF8));
        pushButtonSettings->setText(QApplication::translate("StartWindow", "Configurar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class StartWindow: public Ui_StartWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // STARTWINDOW_H
