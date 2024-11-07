#include <stdio.h>
#include <math.h>

void circles(int x1, int y1, int r1, int x2, int y2, int r2)
{

    float pi4 = 0;
    float d2 = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
    float R2 = (r1 + r2) * (r1 + r2);
    float eps = 1e-5;

    if (fabs(d2 - R2) < eps)
        printf("Touch\n");
    else if (d2 < R2)
        printf("Intersect\n");
    else
        printf("Do not intersect\n");
}

int main()
{
    int x1, y1, r1;
    int x2, y2, r2;
    scanf("%i %i %i", &x1, &y1, &r1);
    scanf("%i %i %i", &x2, &y2, &r2);
    circles(x1, y1, r1, x2, y2, r2);
}