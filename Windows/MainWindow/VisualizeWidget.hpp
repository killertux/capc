/********************************************************************************
** Form generated from reading UI file 'VisualizeWidget.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef VISUALIZEWIDGET_H
#define VISUALIZEWIDGET_H

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

class Ui_visualizeWidget
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *labelVisualizeCollects;
    QListWidget *listWidgetCollects;
    QPushButton *pushButton;

    void setupUi(QWidget *visualizeWidget)
    {
        if (visualizeWidget->objectName().isEmpty())
            visualizeWidget->setObjectName(QString::fromUtf8("visualizeWidget"));
        visualizeWidget->resize(400, 300);
        QFont font;
        font.setFamily(QString::fromUtf8("Verdana"));
        font.setBold(true);
        font.setWeight(75);
        visualizeWidget->setFont(font);
        verticalLayout = new QVBoxLayout(visualizeWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        labelVisualizeCollects = new QLabel(visualizeWidget);
        labelVisualizeCollects->setObjectName(QString::fromUtf8("labelVisualizeCollects"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Verdana"));
        font1.setPointSize(16);
        font1.setBold(false);
        font1.setWeight(50);
        labelVisualizeCollects->setFont(font1);
        labelVisualizeCollects->setAlignment(Qt::AlignHCenter|Qt::AlignTop);

        verticalLayout->addWidget(labelVisualizeCollects);

        listWidgetCollects = new QListWidget(visualizeWidget);
        listWidgetCollects->setObjectName(QString::fromUtf8("listWidgetCollects"));
        QFont font2;
        font2.setBold(false);
        font2.setWeight(50);
        listWidgetCollects->setFont(font2);

        verticalLayout->addWidget(listWidgetCollects);

        pushButton = new QPushButton(visualizeWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setFont(font2);

        verticalLayout->addWidget(pushButton);


        retranslateUi(visualizeWidget);

        QMetaObject::connectSlotsByName(visualizeWidget);
    } // setupUi

    void retranslateUi(QWidget *visualizeWidget)
    {
        visualizeWidget->setWindowTitle(QApplication::translate("visualizeWidget", "Visualizar Widget", 0, QApplication::UnicodeUTF8));
        labelVisualizeCollects->setText(QApplication::translate("visualizeWidget", "Visualizar Coletas", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("visualizeWidget", "Abrir Coleta", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class visualizeWidget: public Ui_visualizeWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // VISUALIZEWIDGET_H
