#include <iostream>
#include <stdio.h>
using namespace std;

struct node
{
  int item;
  node *next;
};

class SLL
{
private:
  node *start;

public:
  SLL();
  SLL(SLL &);
  SLL &operator=(SLL &);
  void insertAtfirst(int);
  void insertAtlast(int);
  void insertAfter(node *, int);
  void deleteAtfirst();
  void deleteAtlast();
  void deletenode(node *);
  int search(int);
  void edit(int,int);
  int count();
  ~SLL();
};

SLL::SLL()
{
  start = NULL;
}
SLL::SLL(SLL &list)
{
  node *t;
  t = list.start;
  start = NULL;
  while (t)
  {
    insertAtlast(t->item);
    t = t->next;
  }
}
SLL &SLL::operator=(SLL &list)
{
  if (this == &list) // self-assignment check
    return *this;
  while (start)
    deleteAtfirst();
  node *t;
  t = list.start;
  while (t)
  {
    insertAtlast(t->item);
    t = t->next;
  }
  return *this;
}
void SLL::insertAtfirst(int data)
{
  node *n = new node;
  n->item = data;
  n->next = start;
  start = n;
}
void SLL::insertAtlast(int data)
{
  node *n = new node;
  node *t;
  n->item = data;
  n->next = NULL;

  if (start == NULL)
  {
    start = n;
  }
  else
  {
    t = start;
    while (t->next != NULL)
    {
      t = t->next;
    }
    t->next = n;
  }
}
void SLL::insertAfter(node *t, int data)
{
  if (t == nullptr) // if t is null, insertion not possible
  {
    cout << "Invalid node (NULL)";
    return;
  }
  node *n = new node;
  n->item = data;
  t->next = n->next;
  t->next = n;
}
void SLL::deleteAtfirst()
{
  node *t;
  if (start)
  {
    t = start;
    start = t->next;
    delete t;
  }
}

void SLL::deleteAtlast()
{
  node *t;
  try
  {
    if (start == NULL)
    {
      throw 1;
    }
    if (start->next == NULL)
    {
      delete start;
      start = NULL;
    }
    else
    {
      node *r = NULL;
      t = start;
      while (t->next != NULL)
      {
        r = t;
        t = t->next;
      }
      delete t;
      r->next = NULL;
    }
  }
  catch (int e)
  {
    if (e == 1)
      cout << "list is empty";
  }
}
void SLL::deletenode(node *t)
{
  node *r;
  try
  {
    if (start == NULL)
    {
      throw 1;
    }
    if (t == start)
    {
      deleteAtfirst();
    }
    else
    {
      r = start;
      while (r->next != t)
      {
        r = r->next;
      }
      r->next = t->next;
      delete t;
    }
  }
  catch (int e)
  {
    if (e == 1)
    {
      cout << "list is empty";
    }
  }
}
int SLL::search(int value)
{
  node*t;
  t=start;
  int pos=1;
  while(t!=NULL)
  {
    if(t->item==value)
    {
      return pos;
    }
    t=t->next;
    pos++;
  }
  return -1;
}
void SLL::edit(int pos,int newValue)
{
  node*t=start;
  int current_pos=1;
  while(t!=NULL&&current_pos<pos)
  {
    t=t->next;
    current_pos++;
  }
  if(t==NULL)
  {
    cout<<"Invalid Position\n";
  }
  t->item=newValue;
}
int SLL::count()
{
  node* t=start;
  int digits=0;
  while(t!=NULL)
  {
    t=t->next;
    digits++;
  }
  return digits;
}
SLL::~SLL()
{
  while(start)
  {
    deleteAtfirst();
  }
}