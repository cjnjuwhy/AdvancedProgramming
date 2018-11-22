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
	int bind_card(Bank_Card* b_card); //����ѧ�����е�У԰������Ϊ�µ����п�
private:
	Student_Card* s_card; //��ѧ�����е�У԰��
};


class Teacher : public Campus_Person {
public:
	Teacher_Card* get_t_card();
	vector<Student*>* get_students();
	Teacher(string campus_id, Bank_Card* b_card, Teacher_Card* t_card);
	~Teacher();
	int add_bind_card(Bank_Card* b_card); //����ʦ��У԰�������Ӱ����п�
	int delete_bind_card(Bank_Card* b_card);//����ʦ��У԰��������ɾ�����п�
	int add_student(Student* stu); //������ʦ��ѧ��
	int delete_student(Student* stu); //ɾ����ʦ��ѧ��
	Teacher_Card* t_card; //����ʦ���е�У԰��
	vector<Student*> stus; //��ʦ��ѧ��
};



