#include <stdio.h>

int main()
{
    int dq[100], front = 50, rear = 49;
    int n, i, ch, val;

    printf("enter number of operations\n");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("1 push front 2 push back 3 pop front 4 pop back 5 front 6 back 7 size 8 display\n");
        scanf("%d", &ch);

        if(ch == 1)
        {
            scanf("%d", &val);
            front--;
            dq[front] = val;
        }
        else if(ch == 2)
        {
            scanf("%d", &val);
            rear++;
            dq[rear] = val;
        }
        else if(ch == 3)
        {
            if(front > rear)
                printf("deque is empty\n");
            else
                front++;
        }
        else if(ch == 4)
        {
            if(front > rear)
                printf("deque is empty\n");
            else
                rear--;
        }
        else if(ch == 5)
        {
            if(front > rear)
                printf("deque is empty\n");
            else
                printf("%d\n", dq[front]);
        }
        else if(ch == 6)
        {
            if(front > rear)
                printf("deque is empty\n");
            else
                printf("%d\n", dq[rear]);
        }
        else if(ch == 7)
        {
            printf("%d\n", rear - front + 1);
        }
        else if(ch == 8)
        {
            if(front > rear)
                printf("deque is empty\n");
            else
            {
                for(val = front; val <= rear; val++)
                    printf("%d ", dq[val]);
                printf("\n");
            }
        }
    }

    return 0;
}