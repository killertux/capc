/********************************************************************************
** Form generated from reading UI file 'CollectWidget.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef COLLECTWIDGET_H
#define COLLECTWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_collectWidget
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QListWidget *listWidget;
    QPushButton *pushButton;

    void setupUi(QWidget *collectWidget)
    {
        if (collectWidget->objectName().isEmpty())
            collectWidget->setObjectName(QString::fromUtf8("collectWidget"));
        collectWidget->resize(518, 349);
        QFont font;
        font.setFamily(QString::fromUtf8("Verdana"));
        collectWidget->setFont(font);
        verticalLayout = new QVBoxLayout(collectWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(collectWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Verdana"));
        font1.setPointSize(16);
        label->setFont(font1);
        label->setAlignment(Qt::AlignHCenter|Qt::AlignTop);

        verticalLayout->addWidget(label);

        label_2 = new QLabel(collectWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        verticalLayout->addWidget(label_2);

        listWidget = new QListWidget(collectWidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        verticalLayout->addWidget(listWidget);

        pushButton = new QPushButton(collectWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout->addWidget(pushButton);


        retranslateUi(collectWidget);

        QMetaObject::connectSlotsByName(collectWidget);
    } // setupUi

    void retranslateUi(QWidget *collectWidget)
    {
        collectWidget->setWindowTitle(QApplication::translate("collectWidget", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("collectWidget", "Realizar Coleta", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("collectWidget", "Pontos de coletas:", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("collectWidget", "Coletar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class collectWidget: public Ui_collectWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // COLLECTWIDGET_H
