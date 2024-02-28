// Joe Massa
// Feb 24, 2024


#include "GroceryItem.h"
#include <string>
#include <map>
#include <iostream>
#include <fstream>

using namespace std;


GroceryItem::GroceryItem() // default constructor
{	
}


// mutator function
void GroceryItem::SetName(string itemName)
{
	name = itemName;
}

// accessor function

string GroceryItem::GetName()
{
	return name;
}

// adds an item to the map.  itemName parameter is passed 
// from main using the GetName accessor
void GroceryItem::AddItemToMap(string itemName)
{
	if (produceSalesList.count(itemName) == 0) // checks to see if key already exists in map
	{
		produceSalesList.emplace(itemName, 1); // if no it is added and value is set to 1
	}
	else
	{
		produceSalesList.at(itemName) += 1; // if already exists value is incremented by 1
	}
}

// outputs conents of map in list form with item name and quantity (value)
void GroceryItem::PrintSalesList()
{
	map<string, int> ::iterator it = produceSalesList.begin(); // creates an iterator to cycle through map contents
	while (it != produceSalesList.end()) // loops until end of map
	{
		cout << it->first << " " << it->second << endl;  // outputs the first and second element of the map for current iteration
		++it;  // increment iteration

	}

}


// prints sales report histogram
void GroceryItem::PrintSalesHistogram()
{
	map<string, int> ::iterator it = produceSalesList.begin(); // creates iterator to cycle through map contents
	int numOfSymbols; // used to print symbols for histogram

	while (it != produceSalesList.end())
	{
		cout << it->first << " "; // outputs the name of the item plus a space
		numOfSymbols = it->second; // assigns the key's value from the map to variable 
		for (int i = 1; i <= numOfSymbols; ++i) // loops numOfSymbols times
		{
			cout << "*"; // prints histogram character
		}
		cout << endl; // goes to new line before next iteration
		++it; // increment iterator
	}
}

// look up user input item in map
void GroceryItem::ItemLookup(string inputItem)
{
	if (produceSalesList.count(inputItem) == 1) // checks to see if the user entered item is in the map
	{
		// outputs the value from the map for the user entered item.
		cout << inputItem << " had a total of " << produceSalesList.at(inputItem) << " units sold." << endl; 
	}
	else // if item is not found in map
	{
		cout << "The item you entered does not exist in the sales list.  Please check the spelling and try again" << endl;
		cin.clear();
		cin.ignore();
	}

}


// write text file for Sales report

void GroceryItem::WriteSalesFile()
{
	ofstream fileOutput;  // creates file stream for writing files.

	fileOutput.open("ProduceSalesList.txt"); // creates and opens text file
	if (!fileOutput.is_open()) // checks if the file opened correctly
	{
		cout << "Could Not Open File" << endl;
	}

	map<string, int> ::iterator it = produceSalesList.begin(); // creates iterator to cycle through map elements
	
	while (it != produceSalesList.end())
	{
		// writes each element from the map to the text file
		fileOutput << it->first << " " << it->second << endl;
		++it; // increment iterator
	}
	fileOutput.close();  // close text file

}




