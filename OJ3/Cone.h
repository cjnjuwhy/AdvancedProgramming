#pragma once
#include "Body.h"
class Cone :
	public Body
{
private:
	double radius;
public:
	Cone(double height, double radius);
	~Cone();
	void getArea();
	void getVolume();
};

