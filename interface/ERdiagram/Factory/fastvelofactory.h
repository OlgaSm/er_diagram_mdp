#ifndef FASTVELOFACTORY_H
#define FASTVELOFACTORY_H
#include "Contaner/Entitie.h"
#include "VeloFactory.h"

class FastVeloFactory : public VeloFactory {
public :
    FastVeloFactory();
    ~FastVeloFactory();
    Entitie* createVelo();
};

#endif // FASTVELOFACTORY_H
