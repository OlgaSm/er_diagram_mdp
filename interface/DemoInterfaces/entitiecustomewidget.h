#ifndef ENTITIECUSTOMEWIDGET_H
#define ENTITIECUSTOMEWIDGET_H

#include <QWidget>
#include <QMenuBar>
#include <QLineEdit>
#include <QBoxLayout>
#include <QLabel>
#include <QTimer>
#include "lineoffield.h"
#include "Contaner/Core.h"
#include "Contaner/ERDiagram.h"
#include "Contaner/Entitie.h"
#include "workplacewidget.h"

class EntitieCustomeWidget : public QWidget
{
    Q_OBJECT
private:
    Core* core;
    int curFocus;

public:
    explicit EntitieCustomeWidget(QWidget *parent = 0);
    void setCore(Core* core);
    Core* getCore();

signals:

public slots:
    void timerEvent();

};

#endif // ENTITIECUSTOMEWIDGET_H
