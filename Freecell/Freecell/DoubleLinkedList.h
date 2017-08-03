//**** Brandon Walter ****//
#pragma once
#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H
#include "Node.h"
#include "Exception.h"
#include <iostream>
#include "Deck.h"

template <class T>
class DoubleLinkedList
{
private:
	Node<T>* head;
	Node<T>* tail;
	int m_nodeCount = 0;

public:
	DoubleLinkedList();
	DoubleLinkedList(const DoubleLinkedList& copy);
	~DoubleLinkedList();
	DoubleLinkedList& operator=(const DoubleLinkedList& rhs);
	DoubleLinkedList& operator=(const DoubleLinkedList& rhs) const;
	bool isEmpty();
	void Prepend(T data);
	void Append(T data);
	T & First() const;
	T & Last();
	T & Last()const;
	Node<T> * getHead() const;
	Node<T> * getTail() const;
	void Purge();
	void Extract(T data);
	void RemoveTailNode();
	void InsertAfter(T data, T after);
	void InsertBefore(T data, T before);
	void PrintForwards();
	void PrintBackwards();
	int getNodeCount();
	friend std::ostream & operator<<(std::ostream & out, const Deck::Card & course);
};

template<class T>
inline DoubleLinkedList<T>::DoubleLinkedList()
{
	head = nullptr;
	tail = nullptr;
}

template<class T>
inline DoubleLinkedList<T>::DoubleLinkedList(const DoubleLinkedList & copy)
{
	head = tail = nullptr;
	Node<T> * temp = copy.head;

	while (temp)
	{
		this->Append(temp->getData());
		temp = temp->getNext();
	}
	m_nodeCount = copy.m_nodeCount;
}

template<class T>
inline DoubleLinkedList<T>::~DoubleLinkedList()
{
	while (head)
	{
		Node<T> * temp = head->getNext();

		delete head;
		head = nullptr;
		head = temp;
	}
	tail = nullptr;
	head = nullptr;
}

template<class T>
inline DoubleLinkedList<T> & DoubleLinkedList<T>::operator=(const DoubleLinkedList & rhs)
{
	head = tail = nullptr;
	Node<T> * temp = rhs.head;
	this->m_nodeCount = 0;
	while (temp)
	{
		this->Append(temp->getData());
		temp = temp->getNext();
	}
	return *this;
}

template<class T>
inline DoubleLinkedList<T> & DoubleLinkedList<T>::operator=(const DoubleLinkedList & rhs) const
{
	head = tail = nullptr;
	Node<T> * temp = rhs.head;
	this->m_nodeCount = 0;
	while (temp)
	{
		this->Append(temp->getData());
		temp = temp->getNext();
	}
	return *this;
}

template<class T>
inline bool DoubleLinkedList<T>::isEmpty()
{
	return head == nullptr;
}

template<class T>
inline void DoubleLinkedList<T>::Prepend(T data)
{
	if (head == nullptr)
	{
		Node<T> * theNewNode = new Node<T>;
		theNewNode->setData(data);
		tail = theNewNode;
		head = theNewNode;
		m_nodeCount++;
	}
	else
	{
		Node<T> * theNewNode = new Node<T>;
		theNewNode->setData(data);
		theNewNode->setNext(head);
		head->setPrevious(theNewNode);
		head = theNewNode;
		m_nodeCount++;
	}
}

template<class T>
inline void DoubleLinkedList<T>::Append(T data)
{
	if (head == nullptr)
	{
		Node<T> * theNewNode = new Node<T>;
		theNewNode->setData(data);
		tail = theNewNode;
		head = theNewNode;
		m_nodeCount++;
	}
	else
	{
		Node<T> * theNewNode = new Node<T>;
		theNewNode->setData(data);
		theNewNode->setPrevious(tail);
		tail->setNext(theNewNode);
		tail = theNewNode;
		m_nodeCount++;
	}
}

template<class T>
inline T & DoubleLinkedList<T>::First() const
{
	if (head == nullptr)
		throw Exception("List is empty");

	return head->getData();
}

template<class T>
inline T & DoubleLinkedList<T>::Last()
{
	if (tail == nullptr)
		throw Exception("List is emtpy");

	return tail->getData();
}

template<class T>
inline T & DoubleLinkedList<T>::Last() const
{
	if (tail == nullptr)
		throw Exception("List is emtpy");

	return tail->getData();
}

template<class T>
inline Node<T>* DoubleLinkedList<T>::getHead() const
{
	return head;
}

template<class T>
inline Node<T>* DoubleLinkedList<T>::getTail() const
{
	return tail;
}

template<class T>
inline void DoubleLinkedList<T>::Purge()
{
	if (head != nullptr)
	{
		while (head)
		{
			Node<T> * temp = head->getNext();

			delete head;
			head = nullptr;
			head = temp;
		}
		tail = nullptr;
		head = nullptr;
		m_nodeCount = 0;
	}
}

template<class T>
inline void DoubleLinkedList<T>::Extract(T data)
{
	if (this->m_nodeCount == 0)
		throw Exception("List is empty");

	if (m_nodeCount == 1)
	{
		delete head;
		head = nullptr;
		tail = nullptr;
	}
	else
	{
		Node<T> * temp = head;
		bool dataMatch = false;

		for (int i = 0; i < m_nodeCount; i++)
		{
			if (temp->getData() == data)
			{
				dataMatch = true;
				i = m_nodeCount;
			}
			temp = temp->getNext();
		}
		if (!dataMatch)
			throw Exception("Data does not exist in list");

		if (temp == nullptr)
		{
			tail = temp->getPrevious();
			temp->setPreviousToNull(temp);
			temp->eraseNodePrevious();
			delete temp;
			temp = nullptr;
			m_nodeCount--;
		}
		else
		{
			if (temp->getPrevious() == nullptr)
			{
				head = temp->getNext();
				temp->setNextToNull(temp);
				temp->eraseNodeNext();
				delete temp;
				temp = nullptr;
				m_nodeCount--;
			}
		}
	}
}

template<class T>
inline void DoubleLinkedList<T>::RemoveTailNode()
{
	Node<T> * temp = tail;
	if (this->m_nodeCount == 1)
	{
		Purge();
	}
	else
	{
		tail = tail->getPrevious();
		temp->setPreviousToNull(temp);
		delete temp;
		temp = nullptr;
		m_nodeCount--;
	}
}

template<class T>
inline void DoubleLinkedList<T>::InsertAfter(T data, T after)
{
	Node<T> * temp = head;

	while (temp->getData() != after)
	{
		temp = temp->getNext();
	}
	if (temp->getNext() == nullptr)
		Append(data);
	else
	{
		Node<T> * NewNode = new Node<T>;
		NewNode->setData(data);
		NewNode->setNext(temp->getNext());
		temp->setNext(NewNode);
		NewNode->setPrevious(temp);
		temp->setPreviousForNewNode(NewNode);
		m_nodeCount++;
	}
}

template<class T>
inline void DoubleLinkedList<T>::InsertBefore(T data, T before)
{
	Node<T> * temp = head;

	while (temp->getData() != before)
	{
		temp = temp->getNext();
	}
	if (temp->getPrevious() == nullptr)
		Prepend(data);
	else
	{
		temp = temp->getPrevious();
		Node<T> * NewNode = new Node<T>;
		NewNode->setData(data);
		NewNode->setNext(temp->getNext());
		temp->setNext(NewNode);
		NewNode->setPrevious(temp);
		temp->setPreviousForNewNode(NewNode);
		m_nodeCount++;
	}
}

template<class T>
inline void DoubleLinkedList<T>::PrintBackwards()
{
	if (tail)
	{
		Node<T> * temp = tail;

		while (temp)
		{
			cout << temp->getData() << endl;
			temp = temp->getPrevious();
		}
	}
	else
		cout << "List is empty" << endl;
}

template<class T>
inline int DoubleLinkedList<T>::getNodeCount()
{
	return this->m_nodeCount;
}

template<class T>
inline void DoubleLinkedList<T>::PrintForwards()
{
	if (head)
	{
		Node<T> * temp = head;

		while (temp)
		{
			cout << temp->getData() << endl;
			temp = temp->getNext();
		}
	}
	else
		cout << "List is empty" << endl;
}
#endif














