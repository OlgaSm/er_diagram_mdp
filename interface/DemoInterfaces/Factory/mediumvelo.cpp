#include "mediumvelo.h"
#include <QString>
#include "Contaner/DoubleField.h"
#include "Contaner/IntField.h"

MediumVelo::MediumVelo():Entitie("Велосипед(ср) "+QString::number(id++).toStdString()){
    this->myfield->push_back(new IntField("X",0));
    this->myfield->push_back(new IntField("Y",0));
    this->myfield->push_back(new IntField("W",100));
    this->myfield->push_back(new IntField("H",100));
    this->myfield->push_back(new IntField("F",1));
    this->myfield->push_back(new IntField("T",1));
    this->myfield->push_back(new IntField("Скорость",10));
}

MediumVelo::~MediumVelo(){
}

string MediumVelo::getBrand(){
    return this->ID;
}

double MediumVelo::getPower(){
    return 10;
}

int MediumVelo::id = 0;
