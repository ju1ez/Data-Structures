
#include <iostream>
using namespace std;
template < class T > //template used

//binary search function
int binarySearch(T * a, T val, int n)
{
  int start = 0, end = n - 1;
  int mid;
  while (start <= end)
  
  {
    mid = (start + end) / 2;
    if (val > a[mid])
      start = mid + 1;
    else if (val < a[mid])
      end = mid - 1;
    else
      return mid;
  }
  return -1;
}

//driver
int main()
{
  //binary search algorithm works in defined/sorted array
  int iArr[10] = {
    20,
    40,
    55,
    62,
    67,
    91,
    123,
    146,
    617,
    826
  };
  
  double dArr[10] = {
    21.4,
    50.153,
    64.14,
    74.45,
    75.7,
    89.54,
    91.44,
    103.22,
    116.33,
    189.9
  };
  
  char cArr[10] = {
    'a',
    'e',
    's',
    't',
    'u',
    'v',
    'w',
    'x',
    'y',
    'z'
  };
  
  float fArr[10] = {
    1.234,
    1.464,
    1.345,
    1.090,
    1.235,
    1.054,
    1.905,
    1.435,
    1.234,
    1.523
  };

  int ii;
  double dd;
  char cc;
  float ff;
  
  //testing for integer array
  cout << "Elements of Integer Array" << endl;
  for (int i = 0; i < 10; i++)
  {
    cout << " " << iArr[i] << " ";
  }
  
  cout << endl << endl << "Enter an integer to be searched:" << endl;
  cin >> ii;
  cout << endl <<"Using Binary Search method" << endl;

  int index = binarySearch(iArr, ii, 10);
  if (index == -1)
    cout << "Item does not found!" << endl;
  else
    cout << "Item found in index: " << index << endl;

  //testing for double array
  cout << endl << "Elements of double Array" <<endl;
  for (int i = 0; i < 10; i++)
  {
    cout << " " << dArr[i] << " ";
  }

  cout << endl << endl << "Enter an double to be searched:" << endl;
  cin >> dd;
  cout << endl << "Using Binary Search method" << endl;
  index = binarySearch(dArr, dd, 10);

  if (index == -1)
    cout << "Item does not found!" << endl;
  else
    cout << "Item found in index:" << index << endl;

  //testing for character array
  cout << endl << "Elements of character Array" << endl;
  for (int i = 0; i < 10; i++)
  {
    cout << " " << cArr[i] << " ";
  }

  cout << endl << endl << "Enter an character to be searched:";
  cin >> cc;
  cout << endl << "Using Binary Search method" << endl;
  index = binarySearch(cArr, cc, 10);
  if (index == -1)
    cout << "Item does not found!" << endl;
  else
    cout << "Item found in index:" << index << endl << endl;
  
   //testing for float array
  cout << endl << "Elements of float Array" <<endl;
  for (int i = 0; i < 10; i++)
  {
    cout << " " << fArr[i] << " ";
  }

  cout << endl << endl << "Enter an float to be searched:" << endl;
  cin >> ff;
  cout << endl << "Using Binary Search method" << endl;
  index = binarySearch(fArr, ff, 10);

  if (index == -1)
    cout << "Item does not found!" << endl;
  else
    cout << "Item found in index:" << index << endl;
  system("pause");
  return 0;
}
