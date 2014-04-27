#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QMenuBar>
#include <QMenu>
#include <QLineEdit>
#include <QBoxLayout>
#include <QTextEdit>
#include <QLabel>
#include <QTabWidget>
#include <QComboBox>
#include "Contaner/Core.h"
#include "workplacewidget.h"
#include "entitiecustomewidget.h"
#include <QToolBar>
class MainWindow : public QWidget{

    Q_OBJECT
private:
    QTimer* timer;
    QMenuBar* menuBar;
    QMenu* pmenu;
    QBoxLayout* qbl;
    QTabWidget* qtw;
    WorkPlaceWidget* w11;
    WorkPlaceWidget* w12;
    EntitieCustomeWidget* ecw;
    QPushButton* pb0;
    QPushButton* pb1;
    QPushButton* pb2;
    QPushButton* pb4;
    QPushButton* pb5;
    QPushButton* pb0b;
    QPushButton* pb1b;
    QPushButton* pb2b;
    //QLineEdit* le;
    QTextEdit* te;
    QWidget* tab1;
    QWidget* tab2;
    QComboBox* cb;
    QComboBox* cb2;
    QLabel* state;
    Core* core;
    QToolBar* qtoolbar;

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void button1Pressed();
    void button2Pressed();
    void button3Pressed();
    //void button4Pressed();
    void button5Pressed();
    void button6Pressed();
    void buttonway();
    //void button7Pressed();
    void tabChanged();
    void timerEvent();
};

#endif // MAINWINDOW_H
