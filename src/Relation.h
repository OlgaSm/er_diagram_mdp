class Relation {
private:
	char* fieldID;
	Entitie* entitieR;
	Entitie* entitieL;
	bool MultiplicityR;
	bool MultiplicityL;
	
public:
	Relation(char* fieldID, Entitie* entitieR, Entitie* entitieL, bool MultiplicityR, bool MultiplicityL);
	~Relation();
};
