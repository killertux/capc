#ifndef OAI_HPP
#define OAI_HPP

#include "../CollectTypes/CollectTypes.hpp"
#include "OAISettingsHandler.hpp"

class OAI : public CollectTypes{
private:
  QString name;
  OAISettingsHandler *myOAISettingsHandler;
public:
  OAI();
  virtual ~OAI();
  
  QString getName(){return this->name;}
  Handler *getSettingsHandler(QMainWindow *parent);
};

#endif