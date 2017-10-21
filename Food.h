#ifndef FOOD_H_INCLUDED
#define FOOD_H_INCLUDED
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class Food
{
private:
	int calories;
	int proteins;
	int fats;
	int carbs;
	string foods;
	string key;
	
public:
	Food();
	Food(const Food &obj);
	int getCalories();
	int getProteins();
	int getFats();
	int getCarbs();
	string getFood();
	string getKey();

	void setCarbs(int carbs_);
	void setNext(Food* nexting);
	void setKey(string keys_);
	void setFood(string foods_);
	void setCalories(int calories_);
	void setProteins(int proteins_);
	void setFats(int fats_);
	void printOutFile(ofstream &outFile);
	void printData();
	void printAdd();
	friend ostream &operator << (ostream &left, const Food &right);
	friend bool operator <(Food &food1, Food &food2);
	friend bool operator >(Food &food1, Food &food2);
	friend bool operator ==(Food &food1, Food &food2);
	friend bool operator !=(Food &food1, Food &food2);
	Food operator +(const Food &food1);
	
};

#endif