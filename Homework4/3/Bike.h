#pragma once
#include<iostream>
#include<string>
#include<math.h>
using namespace std;

class Bike{
private:
	string serial;
	bool occupied;//false
	int distance;//0
	int x;
	int y;
	int comfort;

public:
	Bike();
	Bike(const char*id, int location_x, int location_y, int comfort_rating);
	~Bike();

	virtual bool unlock()=0;
	virtual int lock()=0;
	virtual int compute_cost()=0;//需要重构
	int move_to(int des_x, int des_y);
	int compute_dist(int start_x, int start_y);

	int get_comfort();
	string get_serial();
	int get_dist();
	bool get_occupied();
	void set_occupied(bool b);
	void init_dist();
};