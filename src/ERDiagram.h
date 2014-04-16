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
    List<Entitie*> entities;
    List<Relation*> relations;

public:
    ERDiagram(string id);
    ~ERDiagram();

public:    
    Relation*     relationAt(int i);
    Relation*     relationByID(string id);
    void    addRelation(Relation* r);          
    void    popRelationAt(int i);

public:    
    Entitie*     entitieAt(int i);
    Entitie*     entitieByID(string id);
    void    addEntitie(Entitie* e);          
    void    popEntitieAt(int i);
};

#endif
