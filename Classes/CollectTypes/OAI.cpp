#include "OAI.hpp"

OAI::OAI(){
  this->name = "OAI-PMH";
}

OAI::~OAI(){

}

QString OAI::getName(){
  return this->name;
}