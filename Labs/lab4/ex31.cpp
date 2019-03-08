
#include <iostream>
using namespace std;
int main() {
  //variable declarations
  int bag;
  char C;
  //pointer declarations
  int * int1p;
  int * int2p;
  int * bagOfIntegersp; // there is no data type of Bags..?
  char * Cp;
  //dynamic variables
  int1p = new int;
  int2p = new int;
  //assign values to points/variables
  * int1p = 30; * int2p = 50;
  bag = 100;
  C = 'K';
  //Copy values into variables
  bagOfIntegersp = & bag;
  Cp = & C;
  //add the values of the two dynamic pointers
  * int1p = * int1p + * int2p + * bagOfIntegersp;
  //copy value of first integer variable to the second
  int2p = & ( * int1p);
  //print end results of variables
  cout << "The Added Integers: " << * int1p << endl;
  cout << "Final value of  variables: " << endl;
  cout << "*int1p = " << * int1p << endl << "*int2p = " << * int2p << endl << "*bagOfIntegersp = " << * bagOfIntegersp << endl << "*Cp = " << * Cp;
}
