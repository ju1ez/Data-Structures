#include<iostream>
#include "ID.h"
using namespace idclass1;
ID::ID()
{
	// use default values
}
ID::ID(int l, int m, int r)
{
	left = l;
	middle = m;
	right = r;
}
void ID::display()
{
	std::cout << left << "-" << middle << "-" << right << std::endl;
}
