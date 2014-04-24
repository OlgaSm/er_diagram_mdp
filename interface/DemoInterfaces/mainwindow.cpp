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
#include "QScrollArea"

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
    this->pmenu->addAction("Выйти",this,SLOT(close()));

    this->qbl->setMargin(1);
    this->qbl->addWidget(menuBar);
    this->qbl->addWidget(qtw);
    this->state = new QLabel("Сущность");
    this->qbl->addWidget(this->state);

    //==============================================
    QScrollArea* scrollarea1 = new QScrollArea();
    this->w11 = new WorkPlaceWidget();
    w11->setCore(this->core);
    w11->setFrameStyle(QFrame::Panel);
    QWidget* w21 = new QWidget();
    scrollarea1->setWidget(w11);
    this->tab1->layout()->addWidget(scrollarea1);
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
    //QPushButton* pb7 = new QPushButton("Обновить список сущностей");
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
        QScrollArea* scrollarea2 = new QScrollArea();
        scrollarea2->setMaximumWidth(5000);
        scrollarea2->setMaximumHeight(5000);
        this->w12 = new WorkPlaceWidget();
        w12->setCore(this->core);
        w12->setFrameStyle(QFrame::Panel);
        QWidget* w22 = new QWidget();
        scrollarea2->setWidget(w12);
        this->tab2->layout()->addWidget(scrollarea2);
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
            //blt2->addStretch();
            //w22->layout()->addWidget(pb7);
            w22->layout()->addWidget(this->te);
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
//    QObject::connect(pb7,SIGNAL(clicked()),this,SLOT(button7Pressed()));
    QObject::connect(this->qtw,SIGNAL(currentChanged(int)),this,SLOT(tabChanged()));
}

MainWindow::~MainWindow()
{

}

void MainWindow::tabChanged(){
    if(this->qtw->currentIndex()==1){
        this->core->setState(3);
        this->core->setFocus(-1);
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
    int ind1 = this->cb->currentIndex();
    int ind2 = this->cb2->currentIndex();
    Entitie* e1 = this->core->getEntitieAt(ind1);
    Entitie* e2 = this->core->getEntitieAt(ind2);
    List<string>* way = core->getBestWay(e1,e2);
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
                //if(i>4){
                LineOfField* lf = this->ecw->fildlist->at(i);
                Field* field = lf->getField();
                if(lf->qcb->currentIndex()>=0 && lf->qcb->currentIndex()<4){
                //if(false){
                if((int)field->getType()!=lf->qcb->currentIndex()){
                    this->core->getEntitieAt(this->core->getFocus())->popFieldAt(i+5);
                    this->ecw->fildlist->popAt(i+5);
                    switch(lf->qcb->currentIndex()){
                        case 0:
                            field = new Field(lf->ID->text().toStdString());
                            break;
                        case 1:
                            field = new StringField(lf->ID->text().toStdString(),lf->value->text().toStdString());
                            break;
                        case 2:
                            field = new IntField(lf->ID->text().toStdString(), lf->value->text().toInt(0));
                            break;
                        case 3:
                            field = new DoubleField(lf->ID->text().toStdString(), lf->value->text().toFloat());
                            break;
                    }
                    this->core->getEntitieAt(this->core->getFocus())->addUserField(field);
                    this->ecw->fildlist->push_back(new LineOfField(this->ecw,this->core->getEntitieAt(this->core->getFocus()),field, this));
                    this->ecw->setCurFocus(-1);
                }
                }
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
                //}
            }

        }else{
            Relation* r = this->core->getRelationAt(core->getFocus());
//            string name;
//            int num = this->core->getCounter();
//            char str[255];
//            sprintf(str, "Relation № %d", num);
//            name = (const char*)str;
            Relation* nr = new Relation(this->ecw->tb->text().toStdString(),
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

//void MainWindow::button7Pressed(){
//    int i;
//    i=0;
//    cb->clear();
//    cb2->clear();
//    List<string>* l = core->getListEn();
//    while (i<l->size()){
//        this->cb->addItem( QString::fromStdString(l->at(i)));
//        this->cb2->addItem( QString::fromStdString(l->at(i)));
//        i++;
//    }
//}

