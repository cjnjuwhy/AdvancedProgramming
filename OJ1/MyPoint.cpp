#include "MyPoint.h"
#include<math.h>
#include<iostream>

using namespace std;

MyPoint::MyPoint()
{
	x = 0;
	y = 0;
}

MyPoint::MyPoint(int a, int b)
{
	x = a;
	y = b;
}


MyPoint::~MyPoint()
{
}

int MyPoint::getX() const
{
	cout << x << endl;
	return x;
}

int MyPoint::getY() const
{
	cout << y << endl;
	return y;
}

double MyPoint::distance(const MyPoint p)
{
	double temp;
	temp = (p.x - x)*(p.x - x) + (p.y - y)*(p.y - y);
	cout << sqrt(temp) << endl;
	return sqrt(temp);
}

double MyPoint::distance(int a, int b)
{
	MyPoint temp(a, b);
	return this->distance(temp);
}
