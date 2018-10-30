#pragma once
#include "Body.h"
class Cylinder :
	public Body
{
private:
	double radius;
public:
	Cylinder(double height, double radius);
	~Cylinder();
	void getArea();
	void getVolume();
};

