#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED
#include "Food.h"
#include "Node.h"
#include<iostream>
#include<string>
using namespace std;

template <class T>
class LinkedList
{
private:
	Node<T> *head;
	Node<T> *tail;
	int count;
	bool used = false;
public:
	
	LinkedList<T>(); //Default Constructor
	~LinkedList<T>(); //Deconstructor which will delete every node

	Node<T>* getFront(void) const;
	Node<T>* getRear(void) const;

	void setUsed(bool use);
	bool getUsed();
	bool find(T value);
	int countNode();

	void printDatas();
	void insertAnywhere(Food value); // insert the new Node anywhere
	void deleteNode(Food value); // Delete a node anywhere
	void displays() const; //This will display the linked list from head to tail
	
	bool isEmpty() const; // Check if the Linked List is empty
	bool clearList(); // Removes every single Node if there are still any nodes left

};

template <class T>
LinkedList<T>::LinkedList()
{
	head = NULL;
	tail = NULL;
	count = 0;
}

template <class T>
LinkedList<T>::~LinkedList()
{
	clearList();
}

template<class T>
void LinkedList<T>::setUsed(bool use)
{
	used = use;
}

template<class T>
bool LinkedList<T>::getUsed()
{
	return used;
}
template <class T>
Node<T>* LinkedList<T>::getFront(void) const
{
	return head;
}

template <class T>
Node<T>* LinkedList<T>::getRear(void) const
{
	return tail;
}

template <class T>
void LinkedList<T>::insertAnywhere(Food value)
{	
	Node<T>*newNode;
	Node<T>* nodePtr;
	Node<T>*previousNode = NULL;
	newNode = new Node<T>;
	newNode->setData(value);
	if (head == NULL)
	{
		head = newNode;
		newNode->setNext(NULL);
		count++;
	}
	else
	{
		nodePtr = head;
		previousNode = NULL;
		while (nodePtr != NULL && nodePtr->getData() < value)
		{
			previousNode = nodePtr;
			nodePtr = nodePtr->getNext();
		}
		if (!previousNode)
		{
			head = newNode;
			newNode->setNext(nodePtr);
			count++;
		}
		else
		{
			previousNode->setNext(newNode);
			newNode->setNext(nodePtr);
			count++;
		}
	}
	
}


template <class T>
void LinkedList<T>::deleteNode(Food value)
{
	Node<T> *nodePtr;
	Node<T> *previousNode = NULL;
	if (!head)
	{
		return;
	}
	if (head->getData() == value)
	{
		nodePtr = head->getNext();
		delete head;
		count--;
		head = nodePtr;
	}
	else
	{
		nodePtr = head;
		while (nodePtr->getNext() != NULL && nodePtr->getData() != value)
		{
			previousNode = nodePtr;
			nodePtr = nodePtr->getNext();
		}

		if (nodePtr)
		{
			previousNode->setNext(nodePtr->getNext());
			delete nodePtr;
			count--;
		}
	}
}

template <class T>
void LinkedList<T>::displays() const
{
	Node<T>* newNode = head;
	if (!isEmpty())
	{
		while (newNode->getNext() != NULL)
		{
			cout << newNode->getData() << " --> ";
			newNode = newNode->getNext();
		}
		cout << newNode->getData();
	}
}


template <class T>
bool LinkedList<T>::isEmpty() const
{
	if (count == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}


template <class T>
bool LinkedList<T>::clearList()
{
	if (!isEmpty())
	{
		Node<T> *nodePtr;
		Node<T> *nextNode;

		nodePtr = head;

		while (nodePtr->getNext() != NULL)
		{
			nextNode = nodePtr->getNext();
			delete nodePtr;
			nodePtr = nextNode;
			count--;
		}
		return true;
	}
	return false;
}

template <class T>
int LinkedList<T>::countNode()
{
	Node<T> *nodePtr;
	int counts = 0;
	nodePtr = head;
		while (nodePtr != NULL)
		{
			counts++;
			nodePtr = nodePtr->getNext();
		}
	return count;
}

template <class T>
bool LinkedList<T>::find(T value)
{
	Node<T> * nodePtr;
	nodePtr = head;
	
	while (nodePtr != NULL)
	{
		if (nodePtr->getData() == value)
		{
			return true;
		}
		nodePtr = nodePtr->getNext();
	}
	return false;
}

template <class T>
void LinkedList<T>::printDatas()
{
	Node<T> *nodePtr;
	if (!head)
	{
		cout << "No foods" << endl;
	}
	else
	{
		nodePtr = head;
		while (nodePtr != NULL)
		{
			nodePtr->getData().printData();
			nodePtr = nodePtr->getNext();
		}
	}
}

#endif // !1