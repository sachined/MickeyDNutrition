#include "Food.h"
#include <iomanip>
using namespace std;

Food::Food()
{
	setKey("");
	setFood(" ");
	setCalories(0);
	setProteins(0);
	setCarbs(0);
	setFats(0);
}

Food::Food(const Food &obj)
{
	setKey(obj.key);
	setFood(obj.foods);
	setCalories(obj.calories);
	setProteins(obj.proteins);
	setCarbs(obj.carbs);
	setFats(obj.fats);
}

void Food::setFood(string foods_)
{
	foods = foods_;
}
void Food::setCalories(int calories_)
{
	calories = calories_;
}
void Food::setFats(int fats_)
{
	fats = fats_;
}
void Food::setProteins(int proteins_)
{
	proteins = proteins_;
}
void Food::setKey(string keys_)
{
	key = keys_;
}

void Food::setCarbs(int carbs_)
{
	carbs = carbs_;
}

int Food::getCalories()
{
	return calories;
}
int Food::getProteins()
{
	return proteins;
}
int Food::getFats()
{
	return fats;
}
string Food::getFood()
{
	return foods;
}
string Food::getKey()
{
	return key;
}

int Food::getCarbs()
{
	return carbs;
}

void Food::printData()
{
	cout << left << setw(10) << key;
	cout << setw(25) << foods;
	cout << setw(9) << calories;
	cout << setw(5) << fats;
	cout << setw(6) << carbs;
	cout << setw(8) << proteins;
	cout << endl;
}

void Food::printAdd()
{
	cout << foods << endl;
	cout << "Total Calories: " << calories << endl;
	cout << "Total Fats: " << fats << endl;
	cout << "Total Carbs: " << carbs << endl;
	cout << "Total Protein: " << proteins << endl;
}

void Food::printOutFile(ofstream &outFile)
{
	outFile << "Food: " << foods << endl;
	outFile << "Calories: " << calories << endl;
	outFile << "Fats: " << fats << endl;
	outFile << "Carbs: " << carbs << endl;
	outFile << "Proteins: " << proteins << endl << endl;
}

ostream &operator << (ostream &left, const Food &right)
{
	left << right.foods;
	return left;
}

bool operator <(Food &food1, Food &food2)
{
	if (food1.foods < food2.foods)
	{
		return true;
	}
	return false;
}

bool operator >(Food &food1, Food &food2)
{
	if (food1.foods > food2.foods)
	{
		return true;
	}
	return false;
}

bool operator ==(Food &food1, Food &food2)
{
	if (food1.foods == food2.foods)
	{
		return true;
	}
	return false;
}

bool operator !=(Food &food1, Food &food2)
{
	if(food1.foods != food2.foods)
	{
		return true;
	}
	return false;
}


Food Food::operator +(const Food &food1)
{
	Food food5;
	food5.calories = this->calories + food1.calories;
	food5.foods = this->foods + " and " + food1.foods;
	food5.proteins = this->proteins + food1.proteins;
	food5.fats = this->fats + food1.fats;
	food5.carbs = this->carbs + food1.carbs;
	return food5;
}



