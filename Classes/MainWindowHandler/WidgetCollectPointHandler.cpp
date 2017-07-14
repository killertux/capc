#include "WidgetCollectPointHandler.hpp"

WidgetCollectPointHandler::WidgetCollectPointHandler(QWidget* parent, CollectPoints *collectPoint): Handler(parent){
  this->ui_collectPointWidget = new Ui_collectPointWidget();
  this->ui_collectPointWidget->setupUi(parent);
  this->ui_collectPointWidget->retranslateUi(parent);
  this->collectPoint = collectPoint;
  
  this->ui_collectPointWidget->dateEditStartDate->setDate(collectPoint->getLastCollected());
  this->ui_collectPointWidget->dateEditEndDate->setDate(QDate::currentDate());
  
  //connects
  parent->connect(this->ui_collectPointWidget->pushButtonCancel,SIGNAL(clicked()),this,SLOT(cancel()));
  parent->connect(this->ui_collectPointWidget->pushButtonStartCollect,SIGNAL(clicked()),this,SLOT(collect()));
  
}

WidgetCollectPointHandler::~WidgetCollectPointHandler(){
  delete this->ui_collectPointWidget;
}

void WidgetCollectPointHandler::cancel(){
  delete this->collectPoint;
  emit(deleteThis());
}

void WidgetCollectPointHandler::addMessage(Message newMessage){
  this->ui_collectPointWidget->textEdit->setTextBackgroundColor(newMessage.getColor());
  this->ui_collectPointWidget->textEdit->insertPlainText(newMessage.getMessage()+"\n");
}

void WidgetCollectPointHandler::collect(){
  this->ui_collectPointWidget->pushButtonStartCollect->setDisabled(true);
  this->collectPoint->collect(articles, this->ui_collectPointWidget->dateEditStartDate->date(), this->ui_collectPointWidget->dateEditEndDate->date());

}


#include "WidgetCollectPointHandler.moc"