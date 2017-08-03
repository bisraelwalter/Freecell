//**** Brandon Walter ****//
#pragma once
#ifndef STACKLL_H
#define	STACKLL_H
#include "DoubleLinkedList.h"

template <class T>
class StackLL
{
private:
	DoubleLinkedList<T> m_stack;
	int m_stacknumber;

public:
	StackLL();
	StackLL(const StackLL & copy);
	StackLL &operator=(const StackLL & rhs);
	void Push(T data);
	T Pop();
	T Peek();
	int Size();
	bool isEmpty();
	Node<T>* getHead();
	void setStackNumber(int number);
	int getStackNumber() const;
};






#endif

template<class T>
inline StackLL<T>::StackLL()
{
}

template<class T>
inline StackLL<T>::StackLL(const StackLL & copy)
{
	this->m_stack = copy.m_stack;
}

template<class T>
inline StackLL<T> & StackLL<T>::operator=(const StackLL & rhs)
{
	this->m_stack = rhs.m_stack;
	return *this;
}

template<class T>
inline void StackLL<T>::Push(T data)
{
	this->m_stack.Append(data);
}

template<class T>
inline T StackLL<T>::Pop()
{
	T data = this->m_stack.Last();
	this->m_stack.RemoveTailNode();
	return data;
}

template<class T>
inline T StackLL<T>::Peek()
{
	return this->m_stack.Last();
}

template<class T>
inline int StackLL<T>::Size()
{
	return this->m_stack.getNodeCount();
}

template<class T>
inline bool StackLL<T>::isEmpty()
{
	return this->m_stack.isEmpty();
}

template<class T>
inline Node<T>* StackLL<T>::getHead()
{
	return this->m_stack.getHead();
}

template<class T>
inline void StackLL<T>::setStackNumber(int number)
{
	this->m_stacknumber = number;
}

template<class T>
inline int StackLL<T>::getStackNumber() const
{
	return this->m_stacknumber;
}
