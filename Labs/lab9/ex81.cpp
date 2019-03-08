
#include<iostream>
#include<cstdlib>
using namespace std;
//given AltMoney Class
class AltMoney {
  public:
    AltMoney();
    AltMoney(int d, int c);
    friend AltMoney operator + (AltMoney m1, AltMoney m2);
    friend AltMoney operator += (AltMoney income, AltMoney overload);
    friend bool operator >= (AltMoney income, AltMoney overload);
    void display_money();
    AltMoney add(AltMoney first, AltMoney second, AltMoney & sum);
    void read_money(AltMoney alt);
  private:
    int dollars;
    int cents;
    double sum;
};

void read_money(int & d, int & c);

//driver - most given in instructions/previous lab - modifications made to accept overload operators
int main() {
  int d, c;
  AltMoney sum, income, overload, overl;
  read_money(d, c);
  AltMoney m1(d, c);
  cout << "The first money is: ";
  m1.display_money();
  read_money(d, c);
  AltMoney m2(d, c);
  cout << "The second money is: ";
  m2.display_money();
  sum = m1 + m2;
  cout << "The sum is: ";
  sum.display_money();

  income = m1;
  overload = m2;
  overl = income += overload;

  cout << "The result of overload(+): ";
  overl.display_money();
  return 0;
}

AltMoney::AltMoney() {
  dollars = 0;
  cents = 0;
}

AltMoney::AltMoney(int d, int c) {
  dollars = d;
  cents = c;
}

void AltMoney::display_money() {
  cout << "$" << dollars << ".";
  if (cents <= 9)
    cout << "0"; //to display a 0 in the left for numbers less than 10
  cout << cents << endl;
}
//-------------------------------------- Overload Operators
AltMoney operator +(AltMoney m1, AltMoney m2) {
  AltMoney temp;
  int z = 0;
  temp.cents = m1.cents + m2.cents;
  if (temp.cents >= 100) {
    temp.cents = temp.cents - 100;
    z = 1;
  }
  temp.dollars = m1.dollars + m2.dollars + z;
  return temp;
}

AltMoney operator += (AltMoney income, AltMoney overload) {
  if (income >= overload)
    return (income);
  else
    return (overload);
}

bool operator >= (AltMoney income, AltMoney overload) {
  int a1, a2;
  a1 = income.dollars * 100 + income.cents;
  a2 = overload.dollars * 100 + overload.cents;
  if (a1 >= a2)
    return true;
  else
    return false;
}
//-------------------------------------- End of overload operator functions
void read_money(int & d, int & c) {
  cout << "Enter dollar \n";
  cin >> d;
  cout << "Enter cents \n";
  cin >> c;
  if (d < 0 || c < 0) {
    cout << "Invalid dollars and cents, negative values\n";
    exit(1);
  }
}
AltMoney AltMoney::add(AltMoney first, AltMoney second, AltMoney & sum) {
  int z = 0;
  sum.cents = first.cents + second.cents;
  if (sum.cents >= 100) {
    sum.cents = sum.cents - 100;
    z = 1;
  }
  sum.dollars = first.dollars + second.dollars + z;

}
void AltMoney::read_money(AltMoney alt) {
  int d, c;
  cout << "Enter dollar \n";
  cin >> alt.dollars;
  cout << "Enter cents \n";
  cin >> alt.cents;
  if (d < 0 || c < 0) {
    cout << "Invalid dollars and cents, negative values\n";
    exit(1);
  }
}
