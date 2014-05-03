#ifndef MEDIUMCARFACTORY_H
#define MEDIUMCARFACTORY_H
#include "Contaner/Entitie.h"
#include "CarFactory.h"

class MediumCarFactory : public CarFactory {

public:
    MediumCarFactory();
    ~MediumCarFactory();
    Entitie* createCar ();
};

#endif // MEDIUMCARFACTORY_H
