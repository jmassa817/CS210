#include <iostream>


using namespace std;

#include "Savings.h"

int main()
{
	// input variables
	double inInitialDeposit;
	double inMonthlyDeposit;
	double inInterestRate;
	int inYears;
	// control variable for main loop
	char exitChar;
	
	
	// declares object of savings type
	Savings sav1;
	
		
	cout << "Welcome to Airgead Banking App" << endl;
	exitChar = 'Y';
	
	
	
	
	// loop executes until user enters Q to quit
	while (exitChar != 'Q')
	{
		sav1.PrintMenu(); // displays the blank Data Input prompt
		system("pause"); // used to pause the program until any key is pressed
					
		// capture values from input with input validation
		cout << "Enter your initial deposit (enter a number)" << endl;
		while (!(cin >> inInitialDeposit)) // loop runs until valid input is entered
		{
			cout << "Error: You must enter a number." << endl;
			cout << "Enter your initial deposit (enter a number)" << endl;
			cin.clear(); // clears input stream
			cin.ignore(200, '\n'); // discards previous input
		}
		sav1.SetInitialDeposit(inInitialDeposit); // sets value in object
		
		cout << "Enter your Interest Rate (enter a number)" << endl;
		while (!(cin >> inInterestRate))
		{
			cout << "Error: You must enter a number." << endl;
			cout << "Enter your interest rate (enter a number)" << endl;
			cin.clear(); // clears input stream
			cin.ignore(200, '\n'); // discards previous input
		}
		sav1.SetInterestRate(inInterestRate); // sets value in object
	
		cout << "Enter your monthly deposit (enter a number)" << endl;
		while (!(cin >> inMonthlyDeposit))
		{
			cout << "Error: You must enter a number." << endl;
			cout << "Enter your monthly deposit (enter a number)" << endl;
			cin.clear(); // clears input stream
			cin.ignore(200, '\n'); // discards previous input
		}
		sav1.SetMonthlyDeposit(inMonthlyDeposit); // sets value in object
	
		cout << "Enter the number of years (enter a whole number)" << endl;
		while (!(cin >> inYears))
		{
			cout << "Error: You must enter a number." << endl;
			cout << "Enter the number of years (enter a whole number)" << endl;
			cin.clear();// clears input stream
			cin.ignore(200, '\n'); // discards previous input
		}		
		sav1.SetNumberOfYears(inYears); // sets value in object


		// display updated Data Input confirmation screen with user values
		sav1.PrintConfirmation(inInitialDeposit, inMonthlyDeposit, inInterestRate, inYears);
		system("pause"); //  pause until any key is pressed

		system("cls"); // clear screen before reports print
		
		// calls PrintReport function of class Savings with parameters and keyword for 
		// report without monthly deposits
		sav1.PrintReport(sav1.GetNumberOfYears(), sav1.GetInitialDeposit(), sav1.GetInterestRate(), 0, "Without");


		// calls PrintReport function of class Savings with parameters and keyword for 
		// report with monthly deposits
		sav1.PrintReport(sav1.GetNumberOfYears(), sav1.GetInitialDeposit(), sav1.GetInterestRate(), sav1.GetMonthlyDeposit(), "With");

		// clear input stream before continuing on with program
		cin.clear();
		cin.ignore(200, '\n');

		// prompt user to remain in program or exit.
		cout << "Do you want to try again with different values?" << endl;
		cout << "Enter Y for yes and Q to quit" << endl; // any key other than Q or q will stay in loop.
		cin >> exitChar;  // captures new input from user
		exitChar = toupper(exitChar); // converts to upper case to ensure loop operates correctly
		
		// clear screen for new entry
		system("cls");


	}
		


	return 0;

}