#ifndef VECTOR
#define VECTOR
#include<iostream>
#include<stdexcept>

using namespace std;

template <typename T, typename container>
class Iterator;

template <typename T>
class Vector
{
public:
	Vector(int vectorCapacity = 5);
	Vector(const Vector &specimen);
	virtual ~Vector() { delete []vectorPointer; }

	void insert(T element, int position);
	void remove(int position);
	void clear() { size = 0; }
	int getSize() { return size; }
	void pushBack(T element) { insert(element, size); }
	void popBack() { remove(size - 1); }

	T &operator[](int position) const;
    Vector &operator=(const Vector &specimen);

    //typedef class Iterator<T> iterator;
    Iterator<T, Vector<T>> Begin() { return Iterator<T, Vector<T>>(*this); }
	Iterator<T, Vector<T>> End() { return Iterator<T, Vector<T>>(*this) + size; }

private:
	T *vectorPointer;
	int size;
	int capacity;
	void changeSize();
};


template <typename T>
Vector<T>:: Vector(int vectorCapacity): size(0), capacity(vectorCapacity)
{
	vectorPointer = new T[capacity];
}

template <typename T>
Vector<T>:: Vector(const Vector <T> &specimen)
{
	size = specimen.size;
	capacity = specimen.capacity;
	vectorPointer = new T[capacity];
	for(int i = 0; i < size; i++)
		*(vectorPointer + i) = *(specimen.vectorPointer + i);
}

template <typename T>
void Vector<T>:: changeSize()
{
	capacity += 5;
	T *temp = new T[capacity];
	for(int i = 0; i < size; i++)
		*(temp + i) = *(vectorPointer + i)  ;
	delete []vectorPointer;
	vectorPointer = temp;
}

template <typename T>
void Vector<T>:: insert(T element, int position)
{
	if(position > size)
		throw out_of_range("Inserting out of size");

	if(size >= capacity - 1) // -1 because one free place in the back should be alwyas free
		changeSize();

	T *temp = new T[capacity];
	for(int i = 0; i < position; i++)
		*(temp + i) = *(vectorPointer + i);
	temp[position] = element;
	for(int i = position + 1; i < size; i++)
		*(temp + i) = *(vectorPointer + i);
	delete []vectorPointer;
	vectorPointer = temp;
	size++;
}

template <typename T>
void Vector<T>:: remove(int position)
{
	for(int i = position; i < size; i++)
		*(vectorPointer + i) = *(vectorPointer + i + 1);
	size--;
}

template <typename T>
T &Vector<T>:: operator[](int position) const
{
	if(position > size)
		throw out_of_range("Operation out of size");
	return vectorPointer[position];
}

template <typename T>
Vector<T> &Vector<T>:: operator=(const Vector <T> &specimen)
{
	if(vectorPointer == specimen.vectorPointer)
		return *this;

	delete []vectorPointer;
	vectorPointer = new T[specimen.capacity];
	for(int i = 0; i < specimen.size; i++)
		vectorPointer[i] = specimen.vectorPointer[i];
	size = specimen.size;
	capacity = specimen.capacity;

	return *this ;
}

#endif
