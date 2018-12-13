#pragma once
#include"People.h"
#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Student:public People{
public:
	Student(string name, int card);
	~Student();

	void print();
	Log& addLog(string time, bool in, bool checkCard, bool checkFace = false);
	int getFace();
};
