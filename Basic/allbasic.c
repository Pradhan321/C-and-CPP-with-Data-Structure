// #include<stdio.h>
// int main(){
//   int r;
//   printf("Enter the radius of the circle : ");
//   scanf("%d",&r);

//   printf("Area of circle is %f having the radius %d",3.14*r*r,r);
//   return 0;
// }

// #include<stdio.h>
// int main(){
//   int d,m,y;
// printf("Enter the date ");
// scanf("%d/%d/%d",&d,&m,&y);
// printf("Day - %d , Month - %d , Year - %d",d,m,y);
// return 0;
// }


#include<stdio.h>
int main()
{
  int a=5,b=6;
  int x;
  x=a;
  a=b;
  b=x;
  printf("%d %d",a,b);
  return 0;
}