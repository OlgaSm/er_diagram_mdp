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

class MainWindow : public QWidget{

    Q_OBJECT
private:
    QMenuBar* menuBar;
    QMenu* pmenu;
    QBoxLayout* qbl;
    QTabWidget* qtw;
    WorkPlaceWidget* w11;
    WorkPlaceWidget* w12;
    EntitieCustomeWidget* ecw;
    //QLineEdit* le;
    QTextEdit* te;
    QWidget* tab1;
    QWidget* tab2;
    QComboBox* cb;
    QComboBox* cb2;
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
    void button6Pressed();
    void buttonway();
    void button7Pressed();
    void tabChanged();
};

#endif // MAINWINDOW_H
