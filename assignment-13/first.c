#include<stdio.h>
void display_Date(int);
void calculator();
int main(){
  // printf("Enter a month number : ");
  // scanf("%d",&x);
  // display_Date(x);
  calculator();
  
}
void display_Date(int n)
{
  
  switch(n){
    case 1:
    printf("Its January and total days in jan is 31.");
    break;
    
    case 2:
    printf("Its feb and total days in feb is 31.");
    break;
    case 3:
    printf("Its march and total days in march is 31.");
    break;
    case 4:
    printf("Its april and total days in april is 31.");
    break;
    case 5:
    printf("Its may and total days in may is 31.");
    break;
    case 6:
    printf("Its june and total days in june is 31.");
    break;
    case 7:
    printf("Its july and total days in july is 31.");
    break;
    case 8:
    printf("Its aug and total days in aug is 31.");
    break;
    case 9:
    printf("Its sep and total days in sep is 31.");
    break;
    case 10:
    printf("Its oct and total days in oct is 31.");
    break;
    case 11:
    printf("Its nov and total days in nov is 31.");
    break;
    case 12:
    printf("Its dec and total days in dec is 31.");
    break;
    default:
    printf("Invalid choice");
  }
}
void calculator()
{
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
}