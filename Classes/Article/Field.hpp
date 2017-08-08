#ifndef FIELD_HPP
#define FIELD_HPP

#include <QString>
#include <QVector>
#include "../XML/XMLNode.hpp"

class Field{
private:
  QString label;
  QString reference;
  QString compare;
  QString type;
  QString dcElement;
  QString dcQualifier;
  QVector<QString> options;
  QVector<QString> values;
  bool repetitive;
  bool main;
  bool hidden;
  bool filter;
  
public:
  Field();
  ~Field();
  
  void setLabel(QString label){this->label = label;}
  void setReference(QString reference){this->reference = reference;}
  void setCompare(QString compare){this->compare = compare;}
  void setType(QString type){this->type = type;}
  void setDcElement(QString dcElement){this->dcElement = dcElement;}
  void setDcQualifier(QString dcQualifier){this->dcQualifier = dcQualifier;}
  void setRepetitive(bool repetitive){this->repetitive = repetitive;}
  void setMain(bool main){this->main = main;}
  void setHidden(bool hidden){this->hidden = hidden;}
  void setFilter(bool filter){this->filter = filter;}
  void addOption(QString option){this->options.append(option.simplified());}
  void addValue(QString value){this->values.append(value.simplified());}
  
  QString getLabel(){return this->label;}
  QString getReference(){return this->reference;}
  QString getCompare(){return this->compare;}
  QString getType(){return this->type;}
  QString getDcElement(){return this->dcElement;}
  QString getDcQualifier(){return this->dcQualifier;}
  QString getOption(int index){return this->options.value(index);}
  QVector<QString> getOptions(){return this->options;}
  QString getValue(int index){return this->values.value(index);}
  int getValueSize(){return this->values.size();}
  bool getRepetitive(){return this->repetitive;}
  bool getMain(){return this->main;}
  bool getHidden(){return this->hidden;}
  bool getFilter(){return this->filter;}
  
  void processNode(XMLNode *node);
 
  void operator = (const Field &f){
    label = f.label;
    reference = f.reference;
    compare = f.compare;
    type = f.type;
    dcElement = f.dcElement;
    options = f.options;
    //values = f.values;
    repetitive = f.repetitive;
    main = f.main;
    hidden = f.hidden;
    filter = f.filter;
  }
};

#endif