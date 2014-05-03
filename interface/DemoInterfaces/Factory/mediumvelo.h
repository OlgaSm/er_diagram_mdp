#ifndef MEDIUMVELO_H
#define MEDIUMVELO_H
#include "Contaner/Entitie.h"

class MediumVelo : public Entitie{
private :
    static int id;
public:
    MediumVelo();
    ~MediumVelo();
    string getBrand();
    double getPower ();
};

#endif // MEDIUMVELO_H
