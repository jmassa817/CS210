// Joe Massa
// Feb 24, 2024

#include "GroceryItem.h"
#include <string>
#include <map>
#include <iostream>
#include <fstream>

using namespace std;

// function to display user menu
void printMenu()
{
	cout << endl;
	cout << endl;
	cout << "Corner Grocer Menu" << endl;
	cout << endl;
	cout << "1. Item Lookup" << endl;
	cout << "2. Print list of items purchased" << endl;
	cout << "3. Print histogram list of items purchased" << endl;
	cout << "4. Quit" << endl;
	cout << endl;
	cout << "Enter your selection: " << endl;
}

int main()
{
	int menuSelect;  // user input for menu options
	GroceryItem produceItem; // produce item of GroceryItem class
	ifstream fileInput;  // file input stream
	string itemFromInput; // stores string from Input stream
	string searchItem; // user search string for option 1

	
	// Read input file and create Product Sales Map

	cout << "Reading File Input" << endl;
	fileInput.open("CS210_Project_Three_Input_File.txt");
	if (!fileInput.is_open())  // checks if file has opened correctly
	{
		cout << "Error opening File" << endl;
		return 1;
	}
	fileInput >> itemFromInput;  // stores string from file input to variable

	// loop execute if file input does not fail until end of file
	while (!fileInput.fail())  
	{
		produceItem.SetName(itemFromInput); // sets object name from input
		produceItem.AddItemToMap(produceItem.GetName()); // Adds item to product sales map
		fileInput >> itemFromInput; // calls next input from file
	}
	// handles error in file stream
	if (!fileInput.eof())
	{
		cout << " Input Failure before reaching end of file." << endl;
	}
	
	// closes file after reading all elements
	cout << "Closing File" << endl;
	fileInput.close();

	// sets menu variable to 0	
	menuSelect = 0;
	
	// keeps user in program until exit item is selected
	
	while (menuSelect != 4)	
	{
		printMenu();  // displays menu
		cin >> menuSelect; // captures user selection
		// handles error if user enters  a non-integer input
		while (!cin >> menuSelect) 
		{
			cout << "Error,  please enter 1, 2, 3, or 4 ONLY" << endl;
			cin.clear();
			cin.ignore();
			printMenu();
			cin >> menuSelect;
		}
	
			// switch statement controls menu actions
		switch (menuSelect)
		{
			case 1:
				cout << "Enter an item to search for:" << endl;  // prompt for user input
				cin >> searchItem;
				produceItem.ItemLookup(searchItem); // calls class function to look up item
				break;

			case 2:
				cout << "Running Sales Report" << endl;
				produceItem.PrintSalesList(); // calls class function to print report
				break;

			case 3:
				cout << "Running Sales Histogram Report" << endl;
				produceItem.PrintSalesHistogram();  // calls class function to print histogram
				break;
		
			case 4:
				cout << "Exiting Program ..... Goodbye" << endl;  // exits loop 
				break;

			default:
				cout << "invalid entry";  // handles invalid user entry
				break;
		}
	}

// writes sales report to file
cout << "Writing File" << endl;
produceItem.WriteSalesFile(); // calls class function to wite text file.
return 0;
}
