#include<iostream>
#include"Complex.h"
//#include"Iterator.h"
#include"merge.h"
using namespace std;

/*
int main() {
	int int_array[4] = { 1 , 2 , 3 , 4 };
	Iterator<int> i_begin(int_array);
	Iterator <int> i_end(int_array + 4);
	for (Iterator<int> i = i_begin; i != i_end; i++) {
		cout << *i << endl;
	}


	getchar();
}

*/

int main() {
	int int_array_1[3] = { 1 , 2 , 4 };
	int int_array_2[1] = { 3 };
	int * int_res = NULL;
	int_res = merge(int_array_1, 3, int_array_2, 1);
	for (int i = 0; i < 4; i++)
		std::cout << int_res[i] << endl;

	char char_array_1[2] = { 'c' , 'd' };
	char char_array_2[2] = { 'a' , 'z' };
	char * char_res = NULL;
	char_res = merge(char_array_1, 2, char_array_2, 2);
	for (int i = 0; i < 4; i++)
		std::cout << char_res[i] << endl;

	double double_array_1[5] = { 0.3 , 1.2 , 1.9 , 2.0 , 5.8 };
	double double_array_2[2] = { 0.1 , 2.8 };
	double * double_res = NULL;
	double_res = merge(double_array_1, 5, double_array_2, 2);
	for (int i = 0; i < 7; i++)
		std::cout << double_res[i] << endl;

	getchar();

}