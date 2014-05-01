//=============================================================
#include "Relation.h"
#include "Entitie.h"
//=============================================================

//=====================================
#include "DebugDefine.h"
//=====================================

string Relation::getID(){
    return this->relationID;
}

Entitie* Relation::getEntR(){
    return this->entitieR;
}

Entitie* Relation::getEntL(){
    return this->entitieL;
}

bool Relation::getMulR(){
    return this->MultiplicityR;
}

bool Relation::getMulL(){
    return this->MultiplicityL;
}

bool Relation::getAbsR(){
    return this->AbstractR;
}

bool Relation::getAbsL(){
    return this->AbstractL;
}

string Relation::getKey(){
    return this->key;
}

Relation::Relation(string relationID,
         string key,
         Entitie* entitieR,
         Entitie* entitieL,
         bool MultiplicityR,
         bool MultiplicityL,
         bool AbstractR,
         bool AbstractL){

    this->relationID = relationID;
    this->key = key;
    this->AbstractL = AbstractL;
    this->AbstractR = AbstractR;
    this->MultiplicityR = MultiplicityR;
    this->MultiplicityL = MultiplicityL;
    this->entitieL = entitieL;
    this->entitieR = entitieR;

    this->entitieL->addRelation(this);
    this->entitieR->addRelation(this);
    #ifdef DEBUGLOG_RELATION
        QFile file(LOG_PATH);
        file.open(QIODevice::Append | QIODevice::Text);
        QTextStream out(&file);
        out << "+ Relation created" << endl;
        file.close();
        //CountCreatedObject++;
    #endif
}

Relation::~Relation(){
    if(this->entitieL!=NULL){
        this->entitieL->popRelationByID(this->relationID, false);
    }
    if(this->entitieR!=NULL){
        this->entitieR->popRelationByID(this->relationID, false);
    }
    #ifdef DEBUGLOG_RELATION
        QFile file(LOG_PATH);
        file.open(QIODevice::Append | QIODevice::Text);
        QTextStream out(&file);
        out << "- Relation deleted" << endl;
        file.close();
        //CountDeltedObject++;
    #endif
}
