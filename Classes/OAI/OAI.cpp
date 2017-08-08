#include "OAI.hpp"
#include <iostream>
#include "../../functions.hpp"

OAI::OAI(){
  this->config = NULL;
  this->state = OAI_NONE;
  this->nCollected = 0;
  this->manager = new QNetworkAccessManager(this);
  this->connect(this->manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(fileReady(QNetworkReply*)));
  this->articleDAO = new ArticleDAO("config/article.xml", this);
}

OAI::OAI(QString cfgFilePath){
  this->cfgFilePath = cfgFilePath;
  this->config = new Configuration(QFileInfo(this->cfgFilePath).dir().absolutePath(),QFileInfo(this->cfgFilePath).fileName());
  this->name = this->config->getSetting("name");
  this->state = OAI_NONE;
  this->nCollected = 0;
  this->manager = new QNetworkAccessManager(this);
  if(this->config->getSetting("last_collected_date").isEmpty())
    this->getFirstDate();
  
  this->articleDAO = new ArticleDAO("config/article.xml",this );
  this->connect(this->manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(fileReady(QNetworkReply*)));
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
  this->state = OAI_IDENTIFY;
  this->manager->get(QNetworkRequest(this->prepareOaiVerb("Identify")));
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
    this->buffer = new QByteArray(reply->readAll());
    QBuffer file(this->buffer);
   file.open(QIODevice::ReadOnly);
   XML parser(&file, this);
   this->connect(&parser, SIGNAL(nodeCompleted(XMLNode*)), this, SLOT(xmlProcessor(XMLNode*)));
   parser.parse();
   this->disconnect(&parser, SIGNAL(nodeCompleted(XMLNode*)), this, SLOT(xmlProcessor(XMLNode*)));
   this->config->save();
   delete this->buffer;
   emit(dateUpdated());
   return;
  }
  if(this->state == OAI_LIST_RECORDS){
    this->buffer = new QByteArray(reply->readAll());
    emit(returnFile());
    return;
  }
}

void OAI::xmlProcessor(XMLNode* node){
  if(this->state == OAI_IDENTIFY){
    if(node->getName() == "earliestDatestamp"){
      QDateTime dateTime = QDateTime::fromString(node->getValue(), Qt::ISODate);
      this->setSetting("last_collected_date",dateTime.toString("yyyy-MM-dd"));
    } else if(node->getName() == "granularity"){
      this->setSetting("granularity",this->guessGranularity(node->getValue()));
    }
  } else if(this->state == OAI_LIST_RECORDS){
    if(node->getName() == "capc-article"){
      Article *article = this->articleDAO->getArticleFromXML(node);
      if(article != NULL){
        //We should treat error here
//        std::cout<< article->getMainField()->getValue(0).toUtf8().
        this->nCollected++;
        this->articles.append(article);
        emit(sendMessage(Message("Artigo "+QString::number(this->nCollected)+ ": "+ article->getMainField()->getValue(0),M_OK)));
      }
    }
    if(node->getName() == "resumptionToken"){
      this->resumptionToken = node->getValue();
    }
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


int OAI::collect(Article *** rArticles, QDate startDate, QDate endDate, QObject *parent){
  QMap <QString, QString> parameters;
  QDir dir(QFileInfo(this->cfgFilePath).dir().absolutePath());
  this->connect(this, SIGNAL(sendMessage(Message)), parent, SLOT(addMessage(Message)));
 
  parameters["metadataPrefix"] = this->getSetting("metadata_type");
  parameters["from"] = QDateTime(startDate).toString(this->getSetting("granularity"));
  parameters["until"] = QDateTime(endDate).toString(this->getSetting("granularity"));
  
  this->connect(this,SIGNAL(returnFile()),&this->loop,SLOT(quit()));
  this->state = OAI_LIST_RECORDS;
  this->manager->get(QNetworkRequest(this->prepareOaiVerb("ListRecords",&parameters)));
  
  while(!this->loop.exec()){
    QFile fileOut("temp.xml");
    QDir dir = QFileInfo(this->getCfgFilePath()).absoluteDir();
    QByteArray buf;
    QBuffer fileIn(&buf);
    fileIn.open(QIODevice::ReadWrite);
    fileOut.open(QIODevice::WriteOnly);
    fileOut.write(*this->buffer);
    fileOut.close();
    ((QIODevice*) &fileIn)->write(functions::exec(QString("xsltproc " + dir.absoluteFilePath(this->getSetting("xslt")) + " temp.xml")).toUtf8());
    fileIn.reset();
    this->resumptionToken = "";
    XML parser(&fileIn, this);
    this->connect(&parser, SIGNAL(nodeCompleted(XMLNode*)), this, SLOT(xmlProcessor(XMLNode*)));
    parser.parse();
    this->disconnect(&parser, SIGNAL(nodeCompleted(XMLNode*)), this, SLOT(xmlProcessor(XMLNode*)));
    
    parameters.clear();
    parameters["resumptionToken"] = this->resumptionToken;
    delete this->buffer;
    
    if(this->resumptionToken == "")
      break;
    /*if(this->nCollected >= 2)
      break;*/
    this->manager->get(QNetworkRequest(this->prepareOaiVerb("ListRecords",&parameters)));

  }
  Article **retArticles = new Article*[this->articles.size()];
  for(int i=0; i<this->articles.size(); i++)
    retArticles[i] = this->articles[i];
  
  (*rArticles) = retArticles;
  return this->nCollected;
}

void OAI::slotError(QNetworkReply::NetworkError){

}


#include "OAI.moc"