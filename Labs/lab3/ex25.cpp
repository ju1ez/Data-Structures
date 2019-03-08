
#include<iostream> 
#include<string>
using namespace std;
class Date {
private:
	int month, day, year;
public:
	//Contructors
	Date();
	Date(int);
	Date(int, int);
	Date(int, int, int);
	//Destructor
	~Date() {}
	//void do not return values
	void setDay(int);
	void setMonth(int);
	void setYear(int);
	void showDate1();
	void showDate2();
};
Date::Date() {
//Initialize variables.
	month = 1, day = 1, year = 1900;
}
Date::Date(int Month, int Day, int Year) {
	month = Month;
	//incrementing a day
	day = Day + 1;
	year = Year;
}
//error check: assign value to proper variable; if vaild

void Date::setDay(int d) {
	if (d < 1 && d > 31)
		cout << "The day is invalid" << endl;
	else
		day = d;
}
void Date::setMonth(int m) {
	if (m < 1 && m > 12)
		cout << "The month is invalid" << endl;
	else
		month = m;
}
void Date::setYear(int y) {
	if (y < 1950 && y > 2020)
		cout << "The year is invalid" << endl;
	else
		year = y;
}
//Display the date in 2 different formats: number/paper
void Date::showDate1() {
	cout << month << "/" << day << "/" << year << endl;
}
void Date::showDate2() {
	string monthName[] = {
		"January",
		"February",
		"March",
		"April",
		"May",
		"June",
		"July",
		"August",
		"September",
		"October",
		"November",
		"December"
	};
	cout << monthName[month - 1] << " " << day << " " << year << endl;
}
//Driver
int main() {
	int Month, Day, Year;
	cout << "Please enter a month (between 1 - 12) " << endl;
	cin >> Month;

	cout << "Please enter a day (between 1 - 31) " << endl;
	cin >> Day;

	cout << "Please enter a year (between 1950 - 2020) " << endl;
	cin >> Year;

	Date newDate(Month, Day, Year);
	newDate.showDate1();
	newDate.showDate2();
	cin.get();
	cin.get();
	return 0;
}
/*Please ignore, for my use for compiling...

g++ -Wall -c ex25.cpp 

g++ ex25.cpp -o ex25exe

./ex25exe

*/
