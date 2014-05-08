#include "mainwindow.h"
#include <QApplication>

//=====================================
#include "DebugDefine.h"
//=====================================

int main(int argc, char *argv[]){
    #ifdef DEBUGLOG_CLEAR
        QFile file(LOG_PATH);
        file.open(QIODevice::WriteOnly);
        QTextStream out(&file);
        out << "== Start debug ==\n" << endl;
        file.close();
    #endif

    QApplication a(argc, argv);
    string path = "";
    bool content = false;
    if(argv[1]!=NULL){
        path = argv[1];
        content = true;
    }
    MainWindow w(content, path);
    w.show();

    return a.exec();
}
