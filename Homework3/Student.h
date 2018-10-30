#pragma once
//#ifndef __Student_h
//#define __Student_h

#include<iostream>
#include<string>
#include"Member.h"

class Student: public Member{
private:
	string major;

public:
	Student(int id, const char* name, int date, const char* department, const char* major);
	~Student();	
};

//#endif