#include<stdio.h>
#include<string.h>
void f1()
{
  int len;
  char str[50];
  printf("Enter a string : ");
  fgets(str,50,stdin);
  str[strlen(str)-1]='\0';
  for(len=0;str[len];len++);
  printf("String length is : %d",len);
  
}
void f2()
{
  int len,count=0;
  char str[50],st;
  printf("Enter a string : ");
  fgets(str,50,stdin);
  str[strlen(str)-1]='\0';
  for(len=0;str[len];len++);
  printf("Enter the character of which you want to konw the occurance : ");
  scanf("%c",&st);
  for(int i=0;i<len;i++)
  {
    if(str[i]==st)
    {
      count++;
    }
    
  }
  printf("Occurence of your letter is : %d",count);
  
}
void f3()
{
   int len,count=0;
  char str[50];
  printf("Enter a string : ");
  fgets(str,50,stdin);
  str[strlen(str)-1]='\0';
  for(len=0;str[len];len++);
 
  for(int i=0;i<len;i++)
  {
    if(str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u')
    {
      count++;
    }
    
  }
  printf("total vowels : %d",count);
}
void f4()
{
   int len,count=0;
  char str[50];
  printf("Enter a string : ");
  fgets(str,50,stdin);
  str[strlen(str)-1]='\0';
  for(len=0;str[len];len++);
 
  for(int i=0;i<len;i++)
  {
    if(str[i]!='a'&&str[i]!='e'&&str[i]!='i'&&str[i]!='o'&&str[i]!='u')
    {
      count++;
    }
    
  }
  printf("total consonants : %d",count);
}
void f5()
{
   int len,count=0;
  char str[50];
  printf("Enter a string : ");
  fgets(str,50,stdin);
  str[strlen(str)-1]='\0';
  for(len=0;str[len];len++);
 
  for(int i=0;i<len;i++)
  {
    if(str[i]==' ')
    {
      count++;
    }
    
  }
  printf("total space : %d",count);
}
void f6()
{
   int len,count=0;
  char str[50];
  printf("Enter a string : ");
  fgets(str,50,stdin);
  str[strlen(str)-1]='\0';
  for(len=0;str[len];len++);
 
  for(int i=0;i<len;i++)
  {
    if(str[i]>='A'&&str[i]<='Z')
    {
      str[i]=str[i]+32;
    }
    
  }
  printf("updated string: %s",str);
}
void f7()
{
   int len,count=0;
  char str[50],temp;
  printf("Enter a string : ");
  fgets(str,50,stdin);
  str[strlen(str)-1]='\0';
  for(len=0;str[len];len++);
 
  for(int i=0;i<len/2;i++)
  {
    
   temp=str[i];
   str[i]=str[len-1-i];
   
   str[len-1-i]=temp;
   
    
  }
  printf("updated string: %s",str);
}
void f8()
{
   int len,alpha_count=0,digit_count=0,other_count=0;
  char str[50],temp;
  printf("Enter a string : ");
  fgets(str,50,stdin);
  str[strlen(str)-1]='\0';
  for(len=0;str[len];len++);
 
  for(int i=0;i<len;i++)
  {
    
   switch(str[i])
   {
    case 'a'...'z':
    case 'A'...'Z':
      alpha_count++;
      break;
    case '0'...'9':
      digit_count++;
      break;
    default:
      other_count++;

   }
    
  }
  printf("alphabats : %d",alpha_count);
  printf("\ndigits : %d",digit_count);
  printf("\nspecial char : %d",other_count);
}
int main(){
  // f1();
  // f2();
  // f3();
  // f4();
  // f5();
  // f6();
  // f7();
  f8();
  return 0;
}