#include<stdio.h>
int main(){
  int size=10,min,second_min;
  
  int arr[size];
  printf("Enter the %d of array : ",size);
  for(int i=0;i<size;i++)
  {
    scanf("%d",&arr[i]);
  }
  if(arr[0]<arr[1])
  {
  min=arr[0];
  second_min=arr[1];
  }
  else{
    min=arr[1];
    second_min=arr[0];
  }

  for(int i=2;i<size;i++)
  {
    if(arr[i]<min)
    {
      second_min=min;
      min=arr[i];
    }
    else{
      if(arr[i]<second_min)
        second_min=arr[i];
    }
  }
  
  printf("Second minimum number is %d",second_min);
}