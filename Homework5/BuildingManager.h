#pragma once
#include"Log.h"
#include"People.h"
#include<vector>
#include<set>
#include<algorithm>

using namespace std;

bool comp(const Log& a,const Log& b);

class BuildingManager{
public:
	BuildingManager();

	// add and delete the Card and Face set
	void addCard(vector<int> cards);
	void addFace(vector<int> faces);
	void deleteCard(vector<int> cards);
	void deleteFace(vector<int> faces);
	void deleteCard(int card);
	void deleteFace(int face);

	// clear the dataset
	void clearCard();
	void clearFace();

	// show the dataset
	void printCard();
	void printFace();

	// check whether in the dataset
	bool checkFace(int face);
	bool checkCard(int card);

	void addLog(Log& newLog);
	void showLog();

	void in(People* p, string time);
	void out(People* p, string time);

	friend bool comp(const Log& a,const Log& b);

private:
	set<int> card_info;
	set<int> face_info;
	vector<Log> log;
};


