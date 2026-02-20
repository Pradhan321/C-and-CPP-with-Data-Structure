#include<iostream>
#include<stdio.h>
using namespace std;
#define UNDERFLOW 1
struct node{
  int item;
  node* next;
};
class Stack{
  private:
    node* top;//start
  public:
  Stack();
  Stack(Stack &);
  Stack &operator=(Stack &);
  void push(int);
  void pop();
  int peek();
  void reverse();
  ~Stack();
};
Stack::Stack()
{
  top=NULL;
}
Stack::Stack(Stack &s)
{
  node *t;
  s.reverse();
  t=s.top;
  while(t)
  {
    push(t->item);
    t=t->next;
  }
  s.reverse();
}
Stack& Stack::operator=(Stack& s)
{
  if(this==&s)
  {
    return *this;
  }
  if(top!=NULL)
  {
    while(top)
       pop();
  }
   node *t;
  s.reverse();
  t=s.top;
  while(t)
  {
    push(t->item);
    t=t->next;
  }
  s.reverse();
  return *this;
}
void Stack::push(int data)
{
  node* n=new node;
  n->item=data;
  n->next=top;
  top=n;
}
void Stack::pop()
{
  if(top==NULL)
    throw UNDERFLOW;
  node *t =top;
  top=t->next;
  delete t;
}
int Stack::peek()
{
  if(top==NULL)
    throw UNDERFLOW;
  return top->item;
}
void Stack::reverse()
{
  Stack s1;
  while(top)
  {
    s1.push(peek());
    pop();
  }
  top=s1.top;
  s1.top=NULL;
}
Stack::~Stack()
{
  while(top)
  {
    pop();
  }
}