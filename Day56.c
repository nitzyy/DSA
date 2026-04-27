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

int mirror(struct node *a, struct node *b)
{
    if(a==NULL && b==NULL)
        return 1;

    if(a==NULL || b==NULL)
        return 0;

    if(a->data != b->data)
        return 0;

    return mirror(a->left,b->right) && mirror(a->right,b->left);
}

int main()
{
    struct node *nodes[100];
    int a[100], n, i, j=1;

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

    if(nodes[0]==NULL || mirror(nodes[0]->left,nodes[0]->right))
        printf("YES");
    else
        printf("NO");

    return 0;
}