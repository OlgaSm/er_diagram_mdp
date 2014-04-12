#ifndef FIELD_H
#define FIELD_H

//=====================================================
#include <string>
//=====================================================

using namespace std;

enum Fild_Types{
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
    virtual Fild_Types getType();
};

#endif // FIELD_H
