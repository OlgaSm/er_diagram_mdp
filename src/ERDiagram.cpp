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
}

Relation* ERDiagram::relationAt (int i) 
{
	return = this->relations->at(i);
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

void ERDiagram::addRelation (Relation* r)
{
	this->relations->push_back(r);
}

void ERDiagram::popRelationAt (int i)
{
	this->relations->popAt(i);
}

Entitie* ERDiagram::entitieAt (int i) 
{
	return = this->entities->at(i);
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

void ERDiagram::addEntitie (entitie* e)
{
	this->entities->push_back(e);
}

void ERDiagram::popEntitieAt (int i)
{
	this->entities->popAt(i);
}
