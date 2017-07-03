#include "StartWindowHandler.hpp"

StartWindowHandler::StartWindowHandler(QMainWindow *parent): Handler(parent){
  //Let's create the window and execute its functions
  this->ui_StartWindow = new Ui_StartWindow();
  this->ui_StartWindow->setupUi(parent);
  this->ui_StartWindow->retranslateUi(parent);
  
  //Lets connect our catches
  parent->connect(this->ui_StartWindow->pushButtonCollect,SIGNAL(clicked()),this,SLOT(catchPushButtonCollect()));
  parent->connect(this->ui_StartWindow->pushButtonVisualize,SIGNAL(clicked()),this,SLOT(catchPushButtonVisualize()));
  parent->connect(this->ui_StartWindow->pushButtonSettings,SIGNAL(clicked()),this,SLOT(catchPushButtonSettings()));
  
  //Lets connect our emits
  parent->connect(this,SIGNAL(chooseMainWidget(WidgetIndex)),parent,SLOT(openMainWindow(WidgetIndex)));

}

StartWindowHandler::~StartWindowHandler(){
  delete this->ui_StartWindow;
}

void StartWindowHandler::catchPushButtonCollect(){
  emit chooseMainWidget(CAPC_COLLECT);
}

void StartWindowHandler::catchPushButtonVisualize(){
  emit chooseMainWidget(CAPC_VISUALIZE);
}

void StartWindowHandler::catchPushButtonSettings(){
  emit chooseMainWidget(CAPC_SETTINGS);
}
#include "StartWindowHandler.moc"