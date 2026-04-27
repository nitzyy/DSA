#include <stdio.h>

int main()
{
    int a[100][100], indegree[100], q[100];
    int n, m, i, j, u, v;
    int front = 0, rear = -1, count = 0;

    printf("enter number of vertices\n");
    scanf("%d", &n);

    printf("enter number of edges\n");
    scanf("%d", &m);

    for(i = 0; i < n; i++)
    {
        indegree[i] = 0;

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
        for(j = 0; j < n; j++)
            if(a[i][j] == 1)
                indegree[j]++;

    for(i = 0; i < n; i++)
        if(indegree[i] == 0)
            q[++rear] = i;

    printf("topological order\n");

    while(front <= rear)
    {
        int x = q[front++];
        printf("%d ", x);
        count++;

        for(i = 0; i < n; i++)
        {
            if(a[x][i] == 1)
            {
                indegree[i]--;

                if(indegree[i] == 0)
                    q[++rear] = i;
            }
        }
    }

    if(count != n)
        printf("\ncycle exists");

    return 0;
}