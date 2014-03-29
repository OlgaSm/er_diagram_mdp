class Core {
private:
	ERDiagram* content;
	
public:
	Core();
	~Core();
	void saveProject(char* file);
	void loadProject(char* file);
	void addRelation(Entitie* e1, Entitie* e2);
	void addEntitie(char* name);
	Entitie* getEntitieByID(char* name);
	Relation* getRelationByID(char* name);
	List<char*>* getBestWay(Entitie* e1, Entitie* e2);
};
