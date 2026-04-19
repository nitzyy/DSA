#include <stdio.h>

int main()
{
    int stack[100], top = -1;
    int n, i, ch, val, j;

    printf("enter number of operations\n");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        scanf("%d", &ch);

        if(ch == 1)
        {
            scanf("%d", &val);
            top++;
            stack[top] = val;
        }
        else if(ch == 2)
        {
            if(top == -1)
                printf("stack underflow\n");
            else
            {
                printf("%d\n", stack[top]);
                top--;
            }
        }
        else if(ch == 3)
        {
            if(top == -1)
                printf("stack is empty\n");
            else
            {
                for(j = top; j >= 0; j--)
                    printf("%d ", stack[j]);
                printf("\n");
            }
        }
    }

    return 0;
}