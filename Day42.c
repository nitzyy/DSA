#include <stdio.h>

int main()
{
    int q[100], stack[100];
    int n, i, top = -1;

    printf("enter number of elements\n");
    scanf("%d", &n);

    printf("enter queue elements\n");
    for(i = 0; i < n; i++)
        scanf("%d", &q[i]);

    for(i = 0; i < n; i++)
    {
        top++;
        stack[top] = q[i];
    }

    printf("reversed queue\n");

    while(top != -1)
    {
        printf("%d ", stack[top]);
        top--;
    }

    return 0;
}