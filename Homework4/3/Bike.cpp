#include"Bike.h"

Bike::Bike(){
	occupied = false;
	distance = 0;
}
Bike::Bike(const char*id, int location_x, int location_y, int comfort_rating):Bike(){
	serial = id;
	x = location_x;
	y = location_y;
	comfort = comfort_rating;
}
Bike::~Bike(){
}

int Bike::move_to(int dest_x, int dest_y){
	printf("from %d,%d to %d,%d\n", x, y, dest_x, dest_y);
	distance += abs(x-dest_x)+abs(y-dest_y);
	this->x = dest_x;
	this->y = dest_y;
	return distance;
}
int Bike::compute_dist(int start_x, int start_y){
	int ans = abs(x-start_x)+abs(y-start_y);
	return ans;
}
//interface
int Bike::get_dist(){
	return distance;
}
int Bike::get_comfort(){
	return comfort;
}
string Bike::get_serial(){
	return serial;
}
bool Bike::get_occupied(){
	return occupied;
}
void Bike::set_occupied(bool b){
	occupied = b;
}
void Bike::init_dist(){
	distance = 0;
}

// bool Bike::unlock(){
// 	if(occupied)
// 		return false;
// 	occupied = true;
// 	return true;
// }

// int Bike::lock(){
// 	if(occupied){
// 		occupied = false;
// 		int cost = compute_cost();
// 		distance = 0;
// 		return cost;
// 	}
// 	else
// 		return -1;
// }
