#ifndef Tokenizer_hpp
#define TOkenizer_hpp
#include<vector>
#include<string>
#include<iostream>
#include<stdio.h>

using namespace std;

class Tokenizer{

private:
    vector<string> *tok;

public:
    vector<string> *GetTokens();

};

#endif
