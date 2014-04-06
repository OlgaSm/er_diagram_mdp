#ifndef FILD_H
#define FILD_H

namespace ERdiagram{

class Fild {
private:
    char* ID;
	
public:
    Fild(char* ID);
	~Fild();
	
public:
	char* getID();
    void setID(char* ID);
    virtual char* getType();
};

}

#endif // FILD_H
