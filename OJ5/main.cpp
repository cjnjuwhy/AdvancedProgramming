#include<iostream>
#include"jobs.h"
#include"cards.h"
#include"persons.h"
using namespace std;

//int main() {
//	int n = 4;
//
//	Job myjob[4];
//	myjob[0] = { 1,1,9,1 };
//	myjob[1] = { 2,4,3,2 };
//	myjob[2] = { 3,5,1,3 };
//	myjob[3] = { 4,17,5,4 };
//	JobSchedual *jobs = new JobSchedual(myjob, n);
//	jobs->RoundRobin(3);
//
//	getchar();
//	getchar();
//}

int main()
{
	/*
	����һ��ѧ��
	*/
	Bank_Card* s_b_card = new Bank_Card("s_b1", 100);
	Student_Card* s_card = new Student_Card("s_s1", 0, s_b_card);
	Student* s = new Student("s_1", s_b_card, s_card);
	/*
	����һ����ʦ
	*/
	Bank_Card* t_b_card = new Bank_Card("t_b1", 100);
	Teacher_Card* t_card = new Teacher_Card("t_s1", 0, 0.9, t_b_card);
	Teacher* t = new Teacher("t_1", t_b_card, t_card);
	/*
	�������п�����
	*/
	s_b_card->consume(10);
	if (s_b_card->get_accunt_balance() != 90) cout << "wrong1" << endl;
	s_b_card->recharge(10);
	if (s_b_card->get_accunt_balance() != 100) cout << "wrong2" << endl;
	/*
	����ѧ��������
	*/
	s_card->recharge(s_b_card, 10);
	if (s_b_card->get_accunt_balance() != 90 || s_card->get_accunt_balance() != 10) cout
		<< "wrong3" << endl;
	s_card->consume(10);
	if (s_b_card->get_accunt_balance() != 90 || s_card->get_accunt_balance() != 0) cout
		<< "wrong4" << endl;
	//�½�һ��δ�󶨵Ŀ����˴�Ӧ�ó�ֵʧ��
	Bank_Card* temp1 = new Bank_Card("temp1", 100);
	s_card->recharge(temp1, 10);
	if (s_card->get_accunt_balance() != 0 || temp1->get_accunt_balance() != 100) cout <<
		"wrong5" << endl;

	/*
	������ʦ������
	*/
	t_card->recharge(t_b_card, 10);
	if (t_b_card->get_accunt_balance() != 90 || t_card->get_accunt_balance() != 10)
		cout << "wrong6" << endl;
	t_card->consume(10);
	if (t_b_card->get_accunt_balance() != 90 || t_card->get_accunt_balance() != 1) cout
		<< "wrong7" << endl;
	//ʹ��ѧ������ֵ���˴�Ӧ�ó�ֵʧ��
	t_card->recharge(s_b_card, 10);
	if (t_b_card->get_accunt_balance() != 90 || t_card->get_accunt_balance() != 1 ||
		s_b_card->get_accunt_balance() != 90) cout << "wrong8" << endl;
	/*
	����ѧ���󶨹���
	*/
	s->bind_card(temp1);
	s_card->recharge(s_b_card, 10);
	if (s_b_card->get_accunt_balance() != 90 || s_card->get_accunt_balance() != 0) cout
		<< "wrong9" << endl;
	cout << "s_b_card->get_accunt_balance(): " << s_b_card->get_accunt_balance() << endl;
	cout << "s_card->get_accunt_balance(): " << s_card->get_accunt_balance() << endl;
	s_card->recharge(temp1, 10);
	if (temp1->get_accunt_balance() != 90 || s_card->get_accunt_balance() != 10) cout
		<< "wrong10" << endl;

	/*
	������ʦ�󶨹���
	*/
	t->add_student(s);
	t->add_bind_card(s->get_b_card());
	t_card->recharge(s_b_card, 10);
	if (s_b_card->get_accunt_balance() != 80 || t_card->get_accunt_balance() != 11)
		cout << "wrong11" << endl;
	//������п��İ�֮���ܽ��г�ֵ
	t->delete_bind_card(s->get_b_card());
	t_card->recharge(s_b_card, 10);
	if (s_b_card->get_accunt_balance() != 80 || t_card->get_accunt_balance() != 11)
		cout << "wrong11" << endl;
	//������ʦѧ���Ŀ����ܽ��а�
	Bank_Card* test1 = new Bank_Card("test1", 100);
	if (t->add_bind_card(test1) != -1) cout << "wrong12" << endl;
	//����ɾ��ѧ��
	t->delete_student(s);
	if (t->add_bind_card(s->get_b_card()) != -1) cout << "wrong13" << endl;

	getchar();
	getchar();
	return 0;
}