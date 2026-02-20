#include<stdio.h>
int smallest_in_array(int arr[],int size);
int greatest_in_array(int arr[],int size);
void sort_arr(int arr[],int size);
void rotate_arr_in_your_direction(int arr[],int size,int n,int d);
int occurence_of_first_duplicate(int arr[],int size);
int duplicate(int arr[],int size);
int main(){
int arr[11];
printf("Enter five numbers : ");
for(int i=0;i<11;i++)
{
  scanf("%d",&arr[i]);
}
// int d,n;
// printf("If you want to rotate in right direction then give 1 and if left then give -1 : ");
// scanf("%d",&d);
// printf("enter the number in which times you want to rotate the array : ");
// scanf("%d",&n);
// printf("smallest number is : %d ",smallest_in_array(arr,5));
// printf("\ngreatest number is : %d",greatest_in_array(arr,5));
// sort_arr(arr,5);
// rotate_arr_in_your_direction(arr,5,n,d);
// printf("occurence_of_first_duplicate is : %d ",occurence_of_first_duplicate(arr,8));
printf("%d",duplicate(arr,11));
}

int smallest_in_array(int arr[],int size)
{
  int min=arr[0];
  for(int i=1;i<size;i++)
  {
    if(arr[i]<min)
    {
      min=arr[i];
    }
  }
  return min;
}
int greatest_in_array(int arr[],int size)
{
int max=arr[0];
  for(int i=1;i<size;i++)
  {
    if(arr[i]>max)
    {
      max=arr[i];
    }
  }
  return max;
}
void sort_arr(int arr[],int size)
{
  for(int i=0;i<size-1;i++)
  {
    for(int j=0;j<size-i-1;j++)
    {
      if(arr[j]>arr[j+1])
      {
        int temp=arr[j];
        arr[j]=arr[j+1];
        arr[j+1]=temp;
      }
    }
  }
  for(int i=0;i<size;i++)
  {
    
    printf(" %d ",arr[i]);
  }
}
void rotate_arr_in_your_direction(int arr[],int size,int n,int d){
  if(d==1)
  {
    while(n)
    {
      int temp=arr[size-1];
      for(int i=size-2;i>=0;i--)
      {
        arr[i+1]=arr[i];
      }
      arr[0]=temp;
      n--;
    }
  }
  else{
    while(n)
    {
      int temp=arr[0];
      for(int i=1;i<size;i++)
      {
        arr[i-1]=arr[i];
      }
      arr[size-1]=temp;
      n--;
    }
  }
  printf("\n");
  for(int i=0;i<size;i++)
  {
    printf("%d ",arr[i]); 
  }
}
int occurence_of_first_duplicate(int arr[],int size)
{
  
  for(int i=0;i<size-2;i++)
  {
    
      if(arr[i]==arr[i+1])
      {
        return arr[i];
      }
  }
  
}

void swap(int arr[],int i1,int i2)
{
  int temp=arr[i1];
  arr[i1]=arr[i2];
  arr[i2]=temp;
}

// int duplicate(int arr[],int size)
// {
//   int count=0,i,j;
//   sort_arr(arr,size);
//  i=0;
//  j=1;
//  while(i<size-2)
//  {
//   if(arr[i]==arr[j])
//     count++;
//   while(arr[i]==arr[j])
//     j++;
//   i=j;
//   j=j+1;
//  }
int duplicate(int arr[], int size)
{
  int count = 0;
  for (int i = 0; i < size; i++)
  {
    for (int j = i + 1; j < size; j++)
    {
      if (arr[i] == arr[j])
      {
        count++;
        break;
      }
    }
  }
  return count;
}
