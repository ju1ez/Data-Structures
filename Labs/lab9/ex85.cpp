
#include <iostream>
#include <string>
using namespace std;

//struct for items
struct item {
  public:
    string name;
    int key;
};

//class for bag
class keyedBag {

  public:
    //stores capacity
    int capacity;
    //stores items
    item * items;
    //stores size
    int size;
    
//constructor for class
  keyedBag() {
    //set capacity to 10
    capacity = 10;
    items = new item[capacity];
    size = 0;
  }

  //remove item
  void removeitem() {
    cout << "Enter item key" << endl;
    int key;
    cin >> key;
    bool keyFound = false;

    //check if item is in bag
    for (int i = 0; i < size; i++) {
      if (items[i].key == key) {
        keyFound = true;
        int j;
        for (j = i; j < size - 1; j++) {
          items[j] = items[j + 1];
        }
        item it;
        items[j] = it;
        size--;
      }

      //if not found exception
      if (!keyFound) {
        cout << "Key is not present cannot remove !" << endl;
      }
    }
  }
  
  friend istream & operator >> (istream & is, keyedBag & obj);
  friend ostream & operator << (ostream & os, keyedBag & obj);
  
}; // end class

//overload input to get item info
istream & operator >> (istream & is, keyedBag & obj) {
  string name;
  int key;
  bool uniqueKey = true;

  do {
    uniqueKey = true;
    if (obj.size == obj.capacity) {
      cout << "Bag is full " << endl;
    } else {
      cout << "Enter the Item Name " << endl;
      cin >> name;
      cout << "Enter Item Key " << endl;
      cin >> key;

      for (int i = 0; i < obj.size; i++) {
        if (obj.items[i].key == key) {
          uniqueKey = false;
          cout << "Duplicate key" << endl; //ensure all keys are unique
        }
      }

      if (uniqueKey) {
        item newItem;
        newItem.key = key;
        newItem.name = name;
        obj.items[obj.size] = newItem;
        obj.size++;
        cout << "Item " << name << " has been added to the bag with key " << key << endl;
      }
    }
  } while (!uniqueKey);
  
  return is;
}

//overload << to print item
ostream & operator << (ostream & os, keyedBag & obj) {
  for (int i = 0; i < obj.size; i++) {
    cout << "Item key = " << obj.items[i].key << " Item name " << obj.items[i].name << endl;
  }
  return os;

}

//driver
int main()
{
  keyedBag bag;
  cout << "Adding 5 items" << endl << endl;

  for (int i = 0; i < 5; i++) {
    cout << "Enter Item " << i + 1 << endl;
    cin >> bag;
  }

  cout << bag;
  cout << endl << "Removing item" << endl;
  bag.removeitem();
  cout << bag;
  cout << "Add item " << endl;
  cin >> bag;
  cout << bag;
  cout << "Removing item" << endl;
  bag.removeitem();
  cout << bag;
  cout << "Add Item " << endl;
  cin >> bag;
  cout << bag;
  cout << "Add Item " << endl;
  cin >> bag;
  cout << bag;

  return 0;
}
