/********************************************************************************
** Form generated from reading UI file 'OAISettingsWindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef OAISETTINGSWINDOW_H
#define OAISETTINGSWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFormLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "kurllabel.h"
#include "kurlrequester.h"

QT_BEGIN_NAMESPACE

class Ui_OAISettingsWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QFormLayout *formLayout;
    QLabel *labelOAIAddress;
    QLineEdit *lineEditOAIAddress;
    QLabel *labelMetadataType;
    QLineEdit *lineEditMetadataType;
    QLabel *labelXSLT;
    KUrlRequester *kurlrequesterXSLT;
    QLabel *labelScript;
    KUrlRequester *kurlrequesterScript;
    QLabel *labelScriptParameters;
    QLineEdit *lineEditScriptParameters;
    QLabel *labelName;
    QLineEdit *lineEditName;
    QLabel *labelInfo;
    KUrlLabel *kurllabelDocumentation;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButtonCancel;
    QPushButton *pushButtonSave;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *OAISettingsWindow)
    {
        if (OAISettingsWindow->objectName().isEmpty())
            OAISettingsWindow->setObjectName(QString::fromUtf8("OAISettingsWindow"));
        OAISettingsWindow->resize(439, 349);
        QFont font;
        font.setFamily(QString::fromUtf8("Verdana"));
        OAISettingsWindow->setFont(font);
        centralwidget = new QWidget(OAISettingsWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Verdana"));
        font1.setPointSize(18);
        label->setFont(font1);
        label->setAlignment(Qt::AlignHCenter|Qt::AlignTop);

        verticalLayout->addWidget(label);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::ExpandingFieldsGrow);
        labelOAIAddress = new QLabel(centralwidget);
        labelOAIAddress->setObjectName(QString::fromUtf8("labelOAIAddress"));

        formLayout->setWidget(1, QFormLayout::LabelRole, labelOAIAddress);

        lineEditOAIAddress = new QLineEdit(centralwidget);
        lineEditOAIAddress->setObjectName(QString::fromUtf8("lineEditOAIAddress"));

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEditOAIAddress);

        labelMetadataType = new QLabel(centralwidget);
        labelMetadataType->setObjectName(QString::fromUtf8("labelMetadataType"));

        formLayout->setWidget(2, QFormLayout::LabelRole, labelMetadataType);

        lineEditMetadataType = new QLineEdit(centralwidget);
        lineEditMetadataType->setObjectName(QString::fromUtf8("lineEditMetadataType"));

        formLayout->setWidget(2, QFormLayout::FieldRole, lineEditMetadataType);

        labelXSLT = new QLabel(centralwidget);
        labelXSLT->setObjectName(QString::fromUtf8("labelXSLT"));

        formLayout->setWidget(3, QFormLayout::LabelRole, labelXSLT);

        kurlrequesterXSLT = new KUrlRequester(centralwidget);
        kurlrequesterXSLT->setObjectName(QString::fromUtf8("kurlrequesterXSLT"));

        formLayout->setWidget(3, QFormLayout::FieldRole, kurlrequesterXSLT);

        labelScript = new QLabel(centralwidget);
        labelScript->setObjectName(QString::fromUtf8("labelScript"));

        formLayout->setWidget(4, QFormLayout::LabelRole, labelScript);

        kurlrequesterScript = new KUrlRequester(centralwidget);
        kurlrequesterScript->setObjectName(QString::fromUtf8("kurlrequesterScript"));

        formLayout->setWidget(4, QFormLayout::FieldRole, kurlrequesterScript);

        labelScriptParameters = new QLabel(centralwidget);
        labelScriptParameters->setObjectName(QString::fromUtf8("labelScriptParameters"));

        formLayout->setWidget(5, QFormLayout::LabelRole, labelScriptParameters);

        lineEditScriptParameters = new QLineEdit(centralwidget);
        lineEditScriptParameters->setObjectName(QString::fromUtf8("lineEditScriptParameters"));

        formLayout->setWidget(5, QFormLayout::FieldRole, lineEditScriptParameters);

        labelName = new QLabel(centralwidget);
        labelName->setObjectName(QString::fromUtf8("labelName"));

        formLayout->setWidget(0, QFormLayout::LabelRole, labelName);

        lineEditName = new QLineEdit(centralwidget);
        lineEditName->setObjectName(QString::fromUtf8("lineEditName"));

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEditName);


        verticalLayout->addLayout(formLayout);

        labelInfo = new QLabel(centralwidget);
        labelInfo->setObjectName(QString::fromUtf8("labelInfo"));

        verticalLayout->addWidget(labelInfo);

        kurllabelDocumentation = new KUrlLabel(centralwidget);
        kurllabelDocumentation->setObjectName(QString::fromUtf8("kurllabelDocumentation"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(kurllabelDocumentation->sizePolicy().hasHeightForWidth());
        kurllabelDocumentation->setSizePolicy(sizePolicy);
        kurllabelDocumentation->setFocusPolicy(Qt::ClickFocus);
        kurllabelDocumentation->setOpenExternalLinks(true);
        kurllabelDocumentation->setUseCursor(true);

        verticalLayout->addWidget(kurllabelDocumentation);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pushButtonCancel = new QPushButton(centralwidget);
        pushButtonCancel->setObjectName(QString::fromUtf8("pushButtonCancel"));

        horizontalLayout_2->addWidget(pushButtonCancel);

        pushButtonSave = new QPushButton(centralwidget);
        pushButtonSave->setObjectName(QString::fromUtf8("pushButtonSave"));

        horizontalLayout_2->addWidget(pushButtonSave);


        verticalLayout->addLayout(horizontalLayout_2);

        OAISettingsWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(OAISettingsWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 439, 25));
        OAISettingsWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(OAISettingsWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        OAISettingsWindow->setStatusBar(statusbar);
        QWidget::setTabOrder(lineEditName, lineEditOAIAddress);
        QWidget::setTabOrder(lineEditOAIAddress, lineEditMetadataType);
        QWidget::setTabOrder(lineEditMetadataType, kurlrequesterXSLT);
        QWidget::setTabOrder(kurlrequesterXSLT, kurlrequesterScript);
        QWidget::setTabOrder(kurlrequesterScript, lineEditScriptParameters);
        QWidget::setTabOrder(lineEditScriptParameters, pushButtonSave);
        QWidget::setTabOrder(pushButtonSave, pushButtonCancel);

        retranslateUi(OAISettingsWindow);

        QMetaObject::connectSlotsByName(OAISettingsWindow);
    } // setupUi

    void retranslateUi(QMainWindow *OAISettingsWindow)
    {
        OAISettingsWindow->setWindowTitle(QApplication::translate("OAISettingsWindow", "Novo Ponto de Coleta", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("OAISettingsWindow", "Novo ponto de Coleta OAI-PMH", 0, QApplication::UnicodeUTF8));
        labelOAIAddress->setText(QApplication::translate("OAISettingsWindow", "Endere\303\247o OAI:", 0, QApplication::UnicodeUTF8));
        labelMetadataType->setText(QApplication::translate("OAISettingsWindow", "Padr\303\243o de metadados:", 0, QApplication::UnicodeUTF8));
        labelXSLT->setText(QApplication::translate("OAISettingsWindow", "Folha de estilo:", 0, QApplication::UnicodeUTF8));
        labelScript->setText(QApplication::translate("OAISettingsWindow", "Script externo:", 0, QApplication::UnicodeUTF8));
        labelScriptParameters->setText(QApplication::translate("OAISettingsWindow", "Par\303\242metros para o script:", 0, QApplication::UnicodeUTF8));
        labelName->setText(QApplication::translate("OAISettingsWindow", "Nome:", 0, QApplication::UnicodeUTF8));
        labelInfo->setText(QApplication::translate("OAISettingsWindow", "D\303\272vidas, consulte a documenta\303\247\303\243o em:", 0, QApplication::UnicodeUTF8));
        kurllabelDocumentation->setText(QApplication::translate("OAISettingsWindow", "https://github.com/killertux/capc", 0, QApplication::UnicodeUTF8));
        pushButtonCancel->setText(QApplication::translate("OAISettingsWindow", "Cancelar", 0, QApplication::UnicodeUTF8));
        pushButtonSave->setText(QApplication::translate("OAISettingsWindow", "Salvar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class OAISettingsWindow: public Ui_OAISettingsWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // OAISETTINGSWINDOW_H
