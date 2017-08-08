#ifndef ARTICLEDAO_HPP
#define ARTICLEDAO_HPP

#include "Article.hpp"
#include "Field.hpp"
#include <QMap>
#include <QFile>
#include <QObject>
#include "../XML/XML.hpp"

class ArticleDAO: public QObject{
private:
  Q_OBJECT
  QMap<QString, Field*> possibleFields;
  Article *article;
private slots:
  void processXml(XMLNode*);
public:
  ArticleDAO(QString xmlDefinition, QObject *parent);
  Article *getArticleFromXML(XMLNode *node);
  Article *getArticleFromXML(QString xml);
public slots:
  void processXmlDefinition(XMLNode *node);
};

#endif