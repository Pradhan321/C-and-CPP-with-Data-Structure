#include<iostream>
#include<list>
using namespace std;
int main()
{
  list<int>l1={30,60,20,40};
  //how to access list elements
  // [] and at() are not there in list
  //1. Implicit Iterator
  for(auto x:l1)
    cout<<x<<" ";
  cout<<endl;
  //2.explicit Iterator
  list<int>::iterator it;
  for(it=l1.begin();it!=l1.end();it++)
    cout<<*it<<" ";
  cout<<endl;
  return 0;
}