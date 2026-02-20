#include<iostream>
using namespace std;

class complex{
  private:
    int r;
    int i;
  public:
    void setvalue(int a,int b)
    {
      r=a;
      i=b;
    }
    void getvalue()
    {
      cout<<r<<"+"<<i<<"i";
    }

}