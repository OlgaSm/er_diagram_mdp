#ifndef RELATION_H
#define RELATION_H

//=============================================================
//#include "includs.h"
//#include "Entitie.h"
//=============================================================

class Entitie;

class Relation {
private:
    char* relationID;
    Entitie* entitieR;
    Entitie* entitieL;
	bool MultiplicityR;
	bool MultiplicityL;
    bool AbstractR;
    bool AbstractL;
	
public:
    char* getID();
    Entitie* getEntR();
    Entitie* getEntL();
    bool getMulR();
    bool getMulL();
    bool getAbsR();
    bool getAbsL();
    Relation(char* fieldID,
             Entitie* entitieR,
             Entitie* entitieL,
             bool MultiplicityR,
             bool MultiplicityL,
             bool AbstractR,
             bool AbstractL);
	~Relation();
};

#endif // RELATION_H
