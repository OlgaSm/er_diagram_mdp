#ifndef SLOWCARFACTORY_H
#define SLOWCARFACTORY_H
#include "Contaner/Entitie.h"
#include "CarFactory.h"

class SlowCarFactory: public CarFactory{
public:
    SlowCarFactory();
    virtual ~SlowCarFactory();
    Entitie* createCar();
};

#endif // SLOWCARFACTORY_H

