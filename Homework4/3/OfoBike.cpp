#include"OfoBike.h"

OfoBike::OfoBike(const char*id, int location_x, 
		int location_y, int comfort_rating):
		Bike(id, location_x, location_y, comfort_rating){
}
OfoBike::~OfoBike(){
}

bool OfoBike::unlock(){
	if(!get_occupied()){
		cout << "unlock " << get_serial();
		cout <<endl;
		set_occupied(true);
		return true;
	}
	cout << "fail to unlock " << get_serial();
	cout <<endl;
	return false;
}

int OfoBike::lock(){
	if(!get_occupied()){
		cout << get_serial() << " has been locked";
		cout <<endl;
		return -1;
	}
	cout << "lock " << get_serial();
	cout <<endl;
	set_occupied(false);
	int cost = compute_cost();
	init_dist();
	return cost;
}

int OfoBike::compute_cost(){
	int dist = get_dist();
	double hour = (double)dist / 21;
	int fee_time = ceil(hour);
	int fee = max(0 , fee_time*2-7);
	return fee;
}