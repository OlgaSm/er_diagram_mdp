#ifndef DoubleField_H
#define DoubleField_H

#include <string>
#include "Field.h"

using namespace std;

class DoubleField : public Field
{
private:
	double value;

public:    
    explicit DoubleField(string id, double val);
    ~DoubleField();

public:    
    double getValue();
    void setValue(double val);
    Field_Types getType();
};
#endif
