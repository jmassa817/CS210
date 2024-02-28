#include "Savings.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

Savings::Savings() // default constructor
{
	initialDeposit = 1.0;
	interestRate = 0.5;
	monthlyDeposit = 0.0;
	years = 1;
}

// mutator functions
void Savings::SetInitialDeposit(double t_initialDeposit)
{
	initialDeposit = t_initialDeposit;
}

void Savings::SetInterestRate(double t_interestRate)
{
	interestRate = t_interestRate;
}

void Savings::SetMonthlyDeposit(double t_monthlyDeposit)
{
	monthlyDeposit = t_monthlyDeposit;

}

void Savings::SetNumberOfYears(int t_years)
{
	years = t_years;
}


// accessor functions

double Savings::GetInitialDeposit()
{
	return initialDeposit;
}

double Savings::GetInterestRate()
{
	return interestRate;
}

double Savings::GetMonthlyDeposit()
{
	return monthlyDeposit;
}

int Savings::GetNumberOfYears()
{
	return years;
}

// calculates interest based on balance and interest rate parameters from print report function

double Savings::CalculateInterestAmount(double t_balance, double t_interestRate)
{
	double interestAmount;

	interestAmount = t_balance * ((t_interestRate / 100) / 12);

	return interestAmount; // returns updated interest amount

}

// Prints formatted report based on input parameters from main
void Savings::PrintReport(int t_years, double t_initialDeposit, double t_interestRate, double t_monthlyDeposit, string keyword)
{
	int yearNumber = 1; // used for loop control
	int monthNumber = 1; //  used for loop control
	double interestAmount = 0.0;
	double balance = 0.0;
	double yearEndBalance = 0.0;
	double yearEndInterest = 0.0;
	

	balance = t_initialDeposit; // sets balance amount to initial deposit set by parameter

	// display formatted header for report
	cout << setfill(' ') << setw(10) << "";
	cout << "Balance and Interest "<< keyword <<" Additional Monthly Deposits" << endl; // uses keyword parameter for With or Without
	cout << setfill('=') << setw(70) << "" << endl;
	cout << setfill(' ') << setw(5) << "";
	cout << setfill(' ') << setw(5) << left << "Year" << "";
	cout << setw(25) << right << "Year End Balance ($)" << "";
	cout << setw(35) << right << "Year End Interest ($)" << "" << endl;
	cout << setfill('-') << setw(70) << "" << endl;


	while (yearNumber <= t_years) // loops until the number of years parameter is reached.
	{
		while (monthNumber <= 12) // loops 12 times to calculate monthly deposits, interest and balance
		{
			balance = balance + t_monthlyDeposit; // adds the monthly deposit to balance
			// calls the function to calculate interest and strores return value in variable
			interestAmount = CalculateInterestAmount(balance, t_interestRate); 
			balance = balance + interestAmount; // updates balance with interest calculation
			monthNumber += 1; // increment numberMonth for next loop iteration
			yearEndInterest += interestAmount; // updates yearly interest sum
		}
		yearEndBalance = balance; // after first year loop, year end balance is updated with the current balance.
		
		// Outputs year end values to report
		cout << setfill(' ') << setw(5) << right << yearNumber;
		cout << fixed << setprecision(2);
		cout <<  setw(25) << right <<"$" << yearEndBalance;
		cout <<  setw(35) << right <<"$" << yearEndInterest << endl;

		yearEndInterest = 0.0; // resets yearEndInterest sum to 0
		interestAmount = 0.0; // reset interestAmount to 0
		monthNumber = 1; // reset monthNumber to 1 for next year in loop
		yearNumber += 1; // increments yearNumber for next loop iteration

	}
	// space between reports
	cout << endl;
	cout << endl;
	
}

void Savings::PrintMenu()  // prints the default blank data input screen
{
	cout << endl; // space for visual clarity
	cout << endl;
	
	// formats the first two rows of display output
	cout << setfill('*') << setw(36) << "" << endl;
	cout << setfill('*') << setw(12) << "";
	cout << " Data Input ";
	cout << setfill('*') << setw(12) << "";
	cout << endl;
	
	// outputs rest of the menu	
	cout << "Initial Investment Amount:" <<  endl;
	cout << "Monthly Deposit: " << endl;
	cout << "Annual Interest: " << endl;
	cout << "Number of Years: " << endl;

}
// print confirmation screen with user input values
void Savings::PrintConfirmation(double t_initialDeposit, double t_monthlyDeposit, double t_interestRate, int t_years)
{
	cout << endl; // space for visual clarity
	cout << endl;

	// formatts the first two rows of display output
	cout << setfill('*') << setw(36) << "" << endl;
	cout << setfill('*') << setw(12) << "";
	cout << " Data Input ";
	cout << setfill('*') << setw(12) << "";
	cout << endl;

	// output rest of menu with user entered values
	cout << "Initial Investment Amount:  $" << t_initialDeposit << endl;
	cout << "Monthly Deposit:  $" << t_monthlyDeposit << endl;
	cout << "Annual Interest: %" << t_interestRate << endl;
	cout << "Number of Years: " << t_years << endl;
	

}