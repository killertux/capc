#ifndef COLLECTPOINTSMANAGER_HPP
#define COLLECTPOINTSMANAGER_HPP

#include "CollectPoints.hpp"
//All possible collect points
#include "../OAI/OAI.hpp"

#include "../Configuration/Configuration.hpp"

class CollectPointsManager{
private:
public:
  CollectPoints *getCollectPoint(QString cfgPath);
};

#endif