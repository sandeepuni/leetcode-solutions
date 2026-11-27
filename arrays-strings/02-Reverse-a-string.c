#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *reverseWords(char *s)
{
    int len = strlen(s);
    char *res = (char *)malloc(len + 1);
    int k = 0;

    for (int i = len - 1; i >= 0; i--)
    {
        if (s[i] == ' ')
            continue;
        int end = i;
        while (i >= 0 && s[i] != ' ')
            i--;
        int start = i + 1;
        if (k > 0)
            res[k++] = ' ';
        for (int j = start; j <= end; j++)
        {
            res[k++] = s[j];
        }
    }

    res[k] = '\0';
    return res;
}

int main(void)
{
    // Test 1: Typical case
    char s1[] = "the sky is blue";
    char *r1 = reverseWords(s1);
    printf("Test 1: \"%s\" | Expected: \"blue is sky the\"\n", r1);
    free(r1);

    // Test 2: Leading, trailing, and multiple spaces
    char s2[] = "  hello   world  ";
    char *r2 = reverseWords(s2);
    printf("Test 2: \"%s\" | Expected: \"world hello\"\n", r2);
    free(r2);

    // Test 3: Single word
    char s3[] = "leetcode";
    char *r3 = reverseWords(s3);
    printf("Test 3: \"%s\" | Expected: \"leetcode\"\n", r3);
    free(r3);

    return 0;
}
