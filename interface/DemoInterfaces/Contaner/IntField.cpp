#include "Field.h"
#include "IntField.h"

//=====================================
#include "DebugDefine.h"
//=====================================

IntField::IntField(string id, int val) : Field(id){
    this->value = val;
    #ifdef DEBUGLOG_INT_FIELD
        QFile file(LOG_PATH);
        file.open(QIODevice::Append | QIODevice::Text);
        QTextStream out(&file);
        out << "+ IntField created" << endl;
        file.close();
        //CountCreatedObject++;
    #endif
}

IntField::~IntField(){
    #ifdef DEBUGLOG_INT_FIELD
        QFile file(LOG_PATH);
        file.open(QIODevice::Append | QIODevice::Text);
        QTextStream out(&file);
        out << "- IntField deleted" << endl;
        file.close();
        //CountDeltedObject++;
    #endif
}

int IntField::getValue(){
    return this->value;
}

void IntField::setValue(int val){
    this->value = val;
}

Field_Types IntField::getType(){
    return INT_FIELD;
}

