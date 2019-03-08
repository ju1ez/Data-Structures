
#include <iostream>
#include <cstdlib>
using namespace std;
//class as given in instructions
template < class T >
  class Pair {
    public:
      Pair();
    Pair(T first_value, T second_value);
    void set_element(int position, T value);
    T get_element(int position) const;
    void display_pairs() const; //to display the pairs
    private:
      T first;
    T second;
  };
template < class T >
  void Pair < T > ::set_element(int position, T value) {
    if (position == 1)
      first = value;
    else if (position == 2)
      second = value;
    else {
      cout << "Error: Illegal pair position. \n";
      exit(1);
    }
  }
  
//constructor and definitions 
template < class T >
  Pair < T > ::Pair(T first_value, T second_value): first(first_value), second(second_value) {
    // empty body
  }
template < class T >
  Pair < T > ::Pair() {

  }
template < class T >
  void Pair < T > ::display_pairs() const {
    cout << first << " " << second << endl;
  }
  
//driver with test examples from the instructions
int main() {

  Pair < int > pair;
  pair.set_element(1, 87);
  pair.set_element(2, 90);

  Pair < string > pair1("Tom", "Martha");

  cout << "First pairs: " << endl;
  pair.display_pairs();

  cout << "Second pairs: " << endl;
  pair1.display_pairs();

  return 0;
}
