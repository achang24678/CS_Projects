#include "Tokenizer.hpp"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <vector>
#include <iostream>

using namespace std;
bool loopchar1 (string s);


int main(int argc,char **argv){
    

    
    int input;
    int i = 0;
    

    cout << "Assignment #2-2, Sheng Yu Chang, allen4646463@gmail.com" << endl;
    
    if(argc != 2){

        cout << "ERROR! Program accepts 1 command line argument." << endl;
        exit(0);

    }


    if(loopchar1(argv[1]) == false){

        cout << "ERROR! Program expected integer argument." << endl;
        exit(0);    
    }

    else{

    sscanf(argv[1], "%d", &input);

    for(i = 0; i < input; i++){

    vector<string> *t;
    Tokenizer tokens;
    t = tokens.GetTokens();    
    
        if((*t).size() == 1){

            if(strcasecmp("quit", (*t)[0].c_str()) == 0){

                exit(0);
        
            }
            cout << "STR" << endl;
        }
        else{
			
			cout << "STR INT" << endl;
		}
    
     }
   }

        

return 0;

}


bool loopchar1(string s){
    
    string::iterator st;

	for (st = s.begin(); st != s.end(); st++){

	    if(!isdigit((*st))){
		
        return false;

        }
	}
	return true;

 }
