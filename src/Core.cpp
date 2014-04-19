#include "Core.h"
#include "ERDiagram.h"

    Core::Core(){
        this->content = new ERDiagram("Common");
    }

//    Core::~Core(){

//    }

//    void Core::saveProject(string file){

//    }

//    void Core::loadProject(string file){

//    }

//    void Core::addRelation(Entitie* e1, Entitie* e2){

//    }

    void Core::addEntitie(string name){
        this->content->addEntitie(name);
    }

    Entitie* Core::getEntitieByID(string name){
        return this->content->entitieByID(name);
    }

    Relation* Core::getRelationByID(string name){
        return this->content->relationByID(name);
    }

    Entitie* Core::getEntitieAt(int n){
        return this->content->entitieAt(n);
    }

    Relation* Core::getRelationAt(int n){
        return this->content->relationAt(n);
    }

    int Core::getEntitieCount(){
        return this->content->getEntitieCount();
    }

    int Core::getRelationCount(){
        return this->content->getRelationCount();
    }

//    List<string>* Core::getBestWay(Entitie* e1, Entitie* e2){
//        return NULL;
//    }
