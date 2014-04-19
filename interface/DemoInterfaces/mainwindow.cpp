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

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{   
    // Модель данных
    //===============================================
    this->core = new Core();
    //core->addEntitie("Entitie1");
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
    WorkPlaceWidget* w11 = new WorkPlaceWidget();
    w11->setCore(this->core);
    w11->setFrameStyle(QFrame::Panel);
    QWidget* w21 = new QWidget();
    this->tab1->layout()->addWidget(w11);
    this->tab1->layout()->addWidget(w21);
    QBoxLayout* blt = new QBoxLayout(QBoxLayout::TopToBottom);
    w21->setLayout(blt);
    //==============================================
    QPushButton* pb0 = new QPushButton("Сущность");
    QPushButton* pb1 = new QPushButton("Связь");
    QPushButton* pb2 = new QPushButton("Выделить");
    QPushButton* pb3 = new QPushButton("Указатель");
    QPushButton* pb4 = new QPushButton("Удалить");
    //==============================================
        //this->tab1->setStyleSheet("border: 1px solid black");
        w21->layout()->addWidget(pb0);
        w21->layout()->addWidget(pb1);
        w21->layout()->addWidget(pb2);
        w21->layout()->addWidget(pb3);
        blt->addStretch();
        w21->layout()->addWidget(pb4);
    //==============================================
        WorkPlaceWidget* w12 = new WorkPlaceWidget();
        w12->setCore(this->core);
        w12->setFrameStyle(QFrame::Panel);
        QWidget* w22 = new QWidget();
        this->tab2->layout()->addWidget(w12);
        this->tab2->layout()->addWidget(w22);
        QBoxLayout* blt2 = new QBoxLayout(QBoxLayout::TopToBottom);
        w22->setLayout(blt2);
        //==============================================
            //this->tab1->setStyleSheet("border: 1px solid black");
            w22->layout()->addWidget(new QLabel("Получатель"));
            w22->layout()->addWidget(new QComboBox());
            w22->layout()->addWidget(new QLabel("Отправитель"));
            w22->layout()->addWidget(new QComboBox());
            blt2->addStretch();
            w22->layout()->addWidget(new QPushButton("Отправить посылку"));
    //==============================================


    //w11->addWidget(new Image);
    this->setLayout(qbl);


//  QPushButton pb0 = new QPushButton("Сущность");
//  QPushButton pb1 = new QPushButton("Связь");
//  QPushButton pb2 = new QPushButton("Выделить");
//  QPushButton pb3 = new QPushButton("Указатель");
//  QPushButton pb4 = new QPushButton("Удалить");
    // Соединение со сингналов со слотами
    //==============================================
    QObject::connect(pb0,SIGNAL(clicked()),this,SLOT(button1Pressed()));
    QObject::connect(pb1,SIGNAL(clicked()),this,SLOT(button2Pressed()));
    QObject::connect(pb2,SIGNAL(clicked()),this,SLOT(button3Pressed()));
    QObject::connect(pb3,SIGNAL(clicked()),this,SLOT(button4Pressed()));
    QObject::connect(pb4,SIGNAL(clicked()),this,SLOT(button5Pressed()));
}

MainWindow::~MainWindow()
{

}


void MainWindow::button1Pressed(){
    this->state->setText("Сущность");
    this->core->setState(0);
}

void MainWindow::button2Pressed(){
    this->state->setText("Связь");
    this->core->setState(1);
}

void MainWindow::button3Pressed(){
    this->state->setText("Выделить");
    this->core->setState(2);
}

void MainWindow::button4Pressed(){
    this->state->setText("Указатель");
    this->core->setState(3);
}

void MainWindow::button5Pressed(){
    this->state->setText("Удалить");
    this->core->setState(4);
}

