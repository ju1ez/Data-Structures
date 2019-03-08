
#include <iostream>
using namespace std;

//function declaration
int iterative_factorial(int); 

//driver
int main() {

  int num; //num variable declare
  cout << "This program computes the factorial of a given number" << endl;
  cout << "Enter number: ";
  cin >> num; //input num
  cout << "Factorial of " << num << " is: " << iterative_factorial(num); //print the factoral number pass the function
  return 0;
  
}

//factorial function
int iterative_factorial(int number) {
	
  int fact = 1;
  //iterative method to get factorial of number
  for (int i = 1; i <= number; i++) {
    fact = fact * i;
  }
  
  return fact;
  
}
