#include "MainWindowHandler.hpp"

MainWindowHandler::MainWindowHandler(QMainWindow* parent, WidgetIndex startWidget, CollectTypes** listCollectTypes): Handler(parent){
  this->collectWidget = new QWidget(parent);
  this->visualizeWidget = new QWidget(parent);
  this->settingsWidget = new QWidget(parent);
  
  this->ui_MainWindow = new Ui_MainWindow();
  this->ui_MainWindow->setupUi(parent);
  this->ui_MainWindow->retranslateUi(parent);
  
  this->widgetSettingsHandler = new WidgetSettingsHandler(this->settingsWidget, listCollectTypes);

  this->ui_MainWindow->tabWidget->addTab(this->collectWidget, "Realizar Coleta");
  this->ui_MainWindow->tabWidget->addTab(this->visualizeWidget, "Visualizar Coletas");
  this->ui_MainWindow->tabWidget->addTab(this->settingsWidget, QString::fromUtf8("Configurações"));
  this->ui_MainWindow->tabWidget->setCurrentIndex((int)startWidget);
}

MainWindowHandler::~MainWindowHandler(){
  delete this->ui_MainWindow;
  
  delete this->collectWidget;
  delete this->visualizeWidget;
  delete settingsWidget;
}

#include "MainWindowHandler.moc"