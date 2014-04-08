//=============================================================
#include "Relation.h"
//=============================================================
char* Relation::getID(){
    return this->relationID;
}

Entitie* Relation::getEntR(){
    return this->entitieR;
}

Entitie* Relation::getEntL(){
    return this->entitieL;
}

bool Relation::getMulR(){
    return this->MultiplicityR;
}

bool Relation::getMulL(){
    return this->MultiplicityL;
}

bool Relation::getAbsR(){
    return this->AbstractL;
}

bool Relation::getAbsL(){
    return this->AbstractL;
}

Relation::Relation(char* relationID,
         Entitie* entitieR,
         Entitie* entitieL,
         bool MultiplicityR,
         bool MultiplicityL,
         bool AbstractR,
         bool AbstractL){

    this->relationID = relationID;
    this->AbstractL = AbstractL;
    this->AbstractR = AbstractR;
    this->MultiplicityR = MultiplicityR;
    this->MultiplicityL = MultiplicityL;
    this->entitieL = entitieL;
    this->entitieR = entitieR;
}

Relation::~Relation(){

}
