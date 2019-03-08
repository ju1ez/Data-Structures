
#include<iostream>
#include "ID.h"
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
	std::cout << right << "-" << middle << "-" << right << std::endl;
}
