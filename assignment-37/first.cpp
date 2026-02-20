#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
using namespace std;

class Person
{
private:
  string name;
  int age;

public:
  Person(string name, int age)
  {
    this.age = age;
    this.name = name;
  }
};
class Complex
{
private:
  int a, b;

public:
  void setData(int a, int b)
  {
    this.a = a;
    this.b = b;
  }
  void showData()
  {
    cout << a << "+" << b << "i" << endl;
  }
}

void
f1()
{
  Complex *cptr = new Complex;
  cptr->setData(10, 20);
  cptr->showData();
}

class Time
{
private:
  int hr, min, sec;

public:
  void setTime(int hr, int min, int sec)
  {
    this->hr = hr;
    this->min = min;
    this->sec = sec;
  }
  void showTime()
  {
    cout << hr << " : " << min << " : " << sec << endl;
  }
  void setHours(int hr) { this->hr = hr; }
  void setMin(int min) { this->min = min; }
  void setSec(int sec) { this->sec = sec; }

  void getHours() { return hr; }
  void getMin() { return min; }
  void getSec() { return sec; }
  bool operator<(Time t)
  {
    if (hr < t.hr)
      return true;
    else if (hr > t.hr)
      return false;
    else if (min < t.min)
      return true;
    else if (min > t.min)
      return false;
    else if (sec < t.sec)
      return true;
    else
      return false;
  }
  Time *f1(int size)
  {
    return new Time[size];
  }
  void sort(Time t[], int size)
  {
    int r, i;
    Time temp;
    for (r = 1; r <= size - 1; r++)
    {
      for (i = 0; i <= size - 1 - r; i++)
      {
        if (t[i + 1] < t[i])
        {
          temp = t[i];
          t[i] = t[i + 1];
          t[i + 1] = temp;
        }
      }
    }
  }
  void displayTimeArray(Time t[], int size)
  {
    for (int i = 0; i < size; i++)
    {
      t[i].showTime();
    }
  }
};
class String
{
private:
  char *s;
  int length;

protected:
  int len(char str[])
  {
    int l;
    for (l = 0; str[l]; l++);
    return l;
  }
  char *inputString()
  {
    char ch, *p = NULL, *q = NULL;
    int size = 1, i;
    printf("Enter your text : ");
    p = (char *)malloc(size);
    p[0] = '\0';
    while (1)
    {
      ch = getchar();
      if (ch == '\n')
        break;
      q = (char *)malloc(size + 1);
      for (i = 0; i < size; i++)
        q[i] = p[i];
      q[i - 1] = ch;
      q[i] = '\0';
      free(p);
      size++;
      p = (char *)malloc(size);
      strcpy(p, q);
      free(q);
    }
    return p;
  }

public:
  String()
  {
    s = NULL;
    length = 0;
  }
  void setString()
  {
    if (s != NULL)
    {
      delete[] s;
      length = 0;
    }
    s = inputString();
    length = len(s);
  }
  void setString(char arr[])
  {
    if (s != NULL)
    {
      delete[] s;
      length = 0;
    }
    strcpy(s,arr);
    length=len(arr);
  }
  void upper()
  {
    for(int i=0;i<length;i++)
    {
      if(s[i]>='a'&&s[i]<='z')
        s[i]-=32;
    }
  }
  void lower(char arr[])
  {
     for(int i=0;i<length;i++)
    {
      if(s[i]>='A'&&s[i]<='Z')
        s[i]+=32;
    }
  }
  ~String()
  {
    delete []s;
    length=0;
  }
  void printstring()
  {
    cout<<s;
  }
  char* getString(){
    return s;
  }
  int len()
  {
    return length;
  }
};
