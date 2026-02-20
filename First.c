// #include<stdio.h>
// int main()
// {
// int a,b;
// printf("Enter two numbers a and b : ");
// scanf("%d %d",&a,&b);
// printf("%d", a+b);
// return 0;
// }

#include<stdio.h>
int main(){
  int x;
  int a,b;
  while(1)
  {
  printf("----Menu----\n");
  printf("1. Addition\n");
  printf("2. Multiplication\n");
  printf("3. Substraction\n");
  printf("4. Division\n");
  printf("5. Exit\n");
  printf("Enter your choice : ");
  scanf("%d",&x);
  if(x!=5)
  {
  printf("Enter two operands : ");
  scanf("%d %d",&a,&b);
  }
  switch (x)
  {
  case 1:
    printf("Addition of two number is : %d \n",a+b);
    break;
  case 2:
    printf("Multiplication of two number is : %d \n",a*b);
    break;
  case 3:
    printf("Substraction of two number is : %d \n",a-b);
    break;
  case 4:
    printf("Division of two number is : %d \n",a/b);
    break;
  case 5:
    printf("Exit from the application");
    return 0;
  default:
    printf("Invalid Choice");
  }
}
  return 0;
}