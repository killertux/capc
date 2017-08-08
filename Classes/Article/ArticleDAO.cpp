#include "ArticleDAO.hpp"
#include <iostream>

ArticleDAO::ArticleDAO(QString xmlDefinition, QObject *parent): QObject(parent){
  QFile file(xmlDefinition);
  
  file.open(QIODevice::ReadOnly);
  XML parser(&file, this);
  this->connect(&parser, SIGNAL(nodeCompleted(XMLNode*)), this, SLOT(processXmlDefinition(XMLNode*)));
  parser.parse();
  this->disconnect(&parser, SIGNAL(nodeCompleted(XMLNode*)), this, SLOT(processXmlDefinition(XMLNode*)));
  
  file.close();

}

Article* ArticleDAO::getArticleFromXML(XMLNode* node){
  bool passed = true;
  if(node->getName() == "capc-article"){
    Article *newArticle = new Article;
    for(auto &x: node->getChildren()){
      if(x->getName() == "field"){
        Field *newField = new Field;
        //Field *articleField;
        newField->processNode(x);
        if(this->possibleFields.contains(newField->getReference())){
          *newField = *this->possibleFields[newField->getReference()];
          if(newField->getFilter()){
            passed = false;
            if(newField->getCompare() == "contains"){
              for(auto &possibilites: newField->getOptions()){
                if(newField->getValue(0).contains(possibilites, Qt::CaseInsensitive)){
                  passed = true;
                  break;
                }
              }
            }
          }
          newArticle->addField(newField);
        }
      }
    }
    if(!passed){
      delete newArticle;
      return NULL;
    }
    return newArticle;
  }
  return NULL;
}

Article* ArticleDAO::getArticleFromXML(QString xml){
  QFile file(xml);
  file.open(QIODevice::ReadOnly);
  XML parser(&file, this);
  this->connect(&parser, SIGNAL(nodeCompleted(XMLNode*)), this, SLOT(processXml(XMLNode*)));
  parser.parse();
  this->disconnect(&parser, SIGNAL(nodeCompleted(XMLNode*)), this, SLOT(processXml(XMLNode*)));
  file.close();
  return this->article;
}

void ArticleDAO::processXml(XMLNode *node){
  if(node->getName() == "capc-article"){
    Article *newArticle = new Article;
    QVector<Field *> pFields;
    for(auto &p: this->possibleFields){
      pFields.append(p);
    }
    newArticle->setPossibleFields(pFields);
    for(auto &c: node->getChildren()){
      if(c->getName() == "field"){
        Field *newField = new Field;
        newField->processNode(c);
        *newField = *this->possibleFields[newField->getReference()];
        newArticle->addField(newField);
      }
    }
    this->article = newArticle;
  }
}


void ArticleDAO::processXmlDefinition(XMLNode* node){
  if(node->getName() == "field"){
    Field *field = new Field;
    field->processNode(node);
    this->possibleFields.insert(field->getReference(),field);
  }
}



#include "ArticleDAO.moc"