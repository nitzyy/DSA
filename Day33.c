#include <stdio.h>

int main()
{
    int stack[100], top = -1;
    int n, m, i;

    printf("enter number of elements\n");
    scanf("%d", &n);

    printf("enter values\n");
    for(i = 0; i < n; i++)
    {
        top++;
        scanf("%d", &stack[top]);
    }

    printf("enter number of pops\n");
    scanf("%d", &m);

    for(i = 0; i < m; i++)
    {
        if(top >= 0)
            top--;
    }

    printf("stack after pop\n");

    for(i = top; i >= 0; i--)
        printf("%d ", stack[i]);

    return 0;
}