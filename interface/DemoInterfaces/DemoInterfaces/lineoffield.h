#ifndef LINEOFFIELD_H
#define LINEOFFIELD_H

#include <QWidget>
#include "Contaner/Field.h"
#include "Contaner/Entitie.h"
#include <QBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QComboBox>
#include <QAction>

class EntitieCustomeWidget;

class LineOfField : public QWidget
{
    Q_OBJECT
private:
    Field* field;
    QBoxLayout* qbl;
    QPushButton* qpb;
    Entitie* e;
    EntitieCustomeWidget* ec;

public:
    explicit LineOfField(EntitieCustomeWidget* ec, Entitie* e, Field* field = NULL,QWidget *parent = 0);
    QComboBox* qcb;
    QLineEdit* ID;
    QLineEdit* value;
    Field* getField();
signals:

public slots:
    void buttonDelete();

};

#endif // LINEOFFIELD_H
