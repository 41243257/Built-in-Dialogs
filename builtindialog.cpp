#include "builtindialog.h"
#include <QDebug>
#include <QColorDialog>

BuiltinDialog::BuiltinDialog(QWidget *parent)//建構函數
    : QDialog(parent)
{
    QGridLayout* gridLayout = new QGridLayout;
    displayTextEdit =new QTextEdit("QT內建對話盒示範");
    colorPushBtn = new QPushButton("顏色對話盒");
    errorPushBtn = new QPushButton("錯誤訊息對話盒");
    filePushBtn = new QPushButton("檔案對話盒");
    fontPushBtn =new QPushButton ("字體對話盒");
    inputPushBtn = new QPushButton ("輸入對話盒");
    pagePushBtn = new QPushButton ("分頁設定對話盒");
    progressPushBtn = new QPushButton ("進度對話盒");
    printPushBtn =new QPushButton ("列印對話盒");
    textPushBtn =new QPushButton("設定文字顏色盒");

    gridLayout->addWidget(colorPushBtn,0,0,1,1);
    gridLayout->addWidget(errorPushBtn,0,1,1,1);
    gridLayout->addWidget(filePushBtn,0,2,1,1);
    gridLayout->addWidget(fontPushBtn,1,0,1,1);
    gridLayout->addWidget(inputPushBtn,1,1,1,1);
    gridLayout->addWidget(pagePushBtn,1,2,1,1);
    gridLayout->addWidget(progressPushBtn,2,0,1,1);
    gridLayout->addWidget(printPushBtn,2,1,1,1);
    gridLayout->addWidget(displayTextEdit,3,0,3,3);
    gridLayout->addWidget(textPushBtn,2,2,1,1);

    setLayout(gridLayout);
    setWindowTitle("我的對話盒");
    resize(400,300);
    connect(colorPushBtn,SIGNAL(clicked()),this,SLOT(doPushBtn()));
    connect(errorPushBtn,SIGNAL(clicked()),this,SLOT(doPushBtn()));
    connect(filePushBtn,SIGNAL(clicked()),this,SLOT(doPushBtn()));
    connect(fontPushBtn,SIGNAL(clicked()),this,SLOT(doPushBtn()));
    connect(inputPushBtn,SIGNAL(clicked()),this,SLOT(doPushBtn()));
    connect(pagePushBtn,SIGNAL(clicked()),this,SLOT(doPushBtn()));
    connect(progressPushBtn,SIGNAL(clicked()),this,SLOT(doPushBtn()));
    connect(textPushBtn,SIGNAL(clicked()),this,SLOT(doPushBtn()));


}
void BuiltinDialog:: doPushBtn()
{
    QPushButton* btn= qobject_cast<QPushButton*>(sender());
    if(btn== colorPushBtn)
    {
        QPalette palette=displayTextEdit->palette();
        const QColor& color=
            QColorDialog::getColor(palette.color(QPalette::Base),
                                                     this,"設定背景顏色");

        if(color.isValid())
         {
          palette.setColor(QPalette::Base,color);
          displayTextEdit->setPalette(palette);
         }
    }
    if(btn==errorPushBtn){
        QErrorMessage box(this);
        box.setWindowTitle(QStringLiteral("錯誤訊息盒"));
        box.showMessage(QStringLiteral("訊息盒錯誤實例xx"));
        box.showMessage(QStringLiteral("錯誤實例y"));
        box.showMessage(QStringLiteral("錯誤zz"));
        box.exec();
    }
    if (btn == textPushBtn)
    {
        QPalette palette = displayTextEdit->palette();
        const QColor color =
            QColorDialog::getColor(palette.color(QPalette::Text),
                                   this, "設定文字顏色");
        if (color.isValid())
        {
            palette.setColor(QPalette::Text, color);
            displayTextEdit->setPalette(palette);
        }
    }
    if(btn==filePushBtn)
    {
        QString fileName = QFileDialog::getOpenFileName(this,
                                                        QStringLiteral("打開檔案"), ".",
                                                        QStringLiteral("任何檔案(*.*)"
                                                                       ";;文字檔(*.txt)"
                                                                       ";;XML檔(*.xml)"));
        displayTextEdit->setText(fileName);
    }
    if(btn==progressPushBtn){
        QProgressDialog progress ("正在複製檔案","取消",0,100000,this);//進度條流程
        progress.setWindowTitle("進度對話盒展示");
        progress.show();
        for(int i=0;i<100000;i++){
            progress.setValue(i);
            qApp->processEvents();//qApp全域變數
            if(progress.wasCanceled())
            {
                break;
            }
            qDebug() << i;
        }
        progress.setValue(100000);
    }
       // qDebug()<<"點擊按鈕";
    //else
    //    qDebug()<<"其他按鈕";
}

BuiltinDialog::~BuiltinDialog() = default;//解構函數
