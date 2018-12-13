#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include<string>
#include<iostream>
#include<QMessageBox>

using namespace std;

namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

private:
    Ui::Login *ui;


private slots:
    void on_pushButton_login_clicked();
};

#endif // LOGIN_H
