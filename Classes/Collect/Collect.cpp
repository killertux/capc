#include "Collect.hpp"

Collect::Collect(QString name, QString path){
  this->name = name;
  this->path = path;
  this->articleDao = new ArticleDAO(CONFIG_ARTICLES, NULL);
  QDir dir(path);
  this->date = QDateTime::fromString(dir.dirName(), "hh-mm-dd-MM-yyyy");
  QStringList items = dir.entryList(QDir::Dirs | QDir::NoDotAndDotDot, QDir::Name);
  for(auto i: items){
    QDir dirI(dir);
    dirI.cd(i);
    Article *newArticle = articleDao->getArticleFromXML(dirI.absoluteFilePath("article.xml"));
    if(newArticle == NULL)
      continue;
    if(dirI.exists("note")){
      QFile note(dirI.absoluteFilePath("note"));
      note.open(QIODevice::ReadOnly);
      newArticle->setNote(note.readAll());
      note.close();
    }
    if(dirI.exists("contents")){
      QFile contents(dirI.absoluteFilePath("contents"));
      contents.open(QIODevice::ReadOnly);
      QTextStream in(&contents);
      while(!in.atEnd()){
        newArticle->addFile(in.readLine());
      }
    }
    this->articles.append(newArticle);
  }
}


 Collect::~Collect(){}
