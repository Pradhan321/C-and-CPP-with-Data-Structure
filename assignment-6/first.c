#include<stdio.h>
int main(){
  int x;
  printf("Enter a number : ");
  scanf("%d",&x);
  if(x/100!=0&&x/100<=9){
    printf("%d is a three digit number",x);
  }
  else{
    printf("Not a three digit number");
  }
  return 0;
}