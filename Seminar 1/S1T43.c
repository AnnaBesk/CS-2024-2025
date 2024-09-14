#include <stdio.h>
#include <limits.h>

int main() {
    int n;
    int count;
    scanf("%i", &n);
    int max = INT_MIN;
    for(int i = 0; i < n; ++i){
       int a;
       scanf("%i", &a);
       if (a > max){
        max = a;
        count = 0;
       }
       if (a == max){
        count += 1;
       }
    }
   
    printf("%i %i\n", max, count);
}