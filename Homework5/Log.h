#pragma once
#include<string>
#include<iostream>

using namespace std;

class Log {
public:
	Log(string name, string identity, string time, bool in = false, bool result = true, bool method = 0);
	// default out, default by card, default true in
	~Log();

	Log& getLog();
	string showLog();

	string name;
	string identity;
	string time;
	bool in;
	bool result;
	bool method;
};