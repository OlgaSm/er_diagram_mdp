#include <QCoreApplication>
#include <stdio.h>
#include <conio.h>
//=============================================================
#include "List.h"
#include "Field.h"
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
    //=================================================

    // ListItem Test
    //=================================================
        List<int>* list = new List<int>();
        list->push_back(1);
        printf("%d ",list->at(0));
        list->push_back(2);
        printf("%d ",list->at(1));
        list->push_back(3);
        printf("%d ",list->at(2));
        list->push_back(4);
        printf("%d ",list->at(3));
        list->push_back(5);
        printf("%d ",list->at(4));
        list->push_back(6);
        printf("%d ",list->at(5));
        printf("\n");
        for(int i=0; i<list->size(); i++){
            printf("%d ",list->at(i));
        }
        list->popAt(0);
        list->popAt(4);
        list->popAt(3);
        printf("\n");
        for(int i=0; i<list->size(); i++){
            printf("%d ",list->at(i));
        }
    //=================================================

    // Field Test
    //=================================================
    printf("\n");
    Field* field = new Field("Test");
    printf("Field %s\n", field->getID().c_str());
    printf("Field %d\n", field->getType());
    //=================================================

    // Entitie Test
    //=================================================
    Entitie* entitie1 = new Entitie("Test entitie 1");
    Entitie* entitie2 = new Entitie("Test entitie 2");

    //=================================================

    // Relation Test
    //=================================================
    Relation* relation = new Relation("Test relation",entitie1,entitie2,true,true,true,true);
    printf("Relation %s\n", relation->getID().c_str());
    printf("Entitie %s\n", relation->getEntR()->getID().c_str());
    printf("Entitie %s\n", relation->getEntL()->getID().c_str());
    //=================================================
    return a.exec();
}
