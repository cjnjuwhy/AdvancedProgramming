#include"Shell.h"




vector<string>& Shell::split(const char[] src){
	vector<string> ret;

	char sep[] = "/";
	char *token;
	token = strtok( string, seps );
   	while( token != NULL ){
   		ret.push_back(token);
	    //printf( " %s\n", token );
    	token = strtok( NULL, seps );
    }
    return ret;
}

void Shell::cd(){
	
}