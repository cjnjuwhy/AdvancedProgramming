#pragma once
#include<iostream>
using namespace std;
class Body
{
private:
	double height;
public:
	Body();
	Body(double height);
	~Body();
	void printHeight();
	double getHeight();
};

