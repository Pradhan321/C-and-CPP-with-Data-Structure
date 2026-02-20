#include<stdio.h>
int main(){
  int n,d,rev=0;
  printf("Enter a number : ");
  scanf("%d",&n);
  while (n>0)
  {
    d=n%10;
    rev=rev*10+d;
    n=n/10;
    
   
  }
 printf("rev is %d",rev);
  return 0;
}

//prime number
// #include<stdio.h>
// int main(){
//   int n,i;
//   printf("Enter a number : ");
//   scanf("%d",&n);
//   for ( i = 2; i<n; i++)
//   {
    
//     if (n%i==0)
//     {
//       break;
//     }
//   }
//     if(n==i)
//     printf("%d is a prime number",n);
//     else
//     printf("%d Not a prime number",n);
    
    
    
    
  
//   return 0;
// }

//lcm
// #include<stdio.h>
// int main(){
//   int a ,b ,i,lcm=1,flag=0,c,d;
//   printf("Enter two number ");
//   scanf("%d %d",&a,&b);
//   c=a;
//   d=b;
//   for (i=2;a>1||b>1;)
//   {
//     if(a%i==0){
//       a=a/i;
//       flag=1;
//     }
//     if(b%i==0)
//     {
//       b=b/i;
//       flag=1;
//     }
//     if(flag==1)
//     {
//       lcm=lcm*i;
//       flag=0;
//     }
//     else{
//       i++;
//     }
//   }
  
  
//   printf("Lcm of %d and %d is : %d ",c,d,lcm);
//   return 0;
// }