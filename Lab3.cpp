// Lab3.cpp : Defines the entry point for the console application.
// Jason Diaz

#include "stdafx.h"
#include "iostream"
#include "string"

using namespace std;

int howToUse();
void buyIceCream(double &moneyEarned, int flavorsSold[], int ouncesSold[], int conesSold[]);
void sizesSoldToString(int conesSold[]);
void flavorsSoldToString(int flavorsSold[], int ouncesSold[]);
void moneyEarnedToString(double moneyEarned);

int main()
{
	int userInput = 1;
	double moneyEarned = 0;
	int flavorsSold[2] = { 0,0 };// position 0 = chocolate; position 1 = vanilla
	int ouncesSold[2] = { 0,0 };// position 0 = chocolate; position 1 = vanilla
	int conesSold[3] = { 0,0,0 }; // position 0 = small; position 1 = medium; position 2 = large

	cout << "	Welcome To Sami's Ice Cream shop - Tampa, Fl\n" << endl;

	/* Interpretation:
	0 to quit
	1 to buy ice cream
	2 to show total sizes sold
	3 to show the total number of flavors sold
	4 to show total money made
	*/
	do {
		userInput = howToUse(); // call function to show the user how to use the program
		if (userInput == 1)
			buyIceCream(moneyEarned, flavorsSold, ouncesSold, conesSold);
		if (userInput == 2)
			sizesSoldToString(conesSold);
		if (userInput == 3)
			flavorsSoldToString(flavorsSold, ouncesSold);
		if (userInput == 4)
			moneyEarnedToString(moneyEarned);
	} while (userInput != 0); // 0 will exit program
	return 0;
}

/**
A funtion to show the user how to use the program
*/
int howToUse() {
	int userInput;

	cout << "Enter one of the following values to perform an action: " << endl;
	cout << "	1 - to buy Ice Cream" << endl;
	cout << "	2 - to display how many of each cone size has been sold" << endl;
	cout << "	3 - to display the amount of cones sold by flavor and ounces" << endl;
	cout << "	4 - to display the total amount of money made" << endl;
	cout << "	0 - to exit" << endl;

	cin >> userInput;
	return userInput;
}

/**
A funtion to sell ice cream
*/
void buyIceCream(double &moneyEarned, int flavorsSold[], int ouncesSold[], int conesSold[]) {

	const int sizes[3] = { 9, 12,15 }; // ice cream cones sizes constant
	const double costs[3] = { 2.75, 3.25, 3.75 }; // costs of cones constat

	int userInput;
	int chosenFlavor;

	do {
		cout << "Choose your Flavor\nFor Chocolate enter 0 for Vanilla enter 1" << endl;
		cin >> userInput;
	} while (userInput > 2); // catching an error

	flavorsSold[userInput] += 1; // increase the amount sold
	chosenFlavor = userInput; // saves the chosen flavor to identify the onces sold

	do {
		cout << "Please enter which size you would like:" << endl;
		cout << "0	Small(9oz)		-cost$2.75" << endl;
		cout << "1	Medium(12oz)		-cost$3.25" << endl;
		cout << "2	Large(15oz)		-cost$3.75" << endl;
		cin >> userInput;
	} while (userInput > 3); // catching an error

	moneyEarned += costs[userInput];
	ouncesSold[chosenFlavor] += sizes[userInput];
	conesSold[userInput]++;
	return;
}

/**
A funtion to show the user the number of cones of each size sold
*/
void sizesSoldToString(int conesSold[]) {
	const string sizes[3] = { "Small", "Medium", "Large" };
	for (int i = 0; i < 3; i++) {
		std::cout << "Number of " << sizes[i] << " cones sold " << conesSold[i] << endl;
	}
	return;
}

/**
A funtion to show the user the total amount of ice-cream sold
*/
void flavorsSoldToString(int flavorsSold[], int ouncesSold[]) {
	const string flavors[2] = { "Chocolate", "Vanilla" };

	for (int i = 0; i < 2; i++) {
		std::cout << "Number of " << flavors[i] << " cones sold " << flavorsSold[i] << endl;
		std::cout << "Amount of " << flavors[i] << " in ounces sold " << ouncesSold[i] << endl;

	}
}

/**
A funtion to show the user the total money made
*/
void moneyEarnedToString(double moneyEarned) {

	cout << "$"<< moneyEarned << endl;
	return;
}
