#include "schoolboyfactory.h"
#include "Factory/schoolboy.h"

SchoolboyFactory::SchoolboyFactory()
{
}

SchoolboyFactory::~SchoolboyFactory(){

}

Entitie* SchoolboyFactory::createHuman(){
    return new Schoolboy();
}
