#include<stdio.h>
int main(){
  int a=432,d,sum=0;
  while (a>0)
  {
    d=a%10;
    a=a/10;
    sum=sum+d;
    
  }
  
printf("sum is : %d",sum);

return 0;
}