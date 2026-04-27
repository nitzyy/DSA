#include <stdio.h>

int main()
{
    int a[100], n, i, j;
    int sum, max = 0;

    printf("enter number of elements\n");
    scanf("%d", &n);

    printf("enter values\n");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for(i = 0; i < n; i++)
    {
        sum = 0;

        for(j = i; j < n; j++)
        {
            sum = sum + a[j];

            if(sum == 0)
            {
                if(j - i + 1 > max)
                    max = j - i + 1;
            }
        }
    }

    printf("length is %d", max);

    return 0;
}