
#include<iostream>
#include<cstdlib>
using namespace std;

//driver
int main()
{

  int mat1[3][3], mat2[3][3];
  int i, j;
  
  //initialize the elements by rad [in range from 0 to 9]
  for (i = 0; i < 3; i++)
  {
    for (j = 0; j < 3; j++)
    { 
      mat1[i][j] = rand() % 10;
      mat2[i][j] = rand() % 10;
    }
  }
  //define matrix one
  cout << "Matrix 1:" << endl;
  for (i = 0; i < 3; i++)
  {
    for (j = 0; j < 3; j++)
      cout << mat1[i][j] << " ";
      cout << endl;
  }
  //define matrix two
  cout << endl << "Matrix 2:" << endl;
  for (i = 0; i < 3; i++)
  {
    for (j = 0; j < 3; j++)
      cout << mat2[i][j] << " ";
      cout << endl;
  }

  //store answer 
  int mat3[3][3];
  
  //initialize each element to 0
  for (i = 0; i < 3; i++)
    for (j = 0; j < 3; j++)
	  mat3[i][j] = 0;
	  int temp = 0, k;
  
		  for (i = 0; i < 3; i++)
		  {
		    for (j = 0; j < 3; j++)
		    {
		      for (k = 0; k < 3; k++)
		        temp += mat1[i][k] * mat2[k][j];
		      mat3[i][j] = temp;
		      //set temp to 0
		      temp = 0;
		    }
		  }

  //output
  cout << endl << "Matrices Multiplied..." << endl;

  for (i = 0; i < 3; i++)
  {
    for (j = 0; j < 3; j++)
      cout << mat3[i][j] << " ";
      cout << endl;
  }

  return 0;
}
