#include "Factory/slowcarfactory.h"
#include "Factory/slowcar.h"

SlowCarFactory::SlowCarFactory(){

}

SlowCarFactory::~SlowCarFactory(){

}

Entitie* SlowCarFactory::createCar(){
    return new SlowCar();
}
