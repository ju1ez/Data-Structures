#include<iostream>
#include "ID.h"
using namespace std;
// This part will go to the main program, main_prog.cpp
int main()
{
	using namespace idclass1;
	ID id1;
	id1 = ID(111, 22, 4444);
	id1.display();
	return 0;
}

