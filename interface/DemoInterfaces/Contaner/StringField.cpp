#include <string>
#include "Field.h"
#include "StringField.h"

StringField::StringField(string id, string val) : Field(id)
{
    this->value = val;
}

StringField::~StringField()
{
}

string StringField::getValue()
{
    return this->value;
}

void StringField::setValue(string val)
{
    this->value = val;
}

Field_Types StringField::getType(){
    return STRING_FIELD;
}
