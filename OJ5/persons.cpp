#include "persons.h"

Campus_Person::Campus_Person(string campus_id, Bank_Card * b_card)
{
	this->campus_id = campus_id;
	this->b_card = b_card;
}

Campus_Person::~Campus_Person()
{
}

string Campus_Person::get_campus_id()
{
	return campus_id;
}

Bank_Card * Campus_Person::get_b_card()
{
	return b_card;
}

Student_Card * Student::get_s_card()
{
	return s_card;
}

Student::Student(string campus_id, Bank_Card * b_card, Student_Card * s_card)
	:Campus_Person(campus_id, b_card)
{
	this->s_card = s_card;
}

Student::~Student()
{
}

int Student::bind_card(Bank_Card * b_card)
{
	s_card->b_card = b_card;
	return 0;
}

Teacher_Card * Teacher::get_t_card()
{
	return t_card;
}

vector<Student*>* Teacher::get_students()
{
	return &stus;
}

Teacher::Teacher(string campus_id, Bank_Card * b_card, Teacher_Card * t_card)
	:Campus_Person(campus_id, b_card)
{
	this->t_card = t_card;
}

Teacher::~Teacher()
{
}

int Teacher::add_bind_card(Bank_Card * b_card)
{
	vector<Student*>::iterator it = stus.begin();

	while (it != stus.end()) {
		if ((*it)->get_b_card() == b_card) {
			t_card->get_b_cards()->push_back(b_card);
			return 0;
		}
		it++;
	}
	return -1;
}

int Teacher::delete_bind_card(Bank_Card * b_card)
{
	vector<Bank_Card*>* t = t_card->get_b_cards();
	vector<Bank_Card*>::iterator it = t->begin();
	while (it != t->end()) {
		if (*it == b_card) {
			t->erase(it);
			return 0;
		}
		it++;
	}
	return -1;
}

int Teacher::add_student(Student * stu)
{
	vector<Student*>::iterator it = stus.begin();
	while (it != stus.end()) {
		if (*it == stu)
			return -1;
		it++;
	}
	stus.push_back(stu);
	return 0;
}

int Teacher::delete_student(Student * stu)
{
	vector<Student*>::iterator it = stus.begin();
	while (it != stus.end()) {
		if (*it == stu) {
			stus.erase(it);
			return 0;
		}
		it++;
	}
	return -1;
}
