#include <stdio.h>

#define INF 99999

int main()
{
    int a[100][100];
    int n, i, j, k;

    printf("enter number of vertices\n");
    scanf("%d", &n);

    printf("enter adjacency matrix\n");

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
            if(a[i][j] == -1)
                a[i][j] = INF;
        }
    }

    for(k = 0; k < n; k++)
    {
        for(i = 0; i < n; i++)
        {
            for(j = 0; j < n; j++)
            {
                if(a[i][k] + a[k][j] < a[i][j])
                    a[i][j] = a[i][k] + a[k][j];
            }
        }
    }

    printf("shortest distance matrix\n");

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(a[i][j] == INF)
                printf("-1 ");
            else
                printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}