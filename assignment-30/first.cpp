#include <iostream>
using namespace std;

void check_Prime(int a)
{
  bool isPrime = true;
  if (a <= 1)
    isPrime = false;
  for (int i = 2; i <= a / 2; i++)
  {
    if (a % i == 0)
    {
      isPrime=false;
      break;
    }
  }
  if(isPrime)
    cout<<"Prime Number";
  else
    cout<<"Not a Prime Number";
  cout<<endl;
}
int highest_Digits(int x)
{
  int maxDigit=-1;
  while(x)
  {
  int d=x%10;
  if(maxDigit<d)
  {
    maxDigit=d;
  }
  x=x/10;
}
return maxDigit;
}
double power(double x,double y)
{
   
 if(y>0)
 {
  return x*power(x,y-1);
 }
 else if(y<0)
 {
  return 1/x*power(x,y+1);
 }
 else{
  return 1;
 }
}

bool isFib(int num)
{
  int a=-1,b=1,c=0;
  while(c<num)
  {
    c=a+b;
    if(c==num)
    {
      return true;
    }
    a=b;
    b=c;

  }
  return false;
}
int main()
{
  // check_Prime(88);
  // cout<<"Highest digit is : "<<highest_Digits(4218546)<<endl;
  cout<<"digit is : "<<power(4,-3)<<endl;
  cout << endl;
  return 0;
}