#include "Field.h"

Field::Field(string ID){
    this->ID = ID;
}

Field::~Field(){

}

string Field::getID(){
    return this->ID;
}

void Field::setID(string ID){
    this->ID = ID;
}

Field_Types Field::getType(){
    return BASE_FIELD;
}

