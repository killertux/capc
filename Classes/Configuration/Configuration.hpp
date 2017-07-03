#ifndef CONFIGURATION_HPP
#define CONFIGURATION_HPP

#include <QFile>
#include <QDir>
#include <QTextStream>
#include <QMap>

#include <iostream>

class Configuration{
private:
  QString path;
  QString name;
  QFile *file;
  QMap <QString, QString>settings;
public:
  Configuration(QString path, QString name);
  virtual ~Configuration();
  
  QString getSetting(QString key);
  void setSetting(QString key, QString value);
  void save();
};

#endif