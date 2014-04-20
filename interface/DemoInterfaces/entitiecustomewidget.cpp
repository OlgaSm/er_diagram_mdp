#include "entitiecustomewidget.h"

EntitieCustomeWidget::EntitieCustomeWidget(QWidget *parent) :
    QWidget(parent){
    this->timer = new QTimer(this);
    connect(this->timer, SIGNAL(timeout()), SLOT(timerEvent()));
    this->core = new Core;
    this->qbl = new QBoxLayout(QBoxLayout::TopToBottom);
    this->entitieName = new QLabel("Название сущности:");
    this->tb = new QLineEdit();

    // Label
    this->tb->setMaxLength(50);

    // Layout
    this->setLayout(qbl);


    // Добавление widget'ов
    this->qbl->addWidget(this->entitieName);
    this->qbl->addWidget(this->tb);
    this->qbl->addStretch();
    //this->setStyleSheet("border-radius: 5px; border: 1px solid black;");
}

void EntitieCustomeWidget::setCore(Core *core){
    this->core = core;
}

Core* EntitieCustomeWidget::getCore(){
    return this->core;
}

void EntitieCustomeWidget::timerEvent(){
    if(core->getFocus()!=-1 && this->curFocus != core->getFocus()){
        this->curFocus = core->getFocus();
        Entitie* e = core->getEntitieAt(core->getFocus());
        QLayoutItem* item;
        while(item = this->layout()->itemAt(0)){
            this->layout()->removeItem( item );
            this->layout()->removeWidget(item->widget());
            delete item->widget();
            delete item;
            this->layout()->update();
        }

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
        for(int i=0; i<e->fieldCount(); i++){
            this->qbl->addWidget(new LineOfField(e->fieldAt(i),this));
        }
        this->qbl->addWidget(new QPushButton("Добавить поле"));
        //this->qbl->addWidget(new QPushButton("Сохранить"));
        this->qbl->addStretch();
    }
}
