#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int main()
{
    struct node *head = NULL, *temp, *newnode, *tail, *newhead;
    int n, i, k;

    printf("enter number of elements\n");
    scanf("%d", &n);

    printf("enter values\n");
    for(i = 0; i < n; i++)
    {
        newnode = (struct node*)malloc(sizeof(struct node));
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if(head == NULL)
            head = temp = newnode;
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
    }

    printf("enter rotation value\n");
    scanf("%d", &k);

    k = k % n;

    if(k > 0)
    {
        tail = head;
        while(tail->next != NULL)
            tail = tail->next;

        tail->next = head;

        temp = head;
        for(i = 1; i < n - k; i++)
            temp = temp->next;

        newhead = temp->next;
        temp->next = NULL;
        head = newhead;
    }

    printf("list after rotation\n");

    temp = head;
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}