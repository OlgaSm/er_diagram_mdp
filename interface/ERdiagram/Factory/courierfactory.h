#ifndef COURIERFACTORY_H
#define COURIERFACTORY_H
#include "Contaner/Entitie.h"
#include "HumanFactory.h"

class CourierFactory : public HumanFactory 
{
public :
    CourierFactory();
    ~CourierFactory();
    Entitie* createHuman();
};

#endif
