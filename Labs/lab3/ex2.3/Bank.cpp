
#include<iostream>
#include "Bank.h"

using namespace std;

Bank::Bank() {
	bank_ID = 0;
}

Bank::Bank(int id, Contact p, Contact f) {
	bank_ID = id;
	phone = p;
	fax = f;
}
