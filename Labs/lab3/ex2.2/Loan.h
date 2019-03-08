
#ifndef LOAN_H
#define LOAN_H
#include<iostream>

namespace loanClass
{
	class ID
	{
	public:
		ID();
		ID(int, int, int);
		void display();
	private:
		int left;
		int middle;
		int right;
	};

	class Loan  // Loan class definition 
	{
	public:
		Loan();
		// reduced parameters
		Loan(float, float, int);
		void displayLoan();
	private: 
		float amount; // $ amount of the loan 
		float rate; // annual interest rate 
		int term;  // number of months, length of the loan 
	};
}
#endif
