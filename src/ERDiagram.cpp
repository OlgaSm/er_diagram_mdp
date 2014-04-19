#include "ERDiagram.h"
#include "Entitie.h"
#include "Relation.h"

ERDiagram::ERDiagram (string id) 
{
	this->ID = id;
    this->entities = new List<Entitie*>();
	this->relations = new List<Relation*>();
}

ERDiagram::~ERDiagram () 
{
	for(int i=0; i<this->entities->size(); i++){
		delete(entities->at(i));
    }
	for(int i=0; i<this->relations->size(); i++){
		delete(relations->at(i));
    }
	delete(entities);
	delete(relations);
}

Relation* ERDiagram::relationAt (int i) 
{
    return this->relations->at(i);
}

Relation* ERDiagram::relationByID (string id) 
{
	for (int i=0; i<this->relations->size(); i++)
	{
		if(this->relations->at(i)->getID()==id)
		{	return this->relations->at(i);	}
	}
	return NULL;
}

void ERDiagram::addUserRelation (Relation* r)
{
	this->relations->push_back(r);
}

void ERDiagram::popRelationAt (int i)
{
	delete(this->relations->at(i));
	this->relations->popAt(i);
}

Entitie* ERDiagram::entitieAt (int i) 
{
    return this->entities->at(i);
}

Entitie* ERDiagram::entitieByID (string id) 
{
	for (int i=0; i<this->entities->size(); i++)
	{
		if(this->entities->at(i)->getID()==id)
		{	return this->entities->at(i);	}
	}
	return NULL;
}

void ERDiagram::addUserEntitie (Entitie* e)
{
	this->entities->push_back(e);
}

void ERDiagram::popEntitieAt (int i)
{
	delete(this->entities->at(i));
	this->entities->popAt(i);
}

void    ERDiagram::addRelation(string fieldID, Entitie* entitieR, Entitie* entitieL, bool MultiplicityR, bool MultiplicityL, bool AbstractR, bool AbstractL){
    this->relations->push_back(new Relation(fieldID, entitieR, entitieL, MultiplicityR, MultiplicityL, AbstractR, AbstractL));
}

void    ERDiagram::addEntitie(string ID){
	this->entities->push_back(new Entitie(ID));
}

int ERDiagram::getEntitieCount(){
    return this->entities->size();
}

int ERDiagram::getRelationCount(){
    return this->relations->size();
}
