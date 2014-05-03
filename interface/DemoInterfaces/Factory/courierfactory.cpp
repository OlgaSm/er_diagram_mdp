#include "courierfactory.h"
#include "Factory/courier.h"

CourierFactory::CourierFactory()
{
}

CourierFactory::~CourierFactory(){

}

Entitie* CourierFactory::createHuman(){
    return new Courier();
}
