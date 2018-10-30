#include "ThreePrism.h"


ThreePrism::ThreePrism(double height, double side_a, double side_b, double side_c):Body(height)
{
	this->side_a = side_a;
	this->side_b = side_b;
	this->side_c = side_c;
}

ThreePrism::~ThreePrism()
{
}

void ThreePrism::getArea()
{
	double p = (side_a+side_b+side_c)/2;
	double area = sqrt(p*(p-side_a)*(p-side_b)*(p-side_c));
	printf("%.3f\n", area);

}

void ThreePrism::getVolume()
{
	double p = (side_a + side_b + side_c) / 2;
	double area = sqrt(p*(p - side_a)*(p - side_b)*(p - side_c));
	double v = area * getHeight();
	printf("%.3f\n", v);
}
