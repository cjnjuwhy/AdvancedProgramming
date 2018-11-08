#pragma once
#include<iostream>
#include<iomanip>
using namespace std;
/*
必须对数据有良好的组织，才能够很好的进行后面的操作
如果每次增改后都有序排列，会比较好
所以可以选用数组，或者是链表来实现
涉及到指针操作，就要重载=啊！
在操作符重载时，最关键的就是涉及到指针的操作，涉及到
指针操作就需要自己做很多事情。
*/
struct Node{
	Node* next;
	int data;
	Node(int d){
		next = nullptr;
		data = d;
	}
};

class Set{
private:
	Node * head;
	int len;
	//用于操作符重载new和delete
	static Set *p_free;
	Set * next;

public:
	Set();
	Set( const Set& set);
	Set(int elements[], int length);
	~Set();

public:
	int size();
	void add(int element);
	bool erase(int element);
	bool contains(int element);
	//对集合的一些操作进行操作符重载
	friend ostream &operator<<(ostream &os,const Set &rset);

	Set& operator =(const Set& set);
	friend Set operator +(const Set &lset, const Set &rset);
	Set& operator +=(const Set &rset);
	friend Set operator -(const Set &lset, const Set &rset);
	Set& operator -=(const Set &rset);
	
	friend Set operator &(const Set &lset, const Set &rset);
	friend Set operator |(const Set &lset, const Set &rset);
	
	friend bool operator ==(const Set &lset, const Set &rset);
	friend bool operator !=(const Set &lset, const Set &rset);
	
	friend bool operator >(const Set &lset, const Set &rset);
	friend bool operator >=(const Set &lset, const Set &rset);
	friend bool operator <(const Set &lset, const Set &rset);
	friend bool operator <=(const Set &lset, const Set &rset);
	
	static void * operator new(size_t size);
	static void operator delete(void *p, size_t size); 
};

ostream &operator<<(ostream &os,const Set &rset);
Set operator +(const Set &lset, const Set &rset);
Set operator -(const Set &lset, const Set &rset);
Set operator &(const Set &lset, const Set &rset);
Set operator |(const Set &lset, const Set &rset);
bool operator ==(const Set &lset, const Set &rset);
bool operator !=(const Set &lset, const Set &rset);
bool operator >(const Set &lset, const Set &rset);
bool operator >=(const Set &lset, const Set &rset);
bool operator <(const Set &lset, const Set &rset);
bool operator <=(const Set &lset, const Set &rset);