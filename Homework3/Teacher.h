#pragma once
//#ifndef __Teacher_h
//#define __Teacher_h

#include<iostream>
#include"Member.h"
#include<string>
using namespace std;

class Teacher:public Member{
private:
	string title;
public:
	Teacher(int id, const char* name, int date, const char* department, const char* title);
	~Teacher();
};