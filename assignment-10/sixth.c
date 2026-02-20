// #include <stdio.h>
// int main()
// {
//   int n,n1, i;
//   printf("Enter a two number : ");
//   scanf("%d %d", &n1,&n);
//   for (i = n1+1; i < n; i++)
//   {
//     int isprime=1;
//     for (int j = 2; j <= i/2; j++)
//     {
//       if (i % j == 0)
//       {
//         isprime=0;
//         break;
//       }
//     }
//     if (isprime)
//     {
//       /* code */
//       printf("%d ",i);
//     }
    
//   }
 
//   return 0;
// }

#include <stdio.h>
int main()
{
  int n, i;
  printf("Enter a two number : ");
  scanf("%d",&n);
  n++;
  while(1)
  {
    int isprime=1;
    for (int j = 2; j <= n/2; j++)
    {
      if (n % j == 0)
      {
        isprime=0;
        break;
      }
    }
    if (isprime)
    {
      /* code */
      printf("%d ",n);
      break;
    }
    n++;
}
 
  return 0;
}