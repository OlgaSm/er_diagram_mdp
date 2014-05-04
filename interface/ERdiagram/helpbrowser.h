#ifndef HELPBROWSER_H
#define HELPBROWSER_H

#include <QWidget>
#include <QPushButton>
#include <QTextBrowser>
#include <QVBoxLayout>
#include <QDialog>

class HelpBrowser : public QDialog{
    Q_OBJECT
public:
    explicit HelpBrowser(const QString& strPath,
                         const QString& strFileName,
                               QWidget *parent = 0);

signals:

public slots:

};

#endif // HELPBROWSER_H
