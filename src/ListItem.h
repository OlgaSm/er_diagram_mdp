template<class Type>
class ListItem{
    private:
		Type x;
		ListItem* next;

    public:
		ListItem(Type x0);
		~ListItem();
    public:
		void setNext(ListItem* next);
		ListItem* getNext();
		void setValue(Type x);
		Type getValue();
};
