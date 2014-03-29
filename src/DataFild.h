template<class Type>
class DataFild : Fild {
private:
	Type value;
	
public:	
	DataFild(char* ID, Type value);
	~DataFild();
	
public:	
	Type getValue();
	void setValue(Type value);
};
