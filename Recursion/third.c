#include<stdio.h>
void natural(int);
int main()
{
int n1;
printf("Enter a number : ");
scanf("%d",&n1);

natural(n1);

}

void natural(int n){
  
if(n>0)
{
  
  natural(n-1);
  printf("%d\n",n);
  
}
}