#include <iostream>
#include "Queue.h"
#include "Stack.h"

int main()
{
  TStack<int> a(3);
  a.Push(10);

  std::cout<< a << "\nHi\n";
  return 0;
}
