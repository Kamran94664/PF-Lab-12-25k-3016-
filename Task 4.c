

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n;
    int i;
    float total = 0.0f;

    printf("Enter initial number of days (N): ");
    scanf("%d", &n);

    float *sales = malloc(n * sizeof(float));
    if (sales == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("\nEnter sales for %d days:\n", n);
    for (i = 0; i < n; i++)
    {
        printf("Day %d sale: ", i + 1);
        scanf("%f", &sales[i]);
    }

    total = 0.0f;
    for (i = 0; i < n; i++)
    {
        total += sales[i];
    }

    printf("\nTotal sales for %d days = %.2f\n", n, total);

    int extra;
    printf("\nIf you want to add more days, enter how many extra days (0 to skip): ");
    scanf("%d", &extra);

    if (extra > 0)
    {
        int newN = n + extra;

        float *temp = realloc(sales, newN * sizeof(float));
        if (temp == NULL)
        {
            printf("Reallocation failed. Keeping original data.\n");
            free(sales);
            return 1;
        }
        sales = temp;

        printf("\nEnter sales for the %d extra days:\n", extra);
        for (i = n; i < newN; i++)
        {
            printf("Day %d sale: ", i + 1);
            scanf("%f", &sales[i]);
        }
        total = 0.0f;
        for (i=0;i<newN; i++)
        {
            total += sales[i];
        }

        printf("\nUpdated total sales for %d days = %.2f\n", newN, total);
    }

    free(sales);
    return 0;
}

