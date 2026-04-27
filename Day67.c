#include <stdio.h>

int a[100][100], visit[100], stack[100];
int n, top = -1;

void dfs(int s)
{
    int i;

    visit[s] = 1;

    for(i = 0; i < n; i++)
    {
        if(a[s][i] == 1 && visit[i] == 0)
            dfs(i);
    }

    stack[++top] = s;
}

int main()
{
    int m, i, j, u, v;

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

    printf("enter directed edges\n");
    for(i = 0; i < m; i++)
    {
        scanf("%d%d", &u, &v);
        a[u][v] = 1;
    }

    for(i = 0; i < n; i++)
    {
        if(visit[i] == 0)
            dfs(i);
    }

    printf("topological order\n");

    while(top != -1)
        printf("%d ", stack[top--]);

    return 0;
}