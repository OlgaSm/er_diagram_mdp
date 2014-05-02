#include "convert.h"

using namespace std;

class SlowVelo : public Entitie
{  
private : 
	static int id = 0;
public :
	SlowVelo ()
	{
		id++;
		string brand = "VSLOW"+intToStr(id);
		Entitie (brand);
		this->myfield->push_back(new DoubleField("power",1.0));
	}
	~SlowVelo () {}
	string getBrand ()
	{
		return this->ID; 
	}
	double getPower ()
	{
		return 1.0; 
	}
};

class MediumVelo : public Entitie
{  
private : 
	static int id = 0;	
public :
	MediumVelo ()
	{
		id++;
		string brand = "VMEDIUM"+intToStr(id);
		Entitie (brand);
		this->myfield->push_back(new DoubleField("power",2.0));
	}
	~MediumVelo () {}
	string getBrand ()
	{	
		return this->ID;  
	}
	double getPower ()
	{	
		return 2.0; 
	}
}; 

class FastVelo : public Entitie
{  
private : 
	static int id = 0;
public :
	FastVelo ()
	{
		id++;
		string brand = "VFAST"+intToStr(id);
		Entitie (brand);
		this->myfield->push_back(new DoubleField("power",3.0));
	}
	~FastVelo () {}
	string getBrand ()
	{	
		return this->ID;  
	}
	double getPower ()
	{	
		return 3.0;
	}
};

class VeloFactory
{
public :
	Velo* createVelo();
};

class SlowVeloFactory : public VeloFactory 
{  
public :
	Velo* createVelo ()
	{
		return new SlowVelo ();
	}
};

class MediumVeloFactory : public VeloFactory 
{  
public :
	Velo* createVelo ()
	{
		return new MediumVelo ();
	}
};

class FastVeloFactory : public VeloFactory 
{  
public :
	Velo* createVelo ()
	{
		return new FastVelo ();
	}
};

