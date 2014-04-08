#include "Field.h"

Field::Field(char* ID){
    this->ID = ID;
}

Field::~Field(){

}

char* Field::getID(){
    return this->ID;
}

void Field::setID(char* ID){
    this->ID = ID;
}

int Field::getType(){
    return BASE_FIELD;
}

