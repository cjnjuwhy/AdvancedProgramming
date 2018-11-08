#pragma once
#include<iostream>
#include<math.h>
#include"Bike.h"

class HelloBike:public Bike{
public:
	HelloBike(const char* id, const char* elock_id, int location_x, int location_y, int comfort_rating);
	~HelloBike();
	bool unlock();
	int lock();
	int compute_cost();
private:
	string elock;
};