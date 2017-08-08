#include "XML.hpp"

#include <string.h>

QStack<XMLNode*> XML::nodes;

XML::XML(QIODevice* file, QObject* parent): QObject(parent){
  this->file = file;
  this->p = XML_ParserCreate(NULL);
  XML_SetElementHandler(this->p, startNode, endNode);
  XML_SetCharacterDataHandler(this->p, characterNode);
  XML_SetUserData(this->p, this);
}

XML::~XML(){
  XML_ParserFree(this->p);
}

void XML::parse(){
  char buffer[255];
  int n;
  while( (n= this->file->readLine(buffer, 255))>=0){
    XML_Parse(this->p, buffer, n, this->file->atEnd());
  }
}

void XML::startNode(void* data, const char* el, const char** attr){
  XMLNode *node = new XMLNode();
  node->setName(el);
  for(int i = 0; attr[i]; i += 2)
    node->addAttr(attr[i],   QString::fromUtf8(attr[i+1]));
  if(!XML::nodes.isEmpty()){
    XMLNode *parent = XML::nodes.top();
    parent->addChild(node);
  }
  XML::nodes.push(node);
}

void XML::endNode(void* data, const char* el){
  XMLNode *node = XML::nodes.top();
  XML::nodes.pop();
  emit(((XML*)data)->nodeCompleted(node));
}

void XML::characterNode(void* data, const char* value, int len){
  XMLNode *node = XML::nodes.top();
  char *buffer = new char[len+1];
  memcpy(buffer, value, len);
  buffer[len] = '\0';
  node->setValue(node->getValue().append(QString::fromUtf8(buffer)));
}

#include "XML.moc"