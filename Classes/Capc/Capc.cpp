#include "Capc.hpp"

Capc::Capc(){
  this->startWindowHandler = new StartWindowHandler(this);
  
  this->listCollectTypes[0] = new OAIType();
}

Capc::~Capc(){
  delete this->startWindowHandler;
  delete this->mainWindowHandler;
  
  for(int i=0;i<N_OF_COLLECT_TYPES;i++)
    delete this->listCollectTypes[i];
}

void Capc::openMainWindow(WidgetIndex startWidget){
  delete this->startWindowHandler;
  this->startWindowHandler = NULL;
  this->mainWindowHandler = new MainWindowHandler(this,startWidget,this->listCollectTypes);
}


#include "Capc.moc"