#pragma once
#include<iostream>
using namespace std;
class Complex
{
private:
	double real;
	double image;
public:
	Complex();
	Complex(double real);
	Complex(double real, double image);
	~Complex();
	double getReal();
	double getImage();
	Complex operator + (const Complex & a) const;
	Complex operator - (const Complex & a) const;
	Complex operator * (const Complex & a) const;
	Complex operator / (const Complex & a) const;
	Complex inv() const;
	Complex operator = (const Complex & a);
	friend ostream & operator << (ostream& os, const Complex &a);
};




