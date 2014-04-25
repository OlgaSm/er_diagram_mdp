#include "entitiecustomewidget.h"
#include "Contaner/IntField.h"
#include "Contaner/DoubleField.h"
#include "Contaner/DataField.h"
#include "Contaner/StringField.h"
#include <QScrollArea>

EntitieCustomeWidget::EntitieCustomeWidget(QWidget *parent) :
    QWidget(parent){
    this->timer = new QTimer(this);
    connect(this->timer, SIGNAL(timeout()), SLOT(timerEvent()));
    this->timer->start(100);
    this->core = new Core;
    this->fildlist = new List<LineOfField*>();
    this->curFocus = -1;
    this->curObj = true;
    this->qbl = new QBoxLayout(QBoxLayout::TopToBottom);

    // Layout
    this->setLayout(qbl);

}

void EntitieCustomeWidget::setCore(Core *core){
    this->core = core;
}

Core* EntitieCustomeWidget::getCore(){
    return this->core;
}

void EntitieCustomeWidget::ClearWidget(){
    while(this->layout()->count()>0){
        QLayoutItem* item = this->layout()->itemAt(0);
        this->layout()->removeItem( item );
        this->layout()->removeWidget(item->widget());
        delete item->widget();
        delete item;
        this->layout()->update();
    }
    for(int i=0; i<this->fildlist->size(); i++){
        this->fildlist->popAt(i);
    }
    this->fildlist = new List<LineOfField*>();
}

void EntitieCustomeWidget::timerEvent(){
    if(core->getFocus()!=-1){
        if(this->curFocus != core->getFocus() || (core->getFocusObj()!=this->curObj)){
            this->curFocus = core->getFocus();
            this->curObj = core->getFocusObj();
            if(core->getFocusObj()){
                if(core->getFocus()<core->getEntitieCount()){
                    Entitie* e = core->getEntitieAt(core->getFocus());
                    this->ClearWidget();

                    this->entitieName = new QLabel("Название сущности:");
                    this->tb = new QLineEdit();

                    // Label
                    this->tb->setMaxLength(50);
                    this->tb->setText(QString::fromStdString(e->getID()));

                    // Layout
                    this->setLayout(qbl);

                    // Добавление widget'ов
                    this->qbl->addWidget(this->entitieName);
                    this->qbl->addWidget(this->tb);
                    QScrollArea* scrollArea = new QScrollArea();
                    //scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
                    QWidget* qw = new QWidget();
                    qw->setLayout(new QBoxLayout(QBoxLayout::TopToBottom));
                    for(int i=5; i<e->fieldCount(); i++){
                        LineOfField* lf = new LineOfField(this, e, e->fieldAt(i),this);
                        this->fildlist->push_back(lf);
                        qw->layout()->addWidget(lf);
                        //this->qbl->addWidget(lf);
                    }
                    qw->setMaximumWidth(350);
                    scrollArea->setWidget(qw);
                    scrollArea->viewport()->isMaximized();
                    this->qbl->addWidget(scrollArea);
                    this->addButton = new QPushButton("Добавить поле");
                    this->qbl->addWidget(this->addButton);
                    //this->qbl->addStretch();
                    QObject::connect(this->addButton,SIGNAL(clicked()),this,SLOT(buttonAdd()));
                }
            }else{
                if(core->getFocus()<core->getRelationCount()){
                    Relation* r = core->getRelationAt(core->getFocus());
                    this->ClearWidget();

                    this->entitieName = new QLabel("Название связи:");
                    this->tb = new QLineEdit();
                    // Label
                    this->tb->setMaxLength(50);
                    this->tb->setText(QString::fromStdString(r->getID()));

                    this->qbl->addWidget(this->entitieName);
                    this->qbl->addWidget(this->tb);
                    this->qbl->addWidget(new QLabel("Ключевое поле"));
                    this->key = new QLineEdit("Ключ");
                    this->key->setText(QString::fromStdString(r->getKey()));
                    this->qbl->addWidget(this->key);
                    //==========================================
                    this->ml = new QCheckBox("Множественная связь слева");
                    this->ml->setChecked(r->getMulL());
                    this->qbl->addWidget(ml);
                    //==========================================
                    this->mr = new QCheckBox("Множественная связь справа");
                    this->mr->setChecked(r->getMulR());
                    this->qbl->addWidget(mr);
                    //==========================================
                    this->al = new QCheckBox("Абстрактная связь слева");
                    this->al->setChecked(r->getAbsL());
                    this->qbl->addWidget(al);
                    //==========================================
                    this->ar = new QCheckBox("Абстрактная связь справа");
                    this->ar->setChecked(r->getAbsR());
                    this->qbl->addWidget(ar);
                    //==========================================
                    this->qbl->addStretch();
                    this->setLayout(qbl);
                }
            }
        }
    }else{
        this->curFocus = -1;
        this->curObj = true;
        while(this->layout()->count()>0){
            QLayoutItem* item = this->layout()->itemAt(0);
            this->layout()->removeItem( item );
            this->layout()->removeWidget(item->widget());
            delete item->widget();
            delete item;
            this->layout()->update();
        }
    }
}

//QObject::connect(this->addButton,SIGNAL(clicked()),this,SLOT(buttonAdd()));
void EntitieCustomeWidget::buttonAdd(){
    if(this->core->getFocus()!=-1 && this->core->getFocusObj()){
        this->save();
        Entitie* e = this->core->getEntitieAt(this->core->getFocus());
        e->addStdField("DefaultField");
        this->curFocus = -1;
    }
}

void EntitieCustomeWidget::save(){
    if(this->core->getFocus()!=-1){
            //this->core->popEntitieAt(this->core->getFocus());
            Entitie* e = this->core->getEntitieAt(core->getFocus());
            e->setID(this->tb->text().toStdString());
            for(int i=0; i<this->fildlist->size(); i++){
                //if(i>4){
                LineOfField* lf = this->fildlist->at(i);
                Field* field = lf->getField();
                if(lf->qcb->currentIndex()>=0 && lf->qcb->currentIndex()<4){
                    //if(false){
                    if((int)field->getType()!=lf->qcb->currentIndex()){
                        this->core->getEntitieAt(this->core->getFocus())->popFieldAt(i+5);
                        this->fildlist->popAt(i+5);
                        switch(lf->qcb->currentIndex()){
                            case 0:
                                field = new Field(lf->ID->text().toStdString());
                                break;
                            case 1:
                                field = new StringField(lf->ID->text().toStdString(),lf->value->text().toStdString());
                                break;
                            case 2:
                                field = new IntField(lf->ID->text().toStdString(), lf->value->text().toInt(0));
                                break;
                            case 3:
                                field = new DoubleField(lf->ID->text().toStdString(), lf->value->text().toFloat());
                                break;
                        }
                        this->core->getEntitieAt(this->core->getFocus())->addUserField(field);
                        this->fildlist->push_back(new LineOfField(this,this->core->getEntitieAt(this->core->getFocus()),field, this));
                        this->setCurFocus(-1);
                    }
                }
                field->setID(lf->ID->text().toStdString());
                switch((int)field->getType()){
                    case 1:
                        ((StringField*)(field))->setValue(lf->value->text().toStdString());
                        break;
                    case 2:
                        ((IntField*)(field))->setValue(lf->value->text().toInt());
                        break;
                    case 3:
                        ((DoubleField*)(field))->setValue(lf->value->text().toDouble());
                        break;
                }
                //}
            }
    }
}

int EntitieCustomeWidget::getCurFocus(){
    return this->curFocus;
}

void EntitieCustomeWidget::setCurFocus(int curFocus){
    this->curFocus = curFocus;
}
