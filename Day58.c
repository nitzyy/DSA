#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left,*right;
};

int preindex = 0;

struct node* create(int x)
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->left = newnode->right = NULL;
    return newnode;
}

int search(int in[], int start, int end, int key)
{
    int i;
    for(i = start; i <= end; i++)
        if(in[i] == key)
            return i;
    return -1;
}

struct node* build(int pre[], int in[], int start, int end)
{
    if(start > end)
        return NULL;

    struct node *root = create(pre[preindex++]);

    if(start == end)
        return root;

    int pos = search(in, start, end, root->data);

    root->left = build(pre, in, start, pos - 1);
    root->right = build(pre, in, pos + 1, end);

    return root;
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
    int pre[100], in[100], n, i;
    struct node *root;

    printf("enter number of nodes\n");
    scanf("%d", &n);

    printf("enter preorder values\n");
    for(i = 0; i < n; i++)
        scanf("%d", &pre[i]);

    printf("enter inorder values\n");
    for(i = 0; i < n; i++)
        scanf("%d", &in[i]);

    root = build(pre, in, 0, n - 1);

    printf("postorder traversal\n");
    postorder(root);

    return 0;
}