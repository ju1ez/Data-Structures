
#include "myStack.hpp"
using namespace myStackList;

//constructor
myStack::myStack()

{
//create an empty list
  stackHead = NULL;
}

//destructor
myStack::~myStack()
{
  //emptying the list
  stackHead = NULL;
}

//push element into the stack
void myStack::push(string myStackNode)

{
  //assignng memory to the new node
  struct myStackNode * item = new(struct myStackNode);
  //pushing the new element to the top of the stack
  item -> next = stackHead;
  //inserting the myStackNode to the stacktop
  item -> todo = myStackNode;
  //set item as the head node
  stackHead = item;
}

//pop element fom stack
void myStack::pop()
{
  //if stack is empty
  if (isEmpty())
    cout << "Stack empty!";
  else
  {
    myStackNode * temp = stackHead;
    //set the element after stackHead as the new head of the list
    stackHead = stackHead -> next;
    //unallocate the mamory
    delete(temp);
  }
}

bool myStack::isEmpty()
{
  //then list is empty
  if (stackHead == NULL)
    return true;
  return false;
}

//the top of the stack is returned
myStackNode * myStack::peek()
{

  //if list is empty
  if (isEmpty())
  {
    cout << "Stack empty!";
    return NULL;
  }
  return stackHead;
}
//driver
int main()
{
  myStack ob;
  ob.push("13");
  ob.push("24");
  ob.push("string hehehe :]");
  ob.push("75");
  ob.push("57");

  while (!ob.isEmpty())
  {
    cout << ob.peek() -> todo << endl;
    ob.pop();
  }
  return 0;
}
