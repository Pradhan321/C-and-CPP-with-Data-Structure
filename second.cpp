// // #include<stdio.h>
// // int main()
// // {
// //   printf("Welcome");
// //   return 0;
// // }

// #include<iostream>
// using namespace std;

// class Complex{
//   private:
//   int a,b;
//   public:
//   void setData(int x,int y)
//   {
//     a=x;
//     b=y;
//   }
//   void showdata();
//   Complex add(Complex);
//   Complex operator-(Complex);
    
  
// };
// void Complex::showdata()
// {
// cout<<a<<"+"<<b<<"i"<<endl;
// }
// Complex Complex::add(Complex c)
// {
//   Complex temp;
//   temp.a=a+c.a;
//   temp.b=b+c.b;
//   return temp;
// }
// Complex Complex::operator-(Complex c)
// {
//    Complex temp;
//   temp.a=a-c.a;
//   temp.b=b-c.b;
//   return temp;
// }
// int main()
// {
//   Complex c1,c2,c3,c4;
//   c1.setData(2,4);
//   c2.setData(3,5);
//   c1.showdata();
//   c3=c1.add(c2);
//   c4=c1-c2;
//   c4.showdata();
//   c3.showdata();
//   return 0;
// }
#include<iostream>
using namespace std;
class Item{
  private:
    int a,b;
  public:
    void setData(int a,int b)
    {
      this->a=a;
      this->b=b;
    }
    void showData(){
      cout<<"Value of a is "<<a<<" and value of b is "<<b;
    }
    Item greater(Item i){
      if(a+b>i.a+i.b)
      {
        return *this;
      }
      else{
        return i;
      }
    }
};
int main(){
  Item i1,i2,i3;
  i1.setData(10,20);
  i2.setData(8,20);
  i3=i1.greater(i2);
  i3.showData();
return 0;
}