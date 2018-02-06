#include "Tokenizer.hpp"
#include "Stack.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


using namespace std;


bool loopchar1 (string s);



int main(int argc, char* argv[]){

    Stack<int> stack;
    int input;
    int count = 0;
    int p;



	cout << "Assignment #2-3, Sheng Yu Chang, allen4646463@gmail.com" << endl;

	if(argc > 2){

        cout << "ERROR! Program accepts 1 command line argument." << endl;
        exit(0);

    }


    if(loopchar1(argv[1]) == false){

        cout << "ERROR! Program expected integer argument." << endl;
        exit(0);    
    }

	
	sscanf(argv[1], "%d", &input);
    
	
	
	while(count < input){
	
		Tokenizer tok;
		vector<string>* t;
		t = tok.GetTokens();

		if ((*t).size() == 1){
		
			if (strcasecmp("quit", (*t)[0].c_str()) == 0){
			
				stack.Print();
				exit(0);
			}
			if (loopchar1((*t)[0]) == true){
			
				cout << "ERROR!Expected STR." << endl;
			}
			else{
			
				
				if ((*t)[0] == "pop"){
				
					stack.Pop();
				}
				count++;
			}
		}

		else if ((*t).size() == 2){
		
			if (loopchar1((*t)[0]) == false && loopchar1((*t)[1]) == true){
			
				
				if ((*t)[0] == "push"){
				
					
					sscanf((*t)[1].c_str(), "%d", &p);

					stack.Push(p);
				}
				count++;
			}

			else{
			
				cout << "ERROR! Expected STR INT." << endl;
			}
		}
		else{
		
			cout << "ERROR! Incorrect number of tokens found." << endl;
		}

	    free(t);
	}
    
    
	stack.Print();
	
	return 0;
}



bool loopchar1 (string s){
    
    string::iterator st;
	for (st = s.begin(); st != s.end(); st++){

	    if(!isdigit((*st))){
		
        return false;

        }
	}
	return true;

 }
