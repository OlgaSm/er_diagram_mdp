#ifndef MEDIUMVELOFACTORY_H
#define MEDIUMVELOFACTORY_H
#include "Contaner/Entitie.h"
#include "VeloFactory.h"

class MediumVeloFactory : public VeloFactory {

public:
    MediumVeloFactory();
    ~MediumVeloFactory();
    Entitie* createVelo();
};

#endif // MEDIUMVELOFACTORY_H
