#include "student.h"
#include <QString>
#include "Contaner/DoubleField.h"
#include "Contaner/IntField.h"
#include "Contaner/StringField.h"

Student::Student():Entitie("��㤥�� "+QString::number(id++).toStdString()){
    this->myfield->push_back(new IntField("X",0));
    this->myfield->push_back(new IntField("Y",0));
    this->myfield->push_back(new IntField("W",100));
    this->myfield->push_back(new IntField("H",100));
    this->myfield->push_back(new IntField("F",1));
    this->myfield->push_back(new IntField("T",1));
    this->myfield->push_back(new IntField("�������",10));
    this->myfield->push_back(new StringField("�������","������"));
    this->myfield->push_back(new StringField("���","����"));
    this->myfield->push_back(new StringField("�����⢮","��������"));
	//this->myfield->push_back(new StringField("���� ������","�������"));
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
    return "������ ���� ��������";
}
/*
string Student::getPlace(){
    return "�������";
}
*/
double Student::getPower (){
    return 10;
}

int Student::id = 0;
