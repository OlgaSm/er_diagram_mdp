#include "entitiefactory.h"
#include <QString>
#include "Contaner/DoubleField.h"
#include "Contaner/IntField.h"
#include "Contaner/Entitie.h"


Entitie* EntitieFactory::createEntitie(Entitie_Types t){
    Entitie* e = NULL;
    switch(t){
        case 0:
            e = new Entitie("Сущность "+QString::number(id++).toStdString());
            e->addUserField(new IntField("X",0));
            e->addUserField(new IntField("Y",0));
            e->addUserField(new IntField("W",100));
            e->addUserField(new IntField("H",100));
            e->addUserField(new IntField("F",1));
            e->addUserField(new IntField("T",-1));
            break;
        case 1:
            e = this->scf->createCar();
            break;
        case 2:
            e = this->mcf->createCar();
            break;
        case 3:
            e = this->fcf->createCar();
            break;
        case 4:
            e = this->svf->createVelo();
            break;
        case 5:
            e = this->mvf->createVelo();
            break;
        case 6:
            e = this->fvf->createVelo();
            break;
        default:
            e = new Entitie("Сущность "+QString::number(id++).toStdString());
            e->addUserField(new IntField("X",0));
            e->addUserField(new IntField("Y",0));
            e->addUserField(new IntField("W",100));
            e->addUserField(new IntField("H",100));
            e->addUserField(new IntField("F",1));
            e->addUserField(new IntField("T",-1));
    }
    DeleteFactory();
    return e;
}

EntitieFactory::EntitieFactory(){
    this->scf = new SlowCarFactory();
    this->mcf = new MediumCarFactory();
    this->fcf = new FastCarFactory();
    this->svf = new SlowVeloFactory();
    this->mvf = new MediumVeloFactory();
    this->fvf = new FastVeloFactory();
}

EntitieFactory::~EntitieFactory(){
    delete(this->scf);
    delete(this->mcf);
    delete(this->fcf);
    delete(this->svf);
    delete(this->mvf);
    delete(this->fvf);
}

EntitieFactory* EntitieFactory::entitieFactory(){
    if(factory==NULL){
        factory = new EntitieFactory();
    }
    return factory;
}

void EntitieFactory::DeleteFactory(){
    if(factory!=NULL){
        delete(factory);
        factory=NULL;
    }
}

void EntitieFactory::setGlobalId(int id0){
    id=id0;
    SlowCar::setId(id);
    MediumCar::setId(id);
    FastCar::setId(id);
    SlowVelo::setId(id);
    MediumVelo::setId(id);
    FastVelo::setId(id);
    DeleteFactory();
}

EntitieFactory* EntitieFactory::factory = NULL;
int EntitieFactory::id = 0;
