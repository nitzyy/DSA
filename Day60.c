#include <stdio.h>

int main()
{
    int a[100], n, i, flag = 1;

    printf("enter number of nodes\n");
    scanf("%d", &n);

    printf("enter level order values\n");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for(i = 0; i <= (n - 2) / 2; i++)
    {
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if(left < n && a[i] > a[left])
            flag = 0;

        if(right < n && a[i] > a[right])
            flag = 0;
    }

    if(flag)
        printf("YES");
    else
        printf("NO");

    return 0;
}