
using namespace std;
class Employee {
  public:
  string employee_Name;
  string employee_SSN;
//constructor
  Employee() {}
  Employee(string n, string s) {
      employee_Name = n;
      employee_SSN = s;
    }
//destructor
  ~Employee() {}
  Employee(Employee & emp) {
      employee_Name = emp.employee_Name;
      employee_SSN = emp.employee_SSN;
    }
//overload operator
  Employee & operator = (Employee emp) {
	    employee_Name = emp.employee_Name;
	    employee_SSN = emp.employee_SSN;
    return *this;
  }
};
//findssn function
  string findssn(Employee * arrEmp, int size, string ssn) {
	  for (int i = 0; i < size; ++i) {
	    if (arrEmp[i].employee_SSN == ssn) {
	      return arrEmp[i].employee_Name;
	    }
  }
  return 0;
}
