#pragma once
#include"People.h"
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Teacher:public People{
public:
	Teacher(string name, int card);
    Teacher(string name, int card, int face);
	~Teacher();
	int getFace();

	Log& addLog(string time, bool in, bool checkCard, bool checkFace = false);
	void print();

private:
    int face_number;
};
