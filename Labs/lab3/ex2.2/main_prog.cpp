
#include<iostream>
#include "Loan.h"
using namespace std;
int main()
{
	using namespace loanClass;

	ID id1;
	id1 = ID(111, 22, 4444);
	id1.display();

	Loan id2;
	id2 = Loan(10000, 10, 60);
	id2.displayLoan();
	return 0;
}

//Please ignore, for my use for compiling...
//g++ main_prog.cpp ID.cpp
//Runs the output file
// ./a.out
