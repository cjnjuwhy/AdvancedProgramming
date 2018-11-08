#include"List.h"
using namespace std;
int main(){
	List<char> l;
	l.insert(l.end(), 'a');
	l.insert(l.end(), 'b');
	l.insert(l.end(), 'c');
	l.insert(l.end(), 'd');
	List<char>::iterator it = l.erase(l.begin());
	it = l.erase(it);
	for(; it != l.end(); ++it){
	cout << *it << endl;
	}

}