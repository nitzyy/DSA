#include <stdio.h>

int main()
{
    int stack[100], top = -1;
    int n, m, i, val;

    printf("enter number of elements\n");
    scanf("%d", &n);

    printf("enter values to push\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &val);
        top++;
        stack[top] = val;
    }

    printf("enter number of pops\n");
    scanf("%d", &m);

    for(i = 0; i < m; i++)
    {
        if(top != -1)
            top--;
    }

    printf("remaining stack elements\n");

    for(i = top; i >= 0; i--)
        printf("%d ", stack[i]);

    return 0;
}