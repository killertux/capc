#ifndef WIDGETSETTINGSHANDLER_HPP
#define WIDGETSETTINGSHANDLER_HPP

#include "../Handler/Handler.hpp"
#include "../../Windows/MainWindow/SettingsWidget.hpp"
#include "../CollectTypes/CollectTypes.hpp"
#include "../Configuration/Configuration.hpp"
#include "../../Defines.hpp"
#include <QFile>
#include <QFileInfo>
#include <QDir>

class WidgetSettingsHandler : public Handler{
private:
  Q_OBJECT
  Ui_widgetSettings *ui_widgetSettings;
  CollectTypes **listCollectTypes;
  Configuration *config;
public:
  WidgetSettingsHandler(QWidget* parent, CollectTypes **listCollectTypes);
  virtual ~WidgetSettingsHandler();
  
public slots:
  void addNewCollectPoint();
  void save();
};

#endif