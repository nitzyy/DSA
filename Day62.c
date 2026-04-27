#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int main()
{
    struct node *head[100], *temp, *newnode;
    int n, m, i, u, v;

    printf("enter number of vertices\n");
    scanf("%d", &n);

    printf("enter number of edges\n");
    scanf("%d", &m);

    for(i = 0; i < n; i++)
        head[i] = NULL;

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

    printf("adjacency list\n");

    for(i = 0; i < n; i++)
    {
        printf("%d -> ", i);
        temp = head[i];

        while(temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }

    return 0;
}