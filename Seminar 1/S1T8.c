#include <stdio.h>

int main()
{
  int a, b, c;

  scanf("%i %i %i", &a, &b, &c);
  int n = a;

  while (n <= b)
  {
    if (n % c == 0)
    {
      printf("%i ", n);
      n += c;
    }
    else
    {
      n += 1;
    }
  }
  printf("\n");
}