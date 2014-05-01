#ifndef CARFACTORY_H
#define CARFACTORY_H

class Car 
{
protected :
	string brand;
	double power;
	
public :
	virtual Car (/*string brand, double power*/);
	virtual ~Car ();
	virtual string getBrand ();
	virtual double getPower ();
//	virtual void setBrand (string br);
//	virtual void setPower (double pow);
};

class CarFactory
{
public :
	virtual Car* createCar();
};

#endif
