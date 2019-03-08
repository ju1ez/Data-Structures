#ifndef FIGURE_H
#define FIGURE_H
#include<iostream>
using namespace std;
class Figure
{
public:
   virtual void erase()=0;
   virtual void draw()=0;
   virtual void center()=0;
};
#endif FIGURE_H
