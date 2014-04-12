#ifndef ENTITIE_H
#define ENTITIE_H

//=====================================================
#include <string>
#include "List.h"
//=====================================================
using namespace std;

class Relation;
class Field;

class Entitie {
private:
    string ID;
    List<Field*>* myfield;
    List<Relation*>* myRelations;

public:
    Entitie(string ID);
	~Entitie();	
	
public:
    string getID();
    void setID(string ID);
	
public:
    Field* 	fildAt(int i);
    Field* 	fildByID(string ID);
    void    addFild(Field* f);
	void    popFildAt(int i);
	
public:	
	Relation* 	relationAt(int i);
    Relation* 	relationByID(string ID);
	void    addRelation(Relation* r);          
	void    popRelationAt(int i);
};

#endif // ENTITIE_H
