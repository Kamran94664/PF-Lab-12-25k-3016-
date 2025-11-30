//25k-3016

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int n;
    int i, j;

    printf("Enter number of strings (n): ");
    scanf("%d", &n);
    while (getchar() != '\n'); 
	    char **arr = malloc(n * sizeof(char *));
    if (arr == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    char buffer[1024];

    for (i = 0; i < n; i++)
    {
        printf("Enter string %d: ", i + 1);
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = '\0'; 
        
        arr[i] = malloc(strlen(buffer) + 1);
        if (arr[i] == NULL)
        {
            printf("Memory allocation failed for string %d.\n", i + 1);
            for (j=0;j<i;j++)
            {
                free(arr[j]);
            }
            free(arr);
            return 1;
        }
        strcpy(arr[i], buffer);
    }
    char *tmp;
    for (i=0;i<n-1; i++)
    {
        for (j=i+1;j<n; j++)
        {
            if (strcmp(arr[i], arr[j]) > 0)
            {
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
    printf("\nSorted strings:\n");
    for (i=0;i<n; i++)
    {
        printf("%s\n", arr[i]);
        free(arr[i]);
    }

    free(arr);
    return 0;
}

