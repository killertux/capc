#ifndef OAITYPE_HPP
#define OAITYPE_HPP

#include "../CollectTypes/CollectTypes.hpp"
#include "OAISettingsHandler.hpp"

class OAIType : public CollectTypes{
private:
  QString name;
  OAISettingsHandler *myOAISettingsHandler;
public:
  OAIType();
  virtual ~OAIType();
  
  QString getName(){return this->name;}
  Handler *getSettingsHandler(QMainWindow *parent);
};

#endif