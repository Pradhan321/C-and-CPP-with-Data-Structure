#include <stdio.h>
void p1();
void p2();
void p3();
void p4();
void p5();
void p6();
void p7();
void p8();
void p9();
void p10();
int main()
{
  // p1();
  // p2();
  // p3();
  // p4();
  // p5();
  // p6();
  // p7();
  // p8();
  // p9();
  p10();
  return 0;
}
void p1()
{
  for (int i = 1; i <= 3; i++)
  {
    for (int j = 1; j <= 3; j++)
    {
      if (j <= 3 - i)

        printf(" ");

      else
        printf("*");
    }

    for (int j = 1; j <= 2; j++)
    {
      if (i <= j)

        printf(" ");

      else
        printf("*");
    }
    printf("\n");
  }
}
void p2()
{
  for (int i = 1; i <= 4; i++)
  {
    for (int j = 1; j <= 4; j++)
    {
      if (i > j)
      {
        printf(" ");
      }
      else
      {
        printf("*");
      }
    }
    for (int j = 3; j >= i; j--)
    {
      printf("*");
    }
    printf("\n");
  }
}
void p3()
{
  for (int i = 1; i <= 4; i++)
  {
    for (int j = 1; j <= 4; j++)
    {
      if (i == j || j <= 4 - i || i * 2 == j || i / 2 == j)
      {
        printf(" ");
      }
      else
      {
        printf("*");
      }
    }
    for (int j = 1; j <= 3; j++)
    {
      if (i == j || i < j || i * j == 3 || i == 4 && j == 2)
      {
        printf(" ");
      }
      else
      {
        printf("*");
      }
    }
    printf("\n");
  }
}
void p4()
{
  for (int i = 1; i <= 4; i++)
  {
    int num = 1;
    for (int j = 1; j <= 4; j++)
    {
      if (j <= 4 - i)
      {
        printf(" ");
      }
      else
      {
        printf("%d", num);
        num++;
      }
    }

    int num1 = i - 1;
    for (int j = 1; j <= i - 1; j++)
    {
      printf("%d", num1);
      num1--;
    }

    printf("\n");
  }
}
void p5()
{

  for (int i = 1; i <= 4; i++)
  {
    char ch = 'A';
    for (int j = 1; j <= 7; j++)
    {
      if (i > j || i + j >= 9)
      {
        printf(" ");
      }
      else
      {
        printf("%c", ch);
        ch++;
      }
    }

    printf("\n");
  }
}

void p6()
{

  for (int i = 1; i <= 4; i++)
  {
    char ch = 'A';
    for (int j = 1; j <= 7; j++)
    {
      if (i > j || i + j >= 9)
      {
        printf(" ");
      }
      else
      {
        printf("%c", ch);
        j < 4 ? ch++ : ch--;
      }
    }

    printf("\n");
  }
}

void p7()
{
  int x, k;
  for (int i = 1; i <= 5; i++)
  {
    x = 1;
    k = 1;
    for (int j = 1; j <= 9; j++)
    {
      if (j >= 6 - i && j <= 4 + i)
      {
        if (k)
        {
          printf("%d", x);
          j < 5 ? x++ : x--;
        }
        else
        {
          printf(" ");
          if (j == 5)
            x--;
        }
        k = 1 - k;
      }
      else
        printf(" ");
    }
    printf("\n");
  }
}

void p8()
{

  for (int i = 1; i <= 4; i++)
  {

    for (int j = 1; j <= 7; j++)
    {

      if (j <= 5 - i || j >= 3 + i)
      {
        printf("*");
      }
      else
      {
        printf(" ");
      }
    }

    printf("\n");
  }
}

void p9()
{
  for (int i = 1; i <= 4; i++)
  {
    int x = 1;

    for (int j = 1; j <= 7; j++)
    {

      if (j <= 5 - i || j >= 3 + i)
      {
        printf("%d", x);
        j < 4 ? x++ : x--;
      }
      else
      {
        printf(" ");
        if (j == 4)
          x--;
      }
    }

    printf("\n");
  }
}
void p10()
{
  for (int i = 1; i <= 4; i++)
  {
    char ch = 'A';

    for (int j = 1; j <= 7; j++)
    {

      if (j <= 5 - i || j >= 3 + i)
      {
        printf("%c", ch);
        j < 4 ? ch++ : ch--;
      }
      else
      {
        printf(" ");
        if (j == 4)
          ch--;
      }
    }

    printf("\n");
  }
}