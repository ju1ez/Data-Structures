//Compute Factorial
#include <stdio.h>
#include <iostream>
#include <fstream> //for output file
using namespace std;
//n! function
int fact(int x, int arr[], int size)
{
    int a = 0;
	int i, z;
    for (i = 0; i < size; ++i) {
        z = arr[i] * x + a;
        arr[i] = z % 10;
        a = z / 10;
    }
    while (a != 0) {
        arr[size] = a % 10;
        a = a / 10;
        size++;
    }
    return size;
}
//driver
int main()
{
    int n, arr[100000000], i, size = 1;
    arr[0] = 1;
    ofstream myfile;
    myfile.open("factorial.txt"); //save to file

    printf("Enter a number to perform its factorial - go big or go home: ");
    while (1) {
        scanf("%d", &n);
        if (n <= 0) { //make sure anything less than 0 is not entered
            printf("Please enter a vaild number: ");
        }
        else {
            break;
        }
    }
    for (i = 2; i <= n; ++i) {
        size = fact(i, arr, size);
    }
    for (i = size - 1; i >= 0; --i) {
        printf("%d", arr[i]);
        myfile << arr[i];
    }
    myfile.close(); //close file
    return 0;
}
