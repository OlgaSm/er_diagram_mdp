#include "mediumcarfactory.h"
#include "Factory/mediumcar.h"

MediumCarFactory::MediumCarFactory()
{
}

MediumCarFactory::~MediumCarFactory(){

}

Entitie* MediumCarFactory::createCar (){
    return new MediumCar();
}
