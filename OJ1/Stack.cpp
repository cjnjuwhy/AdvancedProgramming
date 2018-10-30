#include "Stack.h"
#include<iostream>
using namespace std;


Stack::Stack()
{
	top = nullptr;
}

Stack::~Stack()
{
}

void Stack::push(char data)
{
	stackNode *temp = new stackNode;
	temp->data = data;
	temp->next = top;
	top = temp;
	//delete temp;
}

char Stack::pop()
{
	char temp = top->data;
	top = top->next;
	return temp;
}

char Stack::stackTop()
{
	return top->data;
}

bool Stack::isEmpty()
{
	if (top == nullptr)
		return true;
	return false;
}

void Stack::show()
{
	Stack temp;
	temp.top = top;
	while (!temp.isEmpty()) {
		cout << temp.pop();
		cout << endl;
	}
}