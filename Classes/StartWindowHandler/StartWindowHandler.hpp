#ifndef STARTWINDOWHANDLER_HPP
#define STARTWINDOWHANDLER_HPP

#include <QObject>
#include "../../Windows/StartWindow/StartWindow.hpp"
#include "../../Defines.hpp"

class StartWindowHandler : public QObject {
private:
  Q_OBJECT
  Ui_StartWindow *ui_StartWindow;
private slots:
  void catchPushButtonCollect();
  void catchPushButtonVisualize();
  void catchPushButtonSettings();
public:
  StartWindowHandler(QMainWindow *parent);
  virtual ~StartWindowHandler();
signals:
  void chooseMainWidget(WidgetIndex startWidget);

};

#endif
