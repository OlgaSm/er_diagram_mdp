#include <string>
#include "DoubleField.h"

//=====================================
#include "DebugDefine.h"
//=====================================

DoubleField::DoubleField(string id, double val) : Field(id){
    this->value = val;
    #ifdef DEBUGLOG_DOUBLE_FIELD
        QFile file(LOG_PATH);
        file.open(QIODevice::Append | QIODevice::Text);
        QTextStream out(&file);
        out << "+ DoubleField created" << endl;
        file.close();
        //CountCreatedObject++;
    #endif
}

DoubleField::~DoubleField(){
    #ifdef DEBUGLOG_DOUBLE_FIELD
        QFile file(LOG_PATH);
        file.open(QIODevice::Append | QIODevice::Text);
        QTextStream out(&file);
        out << "- DoubleField deleted" << endl;
        file.close();
        //CountDeltedObject++;
    #endif
}

double DoubleField::getValue(){
    return this->value;
}

void DoubleField::setValue(double val){
    this->value = val;
}

Field_Types DoubleField::getType(){
    return DOUBLE_FIELD;
}
