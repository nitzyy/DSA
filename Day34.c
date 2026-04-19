#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct node
{
    int data;
    struct node *next;
};

void push(struct node **top, int val)
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->next = *top;
    *top = newnode;
}

int pop(struct node **top)
{
    struct node *temp = *top;
    int val = temp->data;
    *top = temp->next;
    free(temp);
    return val;
}

int main()
{
    struct node *top = NULL;
    char exp[100], *token;
    int a, b, res;

    printf("enter postfix expression\n");
    fgets(exp, sizeof(exp), stdin);

    token = strtok(exp, " \n");

    while(token != NULL)
    {
        if(isdigit(token[0]))
        {
            push(&top, atoi(token));
        }
        else
        {
            b = pop(&top);
            a = pop(&top);

            if(token[0] == '+')
                res = a + b;
            else if(token[0] == '-')
                res = a - b;
            else if(token[0] == '*')
                res = a * b;
            else if(token[0] == '/')
                res = a / b;

            push(&top, res);
        }

        token = strtok(NULL, " \n");
    }

    printf("result is %d", pop(&top));

    return 0;
}