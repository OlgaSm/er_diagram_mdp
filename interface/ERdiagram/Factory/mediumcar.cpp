#include "mediumcar.h"
#include <QString>
#include "Contaner/DoubleField.h"
#include "Contaner/IntField.h"

MediumCar::MediumCar():Entitie("Автомобиль "+QString::number(id++).toStdString()){
    this->myfield->push_back(new IntField("X",0));
    this->myfield->push_back(new IntField("Y",0));
    this->myfield->push_back(new IntField("W",100));
    this->myfield->push_back(new IntField("H",100));
    this->myfield->push_back(new IntField("F",1));
    this->myfield->push_back(new IntField("T",1));
    this->myfield->push_back(new IntField("Скорость",50));
    this->myfield->push_back(new DoubleField("Дистанция",50));
}

MediumCar::~MediumCar(){
}

void MediumCar::setId(int id0){
    id=id0;
}

string MediumCar::getBrand(){
    return this->ID;
}

double MediumCar::getPower(){
    return 50;
}

int MediumCar::id = 0;
