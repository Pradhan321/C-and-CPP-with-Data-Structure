#include <iostream>
#include <stdio.h>
using namespace std;
#define EMPTY_QUEUE 1
struct node
{
  int item;
  node *next;
  int pno;
};

class PriorityQueue
{
private:
  node *start;

public:
  PriorityQueue();
  PriorityQueue(PriorityQueue &);
  PriorityQueue &operator=(PriorityQueue &);
  void insert(int, int);
  void delete_Highest_Priority_Element();
  int get_Highest_Priority_Element();
  int get_Highest_Priority_number();
  bool isEmpty();
  ~PriorityQueue();
};

PriorityQueue::PriorityQueue()
{
  start = NULL;
}
PriorityQueue::PriorityQueue(PriorityQueue &p)
{
  start=NULL;
  node *t;
  if (p.start)
  {
    t = p.start;
     while (t)
    {
      insert(t->pno,t->item);
      t=t->next;
    }
  }
}
PriorityQueue& PriorityQueue::operator=(PriorityQueue &p)
{
  if(this==&p)
  {
    return *this;
  }
  while(start)
  {
    delete_Highest_Priority_Element();
  }
  node *t;
  if (p.start)
  {
    t = p.start;
     while (t)
    {
      insert(t->pno,t->item);
      t=t->next;
    }
  }
  return *this;
}
void PriorityQueue::insert(int data, int p)
{
  node *n = new node;
  n->pno = p;
  n->item = data;
  node *t;
  if (start == NULL || start->pno < n->pno)
  {
    n->next = start;
    start = n;
  }
  else
  {
    t = start;
    while (t->next != NULL)
    {
      if (start->next->pno < n->pno)
        break;
      t = t->next;
    }
    n->next = t->next;
    t->next = n;
  }
}
void PriorityQueue::delete_Highest_Priority_Element()
{
  node *t;
  if (start)
  {
    t = start;
    start = start->next;
    delete t;
  }
}
int PriorityQueue::get_Highest_Priority_Element()
{
  if (start == NULL)
    throw EMPTY_QUEUE;
  return start->item;
}
int PriorityQueue::get_Highest_Priority_number()
{
  if (start == NULL)
    throw EMPTY_QUEUE;
  return start->pno;
}
PriorityQueue::~PriorityQueue()
{
  while (start)
    delete_Highest_Priority_Element();
}

bool PriorityQueue::isEmpty()
{
  return start == NULL;
}