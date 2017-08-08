#include "MainWindowHandler.hpp"

MainWindowHandler::MainWindowHandler(QMainWindow* parent, WidgetIndex startWidget, CollectTypes** listCollectTypes): Handler(parent){
  this->collectWidget = new QWidget(parent);
  this->visualizeWidget = new QWidget(parent);
  QHBoxLayout *layout = new QHBoxLayout(this->visualizeWidget);
  this->visualizeWidgetContents = new QWidget(this->visualizeWidget);
  layout->addWidget(this->visualizeWidgetContents);
  this->settingsWidget = new QWidget(parent);
  
  this->ui_MainWindow = new Ui_MainWindow();
  this->ui_MainWindow->setupUi(parent);
  this->ui_MainWindow->retranslateUi(parent);
  
  this->widgetSettingsHandler = new WidgetSettingsHandler(this->settingsWidget, listCollectTypes);
  this->widgetCollectHandler = new WidgetCollectHandler(this->collectWidget);
  this->widgetVisualizeHandler = new WidgetVisualizeHandler(this->visualizeWidgetContents);

  this->ui_MainWindow->tabWidget->addTab(this->collectWidget, "Realizar Coleta");
  this->ui_MainWindow->tabWidget->addTab(this->visualizeWidget, "Visualizar Coletas");
  this->ui_MainWindow->tabWidget->addTab(this->settingsWidget, QString::fromUtf8("Configurações"));
  this->ui_MainWindow->tabWidget->setCurrentIndex((int)startWidget);
  
  //Connects
  this->parent->connect(this->ui_MainWindow->tabWidget,SIGNAL(currentChanged(int)),this,SLOT(update(int)));
  this->parent->connect(this->widgetCollectHandler,SIGNAL(startCollect(CollectPoints*)),this,SLOT(startCollect(CollectPoints*)));
  this->parent->connect(this->widgetVisualizeHandler, SIGNAL(listItems(Collect*)), this, SLOT(listItems(Collect*)));
}

MainWindowHandler::~MainWindowHandler(){
  delete this->ui_MainWindow;
  
  delete this->collectWidget;
  delete this->visualizeWidget;
  delete settingsWidget;
}

void MainWindowHandler::update(int index){
  if(index == CAPC_COLLECT){
    this->widgetCollectHandler->updateCollectList();
  }
}

void MainWindowHandler::startCollect(CollectPoints* collectPoint){
  QWidget *pointWidget = new QWidget();
  WidgetCollectPointHandler *handler = new WidgetCollectPointHandler(pointWidget,collectPoint);
  this->parent->connect(handler,SIGNAL(deleteThis()),this,SLOT(stopCollect()));
  this->collectPointsHandler.append(handler);
  this->collectPointsWidgets.append(pointWidget);
  this->ui_MainWindow->tabWidget->setCurrentIndex(this->ui_MainWindow->tabWidget->addTab(pointWidget,collectPoint->getName()));
}

void MainWindowHandler::stopCollect(){
  QWidget *current = this->ui_MainWindow->tabWidget->currentWidget();
  current->close();
  this->ui_MainWindow->tabWidget->removeTab(this->ui_MainWindow->tabWidget->currentIndex());
}

void MainWindowHandler::listItems(Collect* collect){
  QLayout *layout = this->visualizeWidget->layout();
  delete this->visualizeWidgetContents;
  this->visualizeWidgetContents = new QWidget(this->visualizeWidget);
  layout->addWidget(this->visualizeWidgetContents);
  this->widgetListItemsHandler = new WidgetListItemsHandler(this->visualizeWidgetContents, collect);
}


#include "MainWindowHandler.moc"