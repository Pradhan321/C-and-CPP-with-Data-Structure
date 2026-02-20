#include <iostream>
#include <stdio.h>
using namespace std;

struct node
{
  int item;
  node *next;
};

class CLL
{
private:
  node *last;

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
  last = NULL;
}
CLL::CLL(CLL &list)
{
  node *t;
  last = NULL;
  if (list.last != NULL)
  {
    t = list.last->next;
    while (t != list.last)
    {
      insertAtlast(t->item);
      t = t->next;
    }
    insertAtlast(list.last->item);
  }
}
CLL &CLL::operator=(CLL &list)
{
  if (this == &list)
    return *this;
  while (last)
  {
    deleteAtfirst();
  }
  node *t;
  last = NULL;
  if (list.last != NULL)
  {
    t = list.last->next;
    while (t != list.last)
    {
      insertAtlast(t->item);
      t = t->next;
    }
    insertAtlast(list.last->item);
  }
  return *this;
}
void CLL::insertAtfirst(int data)
{
  node *n = new node;
  n->item = data;
  if (last == NULL)
  {
    last = n;
    n->next = n;
  }
  else
  {
    n->next = last->next;
    last->next = n;
  }
}
void CLL::insertAtlast(int data)
{
  node *n = new node;
  n->item = data;
  if (last == NULL)
  {
    last = n;
    n->next = n;
  }
  else
  {
    n->next = last->next;
    last->next = n;
    last = n;
  }
}
void CLL::insertAfter(node *t, int data)
{
  if (t == NULL)
    return;
  node *n = new node;
  n->item = data;
  n->next = t->next;
  t->next = n;
  if (t == last)
  {
    last = n;
  }
}
void CLL::deleteAtfirst()
{
  node *t;
  if (last == NULL)
  {
    return;
  }
  t = last->next;
  if (t == last)
  {
    delete t;
    last == NULL;
  }
  else
  {
    last->next = t->next;
    delete t;
  }
}
void CLL::deleteAtlast()
{
  if (last == NULL)
    return;
  if (last->next == last)
  {
    delete last;
    last = NULL;
    return;
  }
  node *t;
  t = last->next;
  while (t->next != last)
  {
    t = t->next;
  }
  t->next = last->next;
  delete last;
  last = t;
}
void CLL::deletenode(node *t)
{
  if (t == NULL)
  {
    return;
  }

  if (t == last)
  {
    // If it's the last node
    deleteAtLast();
  }
  else if (t == last->next)
  {
    // If it's the first node
    deleteAtFirst();
  }
  else
  {
    // Middle node
    node *r = last->next;
    while (r->next != t)
    {
      r = r->next;
    }
    r->next = t->next;
    delete t;
  }
}
node *CLL::search(int data)
{
  node *t;
  if (last == NULL)
    return NULL;
  t = last->next;
  while (t != last)
  {
    if (t->item == data)
      return t;
    t = t->next;
  }
  if (last->item == data)
  {
    return last;
  }
  return NULL;
}
CLL::~CLL()
{
  while (last)
  {
    deleteAtfirst();
  }
}