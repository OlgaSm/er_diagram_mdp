#include "fastvelofactory.h"
#include "Factory/fastvelo.h"

FastVeloFactory::FastVeloFactory()
{
}

FastVeloFactory::~FastVeloFactory(){

}

Entitie* FastVeloFactory::createVelo(){
    return new FastVelo();
}
