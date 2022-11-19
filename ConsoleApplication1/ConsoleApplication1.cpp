#include <iostream>
#include <string>
using namespace std;
// Constant for days in a week
const int NUMBER_OF_DAYS = 7;

// Input validation function prototype
float inputValidation(float);


int main()
{
	// Creating the array to keep track the food for the monkey
	float monkeyFood[3][NUMBER_OF_DAYS];

	// Array for the days in the week
	string daysInWeek[7] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };

	// Variable used for validation
	float validate = 0.0;

	// Loop to gather data for each of the monkey for each of the day
	for (int index = 0; index < NUMBER_OF_DAYS; index++)
	{
		for (int count = 0; count < 3; count++)
		{
			cout << "Enter the food eaten by monkey #" << count + 1 << " on " << daysInWeek[index] << ":";
			cin >> monkeyFood[count][index];
			validate = monkeyFood[count][index];
			inputValidation(validate);
			monkeyFood[count][index] = inputValidation(validate);
		}
	}

	// Variable used for the total calculation of the food that the monkeys consume per day
	float x = 0.0;
	float totalPerDay = x;

	// Calculations from the data to get the average food eaten per day
	for (int index = 0; index < NUMBER_OF_DAYS; index++)
	{
		for (int count = 0; count < 3; count++)
		{
			totalPerDay += monkeyFood[count][index];
		}
	}
	
	//Display the average food consumed per day by the whole family of monkeys
	cout << "Average food consumed daily: " << totalPerDay / 7 << endl;

	//Variables for the calculation of the least amount and the most amount of food eaten by any monkey during the week.
	float least = 999.99;
	float most = 0.0;
	int monkeyLeast = 0, dayLeast = 0, monkeyMost = 0, dayMost = 0;

	//Calculation for the least amount of food during the week by any monkey
	for (int count = 0; count < 3; count++)
	{
		for (int index = 0; index < NUMBER_OF_DAYS; index++)
		{
			if (least > monkeyFood[count][index])
			{
				least = monkeyFood[count][index];
				monkeyLeast = count;
				dayLeast = index;
			}
			
			if (most < monkeyFood[count][index])
			{
				most = monkeyFood[count][index];
				monkeyMost = count;
				dayMost = index;
			}
			
		}
	}

	//Display the least amount of food eaten by any monkey and most amount of food eaten by any monkey
	cout << "The least daily food consumed was by Monkey #" << monkeyLeast + 1 << " on " << daysInWeek[dayLeast] << "." << endl
		<< "The most daily food consumed was by Monkey #" << monkeyMost + 1 << " on " << daysInWeek[dayMost] << "." << endl;
}



// Input validation function
	 float inputValidation(float test)
	{
		while (test < 0)
		{
			cout << "invalid (negative food quantity -- re-enter";
			cin >> test;
			return test;
		}
		return test;
	}


