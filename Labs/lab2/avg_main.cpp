#include <iostream> //necessary for cin/cout
#include "average.hpp" // use the .hpp for includes
using namespace std;
int main(void)
{ /* Call and test all of the functions written */
cout << "Welcome to the average driver program.\n";
cout << "Please enter the number of items to be summed: ";
int n, count=0;
double single_score, sum=0;
cin >> n;
while (count < n) // read in the test scores and sum them
{
cout << "Test score " << count + 1 << ":";
cin >> single_score;
sum += single_score;
count++;
}
// Call the average function
double avg = average(n, sum);
cout << "The average of " << sum << "/" << n << " is: " << avg << endl;
return 0;
}
