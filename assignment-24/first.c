#include <stdio.h>
#include <string.h>
#include <ctype.h>
void input(char s[][20], int n)
{
  printf("Enter %d strings : ", n);
  for (int i = 0; i < n; i++)
  {
    fgets(s[i], 20, stdin);
    s[i][strcspn(s[i], "\n")] = '\0'; // safely remove newline
  }
}
void count_vowels(char s[][20], int n)
{
  for (int i = 0; i < n; i++)
  {
    int count = 0;
    for (int j = 0; s[i][j] != '\0'; j++)
    {
      char ch = tolower(s[i][j]);
      if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
        count++;
    }
    printf("String %s has %d vowels.\n", s[i], count);
  }
}
void sort_city_name(char s[][20], int n)
{
  int r, i;
  char temp[20];
  for (r = 1; r < n; r++)
  {
    for (i = 0; i <= n - r - 1; i++)
    {
      if (strcmp(s[i], s[i + 1]) > 0)
      {
        strcpy(temp, s[i]);
        strcpy(s[i], s[i + 1]);
        strcpy(s[i + 1], temp);
      }
    }
  }
  for (int i = 0; i < n; i++)
  {
    printf("%s\n", s[i]);
  }
}
void string_to_words(char s[][20], int *n, char str[])
{
  int i=0,j=0;
  *n=0;
  while(str[i]!='\0')
  {
    if(str[i]!=' '&&str[i]!='\t'&&str[i]!='\n')
    {
      s[*n][j++]=str[i];// copy character into current word
    }
    else{
      if(j>0) 
      {
        s[*n][j]='\0';
        (*n)++;
        j=0;
      }
    }
    i++;
  }
  if(j>0)
  {
    s[*n][j]='\0';
    (*n)++;
  }
}
void remove_duplicate(char names[][20],int n){
  int i;
sort_city_name(names,n);
for(i=n-2;i>=0;i--){
  if(strcmp(names[i],names[i+1])==0)
  {
    names[i+1][0]='\0';
  }
}
sort_city_name(names,n);
}
void f4(){
 char str[] = "my name is avinash";
  char words[10][20]; // max 10 words, each up to 19 chars
  int count, i;

  string_to_words(words, &count, str);

  for (i = 0; i < count; i++)
  {
    printf("Word %d: %s\n", i + 1, words[i]);
  }
}
void f5(){
  char names[][20]={
    "Avinash",
    "Gagan",
    "Kartik",
    "Avinash",
    "Palawi",
    "Avinash",
    "Kartik"
  };
  remove_duplicate(names,7);
  for(int i=0;i<=6;i++)
  {
    printf("\n%s",names[i]);
  }
}
void carry_all_s(char cities[][20],int n)
{
  for(int i=0;i<n;i++)
  {
    int len=strlen(cities[i]);
    if(cities[i][len-1]=='s')
    {
      cities[i][0]='\0';
    }
  }
}

void f6(){
  char str[]="Hello guys my name is avinashs pradhan";
  char cities[4][20];
  carry_all_s(cities,7);
  for(int i=0;i<4;i++)
  {
    printf("\n%s",cities[i]);
  }
}
char max_freq_character(char str[][20],int n)
{
  char f[128]={0};
  int i,j,max,maxIndex=0;
  for(i=0;i<n;i++)
  {
    for(j=0;str[i][j];j++)
    {
      f[str[i][j]]++;
    }
  }
  max=f[0];
  for(int i=0;i<=127;i++)
  {
    if(max<f[i])
    {
      max=f[i];
      maxIndex=i;
    }
  }
  return maxIndex;
}
char* sorting(char s[])
{
  int i,r,t;
  char ch;
  for(r=1;r<=strlen(s)-1;r++)
  {
    for(i=0;i<=strlen(s)-1-r;i++)
    {
      if(s[i]>s[i+1])
      {
        t=s[i];
        s[i]=s[i+1];
        s[i+1]=t;
      }
    }
  }
  return s;
}
int is_anagram(char s1[],char s2[])
{
 return strcmp(sorting(s1),sorting(s2))==0;
}
void f7()
{
   char names[][20]={
    "Avinash",
    "Gagan",
    "Kartik",
    "Avinash",
    "Palawi",
    "Avinash",
    "Kartik"
  };
 char ch=max_freq_character(names,7);
 printf("max frequency character is : %c",ch);
}
int check_only_gmails(char email[],char pattern[]){
  int l=strlen(pattern);
  int i;
  if(strlen(email)>l)
  {
    for(i=strlen(email)-1;i>strlen(email)-l;i--)
        if(email[i]!=pattern[--l])
           return 0;
    return 1;
  
  }
  return 0;
}
int main()
{
  // int n;
  // printf("Enter the Number string that you want to store : ");
  // scanf("%d",&n);
  // getchar();  // FIX: consume newline left by scanf

  // char str[n][20];
  // input(str,n);
  // for(int i=0;i<n;i++)
  // {
  // printf("%s",str[i]);
  // if(i<n-1)printf(" ");
  // }
  // printf("\n");
  // count_vowels(str,n);
  // sort_city_name(str,n);
//  f4();
// f5();

// f6();
// f7();
// char s1[]="pear",s2[]="reap";
// if(is_anagram(s1,s2))
// {
//   printf("this string is anagram");
// }
// else{
//   printf("this string is not anagram");

// }
char emails[]={
  "example@gmail.com"
 
};
char p[]="gmail.com";
if(check_only_gmails(emails,p)){
  printf("this email is match the pattern");
}
else{

  printf("this email is not match the pattern");
}

  return 0;
}