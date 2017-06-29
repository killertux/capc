/********************************************************************************
** Form generated from reading UI file 'SettingsWidget.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef SETTINGSWIDGET_H
#define SETTINGSWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QFormLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "kurlrequester.h"

QT_BEGIN_NAMESPACE

class Ui_widgetSettings
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *labelSettings;
    QFormLayout *formLayout;
    QLabel *labelSelectTypeOfCollect;
    QComboBox *comboBoxSelectTypeOfCollect;
    QPushButton *pushButtonAddCollectPoint;
    QLabel *adicionarDefiniEsDosArtigosLabel;
    KUrlRequester *kurlrequesterXmlMeta;
    QLabel *oAIParaRealizarADeduplicaOLabel;
    QLineEdit *oAIParaRealizarADeduplicaOLineEdit;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButtonSave;

    void setupUi(QWidget *widgetSettings)
    {
        if (widgetSettings->objectName().isEmpty())
            widgetSettings->setObjectName(QString::fromUtf8("widgetSettings"));
        widgetSettings->resize(646, 509);
        QFont font;
        font.setFamily(QString::fromUtf8("Verdana"));
        widgetSettings->setFont(font);
        verticalLayout = new QVBoxLayout(widgetSettings);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        labelSettings = new QLabel(widgetSettings);
        labelSettings->setObjectName(QString::fromUtf8("labelSettings"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Verdana"));
        font1.setPointSize(18);
        labelSettings->setFont(font1);
        labelSettings->setAlignment(Qt::AlignHCenter|Qt::AlignTop);

        verticalLayout->addWidget(labelSettings);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::ExpandingFieldsGrow);
        formLayout->setRowWrapPolicy(QFormLayout::WrapLongRows);
        formLayout->setLabelAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        labelSelectTypeOfCollect = new QLabel(widgetSettings);
        labelSelectTypeOfCollect->setObjectName(QString::fromUtf8("labelSelectTypeOfCollect"));

        formLayout->setWidget(0, QFormLayout::LabelRole, labelSelectTypeOfCollect);

        comboBoxSelectTypeOfCollect = new QComboBox(widgetSettings);
        comboBoxSelectTypeOfCollect->setObjectName(QString::fromUtf8("comboBoxSelectTypeOfCollect"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(comboBoxSelectTypeOfCollect->sizePolicy().hasHeightForWidth());
        comboBoxSelectTypeOfCollect->setSizePolicy(sizePolicy);
        comboBoxSelectTypeOfCollect->setEditable(false);
        comboBoxSelectTypeOfCollect->setSizeAdjustPolicy(QComboBox::AdjustToContentsOnFirstShow);
        comboBoxSelectTypeOfCollect->setDuplicatesEnabled(false);

        formLayout->setWidget(0, QFormLayout::FieldRole, comboBoxSelectTypeOfCollect);

        pushButtonAddCollectPoint = new QPushButton(widgetSettings);
        pushButtonAddCollectPoint->setObjectName(QString::fromUtf8("pushButtonAddCollectPoint"));

        formLayout->setWidget(1, QFormLayout::FieldRole, pushButtonAddCollectPoint);

        adicionarDefiniEsDosArtigosLabel = new QLabel(widgetSettings);
        adicionarDefiniEsDosArtigosLabel->setObjectName(QString::fromUtf8("adicionarDefiniEsDosArtigosLabel"));

        formLayout->setWidget(2, QFormLayout::LabelRole, adicionarDefiniEsDosArtigosLabel);

        kurlrequesterXmlMeta = new KUrlRequester(widgetSettings);
        kurlrequesterXmlMeta->setObjectName(QString::fromUtf8("kurlrequesterXmlMeta"));

        formLayout->setWidget(2, QFormLayout::FieldRole, kurlrequesterXmlMeta);

        oAIParaRealizarADeduplicaOLabel = new QLabel(widgetSettings);
        oAIParaRealizarADeduplicaOLabel->setObjectName(QString::fromUtf8("oAIParaRealizarADeduplicaOLabel"));

        formLayout->setWidget(3, QFormLayout::LabelRole, oAIParaRealizarADeduplicaOLabel);

        oAIParaRealizarADeduplicaOLineEdit = new QLineEdit(widgetSettings);
        oAIParaRealizarADeduplicaOLineEdit->setObjectName(QString::fromUtf8("oAIParaRealizarADeduplicaOLineEdit"));

        formLayout->setWidget(3, QFormLayout::FieldRole, oAIParaRealizarADeduplicaOLineEdit);


        verticalLayout->addLayout(formLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        pushButtonSave = new QPushButton(widgetSettings);
        pushButtonSave->setObjectName(QString::fromUtf8("pushButtonSave"));

        verticalLayout->addWidget(pushButtonSave);


        retranslateUi(widgetSettings);

        QMetaObject::connectSlotsByName(widgetSettings);
    } // setupUi

    void retranslateUi(QWidget *widgetSettings)
    {
        widgetSettings->setWindowTitle(QApplication::translate("widgetSettings", "Configura\303\247\303\265es", 0, QApplication::UnicodeUTF8));
        labelSettings->setText(QApplication::translate("widgetSettings", "Configura\303\247\303\265es", 0, QApplication::UnicodeUTF8));
        labelSelectTypeOfCollect->setText(QApplication::translate("widgetSettings", "Selecione o tipo da coleta:", 0, QApplication::UnicodeUTF8));
        pushButtonAddCollectPoint->setText(QApplication::translate("widgetSettings", "Adicionar Ponto de Coleta", 0, QApplication::UnicodeUTF8));
        adicionarDefiniEsDosArtigosLabel->setText(QApplication::translate("widgetSettings", "Adicionar defini\303\247\303\265es dos artigos:", 0, QApplication::UnicodeUTF8));
        oAIParaRealizarADeduplicaOLabel->setText(QApplication::translate("widgetSettings", "OAI Para realizar a deduplica\303\247\303\243o:", 0, QApplication::UnicodeUTF8));
        pushButtonSave->setText(QApplication::translate("widgetSettings", "Salvar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class widgetSettings: public Ui_widgetSettings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // SETTINGSWIDGET_H
