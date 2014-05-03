#ifndef SLOWVELO_H
#define SLOWVELO_H
#include "Contaner/Entitie.h"
#include <string>

class SlowVelo: public Entitie
{
private:
    static int id;
public:
    SlowVelo();
    ~SlowVelo();
    string getBrand();
    double getPower();
};

#endif // SLOWVELO_H
