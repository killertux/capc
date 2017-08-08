#include "Field.hpp"

Field::Field(){
  this->type = "input";
  this->repetitive = false;
  this->main = false;
  this->hidden = false;
  this->filter = false;
}

Field::~Field(){}

void Field::processNode(XMLNode* node){
  if(node->getName() == "field"){
    this->compare = node->getAttr("compare");
    this->type = node->getAttr("type");
    this->repetitive = (node->getAttr("repetitive") == "true")?true:false;
    this->main = (node->getAttr("main") == "true")?true:false;
    this->repetitive = (node->getAttr("repetitive") == "true")?true:false;
    this->hidden = (node->getAttr("hidden") == "true")?true:false;
    this->filter = (node->getAttr("filter") == "true")?true:false;
    for(auto &x: node->getChildren()){
      if(x->getName() == "dc"){
        this->dcElement = x->getAttr("element");
        this->dcQualifier = x->getAttr("qualifier");
      } else if(x->getName() == "label"){
        this->label = x->getValue();
      } else if(x->getName() == "reference"){
        this->reference = x->getValue();
      } else if(x->getName() == "value"){
        this->values.append(x->getValue());
      } else if(x->getName() == "options"){
        for(auto &y: x->getChildren()){
          this->addOption(y->getValue());
        }
      }
    }
  }
}
