#ifndef STUDENT_H
#define STUDENT_H

#include<string>
#include<sstream>
#include<iostream>
using namespace std;

enum{
    MAN = 1, WOMAN = 0
};


using namespace std;

class Student {
public:
    Student():
    id(-1), name(""), sex(""), birthDate(""), birthPlace(""), livingPlace("")
    {
    }

    Student(int id, string name, string sex, string birthDate, string birthPlace, string livingPlace){
        this->id = id;
        this->name = name;
        this->sex = sex;
        this->birthDate = birthDate;
        this->birthPlace = birthPlace;
        this->livingPlace = livingPlace;
    }
    ~Student(){
    }
    int id;
    string name;
    string sex;
    string birthDate;
    string birthPlace;
    string livingPlace;

    void show(){
        cout << id <<"  "<< name <<"  "<< sex <<"  "<< birthDate <<"  "<< birthPlace <<"  " <<livingPlace;
        cout << endl;
    }
};



#endif // STUDENT_H
