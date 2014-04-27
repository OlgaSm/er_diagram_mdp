#include "lineoffield.h"
#include "Contaner/IntField.h"
#include "Contaner/DoubleField.h"
#include "Contaner/DataField.h"
#include "Contaner/StringField.h"
#include "entitiecustomewidget.h"
#include <qcoreapplication.h>

LineOfField::LineOfField(EntitieCustomeWidget* ec, Entitie* e, Field* field, QWidget *parent) :
    QWidget(parent)
{   this->ec = ec;
    this->field = field;
    this->e = e;
    this->qbl = new QBoxLayout(QBoxLayout::LeftToRight);
    QString value;
    switch(field->getType()){
        case 0:
            value = "Nothing";
            break;
        case 1:
            value = QString::fromStdString(((StringField*)(field))->getValue());
            break;
        case 2:
            value = QString::number(((IntField*)(field))->getValue());
            break;
        case 3:
            value = QString::number(((DoubleField*)(field))->getValue());
            break;
        case 4:
            value = "Object";
            break;
    }
    this->ID = new QLineEdit(QString::fromStdString(field->getID()));
    this->value = new QLineEdit(value);
    this->qbl->addWidget(this->ID);
    this->qbl->addWidget(this->value);
    QString type="";
    this->qcb = new QComboBox();

    int t = ((IntField*)e->fieldByID("T"))->getValue();
    if(t!=1){
        this->qcb->addItem("Свойство"); //this->qcb->addItem("BASE_FIELD");
        this->qcb->addItem("Комментарий"); //this->qcb->addItem("STRING_FIELD");
        this->qcb->addItem("Скорость"); // this->qcb->addItem("INT_FIELD");
        this->qcb->addItem("Дистанция"); //this->qcb->addItem("DOUBLE_FIELD");
        //this->qcb->addItem("Шаблонное поле"); //this->qcb->addItem("TEMPLATE_FILD");
    }else{
        this->qcb->addItem("Свойство");
        this->qcb->addItem("Комментарий");
        this->qcb->addItem("Скорость++");
        this->qcb->addItem("Дистанция++");
        //this->qcb->addItem("Шаблонное поле");
    }

    switch(field->getType()){
        case 0:
            type="BASE_FIELD";
            qcb->setCurrentIndex(0);
            break;
        case 1:
            type="STRING_FIELD";
            qcb->setCurrentIndex(1);
            break;
        case 2:
            type="INT_FIELD";
            qcb->setCurrentIndex(2);
            break;
        case 3:
            type="DOUBLE_FIELD";
            qcb->setCurrentIndex(3);
            break;
        case 4:
            type="TEMPLATE_FILD";
            qcb->setCurrentIndex(4);
            break;
    }
    //this->qbl->addWidget(new QLabel(type));
    this->qbl->addWidget(this->qcb);
    QPixmap delIcon(":Images/DelButton.png");
    this->qpb = new QPushButton();
    this->qpb->setIcon(delIcon);
    this->qpb->saveGeometry();
    //this->qpb->setIconSize(delIcon.size());
    this->qbl->addWidget(this->qpb);
    //this->qbl->addStretch();
    this->setLayout(this->qbl);
    QObject::connect(this->qpb,SIGNAL(clicked()),this,SLOT(buttonDelete()));
}

void LineOfField::buttonDelete(){
    this->ec->ClearWidget();
    this->e->popFieldByID(field->getID());
    this->ec->doOnTimer();
    //this->ec->setCurFocus(-1);
}

Field* LineOfField::getField(){
    return this->field;
}
