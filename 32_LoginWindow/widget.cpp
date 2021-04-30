#include "widget.h"
#include "ui_widget.h"

#include <QGridLayout>
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setFixedSize(280, 150);

    userLabel = new QLabel(tr("用户名："), this);
    pwdLabel = new QLabel(tr("密码："), this);

    userLineEdit = new QLineEdit();
    userLineEdit->setMaxLength(12);

    pwdLineEdit = new QLineEdit();
    pwdLineEdit->setEchoMode(QLineEdit::Password);
    pwdLineEdit->setMaxLength(12);

    QGridLayout* gridLayout = new QGridLayout();
    gridLayout->setSpacing(20);
    gridLayout->addWidget(userLabel, 0, 0, 1, 1);
    gridLayout->addWidget(userLineEdit, 0, 1, 1, 1);
    gridLayout->addWidget(pwdLabel, 1, 0, 1, 1);
    gridLayout->addWidget(pwdLineEdit, 1, 1, 1, 1);

    okButton = new QPushButton(tr("确定"));
    connect(okButton, SIGNAL(clicked()), this,SLOT(accept()));

    cancelButton = new QPushButton(tr("取消"));
    connect(cancelButton, SIGNAL(clicked()), this, SLOT(reject()));

    QHBoxLayout* hboxLayout = new QHBoxLayout();
    hboxLayout->setSpacing(60);
    hboxLayout->addWidget(okButton);
    hboxLayout->addWidget(cancelButton);

    QVBoxLayout* vboxLayout = new QVBoxLayout();
    vboxLayout->addLayout(gridLayout);
    vboxLayout->addLayout(hboxLayout);

    this->setLayout(vboxLayout);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::accept()
{
    if (userLineEdit->text().trimmed() == "admin" &&
            pwdLineEdit->text().trimmed() == "admin")
    {
        QDialog::accept();
    }
    else
    {
        QMessageBox::warning(this, tr("警告"), tr("用户名或密码错误"), QMessageBox::Yes);
        userLineEdit->setFocus();
    }
}
