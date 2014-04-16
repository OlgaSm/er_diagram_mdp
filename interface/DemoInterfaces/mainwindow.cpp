#include "mainwindow.h"
#include <QMenuBar>
#include <QMenu>
#include <QBoxLayout>
#include <QTabWidget>
#include <QLabel>
#include <QPushButton>
#include <QComboBox>
#include <QFrame>
#include "workplacewidget.h"

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
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
    //this->qbl->addStretch();

    //==============================================
    WorkPlaceWidget* w11 = new WorkPlaceWidget();
    w11->setFrameStyle(QFrame::Panel);
    QWidget* w21 = new QWidget();
    this->tab1->layout()->addWidget(w11);
    this->tab1->layout()->addWidget(w21);
    QBoxLayout* blt = new QBoxLayout(QBoxLayout::TopToBottom);
    w21->setLayout(blt);
    //==============================================
        //this->tab1->setStyleSheet("border: 1px solid black");
        w21->layout()->addWidget(new QPushButton("Сущность"));
        w21->layout()->addWidget(new QPushButton("Связь"));
        w21->layout()->addWidget(new QPushButton("Выжедить"));
        w21->layout()->addWidget(new QPushButton("Стрелка"));
        blt->addStretch();
        w21->layout()->addWidget(new QPushButton("Удалить"));
    //==============================================
        WorkPlaceWidget* w12 = new WorkPlaceWidget();
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
}

MainWindow::~MainWindow()
{

}
