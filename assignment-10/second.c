#include<stdio.h>
int main(){
  int n,a=0,b=1,temp;
  printf("Enter a number : ");
  scanf("%d",&n);
  
  printf("1 term of fibonacci number is : %d\n",a);
  printf("2 term of fibonacci number is : %d\n",b);
  for(int i=3;i<=n;i++)
  {
    temp=a+b;
    a=b;
    b=temp;
    
    
    printf("%d term of fibonacci number is : %d\n",i,temp);
  }
  return 0;
}