#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *longestCommonPrefix(char **strs, int strsSize)
{
    if (strsSize == 0)
        return "";

    int len = strlen(strs[0]);
    char *prefix = (char *)malloc(len + 1);
    strcpy(prefix, strs[0]);

    for (int i = 1; i < strsSize; i++)
    {
        int j = 0;
        while (prefix[j] != '\0' && strs[i][j] != '\0' && prefix[j] == strs[i][j])
        {
            j++;
        }
        prefix[j] = '\0';
    }

    return prefix;
}

int main(void)
{
    // Test 1: Typical common prefix
    char *strs1[] = {"flower", "flow", "flight"};
    char *res1 = longestCommonPrefix(strs1, 3);
    printf("Test 1: \"%s\" | Expected: \"fl\"\n", res1);
    free(res1);

    // Test 2: No common prefix
    char *strs2[] = {"dog", "racecar", "car"};
    char *res2 = longestCommonPrefix(strs2, 3);
    printf("Test 2: \"%s\" | Expected: \"\"\n", res2);
    free(res2);

    // Test 3: Edge case with single string
    char *strs3[] = {"interspecies"};
    char *res3 = longestCommonPrefix(strs3, 1);
    printf("Test 3: \"%s\" | Expected: \"interspecies\"\n", res3);
    free(res3);

    // Test 4: Edge case with empty string in array
    char *strs4[] = {"", "b"};
    char *res4 = longestCommonPrefix(strs4, 2);
    printf("Test 4: \"%s\" | Expected: \"\"\n", res4);
    free(res4);

    return 0;
}
