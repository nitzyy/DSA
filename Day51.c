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

struct node* insert(struct node *root,int x)
{
    if(root==NULL)
        return create(x);

    if(x < root->data)
        root->left=insert(root->left,x);
    else
        root->right=insert(root->right,x);

    return root;
}

int lca(struct node *root,int a,int b)
{
    while(root!=NULL)
    {
        if(a < root->data && b < root->data)
            root=root->left;
        else if(a > root->data && b > root->data)
            root=root->right;
        else
            return root->data;
    }
    return -1;
}

int main()
{
    struct node *root=NULL;
    int n,i,x,a,b;

    printf("enter number of nodes\n");
    scanf("%d",&n);

    printf("enter values\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&x);
        root=insert(root,x);
    }

    printf("enter two nodes\n");
    scanf("%d%d",&a,&b);

    printf("lca is %d",lca(root,a,b));

    return 0;
}