#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void make_combination(char str[],int r)
{
  int i,j,k;
  int l=strlen(str);
  char temp[r+1];
  for(i=0;i<=l-r;i++)
  {
    temp[0]=str[i];
    for(j=i+1;j<=l-r+1;j++)
    {
      temp[1]=str[j];
      for(k=j+1;k<=l-r+2;k++)
      {
        temp[2]=str[k];
        temp[3]='\0';
        printf("%s\n",temp);
      }
    }
  }

}

int main()
{
  char str[]="ABCDE";
  make_combination(str,3);
  printf("\n");
}