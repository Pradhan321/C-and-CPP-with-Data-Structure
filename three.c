// #include<stdio.h>
// int main(){
//   int a=5, b=6;
//   printf("a=%d and b=%d",a,b);
//   return 0;
// }


// #include<stdio.h>
// int main(){
//   int i,n;
//   printf("Enter a number : ");
//   scanf("%d",&n);
//   for ( i = 2; i < n; i++)
//   {
//     if (n%i==0)
//     {
//       break;
//     }
//   }
//   if (i==n)
//   {
//     printf("Prime number");
//   }
//   else
//   {
//     printf("Not a prime number");
//   }
  
  
  
// }

// #include<stdio.h>
// int main(){
//   int i,a,b;
//   printf("Enter two number : ");
//   scanf("%d %d",&a,&b);
//   for (i=a>b?a:b; i <=(a*b); i++)
//   {
//     if(i%a==0&&i%b==0)
//     {
//       break;
//     }
//   }
//   printf("Lcm of %d and %d is : %d",a,b,i);
  
// }

// #include<stdio.h>
// int main(){
//   int count=1,i;
//   char str[10]={'B','H','O','P','A','L'};
//   for( i=0;str[i];i++)
//   {
//     count++;
//   }
//   printf("%d",i);
// }

#include<stdio.h>
int input(int **q,int n,int size[]);
int display(int *,int );
int main(){
  int a[5],b[6],c[3],d[4];
  int size[]={5,6,3,4};
  int *p[4],i;
  p[0]=a;
  p[1]=b;
  p[2]=c;
  p[3]=d;
  input(p,4,size);
  for(i=0;i<4;i++)
  {
  display(p[i],size[i]);
  }
  printf("\n");
  return 0;
}

int input(int **q,int n,int size[])
{
  int i;
  for(i=0;i<n;i++)
  {
    printf("Enter %d numbers :- \n ",size[i]);
    for(int j=0;j<size[i];j++)
    {
      scanf("%d",*(q+i)+j);
    }
    printf("\n");
  }
}
int display(int *p,int size)
{
  int i;
  for(i=0;i<size;i++)
  {
    printf("%d ",*(p+i));
    
  }
  printf("\n");
}