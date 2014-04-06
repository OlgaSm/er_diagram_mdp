#ifndef ENTITIE_H
#define ENTITIE_H

namespace ERdiagram{

class Entitie {
private:
	char* ID;
	List<Fild*> field;
	List<Relation*> myRelations;

public:
	Entitie();
	~Entitie();	
	
public:
	char* getID();
	void setID(char* ID);
	
public:
	Fild* 	fildAt(int i);
	Fild* 	fildByID(char* ID);
	void    addFild(Fild* f);          
	void    popFildAt(int i);
	
public:	
	Relation* 	relationAt(int i);
	Relation* 	relationByID(char* ID);
	void    addRelation(Relation* r);          
	void    popRelationAt(int i);
};

}
#endif // ENTITIE_H
