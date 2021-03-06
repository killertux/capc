#ifndef COLLECTTYPES_HPP
#define COLLECTTYPES_HPP

#include <QString>
#include "../Handler/Handler.hpp"
#include "../Configuration/Configuration.hpp"

#define N_OF_COLLECT_TYPES 1

class CollectTypes{
public:
  virtual QString getName() = 0;
  virtual Handler *getSettingsHandler(QMainWindow *parent) = 0;
  virtual ~CollectTypes();
};

#endif