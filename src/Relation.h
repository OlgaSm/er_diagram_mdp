#ifndef RELATION_H
#define RELATION_H

//=============================================================
#include <string>
//=============================================================
using namespace std;

class Entitie;

class Relation {
private:
    string relationID;
    Entitie* entitieR;
    Entitie* entitieL;
	bool MultiplicityR;
	bool MultiplicityL;
    bool AbstractR;
    bool AbstractL;
	
public:
    string getID();
    Entitie* getEntR();
    Entitie* getEntL();
    bool getMulR();
    bool getMulL();
    bool getAbsR();
    bool getAbsL();
    Relation(string fieldID,
             Entitie* entitieR,
             Entitie* entitieL,
             bool MultiplicityR,
             bool MultiplicityL,
             bool AbstractR,
             bool AbstractL);
	~Relation();
};

#endif // RELATION_H
