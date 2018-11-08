#include"Bike.h"
#include"HelloBike.h"
#include"OfoBike.h"
#include"BikeSystem.h"
#include<iostream>

using namespace std;

int main(){
	Bike* tempBike = new OfoBike("ofo10", 40,15,4);
	tempBike->unlock();
	tempBike->unlock() ;
	cout << tempBike->lock()<<endl;
	cout << tempBike->lock()<<endl;


	// Bike* tempBike = new OfoBike("ofobike09", 15,55, 3);
	// tempBike->unlock();
	// tempBike->move_to(90,85);
	// cout << tempBike->lock()<< endl;

	BikeSystem bike_system;
	bike_system.add(new OfoBike("ofo05",30,60,9));
	bike_system.add(new HelloBike("hellobike01","hellobike_elock15",0,0,4));
	bike_system.add(new OfoBike("ofo01",100,100,5));
	bike_system.add(new OfoBike("ofo02",90,0,6));
	bike_system.add(new OfoBike("ofo03",30,70,7));
	bike_system.add(new OfoBike("ofo04",70,0,8));

	int idx1 = bike_system.search("xiaoming",50,50,5);
	int idx2 = bike_system.search("xiaohong",50,50,9);
	bike_system.unlock_bike(idx1);
	bike_system.unlock_bike(idx2);
	bike_system.ride_record(idx1,100,100);
	bike_system.ride_record(idx1,100,80);
	int cost = bike_system.lock_bike(idx1);
	cout << cost << endl;

}