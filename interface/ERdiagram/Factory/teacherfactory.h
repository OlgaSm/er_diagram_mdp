#ifndef TEACHERFACTORY_H
#define TEACHERFACTORY_H
#include "Contaner/Entitie.h"
#include "HumanFactory.h"

class TeacherFactory : public HumanFactory 
{
public :
    TeacherFactory();
    ~TeacherFactory();
    Entitie* createHuman();
};

#endif
