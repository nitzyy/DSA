#include <stdio.h>

struct edge
{
    int u,v,w;
};

#define INF 99999

int main()
{
    struct edge e[100];
    int dist[100];
    int n,m,i,j,s;

    printf("enter number of vertices\n");
    scanf("%d",&n);

    printf("enter number of edges\n");
    scanf("%d",&m);

    printf("enter edges and weight\n");
    for(i=0;i<m;i++)
        scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);

    printf("enter source vertex\n");
    scanf("%d",&s);

    for(i=0;i<n;i++)
        dist[i]=INF;

    dist[s]=0;

    for(i=1;i<=n-1;i++)
    {
        for(j=0;j<m;j++)
        {
            if(dist[e[j].u]!=INF && dist[e[j].u]+e[j].w < dist[e[j].v])
                dist[e[j].v]=dist[e[j].u]+e[j].w;
        }
    }

    for(j=0;j<m;j++)
    {
        if(dist[e[j].u]!=INF && dist[e[j].u]+e[j].w < dist[e[j].v])
        {
            printf("NEGATIVE CYCLE");
            return 0;
        }
    }

    printf("shortest distances\n");

    for(i=0;i<n;i++)
        printf("%d -> %d\n",i,dist[i]);

    return 0;
}