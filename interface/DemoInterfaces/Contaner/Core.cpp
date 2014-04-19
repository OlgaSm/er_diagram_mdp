#include "Core.h"
#include "ERDiagram.h"
#include "Entitie.h"
#include "IntField.h"
#include "qmath.h"

    Core::Core(){
        this->content = new ERDiagram("Common");
        this->state = 0;
        this->focus = -1;
        this->focusEntitieOrRelation = true;
    }

//    Core::~Core(){

//    }

//    void Core::saveProject(string file){

//    }

//    void Core::loadProject(string file){

//    }

    void Core::addRelation(Entitie* e1, Entitie* e2, string id, string key){
        this->content->addRelation(id,key,e1,e2,false,false,false,false);
    }

    void Core::addEntitie(string name){
        Entitie* e = new Entitie(name);
        e->addUserField(new IntField("X",qrand()%1000));
        e->addUserField(new IntField("Y",qrand()%1000));
        e->addUserField(new IntField("W",100));
        e->addUserField(new IntField("H",100));
        e->addUserField(new IntField("F",1));
        this->content->addUserEntitie(e);
    }

    void Core::addEntitieTo(string name, int x, int y){
        Entitie* e = new Entitie(name);
        e->addUserField(new IntField("X",x));
        e->addUserField(new IntField("Y",y));
        e->addUserField(new IntField("W",100));
        e->addUserField(new IntField("H",100));
        e->addUserField(new IntField("F",1));
        this->content->addUserEntitie(e);
    }

    void Core::addEntitieTo(Entitie* e){
        this->content->addUserEntitie(e);
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

    int Core::getState(){
        return this->state;
    }

    void Core::setState(int state){
        this->state=state;
    }

    int Core::getFocus(){
        return this->focus;
    }

    void Core::spotFocus(){
        if(this->focusEntitieOrRelation){
            for(int i=0; i<this->content->getEntitieCount(); i++){
                if(this->focus!=i){
                    ((IntField*)(this->content->entitieAt(i)->fieldByID("F")))->setValue(0);
                }else{
                    ((IntField*)(this->content->entitieAt(i)->fieldByID("F")))->setValue(1);
                }
            }
        }else{
            for(int i=0; i<this->content->getEntitieCount(); i++){
                ((IntField*)(this->content->entitieAt(i)->fieldByID("F")))->setValue(0);
            }
        }
    }

    void Core::setFocus(int focus){
        this->focus=focus;
        spotFocus();
    }

    bool Core::getFocusObj(){
        return this->focusEntitieOrRelation;
    }

    void Core::setFocusObj(bool feor){
        this->focusEntitieOrRelation = feor;
    }

//    List<string>* Core::getBestWay(Entitie* e1, Entitie* e2){
//        return NULL;
//    }
