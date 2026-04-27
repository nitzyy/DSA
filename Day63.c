#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head[100];
int visit[100], n;

void dfs(int s)
{
    struct node *temp;

    visit[s] = 1;
    printf("%d ", s);

    temp = head[s];

    while(temp != NULL)
    {
        if(visit[temp->data] == 0)
            dfs(temp->data);

        temp = temp->next;
    }
}

int main()
{
    struct node *newnode;
    int m, i, u, v, s;

    printf("enter number of vertices\n");
    scanf("%d", &n);

    printf("enter number of edges\n");
    scanf("%d", &m);

    for(i = 0; i < n; i++)
    {
        head[i] = NULL;
        visit[i] = 0;
    }

    printf("enter edges\n");
    for(i = 0; i < m; i++)
    {
        scanf("%d%d", &u, &v);

        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = v;
        newnode->next = head[u];
        head[u] = newnode;

        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = u;
        newnode->next = head[v];
        head[v] = newnode;
    }

    printf("enter starting vertex\n");
    scanf("%d", &s);

    printf("dfs traversal\n");
    dfs(s);

    return 0;
}