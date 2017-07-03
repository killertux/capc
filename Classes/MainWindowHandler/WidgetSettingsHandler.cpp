#include "WidgetSettingsHandler.hpp"

WidgetSettingsHandler::WidgetSettingsHandler(QWidget* parent, CollectTypes **listCollectTypes): Handler(parent){
  this->listCollectTypes = listCollectTypes;
  this->ui_widgetSettings = new Ui_widgetSettings();
  this->ui_widgetSettings->setupUi(parent);
  this->ui_widgetSettings->retranslateUi(parent);
  
  for(int i=0;i<N_OF_COLLECT_TYPES;i++)
    this->ui_widgetSettings->comboBoxSelectTypeOfCollect->addItem(this->listCollectTypes[i]->getName());

  //Handle connects
  parent->connect(this->ui_widgetSettings->pushButtonAddCollectPoint,SIGNAL(clicked()),this,SLOT(addNewCollectPoint()));
}

WidgetSettingsHandler::~WidgetSettingsHandler(){
  delete this->ui_widgetSettings;
}

void WidgetSettingsHandler::addNewCollectPoint(){
  //TODO : Fix memory leak of addNewCollectPointWindow
  QMainWindow *addNewCollectPointWindow = new QMainWindow();
  Handler *addNewCollectPointHandler = this->listCollectTypes[this->ui_widgetSettings->comboBoxSelectTypeOfCollect->currentIndex()]->getSettingsHandler(addNewCollectPointWindow);
  addNewCollectPointWindow->show();
}

#include "WidgetSettingsHandler.moc"