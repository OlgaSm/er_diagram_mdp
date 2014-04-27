#include "workplacewidget.h"
#include <QPainter>
#include "Contaner/Entitie.h"
#include "Contaner/Relation.h"
#include "Contaner/IntField.h"
#include <string>
#include <sstream>
#include <math.h>
#define max_width 5000
#define max_height 2500
#define work_count 6

WorkPlaceWidget::WorkPlaceWidget(QWidget *parent) :
    QFrame(parent){
    this->core = new Core();
    QRect r2(0,0,this->size().width()-1,this->size().height()-1);
    this->setMinimumHeight(max_height);
    this->setMinimumWidth(max_width);
    this->scroll(this->size().width()-1,this->size().height()-1,r2);
    this->curX=-1;
    this->curY=-1;
}

void WorkPlaceWidget::paintEvent(QPaintEvent *){
        QPainter painter(this);
        QRect r2(0,0,this->size().width()-1,this->size().height()-1);
        QPixmap pm(":Images/Map.png");
        painter.drawPixmap(0,0,this->size().width()-1,this->size().height()-1,pm);
        painter.drawRect(r2);
        this->paintDesk();
}

void WorkPlaceWidget::paintDesk(){
    this->core->spotFocus();
    for(int i=0; i<this->core->getEntitieCount(); i++){
       this->drawEntitie(this->core->getEntitieAt(i),(i==this->core->getFocus() && this->core->getFocusObj()));
    }
    for(int i=0; i<this->core->getRelationCount(); i++){
        drawRelation(this->core->getRelationAt(i),((i==this->core->getFocus())&&(!this->core->getFocusObj())));
    }
//    if(this->core->getState()==0){
//        QPainter painter(this);
//        //QRect r(this->curX,this->curY,100,50); cursor().pos().x()
//        QRect r(cursor().pos().x(),cursor().pos().y(),100,50);
//        painter.drawRect(r);
//    }
}



void WorkPlaceWidget::drawEntitie(Entitie* e, bool focus){
    QPainter painter(this);
    QColor color(255,200,125);
    QColor color1(255,170,100);
    QColor color2(215,215,255);
    QColor colorRed(252,139,130);
    QColor colorGreen(125,220,125);
    QColor colorGreenAlpha(55,155,55,25);
    QColor colorBlackAlpha(0,0,0,100);
    QPen pen1 = QPen(Qt::black, 1, Qt::SolidLine);
    QPen pen2 = QPen(colorBlackAlpha, 1, Qt::SolidLine);
    painter.setPen(pen1);

    this->calculateEntitie(e);
    int x = ((IntField*)e->fieldByID("X"))->getValue();
    int y = ((IntField*)e->fieldByID("Y"))->getValue();
    int w = ((IntField*)e->fieldByID("W"))->getValue();
    int h = ((IntField*)e->fieldByID("H"))->getValue();
    int t = ((IntField*)e->fieldByID("T"))->getValue();

    if(this->core->getState()==10 && this->core->getWeightOfSolution()!=-1){
        bool green = false;
        for(int i=0; i<this->core->getBestWay()->size(); i++){
            if(e->getID()==this->core->getBestWay()->at(i)){
                green = true;
            }
        }
        if(t!=1){
            if(green){
                painter.setBrush(QBrush(colorGreen));
            }else{
                painter.setBrush(QBrush(colorRed));
            }
        }else{
           painter.setBrush(QBrush(color2));
        }
    }else{
        if(t==0){
            painter.setBrush(QBrush(color1));
        }else if(t==1){
            painter.setBrush(QBrush(color2));
        }else{
            painter.setBrush(QBrush(color));
        }
    }

    if(x>max_width-w-5){
        ((IntField*)e->fieldByID("X"))->setValue(max_width-w-5);
        x=max_width-w-5;
    }
    if(y>max_height-h-5){
        ((IntField*)e->fieldByID("Y"))->setValue(max_height-h-5);
        y=max_height-h-5;
    }
    if(x<5){
        ((IntField*)e->fieldByID("X"))->setValue(5);
        x=5;
    }
    if(y<5){
        ((IntField*)e->fieldByID("Y"))->setValue(5);
        y=5;
    }
    string label = e->getID();
    QRect r1(x,y,w,h);
    QRect r12(x+5,y+5,w-10,h-10);
    QRect r2(x,y,w,20);
    if(focus){
        QRect rf(x-2,y-2,w+4,h+4);
        painter.drawRect(rf);
    }
    painter.drawRect(r1);
    painter.drawRect(r2);
    painter.drawText(r12,label.c_str());
    for(int i=work_count; i<e->fieldCount(); i++){
       string field = e->fieldAt(i)->getID();
       QRect tr(x+5,y+5+(i+1-work_count)*24,w-10,h-10);
       painter.drawText(tr,field.c_str());
    }
    if(t!=1){
        double distance = this->core->getDistanceOf(e);
        painter.setBrush(QBrush(Qt::black));
        painter.drawEllipse(QPoint(x-1,y-1), 2, 2);
        if(focus){
            painter.setBrush(QBrush(colorGreenAlpha));
            painter.setPen(pen2);
            painter.drawEllipse(QPoint(x-1,y-1), (int)qRound(distance), (int)qRound(distance));
        }
     }
}

void WorkPlaceWidget::drawRelation(Relation* r, bool focus){
    QPainter painter(this);
    QColor color(90,185,255);

    painter.setBrush(QBrush(color));

    Entitie* eR = r->getEntR();
    Entitie* eL = r->getEntL();
    int indexR = 0;
    int indexL = 0;
    for(int j=0; j<eR->fieldCount() && indexR==0; j++){
        if(eR->fieldAt(j)->getID()==r->getKey()){
            indexR = j;
        }
    }
    for(int j=0; j<eL->fieldCount() && indexL==0; j++){
        if(eL->fieldAt(j)->getID()==r->getKey()){
            indexL = j;
        }
    }
    if(indexR<work_count-1){
        indexR=work_count-1;
    }
    if(indexL<work_count-1){
        indexL=work_count-1;
    }
    this->calculateEntitie(eL);
    this->calculateEntitie(eR);
    int x1 = ((IntField*)eR->fieldByID("X"))->getValue();
    int y1 = ((IntField*)eR->fieldByID("Y"))->getValue();
    int w1 = ((IntField*)eR->fieldByID("W"))->getValue();
    int h1 = ((IntField*)eR->fieldByID("H"))->getValue();
    //int t1 = ((IntField*)eR->fieldByID("T"))->getValue();
    int x2 = ((IntField*)eL->fieldByID("X"))->getValue();
    int y2 = ((IntField*)eL->fieldByID("Y"))->getValue();
    int w2 = ((IntField*)eL->fieldByID("W"))->getValue();
    int h2 = ((IntField*)eL->fieldByID("H"))->getValue();
    //int t2 = ((IntField*)eR->fieldByID("T"))->getValue();

    int x01=0;
    int x02=0;
    int y01=0;
    int y02=0;
    if(qAbs(x1-x2)>=w2 && qAbs(x1-x2)>=w1){
        if(x1>x2){
            x01=x1;
            x02=x2+w2+1;
        }else{
            x02=x2;
            x01=x1+w1+1;
        }
        y01 = y1+(indexR+1-work_count)*24+((indexR+1-(work_count-1))*24-(indexR+1-work_count)*24)/2;
        y02 = y2+(indexL+1-work_count)*24+((indexL+1-(work_count-1))*24-(indexL+1-work_count)*24)/2;
    }else{
        if(y1>y2){
            y01=y1;
            y02=y2+h2+1;
        }else{
            y02=y2;
            y01=y1+h1+1;
        }
        x01=x1+w1/2;
        x02=x2+w2/2;
    }
    int x0 = 0;
    int y0 = 0;
    QPointF p1(x01,y01);
    QPointF p2(x02,y02);
    if(x01>x02){
        x0 = x02 + (x01 - x02)/2;
    }else{
        x0 = x01 + (x02 - x01)/2;
    }
    if(y01>y02){
        y0 = y02 + (y01 - y02)/2;
    }else{
        y0 = y01 + (y02 - y01)/2;
    }
    QPointF p0(x0,y0);
    QPen pen1 = QPen(Qt::black, 1, Qt::DotLine);
    QPen pen2 = QPen(Qt::black, 1, Qt::SolidLine);
    QPen pen3 = QPen(Qt::black, 2, Qt::SolidLine);
    QPen pen4 = QPen(Qt::black, 2, Qt::DotLine);
    if(r->getAbsL()){
        if(focus){
            painter.setPen(pen4);
        }else{
            painter.setPen(pen1);
        }
    }else{
        if(focus){
            painter.setPen(pen3);
        }else{
            painter.setPen(pen2);
        }
    }
    painter.drawLine(p1,p0);
    if(r->getAbsR()){
        if(focus){
            painter.setPen(pen4);
        }else{
            painter.setPen(pen1);
        }
    }else{
        if(focus){
            painter.setPen(pen3);
        }else{
            painter.setPen(pen2);
        }
    }
    painter.drawLine(p0,p2);
    if(focus){
        painter.setPen(pen3);
    }else{
        painter.setPen(pen2);
    }
    painter.drawEllipse(p0, 10, 10);
    if(r->getMulL()){
        QRect tr(p0.x()-7,p0.y()-7,12,12);
        painter.drawText(tr,"n");
    }
    if(r->getMulR()){
        QRect tr(p0.x()+3,p0.y()-7,12,12);
        painter.drawText(tr,"n");
    }
    painter.setPen(pen2);
    painter.drawLine(QPointF(p0.x(),p0.y()-10),QPointF(p0.x(),p0.y()+10));
}

void WorkPlaceWidget::calculateEntitie(Entitie* e){
    int height = e->fieldCount() - (work_count-1);
    if(height<1) height = 1;
    ((IntField*)e->fieldByID("H"))->setValue(height*24);
}

void WorkPlaceWidget::setCore(Core* core){
    this->core=core;
}

void WorkPlaceWidget::mousePressEvent(QMouseEvent* pe){
    if(this->core->getState()==0){ // Добавление сущности
        //=====================================================
        string name;
        int num = this->core->getCounter();
        char str[255];
        sprintf(str, "Entitie № %d", num);
        name = (const char*)str;
        Entitie* e0 = new Entitie(name);
        e0->addUserField(new IntField("X",pe->x()));
        e0->addUserField(new IntField("Y",pe->y()));
        e0->addUserField(new IntField("W",100));
        e0->addUserField(new IntField("H",100));
        e0->addUserField(new IntField("F",1));
        e0->addUserField(new IntField("T",-1));
        calculateEntitie(e0);
        //=====================================================


        bool add = true;
        for(int i=0; i<this->core->getEntitieCount(); i++){
           Entitie* e = this->core->getEntitieAt(i);
           int x = ((IntField*)e->fieldByID("X"))->getValue();
           int y = ((IntField*)e->fieldByID("Y"))->getValue();
           int w = ((IntField*)e->fieldByID("W"))->getValue();
           int h = ((IntField*)e->fieldByID("H"))->getValue();
           int w0 =((IntField*)e0->fieldByID("W"))->getValue();
           int h0 =((IntField*)e0->fieldByID("H"))->getValue();
           if((x-w0-15<pe->x())&&(y-h0-15<pe->y())&&(w+x+15>pe->x())&&(h+y+15>pe->y())){
               add = false;
           }
        }
        if(add){
            this->core->Changed(true);
            core->addEntitieTo(e0);
            core->setFocus(core->getIndexEntitieByID(e0->getID()));
            this->repaint();
        }
    }
    if(this->core->getState()==1){ // Добавление связи
        //if(core->getFocusObj())
        int focus = -1;
        for(int i=0; i<this->core->getEntitieCount(); i++){
           Entitie* e = this->core->getEntitieAt(i);
           int x =((IntField*)e->fieldByID("X"))->getValue();
           int y = ((IntField*)e->fieldByID("Y"))->getValue();
           int w = ((IntField*)e->fieldByID("W"))->getValue();
           int h = ((IntField*)e->fieldByID("H"))->getValue();
           if((x<pe->x())&&(y<pe->y())&&(w+x>pe->x())&&(h+y>pe->y())){
               focus = i;
           }
        }
        if(core->getFocus()==-1 || !core->getFocusObj()){
            //core->e= this->core->getEntitieCount(focus);
            core->setFocus(focus);
            core->setFocusObj(true);
        }else{
            if(focus!=this->core->getFocus() && focus!=-1){
                string name;
                int num = this->core->getCounter();
                char str[255];
                sprintf(str, "Relation № %d", num);
                name = (const char*)str;

                Entitie* e1 = this->core->getEntitieAt(this->core->getFocus());
                Entitie* e2 = this->core->getEntitieAt(focus);
                core->addRelation(e1,e2,name,"W");
                this->core->Changed(true);
            }
            this->core->setFocus(core->getRelationCount()-1);
            //core->setFocus(-1);
            core->setFocusObj(false);
        }
        core->spotFocus();
        this->repaint();
    }
    if(this->core->getState()==2 || this->core->getState()==10){ // Выделение объектов
        for(int i=0; i<this->core->getEntitieCount(); i++){
           Entitie* e = this->core->getEntitieAt(i);
           int x =((IntField*)e->fieldByID("X"))->getValue();
           int y = ((IntField*)e->fieldByID("Y"))->getValue();
           int w = ((IntField*)e->fieldByID("W"))->getValue();
           int h = ((IntField*)e->fieldByID("H"))->getValue();
           if((x<pe->x())&&(y<pe->y())&&(w+x>pe->x())&&(h+y>pe->y())){
               core->setFocus(i);
               core->setFocusObj(true);
           }
        }
        for(int i=0; i<this->core->getRelationCount(); i++){
           Relation* r = this->core->getRelationAt(i);
           Entitie* eR = r->getEntR();
           Entitie* eL = r->getEntL();

           int indexR = 0;
           int indexL = 0;
           for(int j=0; j<eR->fieldCount() && indexR==0; j++){
               if(eR->fieldAt(j)->getID()==r->getKey()){
                   indexR = j;
               }
           }
           for(int j=0; j<eL->fieldCount() && indexL==0; j++){
               if(eL->fieldAt(j)->getID()==r->getKey()){
                   indexL = j;
               }
           }
           if(indexR<work_count-1){
               indexR=work_count-1;
           }
           if(indexL<work_count-1){
               indexL=work_count-1;
           }
           //this->calculateEntitie(eR);
           //this->calculateEntitie(eL);
           int x1 = ((IntField*)eR->fieldByID("X"))->getValue();
           int y1 = ((IntField*)eR->fieldByID("Y"))->getValue();
           int w1 = ((IntField*)eR->fieldByID("W"))->getValue();
           int h1 = ((IntField*)eR->fieldByID("H"))->getValue();
           int x2 = ((IntField*)eL->fieldByID("X"))->getValue();
           int y2 = ((IntField*)eL->fieldByID("Y"))->getValue();
           int w2 = ((IntField*)eL->fieldByID("W"))->getValue();
           int h2 = ((IntField*)eL->fieldByID("H"))->getValue();

           int x01=0;
           int x02=0;
           int y01=0;
           int y02=0;

           if(qAbs(x1-x2)>w2 && qAbs(x1-x2)>w1){
               if(x1>x2){
                   x01=x1;
                   x02=x2+w2;
               }else{
                   x02=x2-5;
                   x01=x1+w1;
               }
               y01 = y1+(indexR+1-work_count)*24+((indexR+1-(work_count-1))*24-(indexR+1-work_count)*24)/2;
               y02 = y2+(indexL+1-work_count)*24+((indexL+1-(work_count-1))*24-(indexL+1-work_count)*24)/2;
           }else{
               if(y1>y2){
                   y01=y1;
                   y02=y2+h2;
               }else{
                   y02=y2;
                   y01=y1+h1;
               }
               x01=x1+w1/2;
               x02=x2+w2/2;
           }

           int x = pe->x();
           int y = pe->y();

           int x0 = 0;
           int y0 = 0;
           if(x01>x02){
               x0 = x02 + (x01 - x02)/2;
           }else{
               x0 = x01 + (x02 - x01)/2;
           }
           if(y01>y02){
               y0 = y02 + (y01 - y02)/2;
           }else{
               y0 = y01 + (y02 - y01)/2;
           }
           if(x<x0+10 && x>x0-10 && y>y0-10 && y<y0+10){
                core->setFocus(i);
                core->setFocusObj(false);
           }

        }
        core->spotFocus();
        this->repaint();
    }
}

//void WorkPlaceWidget::mouseMoveEvent(QMouseEvent* pe){
//    this->curX=pe->x();
//    this->curY=pe->y();
//}
