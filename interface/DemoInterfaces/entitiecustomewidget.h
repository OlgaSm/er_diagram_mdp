#ifndef ENTITIECUSTOMEWIDGET_H
#define ENTITIECUSTOMEWIDGET_H

#include <QWidget>
#include <QMenuBar>
#include <QLineEdit>
#include <QBoxLayout>
#include <QLabel>
#include <QTimer>
#include <QCheckBox>
#include "lineoffield.h"
#include "Contaner/Core.h"
#include "Contaner/ERDiagram.h"
#include "Contaner/Entitie.h"
#include "Contaner/Relation.h"
#include "Contaner/List.h"
#include "workplacewidget.h"

class EntitieCustomeWidget : public QWidget
{
    Q_OBJECT
private:
    Core* core;
    int curFocus;
    bool curObj;

public:
    explicit EntitieCustomeWidget(QWidget *parent = 0);
    void setCore(Core* core);
    Core* getCore();
    QBoxLayout* qbl;
    QLabel* entitieName;
    QLineEdit* tb;
    QLineEdit* key;
    QTimer* timer;
    QCheckBox* ml;
    QCheckBox* mr;
    QCheckBox* al;
    QCheckBox* ar;
    List<LineOfField*>* fildlist;

signals:

public slots:
    void timerEvent();

};

#endif // ENTITIECUSTOMEWIDGET_H
