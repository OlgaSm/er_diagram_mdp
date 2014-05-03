#include "fastcarfactory.h"
#include "Factory/fastcar.h"

FastCarFactory::FastCarFactory()
{
}

FastCarFactory::~FastCarFactory(){

}

Entitie* FastCarFactory::createCar(){
    return new FastCar();
}
