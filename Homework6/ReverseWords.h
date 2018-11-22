#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<algorithm>

using namespace std;

class ReverseWords
{
public:
	ReverseWords() {
		before_reverse = "";
		after_reverse = "";
	}
	~ReverseWords() {

	}

	string getSentence(string filename) {
		ifstream in_file;
		try {
			in_file.open(filename, ios::in);
			if (in_file.fail())
				throw filename;
		}
		catch (string e) {
			cout << "file: " << e << " not found!\n";
			cout << "Please type the filename again.";
			string file;
			cin >> file;
			in_file.open(file, ios::in);
		}
		string temp;

		while (!in_file.eof()) {
			in_file >> temp;
			sentence.push_back(temp);
		}
		in_file.close();
		for (string s : sentence) {
			if (!before_reverse.empty()) {
				before_reverse += " ";
			}
			before_reverse += s;
		}
		return before_reverse;
	}


	string reverseString() {
		vector<string>::iterator it = sentence.begin();
		for (; it != sentence.end(); it++) {
			reverse((*it).begin(), (*it).end());
		}

		for (string s : sentence) {
			if (!after_reverse.empty()) {
				after_reverse += " ";
			}
			after_reverse += s;
		}
		return after_reverse;
	}

private:
	vector<string> sentence;
	string before_reverse;
	string after_reverse;

};



