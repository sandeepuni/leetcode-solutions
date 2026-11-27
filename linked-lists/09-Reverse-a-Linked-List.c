#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *reverseList(struct ListNode *head)
{
    struct ListNode *prev = NULL;
    struct ListNode *curr = head;

    while (curr != NULL)
    {
        struct ListNode *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

int main(void)
{
    // Test 1: [1, 2, 3, 4, 5] -> [5, 4, 3, 2, 1]
    struct ListNode *head1 = NULL;
    struct ListNode *tail1 = NULL;
    int vals1[] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; i++)
    {
        struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));
        node->val = vals1[i];
        node->next = NULL;
        if (head1 == NULL)
        {
            head1 = tail1 = node;
        }
        else
        {
            tail1->next = node;
            tail1 = node;
        }
    }
    struct ListNode *rev1 = reverseList(head1);
    printf("Test 1: [");
    for (struct ListNode *p = rev1; p != NULL; p = p->next)
    {
        printf("%d%s", p->val, p->next ? ", " : "");
    }
    printf("] | Expected: [5, 4, 3, 2, 1]\n");
    while (rev1 != NULL)
    {
        struct ListNode *tmp = rev1;
        rev1 = rev1->next;
        free(tmp);
    }

    // Test 2: [1, 2] -> [2, 1]
    struct ListNode *head2 = NULL;
    struct ListNode *tail2 = NULL;
    int vals2[] = {1, 2};
    for (int i = 0; i < 2; i++)
    {
        struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));
        node->val = vals2[i];
        node->next = NULL;
        if (head2 == NULL)
        {
            head2 = tail2 = node;
        }
        else
        {
            tail2->next = node;
            tail2 = node;
        }
    }
    struct ListNode *rev2 = reverseList(head2);
    printf("Test 2: [");
    for (struct ListNode *p = rev2; p != NULL; p = p->next)
    {
        printf("%d%s", p->val, p->next ? ", " : "");
    }
    printf("] | Expected: [2, 1]\n");
    while (rev2 != NULL)
    {
        struct ListNode *tmp = rev2;
        rev2 = rev2->next;
        free(tmp);
    }

    // Test 3: Empty list [] -> []
    struct ListNode *rev3 = reverseList(NULL);
    printf("Test 3: [%s] | Expected: []\n", rev3 ? "non-empty" : "");

    // Test 4: Single node [7] -> [7]
    struct ListNode *head4 = (struct ListNode *)malloc(sizeof(struct ListNode));
    head4->val = 7;
    head4->next = NULL;
    struct ListNode *rev4 = reverseList(head4);
    printf("Test 4: [%d] | Expected: [7]\n", rev4->val);
    free(rev4);

    return 0;
}
