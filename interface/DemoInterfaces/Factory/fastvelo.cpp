#include "fastvelo.h"
#include <QString>
#include "Contaner/DoubleField.h"
#include "Contaner/IntField.h"

FastVelo::FastVelo():Entitie("Велосипед(отл) "+QString::number(id++).toStdString()){
    this->myfield->push_back(new IntField("X",0));
    this->myfield->push_back(new IntField("Y",0));
    this->myfield->push_back(new IntField("W",100));
    this->myfield->push_back(new IntField("H",100));
    this->myfield->push_back(new IntField("F",1));
    this->myfield->push_back(new IntField("T",1));
    this->myfield->push_back(new IntField("Скорость",15));
}

FastVelo::~FastVelo(){
}
string FastVelo::getBrand(){
    return this->ID;
}

double FastVelo::getPower (){
    return 15;
}

int FastVelo::id = 0;
