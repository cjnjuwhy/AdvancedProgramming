#pragma once
#include <iostream>
using namespace std;

class List;
class ListNode {
	friend class List;
private:
	int data;
	ListNode *link;
	ListNode(const int item):data(item),link(NULL){}
};

class List {
private:
	ListNode *first, *current;
	int temp;
	int Max(ListNode *f);
	int Num(ListNode *f);
	float Avg(ListNode *f, int& n);
public:
	List() : first(NULL), current(NULL), temp(0) { }
	~List() { }
	ListNode* NewNode(const int item);
	void NewList(const int retvalue);
	void PrintList();
	int GetMax();
	int GetNum();
	float GetAvg();
};


