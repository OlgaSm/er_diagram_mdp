#ifndef ENTITIEFACTORY_H
#define ENTITIEFACTORY_H
#include "Contaner/Entitie.h"
#include "Factory/slowcarfactory.h"
#include "Factory/mediumcarfactory.h"
#include "Factory/fastcarfactory.h"
#include "Factory/slowvelofactory.h"
#include "Factory/mediumvelofactory.h"
#include "Factory/fastvelofactory.h"

enum Entitie_Types{
    _Empty,
    _SlowCar,
    _MediumCar,
    _FastCar,
    _SlowVelo,
    _MediumVelo,
    _FastVelo
    // Add Humans
};


class EntitieFactory{

private:
    static int id;
    explicit EntitieFactory();
    virtual ~EntitieFactory();
    static EntitieFactory* factory;
    //===========================
    SlowCarFactory* scf;
    MediumCarFactory* mcf;
    FastCarFactory* fcf;
    SlowVeloFactory* svf;
    MediumVeloFactory* mvf;
    FastVeloFactory* fvf;
    //===========================

public:
    static EntitieFactory* entitieFactory();
    static void DeleteFactory();
    Entitie* createEntitie(Entitie_Types t);
};

#endif // ENTITIEFACTORY_H
