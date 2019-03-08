
#include <iostream>
using namespace std;

//prototype functions
double factorial(double num);
int yesno(char again);

//variables
double n;
char x = 'y';

//driver
int main() {
  cout << "This program computes the factorial of a given number" << endl;
  while (yesno(x) == 1) {

    cout << "Enter number: ";
    cin >> n;
    cout << "Factorial of " << n << " is " << factorial(n) << endl;
    cout << "Input another number to compute? (y/n) ";
    cin >> x;
    yesno(x);
  }
  return 0;
}

//factoral function
double factorial(double num) {
  double temp;

  if (num <= 1)
    return 1;

  temp = num * factorial(num - 1);
  return temp;
}

//menu for choice selection
int yesno(char again) {
  int y;
  if (again == 'y' || again == 'Y') {
    y = 1;
  } else if (again == 'n' || again == 'N') {
    y = 0;
  } else {
    cout << "Please enter choice again: ";
    cin >> x;
    yesno(x);
  }
  return y;
}
