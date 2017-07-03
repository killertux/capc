#include "OAI.hpp"

OAI::OAI(){
  this->name = "OAI-PMH";
}

OAI::~OAI(){
  delete this->myOAISettingsHandler;
}

Handler* OAI::getSettingsHandler(QMainWindow* parent){
  this->myOAISettingsHandler = new OAISettingsHandler(parent);
  return this->myOAISettingsHandler;
}
