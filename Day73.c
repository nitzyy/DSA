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
        count[s[i] - 'a']++;

    for(i = 0; s[i] != '\0'; i++)
    {
        if(count[s[i] - 'a'] == 1)
        {
            printf("%c", s[i]);
            return 0;
        }
    }

    printf("$");

    return 0;
}