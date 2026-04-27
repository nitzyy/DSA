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

struct node* lca(struct node *root,int a,int b)
{
    if(root==NULL)
        return NULL;

    if(root->data==a || root->data==b)
        return root;

    struct node *left=lca(root->left,a,b);
    struct node *right=lca(root->right,a,b);

    if(left && right)
        return root;

    if(left)
        return left;
    else
        return right;
}

int main()
{
    struct node *nodes[100];
    int a[100], n, i, j=1, x, y;

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

    printf("enter two nodes\n");
    scanf("%d%d",&x,&y);

    printf("lca is %d", lca(nodes[0],x,y)->data);

    return 0;
}