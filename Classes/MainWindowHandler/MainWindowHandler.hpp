#ifndef MAINWINDOWHANDLER_HPP
#define MAINWINDOWHANDLER_HPP

#include <QWidget>
#include "../Handler/Handler.hpp"
#include "../../Windows/MainWindow/MainWindow.hpp"
#include "WidgetSettingsHandler.hpp"
#include "../../Defines.hpp"

class MainWindowHandler : public Handler{
private:
  Q_OBJECT
  Ui_MainWindow *ui_MainWindow;
  
  WidgetSettingsHandler *widgetSettingsHandler;
  
  QWidget *collectWidget;
  QWidget *visualizeWidget;
  QWidget *settingsWidget;
  
public:
  MainWindowHandler(QMainWindow* parent, WidgetIndex startWidget, CollectTypes **listCollectTypes);
  virtual ~MainWindowHandler();
};

#endif