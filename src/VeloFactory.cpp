#include <string>

using namespace std;

class SlowVelo : public Velo 
{  
private : 
	static int id = 0;
public :
	virtual SlowVelo ()
	{
		id++;
		brand = "VSLOW";
		power = 1.0;
	}
	virtual ~SlowVelo () {}
	virtual string getBrand ()
	{	return brand; }
	virtual double getPower ()
	{	return power; }
};

class MediumVelo : public Velo 
{  
private : 
	static int id = 0;	
public :
	virtual MediumVelo ()
	{
		id++;
		brand = "VMEDIUM";
		power = 2.0;
	}
	virtual ~MediumVelo () {}
	virtual string getBrand ()
	{	return brand; }
	virtual double getPower ()
	{	return power; }
}; 

class FastVelo : public Velo 
{  
private : 
	static int id = 0;
public :
	virtual FastVelo ()
	{
		id++;
		brand = "VFAST";
		power = 3.0;
	}
	virtual ~FastVelo () {}
	virtual string getBrand ()
	{	return brand; }
	virtual double getPower ()
	{	return power; }
};

class SlowVeloFactory : public VeloFactory 
{  
public :
	virtual Velo* createVelo ()
	{
		return new SlowVelo ();
	}
};

class MediumVeloFactory : public VeloFactory 
{  
public :
	virtual Velo* createVelo ()
	{
		return new MediumVelo ();
	}
};

class FastVeloFactory : public VeloFactory 
{  
public :
	virtual Velo* createVelo ()
	{
		return new FastVelo ();
	}
};

