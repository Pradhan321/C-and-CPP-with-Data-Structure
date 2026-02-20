#include<stdio.h>
int sum_natural(int);
int sum_odd_natural(int );
int sum_even_natural(int );
int sum_square(int);
int sum_digits(int);
int factorial(int );
int power(int,int);
int HCF(int ,int );
int count_digits(int);
void print_fibonaci(int);
int fibonacci(int);
void natural_reverse(int );
void odd_natural(int );
void odd_natural_rev(int );
void square(int );
void decimal_to_binary(int );
void octal_to_decimal(int );
void reverse_number(int );
int main(){
int x,y;
// printf("Enter a number : ");
printf("Enter two number : ");
scanf("%d %d",&x,&y);
// scanf("%d",&x);
// printf("%d",sum_natural(x));
// printf("%d",sum_odd_natural(x));
// printf("%d",sum_even_natural(x));
// printf("%d",sum_square(x));
// printf("%d",sum_digits(x));
// printf("%d",factorial(x));
// printf("%d",HCF(x,y));
// print_fibonaci(x);
// printf("%d",count_digits(x));
printf("%d",power(x,y));
// natural_reverse(x);
// odd_natural(x);
// odd_natural_rev(x);
// square(x);
// binary_to_decimal(x);
// octal_to_decimal(x);
// reverse_number(x);
}
int sum_natural(int n)
{
 if(n==1)
 return 1;
 int s=n+sum_natural(n-1);
 return s;
}
int sum_odd_natural(int n)
{
  if(n==1)
    return 1;
  return (2*n-1)+sum_odd_natural(n-1);
}
int sum_even_natural(int n)
{
  if(n==1)
    return n+1;
  return (2*n)+sum_even_natural(n-1);
}
int sum_square(int n)
{
  if(n==1)
    return 1;
  return n*n+sum_square(n-1);
}
int sum_digits(int n)
{
  if(n==0)
    return 0;
    return (n%10)+sum_digits(n/10);
}
int factorial(int n)
{
  if(n==1)
    return 1;
  return n*factorial(n-1);
}
int HCF(int a,int b)
{
  if(a>b)
    if(a%b==0)
      return b;
    else
      return HCF(a%b,b);
  else
    if(b%a==0)
      return a;
    else
      return HCF(a,b%a);
  
}
void print_fibonaci(int n)
{
if(n==0)
{
  printf("%d ",n);
}
else{
  print_fibonaci(n-1);
  printf("%d ",fibonacci(n));
}
}

int fibonacci(int n){
if(n==0)
{
  return 0;
}
if(n==1)
{
  return 1;
}
return fibonacci(n-1)+fibonacci(n-2);
}
int count_digits(int n)
{
  if(n==0)
    return 0;
  return count_digits(n/10)+1;
}
int power(int x,int y)
{
  if(y==0)
  {
    return 1;
  }
  return x*power(x,y-1);
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