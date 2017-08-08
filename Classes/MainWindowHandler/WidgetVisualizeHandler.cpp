#include "WidgetVisualizeHandler.hpp"

#include <iostream>

WidgetVisualizeHandler::WidgetVisualizeHandler(QWidget* parent): Handler(parent){
  this->ui_visualizeWidget = new Ui_visualizeWidget();
  this->ui_visualizeWidget->setupUi(parent);
  this->ui_visualizeWidget->retranslateUi(parent);
  updateList();
  this->connect(this->ui_visualizeWidget->pushButton, SIGNAL(clicked()), this, SLOT(openCollect()));
}

void WidgetVisualizeHandler::updateList(){
  QDir dir(COLLECT_DATA_FOLDER);
  QStringList points = dir.entryList(QDir::Dirs| QDir::NoDotAndDotDot, QDir::Name);
  for(auto p: points){
    QDir dirP(dir);
    dirP.cd(p);
    QStringList dates = dirP.entryList(QDir::Dirs | QDir::NoDotAndDotDot, QDir::Time | QDir::Reversed);
    for(auto d: dates){
      QDir dirD(dirP);
      dirD.cd(d);
      Collect *collect = new Collect(p, dirD.absolutePath());
      this->collects.append(collect);
    }
  }
  
  for(int i=0; i<this->collects.size();i++){
    QListWidgetItem *collect = new QListWidgetItem(this->ui_visualizeWidget->listWidgetCollects);
    
    collect->setText(QString(QString::fromUtf8("%1 | Data da Coleta: %2 | Número de artigos: %3")).arg(this->collects[i]->getName(), -20).arg(this->collects[i]->getDate().toString(Qt::ISODate), -30).arg(QString::number(this->collects[i]->getNArticles())));
    collect->setData(Qt::UserRole, i);
  }
}


WidgetVisualizeHandler::~WidgetVisualizeHandler(){}

void WidgetVisualizeHandler::openCollect(){
  QListWidgetItem *item = this->ui_visualizeWidget->listWidgetCollects->currentItem();
  if(item != NULL)
    emit(listItems(this->collects[item->data(Qt::UserRole).toInt()]));
}


#include "WidgetVisualizeHandler.moc"