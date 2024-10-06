#include <stdio.h>

void cube(float* px)
{
    *px = *px * *px * *px;
}

int main()
{
    float a;
    scanf("%f", &a);
    float *p = &a;
    cube(p);
    printf("%f \n", a);
}