#ifndef COLLECT_HPP
#define COLLECT_HPP

#include <QString>
#include <QStringList>
#include <QDir>
#include <QDateTime>

#include "../Article/Article.hpp"
#include "../Article/ArticleDAO.hpp"
#include "../../Defines.hpp"

class Collect{
private:
  QString path;
  QString name;
  QDateTime date;
  ArticleDAO *articleDao;
  QVector<Article *> articles;
public:
  Collect(QString name, QString path);
  
  QString getName(){return this->name;}
  QDateTime getDate(){return this->date;}
  int getNArticles(){return this->articles.size();}
  QVector<Article *> getArticles(){return this->articles;}
  Article * getArticle(int index){return this->articles[index];}
  virtual ~Collect();
};

#endif