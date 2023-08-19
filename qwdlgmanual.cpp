#include "qwdlgmanual.h"
#include <QHBoxLayout>
#include <QVBoxLayout>

// 初始化UI
void QWDlgManual::initUI()
{
    // 创建3个chekcbox并进行水平布局
    chkBoxUnder = new QCheckBox(tr("下划线"));
    chkBoxItalic = new QCheckBox(tr("斜体"));
    chkBoxBold = new QCheckBox(tr("粗体"));
    QHBoxLayout *hl = new QHBoxLayout();
    hl->addWidget(chkBoxUnder);
    hl->addWidget(chkBoxItalic);
    hl->addWidget(chkBoxBold);

    // 创建3个颜色单选按钮，并水平布局
    btnBlack = new QRadioButton(tr("黑色"));
    btnBlue = new QRadioButton(tr("蓝色"));
    btnRed = new QRadioButton(tr("红色"));
    QHBoxLayout *hl2 = new QHBoxLayout();
    hl2->addWidget(btnBlack);
    hl2->addWidget(btnBlue);
    hl2->addWidget(btnRed);

    // 创建3个事件button,并水平布局
    btnOk = new QPushButton(tr("确定"));
    btnCancel = new QPushButton(tr("取消"));
    btnClose = new QPushButton(tr("退出"));
    QHBoxLayout *hl3 = new QHBoxLayout();
    hl3->addStretch();
    hl3->addWidget(btnOk);
    hl3->addWidget(btnCancel);
    hl3->addStretch();
    hl3->addWidget(btnClose);

    // 创建文本框
    txtEdit = new QPlainTextEdit();
    txtEdit->setPlainText("Hello Qt \n\n It is my demo");
    QFont font = txtEdit->font(); //获取字体
    font.setPointSize(20);
    txtEdit->setFont(font);

    // 创建垂直布局，并设置为主布局
    QVBoxLayout *vl = new QVBoxLayout;
    vl->addLayout(hl); // 添加字体布局组
    vl->addLayout(hl2); // 添加颜色按钮组
    vl->addWidget(txtEdit); // 添加文本框
    vl->addLayout(hl3); // 添加按钮组
    setLayout(vl);
}

// 信号与槽的关联
void QWDlgManual::initSignalSlots()
{
    // 字体颜色 信号与槽关联
    connect(btnBlack, SIGNAL(clicked()), this, SLOT(setTextFontColor()));
    connect(btnBlue, SIGNAL(clicked()), this, SLOT(setTextFontColor()));
    connect(btnRed, SIGNAL(clicked()), this, SLOT(setTextFontColor()));

    // 字体风格 信号与槽关联
    connect(chkBoxUnder, SIGNAL(clicked(bool)), this, SLOT(on_chkBoxUnder(bool)));
    connect(chkBoxItalic, SIGNAL(clicked(bool)), this, SLOT(on_chkBoxItalic(bool)));
    connect(chkBoxBold, SIGNAL(clicked(bool)), this, SLOT(on_chkBoxBold(bool)));

    // 三个按钮 信号与槽关联
    connect(btnOk, SIGNAL(clicked()), this, SLOT(accept()));
    connect(btnCancel, SIGNAL(clicked()), this, SLOT(reject()));
    connect(btnClose, SIGNAL(clicked()), this, SLOT(close()));
}


// 下划线按钮事件
void QWDlgManual::on_chkBoxUnder(bool checked)
{
    QFont font = txtEdit->font();
    font.setUnderline(checked);
    txtEdit->setFont(font);
}

// 设置斜体
void QWDlgManual::on_chkBoxItalic(bool checked)
{
    QFont font = txtEdit->font();
    font.setItalic(checked);
    txtEdit->setFont(font);
}

// 设置粗体
void QWDlgManual::on_chkBoxBold(bool checked)
{
    QFont font = txtEdit->font();
    font.setBold(checked);
    txtEdit->setFont(font);
}

// 设置字体颜色
void QWDlgManual::setTextFontColor()
{
    QPalette plet = txtEdit->palette();
    if(btnRed->isChecked()){
        plet.setColor(QPalette::Text, Qt::red);
    }
    else if (btnBlue->isChecked()) {
        plet.setColor(QPalette::Text, Qt::blue);
    }else if(btnBlack->isChecked()) {
        plet.setColor(QPalette::Text, Qt::green);
    }
    txtEdit->setPalette(plet);
}

QWDlgManual::QWDlgManual(QWidget *parent) : QDialog(parent)
{
    initUI(); // 初始化布局
    initSignalSlots(); // 初始化信号与槽
    setWindowTitle("Manually Form");
}

QWDlgManual::~QWDlgManual()
{
}
