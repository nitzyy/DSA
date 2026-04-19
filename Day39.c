#include <stdio.h>
#include <string.h>

int main()
{
    int heap[100], size = 0;
    int n, i, x, j, temp;
    char op[20];

    printf("enter number of operations\n");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        scanf("%s", op);

        if(strcmp(op, "insert") == 0)
        {
            scanf("%d", &x);
            heap[size] = x;
            j = size;
            size++;

            while(j > 0)
            {
                int p = (j - 1) / 2;

                if(heap[p] > heap[j])
                {
                    temp = heap[p];
                    heap[p] = heap[j];
                    heap[j] = temp;
                    j = p;
                }
                else
                    break;
            }
        }
        else if(strcmp(op, "peek") == 0)
        {
            if(size == 0)
                printf("-1\n");
            else
                printf("%d\n", heap[0]);
        }
        else if(strcmp(op, "extractMin") == 0)
        {
            if(size == 0)
                printf("-1\n");
            else
            {
                printf("%d\n", heap[0]);
                heap[0] = heap[size - 1];
                size--;

                j = 0;

                while(1)
                {
                    int left = 2 * j + 1;
                    int right = 2 * j + 2;
                    int small = j;

                    if(left < size && heap[left] < heap[small])
                        small = left;

                    if(right < size && heap[right] < heap[small])
                        small = right;

                    if(small != j)
                    {
                        temp = heap[j];
                        heap[j] = heap[small];
                        heap[small] = temp;
                        j = small;
                    }
                    else
                        break;
                }
            }
        }
    }

    return 0;
}