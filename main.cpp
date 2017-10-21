#include<fstream>
#include <cstdlib>
#include<string>
#include <iomanip>
#include "HashTable.h"
#include "Food.h"
#include "BSTClass.h"
using namespace std;

void inputFunction(HashTable<class Food> *ref, BST<class Food> *&reffer);
void menuScreen(HashTable<class Food> *hash, BST<class Food> *&bst, int &choice, char &choices);
bool search(HashTable<class Food> *ref, BST<class Food> *&reffer);
void insertData(HashTable<class Food> *ref, BST<class Food> *&reffer);
void remove(HashTable<class Food> *ref, BST<class Food> *&reffer);
void calculateMeal(HashTable<class Food> *ref, BST<class Food> *&reffer);
void listByHash(HashTable<class Food> *ref);
void listByKey(BST<class Food> *reffer);
void indentedTree(BST<class Food> *reffer);
void outputFunction(BST<class Food> *reffer);
void efficiency();

int main(void)
{
	char again = 'x';
	int choice = 0;
	HashTable<class Food>* hashFoods = new HashTable<class Food>;
	BST<class Food> * BSTfoods = new BST <class Food>;
	inputFunction(hashFoods, BSTfoods);

	do
	{
		menuScreen(hashFoods, BSTfoods, choice, again);
		if (choice > 0 && choice < 8)
		{
			cout << "Would you like to do more? (y/n)" << endl;
			cin >> again;
			tolower(again);
		}
		cout << endl;

	} while (again != 'n');

	outputFunction(BSTfoods);
	delete hashFoods;
	delete BSTfoods;
	system("pause");
	return 0;

}

void menuScreen(HashTable<class Food> *hash, BST<class Food> *&bst, int &choice, char & choices)
{



	cout << "Hello user, Welcome to Project Group 3 McDonalds Nutrition Program!\n" << endl;
	cout << "1. Add new item" << endl;
	cout << "2. Delete Data" << endl;
	cout << "3. Search for item" << endl;
	cout << "4. Add new data" << endl;
	cout << "5. List Sorted Data" << endl;
	cout << "6. Print indented tree" << endl;
	cout << "7. Efficiency" << endl;
	cout << "8. List Hash Table" << endl;
	cout << "9. Quit" << endl << endl;
	cout << "Please enter what you would like to do: ";
	cin >> choice;
	cout << endl;
	while (choice > 9 || choice < 0)
	{
		cout << "Invalid Input. Choose Again: ";
		cin >> choice;
	}
	switch (choice)
	{
	case 1: insertData(hash, bst);
		break;
	case 2: remove(hash, bst);
		break;
	case 3:	if (search(hash, bst) == true)
	{
		cout << "This item is in the menu" << endl;
	}
			else
			{
				cout << "\nThe item is not in the menu" << endl;
			}
			break;
	case 4: calculateMeal(hash, bst);
		break;
	case 5: listByKey(bst);
		break;
	case 6: indentedTree(bst);
		break;
	case 7: efficiency();
		break;
	case 8: listByHash(hash);
		break;
	case 9: choices = 'n';
		break;

	}
}

void insertData(HashTable<class Food> *ref, BST<class Food> *&reffer)
{
	Food temp;
	string foodName;
	string foodType;
	int calories;
	int fats;
	int carbs;
	int proteins;
	cout << "Type of item (Breakfast/Burger/Chicken/Side/Desserts/Drink): ";
	cin >> foodType;

	cout << "\nWhat is the food name: ";
	cin >> foodName;

	cout << "\nHow many calories: ";
	cin >> calories;

	cout << "\nHow many fats: ";
	cin >> fats;

	cout << "\nHow many carbs: ";
	cin >> carbs;

	cout << "\nHow many proteins: ";
	cin >> proteins;
	cout << endl;

	temp.setKey(foodType);
	temp.setFood(foodName);
	temp.setCalories(calories);
	temp.setFats(fats);
	temp.setCarbs(carbs);
	temp.setProteins(proteins);
	ref->insert(reffer, temp);

	if (ref->search(reffer, temp) == true)
	{
		cout << "Succesfully added!\n" << endl;
	}
	else
	{
		cout << "Failure to add!\n" << endl;
	}

}

void inputFunction(HashTable<class Food> *ref, BST<class Food> *&reffer)
{

	string foods, key;
	ifstream inputFile;
	int calories, fats, carbs, proteins;
	inputFile.open("McDonalds.txt");

	if (!inputFile)
	{
		cout << "File cannot open" << endl;
		exit(1);
	}

	cout << left << setw(10) << "Type" << setw(25) << "Name" << setw(9) << "calories" <<
		setw(5) << "fats" << setw(6) << "carbs" << setw(8) << "protein" << endl << endl;

	while (inputFile >> key >> foods >> calories >> fats >> carbs >> proteins)
	{

		Food temp;
		temp.setKey(key);
		temp.setFood(foods);
		temp.setCalories(calories);
		temp.setFats(fats);
		temp.setCarbs(carbs);
		temp.setProteins(proteins);
		cout << left << setw(10) << key;
		cout << setw(25) << foods;
		cout << setw(9) << calories;
		cout << setw(5) << fats;
		cout << setw(6) << carbs;
		cout << setw(8) << proteins;
		cout << endl;
		ref->insert(reffer, temp);

	}

	inputFile.close();
	cout << endl;

}

bool search(HashTable<class Food> *ref, BST<class Food> *&reffer)
{
	Food temp;
	string searchChoice;

	cout << "Enter name of item would you like to search: " << endl;
	cin >> searchChoice;
	temp.setFood(searchChoice);

	if (ref->search(reffer, temp) == true)
	{
		return true;
	}
	else
	{
		return false;
	}

}

void calculateMeal(HashTable<class Food> *ref, BST<class Food> *&reffer)
{
	Food temp1;
	int number = 0;
	Food temp2;
	Food hold;
	string choice;

	cout << "Enter an item from the menu: ";
	cin >> choice;
	temp2.setFood(choice);
	temp1 = reffer->searchNode1(temp2);
	cout << "Enter an item from the menu: ";
	cin >> choice;
	temp2.setFood(choice);
	hold = reffer->searchNode1(temp2);
	temp1 = temp1 + hold;
	cout << endl;
	temp1.printAdd();

}

void remove(HashTable<class Food> *ref, BST<class Food> *&reffer)
{
	string choice;
	Food temp;
	cout << "What McDonald food do you want to remove: ";
	cin >> ws;
	cin >> choice;
	temp.setFood(choice);

	if (ref->deletes(reffer, temp) == true)
	{
		cout << "\nWe have succesfully remove the item from the menu! " << endl;
	}
	else
	{
		cout << "\nThe item was not in the menu! " << endl;
	}

}

void listByKey(BST<class Food> *reffer)
{

	reffer->displayInOrder();
	cout << endl;

}

void indentedTree(BST<class Food> *reffer)
{

	cout << endl << "PreOrder:" << endl;
	reffer->displayPerOrder();
	cout << endl;

}

void listByHash(HashTable<class Food> *ref)
{

	ref->printList();
	cout << endl;

}

void outputFunction(BST<class Food> *reffer)
{

	ofstream outFile;
	outFile.open("Display.txt");
	reffer->displayPostOrder(outFile);
	outFile.close();

}

void efficiency()
{
	cout << "Big O will be O(n) on average" << endl;
	cout << "The Best Case will be O(log2(n))" << endl;
	cout << "The worse case will be O(n^2)" << endl << endl;
}