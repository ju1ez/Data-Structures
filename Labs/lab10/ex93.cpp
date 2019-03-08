
#include<iostream>
using namespace std;
#include<conio.h>

//driver
int main() {
  int arr[50], size, i, j, temp;
  cout << "Enter list size:" << endl;
  cin >> size;
  cout << "Enter list elements:" << endl;
  for (i = 0; i < size; i++) {
    cin >> arr[i];
  }
  j = i - 1; // now j will point to the last element
  i = 0; //  and i will be point to the first element
  while (i < j) {
    temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
    i++;
    j--;
  }
  cout << "The reverse of the list:" << endl;
  for (i = 0; i < size; i++) {
    cout << arr[i] << " ";
  }
  getch();
}
