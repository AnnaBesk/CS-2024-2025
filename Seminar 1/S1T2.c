#include <stdio.h>


int main() {
    int a, b, c;
    int control;
    scanf("%d %d %d", &a, &b, &c);
    if ((b - a == 1) && (c - b == 1)){
        printf("Consecutive ");
        control += 1;
    } 
    if ((a < b) && (b < c)){
        printf("Increasing ");
        control += 1;
    }
    if ((a > b) && (b > c)){
        printf("Decreasing ");
        control += 1;
    }
    if (a == b && b == c){
        printf("Equal ");
        control += 1;
    }
    if (control == 0){
        printf("None");
    }
    printf("\n");
}