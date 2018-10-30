#pragma once
class MyPoint
{
private:
	int x;
	int y;

public:
	MyPoint();
	MyPoint(int a, int b);
	~MyPoint();

	int getX() const;
	int getY() const;
	double distance(const MyPoint p);
	double distance(int x, int y);



};

