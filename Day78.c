#include <stdio.h>

#define INF 99999

int main()
{
    int a[100][100], visit[100], dist[100];
    int n, m, i, j, u, v, w;
    int total = 0;

    printf("enter number of vertices and edges\n");
    scanf("%d%d", &n, &m);

    for(i = 1; i <= n; i++)
    {
        visit[i] = 0;
        dist[i] = INF;

        for(j = 1; j <= n; j++)
            a[i][j] = 0;
    }

    printf("enter edges with weight\n");
    for(i = 0; i < m; i++)
    {
        scanf("%d%d%d", &u, &v, &w);
        a[u][v] = w;
        a[v][u] = w;
    }

    dist[1] = 0;

    for(i = 1; i <= n; i++)
    {
        int min = INF, x = -1;

        for(j = 1; j <= n; j++)
        {
            if(visit[j] == 0 && dist[j] < min)
            {
                min = dist[j];
                x = j;
            }
        }

        visit[x] = 1;
        total += dist[x];

        for(j = 1; j <= n; j++)
        {
            if(a[x][j] != 0 && visit[j] == 0 && a[x][j] < dist[j])
                dist[j] = a[x][j];
        }
    }

    printf("%d", total);

    return 0;
}