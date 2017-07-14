#include "CollectPointsManager.hpp"

CollectPoints* CollectPointsManager::getCollectPoint(QString cfgPath)
{
  Configuration config(cfgPath);
  if(config.getSetting("type") == "OAI-PMH" )
    return new OAI(cfgPath);
  return NULL;
}
