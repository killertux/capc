#include "WidgetCollectPointHandler.hpp"
#include <iostream>

WidgetCollectPointHandler::WidgetCollectPointHandler(QWidget* parent, CollectPoints *collectPoint): Handler(parent){
  this->ui_collectPointWidget = new Ui_collectPointWidget();
  this->ui_collectPointWidget->setupUi(parent);
  this->ui_collectPointWidget->retranslateUi(parent);
  this->collectPoint = collectPoint;
  
  this->ui_collectPointWidget->dateEditStartDate->setDate(collectPoint->getLastCollected());
  this->ui_collectPointWidget->dateEditEndDate->setDate(QDate::currentDate());
  this->ui_collectPointWidget->textEdit->setLineWrapMode(QTextEdit::NoWrap);
  
  
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
  this->ui_collectPointWidget->textEdit->append(newMessage.getMessage());
}

void WidgetCollectPointHandler::collect(){
  QDir dir(COLLECT_DATA_FOLDER);
  this->ui_collectPointWidget->pushButtonStartCollect->setDisabled(true);
  this->articles = NULL;
  int nCollected = this->collectPoint->collect(&this->articles, this->ui_collectPointWidget->dateEditStartDate->date(), this->ui_collectPointWidget->dateEditEndDate->date(), this);
  this->addMessage(QString::number(nCollected)+QString(" Artigos coletados"));
  this->ui_collectPointWidget->pushButtonStartCollect->setDisabled(false);
  if(!dir.exists())
    dir.mkpath(".");
  if(!dir.exists(this->collectPoint->getName()))
    dir.mkpath(this->collectPoint->getName());
  dir.cd(this->collectPoint->getName());
  dir.mkpath(QDateTime::currentDateTime().toString("hh-mm-dd-MM-yyyy"));
  dir.cd(QDateTime::currentDateTime().toString("hh-mm-dd-MM-yyyy"));
  this->addMessage(Message("Coletando PDFs..."));
  for(int i = 0;i < nCollected ;i++){
    dir.mkpath("Item_"+QString::number(i));
    dir.cd("Item_"+QString::number(i));
    QFile file(dir.absoluteFilePath("article.xml"));
    file.open(QIODevice::WriteOnly);
    file.write(articles[i]->toXml().toUtf8());
    file.close();
    QStringList parameters = this->collectPoint->getSetting("script_parameters").split(" ", QString::SkipEmptyParts);
    QString parameters_str;
    for (auto parameter : parameters){
      Field *field = articles[i]->getField(parameter);
      if (field != NULL)
        parameters_str += " "+field->getValue(0);
    }
    functions::exec(QFileInfo(this->collectPoint->getCfgFilePath()).dir().absoluteFilePath(this->collectPoint->getSetting("script")) + " " + dir.absolutePath() + parameters_str);
    dir.cdUp();
  }
  this->addMessage(Message("Coleta Terminada!"));
}


#include "WidgetCollectPointHandler.moc"