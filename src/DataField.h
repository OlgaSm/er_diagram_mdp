#ifndef DATAFIELD_H
#define DATAFIELD_H

#include <string>
#include Field.h

using namespace std;

template<class Type>
class DataField : Field 
{
private:
	Type value;

public:    
    DataField(string id, Type val);
    ~DataField();

public:    
    Type getValue();
    void setValue(Type val);
};

#endif
