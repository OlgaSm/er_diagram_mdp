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
protected:
    string ID;
    List<Field*>* myfield;
    List<Relation*>* myRelations;

public:
    explicit Entitie(string ID);
    virtual ~Entitie();
	
public:
    string getID();
    void setID(string ID);
	
public:
    Field* 	fieldAt(int i);
    Field* 	fieldByID(string ID);
    void    addUserField(Field* f);
    void    addIntField(int value);
    void    addDoubleField(double value);
    void    addStringField(string value);
    void    addStdField(string value);
    void    popFieldAt(int i);
    void    popFieldByID(string ID);
    int     fieldCount();
    bool    isFieldListEmpty();
	
public:	
	Relation* 	relationAt(int i);
    Relation* 	relationByID(string ID);
	void    addRelation(Relation* r);          
    void    popRelationAt(int i, bool deleteRelationAfterPoping);
    void    popRelationByID(string ID, bool deleteRelationAfterPoping);
    int     relationCount();
    bool    isRelationListEmpty();
	bool    isIDFree(string id);
};

#endif // ENTITIE_H
