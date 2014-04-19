#include <string>
#include "DoubleField.h"

DoubleField::DoubleField(string id, double val) : Field(id)
{
    this->value = val;
}

DoubleField::~DoubleField()
{
}

double DoubleField::getValue()
{
    return this->value;
}

void DoubleField::setValue(double val)
{
    this->value = val;
}

Field_Types DoubleField::getType(){
    return DOUBLE_FIELD;
}
