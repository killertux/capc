#include "OAIType.hpp"

OAIType::OAIType(){
  this->name = "OAI-PMH";
}

OAIType::~OAIType(){
  delete this->myOAISettingsHandler;
}

Handler* OAIType::getSettingsHandler(QMainWindow* parent){
  this->myOAISettingsHandler = new OAISettingsHandler(parent);
  return this->myOAISettingsHandler;
}
