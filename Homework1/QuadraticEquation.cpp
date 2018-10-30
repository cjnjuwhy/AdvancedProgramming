#include "QuadraticEquation.h"
#include<iostream>
#include "math.h"
using namespace std;

QuadraticEquation::QuadraticEquation(int x, int y, int z) {
	a = x;
	b = y;
	c = z;
	initialization();
}

QuadraticEquation::~QuadraticEquation() {
}

void QuadraticEquation::initialization()
{
	det = b * b - 4 * a * c;
	if (det < 0) {
		root1 = 0;root2 = 0;
	}
	else {
		double temp;
		if (det == 0)temp = 0;
		else
			temp = sqrt(det);
		double r1 = ( 0 + temp - b) / double(2 * a);
		double r2 = ( 0 - temp - b) / double(2 * a);
		root1 = r1>r2?r1:r2;
		root2 = r1>r2?r2:r1;

		if (root1 == 0)root1 = 0;
		if (root2 == 0)root2 = 0;
	}
}

int QuadraticEquation::getA() const {
	cout << a << endl;
	return a;
}
int QuadraticEquation::getB() const {
	cout << b << endl;
	return b;
}
int QuadraticEquation::getC() const {
	cout << c << endl;
	return c;
}

int QuadraticEquation::getDiscriminant() {
	cout << det << endl;
	return det;
}

double QuadraticEquation::getRoot1() {
	cout << root1 << endl;
	return root1;
}
double QuadraticEquation::getRoot2() {
	cout << root2 << endl;
	return root2;
}
