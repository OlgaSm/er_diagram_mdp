#include "mainwindow.h"
#include <QApplication>
#include "erallocator.h"

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
    MainWindow w;
    w.show();

    return a.exec();
}
