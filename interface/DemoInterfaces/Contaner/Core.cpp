#include "Core.h"
#include "ERDiagram.h"
#include "Entitie.h"
#include "IntField.h"
#include "qmath.h"
#include "Relation.h"
    Core::Core(){
        this->content = new ERDiagram("Common");
        this->state = 0;
        this->focus = -1;
        this->focusEntitieOrRelation = true;
        this->counter = 0;
        this->weightOfSolution = -1;
        this->solution = NULL;
    }
    int Core::getCounter(){
        return this->counter++;
    }

//    Core::~Core(){

//    }

//    void Core::saveProject(string file){

//    }

//    void Core::loadProject(string file){

//    }

    void Core::popRelationAt(int n){
        this->content->popRelationAt(n,true);
    }

    void Core::popRelationByID(string ID){
        this->content->popRelationByID(ID,true);
    }

    void Core::popEntitieAt(int n){
        this->content->popEntitieAt(n);
    }

    void Core::popEntitieByID(string ID){
        this->content->popEntitieByID(ID);
    }

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

    void Core::addRelation(Relation* r){
        this->content->addUserRelation(r);
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
    bool Core::getBestWay(Entitie* e1, Entitie* e2, List<string>* &last, int weight){
        last->push_back(e1->getID());
        if(e1->getID()==e2->getID()){
            if(weight<this->weightOfSolution || this->weightOfSolution==-1){
                this->weightOfSolution = weight;
                if(this->solution!=NULL){
                    this->solution = new List<string>();
                }else{
                    delete(this->solution);
                    this->solution = new List<string>();
                }
                for(int i=0; i<last->size(); i++){
                    this->solution->push_back(last->at(i));
                }
            }
            last->popAt(last->size()-1);
            return true;
        }else{
            for(int i=0; i<e1->relationCount(); i++){
                Relation* r = e1->relationAt(i);
                if(r->getEntL()!=e1){
                    Entitie* el = r->getEntL();
                    bool tr=true;
                    for(int j=0; j<last->size(); j++){
                        if(last->at(j)==el->getID()){
                            tr=false;
                        }
                    }
                    if(tr){
                        if(getBestWay(el, e2, last,weight+1)){
                            //return true;
                        }
                    }
                }
                if(r->getEntR()!=e1){
                    Entitie* er = r->getEntR();
                    bool tr=true;
                    for(int j=0; j<last->size(); j++){
                        if(last->at(j)==er->getID()){
                            tr=false;
                        }
                    }
                    if(tr){
                        if(getBestWay(er, e2, last,weight+1)){
                            //return true;
                        }
                    }
                }
            }
        }
        last->popAt(last->size()-1);
        return false;
    }

    List<string>* Core::getBestWay(Entitie* e1, Entitie* e2){
           //Entitie* e1;
           //Relation* r1;
           this->weightOfSolution = -1;
           List<string>* way = new List<string>();
//           if(getBestWay(e1, e2, way, 0)){
//               return way;
//           }else{
//               return new List<string>();
//           }
           getBestWay(e1, e2, way, 0);
           if(this->solution!=NULL){
               return this->solution;
           }else{
               return new List<string>();
           }
//           int i,j;
//           i=0;
//           while (i<this->content->getEntitieCount()){
//               e1= this->content->entitieAt(i);
//               way->push_back("Сущность "+e1->getID()+"\n");
//               j=0;
//               while (j<e1->relationCount()){
//                   r1=e1->relationAt(j);
//                   j++;
//                   way->push_back("Связь R "+r1->getEntR()->getID());
//                   way->push_back("Связь L "+r1->getEntL()->getID());
//               }
//               i++;

//           };
           //return way;
      }

    List<string>* Core::getListEn(){
           Entitie* e1;
           List<string>* l = new List<string>();
           int i;
           i=0;
           while (i<this->content->getEntitieCount()){
               e1= this->content->entitieAt(i);
               l->push_back(e1->getID());
               i++;
           };
           return l;
      }

    int Core::getWeightOfSolution(){
        return this->weightOfSolution;
    }

    void Core::setWeightOfSolution(int weight){
        this->weightOfSolution=weight;
    }

    int Core::getIndexRelationByID(string ID){
        return this->content->getIndexRelationByID(ID);
    }

    int Core::getIndexEntitieByID(string ID){
        return this->content->getIndexEntitieByID(ID);
    }
