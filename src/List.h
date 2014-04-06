#ifndef LIST_H
#define LIST_H
//#include "ListItem.cpp"

namespace ERdiagram{

template<class T>
class List{
private:
     ListItem<T>* head;

public:
	List();                        
	~List();                          

public:
	T at(int i);
    int     size();
	void    push_back(T value);          
    bool    popAt(int i);
};

}

#endif // LIST_H
