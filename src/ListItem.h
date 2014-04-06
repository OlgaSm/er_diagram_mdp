#ifndef LISTITEM_H
#define LISTITEM_H

namespace ERdiagram{

template<class Type>
class ListItem{
    private:
		Type x;
		ListItem* next;

    public:
        ListItem(Type x);
		~ListItem();
    public:
		void setNext(ListItem* next);
		ListItem* getNext();
		void setValue(Type x);
		Type getValue();
};

}

#endif // LISTITEM_H
