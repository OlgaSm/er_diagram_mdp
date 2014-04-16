#include DataField.h

DataField::DataField(string id, Type val) : Field(id)
{
	this->value = val;
}

DataField::~DataField()
{
}

Type DataField::getValue()
{
	return this->value;
}

void DataField::setValue(Type val)
{
	this->value = val;
}
