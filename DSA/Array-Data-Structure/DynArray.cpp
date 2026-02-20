#include <iostream>
#include <stdio.h>
using namespace std;

class dynarray
{
private:
  int capacity;
  int lastIndex;
  int *ptr;

public:
  dynarray()
  {
    ptr = NULL;
  }
  // Copy constructor
  dynarray(dynarray &arr)
  {
    capacity = arr.capacity;
    lastIndex = arr.lastIndex;
    ptr = new int[capacity];
    for (int i = 0; i <= lastIndex; i++)
      ptr[i] = arr.ptr[i];
  }
  // Copy assignment operator
  dynarray &operator=(dynarray &arr)
  {
    capacity = arr.capacity;
    lastIndex = arr.lastIndex;
    if (ptr != NULL)
      delete[] ptr;
    ptr = new int[capacity];
    for (int i = 0; i <= lastIndex; i++)
      ptr[i] = arr.ptr[i];
    return (*this);
  }

  void doublearray()
  {
   int *temp;
   temp=new int[capacity*2];
   for(int i=0;i<=lastIndex;i++)
    temp[i]=ptr[i];
    delete []ptr;
    ptr=temp;
    capacity*=2;
     
  }

  void halfarray()
  {
     int *temp;
   temp=new int[capacity/2];
   for(int i=0;i<=lastIndex;i++)
    temp[i]=ptr[i];
    delete []ptr;
    ptr=temp;
    capacity/=2;
  }

  void createArray(int arr)
  {
    capacity = arr;
    lastIndex = -1;
    if (ptr != NULL)
      delete[] ptr;

    ptr = new int[capacity];
  }

  void insert(int index, int value)
  {
    if (index < 0 || index > lastIndex + 1)
    {
      cout << "Invalid index" << endl;
    }
    else if (isFull())
    {
      doublearray();
    }
    else
    {
      for (int i = lastIndex; i >= index; i--)
      {
        ptr[i + 1] = ptr[i];
      }
      ptr[index] = value;
      lastIndex++;
    }
  }
  void append(int value)
  {
    if (isFull())
    {
      doublearray();
    }
    else
    {
      lastIndex++;
      ptr[lastIndex] = value;
    }
  }

  void getItem(int index)
  {
    if (index < 0 || index > lastIndex + 1)
    {
      cout << "Invalid index" << endl;
    }
    else
    {
      cout << "Index at : " << index << " : " << ptr[index] << endl;
    }
  }

  bool isEmpty()
  {
    if (lastIndex == -1)
    {
      cout << "Array is empty" << endl;
    }
    else
    {
      cout << "Array is not empty";
    }
    return lastIndex == -1;
  }

  bool isFull()
  {
    return lastIndex == capacity - 1;
  }

  void del(int index)
  {
    if (index < 0 || index > lastIndex + 1)
    {
      cout << "Invalid Index" << endl;
    }
    else
    {
      for (int i = index; i < lastIndex; i++)
      {
        ptr[i] = ptr[i + 1];
      }
      lastIndex--;
    }
    if(capacity>1 && lastIndex+1 <= capacity/2)
    halfarray();
  }

  void edit(int index, int value)
  {
    if (index < 0 || index > lastIndex + 1)
    {
      cout << "Invalid Index" << endl;
    }
    else
    {
      ptr[index] = value;
    }
  }

  void count()
  {
    cout << "Number of elements present in array " << lastIndex + 1 << endl;
  }

  void getCapacity()
  {
    cout << "Capacity is " << capacity;
  }

  ~dynarray()
  {
    delete[] ptr;
  }
  void view()
  {
    for(int i=0;i<=lastIndex;i++)
    {
      cout<<ptr[i]<<endl;
    }
  }
};
int main()
{
  dynarray arr;
  arr.createArray(5);
  arr.append(11);
  arr.append(12);
  arr.append(14);
  arr.del(3);
  arr.edit(2, 7);
  arr.view();
  return 0;
}