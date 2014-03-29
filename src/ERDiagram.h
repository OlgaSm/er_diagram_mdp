class ERDiagram {
private:
	char* ID;
	List<Entitie*> entities;
	List<Relation*> relations;

public:
	ERDiagram();
	~ERDiagram();
	
public:	
	Relation* 	relationAt(int i);
	Relation* 	relationByID(char* ID);
	void    addRelation(Relation* r);          
	void    popRelationAt(int i);
	
public:	
	Entitie* 	entitieAt(int i);
	Entitie* 	entitieByID(char* ID);
	void    addEntitie(Entitie* e);          
	void    popEntitieAt(int i);
};
