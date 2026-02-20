// #include<stdio.h>
// int main(){
//   int a ,b ,c;
//   printf("Enter three numbers : ");
//   scanf("%d %d %d",&a,&b,&c);
//   if (a>b&&a>c)
//   {
//     printf("%d is greater",a);
//     /* code */
//   }
//   else if (b>a&&b>c)
//   {
//     printf("%d is greater",b);
//     /* code */
//   }
//   else{
//     printf("%d is greater",c);
//   }
  
  
//   return 0;
// }

#include<stdio.h>
int main(){
  int x,i=1;
  printf("Enter a number : ");
  scanf("%d",&x);
  while (i<=x)
  {
    /* code */
    printf("%d \n",i);
    i++;
  }
  
  return 0;
}