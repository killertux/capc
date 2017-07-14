#ifndef CONFIGURATION_HPP
#define CONFIGURATION_HPP

#include <QFile>
#include <QFileInfo>
#include <QDir>
#include <QTextStream>
#include <QMap>

class Configuration{
private:
  QString path;
  QString name;
  QFile *file;
  QMap <QString, QString>settings;
public:
  Configuration(QString path, QString name);
  Configuration(QString filePath);
  virtual ~Configuration();
  
  QString getSetting(QString key);
  void setSetting(QString key, QString value);
  void save();
};

#endif