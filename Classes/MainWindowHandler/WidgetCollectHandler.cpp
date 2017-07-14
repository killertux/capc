#include "WidgetCollectHandler.hpp"

#include <iostream>

WidgetCollectHandler::WidgetCollectHandler(QWidget *parent): Handler(parent){
  this->ui_collectWidget = new Ui_collectWidget();
  this->ui_collectWidget->setupUi(parent);
  this->ui_collectWidget->retranslateUi(parent);
  
  this->updateCollectList();
  
  //Connects
  parent->connect(this->ui_collectWidget->pushButton,SIGNAL(clicked()),this,SLOT(startCollect()));
}

WidgetCollectHandler::~WidgetCollectHandler(){
  delete this->ui_collectWidget;
}


void WidgetCollectHandler::updateCollectList(){
  CollectPointsManager collectPointsManager;
  QDir dir(COLLECT_POINTS_CONFIG_FOLDER);
  
  this->collectPoints.clear();
  this->ui_collectWidget->listWidget->clear();
  
  QStringList allCollectPointsCfgFiles = dir.entryList(QStringList("*.cfg"),QDir::Files,QDir::Name);
  
  for(int i=0; i<allCollectPointsCfgFiles.size();i++){
    CollectPoints *collectPoints = collectPointsManager.getCollectPoint(dir.absoluteFilePath(allCollectPointsCfgFiles[i]));
    if(collectPoints != NULL){
      this->collectPoints.append(collectPoints);
      parent->connect(collectPoints,SIGNAL(dateUpdated()),this,SLOT(updateDates()));
    }
  }
  
  for(int i=0; i<this->collectPoints.size();i++){
    QListWidgetItem *collectItem = new QListWidgetItem(this->ui_collectWidget->listWidget);
    collectItem->setText(this->collectPoints[i]->getName()+QString::fromUtf8(" - Última coleta em :  ") + this->collectPoints[i]->getLastCollected().toString("dd-MM-yyyy"));
    collectItem->setData(Qt::UserRole,this->collectPoints[i]->getCfgFilePath());
  }
}

void WidgetCollectHandler::updateDates(){
  this->ui_collectWidget->listWidget->clear();
  for(int i=0; i<this->collectPoints.size();i++){
    QListWidgetItem *collectItem = new QListWidgetItem(this->ui_collectWidget->listWidget);
    collectItem->setText(this->collectPoints[i]->getName()+QString::fromUtf8(" - Última coleta em :  ") + this->collectPoints[i]->getLastCollected().toString("dd-MM-yyyy"));
    collectItem->setData(Qt::UserRole,this->collectPoints[i]->getCfgFilePath());
  }
}

void WidgetCollectHandler::startCollect(){
  QListWidgetItem *item = this->ui_collectWidget->listWidget->currentItem();
  if(item != NULL)
    for(int i=0; i<this->collectPoints.size();i++){
      if(this->collectPoints[i]->getCfgFilePath() == item->data(Qt::UserRole))
        emit(startCollect(this->collectPoints[i]));
    }
}


#include "WidgetCollectHandler.moc"
