#include<stdio.h>
int main(){
  int a=0,b=1,temp=0,x;
  printf("Enter a number : ");
  scanf("%d",&x);
  if(x==0||x==1)
  {
    printf("fibonacci series");
  }

  while(temp<x)
  {
    temp=a+b;
    a=b;
    b=temp;
  }
if(temp==x)
{
  printf("fibonacci series");
}
else{
  printf("not a fibonacci series");
}
  return 0;
}