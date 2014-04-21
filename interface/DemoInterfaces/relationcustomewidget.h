#ifndef RELATIONCUSTOMEWIDGET_H
#define RELATIONCUSTOMEWIDGET_H

#include <QWidget>
#include <QMenuBar>
#include <QLineEdit>
#include <QBoxLayout>
#include <QLabel>
#include <QTimer>
#include "lineoffield.h"
#include "Contaner/Core.h"
#include "Contaner/ERDiagram.h"
#include "Contaner/Relation.h"
#include "workplacewidget.h"

class RelationCustomeWidget : public QWidget
{
    Q_OBJECT
private:
    Core* core;
    QBoxLayout* qbl;
    QLabel* entitieName;
    QLineEdit* tb;
    QTimer *timer;
    int curFocus;

public:
    explicit EntitieCustomeWidget(QWidget *parent = 0);
    void setCore(Core* core);
    Core* getCore();

signals:

public slots:
    void timerEvent();

};

#endif // RELATIONCUSTOMEWIDGET_H
