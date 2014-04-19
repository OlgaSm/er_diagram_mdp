#include <QCoreApplication>
#include <stdio.h>
#include <conio.h>
//=============================================================
#include "List.h"
#include "Field.h"
#include "IntField.h"
#include "DoubleField.h"
#include "DataField.h"
#include "StringField.h"
#include "Relation.h"
#include "Entitie.h"
//=============================================================

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // ListItem Test
    //=================================================
        ListItem<int>* li = new ListItem<int>(5);
        printf("ListItem = %d\n",li->getValue());
        li->setValue(10);
        printf("ListItem = %d\n",li->getValue());
        if(li->getNext()!=NULL){
            printf("ListItem = %d\n",li->getNext()->getValue());
        }else{
            printf("li->getNext()==NULL\n");
        }
        li->setNext(li);
        if(li->getNext()!=NULL){
            printf("ListItem = %d\n",li->getNext()->getValue());
        }else{
            printf("li->getNext()==NULL\n");
        }
        delete(li);
    //=================================================
    printf("\n===================================================\n");

    // ListItem Test
    //=================================================
        List<int>* list = new List<int>();
        list->push_back(1);
        printf("ADD %d ",list->at(0));
        list->push_back(2);
        printf("ADD %d ",list->at(1));
        list->push_back(3);
        printf("ADD %d ",list->at(2));
        list->push_back(4);
        printf("ADD %d ",list->at(3));
        list->push_back(5);
        printf("ADD %d ",list->at(4));
        list->push_back(6);
        printf("ADD %d ",list->at(5));
        printf("\n");
        for(int i=0; i<list->size(); i++){
            printf("%d ",list->at(i));
        }
        list->popAt(0);
        list->popAt(4);
        list->popAt(3);
//        for(int j=0; j<100; j++){
//            for(int i=0; i<10; i++){
//                list->push_back(1);
//            }
//            for(int i=0; i<10; i++){
//                list->popAt(0);
//            }
//        }
        printf("\n");
        for(int i=0; i<list->size(); i++){
            printf("%d ",list->at(i));
        }
       // delete(list);
    //=================================================
    printf("\n===================================================\n");

    // Field Test
    //=================================================
    printf("\n");
    Field* field = new Field("Test");
    printf("Field %s\n", field->getID().c_str());
    printf("Field Type %d\n", field->getType());
    //=================================================
    printf("\n===================================================\n");

    // IntField Test
    //=================================================
    printf("\n");
    IntField* intfield = new IntField("Test1",1);
    printf("IntField %s\n", intfield->getID().c_str());
    printf("IntField Type %d\n", intfield->getType());
    printf("IntField Value %d\n", intfield->getValue());
    //=================================================
    printf("\n===================================================\n");

    // DoubleField Test
    //=================================================
    printf("\n");
    DoubleField* doublefield = new DoubleField("Test2",2.2);
    printf("DoubleField %s\n", doublefield->getID().c_str());
    printf("DoubleField Type %d\n", doublefield->getType());
    printf("DoubleField Value %e\n", doublefield->getValue());
    //=================================================
    printf("\n===================================================\n");

    // StringField Test
    //=================================================
    printf("\n");
    StringField* templatefield = new StringField("Test3","Value");
    printf("StringField %s\n", templatefield->getID().c_str());
    printf("StringField Type %d\n", templatefield->getType());
    printf("StringField Value %s\n", templatefield->getValue().c_str());
    //=================================================
    printf("\n===================================================\n");

    // TemplateField Test
    //=================================================
    printf("\n");
    DataField<string>* stringfield = new DataField<string>("Test3","Value");
    printf("TemplateField %s\n", stringfield->getID().c_str());
    printf("TemplateField Type %d\n", stringfield->getType());
    printf("TemplateField Value %s\n", stringfield->getValue().c_str());
    //=================================================
    printf("\n===================================================\n");


    // Entitie Test
    //=================================================
    Entitie* entitie1 = new Entitie("Test entitie 1");
    Entitie* entitie2 = new Entitie("Test entitie 2");
    entitie1->addUserField(field);
    entitie2->addUserField(field);
    printf("Field from entitie1 %s\n", entitie1->fieldAt(0)->getID().c_str());
    printf("Field from entitie2 %s\n", entitie2->fieldAt(0)->getID().c_str());
    //=================================================
    printf("\n===================================================\n");

    // Relation Test
    //=================================================
    Relation* relation = new Relation("Test relation",entitie1,entitie2,true,true,true,true);
    if(entitie1->isRelationListEmpty()){
        printf("Relation1 isEmpty==true\n");
    }else{
        printf("Relation1 isEmpty==false\n");
    }
    if(entitie2->isRelationListEmpty()){
        printf("Relation2 isEmpty==true\n");
    }else{
        printf("Relation2 isEmpty==false\n");
    }
    printf("Relation %s\n", relation->getID().c_str());
    printf("Entitie %s\n", relation->getEntR()->getID().c_str());
    printf("Entitie %s\n", relation->getEntL()->getID().c_str());
    delete(relation);
    if(entitie1->isRelationListEmpty()){
        printf("Relation1 isEmpty==true\n");
    }else{
        printf("Relation1 isEmpty==false\n");
    }
    if(entitie2->isRelationListEmpty()){
        printf("Relation2 isEmpty==true\n");
    }else{
        printf("Relation2 isEmpty==false\n");
    }
    //=================================================
    printf("\n===================================================\n");

    return a.exec();
}
