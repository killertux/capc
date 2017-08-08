/********************************************************************************
** Form generated from reading UI file 'ListItemsWidget.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef LISTITEMSWIDGET_H
#define LISTITEMSWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_listItemsWidget
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QListWidget *listWidgetItems;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButtonBack;
    QPushButton *pushButtonNote;
    QPushButton *pushButtonEdit;

    void setupUi(QWidget *listItemsWidget)
    {
        if (listItemsWidget->objectName().isEmpty())
            listItemsWidget->setObjectName(QString::fromUtf8("listItemsWidget"));
        listItemsWidget->resize(400, 300);
        QFont font;
        font.setFamily(QString::fromUtf8("Verdana"));
        listItemsWidget->setFont(font);
        verticalLayout = new QVBoxLayout(listItemsWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(listItemsWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Verdana"));
        font1.setPointSize(16);
        label->setFont(font1);
        label->setAlignment(Qt::AlignHCenter|Qt::AlignTop);

        verticalLayout->addWidget(label);

        listWidgetItems = new QListWidget(listItemsWidget);
        listWidgetItems->setObjectName(QString::fromUtf8("listWidgetItems"));
        listWidgetItems->setProperty("isWrapping", QVariant(false));

        verticalLayout->addWidget(listWidgetItems);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButtonBack = new QPushButton(listItemsWidget);
        pushButtonBack->setObjectName(QString::fromUtf8("pushButtonBack"));

        horizontalLayout->addWidget(pushButtonBack);

        pushButtonNote = new QPushButton(listItemsWidget);
        pushButtonNote->setObjectName(QString::fromUtf8("pushButtonNote"));

        horizontalLayout->addWidget(pushButtonNote);

        pushButtonEdit = new QPushButton(listItemsWidget);
        pushButtonEdit->setObjectName(QString::fromUtf8("pushButtonEdit"));

        horizontalLayout->addWidget(pushButtonEdit);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(listItemsWidget);

        QMetaObject::connectSlotsByName(listItemsWidget);
    } // setupUi

    void retranslateUi(QWidget *listItemsWidget)
    {
        listItemsWidget->setWindowTitle(QApplication::translate("listItemsWidget", "Itens Coletados", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("listItemsWidget", "Itens Coletados", 0, QApplication::UnicodeUTF8));
        pushButtonBack->setText(QApplication::translate("listItemsWidget", "Voltar", 0, QApplication::UnicodeUTF8));
        pushButtonNote->setText(QApplication::translate("listItemsWidget", "Adicionar Nota", 0, QApplication::UnicodeUTF8));
        pushButtonEdit->setText(QApplication::translate("listItemsWidget", "Editar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class listItemsWidget: public Ui_listItemsWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // LISTITEMSWIDGET_H
