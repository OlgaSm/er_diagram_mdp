#ifndef FASTVELO_H
#define FASTVELO_H
#include "Contaner/Entitie.h"

class FastVelo: public Entitie
{
private :
    static int id;
public:
    FastVelo();
    ~FastVelo();
    string getBrand();
    double getPower ();
};

#endif // FASTVELO_H
