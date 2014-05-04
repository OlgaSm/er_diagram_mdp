#ifndef COURIER_H
#define COURIER_H
#include "Contaner/Entitie.h"

class Courier: public Entitie
{
private :
    static int id;
public:
    static void setId(int id0);
    Courier();
    ~Courier();
    string getStatus();
    double getPower ();
	string getName();
	//string getPlace();
};

#endif 
