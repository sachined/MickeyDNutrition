#ifndef NODE_H_INCLUDED 
#define NODE_H_INCLUDED
#include<iostream>
#include<string>
#include "Food.h"
using namespace std;

template<class T>
class Node
{
private:
	T data;
	Node<T>* next;
public:

	Node(); //Default Constructor
	Node(Node& obj); // Copy constructor

	void setData(T& userData); // Set the data
	void setNext(Node<T>* nextNode); //get the Next Data

	T getData() const; // get Data
	Node<T>* getNext(); // get Next

};


template <class T>
Node<T>::Node()
{
	setNext(0);
}

template <class T>
Node<T>::Node(Node& obj)
{
	data = obj.data;
	next = obj.next;
}

template <class T>
void Node<T>::setData(T& userData)
{
	data = userData;
}

template <class T>
void Node<T>::setNext(Node<T>* nextNode)
{
	next = nextNode;
}

template <class T>
T Node<T>::getData() const
{
	return data;
}

template <class T>
Node<T>* Node<T>::getNext()
{
	return next;
}



#endif