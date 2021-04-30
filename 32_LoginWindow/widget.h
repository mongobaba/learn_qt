#ifndef WIDGET_H
#define WIDGET_H

#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QDialog
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    virtual void accept();

private:
    Ui::Widget *ui;
    QLineEdit* userLineEdit;
    QLineEdit* pwdLineEdit;
    QLabel* userLabel;
    QLabel* pwdLabel;
    QPushButton* okButton;
    QPushButton* cancelButton;
};
#endif // WIDGET_H
