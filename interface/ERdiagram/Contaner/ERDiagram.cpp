#include "ERDiagram.h"
#include "Entitie.h"
#include "Relation.h"

//=====================================
#include "DebugDefine.h"
//=====================================

ERDiagram::ERDiagram (string id){
	this->ID = id;
    this->entities = new List<Entitie*>();
	this->relations = new List<Relation*>();
    #ifdef DEBUGLOG_ERD
        QFile file(LOG_PATH);
        file.open(QIODevice::Append | QIODevice::Text);
        QTextStream out(&file);
        out << "+ ERD created" << endl;
        file.close();
        //CountCreatedObject++;
    #endif
}

ERDiagram::~ERDiagram () {
    for(int i=0; i<this->relations->size(); i++){
        delete(relations->at(i));
    }
    for(int i=0; i<this->entities->size(); i++){
        delete(entities->at(i));
    }
    delete(entities);
    delete(relations);
    #ifdef DEBUGLOG_ERD
        QFile file(LOG_PATH);
        file.open(QIODevice::Append | QIODevice::Text);
        QTextStream out(&file);
        out << "- ERD deleted" << endl;
        file.close();
        //CountDeltedObject++;
    #endif
}

Relation* ERDiagram::relationAt (int i) 
{
    return this->relations->at(i);
}

Relation* ERDiagram::relationByID (string id) 
{
	for (int i=0; i<this->relations->size(); i++){
		if(this->relations->at(i)->getID()==id)
		{	return this->relations->at(i);	}
	}
	return NULL;
}

void    ERDiagram::popEntitieByID(string ID){
    for (int i=0; i<this->entities->size(); i++){
        if(this->entities->at(i)->getID()==ID){
            Entitie* e = this->entitieAt(i);
            List<Relation*>* del = new List<Relation*>();
            for(int j=0; j< e->relationCount(); j++){
                del->push_back(e->relationAt(j));
                this->popRelationByID(e->relationAt(j)->getID(),false);
            }
            for(int j=0; j< del->size(); j++){
                delete(del->at(j));
            }
            delete(this->entities->at(i));
            this->entities->popAt(i);
        }
    }
}

void    ERDiagram::popRelationByID(string ID, bool del){
    for (int i=0; i<this->relations->size(); i++){
        Relation* r = this->relations->at(i);
        if(r->getID()==ID){
            if(del){ delete(r); }
            this->relations->popAt(i);
            break;
        }
    }
}

void ERDiagram::addUserRelation (Relation* r){
	this->relations->push_back(r);
}

void ERDiagram::popRelationAt (int i, bool del){
    if(del){delete(this->relations->at(i));}
	this->relations->popAt(i);
}

Entitie* ERDiagram::entitieAt (int i) {
    return this->entities->at(i);
}

Entitie* ERDiagram::entitieByID (string id) {
	for (int i=0; i<this->entities->size(); i++){
        if(this->entities->at(i)->getID()==id){
            return this->entities->at(i);
        }
	}
	return NULL;
}

void ERDiagram::addUserEntitie (Entitie* e){
	this->entities->push_back(e);
}

void ERDiagram::popEntitieAt (int i){
    Entitie* e = this->entitieAt(i);
    List<Relation*>* del = new List<Relation*>();
    for(int j=0; j< e->relationCount(); j++){
        del->push_back(e->relationAt(j));
        this->popRelationByID(e->relationAt(j)->getID(),false);
    }
    for(int j=0; j< del->size(); j++){
        delete(del->at(j));
    }
    delete(del);
	delete(this->entities->at(i));
	this->entities->popAt(i);
}

void    ERDiagram::addRelation(string fieldID, string key, Entitie* entitieR, Entitie* entitieL, bool MultiplicityR, bool MultiplicityL, bool AbstractR, bool AbstractL){
    this->relations->push_back(new Relation(fieldID, key, entitieR, entitieL, MultiplicityR, MultiplicityL, AbstractR, AbstractL));
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

int ERDiagram::getIndexRelationByID(string ID){
    for(int i=0; i<this->getRelationCount(); i++){
        if(this->relationAt(i)->getID()==ID){
            return i;
        }
    }
    return 0;
}

int ERDiagram::getIndexEntitieByID(string ID){
    for(int i=0; i<this->getEntitieCount(); i++){
        if(this->entitieAt(i)->getID()==ID){
            return i;
        }
    }
    return 0;
}
