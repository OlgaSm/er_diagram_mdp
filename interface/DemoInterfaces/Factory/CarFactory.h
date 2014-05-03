#ifndef CARFACTORY_H
#define CARFACTORY_H
#include "Contaner/Entitie.h"

class CarFactory{
public :
    CarFactory();
    virtual ~CarFactory();
    virtual Entitie* createCar();
};

#endif
