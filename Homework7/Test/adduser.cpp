#include "adduser.h"
#include "ui_adduser.h"

AddUser::AddUser(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddUser)
{
    ui->setupUi(this);

}


AddUser::AddUser(StudentManage* stm, int n) :
    AddUser()
{
    const Student& st = stm->student_vector[n];
    ui->id->setText(QString::number(st.id));
    ui->name->setText(QString::fromStdString(st.name));
    ui->sex->setCurrentText(QString::fromStdString(st.sex));
    QDate date;
    date.fromString(QString::fromStdString(st.birthDate), "yyyy/M/d");
    ui->birthDate->setDate(date);
    ui->birthPlace->setText(QString::fromStdString(st.birthPlace));
    ui->livingPlace->setText(QString::fromStdString(st.livingPlace));

}

AddUser::~AddUser()
{
    delete ui;
}


void AddUser::addMember(StudentManage* stm){
    int id = ui->id->text().toInt();
    string name = ui->name->text().toStdString();
    string sex = ui->sex->currentText().toStdString();
    string birthDate = ui->birthDate->text().toStdString();
    //string birthDate = ui->birthDate->text().toStdString();
    string birthPlace = ui->birthPlace->text().toStdString();
    string livingPlace = ui->livingPlace->text().toStdString();

    Student* st = new Student(id, name, sex, birthDate, birthPlace, livingPlace);
    stm->add(*st);
}


void AddUser::modifyMember(StudentManage* stm, int n){
    int id = ui->id->text().toInt();
    string name = ui->name->text().toStdString();
    string sex = ui->sex->currentText().toStdString();
    string birthDate = ui->birthDate->text().toStdString();
    string birthPlace = ui->birthPlace->text().toStdString();
    string livingPlace = ui->livingPlace->text().toStdString();

    Student& st = stm->student_vector[n];
    st.id = id;
    st.name = name;
    st.sex = sex;
    st.birthDate = birthDate;
    st.birthPlace = birthPlace;
    st.livingPlace = livingPlace;

}
