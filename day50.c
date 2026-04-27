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

int search(struct node *root,int key)
{
    if(root==NULL)
        return 0;

    if(root->data==key)
        return 1;

    if(key < root->data)
        return search(root->left,key);
    else
        return search(root->right,key);
}

int main()
{
    struct node *root=NULL;
    int n,i,x,key;

    printf("enter number of nodes\n");
    scanf("%d",&n);

    printf("enter values\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&x);
        root=insert(root,x);
    }

    printf("enter key to search\n");
    scanf("%d",&key);

    if(search(root,key))
        printf("found");
    else
        printf("not found");

    return 0;
}