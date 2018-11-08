#include<iostream>
#include<string>

class Shell{
public:
	Shell(string homedir="/");
	~Shell();

	void cd(string path="");
	void pwd();
	void distance(string path);

	vector<string>& split(const char[] src);
private:
	string home;
	vector<string> tree;
};