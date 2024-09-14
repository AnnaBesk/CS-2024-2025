#include <stdio.h>
#include <limits.h>

int main() {
    int a, b;
    int max = INT_MIN;
    int sample;

    scanf("%i %i", &a, &b);
    for(int i = a; i <= b; ++i){
      int count = 0;
      int n = i;
      while (n != 1){
         count += 1;
         if (n % 2 == 0){
            n = n / 2;
         }
         else{
            n = 3 * n + 1;
         }
      }
      if (max < (count + 1)){
         max = count + 1;
         sample = i;
      }
   }
    printf("%i %i \n", sample, max);
}