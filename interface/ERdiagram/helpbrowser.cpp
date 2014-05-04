#include "helpbrowser.h"
#include <QUrl>

HelpBrowser::HelpBrowser(const QString& strPath, const QString& strFileName,QWidget *parent)
    :QDialog(parent){
    //QPushButton* pbBack = new QPushButton("<<",this);
    //QPushButton* pbHome = new QPushButton("На главную",this);
    //QPushButton* pbForward = new QPushButton(">>",this);
    QTextBrowser* textBrowser = new QTextBrowser(this);

    this->resize(500,500);
    //connect(pbBack, SIGNAL(clicked()),textBrowser,SLOT(backward()));
    //connect(pbHome, SIGNAL(clicked()),textBrowser,SLOT(home()));
    //connect(pbForward, SIGNAL(clicked()),textBrowser,SLOT(forward()));
    //connect(textBrowser, SIGNAL(backwardAvailable(bool)),pbBack,SLOT(setEnabled(bool)));
    //connect(textBrowser, SIGNAL(forwardAvailable(bool)),pbBack,SLOT(setEnabled(bool)));

    textBrowser->setSearchPaths(QStringList() << strPath);
    textBrowser->setSource(QUrl(strFileName));

    // Layout
    QVBoxLayout* vLayout = new QVBoxLayout(this);
    QWidget* qw = new QWidget(this);
    QHBoxLayout* hLayout = new QHBoxLayout(qw);
    qw->setLayout(hLayout);
//    hLayout->addWidget(pbBack);
//    hLayout->addWidget(pbHome);
//    hLayout->addWidget(pbForward);
    vLayout->addWidget(qw);
    vLayout->addWidget(textBrowser);
    this->setLayout(vLayout);
}
