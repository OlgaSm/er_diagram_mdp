#include <QCoreApplication>
#include <stdio.h>
#include <conio.h>
//#include "List.cpp"
//#include "Fild.cpp"
#include "Relation.cpp"

using namespace ERdiagram;

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

    // Fild Test
    //=================================================
    printf("\n");
    Fild* fild = new Fild((char*)"Test");
    printf("Fild %s\n", fild->getID());
    printf("Fild %s\n", fild->getType());
    //=================================================

    // Relation Test
    //=================================================
    Relation* relation = new Relation((char*)"Test relation",NULL,NULL,true,true,true,true);

    printf("Relation %s\n", relation->getID());
    //=================================================
    return a.exec();
}
