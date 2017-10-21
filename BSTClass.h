#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <iostream>
#include "BST_NodeClass.h"
using namespace std;

template <class T>
class BST
{
private:
	BSTNode<T> *root;
	void insert(BSTNode<T> *& nodePtr, BSTNode<T> *& newNode);
	void destroyTree(BSTNode<T> *nodePtr);
	void deleteNode(T&, BSTNode<T> *&nodePtr);
	void makeDeletion(BSTNode<T> *& nodePtr);
	void displayInOrder(BSTNode<T> *nodePtr) const;
	void displayPreOrder(BSTNode<T> *nodePtr) const;
	void displayPostOrder(BSTNode<T> *nodePtr, ofstream &outFile) const;
public:
	BST();
	~BST();
	void insertNode(T& item);
	bool searchNode(T& item);
	T searchNode1(T& item);
	void remove(T& item);
	void displayInOrder() const;
	void displayPerOrder() const;
	void displayPostOrder(ofstream &outFile);
};

template<class T>
BST<T>::BST()
{
	root = NULL;
}

template<class T>
BST<T>::~BST()
{
	destroyTree(root);
}

template <class T>
void BST<T>::insert(BSTNode<T> *&nodePtr, BSTNode<T> *&newNode)
{
	if (nodePtr == NULL)
		nodePtr = newNode;							// insert the node
	else if (newNode->getData() < nodePtr->getData())
		insert(nodePtr->getLeft(), newNode);				// Search the left branch
	else
		insert(nodePtr->getRight(), newNode);			// Search the right branch
}

template <class T>
void BST<T>::insertNode(T& item)
{
	BSTNode<T> *newNode;

	newNode = new BSTNode<T>;
	newNode->setData(item);
	newNode->setLeft(NULL);
	newNode->setRight(NULL);

	insert(root, newNode);
}

template <class T>
void BST<T>::destroyTree(BSTNode<T> *nodePtr)
{
	if (nodePtr)
	{
		if (nodePtr->getLeft())
			destroyTree(nodePtr->getLeft());
		if (nodePtr->getRight())
			destroyTree(nodePtr->getRight());
		delete nodePtr;
	}
}

template <class T>
bool BST<T>::searchNode(T& item)
{
	BSTNode<T> *nodePtr;
	nodePtr = root;
	while (nodePtr)
	{
		if (nodePtr->getData() == item)
			return true;
		else if (item < nodePtr->getData())
			nodePtr = nodePtr->getLeft();
		else
			nodePtr = nodePtr->getRight();
	}
	return false;
}

template <class T>
T BST<T>::searchNode1(T& item)
{
	BSTNode<T> *nodePtr;
	nodePtr = root;
	while (nodePtr)
	{
		if (nodePtr->getData() == item)
			return nodePtr->getData();
		else if (item < nodePtr->getData())
			nodePtr = nodePtr->getLeft();
		else
			nodePtr = nodePtr->getRight();
	}
	return item;
}

template <class T>
void BST<T>::remove(T& item)
{
	deleteNode(item, root);
}

template <class T>
void BST<T>::deleteNode(T& item, BSTNode<T> *&nodePtr)
{
	if (item < nodePtr->getData())
		deleteNode(item, nodePtr->getLeft());
	else if (item > nodePtr->getData())
		deleteNode(item, nodePtr->getRight());
	else
		makeDeletion(nodePtr);
}

template <class T>
void BST<T>::makeDeletion(BSTNode<T> *&nodePtr)
{
	BSTNode<T> *temp;

	if (nodePtr == NULL)
		cout << "Cannot delete empty node.\n";
	else if (nodePtr->getRight() == NULL)
	{
		temp = nodePtr;
		nodePtr = nodePtr->getLeft();
		delete temp;
	}
	else if (nodePtr->getLeft() == NULL)
	{
		temp = nodePtr;
		nodePtr = nodePtr->getRight();
		delete temp;
	}
	// if node has two children
	else
	{
		temp = nodePtr->getRight();

		while (temp->getLeft())
			temp = temp->getLeft();
		temp->setLeft(nodePtr->getLeft()); //
		temp = nodePtr;

		nodePtr = nodePtr->getRight();
		delete temp;
	}
}

template <class T>
void BST<T>::displayInOrder(BSTNode<T> *nodePtr) const
{
	if (nodePtr)
	{
		displayInOrder(nodePtr->getLeft());
		cout << nodePtr->getData() << endl;
		displayInOrder(nodePtr->getRight());
	}
}

template <class T>
void BST<T>::displayPreOrder(BSTNode<T> *nodePtr) const
{
	if (nodePtr)
	{
		nodePtr->getData().printData();
		cout << endl;
		displayPreOrder(nodePtr->getLeft());
		displayPreOrder(nodePtr->getRight());
	}
}

template <class T>
void BST<T>::displayPostOrder(BSTNode<T> *nodePtr, ofstream &outFile) const
{
	if (nodePtr)
	{
		displayPostOrder(nodePtr->getLeft(),outFile);
		displayPostOrder(nodePtr->getRight(),outFile);
		nodePtr->getData().printOutFile(outFile);
	}
}

template <class T>
void BST<T>::displayInOrder() const
{
	displayInOrder(root);
}

template <class T>
void BST<T>::displayPerOrder() const
{
	displayPreOrder(root);
}

template <class T>
void BST<T>::displayPostOrder(ofstream &outFile) 
{
	displayPostOrder(root, outFile);
}

#endif