#include "Iterator.h"

template<class T>
Iterator<T>::Iterator(T * p=0):ptr(p)
{
}
/*
template<class T>
Iterator<T>::Iterator(Iterator<T> p)
{
	*this = p;
}*/

template<class T>
Iterator<T>::~Iterator()
{
}

template<class T>
Iterator<T> Iterator<T>::operator+(size_t s) const
{
	Iterator<T> temp;
	temp = *(this + s * sizeof(T));
	return temp;
}

template<class T>
Iterator<T> Iterator<T>::operator-(size_t s) const
{
	Iterator<T> temp;
	temp = *(this - s * sizeof(T));
	return temp;
}

template<class T>
Iterator<T> Iterator<T>::operator++()
{
	Iterator<T> temp;
	temp = *(this + sizeof(T));
	return temp;
}

template<class T>
Iterator<T> Iterator<T>::operator--()
{
	Iterator<T> temp;
	temp = *(this - sizeof(T));
	return temp;
}

template<class T>
T Iterator<T>::operator++(T)
{
	Iterator<T> temp;
	temp = *(this + sizeof(T));
	return T(temp.ptr);
}

template<class T>
T Iterator<T>::operator--(T)
{
	Iterator<T> temp;
	temp = *(this - sizeof(T));
	return T(temp->ptr);
}

template<class T>
Iterator<T> Iterator<T>::operator=(const Iterator<T> q)
{
	this = q;
	Iterator<T>* temp = *this;
	return temp;
}

template<class T>
bool Iterator<T>::operator==(const Iterator<T> q) const
{
	if (this == *p)
		return true;
	return false;
}

template<class T>
bool Iterator<T>::operator!=(const Iterator<T> q) const
{
	if (*this == q)
		return false;
	return true;
}

template<class T>
T & Iterator<T>::operator*()
{
	T x = this->ptr;
	return x;
	// TODO: 在此处插入 return 语句
}
