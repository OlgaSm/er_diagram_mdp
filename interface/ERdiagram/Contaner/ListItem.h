#ifndef LISTITEM_H
#define LISTITEM_H

//=====================================
#include "DebugDefine.h"
//=====================================

template<class Type>
class ListItem{
    private:
		Type x;
		ListItem* next;

    public:
        explicit ListItem(Type x);
		~ListItem();
    public:
		void setNext(ListItem* next);
		ListItem* getNext();
		void setValue(Type x);
		Type getValue();
};

//=============================================================
//Реализация
//=============================================================

template<class Type>
ListItem<Type>::ListItem(Type x){
    this->x = x;
    this->next = 0;
    #ifdef DEBUGLOG_LISTITEM
        QFile file(LOG_PATH);
        file.open(QIODevice::Append | QIODevice::Text);
        QTextStream out(&file);
        out << "+ ListItem created" << endl;
        file.close();
        //CountCreatedObject++;
    #endif
}

template<class Type>
ListItem<Type>::~ListItem(){
    if(next != 0 && next != this) {
        delete next;
        next = 0;
    }
    #ifdef DEBUGLOG_LISTITEM
        QFile file(LOG_PATH);
        file.open(QIODevice::Append | QIODevice::Text);
        QTextStream out(&file);
        out << "- ListItem deleted" << endl;
        file.close();
        //CountDeltedObject++;
    #endif
}

template<class Type>
void ListItem<Type>::setNext(ListItem* next){
    this->next = next;
}

template<class Type>
ListItem<Type>* ListItem<Type>::getNext(){
    return this->next;
}

template<class Type>
void ListItem<Type>::setValue(Type x){
    this->x = x;
}

template<class Type>
Type ListItem<Type>::getValue(){
    return x;
}

#endif // LISTITEM_H
