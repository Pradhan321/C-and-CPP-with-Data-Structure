// #include<stdio.h>
// #include<string.h>
// int main(){
  
//   int math_marks,eng_marks,com_marks,hin_marks,sci_marks;
 
//   printf(" maths marks : ");
//   scanf("%d",&math_marks);
//   printf(" English marks : ");
//   scanf("%d",&eng_marks);
//   printf(" computer marks : ");
//   scanf("%d",&com_marks);
//   printf(" hindi marks : ");
//   scanf("%d",&hin_marks);
//   printf(" science marks : ");
//   scanf("%d",&sci_marks);

//   if(math_marks<=100&&eng_marks<=100&&com_marks<=100&&hin_marks<=100&&sci_marks<=100)
//   {
//     if(math_marks>=33&&eng_marks>=33&&com_marks>=33&&hin_marks>=33&&sci_marks>=33)
//     {
      
//       printf(" is passed in all subject with marks of math %d english %d computer %d hindi %d science %d",math_marks,eng_marks,com_marks,hin_marks,sci_marks);

//     }
//     else{
//       printf("you are not pass in all subject");
//     }
//     int total=math_marks+eng_marks+com_marks+hin_marks+sci_marks;
//     printf("your total is %d ",total);
//   }
//   return 0;
// }
// #include<stdio.h>
// int main(){
//   int x,i;
//   for( i=1;i<=3;i++){
//     printf("Enter a number : ");
//     scanf("%d",&x);
//     if(x%2==0)
//       break;  
//   }
//   if(i==4){
//   printf("you loose the game");
//   }
//   else{
//     printf("you won the game");
//   }

//   return 0;
// }

// #include<stdio.h>
// int main(){
//   int x,sum=0;
//   printf("Enter a number : ");
//   while (1)
//   {
//     scanf("%d",&x);
//     if(x==0)
//       break;
//     sum=sum+x;
//   }
//   printf("sum is %d",sum);
//   return 0;
// }

#include<stdio.h>
int main(){
  for(int i=5;i>=1;i--)
  {
    for(int j=i+1;j>=1;j--)
    {
      printf("* ");
      
    }
    printf("\n");
  }
  return 0;
}