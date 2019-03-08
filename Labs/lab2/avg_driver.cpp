#include <iostream> 
#include "average.hpp" 
using namespace std;
int main(void)
{  /* Call and test all of the functions written */
cout << "Welcome to the average driver program.\n"; 
cout << "Please enter the number of items to be summed: ";
// Call the sum function to input and sum n numbers
// Store the returned value in the variable sigma 
int n;
cin >> n;
// Call the sum function 
double sigma = sum(n); 
// Call the average function 
double avg = average(n, sigma);
cout << "The average of " << sigma << "/" << n << " is: " << avg << endl;
return 0;
}
