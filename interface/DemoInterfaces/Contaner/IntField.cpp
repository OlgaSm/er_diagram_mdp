#include "Field.h"
#include "IntField.h"

IntField::IntField(string id, int val) : Field(id)
{
    this->value = val;
}

IntField::~IntField()
{
}

int IntField::getValue()
{
    return this->value;
}

void IntField::setValue(int val)
{
    this->value = val;
}

Field_Types IntField::getType(){
    return INT_FIELD;
}

