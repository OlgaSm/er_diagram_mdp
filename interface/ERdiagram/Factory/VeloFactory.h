#ifndef VELOFACTORY_H
#define VELOFACTORY_H
#include "Contaner/Entitie.h"

class VeloFactory{
public :
    VeloFactory();
    virtual ~VeloFactory();
    virtual Entitie* createVelo();
};

#endif
