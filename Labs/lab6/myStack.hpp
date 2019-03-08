#ifndef STACKLINKEDLIST
#define STACKLINKEDLIST
#include<iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
namespace myStackList
{
  //structure of a node of the linked list
  struct myStackNode
  {
    //store the value of the node
    string todo;
    //point to the next node in the list
    struct myStackNode * next;
  };
  //class myStack
  class myStack
  {
    public:
    //constructor
      myStack();
    //destructor
    ~myStack();
    //check if the list is empty
    bool isEmpty();
    //push an element into the list
    void push(string todoItem);
    //pop an element from the list
    void pop();
    //peek the top elemet
    struct myStackNode * peek();
    struct myStackNode * getStackHead() {
      return stackHead;
    }
    private:
    //head of the list
      struct myStackNode * stackHead;
  };
}
#endif
