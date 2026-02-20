#include<stdio.h>
int main(){
  int n,a=0,b=1,temp;
  printf("Enter a number : ");
  scanf("%d",&n);
  while (n-1>0)
  {
    temp=a+b;
    a=b;
    b=temp;
    n--;
  }
  printf("%d term of fibonacci number is : %d",n,temp);
  return 0;
}