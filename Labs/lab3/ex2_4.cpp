
#include<iostream>
#include<cstdlib>
using namespace std;

class AltMoney
{
public:
AltMoney();
AltMoney(int d, int c);
friend void add(AltMoney m1, AltMoney m2, AltMoney& sum);

//Added friend to subtract 
friend void subtract(AltMoney m1, AltMoney m2, AltMoney& sub);

void display_money( );
private:
int dollars;
int cents;
};
void read_money(int& d, int& c);
int main( )
{
int d, c;
AltMoney m1, m2, sum, sub;
sum = AltMoney(0,0);
sub = AltMoney(0,0);
read_money(d, c);
m1 = AltMoney(d,c);
cout << "\n The first money is:";
m1.display_money();
read_money(d, c);
m2 = AltMoney(d,c);
cout << "\n The second money is:";
m2.display_money();
add(m1,m2, sum);
cout << "\n\n The sum is:";
sum.display_money();

//subtract function/printing the difference amount
subtract(m1,m2, sub);
cout << "\n\n The subtraction is:";
sub.display_money();

cout<<"\n\n";
return 0;
}
AltMoney::AltMoney()
{
}
AltMoney::AltMoney(int d, int c)
{
dollars = d;
cents = c;
}
void AltMoney::display_money()
{
cout << "$" << dollars << ".";
if(cents <= 9)
{
cout << "0";
cout << cents << endl;
}
}

void add(AltMoney m1, AltMoney m2, AltMoney& sum)
{
int extra = 0;
sum.cents = m1.cents + m2.cents;
if(sum.cents >=100)
{
sum.cents = sum.cents - 100;
extra = 1;
}
sum.dollars = m1.dollars + m2.dollars + extra;
}

//difference of the two amounts
void subtract(AltMoney m1, AltMoney m2, AltMoney& sub)
{
int m1Cents, m2Cents, subCents;

//convert amount into cents
m1Cents = (m1.dollars * 100) + m1.cents;
m2Cents = (m2.dollars * 100) + m2.cents;

//Subtract amount from the other amount
subCents = m1Cents - m2Cents;

//find amount
sub.dollars = subCents / 100;
sub.cents = subCents % 100;

//flip negative sign for cents
if(sub.cents < 0)
sub.cents = sub.cents * -1;
}
//void for displaying results..
void read_money(int& d, int& c)
{
cout << "\n\n Please enter the amount of dollars: ";
cin >> d;
cout << "\n Please enter the amount of cents: ";
cin >> c;
if(d < 0 || c < 0)
{
cout << "\n Invalid dollars and cents because the values are negative. \n";
exit(1);
}
}

/*Please ignore, for my use for compiling...

g++ -Wall -c ex2_4.cpp 
g++ ex2_4.cpp -o ex24exe
 ./ex24exe
 
*/
