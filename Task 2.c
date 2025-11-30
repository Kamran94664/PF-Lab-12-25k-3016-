//25k-3016
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n;
    int i;

    printf("Enter initial size of the array (n): ");
    scanf("%d", &n);
    
    int *arr = malloc(n * sizeof(int));
    if (arr == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("\nEnter %d integers:\n", n);
    for (i = 0; i < n; i++)
    {
        printf("Element %d: ", i);
        scanf("%d", &arr[i]);
    }
    int newSize = n * 2;
    int *temp = realloc(arr, newSize * sizeof(int));
    if (temp == NULL)
    {
        printf("Reallocation failed. Original array still valid.\n");
        free(arr);
        return 1;
    }
    arr = temp;

    printf("\nEnter %d more integers to fill the expanded array:\n", n);
    for (i=n;i<newSize; i++)
    {
        printf("Element %d: ", i);
        scanf("%d", &arr[i]);
    }

    printf("\nUpdated array (size = %d):\n", newSize);
    for (i=0;i<newSize; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}

