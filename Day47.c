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

int height(struct node *root)
{
    int l,r;

    if(root==NULL)
        return 0;

    l=height(root->left);
    r=height(root->right);

    if(l>r)
        return l+1;
    else
        return r+1;
}

int main()
{
    struct node *nodes[100];
    int a[100],n,i,j=1;

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

    printf("height is %d",height(nodes[0]));

    return 0;
}