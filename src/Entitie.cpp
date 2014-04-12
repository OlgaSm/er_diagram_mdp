#include "Entitie.h"

//=====================================================
#include "Field.h"
#include "Relation.h"
//=====================================================

Entitie::Entitie(string ID){
    this->ID = ID;
    this->myfield = new List<Field*>();
    this->myRelations = new List<Relation*>();
}

Entitie::~Entitie(){

}

string Entitie::getID(){
    return this->ID;
}

void Entitie::setID(string ID){
    this->ID = ID;
}

Field* 	Entitie::fildAt(int i){
    return this->myfield->at(i);
}

Field* 	Entitie::fildByID(string ID){
    for(int i=0; i<this->myfield->size(); i++){
        if(this->myfield->at(i)->getID()==ID){
            return this->myfield->at(i);
        }
    }
    return NULL;
}

void    Entitie::addFild(Field* f){
    this->myfield->push_back(f);
}

void    Entitie::popFildAt(int i){
    this->myfield->popAt(i);
}

Relation* 	Entitie::relationAt(int i){
    return this->myRelations->at(i);
}

Relation* 	Entitie::relationByID(string ID){
    for(int i=0; i<this->myRelations->size(); i++){
        if(this->myRelations->at(i)->getID()==ID){
            return this->myRelations->at(i);
        }
    }
    return NULL;
}

void    Entitie::addRelation(Relation* r){
    this->myRelations->push_back(r);
}

void    Entitie::popRelationAt(int i){
    this->myRelations->popAt(i);
}
