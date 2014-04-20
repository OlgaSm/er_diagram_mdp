#ifndef ERDIAGRAM_H
#define ERDIAGRAM_H

#include <string>
#include "List.h"

using namespace std;

class Entitie;
class Relation;

class ERDiagram 
{
private:
    string ID;
    List<Entitie*>* entities;
    List<Relation*>* relations;

public:
    ERDiagram(string id);
    ~ERDiagram();

public:    
    Relation*     relationAt(int i);
    Relation*     relationByID(string id);
    int     getRelationCount();
    void    addUserRelation(Relation* r);   
	void    addRelation(string fieldID,
                        string key,
						Entitie* entitieR,
						Entitie* entitieL,
						bool MultiplicityR,
						bool MultiplicityL,
						bool AbstractR,
						bool AbstractL);  	
    void    popRelationAt(int i, bool del);
    void    popRelationByID(string ID, bool del);

public:
    int          getEntitieCount();
    Entitie*     entitieAt(int i);
    Entitie*     entitieByID(string id);
    void    addUserEntitie(Entitie* e);   
	void    addEntitie(string ID);
    void    popEntitieAt(int i);
    void    popEntitieByID(string ID);
};

#endif
