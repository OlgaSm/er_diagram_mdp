#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QMenuBar>
#include <QMenu>
#include <QBoxLayout>
#include <QTabWidget>

class MainWindow : public QWidget{

    Q_OBJECT
private:
    QMenuBar* menuBar;
    QMenu* pmenu;
    QBoxLayout* qbl;
    QTabWidget* qtw;

    QWidget* tab1;
    QWidget* tab2;

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
};

#endif // MAINWINDOW_H
