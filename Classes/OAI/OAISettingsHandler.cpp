#include "OAISettingsHandler.hpp"

OAISettingsHandler::OAISettingsHandler(QMainWindow* parent): Handler(parent)
{
  this->ui_OAISettingsWindow = new Ui_OAISettingsWindow();
  this->ui_OAISettingsWindow->setupUi(parent);
  this->ui_OAISettingsWindow->retranslateUi(parent);
  
  //Handle connects
  parent->connect(this->ui_OAISettingsWindow->pushButtonCancel,SIGNAL(clicked()),parent,SLOT(close()));
  parent->connect(this->ui_OAISettingsWindow->pushButtonSave,SIGNAL(clicked()),this,SLOT(save()));
}

OAISettingsHandler::~OAISettingsHandler()
{
  delete this->ui_OAISettingsWindow;
}

void OAISettingsHandler::save(){
  //Check if field are right
  if(this->ui_OAISettingsWindow->lineEditName->text().isEmpty()){
    this->showError(QString::fromUtf8("Nome não preenchido!"));
    return;
  } else if(this->ui_OAISettingsWindow->lineEditName->text().contains(QChar(' '))){
    this->showError(QString::fromUtf8("Nome não pode conter espaços!"));
    return;
  }
  
  if(this->ui_OAISettingsWindow->lineEditOAIAddress->text().isEmpty()){
    this->showError(QString::fromUtf8("Endereço OAI não preenchido!"));
    //TODO : Check if addres is valid
    return;
  }
  
  if(this->ui_OAISettingsWindow->lineEditMetadataType->text().isEmpty()){
    this->showError(QString::fromUtf8("Tipo de metadados não preenchido!"));
    return;
  }
  
  if(this->ui_OAISettingsWindow->kurlrequesterXSLT->text().isEmpty()){
    this->showError(QString::fromUtf8("Folha de estilo não encontrada!"));
  //TODO : Check if XSLT file is valid
    return;
  }
  
  QDir dir(COLLECT_POINTS_CONFIG_FOLDER);
  OAI oai(dir.absoluteFilePath(this->ui_OAISettingsWindow->lineEditName->text()+".cfg"));
  
  oai.setSetting("type","OAI-PMH");
  oai.setSetting("name",this->ui_OAISettingsWindow->lineEditName->text());
  oai.setSetting("oai_address",this->ui_OAISettingsWindow->lineEditOAIAddress->text());
  oai.setSetting("metadata_type",this->ui_OAISettingsWindow->lineEditMetadataType->text());
  QFile::copy(this->ui_OAISettingsWindow->kurlrequesterXSLT->text(),dir.absoluteFilePath(this->ui_OAISettingsWindow->lineEditName->text()+"_xsl.xsl"));
  oai.setSetting("xslt",this->ui_OAISettingsWindow->lineEditName->text()+"_xsl.xsl");
  if(!this->ui_OAISettingsWindow->kurlrequesterScript->text().isEmpty()){
    QFileInfo infoScript(this->ui_OAISettingsWindow->kurlrequesterScript->text());
    QFile::copy(this->ui_OAISettingsWindow->kurlrequesterScript->text(),dir.absoluteFilePath(infoScript.fileName()));
    oai.setSetting("script",infoScript.fileName());
  }
  if(!this->ui_OAISettingsWindow->lineEditScriptParameters->text().isEmpty())
    oai.setSetting("script_parameters",this->ui_OAISettingsWindow->lineEditScriptParameters->text());
  oai.save();
  ((QMainWindow*)this->parent)->close();
}


#include "OAISettingsHandler.moc"