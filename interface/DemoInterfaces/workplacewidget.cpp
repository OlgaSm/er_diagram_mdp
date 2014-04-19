#include "workplacewidget.h"
#include <QPainter>
#include "Contaner/Entitie.h"
#include "Contaner/Relation.h"
#include "Contaner/IntField.h"
#include <string>
#include <sstream>

WorkPlaceWidget::WorkPlaceWidget(QWidget *parent) :
    QFrame(parent){
    this->core = new Core();
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
void WorkPlaceWidget::paintEvent(QPaintEvent *){
        QPainter painter(this);
        QRect r2(0,0,this->size().width()-1,this->size().height()-1);
        painter.drawRect(r2);
        this->paintDesk();
}

void WorkPlaceWidget::paintDesk(){
    this->core->spotFocus();
    for(int i=0; i<this->core->getEntitieCount(); i++){
       this->drawEntitie(this->core->getEntitieAt(i),(i==this->core->getFocus() && this->core->getFocusObj()));
    }
}



void WorkPlaceWidget::drawEntitie(Entitie* e, bool focus){
    QPainter painter(this);
    this->calculateEntitie(e);
    int x = ((IntField*)e->fieldByID("X"))->getValue();
    int y = ((IntField*)e->fieldByID("Y"))->getValue();
    int w = ((IntField*)e->fieldByID("W"))->getValue();
    int h = ((IntField*)e->fieldByID("H"))->getValue();
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
    for(int i=0; i<e->fieldCount(); i++){
       string field = e->fieldAt(i)->getID();
       QRect tr(x+5,y+5+(i+1)*20,w-10,h-10);
       painter.drawText(tr,field.c_str());
    }
    for(int i=0; i<e->relationCount(); i++){
        drawRelation(e->relationAt(i),(i==this->core->getFocus() && !this->core->getFocusObj()));
    }
}

void WorkPlaceWidget::drawRelation(Relation* r, bool focus){
    QPainter painter(this);
    QColor color ( 128,128,128 );

    painter.setBrush ( palette().background() );

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
    int x1 = ((IntField*)eR->fieldByID("X"))->getValue();
    int y1 = ((IntField*)eR->fieldByID("Y"))->getValue();
    int x2 = ((IntField*)eL->fieldByID("X"))->getValue();
    int y2 = ((IntField*)eL->fieldByID("Y"))->getValue();
    int x01 = x1+5;
    int y01 = y1+(indexR+1)*24;
    int x02 = x2+5;
    int y02 = y2+(indexL+1)*24;
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
    painter.drawLine(p1,p2);
    if(focus){
        QPointF p1(x1+5+1,y1+(indexR+1)*24-1);
        QPointF p2(x2+5+1,y2+(indexL+1)*24-1);
        painter.drawLine(p1,p2);
        QPointF p3(x1+5-1,y1+(indexR+1)*24+1);
        QPointF p4(x2+5-1,y2+(indexL+1)*24+1);
        painter.drawLine(p3,p4);
    }
    painter.drawEllipse(p0, 10, 10);
}

void WorkPlaceWidget::calculateEntitie(Entitie* e){
    int height = e->fieldCount();// - 3;
    if(height<1) height = 1;
    ((IntField*)e->fieldByID("H"))->setValue(height*24);
}

void WorkPlaceWidget::setCore(Core* core){
    this->core=core;
}

void WorkPlaceWidget::mousePressEvent(QMouseEvent* pe){
    if(this->core->getState()==0){
        //=====================================================
        string name;
        int num = this->core->getEntitieCount();
        char str[255];
        sprintf(str, "Entitie № %d", num);
        name = (const char*)str;

        Entitie* e0 = new Entitie(name);
        e0->addUserField(new IntField("X",pe->x()));
        e0->addUserField(new IntField("Y",pe->y()));
        e0->addUserField(new IntField("W",100));
        e0->addUserField(new IntField("H",100));
        e0->addUserField(new IntField("F",1));
        calculateEntitie(e0);
        //=====================================================


        bool add = true;
        for(int i=0; i<this->core->getEntitieCount(); i++){
           Entitie* e = this->core->getEntitieAt(i);
           int x =((IntField*)e->fieldByID("X"))->getValue();
           int y = ((IntField*)e->fieldByID("Y"))->getValue();
           int w = ((IntField*)e->fieldByID("W"))->getValue();
           int h = ((IntField*)e->fieldByID("H"))->getValue();
           int w0 = ((IntField*)e0->fieldByID("W"))->getValue();
           int h0 = ((IntField*)e0->fieldByID("H"))->getValue();
           if((x-w0-15<pe->x())&&(y-h0-15<pe->y())&&(w+x+15>pe->x())&&(h+y+15>pe->y())){
               add = false;
           }
        }
        if(add){
            core->addEntitieTo(e0);
            core->setFocus(num);
            this->repaint();
        }
    }
    if(this->core->getState()==1){
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
        if(core->getFocus()==-1){
            //core->e= this->core->getEntitieCount(focus);
            core->setFocus(focus);
        }else{
            if(focus!=this->core->getFocus() && focus!=-1){
                string name;
                int num = this->core->getRelationCount();
                char str[255];
                sprintf(str, "Relation № %d", num);
                name = (const char*)str;

                Entitie* e1 = this->core->getEntitieAt(this->core->getFocus());
                Entitie* e2 = this->core->getEntitieAt(focus);
                core->addRelation(e1,e2,name,"W");
            }
            core->setFocus(-1);
        }
        core->spotFocus();
        this->repaint();
    }
    if(this->core->getState()==2){
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
           int x1 = ((IntField*)eR->fieldByID("X"))->getValue();
           int y1 = ((IntField*)eR->fieldByID("Y"))->getValue();
           int x2 = ((IntField*)eL->fieldByID("X"))->getValue();
           int y2 = ((IntField*)eL->fieldByID("Y"))->getValue();
           x1 = x1+5;
           y1 = y1+(indexR+1)*24;
           x2 = x2+5;
           y2 = y2+(indexL+1)*24;
//           int x1_1 = x1+3;
//           int y1_1 = y1-3;
//           int x2_1 = x2+3;
//           int y2_1 = y2-3;
//           int x1_2 = x1-3;
//           int y1_2 = y1+3;
//           int x2_2 = x2-3;
//           int y2_2 = y2+3;
           int x = pe->x();
           int y = pe->y();

           int x0 = 0;
           int y0 = 0;
           if(x1>x2){
               x0 = x2 + (x1 - x2)/2;
           }else{
               x0 = x1 + (x2 - x1)/2;
           }
           if(y1>y2){
               y0 = y2 + (y1 - y2)/2;
           }else{
               y0 = y1 + (y2 - y1)/2;
           }
           if((((x1>x2)&&(x2<x)&&(x1>x))||((x1<x2)&&(x2>x)&&(x1<x)))
           &&(((y1>y2)&&(y2<y)&&(y1>y))||((y1<y2)&&(y2>y)&&(y1<y)))){
               if(x<x0+10 && x>x0-10 && y>y0-10 && y<y0+10){
                   core->setFocus(i);
                   core->setFocusObj(false);
               }
//               if((((x1 > x2 && y1 > y2)||(x1 < x2 && y1 > y2))&&(y<=(y1_1-((x1_1-x)*(y1_1-y2_1)/(x1_1-x2_1))))&&(y>=(y1_2-((x1_2-x)*(y1_2-y2_2)/(x1_2-x2_2)))))
//               ||(((x1 < x2 && y1 < y2)||(x1 > x2 && y1 < y2))&&(y>=(y1_1-((x1_1-x)*(y1_1-y2_1)/(x1_1-x2_1))))&&(y<=(y1_2-((x1_2-x)*(y1_2-y2_2)/(x1_2-x2_2)))))){
//                   core->setFocus(i);
//                   core->setFocusObj(false);
//               }
           }
        }
        core->spotFocus();
        this->repaint();
    }
}
