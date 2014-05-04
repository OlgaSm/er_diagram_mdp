#ifndef FASTCARFACTORY_H
#define FASTCARFACTORY_H
#include "Contaner/Entitie.h"
#include "CarFactory.h"

class FastCarFactory : public CarFactory {
public :
    FastCarFactory();
    ~FastCarFactory();
    Entitie* createCar();
};

#endif // FASTCARFACTORY_H
