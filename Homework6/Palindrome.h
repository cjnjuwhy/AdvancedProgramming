#pragma once
#include<iostream>
#include<string>
#include<fstream>

using namespace std;

//文件读写最重要的是结尾的判断，C++中对于eof的判断
//1）文件位置指针在文件末尾
//2）并且继续去读文件内容时
//才会变成true。
//如果不妥善解决好这点，就会陷入死循环，无限的读取最后一个部分的内容。
//读取文件的格式也很关键，这决定了位置指针需要移动多少个位置（sizeof(type)）


class Palindrome {
public:
	Palindrome() {
		ans = 0;
	}
	~Palindrome() {
	}

	int GetOddNumber(string filename) {
		ifstream in_file;
		try {
			in_file.open(filename, ios::in | ios::binary);
			if (in_file.fail()) throw filename;
		}
		catch (string e) {
			cout << "file: " << e << " not found!\n";
			cout << "Please type the file name again.";
			string file;
			cin >> file;
			in_file.open(file, ios::in | ios::binary);
		}

		char c;
		int x;
		int flag = 1;
		in_file.read((char*)&c, sizeof(c));
		if (c != '+' && c != '-') {
			in_file.seekg(ios::beg);
		}
		else if (c == '-')
			flag = -1;

		in_file.read((char*)&x, sizeof(x));
		while (x == 0 && !in_file.eof()) {
			in_file.read((char*)&x, sizeof(x));
		}
		while (!in_file.eof()) {
			ans *= 10;
			ans += x;
			// cout << x << "\t";
			in_file.seekg(sizeof(x), in_file.cur);
			in_file.read((char*)&x, sizeof(x));
		}
		ans *= flag;
		in_file.close();
		return ans;
	}


	bool IsOddNumberPalindrome() {
		if (ans < 0) return false;
		int temp = ans;
		int huiwen = 0;
		while (temp != 0) {
			huiwen *= 10;
			huiwen += (temp % 10);
			temp /= 10;
		}
		if (huiwen == ans)
			return true;
		else
			return false;
	}

private:
	int ans;
};