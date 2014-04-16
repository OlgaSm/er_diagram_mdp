#ifndef FIELD_H
#define FIELD_H

//=====================================================
#include <string>
//=====================================================

using namespace std;

enum Field_Types{
    BASE_FIELD,
    STRING_FIELD,
    INT_FIELD
};

class Field {

private:
    string ID;
	
public:
    Field(string ID);
    ~Field();
	
public:
    string getID();
    void setID(string ID);
    virtual Field_Types getType();
};

#endif // FIELD_H
