#include "erallocator.h"

ERAllocator::ERAllocator(){
    object* thisObj = new object();
    thisObj->objClass = "ERAlocator";
    thisObj->deleted = false;
    thisObj->obj = this;
    thisObj->comment = "Create in constructor of ERAlocator";
}

ERAllocator::~ERAllocator(){
}

QList<object*>* ERAllocator::getObjects(){
    return &ERAllocator::objects;
}
