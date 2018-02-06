#include"Tokenizer.hpp"
#include <string>
#include <iostream>
#include <stdio.h>
#include <sstream>


using namespace std;

bool loopchar(string s);



vector<string>* Tokenizer::GetTokens()
{
	vector<string> *t = new vector<string>;

   
    
    bool valid = true;
    
    while(valid == true){

	    cout << ">";
        string s;
	    getline(cin, s);

        (*t).clear();

        string stb;
        stringstream sts(s);


        while(sts >> stb){
        
            (*t).push_back(stb);
		}
        
        if((*t).size() == 1){
        
            if(loopchar((*t)[0]) == true){
        
                    cout << "ERROR!Expected STR." << endl;
            }
            else{
                    return t;
            }
        }

        else if((*t).size() == 2){
            
                if((loopchar((*t)[0]) == false && loopchar((*t)[1])) == true){
            
                    return t;
                }
                else{

                    cout << "ERROR! Expected STR INT." << endl;
                }
        }

        else{

            cout << "ERROR! Incorrect number of tokens found." << endl;
        }
    }

}

bool loopchar(string s){
    
    string::iterator st;

	for (st = s.begin(); st != s.end(); st++){

	    if(!isdigit((*st))){
		
        return false;

        }
	}
	return true;

 }
