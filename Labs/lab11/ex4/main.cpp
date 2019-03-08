#include<iostream>
#include "Figure.h"
#include "Rectangle.h"
#include "Square.h"
#include "Triangle.h"
#include "Circle.h"
using namespace std;
//driver
int main()
{ 
   //Rectangle shape
   Rectangle rect;
   rect.draw();
   rect.erase();
   rect.center();
   
   //Square shape
   Square squ;
   squ.draw();  
   squ.erase();
   squ.center();
   
   //Triangle shape
   Triangle tri;
   tri.draw();
   tri.erase();
   tri.center();
   
   //Circle shape
   Circle circ;
   circ.draw();
   circ.erase();
   circ.center();
   
   system("pause");
   return 0;
}
