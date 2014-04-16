#include "workplacewidget.h"
#include <QPainter>

WorkPlaceWidget::WorkPlaceWidget(QWidget *parent) :
    QFrame(parent){
}

//WorkPlaceWidget::paintEvent(QPaintEvent pe){
//    //QPainter painter(this);
//    //QRect r(40,40,100,100);
//    //if(pe.region().contains(r)){
//        //painter.drawRect(r);
//    //}
//    QPainter* fPainter = new QPainter(this);
//    fPainter->begin(this);
//    fPainter->setRenderHint(QPainter::Antialiasing);
//    fPainter->setBrush(QColor(255,255,255));
//    fPainter->drawRect(50,50,100,100);
//    fPainter->end();
//}
void WorkPlaceWidget::paintEvent(QPaintEvent *)
{
        QPainter painter(this);
        QRect r1(40,40,100,100);
        QRect r2(0,0,this->size().width()-1,this->size().height()-1);
        painter.drawRect(r1);
        painter.drawRect(r2);
}
