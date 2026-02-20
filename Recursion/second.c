#include<stdio.h>
int fac(int);
int main(){
  int k,n1;
printf("Enter a number : ");
scanf("%d",&n1);
  k=fac(n1);
  printf("%d ",k);
return 0;
}


int fac(int n)
{
  int f=1;
  if(n==1)
  {
    return 1;
  }
  return n*fac(n-1);
  
}
