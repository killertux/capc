#include "Message.hpp"

Message::Message(){
  this->message = "";
  this->myStatus = M_NULL;
  this->setColor();
}

Message::Message(QString message){
  this->message = message;
  this->myStatus = M_NULL;
  this->setColor();
}


Message::Message(QString message, MessageStatus status){
  this->message = message;
  this->myStatus = status;
  this->setColor();
}

void Message::setColor(){
  switch(this->myStatus){
    case M_OK:
      this->color.setRgb(204, 255, 255);
      break;
    case M_FIELD_MISSING:
      this->color.setRgb(255, 255, 153);
      break;
    case M_FILE_MISSING:
      this->color.setRgb(255, 102, 102);
      break;
    default:    //M_NULL
      this->color.setRgb(234, 234, 234);
  }
}

