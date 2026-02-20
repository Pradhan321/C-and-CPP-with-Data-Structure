#include<stdio.h>
int main()
{
  int a,b;
  printf("Enter any number : ");
  scanf("%d",&a);
  printf("Enter a number that you want to add : ");
  scanf("%d",&b);
  a=a*10+b;
  printf("%d",a);
  
  return 0;
}