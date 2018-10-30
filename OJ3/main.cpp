#include<iostream>
#include"Vector.h"
using namespace std;

int main(){
	Vector<int> v(10); //最多可容纳 10 个元素
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	Vector<int>::iterator it = v.begin();
	for (it = v.begin(); it != v.end(); it++) {
		cout << *it << endl;
	}
	v.insert(v.begin(), 0);
	v.erase(v.end() - 1);
	for (size_t i = 0; i < v.size(); i++) {
		cout << v[i] << endl;
	}
	cout << v[1];
	getchar();
	getchar();
	return -1;
}
/*
int main()
{
	List test;
	int finished;
	cout << "输入建表结束标志数据 ：";
	cin >> finished; //输入建表结束标志数据
	cout << "Input your data: " << endl; //提示
	test.NewList(finished); //建立链表
	cout << "The List is : " << endl;
	test.PrintList(); //打印链表
	cout << endl;
	cout << "The Max is : " << test.GetMax() << endl;
	cout << "The Num is : " << test.GetNum() << endl;
	cout << "The Ave is : " << test.GetAvg() << endl;
	getchar();
	getchar();
	return 0;
}*/