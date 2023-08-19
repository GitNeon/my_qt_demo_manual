#ifndef QWDLGMANUAL_H
#define QWDLGMANUAL_H

#include <QDialog>
#include <QCheckBox>
#include <QRadioButton>
#include <QPlainTextEdit>
#include <QPushButton>

class QWDlgManual : public QDialog
{
    Q_OBJECT

public:
    QWDlgManual(QWidget *parent = nullptr);
    ~QWDlgManual();

private:
    QCheckBox *chkBoxUnder;
    QCheckBox *chkBoxItalic;
    QCheckBox *chkBoxBold;

    QRadioButton *btnBlack;
    QRadioButton *btnRed;
    QRadioButton *btnBlue;

    QPlainTextEdit *txtEdit;

    QPushButton *btnOk;
    QPushButton *btnCancel;
    QPushButton *btnClose;

    void initUI();
    void initSignalSlots();

private slots:
    // 事件监听
    void on_chkBoxUnder(bool checked);
    void on_chkBoxItalic(bool checked);
    void on_chkBoxBold(bool checked);
    // 设置字体颜色
    void setTextFontColor();
};

#endif // QWDLGMANUAL_H
