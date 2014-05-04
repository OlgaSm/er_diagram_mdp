#include "teacher.h"
#include <QString>
#include "Contaner/DoubleField.h"
#include "Contaner/IntField.h"
#include "Contaner/StringField.h"

Teacher::Teacher():Entitie("Человек "+QString::number(id++).toStdString()){
    this->myfield->push_back(new IntField("X",0));
    this->myfield->push_back(new IntField("Y",0));
    this->myfield->push_back(new IntField("W",100));
    this->myfield->push_back(new IntField("H",100));
    this->myfield->push_back(new IntField("F",1));
    this->myfield->push_back(new IntField("T",0));
    this->myfield->push_back(new IntField("Возраст",25));
    this->myfield->push_back(new StringField("Фамилия","Антонов"));
    this->myfield->push_back(new StringField("Имя","Антон"));
    this->myfield->push_back(new StringField("Отчество","Антонович"));
    this->myfield->push_back(new StringField("Место работы","Университет"));
}

Teacher::~Teacher(){
}

void Teacher::setId(int id0){
    id=id0;
}

string Teacher::getStatus(){
    return this->ID;
}

string Teacher::getName(){
    return "Антонов Антон Антонович";
}
/*
string Teacher::getPlace(){
    return "Universitet";
}
*/
double Teacher::getPower (){
    return 12;
}

int Teacher::id = 0;
