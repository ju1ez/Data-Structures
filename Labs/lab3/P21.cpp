#include<iostream>
using namespace std;
namespace cm
{
	double area(double length, double width);
}
namespace meter
{
	double area(double length, double width);
}
double area_km(double length, double width);
int main()
{
	double length, width; // dimension of a rectangle
	double A; // area of a rectangle
	double P; // paint needed for the rectangle
	cout << "Enter the length and the width of the rectangular field you are painting \n (unit used: m^2))\n";
	cin >> length >> width;
	{
		using namespace cm;
		A = area(length, width);
		//added calculation for paint needed
		P = A * 20;
		cout << "Area is: " << A << endl;
		//added output statement
		cout << "Paint needed: " << P << " mg" << endl;
	}
	{
		using namespace meter;
		A = area(length, width);
		//added calculation for paint needed
		P = A * 0.2;
		cout << "Area is: " << A << endl;
		//added output statement
		cout << "Paint needed: " << P << " kg" << endl;
	}
	A = area_km(length, width);
	//added calculation for paint needed
	P = A * 200;
	cout << "Area is: " << A << endl;
	//added output statement
	cout << "Paint needed: " << P << " T" << endl;
	return 0;
}
namespace cm
{
	double area(double length, double width)
	{
		cout << "From namespace cm, I am sending area in cm^2 back\n";
		return (length * 100)*(width * 100);
	}
}
namespace meter
{
	double area(double length, double width)
	{
		cout << "From namespace meter, I am sending area in m^2 back\n";
		return length * width;
	}
}
double area_km(double length, double width)
{
	cout << "From std namespace, I am sending area in km^2 back\n";
	return (length / 1000)*(width / 1000);
}
