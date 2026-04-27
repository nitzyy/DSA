#include <stdio.h>

int a[100][100], visit[100], n;

int dfs(int s, int parent)
{
    int i;

    visit[s] = 1;

    for(i = 0; i < n; i++)
    {
        if(a[s][i] == 1)
        {
            if(visit[i] == 0)
            {
                if(dfs(i, s))
                    return 1;
            }
            else if(i != parent)
                return 1;
        }
    }

    return 0;
}

int main()
{
    int m, i, j, u, v, flag = 0;

    printf("enter number of vertices\n");
    scanf("%d", &n);

    printf("enter number of edges\n");
    scanf("%d", &m);

    for(i = 0; i < n; i++)
    {
        visit[i] = 0;
        for(j = 0; j < n; j++)
            a[i][j] = 0;
    }

    printf("enter edges\n");
    for(i = 0; i < m; i++)
    {
        scanf("%d%d", &u, &v);
        a[u][v] = 1;
        a[v][u] = 1;
    }

    for(i = 0; i < n; i++)
    {
        if(visit[i] == 0)
        {
            if(dfs(i, -1))
            {
                flag = 1;
                break;
            }
        }
    }

    if(flag)
        printf("YES");
    else
        printf("NO");

    return 0;
}