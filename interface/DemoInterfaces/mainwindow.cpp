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
#include "entitiecustomewidget.h"
#include "lineoffield.h"
#include "Contaner/IntField.h"
#include "Contaner/DoubleField.h"
#include "Contaner/DataField.h"
#include "Contaner/StringField.h"
#include <QScrollArea>

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{   
    // Модель данных
    //===============================================
    this->core = new Core();
    //===============================================

    // Настройка
    this->setAutoFillBackground(true);
    this->resize(1000,600);
    this->timer = new QTimer(this);
    connect(this->timer, SIGNAL(timeout()), SLOT(timerEvent()));
    this->timer->start(50);

    // Инициализация полей
    this->menuBar = new QMenuBar();
    this->pmenu = new QMenu("&Файл");
    this->qbl = new QBoxLayout(QBoxLayout::TopToBottom);
    this->qtw = new QTabWidget();
    this->tab1 = new QWidget();
    this->tab2 = new QWidget();
    this->tab1->setLayout(new QBoxLayout(QBoxLayout::LeftToRight));
    this->tab2->setLayout(new QBoxLayout(QBoxLayout::LeftToRight));
    this->qtw->addTab(tab1,QPixmap(":Images/Work.png"),"&Редактор");
    this->qtw->setIconSize(QSize(20,20));
    this->qtw->addTab(tab2,QPixmap(":Images/Use.png"),"&Работа");

    //this->qtw->setStyleSheet(" QTabWidget::tab-bar { alignment: left; position: relative; bottom: -37.5em;} QTabWidget::pane {bottom: 2em;} ");

    this->menuBar->addMenu(pmenu);
    this->menuBar->setStyleSheet("QMenuBar { background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 WHITE, stop: 0.4 #D4DFEF, stop: 0.5 #BDCFEB, stop: 1.0 WHITE); spacing: 5px; border: 2px solid #B2C8EA }");

    this->pmenu->addAction(QPixmap(":Images/New.png"),"Создать");
    this->pmenu->addAction(QPixmap(":Images/Save.png"),"Сохранить");
    this->pmenu->addAction(QPixmap(":Images/Load.png"),"Загрузить");
    this->pmenu->addSeparator();
    this->pmenu->addAction(QPixmap(":Images/Exit.png"),"Выйти",this,SLOT(close()));

    this->qtoolbar = new QToolBar("Панель инструментов",this);
    this->qtoolbar->setStyleSheet("QToolBar { background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 WHITE, stop: 0.4 #D4DFEF, stop: 0.5 #BDCFEB, stop: 1.0 WHITE); spacing: 5px; border: 2px solid #B2C8EA }"); // #BBD4E8
    this->qtoolbar->setMovable(true);
    this->qtoolbar->setFloatable(true);


    this->qbl->setMargin(1);
    this->qbl->addWidget(menuBar);
    this->qbl->addWidget(this->qtoolbar);
    this->qbl->addWidget(qtw);
    this->state = new QLabel("Сущность");
    this->qbl->addWidget(this->state);

    //==============================================
    QScrollArea* scrollarea1 = new QScrollArea();
    scrollarea1->setMaximumWidth(5000);
    scrollarea1->setMaximumHeight(5000);
    scrollarea1->setMinimumHeight(250);
    scrollarea1->setMinimumWidth(250);
    this->w11 = new WorkPlaceWidget();
    w11->setCore(this->core);
    w11->setFrameStyle(QFrame::Panel);
    QWidget* w21 = new QWidget();
    scrollarea1->setWidget(w11);
    this->tab1->layout()->addWidget(scrollarea1);
    this->tab1->layout()->addWidget(w21);
    QBoxLayout* blt = new QBoxLayout(QBoxLayout::TopToBottom);
    w21->setMaximumWidth(400);
    w21->setMinimumWidth(400);
    w21->setLayout(blt);
    //==============================================
    this->ecw = new EntitieCustomeWidget();
    ecw->setCore(this->core);
    //==============================================
    QPixmap EntitieIcon(":Images/Entitie.png");
    QPixmap RelationIcon(":Images/Relation.png");
    QPixmap SelectionIcon(":Images/Selection.png");
    QPixmap SendIcon(":Images/Send.png");
    //==============================================
    QWidget* pbButtons = new QWidget();
    pbButtons->setLayout(new QBoxLayout(QBoxLayout::LeftToRight));
    this->pb0 = new QPushButton("Сущность");
    pb0->setIcon(EntitieIcon);
    pb0->setIconSize(QSize(20,20));
    pb0->setCheckable(true);
    this->pb1 = new QPushButton("Связь");
    pb1->setIcon(RelationIcon);
    pb1->setIconSize(QSize(20,20));
    pb1->setCheckable(true);
    this->pb2 = new QPushButton("Выделить");
    pb2->setIcon(SelectionIcon);
    pb2->setIconSize(QSize(20,20));
    pb2->setCheckable(true);
    pb2->setChecked(true);

    this->pb0b = new QPushButton();
    pb0b->setIcon(EntitieIcon);
    pb0b->setIconSize(QSize(15,15));
    pb0b->setCheckable(true);
    this->pb1b = new QPushButton();
    pb1b->setIcon(RelationIcon);
    pb1b->setIconSize(QSize(15,15));
    pb1b->setCheckable(true);
    this->pb2b = new QPushButton();
    pb2b->setIcon(SelectionIcon);
    pb2b->setIconSize(QSize(15,15));
    pb2b->setCheckable(true);
    pb2b->setChecked(true);
    //QPushButton* pb3 = new QPushButton("Указатель");

    this->pb4 = new QPushButton("Удалить");
    this->pb5 = new QPushButton("Сохранить");
    QPushButton* pb6 = new QPushButton(); // "Отправить посылку"
    pb6->setIcon(SendIcon);
    pb6->setIconSize(QSize(400,100));
    //QPushButton* pb7 = new QPushButton("Обновить список сущностей");
    //==============================================
        pbButtons->layout()->addWidget(pb0);
        pbButtons->layout()->addWidget(pb1);
        pbButtons->layout()->addWidget(pb2);
        //pbButtons->layout()->addWidget(pb3);

        //w21->layout()->addWidget(pbButtons);
        ((QBoxLayout*)(w21->layout()))->addWidget(pbButtons);
        ((QBoxLayout*)(w21->layout()))->addStretch();
        ((QBoxLayout*)(w21->layout()))->addWidget(ecw,Qt::AlignTop);
        //blt->addStretch();
        w21->layout()->addWidget(pb5);
        w21->layout()->addWidget(pb4);
    //==============================================
        QScrollArea* scrollarea2 = new QScrollArea();
        scrollarea2->setMaximumWidth(5000);
        scrollarea2->setMaximumHeight(5000);
        scrollarea2->setMinimumHeight(250);
        scrollarea2->setMinimumWidth(250);
        this->w12 = new WorkPlaceWidget();
        w12->setCore(this->core);
        w12->setFrameStyle(QFrame::Panel);
        QWidget* w22 = new QWidget();
        scrollarea2->setWidget(w12);
        this->tab2->layout()->addWidget(scrollarea2);
        this->tab2->layout()->addWidget(w22);
        QBoxLayout* blt2 = new QBoxLayout(QBoxLayout::TopToBottom);
        w22->setMaximumWidth(400);
        w22->setMinimumWidth(400);
        w22->setLayout(blt2);
        //==============================================
            //this->tab1->setStyleSheet("border: 1px solid black");

            this->te = new QTextEdit();
            this->te->setReadOnly(true);
            this->te->isMaximized();
            QScrollArea* scrollarea3 = new QScrollArea();
            QBoxLayout* a = new QBoxLayout(QBoxLayout::TopToBottom);
            a->addWidget(te);
            scrollarea3->setLayout(a);
            //scrollarea3->setWidget(te);
            scrollarea3->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
//            scrollarea3->setMaximumWidth(500);
//            scrollarea3->setMaximumHeight(500);
//            scrollarea3->setMinimumHeight(350);
//            scrollarea3->setMinimumWidth(100);
            scrollarea3->viewport()->isMaximized();
            //scrollarea3->
            w22->layout()->addWidget(new QLabel("Получатель"));
            this->cb = new QComboBox();
            this->cb2 = new QComboBox();
            w22->layout()->addWidget(cb);
            w22->layout()->addWidget(new QLabel("Отправитель"));
            w22->layout()->addWidget(cb2);
            //blt2->addStretch();
            //w22->layout()->addWidget(pb7);
            blt2->addWidget(scrollarea3);
            w22->layout()->addWidget(pb6);

    //==============================================
    this->setLayout(qbl);
    // Соединение со сингналов со слотами
    //==============================================
    this->pb0b->setToolTip("Инструмент сущность");
    this->pb1b->setToolTip("Инструмент связь");
    this->pb2b->setToolTip("Инструмент выделение");
    this->qtoolbar->addWidget(pb0b);
    this->qtoolbar->addWidget(pb1b);
    this->qtoolbar->addWidget(pb2b);
    QObject::connect(pb0b,SIGNAL(clicked()),this,SLOT(button1Pressed()));
    QObject::connect(pb1b,SIGNAL(clicked()),this,SLOT(button2Pressed()));
    QObject::connect(pb2b,SIGNAL(clicked()),this,SLOT(button3Pressed()));
    QObject::connect(pb0,SIGNAL(clicked()),this,SLOT(button1Pressed()));
    QObject::connect(pb1,SIGNAL(clicked()),this,SLOT(button2Pressed()));
    QObject::connect(pb2,SIGNAL(clicked()),this,SLOT(button3Pressed()));
    //QObject::connect(pb3,SIGNAL(clicked()),this,SLOT(button4Pressed()));
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
        this->core->setState(10);
        this->core->setFocus(-1);
        if(this->core->isChanged()){
            this->core->setWeightOfSolution(-1);
            this->te->clear();
        }
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
        this->pb0b->setChecked(false);
        this->pb1b->setChecked(false);
        this->pb2b->setChecked(false);
        this->pb0b->setEnabled(false);
        this->pb1b->setEnabled(false);
        this->pb2b->setEnabled(false);
        //setCursor(Qt::ArrowCursor);
    }else{
        this->core->setState(2);
        this->core->Changed(false);
        this->pb0->setChecked(false);
        this->pb1->setChecked(false);
        this->pb2->setChecked(true);
        this->pb0b->setChecked(false);
        this->pb1b->setChecked(false);
        this->pb2b->setChecked(true);
        this->pb0b->setEnabled(true);
        this->pb1b->setEnabled(true);
        this->pb2b->setEnabled(true);
    }
}

void MainWindow::button1Pressed(){
    this->state->setText("Сущность");
    this->core->setState(0);
    this->core->setFocus(-1);
    this->core->setFocusObj(true);
    this->w11->repaint();
    this->pb0->setChecked(true);
    this->pb0b->setChecked(true);
    this->pb1->setChecked(false);
    this->pb2->setChecked(false);
    this->pb1b->setChecked(false);
    this->pb2b->setChecked(false);
    //setCursor(Qt::SizeAllCursor);
}

void MainWindow::button2Pressed(){
    this->state->setText("Связь");
    this->core->setState(1);
    this->core->setFocus(-1);
    this->core->setFocusObj(true);
    this->w11->repaint();
    this->pb1->setChecked(true);
    this->pb0->setChecked(false);
    this->pb2->setChecked(false);
    this->pb1b->setChecked(true);
    this->pb0b->setChecked(false);
    this->pb2b->setChecked(false);
    //setCursor(Qt::CrossCursor);
}

void MainWindow::button3Pressed(){
    this->state->setText("Выделить");
    this->core->setState(2);
    this->w11->repaint();
    this->pb0->setChecked(false);
    this->pb1->setChecked(false);
    this->pb2->setChecked(true);
    this->pb0b->setChecked(false);
    this->pb1b->setChecked(false);
    this->pb2b->setChecked(true);
    //setCursor(Qt::ArrowCursor);
}

//void MainWindow::button4Pressed(){
//    this->state->setText("Указатель");
//    this->core->setState(3);
//    this->w11->repaint();
//}

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
        this->core->Changed(true);
    }
}

void MainWindow::buttonway(){
    int i;
    this->state->setText("Нахождение оптимального пути");
    string en1 = this->cb->currentText().toStdString();
    string en2 = this->cb2->currentText().toStdString();
    Entitie* e1 = this->core->getEntitieByID(en1);
    Entitie* e2 = this->core->getEntitieByID(en2);
    if(e1!=NULL && e2!=NULL){
        List<string>* way = core->getBestWay(e1,e2);
        i=0;
        te->clear();
        if(way->size()!=0){
            Entitie* e0 = NULL;
            double totalTime = 0;
            double totalSpeed = 0;
            double totalDistance = 0;
            while (i<way->size()){
                Entitie* e = this->core->getEntitieByID(way->at(i));
                if(e0!=NULL){
                    double dist = this->core->getDistanceBetween(e,e0);
                    int speed = this->core->getSpeedOf(e0)*5;
                    double time = dist / speed;
                    totalTime +=time;
                    totalSpeed +=speed;
                    totalDistance +=dist;
                    this->te->append("Дистанция: "+QString::number(dist)+"\nСкорость: "+QString::number(speed)+"\nВремя: "+QString::number(time));
                    this->te->append("_________________________________________________");
                }
                this->te->append(""+QString::number(i+1)+") " + QString::fromStdString(way->at(i)));
                i++;
                e0 = e;
            }
            this->te->append("\nОбщая дистанция: "+QString::number(totalDistance)+"\nСредняя скорость: "+QString::number(totalSpeed/i)+"\nВремя пути: "+QString::number(totalTime));
        }else{
           this->te->append("Путь не найден");
        }
        this->w12->repaint();
    }
}

void MainWindow::button6Pressed(){
    if(this->core->getFocus()!=-1){
        this->state->setText("Сохранить");
        if(core->getFocusObj()){
            this->ecw->save();
        }else{
            Relation* r = this->core->getRelationAt(core->getFocus());
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
            this->core->setFocus(this->core->getRelationCount()-1);
            //this->ecw
        }
        this->w11->repaint();
    }
    this->core->Changed(true);
}

void MainWindow::timerEvent(){
    if(core->getFocus()==-1){
       if(this->pb4->isEnabled() && this->pb5->isEnabled()){
          this->pb4->setEnabled(false);
          this->pb5->setEnabled(false);
       }
    }else{
        if(!this->pb4->isEnabled() || !this->pb5->isEnabled()){
           this->pb4->setEnabled(true);
           this->pb5->setEnabled(true);
        }
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

