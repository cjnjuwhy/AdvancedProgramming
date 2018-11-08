#pragma once
#include<iostream>
#include"Bike.h"
#include<math.h>
using namespace std;

class OfoBike:public Bike{

public:
	OfoBike(const char*id, int location_x, int location_y, int comfort_rating);
	~OfoBike();

	bool unlock();
	int lock();
	int compute_cost();
};	
