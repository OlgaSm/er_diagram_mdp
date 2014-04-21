#ifndef CORE_H
#define CORE_H

#include <string>
#include "List.h"

using namespace std;
class ERDiagram;
class Entitie;
class Relation;

class Core {
private:
	ERDiagram* content;
	
public:
	Core();
	~Core();
    void saveProject(string file);
    void loadProject(string file);
	void addRelation(Entitie* e1, Entitie* e2);
    void addEntitie(string name);
    int getEntitieCount();
    int getRelationCount();
    Entitie* getEntitieByID(string name);
    Relation* getRelationByID(string name);
    Entitie* getEntitieAt(int n);
    Relation* getRelationAt(int n);
    List<string>* getBestWay(Entitie* e1, Entitie* e2);
};

#endif //CORE_H
