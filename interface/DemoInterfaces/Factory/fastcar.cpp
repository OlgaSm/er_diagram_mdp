#include "fastcar.h"
#include <QString>
#include "Contaner/DoubleField.h"
#include "Contaner/IntField.h"

FastCar::FastCar():Entitie("Спорткар "+QString::number(id++).toStdString()){
    this->myfield->push_back(new IntField("X",0));
    this->myfield->push_back(new IntField("Y",0));
    this->myfield->push_back(new IntField("W",100));
    this->myfield->push_back(new IntField("H",100));
    this->myfield->push_back(new IntField("F",1));
    this->myfield->push_back(new IntField("T",1));
    this->myfield->push_back(new IntField("Скорость",75));
    this->myfield->push_back(new DoubleField("Дистанция",75));
}

FastCar::~FastCar(){
}
string FastCar::getBrand(){
    return this->ID;
}

double FastCar::getPower (){
    return 75;
}

int FastCar::id = 0;
