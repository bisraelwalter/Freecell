//****Brandon Walter*****
#pragma once
#ifndef ARRAY_H
#define ARRAY_H
#include <iostream>
#include "Exception.h"

template <class T>
class Array
{
private:
	T* m_array;
	int m_length;
	int m_start_index;

public:
	Array();
	Array(int length, int start_index = 0);
	Array(const Array& copy);
	~Array();
	Array& operator=(const Array& rhs);
	Array& operator=(const Array& rhs) const;
	T& operator[](int index);
	int getStartIndex() const;
	void setStartIndex(int start_index);
	int getLength() const;
	void setLength(int length);
};


template<class T>
inline Array<T>::Array()
{
	m_start_index = 0;
	m_length = 0;
	m_array = new T[m_length];
}

template<class T>
inline Array<T>::Array(int length, int start_index)
{
	if (length < 1)
		throw Exception("array cannot be less than one");
	this->m_length = length;
	this->m_start_index = start_index;
	this->m_array = new T[length];
}

template<class T>
inline Array<T>::Array(const Array & copy)
{
	this->m_length = copy.m_length;
	this->m_start_index = copy.m_start_index;

	if (copy.m_array)
	{
		this->m_array = new T[this->m_length];

		for (int i = 0; i < this->m_length; i++)
			this->m_array[i] = copy.m_array[i];
	}
}

template<class T>
inline Array<T>::~Array()
{
	delete[] this->m_array;
}

template<class T>
inline Array<T> & Array<T>::operator=(const Array & rhs)
{
	if (this == &rhs)
		return *this;

	delete[] this->m_array;

	this->m_length = rhs.m_length;
	this->m_start_index = rhs.m_start_index;
	this->m_array = new T[rhs.getLength()];

	for (int i = 0; i < this->m_length; i++)
		this->m_array[i] = rhs.m_array[i];

	return *this;
}

template<class T>
inline Array<T> & Array<T>::operator=(const Array & rhs) const
{
	if (this == &rhs)
		return *this;

	delete[] this->m_array;

	this->m_length = rhs.m_length;
	this->m_start_index = rhs.m_start_index;
	this->m_array = new T[rhs.getLength()];

	for (int i = 0; i < this->m_length; i++)
		this->m_array[i] = rhs.m_array[i];

	return *this;
}

template<class T>
inline T & Array<T>::operator[](int index)
{
	if (index < 0 )
		throw Exception("cannot be less than zero");
	if (index > this->m_length - 1)
		throw Exception("cannot be greater than the size of the array");

	return this->m_array[index];
}

template<class T>
inline int Array<T>::getStartIndex() const
{
	return this->m_start_index;
}

template<class T>
inline void Array<T>::setStartIndex(int start_index)
{
	this->m_start_index = start_index;
}

template<class T>
inline int Array<T>::getLength() const
{
	return this->m_length;
}

template<class T>
inline void Array<T>::setLength(int length)
{
	if (length < 1)
	{
		delete[] m_array;
		this->m_array = new T[length];
		this->m_length = length;
	}
	else
	{
		int smallerOfLengths = 0;

		if (length < 0)
			throw Exception("Length cannot be less than zero");

		T* temp = new T[this->m_length];

		for (int i = 0; i < this->m_length; i++)
			temp[i] = this->m_array[i];

		delete[] m_array;
		this->m_array = new T[length];

		if (length > this->m_length)
			smallerOfLengths = this->m_length;
		else
			smallerOfLengths = length;

		for (int i = 0; i < smallerOfLengths; i++)
			this->m_array[i] = temp[i];

		this->m_length = length;
		delete[] temp;
	}
}
#endif





































