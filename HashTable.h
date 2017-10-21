#include<iostream>
#include<string>
#include "LinkedList.h"
#include "Food.h"
#include "BSTClass.h"

template <class T>
class HashTable
{
private:
	int size;
	int hashFunction(int num);
	LinkedList<T> * array;
public:
	HashTable();
	//~HashTable();
	bool deletes(BST<T> *& food, T data);
	bool search(BST<T> *& food, T value);
	void insert(BST<T> *& food,T &newFoods);
	void clear();
	void printList();
	void printData();
};

template <class T>
HashTable<T>::HashTable()
{
	size = 20;
	array = new LinkedList<T>[size];
}

template <class T>
int HashTable<T>::hashFunction(int num)
{
	return (num * 7) % size;
}

template <class T>
bool HashTable<T>::search(BST<T> *& food, T value)
{
	for(int i = 0; i < size; i++)
		{
			if (array[i].find(value) == true && food->searchNode(value) == true)
			{
				return true;
			}
		}
		return false;
}

template <class T>
void HashTable<T>::insert(BST<T> *& food, T &newFoods)
{
	string keys = newFoods.getKey();
	int bucket = hashFunction(keys.length());
	int numbers;
	for (int tries = 0; tries < size; tries++)
	{
		if (array[bucket].getUsed() == false)
		{
			numbers = array[bucket].countNode();
			if (numbers == 8)
			{
				array[bucket].setUsed(true);
			}
			else
			{
				array[bucket].insertAnywhere(newFoods);
				food->insertNode(newFoods);
				return;
			}
		}
		bucket = (bucket + 1) % size;
	}
}

template<class T>
bool HashTable<T>::deletes(BST<T> *& food, T data)
{
	for (int i = 0; i < size; i++)
	{
		if(array[i].find(data) == true && food->searchNode(data) == true)
		{
			array[i].deleteNode(data);
			food->remove(data);
			return true;
		}
	}
	return false;
}

template <class T>
void HashTable<T>::printList()
{
	for (int i = 0; i < size; i++)
	{
		cout << "["<< "Index " << i << "] " ;
		array[i].displays();
		cout << endl;
	}
	cout << endl;
}

template<class T>
void HashTable<T>::printData()
{
	for (int i = 0; i < size; i++)
	{
		array[i].printDatas();
		cout << endl;
	}
}

/*template <class T>
HashTable<T>::~HashTable
{
}*/