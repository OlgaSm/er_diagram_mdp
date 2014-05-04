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
    static void setId(int id0);
    string getBrand();
    double getPower();
};

#endif // SLOWVELO_H
