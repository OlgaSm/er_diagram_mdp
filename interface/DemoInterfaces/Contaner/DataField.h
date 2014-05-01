#ifndef DATAFIELD_H
#define DATAFIELD_H

#include <string>
#include "Field.h"

//=====================================
#include "DebugDefine.h"
//=====================================

using namespace std;

template<class Type>
class DataField : public Field
{
private:
	Type value;

public:    
    explicit DataField(string id, Type val);
    ~DataField();

public:    
    Type getValue();
    void setValue(Type val);
	Field_Types getType();
};

//=============================================================
//Реализация
//=============================================================

template<class Type>
DataField<Type>::DataField(string id, Type val) : Field(id){
	this->value = val;
    #ifdef DEBUGLOG_DATAFIELD
        QFile file(LOG_PATH);
        file.open(QIODevice::Append | QIODevice::Text);
        QTextStream out(&file);
        out << "+ TemplateField created" << endl;
        file.close();
        //CountCreatedObject++;
    #endif
}

template<class Type>
DataField<Type>::~DataField(){
#ifdef DEBUGLOG_DATAFIELD
    QFile file(LOG_PATH);
    file.open(QIODevice::Append | QIODevice::Text);
    QTextStream out(&file);
    out << "- TemplateField deleted" << endl;
    file.close();
    //CountDeltedObject++;
#endif
}

template<class Type>
Type DataField<Type>::getValue()
{
	return this->value;
}

template<class Type>
void DataField<Type>::setValue(Type val)
{
	this->value = val;
}

template<class Type>
Field_Types DataField<Type>::getType(){
    return TEMPLATE_FILD;
}
#endif
