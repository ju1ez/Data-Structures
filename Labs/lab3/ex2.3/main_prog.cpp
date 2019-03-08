
#include<iostream>
#include "Loan.h"
#include "ID.h"
int main()
{
	Loan loan1(Bank(), ID(111, 22, 4444), 2300.0, 5.5, 48); // initialize to values given
	Loan loan2;
	std::cout << "Display loan1 \n";
	loan1.display();
	loan2.set(); // set the values
	std::cout << "Display loan2 \n";
	loan2.display();
	return 0;
}
/*Please ignore, for my use for testing...

g++ -Wall -c main_prog.cpp 

g++ -Wall -c ID.cpp 

g++ -Wall -c Loan.cpp 

g++ -Wall -c Bank.cpp 

g++ -Wall -c Contact.cpp 

g++ main_prog.cpp -o loan_Exe


./loanexe

*/
