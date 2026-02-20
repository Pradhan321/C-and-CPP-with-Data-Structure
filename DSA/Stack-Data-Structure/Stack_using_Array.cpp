#include <iostream>
#include <stdio.h>
using namespace std;
#define STACK_IS_EMPTY 1

class Stack
{
private:
  int capacity;
  int top;
  int *ptr;

public:
  Stack();
  Stack(int);
  Stack(Stack &);
  Stack &operator=(Stack &);
  void createStack(int);
  void push(int);
  void pop();
  int peek();
  bool isFull();
  bool isEmpty();
  ~Stack();
};

Stack::Stack()
{
  capacity = 0;
  top = -1;
  ptr = NULL;
}
Stack::Stack(int cap)
{
  capacity = cap;
  top = -1;
  ptr = new int[capacity];
}
Stack::Stack(Stack &s)
{
  capacity = s.capacity;
  top = s.top;
  ptr = new int[cap];
  for (int i = 0; i <= top; i++)
  {
    ptr[i] = s.ptr[i];
  }
}
Stack &Stack::operator=(Stack &s)
{
  if (this == &s)
  {
    return *this;
  }
  if (ptr != NULL)
  {
    delete[] ptr;
  }
  capacity = s.capacity;
  top = s.top;
  ptr = new int[cap];
  for (int i = 0; i <= top; i++)
  {
    ptr[i] = s.ptr[i];
  }
  return *this;
}
void Stack::createStack(int cap)
{
  if (ptr != NULL)
  {
    delete[] ptr;
  }
  capacity = cap;
  top = -1;
  ptr = new int[cap];
}
void Stack::push(int data)
{
  if (isFull())
  {
    cout << "\nOverflow";
  }
  else
  {
    top++;
    ptr[top] = data;
  }
}
void Stack::pop()
{
  if (isEmpty())
  {
    cout << "\nUnderflow";
  }
  else
  {
    top--;
  }
}
int Stack::peek()
{
  if (isEmpty())
  {
    throw STACK_IS_EMPTY;
  }
  return ptr[top];
}
bool Stack::isFull()
{
  return top == capacity - 1;
}
bool Stack::isEmpty()
{
  return top == -1;
}
Stack::~Stack()
{
  if (ptr != NULL)
  {
    delete[] ptr;
  }
}