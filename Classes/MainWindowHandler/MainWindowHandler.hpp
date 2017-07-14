#ifndef MAINWINDOWHANDLER_HPP
#define MAINWINDOWHANDLER_HPP

#include <QWidget>
#include <QList>
#include "../Handler/Handler.hpp"
#include "../../Windows/MainWindow/MainWindow.hpp"
#include "WidgetSettingsHandler.hpp"
#include "WidgetCollectHandler.hpp"
#include "WidgetCollectPointHandler.hpp"
#include "../../Defines.hpp"
#include "../CollectPoints/CollectPoints.hpp"

class MainWindowHandler : public Handler{
private:
  Q_OBJECT
  Ui_MainWindow *ui_MainWindow;
  
  WidgetSettingsHandler *widgetSettingsHandler;
  WidgetCollectHandler *widgetCollectHandler;
  
  QWidget *collectWidget;
  QWidget *visualizeWidget;
  QWidget *settingsWidget;
  QList<QWidget *>collectPointsWidgets;
  QList<WidgetCollectPointHandler*>collectPointsHandler;
  
public:
  MainWindowHandler(QMainWindow* parent, WidgetIndex startWidget, CollectTypes **listCollectTypes);
  virtual ~MainWindowHandler();

public slots:
  void update(int index);
  void startCollect(CollectPoints *collectPoint);
  void stopCollect();
};

#endif