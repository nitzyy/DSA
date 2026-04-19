#include <stdio.h>

int main()
{
    int queue[100], front = 0, rear = -1;
    int n, i;

    printf("enter number of elements\n");
    scanf("%d", &n);

    printf("enter values\n");
    for(i = 0; i < n; i++)
    {
        rear++;
        scanf("%d", &queue[rear]);
    }

    printf("queue elements\n");

    for(i = front; i <= rear; i++)
        printf("%d ", queue[i]);

    return 0;
}