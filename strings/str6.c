#include <stdio.h>
#include <string.h>

int main()
{
    int n;
    scanf("%i", &n);

    int coor[2];
    coor[0] = 0;
    coor[1] = 0;

    for (int i = 0; i < n; ++i)
    {
        char dir[100];
        int st;
        scanf("%s", dir);
        scanf("%i", &st);

        if (strcmp(dir, "North") == 0)
        {
            coor[1] += st;
        }
        else if (strcmp(dir, "South") == 0)
        {
            coor[1] -= st;
        }
        else if (strcmp(dir, "East") == 0)
        {
            coor[0] += st;
        }
        else if (strcmp(dir, "West") == 0)
        {
            coor[0] -= st;
        }
    }
    printf("%i  %i \n", coor[0], coor[1]);
}