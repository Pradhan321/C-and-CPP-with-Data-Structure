#include<stdio.h>
int main(){
  int cp,sp;
  printf("Enter the cost price of a product :- ");
  scanf("%d",&cp);
  printf("Enter the selling price of a product :- ");
  scanf("%d",&sp);
  if (sp>cp)
  {
    int profit=((sp-cp)*100)/cp;
    printf("Hoorahh....! Your profit percentage is %d",profit);
  }
  else if(cp>sp){
    int loss=((cp-sp)*100)/sp;
    printf("Ohh No...! Your loss percentage is %d",loss);
  }
  else{
    printf("There is no loss and no profit");
  }
  return 0;
}