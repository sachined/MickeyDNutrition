#ifndef BST_NODECLASS_H
#define BST_NODECLASS_H
#include <iostream>
using namespace std;

template<class ItemType>
class BSTNode
{
private:
	ItemType data;
	BSTNode<ItemType>* left;
	BSTNode<ItemType>* right;

public:
	BSTNode();
	BSTNode(const BSTNode &obj);
	void setData(ItemType &inputData);
	void setLeft(BSTNode<ItemType>* leftNodePtr);
	void setRight(BSTNode<ItemType>* rightNodePtr);
	ItemType getData() const;
	BSTNode<ItemType>*& getLeft();
	BSTNode<ItemType>*& getRight();

};
template<class ItemType>
BSTNode<ItemType>::BSTNode()
{
	setLeft(NULL);
	setRight(NULL);
}

template<class ItemType>
BSTNode<ItemType>::BSTNode(const BSTNode &obj)
{
	data = obj.data;
	left = obj.left;
	right = obj.right;
}

template<class ItemType>
void BSTNode<ItemType>::setData(ItemType &inputData)
{
	data = inputData;
}

template<class ItemType>
void BSTNode<ItemType>::setLeft(BSTNode<ItemType>* leftNodePtr)
{
	left = leftNodePtr;
}

template<class ItemType>
void BSTNode<ItemType>::setRight(BSTNode<ItemType>* rightNodePtr)
{
	right = rightNodePtr;
}

template<class ItemType>
ItemType BSTNode<ItemType>::getData() const
{
	return data;
}

template<class ItemType>
BSTNode<ItemType>*& BSTNode<ItemType>::getLeft() 
{
	return left;
}

template<class ItemType>
BSTNode<ItemType>*& BSTNode<ItemType>:: getRight() 
{
	return right;
}


#endif