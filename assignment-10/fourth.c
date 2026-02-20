#include<stdio.h>
int main(){
  int hcf,a,b;
  printf("Enter a two number : ");
  scanf("%d %d",&a,&b);
  int min=(a<b)?a:b;
  for (int i = 1; i<=min ; i++)
  {
    if (a%i==0&&b%i==0)
    {
      hcf=i;
    }
    
  }
  if(hcf==1)
  {
    printf("Number is co-prime number");
  }
  else{
    printf("Number is not a co-prime number");

  }
  return 0;
}