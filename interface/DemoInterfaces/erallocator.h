#ifndef ERALOCATOR_H
#define ERALOCATOR_H

#include <string>
#include <QList>

//========================================
#include "Contaner/Core.h"
#include "Contaner/DataField.h"
#include "Contaner/DoubleField.h"
#include "Contaner/Entitie.h"
#include "Contaner/ERDiagram.h"
#include "Contaner/Field.h"
#include "Contaner/IntField.h"
#include "Contaner/List.h"
#include "Contaner/ListItem.h"
#include "Contaner/Relation.h"
#include "Contaner/StringField.h"
#include "lineoffield.h"
#include "mainwindow.h"
#include "workplacewidget.h"
//========================================

using namespace std;

struct object{
    void* obj;
    string objClass;
    string comment;
    bool deleted;
};

class ERAllocator{
private:
    static QList<object*> objects;

public:
    ERAllocator();
    ~ERAllocator();
    static QList<object*>* getObjects();
};

#endif // ERALOCATOR_H
