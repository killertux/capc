#ifndef OAI_HPP
#define OAI_HPP

#include <QMap>
#include <QDir>
#include <QFileInfo>
#include <QNetworkAccessManager>
#include <QTemporaryFile>
#include <QUrl>
#include <QBuffer>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QDateTime>
#include <QEventLoop>
#include <QVector>
#include "../XML/XML.hpp"
#include "../Configuration/Configuration.hpp"
#include "../Article/ArticleDAO.hpp"
#include "../Article/Article.hpp"
#include "../CollectPoints/CollectPoints.hpp"
#include "../Article/Article.hpp"
#include "../Message/Message.hpp"

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
  QString resumptionToken;
  QMap<QString, QString> settings;
  Configuration *config;
  CurrentState state;
  QByteArray *buffer;
  QEventLoop loop;
  QNetworkAccessManager *manager;
  ArticleDAO *articleDAO;
  QVector<Article*> articles;
  int nCollected;
  
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
  int collect(Article ***articles, QDate startDate, QDate endDate, QObject *parent);
  
  void setName(QString name){this->name = name;}
  void setCfgFilePath(QString cfgFilePath){this->cfgFilePath = cfgFilePath;}
  void setSetting(QString key, QString setting);
  
  QString getName(){return this->name;}
  QString getCfgFilePath(){return this->cfgFilePath;}
  QString getSetting(QString key);
  QDate getLastCollected();

private slots:
  void slotError(QNetworkReply::NetworkError);
  void xmlProcessor(XMLNode *node);
public slots:
  void fileReady(QNetworkReply *reply);
  
signals:
  void dateUpdated();
  void returnFile();
  void sendMessage(Message newMessage);
};

#endif