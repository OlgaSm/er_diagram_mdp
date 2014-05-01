#include "convert.h"
//#include <string>

using namespace std;

class SlowCar : public Entitie 
{  
private : 
	static int id = 0;
public :
	SlowCar ()
	{
		id++;
		string brand = + "CSLOW"+intToStr(id);
		Entitie (brand);
		this->myfield->push_back(new DoubleField("power",2.5));	
	}
	~SlowCar () {}
	string getBrand ()
	{
		return this->ID; 
	}
	double getPower ()
	{	
		return 2.5; 
	}
};

class MediumCar : public Entitie
{  
private : 
	static int id = 0;	
public :
	MediumCar ()
	{
		id++;
		string brand = "CMEDIUM"+intToStr(id);
		Entitie (brand);
		this->myfield->push_back(new DoubleField("power",5.0));	
	}
	virtual ~MediumCar () {}
	virtual string getBrand ()
	{	
		return this->ID; 
	}
	virtual double getPower ()
	{
		return 5.0; 
	}
}; 

class FastCar : public Entitie
{  
private : 
	static int id = 0;
public :
	FastCar ()
	{
		id++;
		string brand = "CFAST"+intToStr(id);
		Entitie (brand);
		this->myfield->push_back(new DoubleField("power",7.5));	
	}
	~FastCar () {}
	string getBrand ()
	{	
		return this->ID;	
	}
	double getPower ()
	{
		return 7.5; 
	}
};

class CarFactory
{
public :
	Car* createCar();
};

class SlowCarFactory : public CarFactory 
{  
public :
	Car* createCar ()
	{
		return new SlowCar ();
	}
};

class MediumCarFactory : public CarFactory 
{  
public :
	Car* createCar ()
	{
		return new MediumCar ();
	}
};

class FastCarFactory : public CarFactory 
{  
public :
	Car* createCar ()
	{
		return new FastCar ();
	}
};

