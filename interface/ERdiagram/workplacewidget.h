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
    void drawEntitie(Entitie* e, bool focus, bool isAbstract);
    void drawRelation(Relation* r, bool focus);
    void calculateEntitie(Entitie* e);
    int curX;
    int curY;
    int currentMoved;
    bool selected;

public:
    explicit WorkPlaceWidget(QWidget *parent = 0, Core* core = new Core());
    ~WorkPlaceWidget();
    void paintEvent(QPaintEvent *);
signals:

public slots:

protected:
    virtual void mousePressEvent(QMouseEvent* pe);
    virtual void mouseMoveEvent(QMouseEvent* pe);
    virtual void mouseReleaseEvent(QMouseEvent *pe);

};

#endif // WORKPLACEWIDGET_H
