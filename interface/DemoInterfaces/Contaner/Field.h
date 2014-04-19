#ifndef FIELD_H
#define FIELD_H

//=====================================================
#include <string>
//=====================================================

using namespace std;

enum Field_Types{
    BASE_FIELD,
    STRING_FIELD,
    INT_FIELD,
    DOUBLE_FIELD,
	TEMPLATE_FILD
};

class Field {

private:
    string ID;
	
public:
    Field(string ID);
    virtual ~Field();
	
public:
    string getID();
    void setID(string ID);
    virtual Field_Types getType();
};

#endif // FIELD_H
