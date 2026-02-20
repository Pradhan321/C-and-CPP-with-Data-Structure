#include <stdio.h>
float Area_Circle(int);
float simple_int(int, float, int);
int even_odd(int);
void natural(int);
void odd_natural(int);
int fact(int);
int find_digit(int,int);
void prime_factor(int);
int combi(int,int);
int perm(int,int);
int main()
{
  int x;
  int p, t;
  float r;
  // printf("Enter a number : ");
  // scanf("%d", &x);
  // printf("%d",even_odd(x));
  // natural(x);
  // odd_natural(x);
  // printf("%d",fact(x));
  // prime_factor(x); 
  // scanf("%d %f %d",&p,&r,&t);  
  printf("Enter the number and then enter the r : ");   
  scanf("%d %d",&p,&t);   
  printf("combination is %d \n",combi(p,t));
  printf("permutation is %d \n",perm(p,t));
  // printf("%d",find_digit(p,t));
  // printf("%f",Area_Circle(x));
  // printf("%f",simple_int(p,r,t));
}

float Area_Circle(int r)
{
  float a;
  a = 3.14 * r * r;
  return a;
}
float simple_int(int p, float r, int t)
{
  float si;
  si = (p * t * r) / 100;
  return si;
}
int even_odd(int n)
{
  return n % 2 == 0 ? 1 : 0;
}
void natural(int n)
{
  int i = 1;
  while (i <= n)
  {
    printf("%d \n", i);
    i++;
  }
}
void odd_natural(int n)
{
  int i = 1;
  while (i <= n)
  {
    if (i % 2 != 0)
    {
      printf("%d \n", i);
    }
  i++;
  }
}
int fact(int n)
{
  int f=1;
  while(n>1)
  {
    f=f*n;
    n--;
  }
  return f;
}

int find_digit(int number,int digit)
{
  int d;
  while(number>0)
  {
    d=number%10;
    if(d==digit)
    {
      return 1;
    }
    number=number/10;
  }
  return 0;
}

void prime_factor(int n)
{
  int i;
      for(i=2;i<=n;i++)
      {
        
    while(n%i==0)
    {
      printf("%d ",i);
      n=n/i;
    }
  
  }
}

int combi(int n,int r)
{
 int ans=fact(n)/(fact(r)*fact(n-r));
 return ans;
}
int perm(int n,int r)
{
int ans=fact(n)/fact(n-r);
 return ans;
}