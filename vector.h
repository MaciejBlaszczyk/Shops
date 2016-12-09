#ifndef WEKTOR
#define WEKTOR

#include<stdexcept>
#include<exception>
#include<iostream>
#include<fstream>

using namespace std;

template <typename type, typename container>
class Iterator;

template <typename type>
class Vector
{
public:
	Vector(int capacity_of_vector = 5);
	Vector(const Vector &specimen);
	virtual ~Vector() { delete []vector_pointer; }

	void insert_element(type element, int position);
	void delete_element(int position);
	void empty_vector() { vector_size = 0; }
	int get_size() { return vector_size; }
	void push_last(type element) { insert_element(element, vector_size); }
	void pop_last() { delete_element(vector_size - 1); }

	type &operator[](int position) const;
    Vector &operator=(const Vector &specimen);

    Iterator<type, Vector<type>> Begin() { return Iterator<type, Vector<type>>(*this); }
	Iterator<type, Vector<type>> End() { return Iterator<type, Vector<type>>(*this) + vector_size; }

private:
	type *vector_pointer;
	int vector_size;
	int vector_capacity;
	void change_size();
};


template <typename type>
Vector <type>::Vector(int capacity_of_vector): vector_size(0), vector_capacity(capacity_of_vector)
{
	vector_pointer = new type[vector_capacity];
}

template <typename type>
Vector <type>::Vector(const Vector <type> &specimen)
{
	vector_size = specimen.vector_size;
	vector_capacity = specimen.vector_capacity;
	vector_pointer = new type[vector_capacity];
	for(int i = 0; i < vector_size; i++)
		*(vector_pointer + i) = *(specimen.vector_pointer + i);
}

template <typename type>
void Vector <type>::change_size()
{
	vector_capacity += 5;
	type *temp = new type[vector_capacity];
	for(int i = 0; i < vector_size; i++)
		*(temp + i) = *(vector_pointer + i)  ;
	delete []vector_pointer;
	vector_pointer = temp;
}

template <typename type>
void Vector <type>::insert_element(type element, int position)
{
	if(position > vector_size)
		throw out_of_range("Inserting out of size");

	if(vector_size >= vector_capacity - 1) // -1 because one free place in the back should be alwyas free
		change_size();

	type *temp = new type[vector_capacity];
	for(int i = 0; i < position; i++)
		*(temp + i) = *(vector_pointer + i);
	temp[position] = element;
	for(int i = position + 1; i < vector_size; i++)
		*(temp + i) = *(vector_pointer + i);
	delete []vector_pointer;
	vector_pointer = temp;
	vector_size++;
}

template <typename type>
void Vector <type>::delete_element(int position)
{
	for(int i = position; i < vector_size; i++)
		*(vector_pointer + i) = *(vector_pointer + i + 1);
	vector_size--;
}

template <typename type>
type &Vector <type>::operator[](int position) const
{
	if(position > vector_size)
		throw out_of_range("Operation out of size");
	return vector_pointer[position];
}

template <typename type>
Vector <type> &Vector <type>::operator=(const Vector <type> &specimen)
{
	if(vector_pointer == specimen.vector_pointer)
		return *this;

	delete []vector_pointer;
	vector_pointer = new type[specimen.vector_capacity];
	for(int i = 0; i < specimen.vector_size; i++)
		vector_pointer[i] = specimen.vector_pointer[i];
	vector_size = specimen.vector_size;
	vector_capacity = specimen.vector_capacity;

	return *this ;
}

#endif
