#include <stdio.h>
#include <limits.h>

int main()
{
   int n;
   int max = INT_MIN;
   int count = 0;

   scanf("%i", &n);
   while (n != 1)
   {
      printf("%i ", n);
      count += 1;
      if (n > max)
      {
         max = n;
      }
      if (n % 2 == 0)
      {
         n = n / 2;
      }
      else
      {
         n = 3 * n + 1;
      }
   }
   printf("1 \n");
   printf("Length: %i, Max = %i \n", count + 1, max);
}