#ifndef WIDGETVISUALIZEHANDLER_HPP
#define WIDGETVISUALIZEHANDLER_HPP

#include "../Handler/Handler.hpp"
#include "../../Windows/MainWindow/VisualizeWidget.hpp"
#include "../../Defines.hpp"
#include "../Collect/Collect.hpp"
#include <QDir>
#include <QVector>
#include <QString>
#include <QStringList>
#include <QListWidgetItem>

class WidgetVisualizeHandler : public Handler {
private:
  Q_OBJECT
  Ui_visualizeWidget *ui_visualizeWidget;
  QVector<Collect*> collects;
public:
  WidgetVisualizeHandler(QWidget *parent);
  virtual ~WidgetVisualizeHandler();
  
public slots:
  void updateList();
  void openCollect();
signals:
  void listItems(Collect *collect);
};

#endif