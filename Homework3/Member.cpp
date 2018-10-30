#include "Member.h"

using namespace std;

Member::Member(int id, const char* name, int date, const char* department)
{
	this->id = id;
	this->name = name;
	this->date = date;
	this->department = department;
}


Member::~Member()
{
}

void Member::printInfo()
{
	cout << this->id << " " << this->name << " " << this->date << " " << this->department << endl;
}

int Member::getId(){
	return this->id;
}

int Member::getDate(){
	return this->date;
}
