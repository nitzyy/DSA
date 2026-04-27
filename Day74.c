#include <stdio.h>
#include <string.h>

struct vote
{
    char name[50];
    int count;
};

int main()
{
    struct vote a[100];
    char s[50];
    int n, i, j, size = 0, found;
    int max = 0, pos = 0;

    printf("enter number of votes\n");
    scanf("%d", &n);

    printf("enter names\n");

    for(i = 0; i < n; i++)
    {
        scanf("%s", s);
        found = 0;

        for(j = 0; j < size; j++)
        {
            if(strcmp(a[j].name, s) == 0)
            {
                a[j].count++;
                found = 1;
                break;
            }
        }

        if(found == 0)
        {
            strcpy(a[size].name, s);
            a[size].count = 1;
            size++;
        }
    }

    for(i = 0; i < size; i++)
    {
        if(a[i].count > max)
        {
            max = a[i].count;
            pos = i;
        }
        else if(a[i].count == max)
        {
            if(strcmp(a[i].name, a[pos].name) < 0)
                pos = i;
        }
    }

    printf("%s %d", a[pos].name, a[pos].count);

    return 0;
}