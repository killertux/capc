#include "Configuration.hpp"

Configuration::Configuration(QString path, QString name){
  this->path = path;
  this->name = name;
  QDir dir(this->path);
  
  if(!dir.exists()){
    if(!dir.mkpath(".")){}
      //TODO : Resolve Error
    this->file = new QFile(dir.filePath(this->name));
    if(!file->open(QIODevice::WriteOnly | QIODevice::Text)){}
      //TODO : Resolve Error
    file->flush();
    this->file->close();
  } else {
    this->file = new QFile(dir.filePath(this->name));
    if(!file->open(QIODevice::ReadOnly | QIODevice::Text)){}
      //TODO : Resolve Error
    QTextStream in(file);
    while(!in.atEnd()){
      QStringList line = in.readLine().split("=",QString::SkipEmptyParts);
      this->settings[line[0].trimmed()] = line[1].trimmed();
    }
    this->file->close();
  }
}

Configuration::Configuration(QString filePath){
  this->path = QFileInfo(filePath).absolutePath();
  this->name = QFileInfo(filePath).fileName();
  QDir dir(this->path);
  
  if(!dir.exists()){
    if(!dir.mkpath(".")){}
    //TODO : Resolve Error
    this->file = new QFile(dir.filePath(this->name));
    if(!file->open(QIODevice::WriteOnly | QIODevice::Text)){}
    //TODO : Resolve Error
    file->flush();
    this->file->close();
  } else {
    this->file = new QFile(dir.filePath(this->name));
    if(!file->open(QIODevice::ReadOnly | QIODevice::Text)){}
    //TODO : Resolve Error
    QTextStream in(file);
    while(!in.atEnd()){
      QStringList line = in.readLine().split("=",QString::SkipEmptyParts);
      this->settings[line[0].trimmed()] = line[1].trimmed();
    }
    this->file->close();
  }
}


Configuration::~Configuration(){
  //TODO : Save if not already done
  if(this->file->isOpen())
    this->file->close();
}

QString Configuration::getSetting(QString key){
  if(this->settings.contains(key))
    return this->settings[key];
  return QString("");
}

void Configuration::setSetting(QString key, QString value){
  this->settings[key] = value;
}


void Configuration::save(){
  QMap<QString, QString>::const_iterator i = this->settings.constBegin();
  QDir dir(this->path);
  this->file = new QFile(dir.filePath(this->name));
  if(!file->open(QIODevice::WriteOnly | QIODevice::Text)){}
    //TODO : Resolve Error
  QTextStream out(file);
  
  while(i != this->settings.constEnd()){
    out << i.key() << " = " << i.value() << "\n";
    i++;
  }
  out.flush();
  this->file->flush();
  this->file->close();
}


