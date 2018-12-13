#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);


    //this->resize(650,450);
    ui->account->setPlaceholderText("请输入账号");
    ui->password->setPlaceholderText("请输入密码");

}

Login::~Login()
{
    delete ui;
}

void Login::on_pushButton_login_clicked(){
    if(ui->account->text().operator==("why")){ //&& ui->password->text().operator==("123")){
        QMessageBox::information(this,"",tr("登录成功"));
        this->accept();
    }
    else{
        QMessageBox::information(this,"",tr("登录失败"));
    }
}
