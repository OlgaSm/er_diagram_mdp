#include "student.h"
#include <QString>
#include "Contaner/DoubleField.h"
#include "Contaner/IntField.h"
#include "Contaner/StringField.h"

Student::Student():Entitie("Студент "+QString::number(id++).toStdString()){
    this->myfield->push_back(new IntField("X",0));
    this->myfield->push_back(new IntField("Y",0));
    this->myfield->push_back(new IntField("W",100));
    this->myfield->push_back(new IntField("H",100));
    this->myfield->push_back(new IntField("F",1));
    this->myfield->push_back(new IntField("T",1));
    this->myfield->push_back(new IntField("Скорость",10));
    this->myfield->push_back(new StringField("Фамилия","Иванов"));
    this->myfield->push_back(new StringField("Имя","Иван"));
    this->myfield->push_back(new StringField("Отчетство","Иванович"));
	//this->myfield->push_back(new StringField("Место занятия","Институт"));
}

Student::~Student(){
}

void Student::setId(int id0){
    id=id0;
}

string Student::getStatus(){
    return this->ID;
}

string Student::getName(){
    return "Иванов Иван Иванович";
}
/*
string Student::getPlace(){
    return "Институт";
}
*/
double Student::getPower (){
    return 10;
}

int Student::id = 0;
