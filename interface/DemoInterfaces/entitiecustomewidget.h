#ifndef ENTITIECUSTOMEWIDGET_H
#define ENTITIECUSTOMEWIDGET_H

#include <QWidget>
#include <QMenuBar>
#include <QLineEdit>
#include <QBoxLayout>
#include <QLabel>
#include <QTimer>
#include <QCheckBox>
#include "lineoffield.h"
#include "Contaner/Core.h"
#include "Contaner/ERDiagram.h"
#include "Contaner/Entitie.h"
#include "Contaner/Relation.h"
#include "Contaner/List.h"
#include "workplacewidget.h"

class EntitieCustomeWidget : public QWidget
{
    Q_OBJECT
private:
    Core* core;
    int curFocus;
    bool curObj;
    QLabel* entitieName;
    QTimer* timer;
    QPushButton* addButton;

public:
    explicit EntitieCustomeWidget(QWidget *parent = 0);
    void setCore(Core* core);
    Core* getCore();
    QBoxLayout* qbl;
    QLineEdit* tb;
    QLineEdit* key;
    QCheckBox* ml;
    QCheckBox* mr;
    QCheckBox* al;
    QCheckBox* ar;
    QComboBox* qcb;
    List<LineOfField*>* fildlist;
    int getCurFocus();
    void setCurFocus(int curFocus);
    void ClearWidget();
    void save();

signals:

public slots:
    void timerEvent();
    void buttonAdd();

};

#endif // ENTITIECUSTOMEWIDGET_H
