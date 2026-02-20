#include <iostream>
#include <stdio.h>
using namespace std;

struct node
{
  int item;
  node *next;
  node *prev;
};

class CLL
{
private:
  node *start;

public:
  CLL();
  CLL(CLL &);
  CLL &operator=(CLL &);
  void insertAtfirst(int);
  void insertAtlast(int);
  void insertAfter(node *, int);
  void deleteAtfirst();
  void deleteAtlast();
  void deletenode(node *);
  node *search(int);
  ~CLL();
};
CLL::CLL()
{
  start = NULL;
}
CLL::CLL(CLL &list)
{
  node *t;
  start = NULL;
  if (list.start != NULL)
  {
    t = list.start;
    while (t != NULL)
    {
      insertAtlast(t->item);
      t = t->next;
    }
  }
}
CLL &CLL::operator=(CLL &list)
{
  if (this == &list)
    return *this;
  while (start)
  {
    deleteAtfirst();
  }
  node *t;
  start = NULL;
  if (list.start != NULL)
  {
    t = list.start;
    while (t != NULL)
    {
      insertAtlast(t->item);
      t = t->next;
    }
  }
  return *this;
}
void CLL::insertAtfirst(int data)
{
  node *n = new node;
  n->item = data;
  n->prev = NULL;
  n->next = start;
  start->prev = n;
  start = n;
}
void CLL::insertAtlast(int data)
{
  node *n = new node;
  n->item = data;
  n->next = NULL;
  if (start == NULL)
  {
    n->prev = NULL;
    start = n;
  }
  node *t;
  t = start;
  while (t->next != NULL)
  {
    t = t->next;
  }
  t->next = n;
  n->prev = t;
}
void CLL::insertAfter(node *t, int data)
{
  if (t == NULL)
    return;
  node *n = new node;
  n->item = data;
  n->prev = t;
  n->next = t->next;
  if (t->next != NULL)
  {
    t->next->prev = n;
    t->next = n;
  }
}
void CLL::deleteAtfirst()
{
  if (start == NULL)
    return;
  node *t;
  t = start;
  start = t->next;
  if (t->next != NULL)
  {
    start->prev = NULL;
  }
  delete t;
}
void CLL::deleteAtlast()
{
  if (start == NULL)
    return;
  node *t;
  t = start;
  while (t->next != NULL)
  {
    t = t->next;
  }
  if (t->prev != NULL)
  {
    t->prev->next = NULL;
  }
  else
  {
    start = NULL;
  }
  delete t;
}
void CLL::deletenode(node *t)
{
  if (t == NULL)
  {
    return;
  }
  if (t == start)
  {
    deleteAtfirst();
  }
  if (t->prev != NULL)
  {
    t->prev->next = t->next;
  }
  if (t->next != NULL)
  {
    t->next->prev = t->prev;
  }
  delete t;
}
node *CLL::search(int data)
{
  node *t;
  t = start;
  while (t)
  {
    if (t->item == data)
      return t;
    t = t->next;
  }
  return NULL;
}
CLL::~CLL()
{
  while (start)
  {
    deleteAtfirst();
  }
}