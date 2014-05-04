#include "Factory/slowvelofactory.h"
#include "Factory/slowvelo.h"

SlowVeloFactory::SlowVeloFactory(){

}

SlowVeloFactory::~SlowVeloFactory(){

}

Entitie* SlowVeloFactory::createVelo(){
    return new SlowVelo();
}
