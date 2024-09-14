#include <stdio.h>
#include <limits.h>

int main() {
    int n;
    scanf("%i", &n);
    int min_even = INT_MAX;
    int max_odd = INT_MIN;
    for(int i = 0; i < n; ++i){
       int a;
       scanf("%i", &a);
       if (a % 2 == 0 && a < min_even){
        min_even = a;
       }
       if (a % 2 == 1 && a > max_odd){
        max_odd = a;
       }
    }
   if (min_even == INT_MAX && max_odd != INT_MIN){
    printf("None %i\n", max_odd);
   }
   if (min_even != INT_MAX && max_odd == INT_MIN){
    printf("%i None\n", min_even);
   }
   if (min_even == INT_MAX && max_odd == INT_MIN){
    printf("None None\n");
   }
   if (min_even != INT_MAX && max_odd != INT_MIN){
    printf("%i %i\n", min_even, max_odd);
   }
}