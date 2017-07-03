#include "Handler.hpp"

Handler::Handler(QMainWindow* parent): QObject(parent){
  this->parent = parent;
}

Handler::Handler(QWidget* parent): QObject(parent){
  this->parent = parent;
}


Handler::~Handler(){
}

void Handler::showError(QString error){
  QMessageBox::warning((QWidget*)this->parent,QString("Erro"),error);
}


#include "Handler.moc"