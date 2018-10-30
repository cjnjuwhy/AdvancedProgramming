//#ifndef __Member_h
//#define __Member_h
#pragma once
#include<iostream>
#include<string>

using namespace std;

class Member
{
private:
	int id;
	string name;
	int date;
	string department;

public:
	Member(int id, const char* name, int date, const char* department);
	~Member();

	void printInfo();
	int getId();
	int getDate();
};


//#endif

