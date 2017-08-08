#ifndef ARTICLE_HPP
#define ARTICLE_HPP

#include <QVector>
#include <QStringList>
#include "../Message/Message.hpp"
#include "Field.hpp"

class Article{
private:
  QVector<Field*> fields;
  QVector<Field*> possibleFields;
  QString note;
  QVector<QString> files;
public:
  void addField(Field *field){this->fields.append(field);}
  Field *getField(QString reference);
  Field *getMainField();
  QString toXml();
  
  QString getNote(){return this->note;}
  void setNote(QString note){this->note = note;}
  Message getMessage();
  
  void addFile(QString file){this->files.append(file);}
  int getNFiles(){return this->files.size();}
  
  void setPossibleFields(QVector<Field*> possibleFields){this->possibleFields = possibleFields;}
};

#endif