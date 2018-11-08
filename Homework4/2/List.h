#pragma once
#include<iostream>

//using namespace std; you can't use this sentence here, cause already
//have a "vector" in namespace std.

template<class T>
struct _List_node{
	_List_node<T>* prev;
	_List_node<T>* next;
	T data;
	//像class一样书写，可以使用new来初始化
	_List_node(){
		prev = nullptr;
		next = nullptr;
	}
};

template<class T>
struct _List_iterator{
	_List_node<T>* _p_node;
	int d;
	_List_iterator(_List_node<T>* x):_p_node(x){
	}
	~_List_iterator(){
	}

	_List_iterator<T>& operator =(const _List_iterator<T>& it){
		if(this == &it) return *this;
		_p_node = it._p_node;
		return *this;
	}

	bool operator == (const _List_iterator<T> &q){
		if(_p_node == q._p_node) return true;
		else return false;
	}
	bool operator != (const _List_iterator<T> &q){
		return !(*this == q);
	}
	//前置用法
	_List_iterator<T>& operator ++ (){
		_p_node = _p_node->next; //you cannot use _p_node++ to repalce
		return *this;
	}
	_List_iterator<T>& operator -- (){
		_p_node = _p_node->prev;
		return *this;
	}
	//后置用法
	// const in the tail, means readonly
	const _List_iterator<T> operator ++ (int){
		_List_iterator<T> temp(_p_node);
		_p_node = _p_node->next;
		return temp;
	}
	const _List_iterator<T> operator -- (int){
		_List_iterator<T> temp(_p_node);
		_p_node = _p_node->prev;
		return temp;
	}
	T operator * (){
		return _p_node->data;
	}
};

template <class T>
class List{
public:
	typedef _List_node<T> link_type;
	typedef _List_iterator<T> iterator;

	List(){
		node = new link_type();
		size = 0;
	}
	~List(){
		while(!empty()){
			erase(begin());	
		}
		delete node;
		node = nullptr;
		size = 0;
	}

	bool empty(){
		//other way??
		if(size == 0)return true;
		else return false;
	}
	iterator begin(){
		iterator it(node);
		if(size) it++;
		return it;
	}
	iterator end(){
		iterator it(node);
		return it;
	}
	iterator insert(iterator it, T e){
		link_type* temp = new link_type();
		temp->data = e;
		if(empty()){	//question
			temp->next = it._p_node;
			it._p_node->next = temp;
			temp->prev = it._p_node;
			it._p_node->prev = temp;
		}
		else{
			iterator pre(it._p_node->prev);
			pre._p_node->next = temp;
			temp->prev = pre._p_node;
			temp->next = it._p_node;
			it._p_node->prev = temp;
		}
		iterator ret(temp);
		size++;
		return ret;
	}

	iterator erase(iterator it){
		if(empty())return it;
		if(it == end()) return it;
		iterator p(it._p_node->prev);
		iterator q(it._p_node->next);
		p._p_node->next = q._p_node;
		q._p_node->prev = p._p_node;
		delete it._p_node;
		size--;
		return q;
	}

private:
	link_type * node;
	int size;
};