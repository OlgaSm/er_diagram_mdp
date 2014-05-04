#ifndef ENTITIEFACTORY_H
#define ENTITIEFACTORY_H
#include "Contaner/Entitie.h"
#include "Factory/slowcarfactory.h"
#include "Factory/mediumcarfactory.h"
#include "Factory/fastcarfactory.h"
#include "Factory/slowvelofactory.h"
#include "Factory/mediumvelofactory.h"
#include "Factory/fastvelofactory.h"
#include "Factory/HumanFactory.h"
#include "Factory/courierfactory.h"
#include "Factory/schoolboyfactory.h"
#include "Factory/studentfactory.h"
#include "Factory/teacherfactory.h"
#include "Factory/courier.h"
#include "Factory/schoolboy.h"
#include "Factory/student.h"
#include "Factory/teacher.h"
#include "Factory/slowcar.h"
#include "Factory/mediumcar.h"
#include "Factory/fastcar.h"
#include "Factory/slowvelo.h"
#include "Factory/mediumvelo.h"
#include "Factory/fastvelo.h"

enum Entitie_Types{
    _Empty,
    _SlowCar,
    _MediumCar,
    _FastCar,
    _SlowVelo,
    _MediumVelo,
    _FastVelo,
    _SchoolBoy,
    _Student,
    _Teacher,
    _Courier
};


class EntitieFactory{

private:
    static int id;
    explicit EntitieFactory();
    virtual ~EntitieFactory();
    static EntitieFactory* factory;
    //===========================
    SlowCarFactory* scf;
    MediumCarFactory* mcf;
    FastCarFactory* fcf;
    SlowVeloFactory* svf;
    MediumVeloFactory* mvf;
    FastVeloFactory* fvf;
    SchoolboyFactory* sbf;
    TeacherFactory* tf;
    StudentFactory* sf;
    CourierFactory* cf;
    //===========================

public:
    static EntitieFactory* entitieFactory();
    static void setGlobalId(int id0);
    static void DeleteFactory();
    Entitie* createEntitie(Entitie_Types t);
};

#endif // ENTITIEFACTORY_H
