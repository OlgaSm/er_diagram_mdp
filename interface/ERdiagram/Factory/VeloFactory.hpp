#ifndef VELOFACTORY_H
#define VELOFACTORY_H

class SlowVelo : public Entitie{
private :
    static int id;

public :
    SlowVelo():Entitie("VSLOW"+QString::number(id++).toStdString()){
        this->myfield->push_back(new DoubleField("power",1.0));
    }
    ~SlowVelo(){

    }
    string getBrand(){
        return this->ID;
    }

    double getPower (){
        return 1.0;
    }
};
int SlowVelo::id = 0;
//==============================================




class MediumVelo : public Entitie{
private :
    static int id;

public :
    MediumVelo():Entitie("VMEDIUM"+QString::number(id++).toStdString()){
        this->myfield->push_back(new DoubleField("power",2.0));
    }

    ~MediumVelo(){

    }
    string getBrand(){
        return this->ID;
    }
    double getPower (){
        return 2.0;
    }
};
int MediumVelo::id = 0;
//==============================================




class FastVelo : public Entitie{
private :
    static int id;

public :
    FastVelo ():Entitie("VFAST"+QString::number(id++).toStdString()){
        this->myfield->push_back(new DoubleField("power",3.0));
    }

    ~FastVelo(){

    }
    string getBrand(){
        return this->ID;
    }

    double getPower (){
        return 3.0;
    }
};
int FastVelo::id = 0;
//==============================================

class VeloFactory
{
public :
    Entitie* createVelo();
};
//==============================================

#endif
