#include"Student.h"

Student::Student(string name, int card)
:People(name, card){
}

Student::~Student(){

}

void Student::print()
{
	cout << "ѧ����" << name << "\tCard: " << card_number << endl;
}

Log& Student::addLog(string time, bool in, bool checkCard, bool checkFace)
{
	bool result = checkCard;
	Log newLog(name, "ѧ��", time, in, result);
	log.push_back(newLog);
	return log.back();
}

int Student::getFace()
{
	return -1;
}


