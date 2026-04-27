#include <stdio.h>

int lowerBound(int a[], int n, int x)
{
    int l = 0, r = n - 1, ans = n;

    while(l <= r)
    {
        int mid = (l + r) / 2;

        if(a[mid] >= x)
        {
            ans = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }

    return ans;
}

int upperBound(int a[], int n, int x)
{
    int l = 0, r = n - 1, ans = n;

    while(l <= r)
    {
        int mid = (l + r) / 2;

        if(a[mid] > x)
        {
            ans = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }

    return ans;
}

int main()
{
    int a[100], n, i, x;

    printf("enter number of elements\n");
    scanf("%d", &n);

    printf("enter sorted array\n");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("enter target\n");
    scanf("%d", &x);

    printf("%d %d", lowerBound(a, n, x), upperBound(a, n, x));

    return 0;
}