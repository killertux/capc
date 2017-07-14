#ifndef OAISETTINGSHANDLER_HPP
#define OAISETTINGSHANDLER_HPP

#include <QDir>
#include <QFile>
#include <QFileInfo>

#include "../Handler/Handler.hpp"
#include "../../Windows/OAI/OAISettingsWindow.hpp"
#include "OAI.hpp"
#include "../Configuration/Configuration.hpp"
#include "../../Defines.hpp"

#include <iostream>

class OAISettingsHandler : public Handler{
private:
  Q_OBJECT
  Ui_OAISettingsWindow *ui_OAISettingsWindow;
public:
  OAISettingsHandler(QMainWindow* parent);
  virtual ~OAISettingsHandler();  
public slots:
  void save();
};

#endif