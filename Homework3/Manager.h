#include<iostream>
#include"Teacher.h"
#include"Student.h"
#include"Member.h"
#include<vector>
#include<algorithm>

class Manager{
private:
	vector<Member*> data;
public:
	Manager();
	~Manager();
	void add(Member* member);
	void sortById();
	void sortByDate();
	void printSearch(const int id);
	void printAll();
	
};

bool compareId(Member* a, Member* b);
bool compareDate(Member* a, Member* b);