#ifndef FASTCAR_H
#define FASTCAR_H
#include "Contaner/Entitie.h"

class FastCar: public Entitie
{
private :
    static int id;
public:
    FastCar();
    ~FastCar();
    string getBrand();
    double getPower ();
};

#endif // FASTCAR_H
