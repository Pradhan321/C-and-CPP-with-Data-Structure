#include<stdio.h>
void f1();
int main()
{
  f1();
return 0;
}
void f1(){
  int a;
  printf("Enter a value : ");
  scanf("%d",&a);
  if(a>0)
  {
    f1();
  }
  printf("%d",a);
}