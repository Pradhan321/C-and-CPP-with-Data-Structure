#include<stdio.h>
int LCM(int ,int );
int HCF(int ,int );
int Prime(int);
int NextPrime(int);
void first_n_Prime(int);
void given_number_between_Prime(int ,int);
void fibonacci(int);
void print_pascal(int);
int combi(int ,int );
int fact(int );
int main(){
  // int x,y;
  int x;
  printf("Enter a number : ");
  scanf("%d",&x);
  // printf("Enter two number : ");
  // scanf("%d %d",&x,&y);
  // printf("%d \n",LCM(x,y)) ;
  // printf("%d",HCF(x,y)) ;
  // printf("%d",Prime(x)) ;
  // printf("%d",NextPrime(x)) ;
  // first_n_Prime(x) ;
  // given_number_between_Prime(x,y);
  // fibonacci(x);
  print_pascal(x);
  return 0;
}

int LCM(int a,int b)
{
  int lcm=1,flag=0;
  for(int i=2;i<=(a>b?a:b);)
  {
    if(a%i==0)
    {
      a/=i;
      flag=1;
    }
    if(b%i==0)
    {
      b/=i;
      flag=1;
    }
    if(flag==1)
    {
      lcm=lcm*i;
      flag=0;
    }
    else{
      i++;
    }

  }
  return lcm;
}
int HCF(int a,int b)
{
  int hcf;
for(int i=1;i<=(a>b?a/2:b/2);i++)
{
  if(a%i==0&&b%i==0)
  {
    hcf=i;
  }
}
return hcf;
}

int Prime(int a)
{
  int i;
  for( i=2;i<a;i++)
    if(a%i==0)
      return 0;
  return 1;
}

int NextPrime(int a)
{

  while(!Prime(++a));
  return a;
  
}
void first_n_Prime(int a)
{
  int i;
  for(i=2;i<=a;i++)
  {
    if(Prime(i))
      printf("%d \n",i);
    
  }
}
void given_number_between_Prime(int a,int b)
{
  
  int i;
  for(i=(a<b?a:b)+1;i<(a>b?a:b);i++)
  {
    if(Prime(i))
      printf("%d \n",i);
    
  }
}
void fibonacci(int a)
{
  int temp,f=0,f1=1;
  printf("%d %d ",f,f1);
  for(int i=1;i<a-1;i++)
  {
    temp=f1;
    f1=f1+f;
    f=temp;
    printf("%d ",f1);
  }
}
void print_pascal(int n)
{
  int r;
  for (int i = 1; i <= n; i++)
  {
    r=0;
    for (int j = 1; j <= n; j++)
    {
      if (i == j || j <= n - i || i * 2 == j || i / 2 == j)
      {
        printf(" ");
      }
      else
      {
        printf("%2d",combi(i-1,r++));
      }
    }
    int t;
    t=0;
    for (int j = 1; j <= n-1; j++)
    {
      if (i == j || i < j || i * j == 3 || i == 4 && j == 2)
      {
        printf(" ");
      }
      else
      {
        printf("%2d",combi(i,t++));
      }
    }
    printf("\n");
  }
}
int combi(int n,int r)
{
 int ans=fact(n)/(fact(r)*fact(n-r));
 return ans;
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
