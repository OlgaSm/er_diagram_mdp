#include "mainwindow.h"
#include <QMenuBar>
#include <QMenu>
#include <QBoxLayout>
#include <QTabWidget>
#include <QLabel>
#include <QPushButton>
#include <QComboBox>
#include <QFrame>
#include <QObject>
#include "workplacewidget.h"
#include "Contaner/Entitie.h"
#include "Contaner/IntField.h"
#include "entitiecustomewidget.h"
#include "lineoffield.h"
#include "Contaner/DoubleField.h"
#include "Contaner/DataField.h"
#include "Contaner/StringField.h"

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{   
    // Модель данных
    //===============================================
    this->core = new Core();
    //===============================================

    // Настройка
    this->setAutoFillBackground(true);
    this->resize(1000,500);

    // Инициализация полей
    this->menuBar = new QMenuBar();
    this->pmenu = new QMenu("&Файл");
    this->qbl = new QBoxLayout(QBoxLayout::TopToBottom);
    this->qtw = new QTabWidget();
    this->tab1 = new QWidget();
    this->tab2 = new QWidget();
    this->tab1->setLayout(new QBoxLayout(QBoxLayout::LeftToRight));
    this->tab2->setLayout(new QBoxLayout(QBoxLayout::LeftToRight));
    this->qtw->addTab(tab1,QPixmap(),"&Редактор");
    this->qtw->addTab(tab2,QPixmap(),"&Работа");

    this->menuBar->addMenu(pmenu);

    this->pmenu->addAction("Создать");
    this->pmenu->addAction("Сохранить");
    this->pmenu->addAction("Загрузить");
    this->pmenu->addAction("Выйти");

    this->qbl->setMargin(1);
    this->qbl->addWidget(menuBar);
    this->qbl->addWidget(qtw);
    this->state = new QLabel("Сущность");
    this->qbl->addWidget(this->state);
    //this->qbl->addStretch();

    //==============================================
    this->w11 = new WorkPlaceWidget();
    w11->setCore(this->core);
    w11->setFrameStyle(QFrame::Panel);
    QWidget* w21 = new QWidget();
    this->tab1->layout()->addWidget(w11);
    this->tab1->layout()->addWidget(w21);
    QBoxLayout* blt = new QBoxLayout(QBoxLayout::TopToBottom);
    w21->setMaximumWidth(400);
    w21->setLayout(blt);
    //==============================================
    this->ecw = new EntitieCustomeWidget();
    ecw->setCore(this->core);
    //==============================================
    QPushButton* pb0 = new QPushButton("Сущность");
    QPushButton* pb1 = new QPushButton("Связь");
    QPushButton* pb2 = new QPushButton("Выделить");
    QPushButton* pb3 = new QPushButton("Указатель");
    QPushButton* pb4 = new QPushButton("Удалить");
    QPushButton* pb5 = new QPushButton("Сохранить");
    QPushButton* pb6 = new QPushButton("Отправить посылку");
    QPushButton* pb7 = new QPushButton("Получатели/Отправители");
    //==============================================
        //this->tab1->setStyleSheet("border: 1px solid black");
        w21->layout()->addWidget(pb0);
        w21->layout()->addWidget(pb1);
        w21->layout()->addWidget(pb2);
        w21->layout()->addWidget(pb3);
        w21->layout()->addWidget(ecw);
        //blt->addStretch();
        w21->layout()->addWidget(pb5);
        w21->layout()->addWidget(pb4);
    //==============================================
        this->w12 = new WorkPlaceWidget();
        w12->setCore(this->core);
        w12->setFrameStyle(QFrame::Panel);
        QWidget* w22 = new QWidget();
        this->tab2->layout()->addWidget(w12);
        this->tab2->layout()->addWidget(w22);
        QBoxLayout* blt2 = new QBoxLayout(QBoxLayout::TopToBottom);
        w22->setMaximumWidth(400);
        w22->setLayout(blt2);
        //==============================================
            //this->tab1->setStyleSheet("border: 1px solid black");

            this->te = new QTextEdit();
            w22->layout()->addWidget(new QLabel("Получатель"));
            this->cb = new QComboBox();
            this->cb2 = new QComboBox();
            w22->layout()->addWidget(cb);
            w22->layout()->addWidget(new QLabel("Отправитель"));
            w22->layout()->addWidget(cb2);
            blt2->addStretch();
            w22->layout()->addWidget(pb7);
            w22->layout()->addWidget(te);
            w22->layout()->addWidget(pb6);

    //==============================================
    this->setLayout(qbl);
    // Соединение со сингналов со слотами
    //==============================================
    QObject::connect(pb0,SIGNAL(clicked()),this,SLOT(button1Pressed()));
    QObject::connect(pb1,SIGNAL(clicked()),this,SLOT(button2Pressed()));
    QObject::connect(pb2,SIGNAL(clicked()),this,SLOT(button3Pressed()));
    QObject::connect(pb3,SIGNAL(clicked()),this,SLOT(button4Pressed()));
    QObject::connect(pb4,SIGNAL(clicked()),this,SLOT(button5Pressed()));
    QObject::connect(pb5,SIGNAL(clicked()),this,SLOT(button6Pressed()));
    QObject::connect(pb6,SIGNAL(clicked()),this,SLOT(buttonway()));
    QObject::connect(pb7,SIGNAL(clicked()),this,SLOT(button7Pressed()));
}

MainWindow::~MainWindow()
{

}


void MainWindow::button1Pressed(){
    this->state->setText("Сущность");
    this->core->setState(0);
    this->core->setFocus(-1);
    this->core->setFocusObj(true);
    this->w11->repaint();
}

void MainWindow::button2Pressed(){
    this->state->setText("Связь");
    this->core->setState(1);
    this->core->setFocus(-1);
    this->core->setFocusObj(true);
    this->w11->repaint();
}

void MainWindow::button3Pressed(){
    this->state->setText("Выделить");
    this->core->setState(2);
    this->w11->repaint();
}

void MainWindow::button4Pressed(){
    this->state->setText("Указатель");
    this->core->setState(3);
    this->w11->repaint();
}

void MainWindow::button5Pressed(){
    if(this->core->getFocus()!=-1){
        this->state->setText("Удалить");
        //this->core->setState(4);
        if(core->getFocusObj()){
            this->core->popEntitieAt(this->core->getFocus());
        }else{
            this->core->popRelationAt(this->core->getFocus());
        }
        this->core->setFocus(-1);
        this->w11->repaint();
    }
}

void MainWindow::buttonway(){
    int i;
    this->state->setText("Нахождение оптимального пути");
    List<string>* way = core->getBestWay();
    i=0;
    te->clear();
    this->te->setReadOnly(true);
    while (i<way->size()){
        this->te->append( QString::fromStdString(way->at(i)));
        i++;
    }
}

void MainWindow::button6Pressed(){
    if(this->core->getFocus()!=-1){
        this->state->setText("Сохранить");
        if(core->getFocusObj()){
            //this->core->popEntitieAt(this->core->getFocus());
            Entitie* e = this->core->getEntitieAt(core->getFocus());
            e->setID(this->ecw->tb->text().toStdString());
            for(int i=0; i<this->ecw->fildlist->size(); i++){
                if(i>5){
                LineOfField* lf = this->ecw->fildlist->at(i);
                Field* field = lf->getField();
                field->setID(lf->ID->text().toStdString());
                switch((int)field->getType()){
                    case 1:
                        ((StringField*)(field))->setValue(lf->value->text().toStdString());
                        break;
                    case 2:
                        ((IntField*)(field))->setValue(lf->value->text().toInt());
                        break;
                    case 3:
                        ((DoubleField*)(field))->setValue(lf->value->text().toDouble());
                        break;
                }
                }
            }

        }else{
            Relation* r = this->core->getRelationAt(core->getFocus());
            string name;
            int num = this->core->getCounter();
            char str[255];
            sprintf(str, "Relation № %d", num);
            name = (const char*)str;
            Relation* nr = new Relation(name,
                                        this->ecw->key->text().toStdString(),
                                        r->getEntL(),r->getEntR(),
                                        this->ecw->mr->isChecked(),
                                        this->ecw->ml->isChecked(),
                                        this->ecw->ar->isChecked(),
                                        this->ecw->al->isChecked());
            this->core->popRelationByID(r->getID());
            //delete(r);
            this->core->addRelation(nr);
            //this->ecw
        }
        this->w11->repaint();
    }
}

void MainWindow::button7Pressed(){
    int i;
    i=0;
    cb->clear();
    cb2->clear();
    List<string>* l = core->getListEn();
    while (i<l->size()){
        this->cb->addItem( QString::fromStdString(l->at(i)));
        this->cb2->addItem( QString::fromStdString(l->at(i)));
        i++;
    }
}


//this->core->popEntitieAt(this->core->getFocus());
//Entitie* e = this->core->getEntitieAt(core->getFocus());
//e->setID(this->ecw->tb->text().toStdString());
//List<Field*>* del = new List<Field*>();
//List<Field*>* add = new List<Field*>();
//for(int i=0; i<this->ecw->fildlist->size(); i++){
//    LineOfField* lf = this->ecw->fildlist->at(i);
//    Field* field = lf->getField();
//    int ind = lf->qcb->currentIndex();
//    if(field->getType() == ind){
//        field->setID(lf->ID->text().toStdString());
//        switch((int)field->getType()){
//            case 1:
//                ((StringField*)(field))->setValue(lf->value->text().toStdString());
//                break;
//            case 2:
//                ((IntField*)(field))->setValue(lf->value->text().toInt());
//                break;
//            case 3:
//                ((DoubleField*)(field))->setValue(lf->value->text().toDouble());
//                break;
//        }
//    }else{
//        Field* d = e->fieldAt(i);
//        Field* a = NULL;
//        string ID = lf->ID->text().toStdString();
//        switch(lf->qcb->currentIndex()){
//            case 0:
//                a = new Field(ID);
//                break;
//            case 1:
//                a = new StringField(ID,lf->value->text().toStdString());
//                break;
//            case 2:
//                a = new IntField(ID, lf->value->text().toInt());
//                break;
//            case 3:
//                a = new DoubleField(ID, lf->value->text().toDouble());
//                break;
//        }
//        if(a==NULL) a = new Field(ID);
//        del->push_back(d);
//        add->push_back(a);
//    }
//}
//for(int i=0; i< del->size(); i++){
//    e->popFieldByID(del->at(i)->getID());
//}
//for(int i=0; i< add->size(); i++){
//    e->addUserField(add->at(i));
//}
