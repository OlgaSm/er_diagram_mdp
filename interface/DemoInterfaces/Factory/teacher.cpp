#include "teacher.h"
#include <QString>
#include "Contaner/DoubleField.h"
#include "Contaner/IntField.h"
#include "Contaner/StringField.h"

Teacher::Teacher():Entitie("Prepodavatel "+QString::number(id++).toStdString()){
    this->myfield->push_back(new IntField("X",0));
    this->myfield->push_back(new IntField("Y",0));
    this->myfield->push_back(new IntField("W",100));
    this->myfield->push_back(new IntField("H",100));
    this->myfield->push_back(new IntField("F",1));
    this->myfield->push_back(new IntField("T",1));
    this->myfield->push_back(new IntField("Skorost",12));
    this->myfield->push_back(new StringField("Familya","Antonov"));
    this->myfield->push_back(new StringField("Imya","Anton"));
    this->myfield->push_back(new StringField("Otchetstvo","Antonovich"));
	//this->myfield->push_back(new StringField("Mesto zanyatya","Universitet"));
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
    return "Antonov Anton Antonovich";
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
