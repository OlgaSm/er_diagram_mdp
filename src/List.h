#ifndef LIST_H
#define LIST_H

//=============================================================
#include "ListItem.h"
//=============================================================

template<class Type>
class ListItem;

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

#endif // LIST_H

//=============================================================
// Реализация
//=============================================================

template<class T>
List<T>::List(){
    this->head = 0;
}

template<class T>
List<T>::~List(){
    this->head->~ListItem();
}

template<class T>
int List<T>:: size(){
    if(this->head!=0){
        ListItem<T>* li = this->head;
        int count = 0;
        while(li!=0){
            li=li->getNext();
            count++;
        }
        return count;
    }else{
        return 0;
    }
}

// Добавить создание эксепшена
template<class T>
T List<T>::at(int i){
    if(this->head!=0){
        ListItem<T>* li = this->head;
        for(int j=0; li!=0; j++){
            if(j==i){
                return li->getValue();
            }
            li=li->getNext();
        }
        return 0;
    }else{
        return 0;
    }
}

template<class T>
void List<T>::push_back(T value){
    if(this->head!=0){
        ListItem<T>* li = this->head;
        while(li->getNext()!=0){
            li=li->getNext();
        }
        li->setNext(new ListItem<T>(value));
    }else{
        this->head = new ListItem<T>(value);
    }
}

// Добавить создание эксепшена
template<class T>
bool List<T>::popAt(int i){
    if(this->head!=0){
        if(i==0){
            ListItem<T>* li = this->head;
            this->head = this->head->getNext();
            li->setNext(0);
            li->~ListItem();
            return true;
        }
        ListItem<T>* li0 = this->head;
        ListItem<T>* li1 = this->head;
        for(int j=0; li1!=0; j++){
            if(j==i){
                li0->setNext(li1->getNext());
                li1->setNext(0);
                li1->~ListItem();
                return true;
            }
            li0 = li1;
            li1=li1->getNext();
        }
    }
    return false;
}
