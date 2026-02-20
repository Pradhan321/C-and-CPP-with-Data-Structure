#include<iostream>
#include<stdio.h>
using namespace std;
#define EMPTY_DEQUE 1
struct node{
  node* prev;
  int item;
  node* next;
};

class Deque{
  private:
    node* front;
    node* rear;
  public:
    Deque();
    Deque(Deque&);
    Deque& operator=(Deque&);
    void inserAtfront(int);
    void inserAtrear(int);
    void deleteAtfront(int);
    void deleteAtrear(int);
    int getFront();
    int getRear();
    bool isEmpty();
    ~Deque();
};

Deque::Deque()
{
  front=rear=NULL;
}
Deque::Deque(Deque& d)
{
  node*t;
  front=rear=NULL;
  if(d.front==NULL);
  else
  {
    t=d.front;
    while(t!=NULL)
    {
      inserAtrear(t->item);
      t=t->next;
    }
  }
}
Deque& Deque::operator=(Deque& d)
{
  if(this==&d)
  {
    return *this;
  }
  while(front)
  {
    deleteAtfront();
  }
   node*t;
  if(d.front==NULL)
  {
    front=rear=NULL;
  }
  else
  {
    t=d.front;
    while(t!=NULL)
    {
      inserAtrear(t->item);
      t=t->next;
    }
  }
  return *this;
}
void Deque::inserAtfront(int data)
{
  node*n=new node;
  n->item=data;
  n->prev=NULL;
  n->next=front;
  if(front==NULL)
  {
    front=rear=n;
  }
  else
  {
    front->prev=n;
    front=n;
  }
}
void Deque::inserAtrear(int data)
{
  node*n=new node;
  n->item=data;
  n->next=NULL;
  n->prev=rear;
  if(front==NULL)
  {
    front=rear=n;
  }
  else
  {
    rear->next=n;
    rear=n;
  }
}
void Deque::deleteAtfront()
{
  if(front==NULL)
  {
    throw EMPTY_DEQUE;
  }
  node*t=front;
  if(front==rear)
  {
    front=rear=NULL;
  }
  else
  {
    front=front->next;
    front->prev=NULL;
  }
  delete t;
}
void Deque::deleteAtrear()
{
   if(front==NULL)
  {
    throw EMPTY_DEQUE;
  }
  node*t=rear;
  if(front==rear)
  {
    front=rear=NULL;
  }
  else
  {
    rear=rear->prev;
    rear->next=NULL;
  }
  delete t;
}
int Deque::getFront()
{
  if(front==NULL)
  {
    return NULL;
  }
  return front->item;
}
int Deque::getRear()
{
  if(rear==NULL)
  {
    return NULL;
  }
  return rear->item;
}
bool Deque::isEmpty()
{
  return front==NULL;
}

Deque::~Deque()
{
  while(front)
    deleteAtfront();
}