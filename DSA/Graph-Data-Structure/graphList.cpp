#include <iostream>
#include <stdio.h>
#include "../Array-Data-Structure/DynArray.cpp"
using namespace std;

struct node
{
  int vertex;
  int item;
  node *next;
}

class AdjList
{
private:
  node *start;
  int vertex;

public:
  AdjList();
  AdjList(int);
  node* getStart();
  void setVertex(int);
  void addNode(int,int);
  void removeFirstNode();
  void printList();
  ~AdjList();
};
AdjList::AdjList()
{
  start=NULL;
}
AdjList::AdjList(int v)
{
  start=NULL;
  vertex=v;
}
node* AdjList::getStart()
{
  return start;
}
void AdjList::setVertex(int v)
{
  vertex=v;
}
void AdjList::addNode(int v,int data)
{
  node*n=new node;
  n->item=data;
  n->vertex=v;
  n->next=start;
  start=n;
}
void AdjList::removeFirstNode()
{
  node*r;
  while(start)
  {
    r=start;
    start=start->next;
    delete r;
  }
}
void AdjList::printList()
{
  node *t;
  t=start;
  while(t)
  {
    cout<<" ("<<t->vertex<<","<<t->item<<") ";
    t=t->next;
  }
}
AdjList::~AdjList()
{
  while(start)
    removeFirstNode();
}
class Graph
{
private:
  int v_count;
  AdjList *arr;

public:
  Graph();
  int getVCount();
  dynarray& adjacentNodes(int);
  void createGraph(int);
  void printGraph();
  ~Graph();
};

Graph::Graph()
{
  v_count=0;
  arr=NULL;
}
int Graph::getVCount()
{
  return v_count;
}
dynarray& Graph::adjacentNodes(int n)
{
  dynarray *p=new dynarray(1);
  node *t=this->arr[n].getStart();
  while(t)
  {
    p->append(t->vertex);
    t=t->next;
  }
  return *p;
}
void Graph::createGraph(int vno)
{
  int n,v,data;
  v_count=vno;
  arr=new AdjList[v_count];
  for(int i=0;i<v_count;i++)
  {
    arr[i].setVertex(i);
    cout<<"\nHow many adjacent nodes of V"<<i<<":";
    cin>>n;
    for(int j=0;j<n;j++)
    {
      cout<<"\nEnter vertex Number : ";
      cin>>v;
      //cout<<"Enter the data to store";
      //cin>>data;
      data=10;
      arr[i].addNode(v,data); 
    }
  }
}
void Graph::printGraph()
{
  for(int i=0;i<v_count;i++)
  {
    cout<<endl;
    arr[i].printList();
  }
}
Graph::~Graph()
{
  delete []arr;
}