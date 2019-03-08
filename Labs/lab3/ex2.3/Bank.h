
#ifndef BANK_H
#define BANK_H
#include "Contact.h"
class Bank // Bank class definition
{
public:
	Bank();
	Bank(int bank_ID, Contact phone, Contact fax);
private:
	int bank_ID; // 4 digit integer
	Contact phone; // object three integer pieces, # # #, # # #, # # # #
	Contact fax; // object three integer pieces, # # #, # # #, # # # #
};
#endif
