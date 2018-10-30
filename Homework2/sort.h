#include<iostream>

using namespace std;

template <class T>
void sort (T elements[], unsigned int count){
	for (int i=count; i>0; i--){
		for (int j=0; j<i-1; j++){
			if(elements[j]>elements[j+1]){
				T temp = elements[j];
				elements[j] = elements[j+1];
				elements[j+1] = temp;
			}
		}
	}
}

