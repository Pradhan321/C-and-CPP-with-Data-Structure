#include <iostream>
#include <stdio.h>
using namespace std;

struct node
{
  int item;
  node *next;
  node *prev;
};
class CDLL
{
private:
  node *start;

public:
  CDLL();
  CDLL(CDLL &);
  CDLL &operator=(CDLL &);
  void insertAtfirst(int);
  void insertAtlast(int);
  void insertAfter(node *, int);
  void deleteAtfirst();
  void deleteAtlast();
  void deletenode(node *);
  node *search(int data);
  ~CDLL();
};

CDLL::CDLL()
{
  start = NULL;
}
CDLL::CDLL(CDLL &d)
{
  node *t;
  if (d.start = NULL)
    start = NULL;
  else
  {
    t = d.start;
    do
    {
      insertAtlast(t->item);
      t = t->next;
    } while (t != d.start);
  }
}
CDLL &CDLL::operator=(CDLL &d)
{
  if (this == &d)
    return *this;
  while(start)
    deleteAtfirst(); 
  node *t;
  if (d.start = NULL)
    start = NULL;
  else
  {
    t = d.start;
    do
    {
      insertAtlast(t->item);
      t = t->next;
    } while (t != d.start);
  }
  return *this;
}
void CDLL::insertAtfirst(int data)
{
  node *n = new node;
  n->item = data;
  if (start == NULL)
  {
    n->next = n;
    n->prev = n;
    start = n;
  }
  else
  {
    n->prev = start->prev;
    n->next = start;
    start->prev->next = n;
    start->prev = n;
    start = n;
  }
}
void CDLL::insertAtlast(int data)
{
  node *n = new node;
  n->item = data;
  if (start == NULL)
  {
    n->prev = n;
    n->next = n;
    start = n;
  }
  else
  {
    n->prev = start->prev;
    n->next = start;
    start->prev->next = n;
    start->prev = n;
  }
}
void CDLL::insertAfter(node *t, int data)
{
  if (t == NULL || start == NULL)
  {
    cout << "Insertion cannot be Happen !\n";
  }
  else
  {
    node *n = new node;
    n->item = data;
    n->prev = t;
    n->next = t->next;
    t->next->prev = n;
    t->next = n;
  }
}
void CDLL::deleteAtfirst()
{
  if (start != NULL)
  {
    node *t = start;
    if (start->next == start)
    {
      delete start;
      start = NULL;
    }
    else
    {
      start = t->next;
      start->prev = t->prev;
      t->prev->next = start;
      delete t;
    }
  }
}
void CDLL::deleteAtlast()
{
  if (start != NULL)
  {
    node *t;
    if (start->next == start)
    {
      delete start;
      start = NULL;
    }
    else
    {
      t = start->prev;
      t->prev->next = start;
      start->prev = t->prev;
      delete t;
    }
  }
}
void CDLL::deletenode(node *t)
{
  if (t == NULL || start == NULL)
  {
    cout << "Deletion cannot be performed\n";
  }
  else
  {
    if (start == t)
    {
      deleteAtfirst();
    }
    else
    {
      t->prev->next = t->next;
      t->next->prev = t->prev;
      delete t;
    }
  }
}
node *CDLL::search(int data)
{
  if (start == NULL)
  {
    return NULL;
  }
  node *t = start;
  do
  {
    if (t->item == data)
      return t;
    t = t->next;
  } while (t != start);
  return NULL;
}
CDLL::~CDLL()
{
  while (start)
  {
    deleteAtfirst();
  }
}