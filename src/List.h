template<class T>
class List{
private:
     ListItem<T>* head;

public:
	List();                        
	~List();                          

public:
	T at(int i);
	void    push_back(T value);          
	void    popAt(int i);
};
