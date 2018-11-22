#pragma once
#include<string>
#include"Log.h"
#include<vector>
using namespace std;

class People
{
public:
	People(string name, int card_number);
	~People();

	virtual void print() = 0;
	virtual Log& addLog(string time, bool in, bool checkCard, bool checkFace = false)=0;
	
	int getCard();
	virtual int getFace() = 0;
	void showLog();

protected:
	string name;
	int card_number;
	
	vector<Log> log;

};

