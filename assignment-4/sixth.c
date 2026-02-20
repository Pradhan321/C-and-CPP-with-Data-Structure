#include<stdio.h>
int main(){
  int amount;
  float b=84.23;
  printf("Enter the amount in INR : ");
  scanf("%d",&amount);
  printf("Your %d is convert to %f",amount,amount*b);
  return 0;
}