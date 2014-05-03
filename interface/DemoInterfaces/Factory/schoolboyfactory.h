#ifndef SCHOOLBOYFACTORY_H
#define SCHOOLBOYFACTORY_H
#include "Contaner/Entitie.h"
#include "HumanFactory.h"

class SchoolboyFactory : public HumanFactory 
{
public :
    SchoolboyFactory();
    ~SchoolboyFactory();
    Entitie* createHuman();
};

#endif
