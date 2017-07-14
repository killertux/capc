#ifndef MESSAGE_HPP
#define MESSAGE_HPP

#include <QString>
#include <QColor>

enum MessageStatus{
  M_OK = 0,
  M_FIELD_MISSING,
  M_FILE_MISSING,
  M_NULL
};

class Message{
private:
  QString message;
  QColor color;
  MessageStatus myStatus;
  void setColor();
public:
  Message();
  Message(QString message);
  Message(QString message, MessageStatus status);
  
  void setMessage(QString message){this->message = message;}
  void setMessageStatus(MessageStatus status){this->myStatus = status; this->setColor();}
  
  QString getMessage(){return this->message;}
  QColor getColor(){return this->color;}
};

#endif