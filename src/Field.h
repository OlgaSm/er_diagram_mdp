#ifndef FIELD_H
#define FIELD_H
#define BASE_FIELD 1

class Field {
private:
    char* ID;
	
public:
    Field(char* ID);
    ~Field();
	
public:
	char* getID();
    void setID(char* ID);
    virtual int getType();
};

#endif // FIELD_H
