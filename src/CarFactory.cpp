#include <string>

using namespace std;

class SlowCar : public Car 
{  
private : 
	static int id = 0;
public :
	virtual SlowCar ()
	{
		id++;
		brand = "CSLOW";
		power = 2.5;
	}
	virtual ~SlowCar () {}
	virtual string getBrand ()
	{	return brand; }
	virtual double getPower ()
	{	return power; }
};

class MediumCar : public Car 
{  
private : 
	static int id = 0;	
public :
	virtual MediumCar ()
	{
		id++;
		brand = "CMEDIUM";
		power = 5.0;
	}
	virtual ~MediumCar () {}
	virtual string getBrand ()
	{	return brand; }
	virtual double getPower ()
	{	return power; }
}; 

class FastCar : public Car 
{  
private : 
	static int id = 0;
public :
	virtual FastCar ()
	{
		id++;
		brand = "CFAST";
		power = 7.5;
	}
	virtual ~FastCar () {}
	virtual string getBrand ()
	{	return brand; }
	virtual double getPower ()
	{	return power; }
};

class SlowCarFactory : public CarFactory 
{  
public :
	virtual Car* createCar ()
	{
		return new SlowCar ();
	}
};

class MediumCarFactory : public CarFactory 
{  
public :
	virtual Car* createCar ()
	{
		return new MediumCar ();
	}
};

class FastCarFactory : public CarFactory 
{  
public :
	virtual Car* createCar ()
	{
		return new FastCar ();
	}
};

