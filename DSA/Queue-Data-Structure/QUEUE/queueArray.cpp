#include <iostream>
#include <stdio.h>
using namespace std;
#define INVALID_QUEUE_STATE 1
#define UNDERFLOW 2
class queue
{
private:
  int capacity;
  int front;
  int rear;
  int *ptr;

public:
  queue(int);
  queue(queue &);
  queue &operator=(queue &);
  void insert(int);
  bool isFULL();
  bool isEmpty();
  void del();
  int getFront();
  int getBack();
  int count();
  ~queue();
};

queue::queue(int cap)
{
  capacity = cap;
  front = -1;
  rear = -1;
  if (cap > 0)
    ptr = new int[capacity];
  else
    ptr = NULL;
}
queue::queue(queue &q)
{
  capacity=q.capacity;
  front=q.front;
  rear=q.rear;
  ptr=new int[capacity];
  for(int i=0;i<capacity;i++)
    ptr[i]=q.ptr[i];
}
queue& queue::operator=(queue &q)
{
  if(this==&q)
    return *this;
  if(ptr!=NULL)
    delete []ptr;
   capacity=q.capacity;
  front=q.front;
  rear=q.rear;
  ptr=new int[capacity];
  for(int i=0;i<capacity;i++)
    ptr[i]=q.ptr[i];
  return *this;
}
void queue::insert(int data)
{
  if (capacity <= 0)
    throw INVALID_QUEUE_STATE;
  if (isFULL())
  {
    cout << "\nOverflow";
  }
  if (isEmpty())
  {
    rear = front = 0;
    ptr[rear] = data;
  }
  else if (rear == capacity - 1)
  {
    rear = 0;
    ptr[rear] = data;
  }
  else
  {
    rear++;
    ptr[rear] = data;
  }
}
bool queue::isFULL()
{
  return (front == 0 && rear == capacity - 1 || rear + 1 == front);
}
bool queue::isEmpty()
{
  return front == -1;
}
void queue::del()
{
  if (isEmpty())
  {
    cout << "\nUnderflow";
  }
  if (front == rear)
  {
    front = -1;
    rear = -1;
  }
  else if (front == capacity - 1)
  {
    front = 0;
  }
  else
  {
    front++;
  }
}
int queue::getFront()
{
  if (isEmpty())
    throw UNDERFLOW;
  return ptr[front];
}
int queue::getBack()
{
  if (isEmpty())
    throw UNDERFLOW;
  return ptr[rear];
}
int queue:: count()
{
  if(front==-1)
    return 0;
  if(front==rear)
    return 1;
  if(rear>front)
    return rear-front+1;
  else
    return capacity-front+rear+1;
}
queue::~queue()
{
  delete[] ptr;
}