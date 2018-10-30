#pragma once
#include<iostream>
#include<cstdlib>
using namespace std;

template<class T>
class Vector {
public: typedef T* iterator;
private:
	iterator start;
	size_t m_size;
	size_t m_capcity;

public:
	//	typedef T* iterator;
	Vector(size_t c) {
		start = new T[c];
		m_capcity = c;
		m_size = 0;
	}
	~Vector() {
		delete[]start;
		start = nullptr;
		m_size = 0;
		m_capcity = 0;
	}

	void push_back(T e) {
		*end() = e;
		m_size++;
	}

	size_t size() {
		return m_size;
	}

	iterator begin() {
		return start;
	}

	iterator end() {
		return (start + m_size);
	}

	iterator insert(iterator it, T e) {
		iterator temp = end();
		while (temp != it && temp!=start) {
			*(temp) = *(temp-1);
			temp--;
		}
		*it = e;
		m_size++;
		return it;
	}

	iterator erase(iterator it) {
		iterator temp = it;
		while (temp != end()-1) {
			*(temp) = *(temp + 1);
			temp++;
		}
		m_size--;
		return it;
	}

	T& operator [] (int m) {
		return *(start + m);
	}

};