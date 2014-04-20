#include "lineoffield.h"
#include "Contaner/IntField.h"
#include "Contaner/DoubleField.h"
#include "Contaner/DataField.h"
#include "Contaner/StringField.h"

LineOfField::LineOfField(Field* field, QWidget *parent) :
    QWidget(parent)
{
    this->field = field;

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

    this->qbl->addWidget(new QLineEdit(QString::fromStdString(field->getID())));
    this->qbl->addWidget(new QLineEdit(value));
    QString type="";
    this->qcb = new QComboBox();
    this->qcb->addItem("BASE_FIELD");
    this->qcb->addItem("STRING_FIELD");
    this->qcb->addItem("INT_FIELD");
    this->qcb->addItem("DOUBLE_FIELD");
    this->qcb->addItem("TEMPLATE_FILD");

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
    this->qbl->addWidget(new QPushButton("Удалить"));
    //this->qbl->addStretch();
    this->setLayout(this->qbl);
}
