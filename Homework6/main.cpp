#include"ReverseWords.h"
#include"Palindrome.h"
using namespace std;

int main() {
	ReverseWords* rw = new ReverseWords();
	cout << rw->getSentence("test.dat") <<endl;
	cout << rw->reverseString();

	cout << "------------------------\n";

	Palindrome* p = new Palindrome();
	cout << p->GetOddNumber("2.txt") << "\t";
	cout << p->IsOddNumberPalindrome();
	cin.get();
}