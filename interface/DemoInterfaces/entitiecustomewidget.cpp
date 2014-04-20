#include "entitiecustomewidget.h"

EntitieCustomeWidget::EntitieCustomeWidget(QWidget *parent) :
    QWidget(parent){
    this->timer = new QTimer(this);
    connect(this->timer, SIGNAL(timeout()), SLOT(timerEvent()));
    this->timer->start(100);
    this->core = new Core;
    this->curFocus = -1;
    this->curObj = true;
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
    if(core->getFocus()!=-1){
        if(this->curFocus != core->getFocus() || (core->getFocusObj()!=this->curObj)){
            this->curFocus = core->getFocus();
            this->curObj = core->getFocusObj();
            if(core->getFocusObj()){
                Entitie* e = core->getEntitieAt(core->getFocus());
                while(this->layout()->count()>0){
                    QLayoutItem* item = this->layout()->itemAt(0);
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
            }else{
                Relation* r = core->getRelationAt(core->getFocus());
                while(this->layout()->count()>0){
                    QLayoutItem* item = this->layout()->itemAt(0);
                    this->layout()->removeItem( item );
                    this->layout()->removeWidget(item->widget());
                    delete item->widget();
                    delete item;
                    this->layout()->update();
                }

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
