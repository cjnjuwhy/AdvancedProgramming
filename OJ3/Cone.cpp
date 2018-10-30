#include "Cone.h"



Cone::Cone(double height, double radius):Body(height)
{
	this->radius = radius;
}

Cone::~Cone()
{
}

void Cone::getArea()
{
	double area = 3.14*radius*radius;
	printf("%.3f\n", area);
}

void Cone::getVolume()
{
	double v = 3.14*radius*radius*(getHeight())/3;
	printf("%.3f\n", v);
}
