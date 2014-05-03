#ifndef FASTCAR_H
#define FASTCAR_H
#include "Contaner/Entitie.h"

class FastCar: public Entitie
{
private :
    static int id;
public:
    static void setId(int id0);
    FastCar();
    ~FastCar();
    string getBrand();
    double getPower ();
};

#endif // FASTCAR_H
