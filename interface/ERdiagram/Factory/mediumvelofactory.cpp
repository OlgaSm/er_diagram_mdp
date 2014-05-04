#include "mediumvelofactory.h"
#include "Factory/mediumvelo.h"

MediumVeloFactory::MediumVeloFactory()
{
}

MediumVeloFactory::~MediumVeloFactory(){
}

Entitie* MediumVeloFactory::createVelo (){
    return new MediumVelo();
}
