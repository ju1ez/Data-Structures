
#define MAX 5 //ternary operator
#include<iostream>
#include<stdlib.h>
using namespace std;
//initialize queue
int front = 0, rear = 0;
//class for student detail
class Student {
  private:
    char name[30];
    int id;
    char major[30];

  public:  
    void getDetails(void);
    void displayDetails(void);
};

//input of student detail per defined by user
void Student::getDetails(void) {
  cout << endl << "Enter Name: ";
  cin >> name;
  cout << "Enter Student ID: ";
  cin >> id;
  cout << "Enter Major: ";
  cin >> major;
}

//output of student detail per defined by user
void Student::displayDetails(void) {
  cout << endl << "Student detail" << endl;
  cout << "Name:" << name << endl << "Student ID:"  << id << endl << "Major:" << major << endl;
}

//class for queue of student detail
class StudentQueue {
  Student queue[MAX];
  int rear, front;
  public:
    StudentQueue() {
      rear = -1;
      front = -1;
    }
    
//NON STL enqueue operation
  void enqueue() {
    if (rear > 4) {
      cout << "Queue overflow" << endl;
      front = rear = -1;
      return;
    }
    Student student;
    student.getDetails();
    queue[++rear] = student;
    cout << endl << "The following element was added:";
    queue[rear].displayDetails();
  }
  
//NON STL dequeue operation
  void dequeue() {
    if (front == rear) {
      cout << "Queue underflow" << endl;
      return;
    }
    cout << endl << "The following element was deleted:";
    queue[++front].displayDetails();
  }
  
//NON STL print operation
  void display() {
    if (rear == front) {
      cout << endl << "The queue is empty" << endl;
      return;
    }
    for (int i = front + 1; i <= rear; i++)
      queue[i].displayDetails();
  }
}; //end class definition

//driver
int main() {
  int ch;
  int i = 1;
  StudentQueue stuQueue;
  while (i == 1) {
    cout << endl << "   1. Add an element";
    cout << endl << "   2. Remove an element";
    cout << endl << "   3. Display";
    cout << endl << "   4. Exit";
    cout << endl << endl << "     Enter your choice:";
    cin >> ch;
    switch (ch) {
    case 1:
      stuQueue.enqueue();
      break;
    case 2:
      stuQueue.dequeue();
      break;
    case 3:
      stuQueue.display();
      break;
    case 4:
      i = 0;
    //exit(0);
    default:
      cout << endl << "Goodbye...";
    }
  }
  
  return 0;
  
}
