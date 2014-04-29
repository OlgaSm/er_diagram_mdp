#ifndef ENTITIE_H
#define ENTITIE_H

//=====================================================
#include <string>
#include "List.h"
//=====================================================
using namespace std;

class Relation;
class Field;
class IntField;
class DoubleField;
class StringField;

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
};

#endif // ENTITIE_H
