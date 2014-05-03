#include "slowcar.h"
#include <QString>
#include "Contaner/DoubleField.h"
#include "Contaner/IntField.h"

SlowCar::SlowCar():Entitie("Драндулет "+QString::number(id++).toStdString()){
    this->myfield->push_back(new IntField("X",0));
    this->myfield->push_back(new IntField("Y",0));
    this->myfield->push_back(new IntField("W",100));
    this->myfield->push_back(new IntField("H",100));
    this->myfield->push_back(new IntField("F",1));
    this->myfield->push_back(new IntField("T",1));
    this->myfield->push_back(new IntField("Скорость",25));
    this->myfield->push_back(new DoubleField("Дистанция",25));
}

SlowCar::~SlowCar(){

}

void SlowCar::setId(int id0){
    id=id0;
}

string SlowCar::getBrand(){
    return this->ID;
}

double SlowCar::getPower (){
    return 25;
}
int SlowCar::id = 0;
