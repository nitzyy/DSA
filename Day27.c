#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int main()
{
    struct node *head1 = NULL, *head2 = NULL, *temp, *newnode;
    int n, m, i, found = 0;

    printf("enter number of elements in first list\n");
    scanf("%d", &n);

    printf("enter first list values\n");
    for(i = 0; i < n; i++)
    {
        newnode = (struct node*)malloc(sizeof(struct node));
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if(head1 == NULL)
            head1 = temp = newnode;
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
    }

    printf("enter number of elements in second list\n");
    scanf("%d", &m);

    printf("enter second list values\n");
    for(i = 0; i < m; i++)
    {
        newnode = (struct node*)malloc(sizeof(struct node));
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if(head2 == NULL)
            head2 = temp = newnode;
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
    }

    while(head1 != NULL)
    {
        temp = head2;

        while(temp != NULL)
        {
            if(head1->data == temp->data)
            {
                printf("intersection point is %d", head1->data);
                found = 1;
                break;
            }
            temp = temp->next;
        }

        if(found)
            break;

        head1 = head1->next;
    }

    if(!found)
        printf("no intersection");

    return 0;
}