#include "WidgetListItemsHandler.hpp"
#include <iostream>

WidgetListItemsHandler::WidgetListItemsHandler(QWidget* parent, Collect* collect): Handler(parent){
  this->ui_listItemsWidget = new Ui_listItemsWidget;
  this->ui_listItemsWidget->setupUi(parent);
  this->ui_listItemsWidget->retranslateUi(parent);
  this->collect = collect;
  updateList();
}

WidgetListItemsHandler::~WidgetListItemsHandler(){}

void WidgetListItemsHandler::updateList(){
  for(int i=0; i < collect->getNArticles(); i++){
    QListWidgetItem *item = new QListWidgetItem(this->ui_listItemsWidget->listWidgetItems);
    Message msg = this->collect->getArticle(i)->getMessage();
    item->setText(QString::fromUtf8("Título: ") + msg.getMessage());
    item->setBackgroundColor(msg.getColor());
  }
}


#include "WidgetListItemsHandler.moc"