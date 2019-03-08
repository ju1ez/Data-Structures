//*****************************************************************************************
// Program Title: Base conversion
// Name: 
// Description: Program that takes a user defined number and base and converts to a different base.
//*****************************************************************************************
//*****************************************************************************************
//Preprocessor directive - imports header iostream to make able of read user input/output - cout/cin would not work properly
//*****************************************************************************************
# include <iostream>
using namespace std;
//*****************************************************************************************
//C++ standard libary; allows for C++ basic keywords/syntax to be used, without it; error on compile UNLESS you specifically add std. i.e : std::cout
//*****************************************************************************************
//Variable Declaration of Base10
double   Base10(long, int);
// ? Variable Declaration of Anybase
double   Anybase(long, int);
//*****************************************************************************************
//Driver of the program
//*****************************************************************************************
int main(void)
{
	//Variable Declaration of num, result, result10, base_from and base_to
	long   num = 0, result = 0, result10 = 0;
	int  Base_from = 0, Base_to = 0;

	//User direction output and input of their NUMBER to be converted/program termination
	cout << "The Game of the Converting The Base of The Number!" << endl;
	cout << "Enter the number to be converted or zero to terminate the program: ";
	cin >> num;

	//parent while loop, takes in the input, displays conditional outputs if input values are out of range - controls flow of program operation; breaks operation with input of 0
	while (num > 0)
	{
		//input of ORGINAL BASE from user
		cout << "Enter the base of the number to be converted: ";
		cin >> Base_from;

		//ensures only numbers 2-10 - condition of loop
		while (Base_from < 2 || Base_from > 10)
		{
			cout << "You entered a invaild base number!" << endl;
			cout << "Please try again to enter the base of the number to be converted: ";
			cin >> Base_from;
		}

		//input of NEW BASE from user
		cout << "Enter the base to convert to: ";
		cin >> Base_to;

		//ensures only numbers 2-10 - condition of loop
		while (Base_to < 2 || Base_to > 10)
		{
			cout << "You entered a invaild base number!" << endl;
			cout << "Please try again to enter the base to converted to: ";
			cin >> Base_to;
		}
		//Checks if BOTH new/old base are 10, if IT IS, jump to else statement, if one of the two are however, it will resume
		if (Base_from != 10 && Base_to != 10)
		{
			//varibale declaration of result10, calls funcation Base10 displays its result on the screen.
			result10 = Base10(num, Base_from);
			cout << "Base 10 is " << result10 << endl;

			//Checks that the  not 0 and that it is not less of its orginal,  if its not, it displays computation of function as defined above

			if (result10 > 0 && result10 < Base_to)
				cout << num << " in base " << Base_from << " is " << result10 << " in base " << Base_to << endl;
			else // if it is 0 or less of its oringal it jumps here,
			{
				// varibale dec of result, when one of teh two are not base 10
				result = Anybase(result10, Base_to);

				//if the base is equal to -1 then we know that it was number that was too big, this display that ouput
				if (result == -1)
					cout << num << " in base " << Base_from << " is too big to be converted to base " << Base_to << endl;
				else // resumes with calculation from function, displays it on the screen
					cout << num << " in base " << Base_from << " is " << result << " in base " << Base_to << endl;
			}
		}
		else // if both numbers ARE 10, then resume to call base10 function
		{
			//checks old number to being base 10 or not, if it is not, calc new 
			if (Base_from != 10)
				result10 = Base10(num, Base_from);
			else //if it is - no function required as numbers as entered by user already in base 10, no further calc req
				result10 = num;

			//checks if NEW base 10 or not
			if (Base_to != 10)
			{
				//if not, calc as anybase other than 10..
				result = Anybase(result10, Base_to);

				//again, it the number is equal to -1 then it was too big
				if (result == -1)
					cout << num << " in base " << Base_from << " is too big to be converted to base " << Base_to << endl;
				else //if not, calc is displayed
					cout << num << " in base " << Base_from << " is " << result << " in base " << Base_to << endl;
			}
			else // if both numbers are NOT 10, this is where calc is displayed
				cout << num << " in base " << Base_from << " is " << result10 << " in base " << Base_to << endl;
		}

		// reset
		result10 = 0;
		result = 0;
		Base_to = 0;
		Base_from = 0;
		num = 0;

		// repeat output for new user input for another loop
		cout << "\nEnter the number to be convered or zero to terminate the program: ";
		cin >> num;
	}

}
//*****************************************************************************************
// Base10 Function for driver
//*****************************************************************************************
//
//*****************************************************************************************
//Used when main program called for either or both numbers having base of 10, if neither, go to AnyBase
//*****************************************************************************************
double   Base10(long num, int Base_from)
{
	//varibale declaration of the numbers power, sum is reset to 0
	long   power = 1;
	double   sum = 0.0;

	// calculation og users number, so long it is greater than 0
	while (num > 0)
	{
		//sets sum to 0 + users number divided by 10 and takes its to the 1 power. i.e 4/10 = 2 reminder of 2, so value would be 2
		sum += num % 10 * power;
		// num = num/10 
		num /= 10;
		// power = power * (Base_From)
		power *= Base_from;
	}
	//returns sum for the loop iteration - will be wiped on next loop - makes it possible for number to be seen outside function 
	return sum;
}

//*****************************************************************************************
// Anybase Function for driver
//*****************************************************************************************
//
//*****************************************************************************************
// Used when neither base matches 10
//*****************************************************************************************
double   Anybase(long result10, int Base_to)
{
	// variable declaration of sum and power; sum is reset to 0
	double   sum = 0.0;
	double   power = 1;

	// loop to compute result10, so long it is greater than 0
	while (result10 > 0)
	{
		// sum = sum + (result10 / (Base_to * power)) - takes the **remainder**
		sum += result10 % Base_to * power;
		// result10 = result10 (remainder) / Base_10
		result10 /= Base_to;
		// power = power * (10)
		power *= 10;
	}

	// this sets huge results as -1, easier for programming within the driver
	if (sum > 2147483647.0)
		return -1;
	else // returns sum for the loop iteration - will be wiped on next loop - makes it possible for number to be seen outside function 
		return sum;
}
//*****************************************************************************************
