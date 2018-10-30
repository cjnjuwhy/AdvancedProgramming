#include "Complex.h"
#include<iostream>
#include<iomanip>
using namespace std;


Complex::Complex()
{
	this->real = 0;
	this->image = 0;
}

Complex::Complex(double real)
{
	this->real = real;
	this->image = 0;
}

Complex::Complex(double real, double image)
{
	this->real = real;
	this->image = image;
}


Complex::~Complex()
{
}

Complex Complex::operator + (const Complex & a) const {
	Complex temp;
	temp.real = Complex::real + a.real;
	temp.image = Complex::image + a.image;
	return temp;
}
Complex Complex::operator - (const Complex & a) const {
	Complex temp;
	temp.real = Complex::real - a.real;
	temp.image = Complex::image - a.image;
	return temp;
}
Complex Complex::operator * (const Complex & a) const {
	Complex temp;
	temp.real = Complex::real * a.real - Complex::image * a.image;
	temp.image = Complex::real * a.image + Complex::image * a.real;
	return temp;
}
Complex Complex::operator / (const Complex & a) const {
	Complex temp2;
	Complex temp;
	temp.real = a.real / (a.real*a.real + a.image*a.image);
	temp.image = -a.image / (a.real*a.real + a.image*a.image);
	//Complex t = a.inv();
	//temp = *this * t ;
	temp2 = *this * temp;
	return temp2;
}

Complex Complex::inv() const {
	Complex temp;
	temp.real = real / (real*real + image*image);
	temp.image = -image / (real*real + image*image);
	return temp;
}

Complex Complex::operator=(const Complex & a)
{
	if (&a == this) return *this;
	this->real = a.real;
	this->image = a.image;
	return *this;
}

double Complex::getReal() {
	return real;
}
double Complex::getImage() {
	return image;
}


ostream & operator<<(ostream & os, const Complex & a)
{
	//os  << setiosflags(ios::showpoint)<<setprecision(2) << double(a.real) << " " << a.image << endl;
	printf("%.2f %.2f\n", a.real, a.image);
	return os;
}
