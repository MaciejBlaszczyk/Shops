#ifndef ITERATOR
#define ITERATOR

#include "vector.h"

template <typename type, typename container>
class Iterator
{
public:
	Iterator(container &data) : position(0) { data_pointer = &data; }

	type& operator*() { return (*data_pointer)[position]; }
	bool operator==(const Iterator& it) { return (data_pointer == it.data_pointer && position == it.position) ? true : false; }
	bool operator!=(const Iterator& it) { return !(*this == it); }
	Iterator& operator++()
	{
		if(position >= (*data_pointer).get_size())
			throw out_of_range("Operation++ out of size");
		position++;
		return *this;
	}

	Iterator& operator++(int)
	{
		if(position >= (*data_pointer).get_size())
			throw out_of_range("Operation++ out of size");
		position++;
		return *this;
	}

	Iterator& operator--()
	{
		if(position == 0)
			throw out_of_range("Operation-- out of size");
		position--;
		return *this;
	}

	Iterator& operator--(int)
	{
		if(position == 0)
			throw out_of_range("Operation-- out of size");
		position--;
		return *this;
	}

	Iterator& operator+(int add)
	{
		if(position + add > (*data_pointer).get_size())
			throw out_of_range("Operation+ out of size");
		position += add;
		return *this;
	}

	Iterator& operator-(int sub)
	{
		if(position - sub < 0)
			throw out_of_range("Operation- out of size");
		position -= sub;
		return *this;
	}

	Iterator& operator=(const Iterator& source)
	{
		data_pointer = source.data_pointer;
		position = source.position;
		return *this;
	}

private:
	container *data_pointer;
	int position;
};

#endif // ITERATOR
