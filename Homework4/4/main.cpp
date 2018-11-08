//#include"Shell.h"
#include<cstring>
#include<vector>
#include<iostream>
using namespace std;

int main( void ){
	vector<string> s;
	char string[] = "why/desktop/user/why";
	char seps[]   = "/";
	char *token;
   	printf( "%s\n\nTokens:\n", string );
   	token = strtok( string, seps );
   	
   	while( token != NULL ){
   		s.push_back(token);
	    printf( " %s\n", token );
    	token = strtok( NULL, seps );
    }
   	cout << "------------------------" << endl;
   	//vector<string>::iterator it = s.begin();
   	for(auto k:s)
   		cout << k <<endl;
}