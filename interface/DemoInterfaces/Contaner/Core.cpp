#include "Core.h"
#include "ERDiagram.h"
#include "Entitie.h"
#include "IntField.h"
#include "DoubleField.h"
#include "qmath.h"
#include "Relation.h"

//=====================================
#include "DebugDefine.h"
//=====================================

    Core::Core(){
        this->content = new ERDiagram("Common");
        this->state = 2;
        this->focus = -1;
        this->focusEntitieOrRelation = true;
        this->counter = 0;
        this->counter0 = 0;
        this->counter1 = 0;
        this->weightOfSolution = -1;
        this->solution = NULL;
        this->changed = false;
        #ifdef DEBUGLOG_CORE
            QFile file(LOG_PATH);
            file.open(QIODevice::Append | QIODevice::Text);
            QTextStream out(&file);
            out << "+ Core created" << endl;
            file.close();
            //CountCreatedObject++;
        #endif
    }

    int Core::getCounter(){
        return this->counter++;
    }

    int Core::getCounter0(){
        return this->counter0++;
    }

    int Core::getCounter1(){
        return this->counter1++;
    }

    Core::~Core(){
        #ifdef DEBUGLOG_CORE
            QFile file(LOG_PATH);
            file.open(QIODevice::Append | QIODevice::Text);
            QTextStream out(&file);
            out << "- Core deleted" << endl;
            file.close();
            //CountDeltedObject++;
        #endif
        delete(this->solution);
        delete(this->content);
    }


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
        bool add = true;
        for(int i=0; i<e1->relationCount(); i++){
           Relation* r = e1->relationAt(i);
           if(r->getEntL()== e2 || r->getEntR()== e2){
               add = false;
           }
        }
        if(add){
            this->content->addRelation(id,key,e1,e2,false,false,false,false);
        }
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

    List<string>* Core::getBestWay(){
        return this->solution;
    }
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
            int speed = this->getSpeedOf(e1);
            double distance = this->getDistanceOf(e1);
            int addWeight = 1;
            int subWeight = 0;
            for(int i=0; i<e1->relationCount(); i++){
                Relation* r = e1->relationAt(i);
                if(r->getEntL()!=e1){
                    Entitie* el = r->getEntL();
                    if(r->getAbsL()){
                        addWeight+=2;
                    }
                    if(r->getMulL()){
                        subWeight+=1;
                    }
                    int t = ((IntField*)el->fieldByID("T"))->getValue();
                    double dist = getDistanceBetween(e1, el);
                    if(t!=1 && dist<=(distance + this->getDistanceOf(el))){
                        bool tr=true;
                        for(int j=0; j<last->size(); j++){
                            if(last->at(j)==el->getID()){
                                tr=false;
                            }
                        }
                        if(tr){
                            getBestWay(el, e2, last,(weight+1+dist/speed)*addWeight-subWeight);
                        }
                    }
                }
                if(r->getEntR()!=e1){
                    Entitie* er = r->getEntR();
                    if(r->getAbsR()){
                        addWeight+=2;
                    }
                    if(r->getMulR()){
                        subWeight+=1;
                    }
                    int t = ((IntField*)er->fieldByID("T"))->getValue();
                    double dist = getDistanceBetween(e1, er);
                    if(t!=1 && dist<=(distance + this->getDistanceOf(er))){
                        bool tr=true;
                        for(int j=0; j<last->size(); j++){
                            if(last->at(j)==er->getID()){
                                tr=false;
                            }
                        }
                        if(tr){
                            getBestWay(er, e2, last,weight+1+dist/speed+addWeight);
                        }
                    }
                }
            }
        }
        last->popAt(last->size()-1);
        return false;
    }

    int Core::getSpeedOf(Entitie* e){
        int speed = 5;
        int t = ((IntField*)e->fieldByID("T"))->getValue();
        if(t==0){
            speed+=5;
        }
        for(int i=0; i<e->relationCount(); i++){
            Relation* r = e->relationAt(i);
            if(r->getEntL()!=e){
                Entitie* eL = r->getEntL();
                int t = ((IntField*)eL->fieldByID("T"))->getValue();
                if(t==1){
                    for(int j=6; j<eL->fieldCount(); j++){
                        if((int)eL->fieldAt(j)->getType()==2){
                            speed+=((IntField*)eL->fieldAt(j))->getValue();
                        }
                    }
                }
            }
            if(r->getEntR()!=e){
                Entitie* eR = r->getEntR();
                int t = ((IntField*)eR->fieldByID("T"))->getValue();
                if(t==1){
                    for(int j=6; j<eR->fieldCount(); j++){
                        if((int)eR->fieldAt(j)->getType()==2){
                            speed+=((IntField*)eR->fieldAt(j))->getValue();
                        }
                    }
                }
            }
        }
        if(speed>=0){
            return speed;
        }else{
            return 0;
        }
    }

    double Core::getDistanceOf(Entitie* e){
        double distance = 100;
        int t = ((IntField*)e->fieldByID("T"))->getValue();
        if(t==0){
            distance+=100;
        }
        for(int i=0; i<e->relationCount(); i++){
            Relation* r = e->relationAt(i);
            if(r->getEntL()!=e){
                Entitie* eL = r->getEntL();
                int t = ((IntField*)eL->fieldByID("T"))->getValue();
                if(t==1){
                    for(int j=6; j<eL->fieldCount(); j++){
                        if((int)eL->fieldAt(j)->getType()==3){
                            distance+=((DoubleField*)eL->fieldAt(j))->getValue();
                        }
                    }
                }
            }
            if(r->getEntR()!=e){
                Entitie* eR = r->getEntR();
                int t = ((IntField*)eR->fieldByID("T"))->getValue();
                if(t==1){
                    for(int j=6; j<eR->fieldCount(); j++){
                        if((int)eR->fieldAt(j)->getType()==3){
                            distance+=((DoubleField*)eR->fieldAt(j))->getValue();
                        }
                    }
                }
            }
        }
        if(distance>=0){
            return distance;
        }else{
            return 0;
        }
    }

    double Core::getDistanceBetween(Entitie* e1, Entitie* e2){
        int x1 = ((IntField*)e1->fieldByID("X"))->getValue();
        int y1 = ((IntField*)e1->fieldByID("Y"))->getValue();
        int x2 = ((IntField*)e2->fieldByID("X"))->getValue();
        int y2 = ((IntField*)e2->fieldByID("Y"))->getValue();
        return qSqrt(qPow((x1-x2),2)+qPow((y1-y2),2));
    }

    List<string>* Core::getBestWay(Entitie* e1, Entitie* e2){
           this->weightOfSolution = -1;
           delete(this->solution);
           this->solution=NULL;
           List<string>* way = new List<string>();
           getBestWay(e1, e2, way, 0);
           delete(way);
           if(this->solution!=NULL){
               return this->solution;
           }else{
               return new List<string>();
           }
      }

    List<string>* Core::getListEn(){
           Entitie* e1;
           List<string>* l = new List<string>();
           int i;
           i=0;
           while (i<this->content->getEntitieCount()){
               e1= this->content->entitieAt(i);
               int t = ((IntField*)e1->fieldByID("T"))->getValue();
               if(t!=1){
                   l->push_back(e1->getID());
               }
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

    void Core::Changed(bool changed){
        this->changed=changed;
    }

    bool Core::isChanged(){
        return this->changed;
    }
