#include "average.hpp"
#include <iostream>
using namespace std;

//SUM FUNCTION DEFINITION 
double sum(int n){
	 int sum = 0;
    int number;
  
	 for(int i=0;i<n;i++)
    {
        cout << "Enter number:" << endl;
        cin >> number; 
        sum=sum+number;

    }
	// Output Statements
    cout<<"Input sum is: "<< sum << endl;
	return sum;
}
//AVERAGE FUNCTION DEFINITION 
double average(int num_scores, double sum)
{
return sum / num_scores;
}
