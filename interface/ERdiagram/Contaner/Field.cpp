#include "Field.h"

//=====================================
#include "DebugDefine.h"
//=====================================

Field::Field(string ID){
    this->ID = ID;
    #ifdef DEBUGLOG_FIELD
        QFile file(LOG_PATH);
        file.open(QIODevice::Append | QIODevice::Text);
        QTextStream out(&file);
        out << "+ Field created" << endl;
        file.close();
        //CountCreatedObject++;
    #endif
}

Field::~Field(){
    #ifdef DEBUGLOG_FIELD
        QFile file(LOG_PATH);
        file.open(QIODevice::Append | QIODevice::Text);
        QTextStream out(&file);
        out << "- Field deleted" << endl;
        file.close();
        //CountDeltedObject++;
    #endif
}

string Field::getID(){
    return this->ID;
}

void Field::setID(string ID){
    this->ID = ID;
}

Field_Types Field::getType(){
    return BASE_FIELD;
}

