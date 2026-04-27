#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left,*right;
};

struct node* create(int x)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->left=newnode->right=NULL;
    return newnode;
}

int main()
{
    struct node *nodes[100], *q[100];
    int a[100], n, i, j=1, front=0, rear=-1;

    printf("enter number of nodes\n");
    scanf("%d",&n);

    printf("enter level order values\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);

    for(i=0;i<n;i++)
    {
        if(a[i]==-1)
            nodes[i]=NULL;
        else
            nodes[i]=create(a[i]);
    }

    for(i=0;i<n && j<n;i++)
    {
        if(nodes[i]!=NULL)
        {
            if(j<n)
                nodes[i]->left=nodes[j++];

            if(j<n)
                nodes[i]->right=nodes[j++];
        }
    }

    if(nodes[0]!=NULL)
        q[++rear]=nodes[0];

    printf("level order traversal\n");

    while(front<=rear)
    {
        struct node *temp=q[front++];
        printf("%d ",temp->data);

        if(temp->left!=NULL)
            q[++rear]=temp->left;

        if(temp->right!=NULL)
            q[++rear]=temp->right;
    }

    return 0;
}