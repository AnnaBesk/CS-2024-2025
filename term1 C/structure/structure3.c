#include <stdio.h>
#include <string.h>
#include <math.h>

struct game
{
    char title[50];
    float rating;
};

typedef struct game Game;

int main()
{
    int n;
    scanf("%i", &n);
    char temp;
    scanf("%c", &temp);

    Game arr[100];

    for (int i = 0; i < n; ++i)
    {
        char name[50];
        scanf("%[^:]", name);
        scanf("%c", &temp);

        float k;
        float sum = 0;
        scanf("%f", &k);
        for (int j = 0; j < k; ++j)
        {
            int tm;
            scanf("%i", &tm);
            sum += tm;
        }
        strcpy(arr[i].title, name);
        arr[i].rating = sum / k;

        scanf("%c", &temp);
    }

    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 0; j < n - 1 - i; ++j)
        {
            if (arr[j].rating < arr[j + 1].rating)
            {
                float temp = arr[j].rating;
                char nn[50];
                strcpy(nn, arr[j].title);

                strcpy(arr[j].title, arr[j + 1].title);
                arr[j].rating = arr[j + 1].rating;

                strcpy(arr[j + 1].title, nn);
                arr[j + 1].rating = temp;
            }
        }
    }

    for (int i = 0; i < n; ++i)
    {
        printf("%s, ", arr[i].title);
        printf("%.3f \n", arr[i].rating);
    }
}