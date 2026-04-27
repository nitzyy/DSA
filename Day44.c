#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left, *right;
};

struct node* create(int x)
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->left = newnode->right = NULL;
    return newnode;
}

void inorder(struct node *root)
{
    if(root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct node *root)
{
    if(root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node *root)
{
    if(root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main()
{
    struct node *nodes[100];
    int a[100], n, i, j = 1;

    printf("enter number of nodes\n");
    scanf("%d", &n);

    printf("enter level order values\n");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for(i = 0; i < n; i++)
    {
        if(a[i] == -1)
            nodes[i] = NULL;
        else
            nodes[i] = create(a[i]);
    }

    for(i = 0; i < n && j < n; i++)
    {
        if(nodes[i] != NULL)
        {
            if(j < n)
                nodes[i]->left = nodes[j++];

            if(j < n)
                nodes[i]->right = nodes[j++];
        }
    }

    printf("inorder traversal\n");
    inorder(nodes[0]);
    printf("\n");

    printf("preorder traversal\n");
    preorder(nodes[0]);
    printf("\n");

    printf("postorder traversal\n");
    postorder(nodes[0]);

    return 0;
}