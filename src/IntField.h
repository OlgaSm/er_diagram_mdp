#ifndef INTFIELD_H
#define INTFIELD_H

#include <string>
#include "Field.h"

using namespace std;

class IntField : public Field
{
private:
	int value;

public:    
    IntField(string id, int val);
    ~IntField();

public:    
    int getValue();
    void setValue(int val);
    Field_Types getType();
};

#endif
