#ifndef WORKPLACEWIDGET_H
#define WORKPLACEWIDGET_H

#include <QWidget>
#include <QFrame>
#include <QPaintEvent>
#include "Contaner/Core.h"

class WorkPlaceWidget : public QFrame
{
    Q_OBJECT
private:
    Core* core;
    void paintDesk();
    void drawEntitie(Entitie* e, bool focus);
    void drawRelation(Relation* r, bool focus);
    void calculateEntitie(Entitie* e);

public:
    explicit WorkPlaceWidget(QWidget *parent = 0);
    void paintEvent(QPaintEvent *);
    void setCore(Core* core);
signals:

public slots:

protected:
    virtual void mousePressEvent(QMouseEvent* pe);

};

#endif // WORKPLACEWIDGET_H
