#include <iostream>
#include <stdio.h>
using namespace std;
#define EMPTY_QUEUE 1
struct node
{
  node *prev;
  int item;
  node *next;
};

class Queue
{
private:
  int item;
  node *front; // start
  node *rear;

public:
  Queue(int);
  Queue(Queue &);
  Queue &operator=(Queue &);
  void insert(int);
  void del();
  int getFront();
  int getBack();
  int count();
  ~Queue();
};

Queue::Queue()
{
  front = NULL;
  rear = NULL;
}
Queue::Queue(Queue &q)
{
  front = rear = NULL;
  node *t = q.front;
  while (t != NULL)
  {
    insert(t->item);
    t = t->next;
  }
}
Queue &Queue::operator=(Queue &q)
{
  if (this == &q)
    return *this;
  while(front)
    del();
  node *t = q.front;
  while (t != NULL)
  {
    insert(t->item);
    t = t->next;
  }
  return *this;
}
void Queue::insert(int data)
{
  node *n = new node;
  n->item = data;
  n->next = NULL;
  if (front == NULL)
  {
    n->prev = NULL;
    front = rear = n;
  }
  else
  {
    n->prev = rear;
    rear->next = n;
    rear = n;
  }
}
int Queue::getFront()
{
  if (front == NULL)
    throw EMPTY_QUEUE;
  return front->item;
}
int Queue::getBack()
{
  if (rear == NULL)
    throw EMPTY_QUEUE;
  return rear->item;
}
void Queue::del()
{
  if (front == NULL)
    throw EMPTY_QUEUE;
  node *t = front;
  if (front == rear)
  {
    front = rear = NULL;
  }
  else
  {
    front = t->next;
    front->prev = NULL;
  }
  delete t;
}
int Queue::count()
{
  int digit = 0;
  node *t = front;
  while (t != NULL)
  {
    digit++;
    t = t->next;
  }
  return digit;
}
Queue::~Queue()
{
  while (front)
  {
    del();
  }
}