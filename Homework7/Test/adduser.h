#ifndef ADDUSER_H
#define ADDUSER_H

#include <QDialog>
#include "studentmanage.h"
#include "student.h"

namespace Ui {
class AddUser;
}

class AddUser : public QDialog
{
    Q_OBJECT

public:
    explicit AddUser(QWidget *parent = nullptr);
    AddUser(StudentManage* stm, int n);

    ~AddUser();
    void addMember(StudentManage* stm);
    void modifyMember(StudentManage* stm, int n);

private:
    Ui::AddUser *ui;
};

#endif // ADDUSER_H
