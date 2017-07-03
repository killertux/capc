#ifndef WIDGETSETTINGSHANDLER_HPP
#define WIDGETSETTINGSHANDLER_HPP

#include "../Handler/Handler.hpp"
#include "../../Windows/MainWindow/SettingsWidget.hpp"
#include "../CollectTypes/CollectTypes.hpp"

class WidgetSettingsHandler : public Handler{
private:
  Q_OBJECT
  Ui_widgetSettings *ui_widgetSettings;
  CollectTypes **listCollectTypes;
public:
  WidgetSettingsHandler(QWidget* parent, CollectTypes **listCollectTypes);
  virtual ~WidgetSettingsHandler();
  
public slots:
  void addNewCollectPoint();
};

#endif