#ifndef HANDLER_HPP
#define HANDLER_HPP

#include <QObject>
#include <QMainWindow>
#include <QMessageBox>

class Handler : public QObject{
private:
  Q_OBJECT
protected:
  QObject *parent;
  void showError(QString error);
public:
  Handler(QMainWindow* parent);
  Handler(QWidget* parent);
  virtual ~Handler();
};

#endif