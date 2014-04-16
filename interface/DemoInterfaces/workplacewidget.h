#ifndef WORKPLACEWIDGET_H
#define WORKPLACEWIDGET_H

#include <QWidget>
#include <QFrame>
#include <QPaintEvent>

class WorkPlaceWidget : public QFrame
{
    Q_OBJECT
public:
    explicit WorkPlaceWidget(QWidget *parent = 0);
    void paintEvent(QPaintEvent *);
signals:

public slots:

};

#endif // WORKPLACEWIDGET_H
