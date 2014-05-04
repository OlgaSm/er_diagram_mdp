#ifndef STUDENT_H
#define STUDENT_H
#include "Contaner/Entitie.h"

class Student: public Entitie
{
private :
    static int id;
public:
    static void setId(int id0);
    Student();
    ~Student();
    string getStatus();
    double getPower ();
	string getName();
	//string getPlace();
};

#endif 
