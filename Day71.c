#include <stdio.h>
#include <string.h>

int main()
{
    int table[100], n, m, i, key, pos, j;
    char op[20];

    printf("enter table size\n");
    scanf("%d", &m);

    for(i = 0; i < m; i++)
        table[i] = -1;

    printf("enter number of operations\n");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        scanf("%s%d", op, &key);

        if(strcmp(op, "INSERT") == 0)
        {
            for(j = 0; j < m; j++)
            {
                pos = (key % m + j * j) % m;

                if(table[pos] == -1)
                {
                    table[pos] = key;
                    break;
                }
            }
        }
        else if(strcmp(op, "SEARCH") == 0)
        {
            int found = 0;

            for(j = 0; j < m; j++)
            {
                pos = (key % m + j * j) % m;

                if(table[pos] == key)
                {
                    found = 1;
                    break;
                }

                if(table[pos] == -1)
                    break;
            }

            if(found)
                printf("FOUND\n");
            else
                printf("NOT FOUND\n");
        }
    }

    return 0;
}