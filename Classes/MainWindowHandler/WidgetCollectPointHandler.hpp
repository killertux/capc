#ifndef WIDGETCOLLECTPOINTHANDLER_HPP
#define WIDGETCOLLECTPOINTHANDLER_HPP

#include "../Handler/Handler.hpp"
#include "../../Windows/MainWindow/CollectPointWidget.hpp"
#include "../CollectPoints/CollectPoints.hpp"
#include "../OAI/OAI.hpp"
#include "../Message/Message.hpp"
#include "../../Defines.hpp"
#include "../../functions.hpp"

class WidgetCollectPointHandler : public Handler{
private:
  Q_OBJECT
  Ui_collectPointWidget *ui_collectPointWidget;
  CollectPoints *collectPoint;
  Article **articles;
  
public:
  WidgetCollectPointHandler(QWidget* parent, CollectPoints *collectPoint);
  virtual ~WidgetCollectPointHandler();
  
public slots:
  void cancel();
  void addMessage(Message newMessage);
  void collect();
  
signals:
  void deleteThis();
};

#endif