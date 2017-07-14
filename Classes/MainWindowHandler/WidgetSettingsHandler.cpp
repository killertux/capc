#include "WidgetSettingsHandler.hpp"

WidgetSettingsHandler::WidgetSettingsHandler(QWidget* parent, CollectTypes **listCollectTypes): Handler(parent){
  this->listCollectTypes = listCollectTypes;
  this->ui_widgetSettings = new Ui_widgetSettings();
  this->ui_widgetSettings->setupUi(parent);
  this->ui_widgetSettings->retranslateUi(parent);
  this->config = new Configuration(CONFIG_FOLDER,"capc.cfg");
  
  for(int i=0;i<N_OF_COLLECT_TYPES;i++)
    this->ui_widgetSettings->comboBoxSelectTypeOfCollect->addItem(this->listCollectTypes[i]->getName());
  
  this->ui_widgetSettings->kurlrequesterXmlMeta->setUrl(this->config->getSetting("article_description"));

  //Handle connects
  parent->connect(this->ui_widgetSettings->pushButtonAddCollectPoint,SIGNAL(clicked()),this,SLOT(addNewCollectPoint()));
  parent->connect(this->ui_widgetSettings->pushButtonSave,SIGNAL(clicked()),this,SLOT(save()));
}

WidgetSettingsHandler::~WidgetSettingsHandler(){
  delete this->ui_widgetSettings;
  delete this->config;
}

void WidgetSettingsHandler::addNewCollectPoint(){
  //TODO : Fix memory leak of addNewCollectPointWindow
  QMainWindow *addNewCollectPointWindow = new QMainWindow();
  Handler *addNewCollectPointHandler = this->listCollectTypes[this->ui_widgetSettings->comboBoxSelectTypeOfCollect->currentIndex()]->getSettingsHandler(addNewCollectPointWindow);
  addNewCollectPointWindow->show();
}

void WidgetSettingsHandler::save(){
  QFile::copy(this->ui_widgetSettings->kurlrequesterXmlMeta->text(),QDir(CONFIG_FOLDER).absoluteFilePath(QFileInfo(this->ui_widgetSettings->kurlrequesterXmlMeta->text()).fileName()));
  this->config->setSetting("article_description",QDir(CONFIG_FOLDER).absoluteFilePath(QFileInfo(this->ui_widgetSettings->kurlrequesterXmlMeta->text()).fileName()));
  this->config->save();
  QMessageBox::information((QWidget*)this->parent, "Sucesso", QString::fromUtf8("Alterações salvas com sucesso!"));
}



#include "WidgetSettingsHandler.moc"