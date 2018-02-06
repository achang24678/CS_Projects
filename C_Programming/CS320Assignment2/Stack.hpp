#include<iostream>

using namespace std;

template<class T>
class Stack{

public:

	Stack();	
	void Push(T d);
	void Pop();
	void Print();
    T peak() {
         return indexval[t]; 
    }
	bool empty() { 
        if(size > 0){
            return false;
        }
        else{
            return true;
        }   
    }

private:

	T* indexval;
    int size;
	int t;
};

