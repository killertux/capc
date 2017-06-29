#ifndef MAINWINDOWHANDLER_HPP
#define MAINWINDOWHANDLER_HPP

#include <QObject>
#include <QWidget>
#include "../../Windows/MainWindow/MainWindow.hpp"
#include "../../Windows/MainWindow/SettingsWidget.hpp"
#include "../../Defines.hpp"
#include "../CollectTypes/CollectTypes.hpp"

class MainWindowHandler : public QObject{
private:
  Q_OBJECT
  Ui_MainWindow *ui_MainWindow;
  Ui_widgetSettings *ui_widgetSetings;
  CollectTypes **listCollectTypes;
  
  QWidget *collectWidget;
  QWidget *visualizeWidget;
  QWidget *settingsWidget;
  
public:
  MainWindowHandler(QMainWindow* parent, WidgetIndex startWidget, CollectTypes **listCollectTypes);
  virtual ~MainWindowHandler();
};

#endif