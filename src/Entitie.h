#ifndef ENTITIE_H
#define ENTITIE_H

//=====================================================
#include "List.h"
//#include "Fild.h"
//#include "Relation.h"
//=====================================================
class Relation;
class Feild;

class Entitie {
private:
    char* ID;
    List<Feild*> field;
	List<Relation*> myRelations;

public:
	Entitie();
	~Entitie();	
	
public:
	char* getID();
	void setID(char* ID);
	
public:
	Feild* 	fildAt(int i);
	Feild* 	fildByID(char* ID);
	void    addFild(Feild* f);          
	void    popFildAt(int i);
	
public:	
	Relation* 	relationAt(int i);
	Relation* 	relationByID(char* ID);
	void    addRelation(Relation* r);          
	void    popRelationAt(int i);
};

#endif // ENTITIE_H
