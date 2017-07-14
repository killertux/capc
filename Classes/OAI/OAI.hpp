#ifndef OAI_HPP
#define OAI_HPP

#include <QMap>
#include <QDir>
#include <QFileInfo>
#include <QNetworkAccessManager>
#include <QTemporaryFile>
#include <QUrl>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QtXml>
#include <QDateTime>
#include <QXmlResultItems>
#include <QXmlNodeModelIndex>
#include <QXmlQuery>
#include <QEventLoop>
#include "../Configuration/Configuration.hpp"

#include "../CollectPoints/CollectPoints.hpp"
#include "../Article/Article.hpp"

enum CurrentState{
  OAI_NONE = 0,
  OAI_IDENTIFY,
  OAI_LIST_RECORDS
};

class OAI : public CollectPoints{
private:
  Q_OBJECT
  QString name;
  QString cfgFilePath;
  QMap<QString, QString> settings;
  Configuration *config;
  CurrentState state;
  QBuffer *file;
  QEventLoop loop;
  
  void getFirstDate();
  QString guessGranularity(QString granularity);
  QUrl prepareOaiVerb(QString verb, QMap<QString,QString> *parameters = NULL);
public:
  OAI();
  OAI(QString cfgFilePath);
  ~OAI();
  
  void load();
  void load(QString cfgFilePath);
  void save();
  int collect(Article **articles, QDate startDate, QDate endDate);
  
  void setName(QString name){this->name = name;}
  void setCfgFilePath(QString cfgFilePath){this->cfgFilePath = cfgFilePath;}
  void setSetting(QString key, QString setting);
  
  QString getName(){return this->name;}
  QString getCfgFilePath(){return this->cfgFilePath;}
  QString getSetting(QString key);
  QDate getLastCollected();

private slots:
  
public slots:
  void fileReady(QNetworkReply *reply);
  
signals:
  void dateUpdated();
  void returnFile();
};

#endif