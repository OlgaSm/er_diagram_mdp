#-------------------------------------------------
#
# Project created by QtCreator 2014-04-06T15:07:08
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = Contaner
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

HEADERS  += ListItem.h \
    List.h \
    Relation.h \
    Entitie.h \
    Field.h \
    Core.h \
    DataField.h \
    DoubleField.h \
    ERDiagram.h \
    IntField.h \
    StringField.h

SOURCES += main.cpp \
    Relation.cpp \
    Entitie.cpp \
    Field.cpp \
    ERDiagram.cpp \
    IntField.cpp \
    StringField.cpp \
    DoubleField.cpp \
    Core.cpp
