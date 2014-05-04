#ifndef SLOWVELOFACTORY_H
#define SLOWVELOFACTORY_H
#include "Contaner/Entitie.h"
#include "VeloFactory.h"

class SlowVeloFactory: public VeloFactory{
public:
    SlowVeloFactory();
    virtual ~SlowVeloFactory();
    Entitie* createVelo();
};

#endif // SLOWVELOFACTORY_H

