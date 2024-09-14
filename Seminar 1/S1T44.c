#include <stdio.h>
#include <limits.h>

int main() {
    int n;
    int max = INT_MIN;
    int min = INT_MAX;
    int c_mx = 0;
    int c_mn = 0;
    int count_mx = 0;
    int count_mn = 0;
    int prev;
    scanf("%i", &n);
    for(int i = 0; i < n; ++i){
       int a;
       scanf("%i", &a);

       if(max < a){
        max = a;
        c_mx += 1;
       }
       else if(max == a){
        count_mx += 1;
       }

       if(min > a){
        min = a;
        c_mn += 1;
       }
       else if(min == a){
        count_mn += 1;
       }
    }
   if (c_mx == n){
        printf("Increasing \n");
   }
   else if (c_mn == n){
    printf("Decreasing \n");
   }
   else if (count_mn == n - 1 || count_mx == n - 1){
    printf("Equal \n");
   }
   else{
    printf("None \n");
   }
}