#include <stdio.h>

int a[100][100], visit[100], rec[100], n;

int dfs(int s)
{
    int i;

    visit[s] = 1;
    rec[s] = 1;

    for(i = 0; i < n; i++)
    {
        if(a[s][i] == 1)
        {
            if(visit[i] == 0)
            {
                if(dfs(i))
                    return 1;
            }
            else if(rec[i] == 1)
                return 1;
        }
    }

    rec[s] = 0;
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
        rec[i] = 0;

        for(j = 0; j < n; j++)
            a[i][j] = 0;
    }

    printf("enter directed edges\n");
    for(i = 0; i < m; i++)
    {
        scanf("%d%d", &u, &v);
        a[u][v] = 1;
    }

    for(i = 0; i < n; i++)
    {
        if(visit[i] == 0)
        {
            if(dfs(i))
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