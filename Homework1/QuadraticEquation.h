#pragma once
class QuadraticEquation {
public:
	QuadraticEquation(int x, int y, int z);
	~QuadraticEquation();

	int getA() const;
	int getB() const;
	int getC() const;
	int getDiscriminant();
	double getRoot1();
	double getRoot2();

private:
	void initialization();
	int a;
	int b;
	int c;
	int det;
	double root1;
	double root2;
};

