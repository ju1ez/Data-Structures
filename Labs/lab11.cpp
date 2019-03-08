
#include <iostream>
#include <conio.h>
using namespace std;

//MAX_HEAP INSERT/DELETE function
void max_heapify(int * a, int i, int n) {
  int j, temp;
  temp = a[i];
  j = 2 * i;
  while (j <= n) {
    if (j < n && a[j + 1] > a[j])
      j = j + 1;
    if (temp > a[j])
      break;
    else if (temp <= a[j]) {
      a[j / 2] = a[j];
      j = 2 * j;
    }
  }
  a[j / 2] = temp;
  return;
}

//PRINT sorting of MAX_HEAP
void build_maxheap(int * a, int n) {
  int i;
  for (i = n / 2; i >= 1; i--) {
    max_heapify(a, i, n);
  }
}

//driver
int main() {
  int n, i, x;
  cout << "Enter the number of elements in the heap: ";
  cin >> n;
  int a[20];
  for (i = 1; i <= n; i++) {
    cout << "Enter element " << (i) << ": ";
    cin >> a[i];
  }
  build_maxheap(a, n);
  cout << endl << "Max Heap in preorder traversal: " << endl;
  for (i = 1; i <= n; i++) {
    cout << a[i] << endl;
  }
  getch();
   
}
