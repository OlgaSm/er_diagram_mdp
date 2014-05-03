#include "student.h"
#include <QString>
#include "Contaner/DoubleField.h"
#include "Contaner/IntField.h"

Student::Student():Entitie("???????? "+QString::number(id++).toStdString()){
    this->myfield->push_back(new IntField("X",0));
    this->myfield->push_back(new IntField("Y",0));
    this->myfield->push_back(new IntField("W",100));
    this->myfield->push_back(new IntField("H",100));
    this->myfield->push_back(new IntField("F",1));
    this->myfield->push_back(new IntField("T",1));
    this->myfield->push_back(new IntField("????????",10));
    this->myfield->push_back(new StringField("???????","??????"));
    this->myfield->push_back(new StringField("???","????"));
    this->myfield->push_back(new StringField("????????","????????"));	
}

void Student::setId(int id0){
    id=id0;
}

::~Student(){
}
string Student::getBrand(){
    return this->ID;
}

double Student::getPower (){
    return 75;
}

int Student::id = 0;
