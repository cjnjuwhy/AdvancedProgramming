#include"Set.h"
#include<iostream>

using namespace std;
int main(){

	Set set1;
	int ele2[] = {1,2,3,4,5};
	Set set2(ele2, 5);

	cout << set1 ;
	cout << set1.size() <<endl;
	set2  -= set1;
	cout << "set2-=set1: " << set2 <<endl;
	cout <<"set2-set1:   " << set2 - set1 << endl;

	cout << "set1 >= set2" << (set1 >= set2);
	if(set1 <= set2)
		cout << "set1 <= set2";
	if(set1 < set2)
		cout << "set1 < set2";
	if(set1 > set2)
		cout << "set1 > set2";
	return 0;
}