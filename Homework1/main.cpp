#include<iostream>
#include<vector>
#include "QuadraticEquation.h"

using namespace std;

int main() {
	int i = 0;
	vector<int> x(3);
	while (i != 3) {
		cin >> x[i];
		//cout << "x:  " << x[i]  << endl;
		i++;
	}

	QuadraticEquation q(x[0], x[1], x[2]);
	cout << "The answer is: \n";
	int a = q.getA();
	cout << endl;
	int b = q.getDiscriminant();
	cout << endl;
	double result1 = q.getRoot1();
	cout << endl;
	double result2 = q.getRoot2();

	cout << endl;
	cout << (result1 == 0);

	cout << "--------------------------";
	getchar();
	getchar();
	return 0;
}
