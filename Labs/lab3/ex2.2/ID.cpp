#include<iostream>
#include "Loan.h"
using namespace loanClass;
ID::ID()
{}
ID::ID(int l, int m, int r)
{
	left = l;
	middle = m;
	right = r;
}
Loan::Loan() 
{}
Loan::Loan(float a, float ra, int t) {

	amount = a;
	rate = ra;
	term = t;

}
void ID::display()
{
	std::cout << left << "-" << middle << "-" << right << std::endl;
}
// added display for the LOAN.H
void Loan::displayLoan()
{
	std::cout << "Your Loan amount is: " << amount << ". And the rate would be " << rate << ". Of a term of " << term << " months." << std::endl;
}
