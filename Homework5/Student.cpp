#include"Student.h"

Student::Student(string name, int card)
:People(name, card){
}

Student::~Student(){

}

void Student::print()
{
	cout << "学生：" << name << "\tCard: " << card_number << endl;
}

Log& Student::addLog(string time, bool in, bool checkCard, bool checkFace)
{
	bool result = checkCard;
	Log newLog(name, "学生", time, in, result);
	log.push_back(newLog);
	return log.back();
}

int Student::getFace()
{
	return -1;
}


