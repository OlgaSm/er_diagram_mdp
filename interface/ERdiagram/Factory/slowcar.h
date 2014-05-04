#ifndef SLOWCAR_H
#define SLOWCAR_H
#include "Contaner/Entitie.h"
#include <string>

class SlowCar: public Entitie
{
private:
    static int id;
public:
    SlowCar();
    ~SlowCar();
    static void setId(int id0);
    string getBrand();
    double getPower();
};

#endif // SLOWCAR_H
