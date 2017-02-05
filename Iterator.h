#ifndef ITERATOR
#define ITERATOR

#include "vector.h"

template <typename T, typename container>
class Iterator
{
public:
	Iterator(container &data);

	T& operator*();
	bool operator==(const Iterator& it);
	bool operator!=(const Iterator& it);
	Iterator& operator++();
	Iterator& operator++(int);
	Iterator& operator--();
	Iterator& operator--(int) ;
	Iterator& operator+(int add);
	Iterator& operator-(int sub);
	Iterator& operator=(const Iterator& source);

private:
	container *dataPointer;
	int position;
};

template <typename T, typename container>
Iterator<T,container>:: Iterator(container &data) : position(0)
{
	dataPointer = &data;
}

template <typename T, typename container>
T& Iterator<T, container>:: operator*()
{
	return (*dataPointer)[position];
}

template <typename T, typename container>
bool Iterator<T, container>:: operator==(const Iterator<T, container> &it)
{
	return (dataPointer == it.dataPointer && position == it.position) ? true : false;
}

template <typename T, typename container>
bool Iterator<T, container>:: operator!=(const Iterator<T, container> &it)
{
	return !(*this == it);
}

template <typename T, typename container>
Iterator<T, container>& Iterator<T, container>:: operator++()
{
	if(position >= (*dataPointer).getSize())
		throw out_of_range("Operation++ out of size");
	position++;
	return *this;
}

template <typename T, typename container>
Iterator<T, container>& Iterator<T, container>:: operator++(int)
{
	if(position >= (*dataPointer).getSize())
		throw out_of_range("Operation++ out of size");
	position++;
	return *this;
}

template <typename T, typename container>
Iterator<T, container>& Iterator<T, container>:: operator--()
{
	if(position == 0)
		throw out_of_range("Operation-- out of size");
	position--;
	return *this;
}

template <typename T, typename container>
Iterator<T, container>& Iterator<T, container>:: operator--(int)
{
	if(position == 0)
		throw out_of_range("Operation-- out of size");
	position--;
	return *this;
}

template <typename T, typename container>
Iterator<T, container>& Iterator<T, container>:: operator+(int add)
{
	if(position + add > (*dataPointer).getSize())
		throw out_of_range("Operation+ out of size");
	position += add;
	return *this;
}

template <typename T, typename container>
Iterator<T, container>& Iterator<T, container>:: operator-(int sub)
{
	if(position - sub < 0)
		throw out_of_range("Operation- out of size");
	position -= sub;
	return *this;
}

template <typename T, typename container>
Iterator<T, container>& Iterator<T, container>:: operator=(const Iterator& source)
{
	dataPointer = source.dataPointer;
	position = source.position;
	return *this;
}

#endif // ITERATOR
