#ifndef BUILTINDIALOG_H
#define BUILTINDIALOG_H

#include <QDialog>
#include <QTWidgets>
class BuiltinDialog : public QDialog
{
    Q_OBJECT //巨集(Qt定義)

public:
    explicit BuiltinDialog(QWidget *parent = nullptr);
    ~BuiltinDialog() override;
private:
    QTextEdit* displayTextEdit;
    QPushButton* colorPushBtn;
    QPushButton* errorPushBtn;
    QPushButton* filePushBtn;
    QPushButton* fontPushBtn;
    QPushButton* inputPushBtn;
    QPushButton* pagePushBtn;
    QPushButton* progressPushBtn;
    QPushButton* printPushBtn;
    QPushButton* textPushBtn;

private slots:
        void doPushBtn();
};
#endif // BUILTINDIALOG_H
