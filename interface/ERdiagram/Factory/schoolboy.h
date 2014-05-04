#ifndef SCHOOLBOY_H
#define SCHOOLBOY_H
#include "Contaner/Entitie.h"

class Schoolboy: public Entitie
{
private :
    static int id;
public:
    static void setId(int id0);
    Schoolboy();
    ~Schoolboy();
    string getStatus();
    double getPower ();
	string getName();
	//string getPlace();
};

#endif 
