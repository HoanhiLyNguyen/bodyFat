// Courtney Nguyen
// Date: 9/23
// Program Title: bodyFat
// Program Description: Ask the user if they want to calculate body fat percentage of a man or a woman and outputs result in an output file

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

// Named constants

int main()
{

	// Variable declaration

	int choice;
	double weight, wrist, waist, hip, forearm, bodyFat;
	double A1, A2, A3, A4, A5, B;

	ofstream outData;
	outData.open("output.out");

	//Program title and description for the user

	cout << "Body Fat Percentage Calculator" << endl << endl;

	// User input

	cout << "Choose the corresponding number for what task you want to complete." << endl;
	cout << "1 - Female" << endl;
	cout << "2 - Male" << endl;
	cout << "Enter selected number here: ";
	cin >> choice;

	// Calculations

	// Output to the screen

	if (choice == 1)
	{
		cout << "What is the weight? " << endl;
		cin >> weight;
		cout << "What is the wrist measurement? " << endl;
		cin >> wrist;
		cout << "What is the waist measurement? " << endl;
		cin >> waist;
		cout << "What is the hip measurement? " << endl;
		cin >> hip;
		cout << "What is the forearm measurement? " << endl;
		cin >> forearm;

		A1 = (weight * .732) + 8.978;
		A2 = wrist / 3.140;
		A3 = waist * .157;
		A4 = hip * .249;
		A5 = forearm * .434;
		B = A1 + A2 - A3 - A4 + A5;
		bodyFat = (weight - B) * (100 / weight);
		
		outData << "The body fat percentage is " << bodyFat << "%." << endl;
		cout << "Please check output.out." << endl;
	}
	else if (choice == 2)
	{
		cout << "What is the weight?" << endl;
		cin >> weight;
		cout << "What is the wrist measurement? " << endl;
		cin >> wrist;

		A1 = (weight * 1.082) + 94.42;
		A2 = wrist / 4.15;
		B = A1 - A2;
		bodyFat = (weight - B) * (100 / weight);
		outData << A1 << " " << A2 << " " << B << " " << weight << (weight - B) << endl;
		outData << "The body fat percentage is " << bodyFat << "%." << endl;
		cout << "Please check output.out." << endl;
	}
	else
		cout << "Input error; program terminating" << endl;

	outData.close();
	return 0;
}