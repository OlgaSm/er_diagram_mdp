#include "eralocator.h"

ERAlocator::ERAlocator(){
    this->objects = new QList<object*>();
    object* thisObj = new object();
    thisObj->objClass = "ERAlocator";
    thisObj->deleted = false;
    thisObj->obj = this;
    thisObj->comment = "Create in constructor of ERAlocator";
    this->objects->append(thisObj);
}

ERAlocator::~ERAlocator(){
    for(int i=0; i<this->objects->size(); i++) {
        delete(this->objects->at(i));
    }
    delete(this->objects);
}
