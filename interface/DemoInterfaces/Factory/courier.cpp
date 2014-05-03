#include "courier.h"
#include <QString>
#include "Contaner/DoubleField.h"
#include "Contaner/IntField.h"
#include "Contaner/StringField.h"

Courier::Courier():Entitie("Courier "+QString::number(id++).toStdString()){
    this->myfield->push_back(new IntField("X",0));
    this->myfield->push_back(new IntField("Y",0));
    this->myfield->push_back(new IntField("W",100));
    this->myfield->push_back(new IntField("H",100));
    this->myfield->push_back(new IntField("F",1));
    this->myfield->push_back(new IntField("T",1));
    this->myfield->push_back(new IntField("Skorost",15));
    this->myfield->push_back(new StringField("Familya","Stepanov"));
    this->myfield->push_back(new StringField("Imya","Stepan"));
    this->myfield->push_back(new StringField("Otchetstvo","Stepanovich"));
	//this->myfield->push_back(new StringField("Mesto zanyatya","Gorod"));
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
    return "Stepanov Stepan Stepanovich";
}
/*
string Courier::getPlace(){
    return "Gorod";
}
*/
double Courier::getPower (){
    return 15;
}

int Courier::id = 0;
