#include "Cylinder.h"


Cylinder::Cylinder(double height, double radius):Body(height)
{
	this->radius = radius;
}

Cylinder::~Cylinder()
{
}

void Cylinder::getArea()
{
	double area = 3.14*radius*radius;
	printf("%.3f\n",area);
}

void Cylinder::getVolume()
{
	double v = 3.14*radius*radius*(getHeight());
	printf("%.3f\n", v);
}


