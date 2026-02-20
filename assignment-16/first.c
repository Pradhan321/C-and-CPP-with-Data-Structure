#include<stdio.h>
void natural(int);
void natural_reverse(int );
void odd_natural(int );
void odd_natural_rev(int );
void square(int );
void decimal_to_binary(int );
void octal_to_decimal(int );
void reverse_number(int );
int main(){
int x;
printf("Enter a number : ");
scanf("%d",&x);
// natural(x);
// natural_reverse(x);
// odd_natural(x);
// odd_natural_rev(x);
// square(x);
// binary_to_decimal(x);
// octal_to_decimal(x);
reverse_number(x);
}
void natural(int n)
{
  if(n>0)
  natural(n-1);
  printf("%d ",n);
}
void natural_reverse(int n)
{
  if(n>0)
  printf("%d ",n);
  natural_reverse(n-1);
}
void odd_natural(int n)
{
  if(n>0)
  
  odd_natural(n-1);
  if(n%2!=0)
  {
  printf("%d ",n);
  }

}
void odd_natural_rev(int n)
{
  if(n>0)
  {
  if(n%2!=0)
  {
  printf("%d ",n);
  }
  odd_natural_rev(n-1);
}
}
void square(int n)
{

  if(n>0)
  square(n-1);
  printf("%d ",n*n);

}

void decimal_to_binary(int n)
{
 if(n>0)
 decimal_to_binary(n/2);
 printf("%d ",n%2);
}
void octal_to_decimal(int n)
{
 if(n>2)
 octal_to_decimal(n/8);
 printf("%d",n%8);
}
void reverse_number(int n)
{
if(n>0)
{
printf("%d",n%10);
reverse_number(n/10);
}

}