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
    Field* 	fieldAt(int i);
    Field* 	fieldByID(string ID);
    void    addField(Field* f);
    void    popFieldAt(int i);
    void    popFieldByID(string ID);
    int     fieldCount();
    bool    isFieldListEmpty();
	
public:	
	Relation* 	relationAt(int i);
    Relation* 	relationByID(string ID);
	void    addRelation(Relation* r);          
    void    popRelationAt(int i);
    void    popRelationByID(string ID);
    int     relationCount();
    bool    isRelationListEmpty();
};

#endif // ENTITIE_H
