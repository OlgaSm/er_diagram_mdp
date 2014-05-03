#ifndef HUMANFACTORY_H
#define HUMANFACTORY_H
#include "Contaner/Entitie.h"

class HumanFactory{
public :
    HumanFactory();
    virtual ~HumanFactory();
    virtual Entitie* createHuman();
};

#endif
