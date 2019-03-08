
#include<iostream>
#include "Contact.h"

using namespace std;

Contact::Contact() {
	part1 = 0;
	part2 = 0;
	part3 = 0;
}

Contact::Contact(int p1, int p2, int p3) {
	part1 = p1;
	part2 = p2;
	part3 = p3;
}

void Contact::display() {
	cout << part1 << "-" << part2 << "-" << part3 << endl;
}
