#ifndef STRINGFIELD_H
#define STRINGFIELD_H

#include <string>
#include "Field.h"

using namespace std;

class StringField : public Field
{
private:
	string value;

public:    
    StringField(string id, string val);
    ~StringField();

public:    
    string getValue();
    void setValue(string val);
    Field_Types getType();
};
#endif
