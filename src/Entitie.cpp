#include "Entitie.h"

//=====================================================
#include "Field.h"
#include "IntField.h"
#include "DoubleField.h"
#include "StringField.h"
#include "Relation.h"
//=====================================================

Entitie::Entitie(string ID){
   	this->ID = ID;
	this->myfield = new List<Field*>();
	this->myRelations = new List<Relation*>();
}

Entitie::~Entitie(){
    for(int i=0; i<this->myfield->size(); i++){
        delete(myfield->at(i));
    }
    for(int i=0; i<this->myRelations->size(); i++){
        delete(this->myRelations->at(i));
        this->myRelations->popAt(i);

    }
    delete(myfield);
    delete(myRelations);
}

string Entitie::getID(){
    return this->ID;
}

void Entitie::setID(string ID){
    this->ID = ID;
}

bool Entitie::isIDFree (string id)
{
	for(int i=0; i<this->myfield->size(); i++)
	{
		if (myfield->at(i)->getID() == id)
			return false;
	}
	return true;
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

void    Entitie::addUserField(Field* f){
	if (isIDFree())
		this->myfield->push_back(f);
	//else
}

void    Entitie::addIntField(int value){
    this->myfield->push_back(new IntField("StandartInt",value));
}

void    Entitie::addDoubleField(double value){
    this->myfield->push_back(new DoubleField("StandartDouble",value));
}

void    Entitie::addStringField(string value){
    this->myfield->push_back(new StringField("StandartString",value));
}

void    Entitie::addStdField(string value){
    this->myfield->push_back(new Field(value));
}

void    Entitie::popFieldAt(int i){
	delete(this->myfield->at(i));
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

void    Entitie::popRelationAt(int i, bool deleteRelationAfterPoping){
    this->myRelations->popAt(i);
    if(deleteRelationAfterPoping){ delete(this->myRelations->at(i)); }
}

void    Entitie::popRelationByID(string ID, bool deleteRelationAfterPoping){
    bool stop = false;
    for(int i=0; i<this->myRelations->size() && stop==false; i++){
        if(this->myRelations->at(i)->getID()==ID){
            if(deleteRelationAfterPoping){ delete(this->myRelations->at(i)); }
            this->myRelations->popAt(i);
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
