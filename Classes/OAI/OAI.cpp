#include "OAI.hpp"
#include <iostream>

OAI::OAI(){
  this->config = NULL;
  this->state = OAI_NONE;
  this->file = NULL;
}

OAI::OAI(QString cfgFilePath){
  this->cfgFilePath = cfgFilePath;
  this->config = new Configuration(QFileInfo(this->cfgFilePath).dir().absolutePath(),QFileInfo(this->cfgFilePath).fileName());
  this->name = this->config->getSetting("name");
  this->state = OAI_NONE;
  this->file = NULL;
  if(this->config->getSetting("last_collected_date").isEmpty())
    this->getFirstDate();
}

OAI::~OAI(){
  this->loop.exit(-1);
  delete this->config;
}

void OAI::load(){
  if(this->config != NULL)
    delete this->config;
  this->config = new Configuration(QDir(this->cfgFilePath).absolutePath(),QFileInfo(this->cfgFilePath).fileName());
  this->name = this->config->getSetting("name");
  if(this->config->getSetting("last_collected_date").isEmpty())
    this->getFirstDate();
}

void OAI::load(QString cfgFilePath){
  if(this->config != NULL)
    delete this->config;
  this->config = new Configuration(QDir(cfgFilePath).absolutePath(),QFileInfo(cfgFilePath).fileName());
  this->name = this->config->getSetting("name");
  if(this->config->getSetting("last_collected_date").isEmpty())
    this->getFirstDate();
}

void OAI::save(){
  this->config->save();
}

void OAI::setSetting(QString key, QString setting){
  this->config->setSetting(key, setting);
  if(key == "name")
    this->name = setting;
}

QString OAI::getSetting(QString key){
  return this->config->getSetting(key);
}

QDate OAI::getLastCollected(){
  return QDate::fromString(this->getSetting("last_collected_date"),"yyyy-MM-dd");
}

void OAI::getFirstDate(){
  QNetworkAccessManager *manager = new QNetworkAccessManager(this);
  this->connect(manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(fileReady(QNetworkReply*)));
  this->state = OAI_IDENTIFY;
  manager->get(QNetworkRequest(this->prepareOaiVerb("Identify")));
}

QUrl OAI::prepareOaiVerb(QString verb, QMap<QString,QString> *parameters){
  QString url = this->getSetting("oai_address")+"?verb="+verb;
  if(parameters != NULL)
    for(auto parameter : parameters->keys())
      url +="&"+ parameter + "=" + parameters->value(parameter);
  return QUrl(url);
}


void OAI::fileReady(QNetworkReply* reply){
  if(this->state == OAI_IDENTIFY){
    QByteArray buffer = reply->readAll();
    QBuffer file(&buffer);
    QXmlQuery query;
    QXmlResultItems result;
    QString strQuery = "declare namespace oai = 'http://www.openarchives.org/OAI/2.0/'; let $document := doc($file)//oai:OAI-PMH/oai:Identify return ($document/oai:granularity/string(), $document/oai:earliestDatestamp/string())";
  
    file.open(QIODevice::ReadOnly);
    
    query.bindVariable("file", &file);
    query.setQuery(strQuery);
    query.evaluateTo(&result);
    
    QXmlItem granularity(result.next());
    QXmlItem earliestDate(result.next());
    QDateTime dateTime = QDateTime::fromString(earliestDate.toAtomicValue().toString(),Qt::ISODate);
    this->setSetting("last_collected_date",dateTime.toString("yyyy-MM-dd"));
    this->setSetting("granularity",this->guessGranularity(granularity.toAtomicValue().toString()));
    this->config->save();
    emit(dateUpdated());
    return;
  }
  if(this->state == OAI_LIST_RECORDS){
    QByteArray buffer = reply->readAll();
    this->file = new QBuffer(&buffer);
    this->file->open(QIODevice::ReadOnly);
    emit(returnFile());
    return;
  }
}

QString OAI::guessGranularity(QString granularity){
  QStringList dateParts = granularity.split("-",QString::SkipEmptyParts);
  QStringList time;
  QString guessedGranularity = "";
  
  if(dateParts.size() > 0){
    dateParts[0] = dateParts[0].toLower();
    guessedGranularity += dateParts[0]; 
  }
  
  if(dateParts.size() > 1){
    dateParts[1] = dateParts[1].toUpper();
    guessedGranularity += "-"+dateParts[1]; 
  }
  
  if(dateParts.size()>2){
    time = dateParts[2].split("T",QString::SkipEmptyParts);
    if(time.size()>1)
      dateParts[2] = time[0];
    dateParts[2] = dateParts[2].toLower();
    guessedGranularity += "-"+ dateParts[2];
    
  }
  
  if(time.size()>1){
    bool containsZ = false;
    QStringList timeParts = time[1].split(":");
    
    if(timeParts.size()>0){
      if(timeParts[0].contains('z',Qt::CaseInsensitive)){
        containsZ = true;
        timeParts[0].chop(1);
      }
      timeParts[0] = timeParts[0].toLower();
      guessedGranularity +="T"+timeParts[0];
    }
    if(timeParts.size()>1){
      if(timeParts[1].contains('z',Qt::CaseInsensitive)){
        containsZ = true;
        timeParts[1].chop(1);
      }
      timeParts[1] = timeParts[1].toLower();
      guessedGranularity +=":"+timeParts[1];
    }
    if(timeParts.size()>2){
      if(timeParts[2].contains('z',Qt::CaseInsensitive)){
        containsZ = true;
        timeParts[2].chop(1);
      }
      timeParts[2] = timeParts[2].toLower();
      guessedGranularity +=":"+timeParts[2];
    }
    if(containsZ)
      guessedGranularity += "Z";
  }
  return guessedGranularity;
}


int OAI::collect(Article** articles, QDate startDate, QDate endDate){
  QMap <QString, QString> parameters;
  QNetworkAccessManager *manager = new QNetworkAccessManager(this);
  this->connect(this,SIGNAL(returnFile()),&this->loop,SLOT(quit()));
  parameters["metadataPrefix"] = this->getSetting("metadata_type");
  parameters["from"] = QDateTime(startDate).toString(this->getSetting("granularity"));
  parameters["until"] = QDateTime(endDate).toString(this->getSetting("granularity"));
  
  this->connect(manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(fileReady(QNetworkReply*)));
  this->state = OAI_LIST_RECORDS;
  manager->get(QNetworkRequest(this->prepareOaiVerb("ListRecords",&parameters)));
  
  std::cout << this->prepareOaiVerb("ListRecords",&parameters).toString().toStdString() << std::endl;
  while(!this->loop.exec()){
    if(this->file == NULL)
      std::cout << "To Slow\n";
    QString teste = this->file->readLine();
    //std::cout << "-- " << QString(this->file->readAll()).toStdString() << std::endl;
    std::cout << teste.toStdString() << std::endl;
    
    delete this->file;
  }
  
  return 0;
}


#include "OAI.moc"