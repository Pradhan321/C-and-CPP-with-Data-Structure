#include <stdio.h>
#include <math.h>
int main()
{
  int  n;
  printf("Enter a number : ");
  scanf("%d", &n);
  for(int i=1;i<=n;i++)
  {
    double  sum = 0;
  int temp = i;
  int c=0;
  
  while (temp > 0)
  {

    temp = temp / 10;
    c++;
  }
  temp = i;
  while (temp > 0)
  {
    int d = temp % 10;
    sum = sum + pow(d, c);
    temp = temp / 10;
  }
  if (i== sum)
  {
    printf("armstrong number are : %d \n",i);
  }
}
  return 0;
}