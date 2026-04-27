#include <stdio.h>

int main()
{
    int a[100][100], n, m, i, j, u, v;

    printf("enter number of vertices\n");
    scanf("%d", &n);

    printf("enter number of edges\n");
    scanf("%d", &m);

    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            a[i][j] = 0;

    printf("enter edges\n");
    for(i = 0; i < m; i++)
    {
        scanf("%d%d", &u, &v);
        a[u][v] = 1;
        a[v][u] = 1;
    }

    printf("adjacency matrix\n");

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }

    return 0;
}