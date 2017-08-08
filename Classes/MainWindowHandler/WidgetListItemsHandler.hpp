#ifndef WIDGETLISTITEMSHANDLER_HPP
#define WIDGETLISTITEMSHANDLER_HPP

#include "../Handler/Handler.hpp"
#include "../Collect/Collect.hpp"
#include "../../Windows/MainWindow/ListItemsWidget.hpp"

class WidgetListItemsHandler : public Handler{
private:
  Q_OBJECT
  Collect *collect;
  Ui_listItemsWidget *ui_listItemsWidget;
  
public:
  WidgetListItemsHandler(QWidget* parent, Collect *collect);
  virtual ~WidgetListItemsHandler();
public slots:
  void updateList();
};

#endif