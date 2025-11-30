//25K-3016
// Syed kamran ahmed

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int m;
    int n;
    int p;
    int i, j, k;


    printf("Enter number of rows for Matrix A (m): ");
    scanf("%d", &m);

    printf("Enter number of columns for Matrix A (n): ");
    scanf("%d", &n);

    printf("Enter number of columns for Matrix B (p): ");
    scanf("%d", &p);

    int **A = malloc(m * sizeof(int *));
    for (i=0;i< m; i++)
    {
        A[i] = malloc(n * sizeof(int));
    }

    int **B = malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
    {
        B[i] = malloc(p * sizeof(int));
    }

   int **C = malloc(m * sizeof(int *));
    for (i = 0; i < m; i++)
    {
        C[i] = malloc(p * sizeof(int));
    }

    printf("\nEnter elements of Matrix A:\n");
    for (i=0;i<m; i++)
    {
        for (j=0;j<n;j++)
        {
            printf("A[%d][%d]: ", i, j);
            scanf("%d", &A[i][j]);
        }
    }

    /* Input B */
    printf("\nEnter elements of Matrix B:\n");
    for (i=0;i<n;i++)
    {
        for (j=0;j<p;j++)
        {
            printf("B[%d][%d]: ", i, j);
            scanf("%d", &B[i][j]);
        }
    }

    
    for (i=0;i<m; i++)
    {
        for (j=0;j<p;j++)
        {
            C[i][j] = 0;
            for (k = 0; k < n; k++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    printf("\nResultant Matrix C (m x p):\n");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < p; j++)
        {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }


    for (i = 0; i < m; i++){
        free(A[i]);
    }
    free(A);

    for (i = 0; i < n; i++)
    {
        free(B[i]);
    }
    free(B);

    for (i = 0; i < m; i++)
    {
        free(C[i]);
    }
    free(C);

    return 0;
}

