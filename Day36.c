#include <stdio.h>

int main()
{
    int q[100], front = 0, rear = -1;
    int n, m, i, size = 100;

    printf("enter number of elements\n");
    scanf("%d", &n);

    printf("enter values\n");
    for(i = 0; i < n; i++)
    {
        rear = (rear + 1) % size;
        scanf("%d", &q[rear]);
    }

    printf("enter number of dequeue operations\n");
    scanf("%d", &m);

    for(i = 0; i < m; i++)
        front = (front + 1) % size;

    printf("queue after operations\n");

    i = front;
    while(1)
    {
        printf("%d ", q[i]);
        if(i == rear)
            break;
        i = (i + 1) % size;
    }

    return 0;
}