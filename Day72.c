#include <stdio.h>
#include <string.h>

int main()
{
    char s[100];
    int count[26] = {0};
    int i;

    printf("enter string\n");
    scanf("%s", s);

    for(i = 0; s[i] != '\0'; i++)
    {
        if(count[s[i] - 'a'] == 1)
        {
            printf("%c", s[i]);
            return 0;
        }

        count[s[i] - 'a']++;
    }

    printf("-1");

    return 0;
}