#include "teacherfactory.h"
#include "Factory/teacher.h"

TeacherFactory::TeacherFactory()
{
}

TeacherFactory::~TeacherFactory(){

}

Entitie* TeacherFactory::createHuman(){
    return new Teacher();
}
