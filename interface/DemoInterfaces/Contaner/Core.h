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
    int focus;
    int state;
    bool changed;
    // 0 - Сущность
    // 1 - Связь
    // 2 - Выделить
    int counter;
    int counter0;
    int counter1;
    int weightOfSolution;
    List<string>* solution;
    bool focusEntitieOrRelation;

public:
    explicit Core();
	~Core();
    void saveProject(string file);
    void loadProject(string file);
    void addRelation(Relation* r);
    void addRelation(Entitie* e1, Entitie* e2, string id, string key);
    void addEntitie(string name);
    void addEntitieTo(string name, int x, int y);
    void addEntitieTo(Entitie* e);
    void popRelationAt(int n);
    void popRelationByID(string ID);
    void popEntitieAt(int n);
    void popEntitieByID(string ID);
    void setState(int state);
    void setFocus(int focus);
    void spotFocus();
    void setWeightOfSolution(int weight);
    void Changed(bool changed);
    void setFocusObj(bool feor);

    int getEntitieCount();
    int getRelationCount();
    int getCounter();
    int getCounter0();
    int getCounter1();
    int getState();
    int getFocus();
    int getIndexRelationByID(string ID);
    int getIndexEntitieByID(string ID);
    int getWeightOfSolution();
    int getSpeedOf(Entitie* e);

    Entitie* getEntitieByID(string name);
    Entitie* getEntitieAt(int n);

    Relation* getRelationByID(string name);
    Relation* getRelationAt(int n);

    List<string>* getBestWay(Entitie* e1, Entitie* e2);
    List<string>* getBestWay();
    List<string>* getListEn();

    bool getFocusObj();
    bool getBestWay(Entitie* e1, Entitie* e2, List<string>* &last, int weight);
    bool isChanged();

    double getDistanceOf(Entitie* e);
    double getDistanceBetween(Entitie* e1, Entitie* e2);
};

#endif //CORE_H
