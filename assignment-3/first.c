// write a program to calculate the size of character constant

// #include<stdio.h>
// int main(){

//   printf("%d",sizeof('a'));
//   return 0;
// }

// #include<stdio.h>
// int main(){
//   char ch='A';
//   printf("%c",ch+1);
//   return 0;
// }


// #include<stdio.h>
// int main(){
//   int a=534;
//   printf("%d",a/10);
//   return 0;
// }

// #include<stdio.h>
// int main(){
//   int a=4,b=9;
//   a=b-a;
//   b=b-a;
//   a=a+b;
//   printf("%d %d",a,b);
//   return 0;
// }
// #include<stdio.h>
// int main(){
//   int a=4,b=9;
//   a=a*b;
//   b=a/b;
//   a=a/b;
//   printf("a=%d b=%d",a,b);

//   return 0;
// }

#include<stdio.h>
int main(){
  int a=4,b=9;
a=a^b;
b=a^b;
a=b^a;
  printf("a=%d b=%d",a,b);

  return 0;
}