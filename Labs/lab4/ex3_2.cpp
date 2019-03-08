
#include <iostream>
#include "empClass.h" //include class
using namespace std;
int main() {
	//user size definition for [dynamic] array
   int size;
   cout << "Enter the Number of Employees: ";
   cin >> size;
   
   //dynamic variable/array input
   Employee *empArray = new Employee[size];
   		for(int i = 0; i < size; ++i) {
		       cout << "Enter Name of Employee " << i+1 << ": ";
		       cin >> empArray[i].employee_name;
		       cout << "Enter the Employees SSN " << i+1 << ": ";
		       cin >> empArray[i].employee_SSN;
   			} 
   //print user defined array - nice formatted c:
   for(int i = 0; i < size; ++i) {
       cout << endl << "Employee" << i+1 << ": ";
       cout << "Name: " << empArray[i].employee_name << endl;
       cout << "Social Security Number: " << empArray[i].employee_SSN << endl;
   }
   //deleting array pointer on exit
   delete[] empArray;
   //clear
   return 0;
}
