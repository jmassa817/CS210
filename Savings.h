#pragma once
#ifndef SAVINGS_H
#define SAVINGS_H
#include <string>

using namespace std;

class Savings
{
	public:
		Savings(); // constructor

		// mutator declarations
		void SetInitialDeposit(double t_initialDeposit);
		void SetInterestRate(double t_interestRate);
		void SetMonthlyDeposit(double t_monthlyDeposit);
		void SetNumberOfYears(int t_years);

		// accessor declarations
		double GetInitialDeposit();
		double GetInterestRate();
		double GetMonthlyDeposit();
		int GetNumberOfYears();

		// other function declarations
		double CalculateInterestAmount(double t_balance, double t_interestRate);
		void PrintReport(int t_years, double t_initialDeposit, double t_interestRate, double t_monthlyDeposit, string keyword);
		void PrintMenu();
		void PrintConfirmation(double t_initialDeposit, double t_monthlyDeposit, double t_interestRate, int t_years);

// private variable declarations
    private:
		double initialDeposit;
		double interestRate;
		double monthlyDeposit;
		int years;


		


};

#endif
