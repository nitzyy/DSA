#include <stdio.h>

int a[100][100], visit[100];
int n;

void dfs(int s)
{
    int i;
    visit[s] = 1;

    for(i = 1; i <= n; i++)
    {
        if(a[s][i] == 1 && visit[i] == 0)
            dfs(i);
    }
}

int main()
{
    int m, i, u, v, start = 1;

    printf("enter number of vertices and edges\n");
    scanf("%d%d", &n, &m);

    for(i = 1; i <= n; i++)
    {
        visit[i] = 0;
        for(int j = 1; j <= n; j++)
            a[i][j] = 0;
    }

    printf("enter edges\n");
    for(i = 0; i < m; i++)
    {
        scanf("%d%d", &u, &v);
        a[u][v] = 1;
        a[v][u] = 1;
    }

    dfs(start);

    for(i = 1; i <= n; i++)
    {
        if(visit[i] == 0)
        {
            printf("NOT CONNECTED");
            return 0;
        }
    }

    printf("CONNECTED");

    return 0;
}