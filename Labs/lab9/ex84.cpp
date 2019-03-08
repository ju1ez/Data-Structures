
#include <iostream>
using namespace std;
class RunnerData
{
  public:
    void set_distance(int d);
    void set_times(int i, double t);
    void display();
    void statistics();
  private:
    double time[5]; //array of time in (s)
    int distance; //distance in (m)
    double min, max, average;

};

//member functions
void RunnerData::set_distance(int d)
{
  distance = d;
}

void RunnerData::set_times(int i, double t) {
  time[i] = t;
}

void RunnerData::display()
{
  cout << "Here are your 5 best times for " << distance << " meter:" << endl;
  for (int i = 0; i < 5; i++)
  {
    cout << time[i] << endl;
  }
}

//defintion for statistics function
void RunnerData::statistics()
{
  double sum = 0, avg;
  double best = time[0];
  double worst = time[0];
  for (int i = 0; i < 5; i++)
  {
    //find the worst time
    if (time[i] > best)
    {
      worst = time[i];
    }
    //find the best time
    else if (time[i] < worst)
    {
      best = time[i];
    }
    //calculate sum
    sum = sum + time[i];
  }
  //calculate the average time
  avg = sum / 5;
  
  //display the output
  cout << "Best time is: " << best << endl;
  cout << "Worst time is: " << worst << endl;
  cout << "Average time is: " << avg << endl;
}

//driver
int main()
{
  //creating a class object
  RunnerData D;
  //calling the functions
  D.set_distance(100);
  D.set_times(0, 7.3);
  D.set_times(3, 11.5);
  D.set_times(4, 12.6);
  D.set_times(1, 6.32);
  D.set_times(2, 9.15);
  D.display();
  D.statistics();

  return 0;

}
