#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head[100];

int main()
{
    struct node *newnode, *temp;
    int visit[100], q[100];
    int n, m, i, u, v, s;
    int front = 0, rear = -1;

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

    printf("enter source vertex\n");
    scanf("%d", &s);

    q[++rear] = s;
    visit[s] = 1;

    printf("bfs traversal\n");

    while(front <= rear)
    {
        int x = q[front++];
        printf("%d ", x);

        temp = head[x];

        while(temp != NULL)
        {
            if(visit[temp->data] == 0)
            {
                visit[temp->data] = 1;
                q[++rear] = temp->data;
            }

            temp = temp->next;
        }
    }

    return 0;
}