#include "slowvelo.h"
#include <QString>
#include "Contaner/DoubleField.h"
#include "Contaner/IntField.h"

SlowVelo::SlowVelo():Entitie("Велосипед "+QString::number(id++).toStdString()){
    this->myfield->push_back(new IntField("X",0));
    this->myfield->push_back(new IntField("Y",0));
    this->myfield->push_back(new IntField("W",100));
    this->myfield->push_back(new IntField("H",100));
    this->myfield->push_back(new IntField("F",1));
    this->myfield->push_back(new IntField("T",1));
    this->myfield->push_back(new IntField("Скорость",5));
}

SlowVelo::~SlowVelo(){

}

void SlowVelo::setId(int id0){
    id=id0;
}

string SlowVelo::getBrand(){
    return this->ID;
}

double SlowVelo::getPower (){
    return 5;
}
int SlowVelo::id = 0;
