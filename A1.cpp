//Program that uses a predefined .dat file with arrays in which need to be compressed and organized into a single array
//1-30-2018
#include<fstream>
#include <iostream>
using namespace std;
int main()

{	
	//import predefined arrays
	ifstream input;
	input.open("myA1.dat");
	//read first line
	int rows, cols;
	input >> rows >> cols;
	
	//make a 2-D array
	int matrix[rows][cols];
	//fill the array
	for (int i = 0; i<rows; i++)
	{
		for (int j = 0; j<cols; j++)
		{
			input >> matrix[i][j];
		}
	}
	int nonZero = 0;
	
	//print the non zero rows in the array
	for (int i = 0; i<rows; i++)
	{
		//print the address
		cout << (matrix[i]) << " ";
		for (int j = 0; j<cols; j++)
		{
			if (matrix[i][j] != 0)
			{
				cout << matrix[i][j] << " ";
				nonZero++;//encountered a non zero value
			}
		}
		cout << endl;
	}

	//create a non zero array	
	int non_zero = 0;	
	int non_zero_ele[non_zero];
	int index = 0;
	
	for (int i = 0; i<rows; i++)
	{
		for (int j = 0; j<cols; j++)
		{
			if (matrix[i][j] != 0)
				non_zero_ele[index++] = matrix[i][j];
		}
	}

	//print the array
	cout << endl << endl << "The non zero array is : " << endl;
	for (int i = 0; i<index; i++)
	{
		cout << non_zero_ele[i] << " ";
	}
	input.close();//close the file
	cin.get();//to hold the console screen
	return 0;

}
