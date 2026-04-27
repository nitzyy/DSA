#include <stdio.h>

#define INF 99999

int main()
{
    int a[100][100], dist[100], visit[100];
    int n, m, i, j, u, v, w, s;

    printf("enter number of vertices and edges\n");
    scanf("%d%d", &n, &m);

    for(i = 1; i <= n; i++)
    {
        dist[i] = INF;
        visit[i] = 0;

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

    printf("enter source vertex\n");
    scanf("%d", &s);

    dist[s] = 0;

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

        if(x == -1)
            break;

        visit[x] = 1;

        for(j = 1; j <= n; j++)
        {
            if(a[x][j] != 0 && visit[j] == 0)
            {
                if(dist[x] + a[x][j] < dist[j])
                    dist[j] = dist[x] + a[x][j];
            }
        }
    }

    for(i = 1; i <= n; i++)
    {
        if(dist[i] == INF)
            printf("INF ");
        else
            printf("%d ", dist[i]);
    }

    return 0;
}