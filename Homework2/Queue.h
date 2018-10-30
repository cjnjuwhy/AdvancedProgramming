/*
 * Queue.h
 *
 *  Created on: 2018Äê9ÔÂ24ÈÕ
 *      Author: why
 */

#ifndef QUEUE_H_
#define QUEUE_H_
#include<iostream>
using namespace std;

template<class T>
struct queueNode{
	T data;
	queueNode* next = nullptr ;
};


template <class T>
class Queue{
private:
	queueNode<T> *head;
	queueNode<T> *tail;
	unsigned int count;

public:
	Queue(){
		count = 0;
		queueNode<T>* p = new queueNode<T>;
		head = p;
		//**************//
		tail = head;
	}
	~Queue(){
		while(!isEmpty()){
			pop();
		}
		tail = head;
	}
	void push(T e);
	T pop();
	T back();
	T front();
	bool isEmpty();
	size_t size();
	void show();
};

template<class T>
void Queue<T>::push(T e){
	queueNode<T> *p = new queueNode<T>;
	p->data = e;
	tail->next = p;
	tail = p;
	count++;
}

template<class T>
T Queue<T>::pop(){
	if(isEmpty())
		cerr << "Error!" << endl;

	T ans = head->next->data;
	queueNode<T> *p = head->next;
	head->next = p->next;
	delete p;
	count--;
	return ans;
}

template<class T>
T Queue<T>::back(){
	return tail->data;
}

template<class T>
T Queue<T>::front(){
	return head->next->data;
}

template<class T>
bool Queue<T>::isEmpty(){
	if(count==0)
		return true;
	return false;
}

template<class T>
size_t Queue<T>::size(){
	return count;
}

template<class T>
void Queue<T>::show(){
	queueNode<T>* p = head->next;
	int t = count;
	while(t!=0){
		cout << p->data;
		t--;
		if(p->next != nullptr)
			cout<<" ";
		p = p->next;
	}
	cout << endl;
}

#endif /* QUEUE_H_ */
