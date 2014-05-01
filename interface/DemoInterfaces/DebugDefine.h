#ifndef DEBUGDEFINE_H
#define DEBUGDEFINE_H
#include <string>
using namespace std;
//================================================
//#define DEBUGLOG
#ifdef DEBUGLOG
    #include <QFile>
    #include <QTextStream>
    //========================
    #define DEBUGLOG_CLEAR

    #define DEBUGLOG_LIST
    #define DEBUGLOG_LISTITEM
    #define DEBUGLOG_CORE
    #define DEBUGLOG_ENTITIE
    #define DEBUGLOG_ERD

    #define DEBUGLOG_FIELD
    #define DEBUGLOG_INT_FIELD
    #define DEBUGLOG_STRING_FIELD
    #define DEBUGLOG_DOUBLE_FIELD
    #define DEBUGLOG_DATAFIELD

    #define DEBUGLOG_RELATION
    #define DEBUGLOG_ENTITIEWIDGET
    //#define DEBUGLOG_LINEFIELD //- C этим какие-то баги!
    #define DEBUGLOG_MAIN
    #define DEBUGLOG_WORKDESK
    //========================
    const QString LOG_PATH="C://loggggg.txt";
//    #ifndef COUNTOBJ
//    #define COUNTOBJ
//        int CountCreatedObject = 0;
//        int CountDeltedObject = 0;
//    #endif
#endif
//================================================
#endif // DEBUGDEFINE_H
