
#include<iostream>
using namespace std;

//initialization of circular queue
class trafficQ {
  char *a;
  //delay1 = duration of blinking for RED/GREEN; delay2 = duration of YELLOW
  int delay1, delay2; 
  int r, f, size;
  public:
    trafficQ();
  //add RED/YELLOW/GREEN -> circular queue
  void enque(char); 
  void display();
};

//user definition of the color red/green
trafficQ::trafficQ() {
  size = 3;
  delay2 = 5; //yellow predefined
  cout << "Enter the duration for blinking of the RED and GREEN light:" << endl;
  cin >> delay1;
  a = new char[size];
  r = -1;
  f = -1;
}

//input -> circular queue
void trafficQ::enque(char x) {
  if ((r + 1) % size == f)
    cout << "Circular Q overflow";
  else {
    if (r == size - 1)
      r = 0;
    else {
      r = r + 1;
      a[r] = x;
      if (f == -1)
        f++;
    }
  }
}

//circular queue -> output
void trafficQ::display() {
  int i, j;
  for (i = f; i <= r; i++) {
    cout << endl;
    if (i == 1) {
      for (j = 0; j < delay2; j++)
        cout << a[i];
    } else {
      for (j = 0; j < delay1; j++)
        cout << a[i];
    }
  }
}

//driver
int main() {
  trafficQ q; //initialize
  cout << endl << "The number of characters represents the time [in seconds] duration of the color it represents. i.e. RRR = 3s of the RED light..." << endl;
  q.enque('R');
  q.enque('Y');
  q.enque('G');
  q.display(); //display
  return 0;
}
