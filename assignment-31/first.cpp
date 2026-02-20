#include <iostream>
#include <string.h>
using namespace std;

void sortArray(int arr[], int size, bool asending = false)
{
  for (int i = 0; i < size - 1; i++)
  {
    for (int j = i + 1; j < size; j++)
    {
      if (asending)
      {
        if (arr[i] > arr[j])
        {
          int temp = arr[i];
          arr[i] = arr[j];
          arr[j] = temp;
        }
      }
      else
      {
        if (arr[i] < arr[j])
        {
          int temp = arr[i];
          arr[i] = arr[j];
          arr[j] = temp;
        }
      }
    }
  }
  for (int i = 0; i < size; i++)
  {
    cout << arr[i] << " ";
  }
}
void sortcharArray(char *arr[], int size, bool asending = true)
{
  int i, r;
  char temp[20];
  for (r = 1; r <= size - 1; r++)
  {
    for (i = 0; i <= size - r - 1; i++)
    {
      if (asending)
      {
        if (strcmp(arr[i], arr[i + 1]) > 0)
        {
          strcpy(temp, arr[i]);
          strcpy(arr[i], arr[i + 1]);
          strcpy(arr[i + 1], temp);
        }
      }
      else
      {
        if (strcmp(arr[i], arr[i + 1]) < 0)
        {
          strcpy(temp, arr[i]);
          strcpy(arr[i], arr[i + 1]);
          strcpy(arr[i + 1], temp);
        }
      }
    }
  }
  for (int i = 0; i < size; i++)
  {
    cout << arr[i] << " ";
  }
}
void rotateArray(int arr[], int size, int n, int d)
{
  if (d == -1)
  {
    while (n > 0)
    {
      int temp;
      temp = arr[0];
      for (int i = 1; i < size; i++)
      {
        arr[i - 1] = arr[i];
      }
      arr[size - 1] = temp;
      n--;
    }
  }
  else
  {
    while (n > 0)
    {
      int temp;
      temp = arr[size - 1];
      for (int i = size - 1; i > 0; i--)
      {
        arr[i] = arr[i - 1];
      }
      arr[0] = temp;
      n--;
    }
  }
}
int LCM(int a,int b,int c)
{
  int L;
  for(L=a>b?a>c?a:c:b>c?b:c;L<=a*b*c;L++)
  {
    if(L%a==0&&L%b==0&&L%c==0)
    {
      return L;
    }
  }
  return 1;
}
int HCF(int a,int b)
{
  int hcf=1;
  for(int i=2;i<=(a>b?a:b);i++)
  {
    if(a%i==0&&b%i==0)
    {
      hcf=i;
    }
  }
  return hcf;
}
bool isPrime(int x)
{
  if(x<2)return false;
  for(int i=2;i<=x/2;i++)
  {
    if(x%i==0) return false;
  }
  return true;
}
void primefactor(int num)
{

  for (int i = 2; i <= num; i++)
  {
    if (num % i == 0 && isPrime(i))
    {

      cout << i << endl;
    }
  }
}

void substring(int startIndex,int endIndex=-1,char str[]);
void substring(int startIndex,int endIndex,char str[])
{
  int len=strlen(str);
  if(endIndex==-1)
  {
    endIndex=len;
  }
  if(startIndex<0||startIndex>=len||endIndex<0||endIndex>=len)
  {
    cout<<"Invalid index";
    return;
  }
  for(int i=startIndex;i<=endIndex;i++)
  {
    cout<<str[i]<<" ";
  }
}