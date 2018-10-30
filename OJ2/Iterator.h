#pragma once
template<class T>
class Iterator
{
private:
	T *ptr;
public:
	Iterator(T *p);
	//Iterator(Iterator<T> p);
	~Iterator();

	Iterator<T> operator + (size_t s)const;
	Iterator<T> operator - (size_t s)const;
	Iterator<T> operator ++ ();
	Iterator<T> operator -- ();
	T operator ++ (T);
	T operator -- (T);
	Iterator<T> operator = (const Iterator<T> q);
	bool operator == (const Iterator<T> q)const;
	bool operator != (const Iterator<T> q)const;
	T& operator *();

};
