#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool isValid(char* s) {
    int len = strlen(s);
    char* stack = (char*)malloc(len);
    int top = -1;

    for (int i = 0; i < len; i++) {
        char c = s[i];
        if (c == '(' || c == '{' || c == '[') {
            stack[++top] = c;
        } else {
            if (top < 0) {
                free(stack);
                return false;
            }
            char open = stack[top--];
            if ((c == ')' && open != '(') ||
                (c == '}' && open != '{') ||
                (c == ']' && open != '[')) {
                free(stack);
                return false;
            }
        }
    }

    bool valid = (top == -1);
    free(stack);
    return valid;
}

int main(void) {
    // Test 1: Simple valid pair
    printf("Test 1: %s | Expected: true\n", isValid("()") ? "true" : "false");

    // Test 2: Multiple valid bracket types
    printf("Test 2: %s | Expected: true\n", isValid("()[]{}") ? "true" : "false");

    // Test 3: Mismatched bracket pair
    printf("Test 3: %s | Expected: false\n", isValid("(]") ? "true" : "false");

    // Test 4: Nested valid brackets
    printf("Test 4: %s | Expected: true\n", isValid("([])") ? "true" : "false");

    // Test 5: Improperly interleaved brackets
    printf("Test 5: %s | Expected: false\n", isValid("([)]") ? "true" : "false");

    // Test 6: Unmatched closing bracket only
    printf("Test 6: %s | Expected: false\n", isValid("]") ? "true" : "false");

    // Test 7: Unclosed opening bracket
    printf("Test 7: %s | Expected: false\n", isValid("((") ? "true" : "false");

    return 0;
}
