
#include<iostream>
#include<queue>
#include<cstdio>
using namespace std;

//driver
int main() {
	//variable declarations
  int n, choice, ID;
  string name, desc;
  queue < pair < string, int > > q;
  
  //parent while loop
  while (1) {
    cout << "1. Add" << endl << "2. Delete" << endl << "3. Display" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    fflush(stdin);
    
    //case statements to control queue
    switch (choice) {
    case 1: //queue input from user
      cout << "Enter Name:";
      cin >> name;
      cout << "Enter ID:";
      cin >> ID;
      cout << "Enter Major:";
      cin >> desc;
      q.push(make_pair(name, ID));
      break;
    case 2: //delete input from queue
      if (q.size() > 0) {
        cout << "The Following Entry has been deleted: " << q.front().first << " " << q.front().second << endl;
        q.pop();
      } else {
        cout << "Nothing to Delete..." << endl;
      }
      break;
    case 3: //display input from queue
      cout << endl << "Displaying Queue:" << endl;
      while (q.size() > 0) {
        cout << q.front().first << " " << q.front().second << endl;
        q.pop();
      }
      break;
    }
  }
  
  return 0;
}
