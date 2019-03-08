
#include<iostream>
#include "Loan.h"
#include "ID.h"
Loan::Loan()
{
}
Loan::Loan(Bank b, ID I, float am, float rt, int trm)
{
	id = I;
	amount = am;
	rate = rt;
	term = trm;
}
void Loan::set()
{
	int l, m, r;
	ID temp_id;
	// Initialize the loan1 object 
	std::cout << "Enter the left part of the loan ID \n";
	std::cin >> l;
	std::cout << "Enter the middle part of the loan ID \n";
	std::cin >> m;
	std::cout << "Enter the right part of the loan ID \n";
	std::cin >> r;
	id = ID(l, m, r);
	std::cout << "Enter the amount of this loan \n";
	std::cin >> amount;
	std::cout << "Enter the annual interest rate of this loan (in %) \n";
	std::cin >> rate;
	std::cout << "Enter the term (number of months, length of the loan) \n";
	std::cin >> term;
}
void Loan::display()
{
	id.display();
	std::cout << amount << std::endl;
	std::cout << rate << std::endl;
	std::cout << term << std::endl;
}
