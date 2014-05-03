#ifndef STUDENTFACTORY_H
#define STUDENTFACTORY_H
#include "Contaner/Entitie.h"
#include "HumanFactory.h"

class StudentFactory : public HumanFactory 
{
public :
    StudentFactory();
    ~StudentFactory();
    Entitie* createHuman();
};

#endif
