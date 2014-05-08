#include "workplacewidget.h"
#include <QPainter>
#include "Contaner/Entitie.h"
#include "Contaner/Relation.h"
#include "Contaner/IntField.h"
#include <string>
#include <sstream>
#include <math.h>
#include <Factory/entitiefactory.h>
#define max_width 5000
#define max_height 2500
#define work_count 6

//=====================================
#include "DebugDefine.h"
//=====================================

WorkPlaceWidget::WorkPlaceWidget(QWidget *parent, Core* core) :
    QFrame(parent){
    this->core = core;
    QRect r2(0,0,this->size().width()-1,this->size().height()-1);
    this->setMinimumHeight(max_height);
    this->setMinimumWidth(max_width);
    this->scroll(this->size().width()-1,this->size().height()-1,r2);
    this->curX = 10;
    this->curY = 10;
    this->selected = false;
    this->currentMoved = -1;
    this->setMouseTracking(true);
    #ifdef DEBUGLOG_WORKDESK
        QFile file(LOG_PATH);
        file.open(QIODevice::Append | QIODevice::Text);
        QTextStream out(&file);
        out << "+ WORKDESK created" << endl;
        file.close();
        //CountCreatedObject++;
    #endif
}

WorkPlaceWidget::~WorkPlaceWidget(){
    #ifdef DEBUGLOG_WORKDESK
        QFile file(LOG_PATH);
        file.open(QIODevice::Append | QIODevice::Text);
        QTextStream out(&file);
        out << "- WORKDESK deleted" << endl;
        file.close();
        //CountDeltedObject++;
    #endif
}

void WorkPlaceWidget::paintEvent(QPaintEvent *){
        QPainter painter(this);
        QRect r2(0,0,this->size().width()-1,this->size().height()-1);
        QPixmap pm(":Images/Map.png");
        painter.drawPixmap(0,0,this->size().width()-1,this->size().height()-1,pm);
        painter.drawRect(r2);
        if(this->curX<10){
            this->curX=10;
        }
        if(this->curY<10){
            this->curY=10;
        }
        if(this->curX>max_width-10){
            this->curX=max_width-10;
        }
        if(this->curY>max_height-10){
            this->curY=max_height-10;
        }
        this->paintDesk();
}

void WorkPlaceWidget::paintDesk(){
    this->core->spotFocus();
    for(int i=0; i<this->core->getEntitieCount(); i++){
       this->drawEntitie(this->core->getEntitieAt(i),(i==this->core->getFocus() && this->core->getFocusObj()),false);
    }
    for(int i=0; i<this->core->getRelationCount(); i++){
        drawRelation(this->core->getRelationAt(i),((i==this->core->getFocus())&&(!this->core->getFocusObj())));
    }
    if(this->core->getState()==0){
        switch(this->core->getEntitieType()){
            case 0:
                this->drawEntitie(this->core->Empty,false,true);
                break;
            case 1:
                this->drawEntitie(this->core->SlowCar,false,true);
                break;
            case 2:
                this->drawEntitie(this->core->MediumCar,false,true);
                break;
            case 3:
                this->drawEntitie(this->core->FastCar,false,true);
                break;
            case 4:
                this->drawEntitie(this->core->SlowVelo,false,true);
                break;
            case 5:
                this->drawEntitie(this->core->MediumVelo,false,true);
                break;
            case 6:
                this->drawEntitie(this->core->FastVelo,false,true);
                break;
            case 7:
                this->drawEntitie(this->core->SchoolBoy,false,true);
                break;
            case 8:
                this->drawEntitie(this->core->Student,false,true);
                break;
            case 9:
                this->drawEntitie(this->core->Teacher,false,true);
                break;
            case 10:
                this->drawEntitie(this->core->Courier,false,true);
                break;
            default:
            this->drawEntitie(this->core->Empty,false,true);
        }
    }
}



void WorkPlaceWidget::drawEntitie(Entitie* e, bool focus, bool isAbstract){
    this->calculateEntitie(e);
    int x = ((IntField*)e->fieldByID("X"))->getValue();
    int y = ((IntField*)e->fieldByID("Y"))->getValue();
    int w = ((IntField*)e->fieldByID("W"))->getValue();
    int h = ((IntField*)e->fieldByID("H"))->getValue();
    int t = ((IntField*)e->fieldByID("T"))->getValue();

    bool mov = true;
    for(int i=0; i<this->core->getEntitieCount(); i++){
       Entitie* e0 = this->core->getEntitieAt(i);
       int xe = ((IntField*)e0->fieldByID("X"))->getValue();
       int ye = ((IntField*)e0->fieldByID("Y"))->getValue();
       int we = ((IntField*)e0->fieldByID("W"))->getValue();
       int he = ((IntField*)e0->fieldByID("H"))->getValue();
       if((xe-w-15<x)&&(ye-h-15<y)&&(we+xe+15>x)&&(he+ye+15>y)&&(e0!=e)){
           mov = false;
       }
    }
    int alpha =  (((isAbstract)||(!mov)) ? 20 : 250);
    int alpha0 = (((isAbstract)||(!mov)) ? 0 : 25);
    int alpha1 = (((isAbstract)||(!mov)) ? 0 : 100);
    if(isAbstract){
        ((IntField*)e->fieldByID("X"))->setValue(this->curX);
        ((IntField*)e->fieldByID("Y"))->setValue(this->curY);
    }
    QPainter painter(this);
    QColor color(255,200,125,alpha);
    QColor color1(255,170,100,alpha);
    QColor color2(215,215,255,alpha);
    QColor colorRed(252,139,130,alpha);
    QColor colorGreen(125,220,125,alpha);
    QColor colorGreenAlpha(55,155,55,alpha0);
    QColor colorBlackAlpha(0,0,0,alpha1);
    QPen pen1 = QPen(Qt::black, 1, Qt::SolidLine);
    QPen pen2 = QPen(colorBlackAlpha, 1, Qt::SolidLine);
    painter.setPen(pen1);

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
    Entitie* eR = r->getEntR();
    Entitie* eL = r->getEntL();
    this->calculateEntitie(eL);
    this->calculateEntitie(eR);
    int x1 = ((IntField*)eR->fieldByID("X"))->getValue();
    int y1 = ((IntField*)eR->fieldByID("Y"))->getValue();
    int w1 = ((IntField*)eR->fieldByID("W"))->getValue();
    int h1 = ((IntField*)eR->fieldByID("H"))->getValue();
    int t1 = ((IntField*)eR->fieldByID("T"))->getValue();
    int x2 = ((IntField*)eL->fieldByID("X"))->getValue();
    int y2 = ((IntField*)eL->fieldByID("Y"))->getValue();
    int w2 = ((IntField*)eL->fieldByID("W"))->getValue();
    int h2 = ((IntField*)eL->fieldByID("H"))->getValue();
    int t2 = ((IntField*)eL->fieldByID("T"))->getValue();

    int alpha = 250;
    int alpha0 = 25;
    int alpha1 = 100;
    int alpha2 = 250;
    if((x1-w2-15<x2)&&(y1-h2-15<y2)&&(w1+x1+15>x2)&&(h1+y1+15>y2)){
        alpha = 0;
        alpha0 = 0;
        alpha1 = 0;
        alpha2 = 0;
    }

    QPainter painter(this);
    QColor color(90,185,255,alpha);
    QColor colorGreenAlpha(55,155,55,alpha0);
    QColor colorBlackAlpha(0,0,0,alpha1);
    QColor colorBlack(0,0,0,alpha2);
    QPen penf = QPen(colorBlackAlpha, 1, Qt::SolidLine);

    painter.setBrush(QBrush(color));

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
    QPen pen1 = QPen(colorBlack, 1, Qt::DotLine);
    QPen pen2 = QPen(colorBlack, 1, Qt::SolidLine);
    QPen pen3 = QPen(colorBlack, 2, Qt::SolidLine);
    QPen pen4 = QPen(colorBlack, 2, Qt::DotLine);
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
    if(focus){
        if(t1!=1){
            double distance = this->core->getDistanceOf(eR);
            painter.setBrush(QBrush(colorGreenAlpha));
            painter.setPen(penf);
            painter.drawEllipse(QPoint(x1-1,y1-1), (int)qRound(distance), (int)qRound(distance));
         }
        if(t2!=1){
            double distance = this->core->getDistanceOf(eL);
            painter.setBrush(QBrush(colorGreenAlpha));
            painter.setPen(penf);
            painter.drawEllipse(QPoint(x2-1,y2-1), (int)qRound(distance), (int)qRound(distance));
         }
    }
}

void WorkPlaceWidget::calculateEntitie(Entitie* e){
    int height = e->fieldCount() - (work_count-1);
    if(height<1) height = 1;
    ((IntField*)e->fieldByID("H"))->setValue(height*24);
}

void WorkPlaceWidget::mousePressEvent(QMouseEvent* pe){
    if(this->core->getState()==0){ // Добавление сущности
        //=====================================================
        string name;
        int num = this->core->getCounter();
        char str[255];
        sprintf(str, "Entitie № %d", num);
        name = (const char*)str;
        Entitie* e0 = EntitieFactory::entitieFactory()->createEntitie(this->core->getEntitieType());
        ((IntField*)e0->fieldByID("X"))->setValue(pe->x());
        ((IntField*)e0->fieldByID("Y"))->setValue(pe->y());
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
        }else{
            delete(e0);
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
                int num = this->core->getCounter0();
                char str[255];
                sprintf(str, "Relation %d", num);
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
        this->selected = true;
        core->setFocus(-1);
        for(int i=0; i<this->core->getEntitieCount(); i++){
           Entitie* e = this->core->getEntitieAt(i);
           int x =((IntField*)e->fieldByID("X"))->getValue();
           int y = ((IntField*)e->fieldByID("Y"))->getValue();
           int w = ((IntField*)e->fieldByID("W"))->getValue();
           int h = ((IntField*)e->fieldByID("H"))->getValue();
           if((x<pe->x())&&(y<pe->y())&&(w+x>pe->x())&&(h+y>pe->y())){
               if(this->currentMoved==-1){this->currentMoved=i;}
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

void WorkPlaceWidget::mouseMoveEvent(QMouseEvent* pe){
    int deltaX = this->curX - (pe->x());
    int deltaY = this->curY - (pe->y());
    if(this->currentMoved!=-1 && this->selected){
        Entitie* e = this->core->getEntitieAt(this->currentMoved);
        ((IntField*)e->fieldByID("X"))->setValue(((IntField*)e->fieldByID("X"))->getValue()-deltaX);
        ((IntField*)e->fieldByID("Y"))->setValue(((IntField*)e->fieldByID("Y"))->getValue()-deltaY);
    }
    this->curX=pe->x();
    this->curY=pe->y();
    this->repaint();
}

void WorkPlaceWidget::mouseReleaseEvent(QMouseEvent *pe){
    this->selected = false;
    this->currentMoved=-1;
    pe->ignore();
}
