#include "schoolboy.h"
#include <QString>
#include "Contaner/DoubleField.h"
#include "Contaner/IntField.h"
#include "Contaner/StringField.h"

Schoolboy::Schoolboy():Entitie("Shkolnik "+QString::number(id++).toStdString()){
    this->myfield->push_back(new IntField("X",0));
    this->myfield->push_back(new IntField("Y",0));
    this->myfield->push_back(new IntField("W",100));
    this->myfield->push_back(new IntField("H",100));
    this->myfield->push_back(new IntField("F",1));
    this->myfield->push_back(new IntField("T",1));
    this->myfield->push_back(new IntField("Skorost",8));
    this->myfield->push_back(new StringField("Familya","Petrov"));
    this->myfield->push_back(new StringField("Imya","Petr"));
    this->myfield->push_back(new StringField("Otchetstvo","Petrovich"));
	//this->myfield->push_back(new StringField("Mesto zanyatya","Shkola"));
}

Schoolboy::~Schoolboy(){
}

void Schoolboy::setId(int id0){
    id=id0;
}

string Schoolboy::getStatus(){
    return this->ID;
}

string Schoolboy::getName(){
    return "Petrov Petr Petrovich";
}
/*
string Schoolboy::getPlace(){
    return "Shkola";
}
*/
double Schoolboy::getPower (){
    return 8;
}

int Schoolboy::id = 0;
