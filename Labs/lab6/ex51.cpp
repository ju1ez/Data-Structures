
#include <iostream>
//stack class
#include <stack>
#include <string.h>
using namespace std;
void stackreverse(char * a, int l) {
  stack < char > b;

  // Push stack
  for (int i = 0; i < l; i++)
    b.push(a[i]);

  // Pop stack
  for (int i = 0; i < l; i++) {
    a[i] = b.top();
    b.pop();
  }

}
//driver
int main() {

  char a[100];
  int l;
  cout << "Enter a string to be displayed backwards:" << endl;
  cin >> a;

  l = strlen(a);

  stackreverse(a, l);

  cout << endl << "The reversed string is:" << endl << a;

  return 0;
}
