#pragma once
#include "Body.h"
#include<math.h>
class ThreePrism :
	public Body
{
private:
	double side_a;
	double side_b;
	double side_c;
public:
	ThreePrism(double height, double side_a, double side_b, double side_c);
	~ThreePrism();
	void getArea();
	void getVolume();
};

