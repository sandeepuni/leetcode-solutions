#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool isAnagram(char *s, char *t)
{
    if (strlen(s) != strlen(t))
        return false;

    int count[26] = {0};

    for (int i = 0; s[i] != '\0'; i++)
    {
        count[s[i] - 'a']++;
        count[t[i] - 'a']--;
    }

    for (int i = 0; i < 26; i++)
    {
        if (count[i] != 0)
            return false;
    }

    return true;
}

int main(void)
{
    // Test 1: Typical valid anagram
    printf("Test 1: %s | Expected: true\n", isAnagram("anagram", "nagaram") ? "true" : "false");

    // Test 2: Non-anagram of same length
    printf("Test 2: %s | Expected: false\n", isAnagram("rat", "car") ? "true" : "false");

    // Test 3: Edge case with single character
    printf("Test 3: %s | Expected: true\n", isAnagram("a", "a") ? "true" : "false");

    // Test 4: Edge case with different lengths
    printf("Test 4: %s | Expected: false\n", isAnagram("ab", "a") ? "true" : "false");

    return 0;
}
