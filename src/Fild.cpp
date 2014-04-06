#include "Fild.h"

Fild::Fild(char* ID){
    this->ID = ID;
}

Fild::~Fild(){

}

char* Fild::getID(){
    return this->ID;
}

void Fild::setID(char* ID){
    this->ID = ID;
}

char* Fild::getType(){
    return (char*)"BaseFild";
}
