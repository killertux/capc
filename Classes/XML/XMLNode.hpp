#ifndef XMLNODE_HPP
#define XMLNODE_HPP

#include <QString>
#include <QVector>
#include <QMap>

class XMLNode{
private:
  QString name;
  QString value;
  QMap<QString, QString> attrs;
  QVector<XMLNode *> children;
public:
  void setName(QString name){this->name = name;}
  void setValue(QString value){this->value = value;}
  void addAttr(QString attr_name, QString attr_value){this->attrs.insert(attr_name, attr_value);}
  void addChild(XMLNode *child){this->children.append(child);}
  
  QString getName(){return this->name;}
  QString getValue(){return this->value;}
  QString getAttr(QString attr_name){return this->attrs[attr_name];}
  
  QVector<XMLNode *> getChildren(){return this->children;}
};

#endif