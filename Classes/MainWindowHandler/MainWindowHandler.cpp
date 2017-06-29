#include "MainWindowHandler.hpp"

MainWindowHandler::MainWindowHandler(QMainWindow* parent, WidgetIndex startWidget, CollectTypes** listCollectTypes): QObject(parent){
  this->listCollectTypes = listCollectTypes;
  
  this->collectWidget = new QWidget(parent);
  this->visualizeWidget = new QWidget(parent);
  this->settingsWidget = new QWidget(parent);
  
  this->ui_MainWindow = new Ui_MainWindow();
  this->ui_MainWindow->setupUi(parent);
  this->ui_MainWindow->retranslateUi(parent);
  
  this->ui_widgetSetings = new Ui_widgetSettings();
  this->ui_widgetSetings->setupUi(this->settingsWidget);
  this->ui_widgetSetings->retranslateUi(this->settingsWidget);

  this->ui_MainWindow->tabWidget->addTab(this->collectWidget, "Realizar Coleta");
  this->ui_MainWindow->tabWidget->addTab(this->visualizeWidget, "Visualizar Coletas");
  this->ui_MainWindow->tabWidget->addTab(this->settingsWidget, QString::fromUtf8("Configurações"));
  this->ui_MainWindow->tabWidget->setCurrentIndex((int)startWidget);
  
  for(int i=0;i<N_OF_COLLECT_TYPES;i++)
    this->ui_widgetSetings->comboBoxSelectTypeOfCollect->addItem(this->listCollectTypes[i]->getName());
}

MainWindowHandler::~MainWindowHandler(){
  delete this->ui_MainWindow;
  delete this->ui_widgetSetings;
  
  delete this->collectWidget;
  delete this->visualizeWidget;
  delete settingsWidget;
}

#include "MainWindowHandler.moc"