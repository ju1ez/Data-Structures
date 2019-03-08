
#include <iostream>
#include <cstdlib>
using namespace std;
class PartFilledArray {
  public:
    PartFilledArray(int array_size);
    PartFilledArray(const PartFilledArray & object);
    ~PartFilledArray();
    void operator = (const PartFilledArray & right_side);
    void add_value(double new_entry);
    void printDetails(); //added member function
  protected:
    double * a;
    int max_number;
    int number_used;
};

PartFilledArray::PartFilledArray(int array_size): max_number(array_size), number_used(0) {
  a = new double[max_number];
}

//copy constructor
PartFilledArray::PartFilledArray(const PartFilledArray & object) {
  max_number = object.max_number;
  number_used = object.number_used;
  a = new double[max_number];
  for (int i = 0; i < max_number; i++) {
    a[i] = object.a[i];
  }
}
//overloaded assignment operator
void PartFilledArray::operator = (const PartFilledArray & right_side) {
  max_number = right_side.max_number;
  number_used = right_side.number_used;
  a = new double[max_number];
  for (int i = 0; i < max_number; i++) {
    a[i] = right_side.a[i];
  }
}

//add_value function definition
void PartFilledArray::add_value(double newEntry) {
  if (number_used < max_number) {
    a[number_used] = newEntry;
  }
  number_used++;
}

//added print-member function definition
void PartFilledArray::printDetails() {
  cout << "max number " << max_number << endl;
  cout << "number used " << number_used << endl;
  cout << "Array is as below" << endl;
  for (int i = 0; i < number_used; i++) {
    cout << a[i] << " ";
  }
}
//deconstructor
PartFilledArray::~PartFilledArray() {
  delete a;
}

//driver to test functions/class
/*
int main() {
  PartFilledArray pfa(5);
  pfa.add_value(20);
  pfa.add_value(21);
  pfa.add_value(9);
  cout << "PFA" << endl;
  pfa.printDetails();
  PartFilledArray pfa2(0);
  pfa2 = pfa;
  cout << "\nPFA2" << endl;
  pfa2.printDetails();
  cout << "\nPFA3" << endl;
  PartFilledArray pfa3(pfa2);
  pfa3.add_value(800);
  pfa3.printDetails();

  return 0;

}
*/
