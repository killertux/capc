#ifndef Capc_HPP
#define Capc_HPP

#include <QObject>

#include "../StartWindowHandler/StartWindowHandler.hpp"
#include "../MainWindowHandler/MainWindowHandler.hpp"
#include "../../Defines.hpp"

#include "../CollectTypes/CollectTypes.hpp"
#include "../CollectTypes/OAI.hpp"

class Capc: public QMainWindow{
private:
  Q_OBJECT
  StartWindowHandler *startWindowHandler;
  MainWindowHandler *mainWindowHandler;
  CollectTypes *listCollectTypes[N_OF_COLLECT_TYPES];
public:
  Capc();
  virtual ~Capc();
  
public slots:
  void openMainWindow(WidgetIndex startWidget);
};

#endif // capc_H
