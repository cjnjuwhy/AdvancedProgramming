#pragma once
struct stackNode {
	char data;
	stackNode* next;
};

class Stack
{
private:
	stackNode *top;
public:
	Stack();
	Stack(const stackNode *node);
	~Stack();

	void push(char data);
	char pop();
	char stackTop();
	bool isEmpty();
	void show();
};

