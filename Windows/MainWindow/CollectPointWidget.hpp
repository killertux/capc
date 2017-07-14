/********************************************************************************
** Form generated from reading UI file 'CollectPointWidget.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef COLLECTPOINTWIDGET_H
#define COLLECTPOINTWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDateEdit>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QTextEdit>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_collectPointWidget
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QGridLayout *gridLayout;
    QLabel *dataDeInCioLabel;
    QDateEdit *dateEditStartDate;
    QLabel *dataDeFimLabel;
    QDateEdit *dateEditEndDate;
    QPushButton *pushButtonStartCollect;
    QTextEdit *textEdit;
    QPushButton *pushButtonCancel;

    void setupUi(QWidget *collectPointWidget)
    {
        if (collectPointWidget->objectName().isEmpty())
            collectPointWidget->setObjectName(QString::fromUtf8("collectPointWidget"));
        collectPointWidget->resize(645, 461);
        QFont font;
        font.setFamily(QString::fromUtf8("Verdana"));
        font.setBold(false);
        font.setWeight(50);
        collectPointWidget->setFont(font);
        verticalLayout = new QVBoxLayout(collectPointWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        label = new QLabel(collectPointWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Verdana"));
        font1.setPointSize(16);
        font1.setBold(false);
        font1.setWeight(50);
        label->setFont(font1);
        label->setAlignment(Qt::AlignHCenter|Qt::AlignTop);

        verticalLayout->addWidget(label);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        dataDeInCioLabel = new QLabel(collectPointWidget);
        dataDeInCioLabel->setObjectName(QString::fromUtf8("dataDeInCioLabel"));

        gridLayout->addWidget(dataDeInCioLabel, 0, 0, 1, 1);

        dateEditStartDate = new QDateEdit(collectPointWidget);
        dateEditStartDate->setObjectName(QString::fromUtf8("dateEditStartDate"));

        gridLayout->addWidget(dateEditStartDate, 0, 1, 1, 1);

        dataDeFimLabel = new QLabel(collectPointWidget);
        dataDeFimLabel->setObjectName(QString::fromUtf8("dataDeFimLabel"));

        gridLayout->addWidget(dataDeFimLabel, 1, 0, 1, 1);

        dateEditEndDate = new QDateEdit(collectPointWidget);
        dateEditEndDate->setObjectName(QString::fromUtf8("dateEditEndDate"));

        gridLayout->addWidget(dateEditEndDate, 1, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        pushButtonStartCollect = new QPushButton(collectPointWidget);
        pushButtonStartCollect->setObjectName(QString::fromUtf8("pushButtonStartCollect"));

        verticalLayout->addWidget(pushButtonStartCollect);

        textEdit = new QTextEdit(collectPointWidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(textEdit->sizePolicy().hasHeightForWidth());
        textEdit->setSizePolicy(sizePolicy);
        textEdit->setMaximumSize(QSize(16777215, 16777215));
        textEdit->setReadOnly(true);

        verticalLayout->addWidget(textEdit);

        pushButtonCancel = new QPushButton(collectPointWidget);
        pushButtonCancel->setObjectName(QString::fromUtf8("pushButtonCancel"));

        verticalLayout->addWidget(pushButtonCancel);

        label->raise();
        pushButtonCancel->raise();
        textEdit->raise();
        pushButtonStartCollect->raise();

        retranslateUi(collectPointWidget);

        QMetaObject::connectSlotsByName(collectPointWidget);
    } // setupUi

    void retranslateUi(QWidget *collectPointWidget)
    {
        collectPointWidget->setWindowTitle(QApplication::translate("collectPointWidget", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("collectPointWidget", "Realizar Coleta", 0, QApplication::UnicodeUTF8));
        dataDeInCioLabel->setText(QApplication::translate("collectPointWidget", "Data de In\303\255cio:", 0, QApplication::UnicodeUTF8));
        dateEditStartDate->setDisplayFormat(QApplication::translate("collectPointWidget", "dd-MM-yyyy", 0, QApplication::UnicodeUTF8));
        dataDeFimLabel->setText(QApplication::translate("collectPointWidget", "Data de Fim", 0, QApplication::UnicodeUTF8));
        dateEditEndDate->setDisplayFormat(QApplication::translate("collectPointWidget", "dd-MM-yyyy", 0, QApplication::UnicodeUTF8));
        pushButtonStartCollect->setText(QApplication::translate("collectPointWidget", "Come\303\247ar Coleta", 0, QApplication::UnicodeUTF8));
        pushButtonCancel->setText(QApplication::translate("collectPointWidget", "Cancelar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class collectPointWidget: public Ui_collectPointWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // COLLECTPOINTWIDGET_H
