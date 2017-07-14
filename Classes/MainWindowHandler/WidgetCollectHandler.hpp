#ifndef WIDGETCOLLECTHANDLER_HPP
#define WIDGETCOLLECTHANDLER_HPP

#include <QDir>
#include <QVector>
#include <QLayoutItem>
#include "../Handler/Handler.hpp"
#include "../../Windows/MainWindow/CollectWidget.hpp"
#include "../../Defines.hpp"
#include "../CollectPoints/CollectPointsManager.hpp"
#include "../CollectPoints/CollectPoints.hpp"

class WidgetCollectHandler : public Handler{
private:
  Q_OBJECT
  Ui_collectWidget *ui_collectWidget;
  QVector<CollectPoints*> collectPoints;
public:
  WidgetCollectHandler(QWidget *parent);
  virtual ~WidgetCollectHandler();
  
public slots:
  void updateCollectList();
  void updateDates();
  void startCollect();

signals:
  void startCollect(CollectPoints*);
};

#endif