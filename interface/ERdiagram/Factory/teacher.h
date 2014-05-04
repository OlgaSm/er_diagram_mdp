#ifndef TEACHER_H
#define TEACHER_H
#include "Contaner/Entitie.h"

class Teacher: public Entitie
{
private :
    static int id;
public:
    static void setId(int id0);
    Teacher();
    ~Teacher();
    string getStatus();
    double getPower ();
	string getName();
	//string getPlace();
};

#endif 
