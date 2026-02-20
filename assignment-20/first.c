#include<stdio.h>
void f1();
void f2();
void f3();
int main(){
  
// f1();
// f2();
f3();
  return 0;
}

void f1()
{
 int arr1[3][3],arr2[3][3],arr3[3][3],i,j;
printf("Enter 9 numbers of first matrices : ");
for(i=0;i<=2;i++)
{
  for(j=0;j<=2;j++)
  {
    scanf("%d",&arr1[i][j]);
  }
}
printf("Enter 9 numbers of second matrices : ");
 for(i=0;i<=2;i++)
 {
  for(j=0;j<=2;j++)
  {
    scanf("%d",&arr2[i][j]);
  }
 }
 for(i=0;i<=2;i++)
 {
  for(j=0;j<=2;j++)
  {
    arr3[i][j]=arr1[i][j]+arr2[i][j];
  }
 }
 printf("Sum of two matrices are : \n");
 for(i=0;i<=2;i++)
 {
  for(j=0;j<=2;j++)
  {
    printf("%d ",arr3[i][j]);
  }
  printf("\n");
 }

}
void f2()
{
 int arr1[3][3],arr2[3][3],arr3[3][3],i,j,sum,k;
printf("Enter 9 numbers of first matrices : ");
for(i=0;i<=2;i++)
{
  for(j=0;j<=2;j++)
  {
    scanf("%d",&arr1[i][j]);
  }
}
printf("Enter 9 numbers of second matrices : ");
 for(i=0;i<=2;i++)
 {
  for(j=0;j<=2;j++)
  {
    scanf("%d",&arr2[i][j]);
  }
 }
 for(i=0;i<=2;i++)
 {
  for(j=0;j<=2;j++)
  {
    for(k=0,sum=0;k<=2;k++)
    {
      
      sum=sum+arr1[i][k]*arr2[k][j];
    }
    arr3[i][j]=sum;
  }
 }
 printf("product of two matrices are : \n");
 for(i=0;i<=2;i++)
 {
  for(j=0;j<=2;j++)
  {
    printf("%d ",arr3[i][j]);
  }
  printf("\n");
 }

}
void f3()
{
  int arr[3][3],i,j,k,temp;
  printf("Enter the value of matrix : ");
  for(i=0;i<=2;i++)
  {
    for(j=0;j<=2;j++)
    {
      scanf("%d",&arr[i][j]);
    }
  }
  printf("Your original matrix :- \n");
  for(i=0;i<=2;i++)
  {
    for(j=0;j<=2;j++)
    {
      printf("%d ",arr[i][j]);
    }
    printf("\n");
  }
 for(i=0,j=1,k=0;k<3;k++)
 {
  temp=arr[i][j];
  arr[i][j]=arr[j][i];
  arr[j][i]=temp;
  if(j-i==1)
  {
    j++;
  }
  else{
    i++;
  }
 }
 printf("Here is your transpose matrix : \n");
  for(i=0;i<=2;i++)
  {
    for(j=0;j<=2;j++)
    {
      printf("%d ",arr[i][j]);
    }
    printf("\n");
  }
}