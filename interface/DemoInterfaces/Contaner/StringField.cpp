#include <string>
#include "Field.h"
#include "StringField.h"

//=====================================
#include "DebugDefine.h"
//=====================================

StringField::StringField(string id, string val) : Field(id){
    this->value = val;
    #ifdef DEBUGLOG_STRING_FIELD
        QFile file(LOG_PATH);
        file.open(QIODevice::Append | QIODevice::Text);
        QTextStream out(&file);
        out << "+ StringField created" << endl;
        file.close();
        //CountCreatedObject++;
    #endif
}

StringField::~StringField(){
    #ifdef DEBUGLOG_STRING_FIELD
        QFile file(LOG_PATH);
        file.open(QIODevice::Append | QIODevice::Text);
        QTextStream out(&file);
        out << "- StringField deleted" << endl;
        file.close();
        //CountDeltedObject++;
    #endif
}

string StringField::getValue()
{
    return this->value;
}

void StringField::setValue(string val)
{
    this->value = val;
}

Field_Types StringField::getType(){
    return STRING_FIELD;
}
