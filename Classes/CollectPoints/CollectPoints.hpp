#ifndef COLLECTPOINTS_HPP
#define COLLECTPOINTS_HPP

#include <QString>
#include <QDate>
#include <QObject>
#include "../Article/Article.hpp"

class CollectPoints : public QObject {
public:
  virtual void load() = 0;
  virtual void load(QString cfgFilePath) = 0;
  virtual void save()= 0 ;
  virtual int collect(Article ***articles, QDate startDate, QDate endDate, QObject *parent) = 0;
  
  virtual void setName(QString name) = 0;
  virtual void setCfgFilePath(QString cfgFilePath) = 0;
  virtual void setSetting(QString key, QString setting) = 0;
  
  virtual QString getName() = 0;
  virtual QString getSetting(QString key) = 0;
  virtual QString getCfgFilePath() = 0;
  virtual QDate getLastCollected() = 0;
  
  virtual ~CollectPoints(){}
};

#endif