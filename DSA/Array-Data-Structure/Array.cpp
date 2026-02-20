#include <iostream>
#include <stdio.h>
using namespace std;
class Array
{
private:
  int capacity;
  int lastIndex;
  int *ptr;

public:
  Array();
  Array(Array&);
  Array& operator=(Array&);
  void createArray(int); // size
  void insert(int, int); // index and values
  void append(int);      // value
  int getItem(int);      // index
  bool isEmpty();
  bool isFull();
  void del(int);       // index
  void edit(int, int); // index and values
  int count();
  int getCapacity();
  ~Array();
};
Array::Array()
{
  ptr=NULL;
}
Array::Array(Array &arr)
{
  int i;
  capacity=arr.capacity;
  lastIndex=arr.lastIndex;
  ptr=new int[capacity];
  for(i=0;i<=lastIndex;i++)
  ptr[i]=arr.ptr[i];
}
Array& Array::operator=(Array &arr)
{
  int i;
  capacity=arr.capacity;
  lastIndex=arr.lastIndex;
  if(ptr!=NULL)
  {
    delete []ptr;
  }
  ptr=new int[capacity];
  for(i=0;i<=lastIndex;i++)
  ptr[i]=arr.ptr[i];
  return *this;
}
void Array::createArray(int size)
{
  capacity = size;
  lastIndex = -1;
  if (ptr != NULL)
  {
    delete []ptr;
  }
  ptr = new int[capacity];
}

void Array::insert(int index, int value)
{
  if (index < 0 || index > lastIndex + 1)
  {
    cout << "Invalid Index";
  }
  else
  {
    for (int i = lastIndex; i >= index; i--)
    {
      ptr[i + 1] = ptr[i]
    }
    ptr[index] = value;
    lastIndex++;
  }
}

void Array::append(int value)
{
  if (isFull())
  {
    cout << "Array is Full";
  }
  else
  {
    lastIndex++;
    ptr[lastIndex] = value;
  }
}
int Array::getItem(int index)
{
  if (index < 0 || index > lastIndex)
  {
    cout << "Invalid Index";
  }
  return ptr[index];
}
bool Array::isEmpty()
{
  if (lastIndex == -1)
  {
    cout << "Array is empty";
  }
  else
  {
    cout << "Array is not empty";
  }
  return lastIndex == -1;
}

bool Array::isFull()
{
  return lastIndex = capacity - 1;
}

void Array::del(int index)
{
  if (index < 0 || index > lastIndex + 1)
  {
    cout << "Invalid Index";
  }
  else
  {
    for (int i = index; i < lastIndex; i++)
    {
      ptr[i] = ptr[i + 1];
    }
    lastIndex--;
  }
}

void Array::edit(int index, int value)
{
  if (index < 0 || index > lastIndex + 1)
  {
    cout << "Invalid Index";
  }
  else
  {
    ptr[index] = value;
  }
}

int Array::count()
{
  return lastIndex + 1;
}

int Array::getCapacity()
{
  return capacity;
}

Array::~Array()
{
  delete []ptr;
}