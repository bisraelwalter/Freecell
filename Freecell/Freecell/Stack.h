//**** Brandon Walter ****//
#pragma once
#ifndef  STACK_H
#define  STACK_H
#include "Array.h"
#include "Exception"

template <class T>
class Stack
{
private:
	Array<T> m_stack;
	int m_size;
	int m_position;

public:
	Stack();
	Stack(int size);
	Stack(const Stack<T> & copy);
	Stack &operator=(const Stack<T> & rhs);
	void Push(T data);
	T & Pop();
	T & Peep();
	int Size();
	bool isEmpty();
	bool isFull();
	int getSize() const;
};

template<class T>
inline Stack<T>::Stack()
{
	this->m_size = 0;
	this->m_position = 0;
}

template<class T>
inline Stack<T>::Stack(int size)
{
	this->m_stack.setLength(size);
	this->m_size = size;
	this->m_position = 0;
}

template<class T>
inline Stack<T>::Stack(const Stack<T>& copy)
{
	this->m_stack = copy.m_stack;
	this->m_size = copy.m_size;
	this->m_position = copy.m_position;
}

template<class T>
inline Stack<T> & Stack<T>::operator=(const Stack<T>& rhs)
{ 
	this->m_stack = rhs.m_stack;
	this->m_size = rhs.m_size;
	this->m_position = rhs.m_position;
	return *this;
}

template<class T>
inline void Stack<T>::Push(T data)
{
	if (isFull())
		throw Exception("Stack is full");
	m_position++;
	m_stack[this->m_position - 1] = data;
}

template<class T>
inline T & Stack<T>::Pop()
{
	if (isEmpty())
		throw Exception("Stack is empty");
	m_position--;
	return m_stack[m_position];
}

template<class T>
inline T & Stack<T>::Peep()
{
	if (isEmpty())
		throw Exception("The stack is empty");
	return m_stack[m_position - 1];
}

template<class T>
inline int Stack<T>::Size()
{
	return m_position;
}

template<class T>
inline bool Stack<T>::isEmpty()
{
	if (m_position == 0)
		return true;

	return false;
}

template<class T>
inline bool Stack<T>::isFull()
{
	if (this->m_position >= this->m_size)
		return true;

	return false;
}

template<class T>
inline int Stack<T>::getSize() const
{
	return this->m_size;
}
#endif

