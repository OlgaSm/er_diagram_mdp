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
    delete(myfield);
    delete(myRelations);
}

string Entitie::getID(){
    return this->ID;
}

void Entitie::setID(string ID){
    this->ID = ID;
}

Field* 	Entitie::fieldAt(int i){
    return this->myfield->at(i);
}

Field* 	Entitie::fieldByID(string ID){
    for(int i=0; i<this->myfield->size(); i++){
        if(this->myfield->at(i)->getID()==ID){
            return this->myfield->at(i);
        }
    }
    return NULL;
}

void    Entitie::addField(Field* f){
    this->myfield->push_back(f);
}

void    Entitie::popFieldAt(int i){
    this->myfield->popAt(i);
}

void    Entitie::popFieldByID(string ID){
    bool stop = false;
    for(int i=0; i<this->myfield->size()&& stop==false; i++){
        if(this->myfield->at(i)->getID()==ID){
            this->popFieldAt(i);
            stop=true;
        }
    }
}

int Entitie::fieldCount(){
    return this->myfield->size();
}

bool Entitie::isFieldListEmpty(){
    if(this->fieldCount()>0){
        return false;
    }else{
        return true;
    }
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

void    Entitie::popRelationByID(string ID){
    bool stop = false;
    for(int i=0; i<this->myRelations->size() && stop==false; i++){
        if(this->myRelations->at(i)->getID()==ID){
            this->popRelationAt(i);
            stop=true;
        }
    }
}

int Entitie::relationCount(){
    return this->myRelations->size();
}

bool Entitie::isRelationListEmpty(){
    if(this->relationCount()>0){
        return false;
    }else{
        return true;
    }
}
