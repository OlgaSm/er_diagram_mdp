#ifndef VELOFACTORY_H
#define VELOFACTORY_H

class Velo 
{
protected :
	string brand;
	double power;
	
public :
	virtual Velo ();
	virtual ~Velo ();
	virtual string getBrand ();
	virtual double getPower ();
};

class VeloFactory
{
public :
	virtual Velo* createVelo();
};

#endif
