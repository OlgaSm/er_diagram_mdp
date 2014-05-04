#include "schoolboy.h"
#include <QString>
#include "Contaner/DoubleField.h"
#include "Contaner/IntField.h"
#include "Contaner/StringField.h"

Schoolboy::Schoolboy():Entitie("Школьник "+QString::number(id++).toStdString()){
    this->myfield->push_back(new IntField("X",0));
    this->myfield->push_back(new IntField("Y",0));
    this->myfield->push_back(new IntField("W",100));
    this->myfield->push_back(new IntField("H",100));
    this->myfield->push_back(new IntField("F",1));
    this->myfield->push_back(new IntField("T",0));
    this->myfield->push_back(new IntField("Возраст",8));
    this->myfield->push_back(new StringField("Фамилия","Петров"));
    this->myfield->push_back(new StringField("Имя","Петя"));
    this->myfield->push_back(new StringField("Отчество","Петрович"));
    this->myfield->push_back(new StringField("Школа","Школа №1"));
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
    return "Петров Петя Петрович";
}
/*
string Schoolboy::getPlace(){
    return "Школа №1";
}
*/
double Schoolboy::getPower(){
    return 8;
}

int Schoolboy::id = 0;
