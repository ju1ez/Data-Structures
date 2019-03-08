
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
  //template used for generic programming; good when working with multiple data types, typename is just a placeholder for the datatype of the different functions that are defined within the class
  template < typename T >
  //creating Matrix class
  class Matrix {
    private:
    	
    vector<vector<T> > mat;
    int x_size;
    int y_size;
    public:
    	
    //constructor
      template < typename T2 >
      Matrix(vector <vector <T2> > vec) {
        x_size = vec[0].size();
        y_size = vec.size();
        for (int i = 0; i < y_size; i++) {
          vector < T2 >
            var;
          for (int j = 0; j < x_size; j++) {
            var.push_back(vec[i][j]);
          }
          mat.push_back(var);
        }
      }

    //destructor
    ~Matrix() {}

	//returns size of matrix
    int getSize() {
      return x_size * y_size;
    }
    //returns value at current x position [row]
    int getXsize() {
      return x_size;
    }
    //returns value at current y position [cols]
    int getYsize() {
      return y_size;
    }
    //sets the value at given x/y pos
    void setValue(int x, int y, T val) {
      mat[x][y] = val;
    }
    //returns value at givem current pos
    T getValue(int x, int y) {
      return mat[x][y];
    }
    
	//addition function
    Matrix add(Matrix b) {
      if (x_size != b.getXsize() || y_size != b.getYsize()) { //error catch
        cout << "Matrix cannot be added" << endl; 
        return b;
      }
      for (int i = 0; i < y_size; i++) {
        for (int j = 0; j < x_size; j++) {
          b.setValue(i, j, b.getValue(i, j) + mat[i][j]);
        }
      }
      return b;
    }
    
    //subtraction function
    Matrix subtract(Matrix b) {
    	if (x_size != b.getXsize() || y_size != b.getYsize()) { //error catch
        cout << "Matrix cannot be subtracted" << endl;
        return b;
      }
      for (int i = 0; i < y_size; i++) {
        for (int j = 0; j < x_size; j++) {
          b.setValue(i, j, -1 * b.getValue(i, j) + mat[i][j]);
        }
      }
      return b;
    }
    
	//multiplication function
    Matrix multiply(Matrix b) {
      if (x_size != b.getYsize()) { //error catch
        vector < vector < T > > a;
        cout << "Matrix cannot be muliplied" << endl;
        Matrix s(a);
        return s;
      }
      vector < vector < T > > vec;
      for (int i = 0; i < y_size; i++) {
        vector < T > ss;
        for (int j = 0; j < b.getXsize(); j++) {
          for (int l = 0; l < x_size; l++) {
            if (ss.size() == j) {
              ss.push_back(mat[i][l] * b.getValue(l, j));
            } else {
              ss[j] = ss[j] + mat[i][l] * b.getValue(l, j);
            }
          }
        }
        vec.push_back(ss);
      }
      Matrix ma(vec);
      return ma;
    }
	//overlap function
    Matrix overlap(Matrix b) {
    vector < vector < T > > vec2;
    for (int i = 0; i < max(y_size, b.getYsize()); i++) {
    vector < T > vec;
    for (int j = 0; j < max(x_size, b.getXsize()); j++) {
      if ((i < y_size && j < x_size) && (i < b.getYsize() && j < b.getXsize())) {
        vec.push_back(max(mat[i][j], b.getValue(i, j)));
      } else if ((i < y_size && j < x_size)) {
        vec.push_back(mat[i][j]);
      } else if (i < b.getYsize() && j < b.getXsize()) {
        vec.push_back(b.getValue(i, j));
      }
    }
    vec2.push_back(vec);  
  }
  Matrix m(vec2);
  return m;
  }
  
    //print function
    void print() {
      for (int i = 0; i < y_size; i++) {
        for (int j = 0; j < x_size; j++) {
          cout << mat[i][j] << " ";
        }
        cout << endl;
      }
    }
  }; //end Matrix class
  
//driver
int main() {
  //initalize values matrix a
  vector < vector < int > > s;
  vector < int > a;
  a.push_back(2);
  a.push_back(3);
  a.push_back(5);
  s.push_back(a);
  vector < int > b;
  b.push_back(1);
  b.push_back(3);
  b.push_back(4);
  s.push_back(b);
  
  //initalize values matrix b
  vector < vector < int > > s1;
  vector < int > a1;
  a1.push_back(8);
  s1.push_back(a1);
  vector < int > b1;
  b1.push_back(3);
  s1.push_back(b1);
  vector < int > c1;
  c1.push_back(5);
  s1.push_back(c1);
  
  //initalize matrices
  Matrix < int > A(s);
  Matrix < int > B(s1);

  //display to user
  cout << "Printing Matrix A" << endl;
  A.print();
  cout << endl;
  
  cout << "Printing Matrix B" << endl;
  B.print();
  cout << endl;
   
  cout << "Printing Addition of Matrix A and B" << endl;
  Matrix < int > D = A.add(B);
  cout << endl;
  
  cout << "Printing Subtraction of Matrix A and B" << endl;
  Matrix < int > E = A.subtract(B);
  cout << endl;
  
  cout << "Printing muliplication of Matrix A and B" << endl;
  Matrix < int > C = A.multiply(B);
  C.print();
  cout << endl;
  
  cout << "Printing overlap of Matrix A and B" << endl;
  D = A.overlap(B);
  D.print();
  
  return 0;

}
