#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int data;
    struct node *next;
};

int main()
{
    struct node *front = NULL, *rear = NULL, *temp;
    int n, i, x;
    char op[20];

    printf("enter number of operations\n");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        scanf("%s", op);

        if(strcmp(op, "enqueue") == 0)
        {
            scanf("%d", &x);

            temp = (struct node*)malloc(sizeof(struct node));
            temp->data = x;
            temp->next = NULL;

            if(front == NULL)
                front = rear = temp;
            else
            {
                rear->next = temp;
                rear = temp;
            }
        }
        else if(strcmp(op, "dequeue") == 0)
        {
            if(front == NULL)
                printf("-1\n");
            else
            {
                temp = front;
                printf("%d\n", front->data);
                front = front->next;

                if(front == NULL)
                    rear = NULL;

                free(temp);
            }
        }
    }

    return 0;
}