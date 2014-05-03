#ifndef MEDIUMCAR_H
#define MEDIUMCAR_H
#include "Contaner/Entitie.h"

class MediumCar : public Entitie{
private :
    static int id;
public:
    MediumCar();
    ~MediumCar();
    static void setId(int id0);
    string getBrand();
    double getPower ();
};

#endif // MEDIUMCAR_H
