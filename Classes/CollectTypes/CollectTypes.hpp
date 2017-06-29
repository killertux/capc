#ifndef COLLECTTYPES_HPP
#define COLLECTTYPES_HPP

#include <QString>

#define N_OF_COLLECT_TYPES 1

class CollectTypes{
public:
  virtual QString getName();
  virtual ~CollectTypes();
};

#endif