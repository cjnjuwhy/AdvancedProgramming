#pragma once
#include<string>
#include<iostream>
#include"cards.h"

using namespace std;

class Campus_Person{

public:
	Campus_Person(string campus_id, Bank_Card* b_card);
	~Campus_Person();

	string get_campus_id();
	Bank_Card* get_b_card();

protected:
	string campus_id;
	Bank_Card* b_card;
};


class Student : public Campus_Person {
public:
	Student_Card* get_s_card();
	Student(string campus_id, Bank_Card* b_card, Student_Card* s_card);
	~Student();
	int bind_card(Bank_Card* b_card); //将该学生持有的校园卡设置为新的银行卡
private:
	Student_Card* s_card; //该学生持有的校园卡
};


class Teacher : public Campus_Person {
public:
	Teacher_Card* get_t_card();
	vector<Student*>* get_students();
	Teacher(string campus_id, Bank_Card* b_card, Teacher_Card* t_card);
	~Teacher();
	int add_bind_card(Bank_Card* b_card); //向老师的校园卡中增加绑定银行卡
	int delete_bind_card(Bank_Card* b_card);//向老师的校园卡中增加删除银行卡
	int add_student(Student* stu); //增加老师的学生
	int delete_student(Student* stu); //删除老师的学生
	Teacher_Card* t_card; //该老师持有的校园卡
	vector<Student*> stus; //老师的学生
};



