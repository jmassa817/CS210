// Joe Massa
// Feb 24, 2024


#pragma once
#ifndef GROCERYITEM_H
#define GROCERYITEM_H

#include <map>
#include <string>

using namespace std;


class GroceryItem
{
	public:
		GroceryItem(); // default constructor

		void SetName(string itemName); // mutator
		string GetName();  // acccessor

		// class public functions
		void AddItemToMap(string itemName); // adds item to product sales map
		void PrintSalesList(); //  prints sales report with quantities
		void PrintSalesHistogram(); // prints sales report with histogram
		void ItemLookup(string inputItem); // finds user entered item in map
		void WriteSalesFile(); // creates text file with sales report data


 // class private variables
	private:
		string name;
		map<string, int> produceSalesList;
};

#endif