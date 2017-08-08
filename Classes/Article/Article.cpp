#include "Article.hpp"

Field *Article::getMainField(){
  if(!this->fields.isEmpty())
    for(auto x: this->fields)
      if(x->getMain())
        return x;
  return NULL;
}

QString Article::toXml(){
  QString ret = "<cacp-article>\n";
  
  for(auto &field: this->fields){
    ret += "\t<field>\n";
    ret += "\t\t<reference>" + field->getReference() + "</reference>\n";
    for(int i = 0; i < field->getValueSize(); i++)
      ret += "\t\t<value>" + field->getValue(i) + "</value>\n";
    ret += "\t</field>\n";
  }
  ret += "</cacp-article>\n";
  return ret;
}

Field* Article::getField(QString reference){
  for(auto &field: this->fields){
    if(field->getReference() == reference)
      return field;
  }
  return NULL;
}

Message Article::getMessage(){
  Message msg;
  msg.setMessage(this->getMainField()->getValue(0) + "\n Notas:" + this->note);
  if(this->getNFiles() == 0){
    msg.setMessageStatus(M_FILE_MISSING);
    return msg;
  }
  for(auto &p: this->possibleFields){
    if(!p->getHidden()){
      bool found =false;
      for(auto &f: this->fields){
        if(f->getReference() == p->getReference()){
          found = true;
          break;
        }
      }
      if(!found){
        msg.setMessageStatus(M_FIELD_MISSING);
        return msg;
      }
    }
  }
  return msg;
}
