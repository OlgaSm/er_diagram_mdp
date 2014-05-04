#include "courier.h"
#include <QString>
#include "Contaner/DoubleField.h"
#include "Contaner/IntField.h"
#include "Contaner/StringField.h"

Courier::Courier():Entitie("Курьер "+QString::number(id++).toStdString()){
    this->myfield->push_back(new IntField("X",0));
    this->myfield->push_back(new IntField("Y",0));
    this->myfield->push_back(new IntField("W",100));
    this->myfield->push_back(new IntField("H",100));
    this->myfield->push_back(new IntField("F",1));
    this->myfield->push_back(new IntField("T",0));
    this->myfield->push_back(new IntField("Возраст",21));
    this->myfield->push_back(new StringField("Фамилия","Степанов"));
    this->myfield->push_back(new StringField("Имя","Степан"));
    this->myfield->push_back(new StringField("Отчество","Степанович"));
    this->myfield->push_back(new StringField("Место работы","Город"));
}

Courier::~Courier(){
}

void Courier::setId(int id0){
    id=id0;
}

string Courier::getStatus(){
    return this->ID;
}

string Courier::getName(){
    return "Степанов Степан Степанович";
}
/*
string Courier::getPlace(){
    return "Город";
}
*/
double Courier::getPower (){
    return 15;
}

int Courier::id = 0;
