#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QMenuBar>
#include <QMenu>
#include <QBoxLayout>
#include <QLabel>
#include <QTabWidget>
#include "Contaner/Core.h"
#include "workplacewidget.h"

class MainWindow : public QWidget{

    Q_OBJECT
private:
    QMenuBar* menuBar;
    QMenu* pmenu;
    QBoxLayout* qbl;
    QTabWidget* qtw;
    WorkPlaceWidget* w11;
    WorkPlaceWidget* w12;

    QWidget* tab1;
    QWidget* tab2;

    QLabel* state;
    Core* core;

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void button1Pressed();
    void button2Pressed();
    void button3Pressed();
    void button4Pressed();
    void button5Pressed();
};

#endif // MAINWINDOW_H
