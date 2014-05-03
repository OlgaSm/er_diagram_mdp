#include "studentfactory.h"
#include "Factory/student.h"

StudentFactory::StudentFactory()
{
}

StudentFactory::~StudentFactory(){

}

Entitie* StudentFactory::createHuman(){
    return new Student();
}
