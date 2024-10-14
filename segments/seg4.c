#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float* get_geometric_progression(float a, float r, int n) {
    float* progression = (float*)malloc(n * sizeof(float));
    
    for (int i = 0; i < n; i++) {
        progression[i] = a * (float)pow(r, i);
    }
    return progression;
}

int main() {
    int n = 10; 
    float a = 1; 
    float r = 3;

    float* progression = get_geometric_progression(a, r, n);

    printf("Первые %d степени тройки:\n", n);
    for (int i = 0; i < n; i++) {
        printf("3^%d = %.2f\n", i, progression[i]);
    }
    free(progression);
}