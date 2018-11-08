#include"HelloBike.h"

HelloBike::HelloBike(const char* id, const char* elock_id, int location_x, 
		int location_y, int comfort_rating):
		Bike(id, location_x, location_y, comfort_rating){
	elock = elock_id;
}

HelloBike::~HelloBike(){
}

bool HelloBike::unlock(){
	if(!get_occupied()){
		printf("unlock %s %s\n",get_serial(),elock);
//		cout << "unlock " << get_serial() << " " << elock;cout <<endl;
		set_occupied(true);
		return true;
	}
	printf("fail to unlock %s %s\n",get_serial(),elock);
	return false;
}

int HelloBike::lock(){
	if(!get_occupied()){
		printf("%s %s has been locked\n",get_serial(),elock);
		return -1;
	}
	cout << "lock " << get_serial() << " " << elock;cout <<endl;
	set_occupied(false);
	int cost = compute_cost();
	init_dist();
	return cost;
}
int HelloBike::compute_cost(){
	int dist = get_dist();
	double hour = (double)dist / 25;
	int fee_time = ceil(hour);
	int fee = max(0 , fee_time*2-5);
	return fee;
}
