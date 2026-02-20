#include<stdio.h>
#include<string.h>
#include<ctype.h>
void swap(int *a,int *b)
{
  int t=*a;
  *a=*b;
  *b=t;
}
void uppercase(char*str){
  for(int i=0;i<strlen(str);i++)
  {
    str[i]=toupper(str[i]);
  }
}
void lowercase(char *str){
 for(int i=0;i<strlen(str);i++)
  {
    str[i]=tolower(str[i]);
  }
}
void swap_string(char*s1,char*s2)
{
  char temp[50];
  strcpy(temp,s1);
  strcpy(s1,s2);
  strcpy(s2,temp);
}
int search_all_occurrences(char*str,char ch,int *arr)
{
  int i,k;
  for(i=0,k=0;str[i];i++)
  {
    if(str[i]==ch)
    {
      arr[k]=i;
      k++;
    }
  }
  return k;
  
}
void extract_string(char *str,int start_index,int end_index,char* result){
  for(int i=start_index;i<end_index;i++)
  {
    result[i-start_index]=str[i];
  }
  result[end_index-start_index]='\0';
}

void sort(int*ptr,int size)
{
  int r,i;
  for(r=1;r<size-1;r++)
  {
    for(i=0;i<size-1-r;i++)
    {
      if(ptr[i]>ptr[i+1])
      {
        int temp=ptr[i];
        ptr[i]=ptr[i+1];
        ptr[i+1]=temp;
      }
    }
  }
}

void merge(int*arr1,int size1,int*arr2,int size2,int*arr3)
{
  for(int i=0;i<size1;i++)
  {
    arr3[i]=arr1[i];
  }
  
  for(int i=size1,j=0;i<size1+size2&&j<size2;i++,j++)
  {
    arr3[i]=arr2[j];
  }
}


int f9(int a[],int n)
{
  int left=0,t;
  int loc=0;
  int right=n-1;
  while (left<right)
  {
    while(left<right&&a[loc]<=a[right])
      right--;
    if(left==right)
       break;
    t=a[loc];
    a[loc]=a[right];
    a[right]=t;
    loc=right;
    while(left<right&&a[left]<a[loc])
      left++;
    if(left==right)
       break;
    t=a[left];
    a[left]=a[loc];
    a[loc]=t;
    loc=left;
    
  }
  return loc;

  
}
int highestMarks(int**ptr,int n,int size[])
{
  int max=ptr[0][0];
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<size[i];j++)
    {
      if(max<ptr[i][j])
      {
        max=ptr[i][j];
      }
    }
  }
  return max;
}
int main()
{
  // int x=4,y=5;
  // printf("x is %d and y is %d",x,y);
  // swap(&x,&y);
  // printf("\nx is %d and y is %d",x,y);
  // char ch[]="Hello my name is Avinash";
  // uppercase(ch);
  
  //   printf("%s",ch);
  // lowercase(ch);
  //   printf("\n%s",ch);
  // char *f="Avinash";
  // char *s="kartik";
  // printf("%s and %s",f,s);
  // swap_string(&f,&s);
  // printf("\n%s and %s",f,s);
  // char *s = "Avinashsasfdafsdafsdasda";
  //   int array[10];
  //   int count = search_all_occurrences(s, 'a', array);

  //   for(int i = 0; i < count; i++)
  //   {
  //       printf("%d ", array[i]);
  //   }
  // int arr1[] = {1, 2, 3};
  //   int arr2[] = {4, 5, 6, 7};
  //   int size1 = sizeof(arr1) / sizeof(arr1[0]);
  //   int size2 = sizeof(arr2) / sizeof(arr2[0]);
  //   int arr3[size1 + size2];  // merged array

  //   // Call merge
  //   merge(arr1, size1, arr2, size2, arr3);

  //   // Print merged array
  //   printf("Merged array: ");
  //   for (int i = 0; i < size1 + size2; i++) {
  //       printf("%d ", arr3[i]);
  //   }
  //   printf("\n");

  int A[] = {85, 90, 78, 92, 88};   // Marks for Student A
    int B[] = {81, 69, 85, 80};   // Marks for Student B
    int C[] = {95, 89, 92, 100, 91, 56};   // Marks for Student C
    int D[] = {68, 70, 65};   // Marks for Student D
    int E[] = {88, 84, 79, 85, 90, 69, 98};   // Marks for Student E

int *ptr[5],size[]={5,4,6,3,7};
int hmarks;
ptr[0]=A;
ptr[1]=B;
ptr[2]=C;
ptr[3]=D;
ptr[4]=E;
hmarks=highestMarks(ptr,5,size);
printf("highest Marks : %d",hmarks);
  return 0;
}