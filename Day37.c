#include <stdio.h>
#include <string.h>

int main()
{
    int q[100], n, i, size = 0, j, pos, min;
    char op[20];

    printf("enter number of operations\n");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        scanf("%s", op);

        if(strcmp(op, "insert") == 0)
        {
            scanf("%d", &q[size]);
            size++;
        }
        else if(strcmp(op, "delete") == 0)
        {
            if(size == 0)
                printf("-1\n");
            else
            {
                min = q[0];
                pos = 0;

                for(j = 1; j < size; j++)
                {
                    if(q[j] < min)
                    {
                        min = q[j];
                        pos = j;
                    }
                }

                printf("%d\n", min);

                for(j = pos; j < size - 1; j++)
                    q[j] = q[j + 1];

                size--;
            }
        }
        else if(strcmp(op, "peek") == 0)
        {
            if(size == 0)
                printf("-1\n");
            else
            {
                min = q[0];

                for(j = 1; j < size; j++)
                    if(q[j] < min)
                        min = q[j];

                printf("%d\n", min);
            }
        }
    }

    return 0;
}