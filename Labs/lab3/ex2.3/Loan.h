
#ifndef LOAN_H
#define LOAN_H
#include "Bank.h"
#include "ID.h"
class Loan
{
public:
	Loan();
	Loan(Bank bank, ID id, float amount, float rate, int term);
	void set();
	float payment();
	void display();
private:
	Bank bank;
	ID id; // assume an unique integer in three integer parts
	float amount; // $ amount of the loan
	float rate; // annual interest rate
	int term; // number of months, length of the loan
};
#endif
