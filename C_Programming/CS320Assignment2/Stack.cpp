#include <iostream>
#include "Stack.hpp"

template<class T>
Stack<T>::Stack(){
    size = 0;
	t = -1;
	indexval = new T[10];
}

template<class T>
void Stack<T>::Push(T d)
{
	

	t++;
	indexval[t] = d;
	size++;
}

template<class T>
void Stack<T>::Pop()
{
	if (size <= 0){
		
		return;
	}
	else{

		t--;
		size--;
	}
}

template<class T>
void Stack<T>::Print()
{
	Stack<T> stack;
	while (Stack<T>::empty() == false)
	{
		stack.Push(Stack<T>::peak());
		Stack<T>::Pop();
	}

	cout << "[ ";
	while (stack.empty() == false){

		cout << stack.peak() << " ";
		stack.Pop();
	}
	cout << "]" << endl;

}
template class Stack<int>;
