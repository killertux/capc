#ifndef XML_HPP
#define XML_HPP

#include <QIODevice>
#include <QObject>
#include <QStack>
#include <expat.h>
#include "XMLNode.hpp"

class XML : public QObject{
private:
  Q_OBJECT
  static void XMLCALL startNode(void *data, const char *el, const char **attr);
  static void XMLCALL endNode(void *data, const char *el);
  static void XMLCALL characterNode(void *data, const char *value, int len);
  static QStack<XMLNode*> nodes;
  
  QIODevice *file;
  XML_Parser p;
public:
  XML(QIODevice *file, QObject *parent);
  virtual ~XML();
  void parse();
signals:
  void nodeCompleted(XMLNode *node);
};

#endif