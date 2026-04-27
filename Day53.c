#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data, hd;
    struct node *left, *right;
};

struct node* create(int x)
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->hd = 0;
    newnode->left = newnode->right = NULL;
    return newnode;
}

void printvertical(struct node *root, int line)
{
    if(root == NULL)
        return;

    if(root->hd == line)
        printf("%d ", root->data);

    printvertical(root->left, line);
    printvertical(root->right, line);
}

void sethd(struct node *root, int hd, int *min, int *max)
{
    if(root == NULL)
        return;

    root->hd = hd;

    if(hd < *min) *min = hd;
    if(hd > *max) *max = hd;

    sethd(root->left, hd - 1, min, max);
    sethd(root->right, hd + 1, min, max);
}

int main()
{
    struct node *nodes[100];
    int a[100], n, i, j = 1, min = 0, max = 0;

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

    sethd(nodes[0], 0, &min, &max);

    printf("vertical order traversal\n");

    for(i = min; i <= max; i++)
    {
        printvertical(nodes[0], i);
        printf("\n");
    }

    return 0;
}