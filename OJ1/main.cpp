#include "MyPoint.h"
#include"Stack.h"
#include<iostream>

using namespace std;


int main() {
	int xx, yy;
	int dis;

	MyPoint p;
	MyPoint q(3,4);
	cin >> xx >> yy;

	p.getX();
	p.getY();
	p.distance(xx, yy);
	q.distance(xx,yy);

	Stack* s = new Stack;
	s->show();
	char a = 'a';
	s->push(a);
	s->show();

	Stack* s2 = new Stack;
	char ctemp[5] = { 'a','b','c','d','e' };
	for (int i = 0; i != 5; ++i)
	{
		s2->push(ctemp[i]);
	}
	s2->show();
	s2->pop();
	s2->pop();
	s2->show();

	
	cout << "-----------------------" << endl;

	getchar();
	getchar();
}