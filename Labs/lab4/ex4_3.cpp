
#include <iostream>
#include "empClass2.h" //include class
using namespace std;
//driver
int main() {
	
  //predefining Marcy
  Employee * emp1 = new Employee;
  emp1 -> employee_Name = "Marcy";
  emp1 -> employee_SSN = "678-09-1234";
  
  //predefining Michael
  Employee * emp2 = new Employee();
  emp2 -> employee_Name = "Michael";
  emp2 -> employee_SSN = "123-99-4567";
  
  //before swap
  cout << "Before swapping" << endl;
  cout << "Employee 1" << endl;
  cout << "Name: " << emp1 -> employee_Name << endl;
  cout << "SSN: " << emp1 -> employee_SSN << endl << endl;
  cout << "Employee 2" << endl;
  cout << "Name: " << emp2 -> employee_Name << endl;
  cout << "SSN: " << emp2 -> employee_SSN << endl;
  
  //swapping
  Employee * temp = emp1;
  emp1 = emp2;
  emp2 = temp;
  
  //after swap
  cout << endl << "After swapping" << endl;
  cout << "Employee 1" << endl;
  cout << "Name: " << emp1 -> employee_Name << endl;
  cout << "SSN: " << emp1 -> employee_SSN << endl << endl;
  cout << "Employee 2" << endl;
  cout << "Name: " << emp2 -> employee_Name << endl;
  cout << "SSN: " << emp2 -> employee_SSN << endl;

  //testing findssn
  cout << endl << "Testing..." << endl;
  Employee arrEmp[2];
  arrEmp[0].employee_Name = "Julia";
  arrEmp[0].employee_SSN = "10";
  arrEmp[1].employee_Name = "Mark";
  arrEmp[1].employee_SSN = "11";
  cout << findssn(arrEmp, 2, "10") << endl;
  cout << findssn(arrEmp, 2, "11") << endl;
  return 0;
}
