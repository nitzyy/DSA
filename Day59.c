#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left,*right;
};

int postindex;

struct node* create(int x)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->left=newnode->right=NULL;
    return newnode;
}

int search(int in[],int start,int end,int key)
{
    int i;
    for(i=start;i<=end;i++)
        if(in[i]==key)
            return i;
    return -1;
}

struct node* build(int in[],int post[],int start,int end)
{
    if(start>end)
        return NULL;

    struct node *root=create(post[postindex--]);

    if(start==end)
        return root;

    int pos=search(in,start,end,root->data);

    root->right=build(in,post,pos+1,end);
    root->left=build(in,post,start,pos-1);

    return root;
}

void preorder(struct node *root)
{
    if(root!=NULL)
    {
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

int main()
{
    int in[100],post[100],n,i;
    struct node *root;

    printf("enter number of nodes\n");
    scanf("%d",&n);

    printf("enter inorder values\n");
    for(i=0;i<n;i++)
        scanf("%d",&in[i]);

    printf("enter postorder values\n");
    for(i=0;i<n;i++)
        scanf("%d",&post[i]);

    postindex=n-1;

    root=build(in,post,0,n-1);

    printf("preorder traversal\n");
    preorder(root);

    return 0;
}