#-------------------------------------------------
#
# Project created by QtCreator 2014-03-29T17:57:37
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DemoInterfaces
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    workplacewidget.cpp \
    Contaner/Core.cpp \
    Contaner/DoubleField.cpp \
    Contaner/Entitie.cpp \
    Contaner/ERDiagram.cpp \
    Contaner/Field.cpp \
    Contaner/IntField.cpp \
    Contaner/Relation.cpp \
    Contaner/StringField.cpp \
    entitiecustomewidget.cpp \
    lineoffield.cpp \
    helpbrowser.cpp \
    Factory/entitiefactory.cpp \
    Factory/slowcar.cpp \
    Factory/mediumcar.cpp \
    Factory/fastcar.cpp \
    Factory/slowcarfactory.cpp \
    Factory/CarFactory.cpp \
    Factory/mediumcarfactory.cpp \
    Factory/fastcarfactory.cpp \
    Factory/fastvelo.cpp \
    Factory/mediumvelo.cpp \
    Factory/slowvelo.cpp \
    Factory/fastvelofactory.cpp \
    Factory/mediumvelofactory.cpp \
    Factory/slowvelofactory.cpp \
    Factory/VeloFactory.cpp

HEADERS  += mainwindow.h \
    workplacewidget.h \
    Contaner/Core.h \
    Contaner/DataField.h \
    Contaner/DoubleField.h \
    Contaner/Entitie.h \
    Contaner/ERDiagram.h \
    Contaner/Field.h \
    Contaner/IntField.h \
    Contaner/List.h \
    Contaner/ListItem.h \
    Contaner/Relation.h \
    Contaner/StringField.h \
    entitiecustomewidget.h \
    lineoffield.h \
    DebugDefine.h \
    helpbrowser.h \
    Factory/entitiefactory.h \
    Factory/slowcar.h \
    Factory/mediumcar.h \
    Factory/fastcar.h \
    Factory/slowcarfactory.h \
    Factory/CarFactory.h \
    Factory/mediumcarfactory.h \
    Factory/fastcarfactory.h \
    Factory/fastvelo.h \
    Factory/mediumvelo.h \
    Factory/slowvelo.h \
    Factory/fastvelofactory.h \
    Factory/mediumvelofactory.h \
    Factory/slowvelofactory.h \
    Factory/VeloFactory.h

OTHER_FILES += \
    Contaner/ReadMe.txt \
    Images/DelButton.png \
    Images/Entitie.png \
    Images/Exit.png \
    Images/Relation.png \
    Images/Selection.png \
    Images/Use.png \
    Images/Work.png

RESOURCES += \
    ERDRes.qrc
