#ifndef LINEOFFIELD_H
#define LINEOFFIELD_H

#include <QWidget>
#include "Contaner/Field.h"
#include <QBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QComboBox>
#include <QAction>

class LineOfField : public QWidget
{
    Q_OBJECT
private:
    Field* field;
    QBoxLayout* qbl;
    QComboBox* qcb;
public:
    explicit LineOfField(Field* field = NULL,QWidget *parent = 0);
    QLineEdit* ID;
    QLineEdit* value;
    Field* getField();
signals:

public slots:

};

#endif // LINEOFFIELD_H
