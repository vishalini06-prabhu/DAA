#include <stdio.h>
#include <string.h>

/* Brute force string matching function */
int bruteForceMatch(char text[], char pattern[])
{
    int i, j, n, m;

    n = strlen(text);
    m = strlen(pattern);

    for (i = 0; i <= n - m; i++)
    {
        j = 0;

        while (j < m && text[i + j] == pattern[j])
        {
            j++;
        }

        if (j == m)
        {
            return i;   /* pattern found */
        }
    }

    return -1;          /* pattern not found */
}

int main()
{
    char text[100], pattern[100];
    int result;

    printf("Enter the text: ");
    scanf("%s", text);

    printf("Enter the pattern: ");
    scanf("%s", pattern);

    result = bruteForceMatch(text, pattern);

    if (result != -1)
    {
        printf("Pattern found at position %d\n", result);
    }
    else
    {
        printf("Pattern not found\n");
    }

    return 0;
}
