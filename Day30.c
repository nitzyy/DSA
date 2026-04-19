#include <stdio.h>
#include <stdlib.h>

struct node
{
    int coef, exp;
    struct node *next;
};

int main()
{
    struct node *head = NULL, *temp, *newnode;
    int n, i;

    printf("enter number of terms\n");
    scanf("%d", &n);

    printf("enter coefficient and exponent\n");

    for(i = 0; i < n; i++)
    {
        newnode = (struct node*)malloc(sizeof(struct node));
        scanf("%d%d", &newnode->coef, &newnode->exp);
        newnode->next = NULL;

        if(head == NULL)
            head = temp = newnode;
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
    }

    printf("polynomial is\n");

    temp = head;
    while(temp != NULL)
    {
        if(temp->exp > 1)
            printf("%dx^%d", temp->coef, temp->exp);
        else if(temp->exp == 1)
            printf("%dx", temp->coef);
        else
            printf("%d", temp->coef);

        if(temp->next != NULL)
            printf(" + ");

        temp = temp->next;
    }

    return 0;
}